#include "main.h"

/* etatFoncition :
    0 = reglage heure minuteur (titre, minuteur, heure selected, bouton "Valider", bouton "Annuler")
    1 = reglage minute minuteur (titre, minuteur, minute selected, bouton "Valider", bouton "Annuler")
    2 = reglage seconde minuteur (titre, minuteur, seconde selected, bouton "Valider", bouton "Annuler")
    3 = reglage valider (titre, minuteur, bouton "Valider" selected, bouton "Annuler")
    4 = reglage annuler (titre, minuteur, bouton "Valider", bouton "Annuler" selected)
    5 = minuteur lancé (minuteur plein écran)
    6 = fin minuteur (minuteur plein écran, clignote)
*/
void affichageMinut(byte sec, byte min, byte hour)
{
  if(etatFonction < 5)
  {
    ecran.setTextSize(1);
    ecran.setTextColor(WHITE);
  
    ecran.setCursor(40, 0);  
    ecran.print("Minuteur");

    ecran.setCursor(52, 12);
    ecran.print(":  :");

    char txt[3] = "";

    ecran.setCursor(40, 12);
    editForm(txt, hour, 24, ' ');
    if(etatFonction == 0)
    {
      ecran.setTextColor(BLACK);
      ecran.fillRect(39, 11, 13, 9, WHITE);
    }
    else
    {
      ecran.setTextColor(WHITE);
    }
    ecran.print(txt);
    
    ecran.setCursor(58, 12);
    editForm(txt, min, 60, '0');
    if(etatFonction == 1)
    {
      ecran.setTextColor(BLACK);
      ecran.fillRect(57, 11, 13, 9, WHITE);
    }
    else
    {
      ecran.setTextColor(WHITE);
    }
    ecran.print(txt);
    
    ecran.setCursor(76, 12);
    editForm(txt, sec, 60, '0');
    if(etatFonction == 2)
    {
      ecran.setTextColor(BLACK);
      ecran.fillRect(75, 11, 13, 9, WHITE);
    }
    else
    {
      ecran.setTextColor(WHITE);
    }
    ecran.print(txt);

    boutonBas("Valider", etatFonction == 3, etatFonction == 4);
  }
  else
  {
    afficherTimeFullscreen(sec, min, hour);
  }
  
}

void gestionMinut(bool appui, char dir, byte* sec, byte* min, byte* hour)
{
  switch (etatFonction)
  {
  case 0:
    if(appui)
      etatFonction = 1;
    else if(dir == 1)
      incrementeValue(hour, 24);
    else if(dir == -1)
      decrementeValue(hour, 24);
    break;

  case 1:
    if(appui)
      etatFonction = 2;
    else if(dir == 1)
      incrementeValue(min, 60);
    else if(dir == -1)
      decrementeValue(min, 60);
    break;

  case 2:
    if(appui)
      etatFonction = 3;
    else if(dir == 1)
      incrementeValue(sec, 60);
    else if(dir == -1)
      decrementeValue(sec, 60);
    break;

  case 3:
    if(appui)
    {
      etatFonction = 5;
      //rtc.writeSqwPinMode(SquareWave1HZ);
    }
    else if(dir != 0)
      etatFonction = 4;
    break;
    
  case 4:
    if(appui)
    {
      etatFonction = 0;
      etat = NORMAL;
    }
    else if(dir != 0)
      etatFonction = 3;
    break;
    
  case 5:
    Serial.println(secondDetected);
    decrementeValue(hour, 24, decrementeValue(min, 60, decrementeValue(sec, 60, secondDetected)));
    if(secondDetected)
      secondDetected = 0;
    if(appui)
    {
      etatFonction = 0;
      //rtc.writeSqwPinMode(OFF);
    }
    if(*sec == 0 && *min == 0 && *hour == 0)
    {
      etatFonction = 6;
      //rtc.writeSqwPinMode(OFF);
      clignote = true;
      buzzer = true;
    }
    break;
    
  case 6:
    if(appui)
    {
      etatFonction = 4;
      clignote = false;
      buzzer = false;
    }
    break;
  }
}

