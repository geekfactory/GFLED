# GFLED - Geek Factory LED Library #

Arduino library for easily creating configurable blinking LEDs without writing repetitive code in the main sketch. Almost every Arduino project needs an indicator light — this library takes care of that for you.

The purpose of this library is to move LED logic outside of the main Arduino sketch to help keep your code organized and clean.

## Basic library usage ##

The following example illustrates how to use the library. A blinking LED can be created with just three lines of code in your main sketch.

```cpp
/**
	Geek Factory - "INNOVATING TOGETHER"
	www.geekfactory.mx

	Simple example of GFLED library that shows how to create a blinking LED
	on pin 13 (LED_BUILTIN) of the arduino board.
*/

#include "GFLED.h"

// Create a GFLED instance, defaults to pin 13
GFLED statusled;
// Equivalent constructor, can configure any pin and active level
// GFLed statusled(13, HIGH);

/**
 * PROGRAM INITIALIZATION
 */
void setup()
{
	// Initialize the status LED
	statusled.begin();
}

/**
 * MAIN PROGRAM LOOP
 */
void loop()
{
	// Call the process method inside the main loop
	statusled.process();
}
```

## Project objectives ##

* Simplify LED programming, including multicolor LEDs
* Move status LED–related code outside the Arduino sketch
* Provide advanced LED functionality: color control, timing configuration, and pattern control.
* Easy to configure and use
* Low memory footprint

## Supported devices ##

This library was developed and tested on the following boards:

* Arduino UNO R3
* Arduino Mega 2560 R3

The code is portable and should work correctly on most other Arduino boards without modification.

## Contact me ##

* Feel free to write for any inquiry: ruben at geekfactory.mx 
* Check our website: https://www.geekfactory.mx
