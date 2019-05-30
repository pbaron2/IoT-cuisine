#include "main.h"


void affichageMenu()
{
  ecran.setTextSize(1);

  ecran.setTextColor(choix != MINUTEUR);
  ecran.fillRect(39, 0, 49, 7, choix == MINUTEUR);
  ecran.setCursor(40, 0);  
  ecran.print("Minuteur");

  ecran.setTextColor(choix != CHRONOMETRE);
  ecran.fillRect(30, 8, 67, 7, choix == CHRONOMETRE);
  ecran.setCursor(31, 8);  
  ecran.print("Chronometre");

  ecran.setTextColor(choix != TEMPERATURE);
  ecran.fillRect(30, 16, 67, 7, choix == TEMPERATURE);
  ecran.setCursor(31, 16);  
  ecran.print("Temperature");

  ecran.setTextColor(choix != REGLAGE);
  ecran.fillRect(24, 24, 79, 7, choix == REGLAGE);
  ecran.setCursor(25, 24);  
  ecran.print("Reglage Heure");

}



