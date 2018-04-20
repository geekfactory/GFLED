/**
   GeekFactory - "INNOVATING TOGETHER"
   Distribucion de materiales para el desarrollo e innovacion tecnologica
   www.geekfactory.mx

   Simple example of GFLed library. Create a blinking led on pin 13 of the
   arduino board.
*/

#include "GFLed.h"

// Create a led instance, defaults to pin 13
GFLed statusled;
// Equivalent constructor, can connect the led to any pin
// GFLed statusled(13);

/**
   PROGRAM INITIALIZATION
*/
void setup() {
  // No need to do anything to get the led working
}

/**
   MAIN PROGRAM LOOP
*/
void loop() {
  // Call the process method inside the main loop
  statusled.process();
}
