/**
 * ErgoMusic - Simple music player and music library manager.
 * Copyright (C) 2011 Alexandre Moore <alexandre.moore@kernelcoffee.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SHAREDOBJECT_HPP
#define SHAREDOBJECT_HPP

#include <QSettings>

#include "singleton.hpp"

const static QString	APPLICATION_VERSION	= "0.0.1";
const static QString	APPLICATION_NAME	= "ErgoMusic";

const static QString	ORGANIZATION_DOMAIN	= "kernelcoffee.org";
const static QString	ORGANIZATION_NAME	= "KernelCoffee";


class SharedObject : public Singleton<SharedObject>
{
    friend class	Singleton<SharedObject>;

public:
    SharedObject();
    ~SharedObject();
private:
};

#endif // SHAREDOBJECT_HPP
