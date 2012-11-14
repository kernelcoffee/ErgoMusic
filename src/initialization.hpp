/**
 * ErgoMusic - Simple music player and music library manager.
 * Copyright (C) 2011-2012 Alexandre Moore <alexandre.moore@kernelcoffee.org>
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

#ifndef INITIALIZATION_HPP
#define INITIALIZATION_HPP

#include <QSplashScreen>
#include <QtCore/QTranslator>

class Initialization
{
public:
    Initialization(void);
    ~Initialization(void);
    void    initSettings(void);
    void    initManagers(void);

private:
    void    initDefault(void);

    QTranslator*    _translator;
    QStringList     _arguments;
};

#endif // INITIALIZATION_HPP
