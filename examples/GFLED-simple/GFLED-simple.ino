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
