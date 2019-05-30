#include "main.h"


/*
void boutonBas(bool validated, bool selected)
{
  ecran.setTextSize(1);
  

  ecran.setCursor(43, 24);
  
  if(validated)
  {
    ecran.fillRect(43, 24, 42, 8, WHITE);
    ecran.setTextColor(BLACK);
    ecran.print(F("Annuler"));
  }
  else
  {
    ecran.setTextColor(WHITE);
    ecran.print(F("Valider"));
  }
  
}
*/
void boutonBas(const char txtFirst[], bool firstSelected, bool secondSelected)
{
  byte lengthFirst = strlen(txtFirst);
  byte halfLength = (lengthFirst + 14) * 3;
  byte xFirst, xSecond;
    
  xFirst = 64 - halfLength;
  xSecond = 22 + halfLength;
  
  ecran.setTextSize(1);
  
  ecran.setCursor(xFirst, 24);
  if(firstSelected)
  {
    ecran.fillRect(xFirst - 1, 23, lengthFirst * 6 + 1, 9, WHITE);
    ecran.setTextColor(BLACK);
  }
  else
  {
    ecran.setTextColor(WHITE);
  }
  ecran.print(txtFirst);

  ecran.setCursor(xSecond, 24);
  if(secondSelected)
  {
    ecran.fillRect(xSecond - 1, 23, 43, 9, WHITE);
    ecran.setTextColor(BLACK);
  }
  else
  {
    ecran.setTextColor(WHITE);
  }
  ecran.print(F("Annuler"));
}


void editForm(char text[], int data, int limit, char c)
{
  if(data < -10)
  {
    text[0] = '-';
    text[1] = '!';
  }
  else if(data < 0)
  {
    text[0] = '-';
    text[1] = (char)(48 + data);
  }
  else if(data < 10)
  {
    text[0] = c;
    text[1] = (char)(48 + data);
  }
  else if(data < limit)
  {
    text[0] = (char)(48 + data / 10);
    text[1] = (char)(48 + (data - data / 10 * 10));
  }
  else
  {
    text[0] = '+';
    text[1] = '!';
  }
  text[2] = '\0';
}


void dateForm(char date[], int jour, int mois, int annee)
{
  int c = (14 - mois) / 12;
  int a = annee - c;
  int m = mois + 12 * c - 2;
  int j = (jour + a + a/4 - a/100 + a/400 + (31*m)/12) % 7;

  //eeprom_read_block(date, &jourL[j], LONG_JOURL);
  memcpy(date, &jourL[j], LONG_JOURL);
  
  byte i = 0;
  while(date[i] != '\0')
  {
    i++;
  }
  date[i] = ' ';
  if(jour < 10)
  {
    date[i + 1] = (char)(48 + jour);
    i = i + 2;
  }
  else
  {
    date[i + 1] = (char)(48 + (jour / 10));
    date[i + 2] = (char)(48 + (jour - jour / 10 * 10));
    i = i + 3;
  }
  date[i] = ' ';
  
  //eeprom_read_block(&date[i + 1], &moisL[mois-1], LONG_MOISL);
  memcpy(&date[i + 1], &moisL[mois-1], LONG_MOISL);
  
}

byte nbJourDansMois(int month, int year)
{
  if (month == 4 || month == 6 || month == 9 || month == 11)  
    return 30;  
  else if (month == 2)  
  {
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);  
    if (isLeapYear)  
      return 29;  
    else  
      return 28;  
  }  
  else  
    return 31; 
}


void afficherTimeFullscreen(byte sec, byte min, byte hour)
{
  ecran.setTextSize(3);
  ecran.setTextColor(WHITE);
    
  ecran.setCursor(32, 4);
  ecran.print(":");

  ecran.setCursor(78, 4);
  ecran.print(":");

  char txt[3] = "";
  
  ecran.setCursor(0, 4);
  editForm(txt, hour, 24, ' ');
  ecran.print(txt);
  
  ecran.setCursor(46, 4);
  editForm(txt, min, 60, '0');
  ecran.print(txt);
  
  ecran.setCursor(92, 4);
  editForm(txt, sec, 60, '0');
  ecran.print(txt);
}

byte incrementeValue(byte *value, const byte limit, const char n)
{
  byte s = 0;
  for(char i = 0; i < abs(n); i++)
  {
    s += incrementeValue(value, limit);
  }
  return s;
}

byte incrementeValue(byte *value, const byte limit)
{
  if(*value == limit - 1)
  {
    *value = 0;
    return 1;
  }
  else
  {
    (*value)++;
    return 0;
  }
}


byte decrementeValue(byte *value, const byte limit, const char n)
{
  byte s = 0;
  for(char i = 0; i < abs(n); i++)
  {
    s += decrementeValue(value, limit);
  }
  return s;
}

byte decrementeValue(byte *value, const byte limit)
{
  if(*value == 0)
  {
    *value = limit - 1;
    return -1;
  }
  else
  {
    (*value)--;
    return 0;
  }
}

