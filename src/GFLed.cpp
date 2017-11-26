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

#include "GFLed.h"

GFLed::GFLed(uint8_t pin)
{
	pinMode(pin, OUTPUT);

	// Set object fields
	_state = E_LED_TON;
	_toggle = true;
	_pin = pin;
	_apin = 0xFF;
	_color = LED_GREEN;
	_flashSetting = 2;
	_flashCount = 0;
	_ton = 300;
	_toff = LED_VFAST_TIME;
	_period = 300;
	_ledTimer = 0;
}

GFLed::GFLed(uint8_t pin, uint8_t apin) : GFLed(pin)
{
	_color = LED_RED;
	pinMode(apin, OUTPUT);
	_apin = apin;
}

void GFLed::setTimings(uint16_t ton, uint16_t toff)
{
	_ton = ton;
	_toff = toff;
	_period = _ton / (_flashSetting - 1);
}

void GFLed::setFlash(uint8_t flash)
{
	// Turn off the led
	ledOutput(LED_NONE);
	
	// Set the new period for the led signal
	_flashSetting = flash * 2;
	_period = _ton / (_flashSetting - 1);
	
	// Reset flash logic
	_state = E_LED_TON;
	_toggle = true;
	_flashCount = 0;
	_ledTimer = millis();

}

void GFLed::setSpeed(enum ledspeeds speed)
{
	setTimings(300, getTime(speed));
}

void GFLed::setColor(enum ledcolors color)
{
	_color = color;
}

void GFLed::process()
{
	switch (_state) {
	case E_LED_TON:
		if (millis() - _ledTimer >= (uint32_t) _period) {
			_ledTimer = millis();
			if (_toggle) {
				ledOutput(_color);
				_toggle = false;
			} else {
				ledOutput(LED_NONE);
				_toggle = true;
			}
			if (++_flashCount >= _flashSetting) {
				_flashCount = 0;
				_state = E_LED_TOFF;
			}
		}
		break;
	case E_LED_TOFF:
		if (millis() - _ledTimer >= (uint32_t) _toff) {
			_state = E_LED_TON;
			ledOutput(LED_NONE);
		}
		break;
	}
}

void GFLed::block()
{
	// Infinite loop
	for (;;) {
		process();
	}
}

uint16_t GFLed::getTime(enum ledspeeds speed)
{
	switch (speed) {
	case LED_SLOW:
		return LED_SLOW_TIME;
	case LED_NORMAL:
		return LED_NORMAL_TIME;
	case LED_FAST:
		return LED_FAST_TIME;
	case LED_VFAST:
		return LED_VFAST_TIME;
	}
	return LED_NORMAL_TIME;
}

void GFLed::ledOutput(enum ledcolors color)
{
	switch (color) {
	case LED_NONE:
		digitalWrite(_pin, LOW);
		digitalWrite(_apin, LOW);
		break;

	case LED_GREEN:
		digitalWrite(_pin, HIGH);
		digitalWrite(_apin, LOW);
		break;

	case LED_RED:
		digitalWrite(_pin, LOW);
		digitalWrite(_apin, HIGH);
		break;

	case LED_YELLOW:
		digitalWrite(_pin, HIGH);
		digitalWrite(_apin, HIGH);
		break;

	case LED_TOGGLE:
		digitalWrite(_pin, !digitalRead(_pin));
		digitalWrite(_apin, !digitalRead(_apin));
		break;
	}
}
