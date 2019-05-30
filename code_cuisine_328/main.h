#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

//#include <stdint.h>
#include <OneWire.h>
#include <Wire.h>
#include <RTClib.h>
#include <Adafruit_SSD1306_32.h>
#include <DallasTemperature.h>
#include <Adafruit_MAX31855.h>
#include <toneAC.h>


#include "boutons.h"
#include "affichage.h"


#define PIN_SCL         A5
#define PIN_SDA         A4

#define PIN_TEMP        7

#define PIN_VOLT        A0

#define PIN_1HZ       2

#define PIN_RE_SW     8
#define PIN_RE_A      4
#define PIN_RE_B      5

#define PIN_BUZZ_A    9
#define PIN_BUZZ_B    10

#define PIN_MAXCS     6


#define LONG_JOURL      9
#define NB_JOURL        7
#define LONG_MOISL      10
#define NB_MOISL        12



extern RTC_DS1307 rtc;
extern OneWire TemperatureSensor;
extern Adafruit_SSD1306 ecran;
extern Adafruit_MAX31855 thermocouple;

enum Choix { MINUTEUR, CHRONOMETRE, TEMPERATURE, REGLAGE };
extern enum Choix choix;

enum Etat { VEILLE, NORMAL, MENU, FONCTION };
extern enum Etat etat;

struct Time
{
    byte hour;
    byte min;
    byte sec;
};

extern int temperature;

extern const char jourL[NB_JOURL][LONG_JOURL];
extern const char moisL[NB_MOISL][LONG_MOISL];

extern byte etatFonction;
extern bool clignote;
extern bool buzzer;

extern volatile char secondDetected;

extern volatile char direction;
extern volatile bool click;



#endif

