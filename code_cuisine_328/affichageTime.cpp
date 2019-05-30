#include "main.h"

/* etatFoncition :
    0 = reglage jour (titre, date, heure, jour selected, bouton "Valider")
    1 = reglage mois (titre, date, heure, mois selected, bouton "Valider")
    2 = reglage annee (titre, date, heure, annee selected, bouton "Valider")
    3 = reglage heure (titre, date, heure, heure selected, bouton "Valider")
    4 = reglage minute (titre, date, heure, minute selected, bouton "Valider")
    5 = reglage seconde (titre, date, heure, seconde selected, bouton "Valider")
    6 = valider reglage (titre, date, heure, bouton "Valider" selected)
*/
void affichageTime(DateTime time)
{
  ecran.setTextSize(1);
  ecran.setTextColor(WHITE);
  
  ecran.setCursor(25, 0);  
  ecran.print("Reglage Heure");

 
  char txt[3] = "";

  // Date
  ecran.setCursor(46, 8);
  ecran.print("/  /");

  // Heure
  ecran.setCursor(52, 16);
  ecran.print(":  :");
  

  // Jour
  ecran.setCursor(34, 8);
  editForm(txt, time.day(), 32, '0');
  if(etatFonction == 0)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(33, 8, 13, 7, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
  }
  ecran.print(txt);
  
  // Mois
  ecran.setCursor(52, 8);
  editForm(txt, time.month(), 13, '0');
  if(etatFonction == 1)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(51, 8, 13, 7, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
  }
  ecran.print(txt);

  // Annee
  ecran.setCursor(72, 8);
  if(etatFonction == 2)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(71, 8, 25, 7, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
  }
  ecran.print(time.year());


  // Heure
  ecran.setCursor(40, 16);
  editForm(txt, time.hour(), 24, '0');
  if(etatFonction == 3)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(39, 16, 13, 7, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
  }
  ecran.print(txt);

  // Minute
  ecran.setCursor(58, 16);
  editForm(txt, time.minute(), 60, '0');
  if(etatFonction == 4)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(57, 16, 13, 7, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
  }
  ecran.print(txt);
  
  // Seconde
  ecran.setCursor(76, 16);
  editForm(txt, time.second(), 60, '0');
  if(etatFonction == 5)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(75, 16, 13, 7, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
  }
  ecran.print(txt);

  ecran.setTextSize(1);

  // Bouton Valider
  ecran.setCursor(43, 24);
  if(etatFonction == 6)
  {
    ecran.fillRect(42, 23, 43, 9, WHITE);
    ecran.setTextColor(BLACK);
  }
  else
  {
    ecran.setTextColor(WHITE);
  }
  ecran.print(F("Valider"));
  
}


void gestionTime(bool appui, char dir, DateTime now)
{
  switch (etatFonction)
  {
  case 0:
    if(appui)
      etatFonction = 1;
    else if(dir == 1)
      rtc.adjust(DateTime(now.year(), now.month(), now.day() % nbJourDansMois(now.month(), now.year()) + 1, now.hour(), now.minute(), now.second()));
    else if(dir == -1)
      rtc.adjust(DateTime(now.year(), now.month(), ((now.day() + nbJourDansMois(now.month(), now.year()) - 2) % nbJourDansMois(now.month(), now.year())) + 1, now.hour(), now.minute(), now.second()));
    break;

  case 1:
    if(appui)
      etatFonction = 2;
    else if(dir == 1)
    {
      byte nbJour = nbJourDansMois((now.month() % 12) + 1, now.year());
      byte jour = (now.day() > nbJour) ? nbJour : now.day();
      rtc.adjust(DateTime(now.year(), (now.month() % 12) + 1, jour, now.hour(), now.minute(), now.second()));
    }
    else if(dir == -1)
    {
      byte nbJour = nbJourDansMois(((now.month() + 10) % 12) + 1, now.year());
      byte jour = (now.day() > nbJour) ? nbJour : now.day();
      rtc.adjust(DateTime(now.year(), ((now.month() + 10) % 12) + 1, jour, now.hour(), now.minute(), now.second()));
    }
    break;

  case 2:
    if(appui)
      etatFonction = 3;
    else if(dir == 1)
      rtc.adjust(DateTime(((now.year() - 1999) % 100) + 2000, now.month(), now.day(), now.hour(), now.minute(), now.second()));
    else if(dir == -1)
      rtc.adjust(DateTime(((now.year() - 1901) % 100) + 2000, now.month(), now.day(), now.hour(), now.minute(), now.second()));
    break;

  case 3:
    if(appui)
      etatFonction = 4;
    else if(dir == 1)
      rtc.adjust(DateTime(now.year(), now.month(), now.day(), (now.hour() + 1) % 24, now.minute(), now.second()));
    else if(dir == -1)
      rtc.adjust(DateTime(now.year(), now.month(), now.day(), (now.hour() + 23) % 24, now.minute(), now.second()));
    break;
    
  case 4:
    if(appui)
      etatFonction = 5;
    else if(dir == 1)
      rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), (now.minute() + 1) % 60, now.second()));
    else if(dir == -1)
      rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), (now.minute() + 59) % 60, now.second()));
    break;
    
  case 5:
    if(appui)
      etatFonction = 6;
    else if(dir == 1)
      rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), now.minute(), 30));
    else if(dir == -1)
      rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), now.minute(), 0));
    break;
    
  case 6:
    if(appui)
    {
      etatFonction = 0;
      etat = NORMAL;
    }
    break;
  }
}

