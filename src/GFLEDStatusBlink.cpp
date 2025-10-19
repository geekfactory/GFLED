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

#include "GFLEDStatusBlink.h"

GFLEDStatusBlink::GFLEDStatusBlink(IGFLEDDriver &driver) : GFLEDBase(driver) {};

void GFLEDStatusBlink::begin()
{
	GFLEDBase::begin();
	_state = E_LED_TOFF;
}

/**
 * _transitionCount starts at 1 when LED turns ON.
 * Each toggle increments it until reaching _transitionLimit.Thus, setFlashCount(1) = steady ON, setFlashCount(2) = ON-OFF-ON pattern, etc.
 */
void GFLEDStatusBlink::process()
{
	// get the number of elapsed millis for time calculations and store to local variable
	uint32_t now = millis();

	// implementation of the state machine
	switch (_state)
	{
	case E_GFLED_INIT:
		// this should only run once if we don't call the begin() method
		begin();
		break;

	case E_LED_TOFF:
		if (now - _ledTimer >= (uint32_t)_toff)
		{
			_ledTimer += (uint32_t)_toff;

			// LED turns ON immediately when re-entering TON
			on();
			_state = E_LED_TON;
			_transitionCount = 1; // start counting from first ON state
		}
		break;

	case E_LED_TON:
		if (now - _ledTimer >= (uint32_t)_flashTime)
		{
			_ledTimer += (uint32_t)_flashTime;

			toggle(); // this changes ON<->OFF
			if (++_transitionCount >= _transitionLimit)
			{
				off();
				_state = E_LED_TOFF;
			}
		}
		break;
	}
}

void GFLEDStatusBlink::setTiming(uint16_t ton, uint16_t toff)
{
	_ton = ton;
	_toff = toff;
	recalculateFlashTime();
}

void GFLEDStatusBlink::setFlashCount(uint8_t count)
{
	// don't let count be less than 1
	if (count == 0)
		count = 1;

	// turn off the LED
	off();

	// reset flash logic
	_transitionCount = 1;
	_transitionLimit = count * 2;
	recalculateFlashTime();

	// reset flash logic variables
	_state = E_LED_TOFF;
	_ledTimer = millis();
}

void GFLEDStatusBlink::setSpeedPreset(GFLEDSpeed speed)
{
	switch (speed)
	{
	case GFLEDSpeed::VERY_SLOW:
		setTiming(2000, 6000);
		break;
	case GFLEDSpeed::SLOW:
		setTiming(1000, 4000);
		break;
	case GFLEDSpeed::NORMAL:
		setTiming(1000, 2000);
		break;
	case GFLEDSpeed::FAST:
		setTiming(300, 700);
		break;
	case GFLEDSpeed::VERY_FAST:
		setTiming(150, 350);
		break;
	default:
		setTiming(1000, 2000);
		break;
	}
}