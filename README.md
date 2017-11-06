# GFButton Library #

Arduino library to create easily configurable blinking led without the need to put code in the main sketch. Almost every arduino project needs an indicator light, and this library takes care of this.

The objective of this library is to move the led logic outside of the arduino sketch in order to keep the code organized.

## Basic library usage ##

The following example ilustrates the library usage. A blinking led can be created by using 3 lines of code on the main sketch.

```cpp
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
```

## Project objectives ##

* Simplify the programming of leds, including multi color led
* Move status led related code outside the arduino sketch
* Provide advanced led functionality: color control, timming configuration and pattern control
* Easy to configure and use
* Low memory footprint

## Supported devices ##

This library was developed/tested on the following boards:

* Arduino UNO R3
* Arduino Mega 2560 R3

This code should be portable and work well on any other arduino board without modification.

## Contact me ##

* Feel free to write for any inquiry: ruben at geekfactory.mx 
* Check our website: https://www.geekfactory.mx
