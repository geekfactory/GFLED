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
#include "GFLEDEnums.h"

/**
 * @brief Interface that defines the methods required to initialize, turn on and off a LED.
 *
 */
class IGFLEDDriver
{
public:
	virtual void initialize() = 0;
	virtual void setState(bool on) = 0;
	virtual ~IGFLEDDriver() = default;
};

/**
 * @brief Inteface that defines the methods required to set the color of a multiple color (RGB) LED.
 */
class IGFLEDDriverColor
{
public:
	virtual void setColor(GFLEDColor color) = 0;
	virtual void setColor(uint8_t r, uint8_t g, uint8_t b) = 0;
	virtual ~IGFLEDDriverColor() = default;
};

/**
 * @brief Inteface to define the methods where the LED behavior is handled.
 */
class IGFLEDBehavior
{
public:
	/**
	 * @brief Virtual method that should implement the hardware initialziation.
	 */
	virtual void begin() = 0;

	/**
	 * @brief Virtual method that should implement the behavior of of the LED.
	 */
	virtual void process() = 0;

	/**
	 * @brief Destroy the IGFLEDBehavior object
	 */
	virtual ~IGFLEDBehavior() = default;
};