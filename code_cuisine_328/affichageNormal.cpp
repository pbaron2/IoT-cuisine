#include "main.h"




void affichageNormal(DateTime time)
{
  ecran.setTextSize(1);
  ecran.setTextColor(WHITE);
  

  // Date
  char date[22] = "";
  dateForm(date, time.day(), time.month(), time.year());
  ecran.setCursor(64 - 3 * strlen(date), 0);  
  ecran.print(date);

  //Heure
  char txt[3] = "";
  ecran.setCursor(49, 12);
  editForm(txt, time.hour(), 24, ' ');
  ecran.print(txt);
  
  ecran.setCursor(67, 12);
  editForm(txt, time.minute(), 60, '0');
  ecran.print(txt);
  
  ecran.setCursor(61, 12);
  ecran.print(":");
  
  // Temperature
  ecran.setCursor(58, 24);  
  ecran.print(". 'C");
  
  ecran.setCursor(46, 24); 
  editForm(txt, temperature / 10, 100, ' ');
  ecran.print(txt);
  
  ecran.setCursor(64, 24);  
  txt[0] = (char)(48 + abs(temperature - (temperature / 10) * 10));
  txt[1] = '\0';
  ecran.print(txt);
  
}


