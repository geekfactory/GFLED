/**
	Geek Factory - "INNOVATING TOGETHER"
	www.geekfactory.mx

	Simple example of GFLED library that shows how to create a blinking RGB LED
	using GFLEDRGB class.
*/

#include "GFLED.h"

// Create a GFLEDRGB instance
// for an RGB LED connected to pins 8 (Red), 9 (Green), and 10 (Blue)
GFLEDRGB colorstatusled(8, 9, 10);

/**
 * PROGRAM INITIALIZATION
 */
void setup()
{
	// Initialize the status LED
	colorstatusled.begin();
}

/**
 * MAIN PROGRAM LOOP
 */
void loop()
{
	// Call the process method inside the main loop
	colorstatusled.process();
}