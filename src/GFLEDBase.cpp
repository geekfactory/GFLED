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

#include "GFLEDBase.h"

GFLEDBase::GFLEDBase(IGFLEDDriver &driver) : _driver(driver) {}

void GFLEDBase::begin()
{
	_driver.initialize();
	_ledTimer = millis();
}

void GFLEDBase::on()
{
	_driver.setState(true);
	_toggle = true;
}

void GFLEDBase::off()
{
	_driver.setState(false);
	_toggle = false;
}

void GFLEDBase::toggle()
{
	_driver.setState(!_toggle);
	_toggle = !_toggle;
}