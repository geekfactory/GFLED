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

#include "GFLEDDriver.h"

/*-------------------------------------------------------------*/
/*	Implementation of concrete classes used to drive LEDs	*/
/*-------------------------------------------------------------*/

/*-------------------------------------------------------------*/
/*		Driver for simple one color LED			*/
/*-------------------------------------------------------------*/

GFLEDDriverSingle::GFLEDDriverSingle(uint8_t pin, uint8_t activeLevel) : _pin(pin), _activeLevel(activeLevel) {}

void GFLEDDriverSingle::initialize()
{
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, !_activeLevel);
}

void GFLEDDriverSingle::setState(bool on)
{
	digitalWrite(_pin, on ? _activeLevel : !_activeLevel);
}

/*-------------------------------------------------------------*/
/*		Driver for RGB LED without PWM control		*/
/*-------------------------------------------------------------*/

GFLEDDriverRGB::GFLEDDriverRGB(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, uint8_t activeLevel)
    : _redPin(redPin), _greenPin(greenPin), _bluePin(bluePin), _activeLevel(activeLevel) {}

void GFLEDDriverRGB::initialize()
{
	pinMode(_redPin, OUTPUT);
	pinMode(_greenPin, OUTPUT);
	pinMode(_bluePin, OUTPUT);
	off();
}

void GFLEDDriverRGB::setState(bool on)
{
	if (!on || _currentColor == GFLEDColor::OFF)
	{
		off();
		return;
	}
	digitalWrite(_redPin, (_currentColor & GFLEDColor::RED) ? _activeLevel : !_activeLevel);
	digitalWrite(_greenPin, (_currentColor & GFLEDColor::GREEN) ? _activeLevel : !_activeLevel);
	digitalWrite(_bluePin, (_currentColor & GFLEDColor::BLUE) ? _activeLevel : !_activeLevel);
}

void GFLEDDriverRGB::setColor(GFLEDColor color)
{
	_currentColor = color;
}

void GFLEDDriverRGB::setColor(uint8_t r, uint8_t g, uint8_t b)
{
	_currentColor = GFLEDColor::OFF;
	if (r)
		_currentColor = _currentColor | GFLEDColor::RED;
	if (g)
		_currentColor = _currentColor | GFLEDColor::GREEN;
	if (b)
		_currentColor = _currentColor | GFLEDColor::BLUE;
}

/**
 * Private helper method to turn off all individual LEDs
 */
void GFLEDDriverRGB::off()
{
	digitalWrite(_redPin, !_activeLevel);
	digitalWrite(_greenPin, !_activeLevel);
	digitalWrite(_bluePin, !_activeLevel);
}