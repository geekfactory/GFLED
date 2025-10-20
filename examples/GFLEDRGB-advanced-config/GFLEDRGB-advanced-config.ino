/**
	Geek Factory - "INNOVATING TOGETHER"
	www.geekfactory.mx

	Example that illustrates the usage of GFLEDRGB class to create a blinking RGB LED
	and configure its color and blinking pattern.
*/

#include <GFLED.h>

// Create a GFLEDRGB instance
// for an RGB LED connected to pins 8 (Red), 9 (Green), and 10 (Blue)
GFLEDRGB statusled(8, 9, 10);

/**
 * PROGRAM INITIALIZATION
 */
void setup()
{
	// initialize the status LED on the setup function
	statusled.begin();

	// set the LED color to red
	statusled.setColor(GFLEDColor::YELLOW);
	// configure the blinking pattern: 1 second ON, 2 seconds OFF
	statusled.setTiming(1000, 2000);
	// set the number of blinks in the ON period to 3
	statusled.setFlashCount(3);
}

/**
 * MAIN PROGRAM LOOP
 */
void loop()
{
	// call the process method regularly to update the LED state
	statusled.process();
}