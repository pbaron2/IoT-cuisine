#include "main.h"



ISR (PCINT2_vect) // handle pin change interrupt for D0 to D7 here
{ 
  if(digitalRead(PIN_RE_A))
  {
    if(digitalRead(PIN_RE_B))
      direction = 1;
    else
      direction = -1;
  }
}

ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
{
  click = !digitalRead(PIN_RE_SW);
}


void secondDetector()
{
  secondDetected = 1;
}


void pciSetup(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}



