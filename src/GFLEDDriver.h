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
#include <Arduino.h>
#include "GFLEDInterfaces.h"
#include "GFLEDDriver.h"

/*-------------------------------------------------------------*/
/*	Declaration of concrete classes used to drive LEDs	*/
/*-------------------------------------------------------------*/

/**
 * @brief Hardware driver used to control a single color LED
 *
 * This is the driver used to control a single color LED, it implemtents the IGFLEDDriver interface.
 * The driver can output an active high or low signal to turn on the LED.
 */
class GFLEDDriverSingle : public IGFLEDDriver
{
public:
	GFLEDDriverSingle(uint8_t pin, uint8_t activeLevel);
	void initialize() override;
	void setState(bool on) override;

private:
	uint8_t _pin;
	uint8_t _activeLevel;
};

/**
 * @brief Hardware driver used to control RGB LED
 *
 * This is the driver used to control multi-color RGB LEDs. It implements both the IGFLEDDriver and
 * IGFLEDDriverColor interfaces, providing access to the init, on / off, and color set functionality,
 */
class GFLEDDriverRGB : public IGFLEDDriver, public IGFLEDDriverColor
{
public:
	GFLEDDriverRGB(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, uint8_t activeLevel);
	void initialize() override;
	void setState(bool on) override;
	void setColor(GFLEDColor color) override;
	void setColor(uint8_t r, uint8_t g, uint8_t b) override;

private:
	void off();
	uint8_t _redPin, _greenPin, _bluePin, _activeLevel;
	GFLEDColor _currentColor = GFLEDColor::WHITE;
};