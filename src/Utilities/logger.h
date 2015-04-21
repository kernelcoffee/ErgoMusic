#ifndef LOGGER_H
#define LOGGER_H

#include "singleton.h"
#include <QString>
#include <QFile>

// This log class was made to be used within the Qt messageHandler system
// http://qt-project.org/doc/qt-5/qtglobal.html#qInstallMessageHandler
// If you intent to other levels for debug, please create another class.

class Logger : public QObject, public Singleton<Logger>
{
    friend class Singleton<Logger>;

    Q_OBJECT
public:
    static void	log(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    static void	notice(const QString &msg);

signals:
    void    notify(QString, QString);

protected:
    explicit Logger(QObject *parent = 0);
    ~Logger();
private:
    void		_write(const QString &msg);
    QString		_getLogFileName();
    QString		_getLogPrefix();
    QString		_getLogHeader();
    QString		_getLogFilePath();

    QString		_logFilePath;

    QFile*		_logFile;
};

#endif // LOGGER_H
