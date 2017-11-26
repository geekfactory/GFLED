/* GeekFactory GFLed Library for Arduino
 * 
 * Copyright (C) 2017 Jesus Ruben Santa Anna Zamudio.
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Author website: http://www.geekfactory.mx
 * Author e-mail: ruben at geekfactory dot mx
 */

#ifndef GFLED_H
#define GFLED_H

/*-------------------------------------------------------------*/
/*		Includes and dependencies			*/
/*-------------------------------------------------------------*/
#include <Arduino.h>

/*-------------------------------------------------------------*/
/*		Library configuration				*/
/*-------------------------------------------------------------*/
#define GFLED_VERSION_STRING	"1.0.1"
#define LED_SLOW_TIME		6000
#define LED_NORMAL_TIME		3000
#define LED_FAST_TIME		900
#define LED_VFAST_TIME		300

/*-------------------------------------------------------------*/
/*		Typedefs enums & structs			*/
/*-------------------------------------------------------------*/
/**
 * Defines the led colors
 */
enum ledcolors {
	LED_NONE,
	LED_GREEN,
	LED_RED,
	LED_YELLOW,
	LED_TOGGLE=0xFF,
};

/**
 * Defines the led flashing speeds
 */
enum ledspeeds {
	LED_SLOW,
	LED_NORMAL,
	LED_FAST,
	LED_VFAST,
};

/**
 * Defines the led FSM states.
 */
enum ledstates {
	E_LED_TON,
	E_LED_TOFF,
};

/*-------------------------------------------------------------*/
/*		Class declaration				*/
/*-------------------------------------------------------------*/
class GFLed {
public:
	/**
	 * Prepares a led object
	 * 
	 * @param pin The pin where the led is connected
	 */
	GFLed(uint8_t pin = 13);
	
	/**
	 * Prepares a dual color led object
	 * 
         * @param pin The pin connected to the green led
         * @param apin The pin connected to the red led
         */
	GFLed(uint8_t pin, uint8_t apin);

	/**
	 * Sets the led on and off times
	 * 
	 * Configures the amount of time that the led is on and off
	 * 
	 * @param ton The number of milliseconds the led should turn on
	 * @param toff The number of milliseconds the led should be off
	 */
	void setTimings(uint16_t ton, uint16_t toff);

	/**
	 * Sets the number of led flashes during "ton" period
	 * 
	 * @param flash The number of led flashes during the led active cycle
	 */
	void setFlash(uint8_t flash);

	/**
	 * Sets the speed of the led blink
	 * 
	 * @param speed The speed preset value according to ledspeeds enum
	 */
	void setSpeed(enum ledspeeds speed);
	
	/**
	 * 
         */
	void setColor(enum ledcolors color);

	/**
	 * Main led processing is done here, must be called frequently on the
	 * main program loop
	 */
	void process();

	/**
	 * This function keeps the led flashing but never returns, effectively
	 * blocking the program execution on a multitasking environment.
	 */
	void block();
private:
	uint16_t getTime(enum ledspeeds speed);
	void ledOutput(enum ledcolors color);
		
	enum ledstates _state;
	bool _toggle;
	uint8_t _pin;
	uint8_t _apin;
	enum ledcolors _color;
	uint8_t _flashSetting;
	uint8_t _flashCount;
	uint16_t _ton;
	uint16_t _toff;
	uint16_t _period;
	uint32_t _ledTimer;
};
#endif
