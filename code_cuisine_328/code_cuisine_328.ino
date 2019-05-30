#include "main.h"




RTC_DS1307 rtc;
OneWire TemperatureSensor(PIN_TEMP);
Adafruit_SSD1306 ecran(14);
//Adafruit_MAX31855 thermocouple(PIN_MAXCS);

DallasTemperature sensors(&TemperatureSensor);
DeviceAddress sensorDeviceAddress;


int temperature = 0;
unsigned long previousMillisTemp = 0;
unsigned long previousMillisClign = 0;
unsigned long previousMillisBuzz = 0;
unsigned long previousMillisBack = 0;
unsigned long previousMillisVeille = 0;


const char jourL[NB_JOURL][LONG_JOURL] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vencredi", "Samedi"};
const char moisL[NB_MOISL][LONG_MOISL] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};

enum Choix choix = MINUTEUR;
enum Etat etat = NORMAL;

byte etatFonction = 0;
bool clignote = false;
bool buzzer = false;

volatile char secondDetected = 0;

volatile char direction = 0;
volatile bool click = false;

struct Time timeChrono = {0, 0, 0};
struct Time timeMinut = {0, 0, 0};
byte temperatureConsigne = 90;

bool stateClignote = true;


void setup()
{
  Serial.begin(115200);

  
  // RTC
  Wire.begin();            // Begin I2C 
  rtc.begin();                  // Begin DS1307 real time clock
  if (!rtc.isrunning())
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //rtc.writeSqwPinMode(OFF);
  rtc.writeSqwPinMode(SquareWave1HZ);
  pinMode(PIN_1HZ,INPUT);
  digitalWrite(PIN_1HZ, HIGH);
  attachInterrupt(digitalPinToInterrupt(PIN_1HZ), secondDetector, RISING);


  // Voltage
  pinMode(PIN_VOLT, INPUT);


  // Rotary encoder
  pinMode(PIN_RE_A,INPUT);
  pinMode(PIN_RE_B,INPUT);
  pinMode(PIN_RE_SW,INPUT);
  digitalWrite(PIN_RE_A, HIGH);
  digitalWrite(PIN_RE_B, HIGH);
  digitalWrite(PIN_RE_SW, HIGH);
  pciSetup(PIN_RE_A);
  pciSetup(PIN_RE_SW);
  
  
  // Ecran
  ecran.begin(SSD1306_SWITCHCAPVCC, 0x3C);


  // Capteur temperature
  sensors.getAddress(sensorDeviceAddress, 0); //Demande l'adresse du capteur à l'index 0 du bus
  sensors.setResolution(sensorDeviceAddress, 12); //Résolutions possibles: 9,10,11,12

  // Thermocouple
  //thermocouple.begin();
}

void loop()
{
  unsigned long currentMillis = millis();
  
  //Serial.println("\n\tLOOP");
  
  DateTime now = rtc.now(); 

  readTemp();

  ecran.clearDisplay();


  //Serial.println(int(direction));

  char dir = direction;
  direction = 0;
  bool appui = click;
  click = false;

  if(appui || dir != 0 || etat != NORMAL)
    previousMillisVeille = currentMillis;
  

  if(etat == VEILLE)
  {
    if(appui || dir != 0)
    {
      ecran.ssd1306_command(SSD1306_DISPLAYON);
      etat = NORMAL;
    }
  }
  else if(etat == NORMAL)
  {
    affichageNormal(now);

    if(appui)
    {
      etat = MENU;
      previousMillisBack = currentMillis;
    }

    if (currentMillis - previousMillisVeille >= 15000)
    {
      etat = VEILLE;
      ecran.ssd1306_command(SSD1306_DISPLAYOFF);
      previousMillisVeille = currentMillis;
    }
  }
  else if(etat == MENU)
  {
    affichageMenu();
    
    choix = (choix + 4 + dir) % 4;
    
    if(appui)
    {
      previousMillisBack = currentMillis;
      etat = FONCTION;
    }

    if(dir != 0)
    {
      previousMillisBack = currentMillis;
    }

    if (currentMillis - previousMillisBack >= 8000)
    {
      etat = NORMAL;
      previousMillisBack = currentMillis;
    }
    
  }
  else if(etat == FONCTION)
  {
    if(choix == MINUTEUR)
    {
      affichageMinut(timeMinut.hour, timeMinut.min, timeMinut.sec);
      
      gestionMinut(appui, dir, &timeMinut.hour, &timeMinut.min, &timeMinut.sec);
      
    }
    else if(choix == CHRONOMETRE)
    {
      affichageChrono(timeChrono.hour, timeChrono.min, timeChrono.sec);

      gestionChrono(appui, dir, &timeChrono.hour, &timeChrono.min, &timeChrono.sec);
    }
    else if(choix == TEMPERATURE)
    {
      affichageTemp(temperatureConsigne);

      gestionTemp(appui, dir, &temperatureConsigne);
    }
    else if(choix == REGLAGE)
    {
      affichageTime(now);

      gestionTime(appui, dir, now);
    }
  }

  clignoter();
  controlBuzzer();

  ecran.display();

  delay(10);

}






void readTemp()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillisTemp >= 2000)
  {
    sensors.requestTemperatures(); //Demande la température aux capteurs
    double t = sensors.getTempCByIndex(0) * 10; //Récupération de la température en celsius du capteur n°0

    //thermocouple.readInternal();
    //double t2 = thermocouple.readCelsius() * 10;
    Serial.print(t);
    //Serial.print(" / ");
    //Serial.println(t2);
    temperature = t;

    previousMillisTemp = currentMillis;
  }
}


void clignoter()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillisClign >= 500 || !clignote)
  {
    ecran.invertDisplay(stateClignote && clignote);
    stateClignote = !stateClignote;
  
    previousMillisClign = currentMillis;
  }
}


void controlBuzzer()
{
  if(buzzer)
  {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillisBuzz >= 1000)
    {
      toneAC(880, 8, 500, true); //   toneAC( frequency [, volume [, length [, background ]]] ) - Play a note.
      previousMillisBuzz = currentMillis;
    }
  }
}

