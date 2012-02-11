#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <QFile>
#include <QString>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QDesktopServices>

#include "sharedobject.hpp"

/**
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

const static QString DEFAULT_LOG_DIR = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/" + ORGANIZATION_NAME + "/" + APPLICATION_NAME + "/logs";	///< Log directory
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

enum	notifyLevel {
    NOTIFY_NOICON,
    NOTIFY_INFORMATION,
    NOTIFY_WARNING,
    NOTIFY_CRITICAL
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

#endif // LOGGER_HPP
