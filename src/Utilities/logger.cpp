#include "logger.hpp"

#include <QDateTime>
#include <QDir>
#include <QSettings>
#include <QDesktopServices>


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
    _logFile->write(getLogHeader().toAscii());
}

Logger::~Logger()
{
    _logFile->close();
    delete _logFile;
}

void	Logger::log(const QString &message, logLevel level)
{
    Logger::instance()->update(message, level);
}

void	Logger::update(QString msg, logLevel level)
{
    QString	logMessage;

    logMessage = getLogPrefix();
    logMessage += logLevel_str[level] + " : " + msg + "\n";

    qDebug() << logLevel_str[level] << " : " << msg;
    _logFile->write(logMessage.toAscii());
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
