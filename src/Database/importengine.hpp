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


#ifndef IMPORTENGINE_HPP
#define IMPORTENGINE_HPP

#include <QFileSystemWatcher>
#include <QDir>
#include <QObject>

class ImportEngine : public QObject
{
    Q_OBJECT
public:
    explicit ImportEngine(QObject *parent = 0);
    ~ImportEngine();

signals:

public slots:

private:

};

#endif // IMPORTENGINE_HPP