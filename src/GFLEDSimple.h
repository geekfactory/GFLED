/* Geek Factory GFLED Library
 *
 * Copyright (C) 2025 Jesus Ruben Santa Anna Zamudio.
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
 * Author website: https://www.geekfactory.mx
 * Author e-mail: ruben at geekfactory dot mx
 */

#pragma once
#include "GFLEDStatusBlink.h"
#include "GFLEDDriver.h"

/**
 * @brief Simple status LED that blinks to indicate firmware activity.
 *
 * This class controls a single-color LED, such as the built-in LED on most Arduino boards (pin 13).
 * It provides non-blocking blinking behavior through GFLEDStatusBlink.
 *
 * By default, the constructor uses the board's LED_BUILTIN pin (if defined) and assumes an active
 * HIGH configuration.
 */
class GFLED final : public GFLEDStatusBlink
{
private:
	/**
	 * Object used to access the physical pins where the LED is connected.
	 */
	GFLEDDriverSingle _driverSingle;

public:
	/**
	 * @brief Construct a new GFLED object.
	 *
	 * @param pin The pin used to connect the LED.
	 * @param activeLevel The level used to turn ON the LED, should be set to HIGH or LOW.
	 *
	 * @note The base class (GFLEDStatusBlink) is initialized with a reference to '_driverRGB'.
	 * Although '_driverRGB' is declared after the base class, this order is safe because
	 * '_driverRGB' is only *referenced* during construction, not *used*. The actual initialization
	 * order in C++ is always: base classes first, then members (in the order of declaration).
	 */
	GFLED(uint8_t pin = LED_BUILTIN, uint8_t activeLevel = HIGH)
	    : GFLEDStatusBlink(_driverSingle), _driverSingle(pin, activeLevel) {}
};