#include "main.h"

/* etatFoncition :
    0 = reglage temperature (titre, temperatureC selected, bouton "Valider", bouton "Annuler")
    1 = reglage temperature (titre, temperatureC, bouton "Valider" selected, bouton "Annuler")
    2 = reglage temperature (titre, temperatureC, bouton "Valider", bouton "Annuler" selected)
    3 = mesure lancée (temperature & temperatureC plein écran)
    4 = temperature atteinte (temperature plein écran, clignote)
*/
void affichageTemp(byte t)
{
  char txt[4] = "";
  itoa(t, txt, 10);
  
  if(etatFonction < 3)
  {
    ecran.setTextSize(1);
    ecran.setTextColor(WHITE);
    
    ecran.setCursor(31, 0);  
    ecran.print("Temperature");

    if(etatFonction == 0)
    {
      ecran.setTextColor(BLACK);
      ecran.fillRect(45, 11, 31, 9, WHITE);
    }
    else
    {
      ecran.setTextColor(WHITE);
    }

    ecran.setCursor(64, 12);  
    ecran.print("'C");
    
    ecran.setCursor(64 - strlen(txt) * 6, 12);
    ecran.print(txt);

    boutonBas("Valider", etatFonction == 1, etatFonction == 2);
  }
  else
  {
    ecran.setTextColor(WHITE);

    
    ecran.setTextSize(1);
    
    ecran.setCursor(64, 4);  
    ecran.print("'C");
    ecran.setCursor(64 - strlen(txt) * 6, 4);
    ecran.print(txt);


    ecran.setTextSize(2);
    
    ecran.setCursor(64, 16);  
    ecran.print("'C");
    itoa(temperature/10, txt, 10);
    ecran.setCursor(64 - strlen(txt) * 12, 16);  
    ecran.print(txt);
  }
  
}

void gestionTemp(bool appui, char dir, byte *t)
{
  switch (etatFonction)
  {
  case 0:
    if(appui)
      etatFonction = 1;
    else if(dir == 1)
      incrementeValue(t, 125);
    else if(dir == -1)
      decrementeValue(t, 125);
    break;

  case 1:
    if(appui)
    {
      etatFonction = 3;
    }
    else if(dir != 0)
      etatFonction = 2;
    break;
    
  case 2:
    if(appui)
    {
      etatFonction = 0;
      etat = NORMAL;
    }
    else if(dir != 0)
      etatFonction = 1;
    break;
    
  case 3:
    if(appui)
    {
      etatFonction = 0;
    }
    if(temperature/10 > *t)
    {
      etatFonction = 4;
      clignote = true;
      buzzer = true;
    }
    break;
    
  case 4:
    if(appui)
    {
      etatFonction = 2;
      clignote = false;
      buzzer = false;
    }
    break;
  }
}


