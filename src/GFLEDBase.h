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

// Forward declaration of IGFLEDDriver
class IGFLEDDriver;

/**
 * This is the base class for all GFLED classes. It provides the basic functionality to control
 * the LED state (on, off, toggle) and to initialize the hardware.
 */
class GFLEDBase : public IGFLEDBehavior
{
public:
	/**
	 * @brief Constructor for GFLEDBase. Accepts an object implementing the IGFLEDDriver interface.
	 *
	 * @param driver Reference to an IGFLEDDriver implementation.
	 */
	explicit GFLEDBase(IGFLEDDriver &driver);

	/**
	 * @brief Virtual destructor.
	 */
	virtual ~GFLEDBase() = default;

	/**
	 * @brief Prepares the GFLEDBase object for operation.
	 */
	virtual void begin() override;

protected:
	/**
	 * @brief Turns the LED on.
	 */
	void on();

	/**
	 * @brief Turns the LED off.
	 */
	void off();

	/**
	 * @brief Toggles the LED state.
	 */
	void toggle();

	/**
	 * Helper variable used for timing operations, can be used in derived classes to keep track of time.
	 */
	uint32_t _ledTimer = 0;

	/**
	 * Tracks the current state of the LED (on/off).
	 */
	bool _toggle = false;

	/**
	 * Reference to the IGFLEDDriver implementation used to control the LED hardware.
	 */
	IGFLEDDriver &_driver;
};