/* Blinking Led Library for Arduino
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

	_pin = pin;
	_flashSetting = 2;
	_period = 300;
	_ton = 300;
	_toff = LED_VFAST_TIME;
	_state = E_LED_TON;
	_flashCount = 0;
}

void GFLed::SetTimings(uint16_t ton, uint16_t toff)
{
	_ton = ton;
	_toff = toff;
	_period = _ton / (_flashSetting - 1);
}

void GFLed::SetFlash(uint8_t flash)
{
	_flashSetting = flash * 2;
	_period = _ton / (_flashSetting - 1);
}

void GFLed::SetSpeed(enum ledspeeds speed)
{
	SetTimings(300, GetTime(speed));
}

void GFLed::Process()
{
	switch (_state) {
	case E_LED_TON:
		if (millis() - _ledTimer >= (uint32_t) _period) {
			_ledTimer = millis();
			// Toggle pin
			digitalWrite(_pin, !digitalRead(_pin));
			if (++_flashCount >= _flashSetting) {
				_flashCount = 0;
				_state = E_LED_TOFF;
			}
		}
		break;
	case E_LED_TOFF:
		if (millis() - _ledTimer >= (uint32_t) _toff) {
			_state = E_LED_TON;
			digitalWrite(_pin, LOW);
		}
		break;
	}
}

void GFLed::Block()
{
	// Infinite loop
	for (;;) {
		Process();
	}
}

uint16_t GFLed::GetTime(enum ledspeeds speed)
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
}
