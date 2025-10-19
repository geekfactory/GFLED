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
 * @brief RGB status LED that blinks or changes color to indicate firmware activity or state.
 *
 * This class controls a three-channel (RGB) LED using a non-blocking state machine inherited
 * from GFLEDStatusBlink. It supports both simple blinking and static color control for
 * different system states or modes.
 *
 * By default, all LED channels are active HIGH.
 */
class GFLEDRGB final : public GFLEDStatusBlink
{
public:
	/**
	 * @brief Construct a new GFLEDRGB object.
	 *
	 * @param redPin   The pin connected to the red LED channel.
	 * @param greenPin The pin connected to the green LED channel.
	 * @param bluePin  The pin connected to the blue LED channel.
	 * @param activeLevel The logic level that turns a channel ON (default: HIGH).
	 *
	 * @note The base class (GFLEDStatusBlink) is initialized with a reference to '_driverRGB'.
	 * Although '_driverRGB' is declared after the base class, this order is safe because
	 * '_driverRGB' is only *referenced* during construction, not *used*. The actual initialization
	 * order in C++ is always: base classes first, then members (in the order of declaration).
	 */
	GFLEDRGB(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, uint8_t activeLevel = HIGH)
	    : GFLEDStatusBlink(_driverRGB), _driverRGB(redPin, greenPin, bluePin, activeLevel) {}

	/**
	 * @brief Sets the LED color using a predefined color object.
	 *
	 * @param color A GFLEDColor instance specifying RGB values.
	 */
	void setColor(GFLEDColor color) { _driverRGB.setColor(color); }

	/**
	 * @brief Sets the LED color using raw RGB intensity values.
	 *
	 * @param r Red channel intensity (0–255).
	 * @param g Green channel intensity (0–255).
	 * @param b Blue channel intensity (0–255).
	 */
	void setColor(uint8_t r, uint8_t g, uint8_t b) { _driverRGB.setColor(r, g, b); }

private:
	/**
	 * @brief Low-level driver controlling the RGB LED pins.
	 */
	GFLEDDriverRGB _driverRGB;
};