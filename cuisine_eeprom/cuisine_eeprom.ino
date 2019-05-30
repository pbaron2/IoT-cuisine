#include <avr/eeprom.h>

#define ADDRESS_JOURL   0
#define LONG_JOURL      9
#define NB_JOURL        7
#define ADDRESS_MOISL   (ADDRESS_JOURL + NB_JOURL * LONG_JOURL)
#define LONG_MOISL      10
#define NB_MOISL        12

const char jourL[NB_JOURL][LONG_JOURL] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"};
const char moisL[NB_MOISL][LONG_MOISL] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};




void setup()
{
  for(int i = 0; i < NB_JOURL; i++)
  {
    eeprom_write_block(jourL[i], ADDRESS_JOURL + i * LONG_JOURL, LONG_JOURL);
  }
  for(int i = 0; i < NB_MOISL; i++)
  {
    eeprom_write_block(moisL[i], ADDRESS_MOISL + i * LONG_MOISL, LONG_MOISL);
  }

}

void loop()
{
  delay(500);

}
