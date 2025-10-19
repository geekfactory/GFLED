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

/**
 * Enumeration for the colors supported by the GFLED library.
 * These colors can be used with RGB LEDs or dual color LEDs.
 */
enum class GFLEDColor : uint8_t
{
	OFF = 0x00,
	RED = 0x01,
	GREEN = 0x02,
	BLUE = 0x04,
	YELLOW = RED | GREEN,
	PURPLE = RED | BLUE,
	CYAN = GREEN | BLUE,
	WHITE = RED | GREEN | BLUE,
};

/**
 * Enumeration for the speed presets supported by the GFLED library.
 * These presets can be used to quickly set the blink speed of the LED.
 */
enum class GFLEDSpeed : uint8_t
{
	VERY_SLOW = 0,
	SLOW,
	NORMAL,
	FAST,
	VERY_FAST,
};

inline GFLEDColor operator|(GFLEDColor a, GFLEDColor b)
{
	return static_cast<GFLEDColor>(static_cast<uint8_t>(a) | static_cast<uint8_t>(b));
}

inline bool operator&(GFLEDColor a, GFLEDColor b)
{
	return static_cast<uint8_t>(a) & static_cast<uint8_t>(b);
}