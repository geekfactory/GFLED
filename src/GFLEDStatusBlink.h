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
#include "GFLEDBase.h"

/**
 * Enumeration for the states of the finite state machine (FSM) used to control the LED blinking behavior.
 */
enum gfled_fsm_states
{
	E_GFLED_INIT,
	E_LED_TON,
	E_LED_TOFF,
};

/**
 * This class defines the behavior of a general purpose status LED that blinks whenever the
 * arduino program is running. The LED can be a single color LED, a dual color LED or an RGB LED
 * depending on the driver provided and the derived class used.
 */
class GFLEDStatusBlink : public GFLEDBase
{
public:
	explicit GFLEDStatusBlink(IGFLEDDriver &driver);

	/**
	 * @brief Initializes the GFLEDStatusBlink instance.
	 */
	void begin() override;

	/**
	 * @brief Processes the behavior of the blinking status LED.
	 */
	void process() override;

	/**
	 * @brief Sets the timing for the LED on and off durations.
	 *
	 * @param ton Duration in milliseconds for which the LED stays on during a blink cycle.
	 * @param toff Duration in milliseconds for which the LED stays off between blink cycles.
	 */
	void setTiming(uint16_t ton, uint16_t toff);

	/**
	 * @brief Sets the number of blinks in each blink cycle.
	 *
	 * @param count Number of blinks (toggles) in each blink cycle.
	 */
	void setFlashCount(uint8_t count);

	/**
	 * @brief Sets the blink speed using predefined speed presets.
	 *
	 * @param speed The desired blink speed preset from the GFLEDSpeed enumeration.
	 */
	void setSpeedPreset(GFLEDSpeed speed);

protected:
	uint16_t _ton = 1000;
	uint16_t _toff = 2000;

	uint16_t _flashTime = 1000;
	uint8_t _transitionCount = 1;
	uint8_t _transitionLimit = 2;

	enum gfled_fsm_states _state = E_GFLED_INIT;

private:
	inline void recalculateFlashTime()
	{
		_flashTime = (_transitionLimit > 1) ? _ton / (_transitionLimit - 1) : _ton;
	}
};