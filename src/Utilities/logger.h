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

#ifndef LOGGER_H
#define LOGGER_H

#include <QtCore/QFile>
#include <QtCore/QString>
#include <QtCore/QDebug>
#include <QtCore/QStandardPaths>
#include <QtCore/QSettings>

#include "common.h"
#include "singleton.h"

/**
 * This is my generic log management class.
 * It will log by day.
 * Linux : ~/.config/ORGANIZATION_NAME/APPLICATION_NAME/log_<date>.log
 * OS X  :
 * Windows :
 *
 * HOW TO USE IT
 * include this header file and use logger::log(<log_message>, <debug_level>);
 *
 * DEBUG LEVELS
 *
 * LOG_CRIT     This is catastrophic. Basically, the program can not recover
 *              from this. If you're going to log at this level provide
 *              as much information as possible.
 *
 * LOG_ERR      Okay, something bad happened. We can recover from this.
 *              This should be for things like when we cannot create
 *              a socket, or out of memory.
 *
 * LOG_WARNING  There is condition which will change the behaviour of
 *              the program from what is expected. For example, somebody did
 *              not specify a port for a socket.
 *
 * LOG_NOTICE   This is for a special condition. Nothing has gone wrong, but
 *              it is more important than the common LOG_INFO level.
 *              It is used for actions like creating/destroying children,
 *              unauthorized access, signal handling, etc.
 *
 * LOG_INFO     Everything else ends up here. Logging for incoming
 *              connections, denying due to filtering rules, unable to
 *              connect to remote server, etc.
 *
 * LOG_DEBUG    The default debug mode level for developping goodness.
 **/

const static QString DEFAULT_LOG_DIR = QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/" + ORGANIZATION_NAME + "/" + APPLICATION_NAME + "/logs";	///< Log directory
const static QString DEFAULT_LOG_FILE = "logFile";	///< Log file name
const static QString DEFAULT_LOG_EXT = "log";

enum	logLevel {
    LOG_CRIT,
    LOG_ERR,
    LOG_WARNING,
    LOG_NOTICE,
    LOG_INFO,
    LOG_DEBUG
};

class Logger : public	Singleton<Logger>
{
    friend class Singleton<Logger>;

public:
    static void	log(const QString &message, logLevel level = LOG_INFO);
protected:
    Logger();
    ~Logger();
private:
    void		update(QString msg, logLevel level);
    QString		getLogFileName();
    QString		getLogPrefix();
    QString		getLogHeader();
    QString		getLogFilePath();

    QString		_logFilePath;

    QFile*		_logFile;
};

#endif // LOGGER_H
