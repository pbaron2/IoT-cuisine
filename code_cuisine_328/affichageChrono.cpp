#include "main.h"


/* etatFoncition :
    0 = chrono en pause (titre, chrono, bouton "Compter" selected, bouton "Annuler")
    1 = chrono en pause (titre, chrono, bouton "Compter", bouton "Annuler" selected)
    2 = chrono lancé (chrono plein écran)
*/
void affichageChrono(byte sec, byte min, byte hour)
{
  if(etatFonction < 2)
  {
    ecran.setTextSize(1);
    ecran.setTextColor(WHITE);
  
    ecran.setCursor(31, 0);  
    ecran.print("Chronometre");

    ecran.setCursor(52, 12);
    ecran.print(":  :");

    char txt[3] = "";
    
    ecran.setCursor(40, 12);
    editForm(txt, hour, 24, ' ');
    ecran.print(txt);
    
    ecran.setCursor(58, 12);
    editForm(txt, min, 60, '0');
    ecran.print(txt);
    
    ecran.setCursor(76, 12);
    editForm(txt, sec, 60, '0');
    ecran.print(txt);

    boutonBas("Compter", etatFonction == 0, etatFonction == 1);
  }
  else
  {
    afficherTimeFullscreen(sec, min, hour);
  }
}

void gestionChrono(bool appui, char dir, byte* sec, byte* min, byte* hour)
{
  switch (etatFonction)
  {
  case 0:
    if(appui)
    {
      etatFonction = 2;
      //rtc.writeSqwPinMode(SquareWave1HZ);
    }
    else if(dir != 0)
      etatFonction = 1;
    break;
    
  case 1:
    if(appui)
    {
      etatFonction = 0;
      etat = NORMAL;
    }
    else if(dir != 0)
      etatFonction = 0;
    break;
    
  case 2:
    incrementeValue(hour, 24, incrementeValue(min, 60, incrementeValue(sec, 60, secondDetected)));
    if(secondDetected)
      secondDetected = 0;
    if(appui)
    {
      //rtc.writeSqwPinMode(OFF);
      etatFonction = 0;
    }
    break;
    
  }
}

