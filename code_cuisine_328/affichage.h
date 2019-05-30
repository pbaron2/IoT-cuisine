#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

void boutonBas(const char txtFirst[], bool firstSelected, bool secondSelected);

void editForm(char text[], int data, int limit, char c);
void dateForm(char date[], int jour, int mois, int annee);
byte nbJourDansMois(int month, int year);

byte incrementeValue(byte *value, const byte limit);
byte incrementeValue(byte *value, const byte limit, const char n);
byte decrementeValue(byte *value, const byte limit);
byte decrementeValue(byte *value, const byte limit, const char n);

void afficherTimeFullscreen(byte sec, byte min, byte hour);

void affichageNormal(DateTime time);
void affichageMenu();
void affichageMinut(byte sec, byte min, byte hour);
void affichageChrono(byte sec, byte min, byte hour);
void affichageTemp(byte t);
void affichageTime(DateTime time);

void gestionMinut(bool appui, char dir, byte* sec, byte* min, byte* hour);
void gestionChrono(bool appui, char dir, byte* sec, byte* min, byte* hour);
void gestionTemp(bool appui, char dir, byte *t);
void gestionTime(bool appui, char dir, DateTime now);



#endif

