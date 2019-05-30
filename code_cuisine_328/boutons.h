#ifndef BOUTONS_H_INCLUDED
#define BOUTONS_H_INCLUDED

ISR (PCINT2_vect);
ISR (PCINT0_vect);
void pciSetup(byte pin);

void secondDetector();


#endif

