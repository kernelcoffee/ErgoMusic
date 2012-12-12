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

#include "logger.h"

#include <QDateTime>
#include <QDir>
#include <QDebug>

static const QString	logLevel_str[] = {
    "CRITICAL",
    "ERROR",
    "WARNING",
    "NOTICE",
    "INFO",
    "DEBUG"
};

Logger::Logger()
{
    QDir	dir;

    dir.mkpath(DEFAULT_LOG_DIR);
    _logFile = new QFile(getLogFileName());
    _logFile->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    _logFile->write(getLogHeader().toLatin1());
}

Logger::~Logger()
{
    _logFile->close();
    delete _logFile;
}

void	Logger::log(const QString &message, logLevel level)
{
    if (level < LOG_CRIT) {
        exit(-1);
    }
    Logger::instance()->update(message, level);
}

void	Logger::update(QString msg, logLevel level)
{
    QString	logMessage;

    logMessage = getLogPrefix();
    logMessage += logLevel_str[level] + " : " + msg + "\n";

    if (level == LOG_DEBUG && DEBUG_MODE)
        qDebug() << logLevel_str[level] + " : " + msg;
    _logFile->write(logMessage.toUtf8());
    _logFile->flush();
}

QString	Logger::getLogFileName()
{
    return DEFAULT_LOG_DIR + "/" + DEFAULT_LOG_FILE + "_" + QDateTime::currentDateTime().toString("yyyyMMdd") + "." + DEFAULT_LOG_EXT;
}

QString	Logger::getLogPrefix()
{
    return "<" + QDateTime::currentDateTimeUtc().toString("yyyy-MM-dd-hh:mm:ss") + "> : ";
}

QString Logger::getLogHeader()
{
    return "\n# -- Starting new session --";
}
