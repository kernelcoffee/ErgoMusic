#include "logger.h"
#include "common.h"
#include <QDir>
#include <iostream>
#include <QtCore/QStandardPaths>
#include <QDateTime>
#include <QMutexLocker>

const static QString    DEFAULT_LOG_DIR = QStandardPaths::writableLocation(QStandardPaths::DataLocation) + "/Kernelcoffee/ErgoMusic/logs";	///< Log directory
const static QString    DEFAULT_LOG_FILE = "logFile";	///< Log file name
const static QString    DEFAULT_LOG_EXT = "log";
const static bool       WRITE_IN_LOGFILE = true;
const static bool       WRITE_ON_OUTPUT = true;
QMutex mutex;

static const QString	logLevel_str[] = {
    "Debug",
    "Warning",
    "Critical",
    "Fatal",
    "Info"
};

inline QString	_getLogPrefix()
{
    return QDateTime::currentDateTimeUtc().toString("yyyy-MM-dd-hh:mm:ss") + " : ";
}

inline QString	_getLogFileName()
{
    return DEFAULT_LOG_DIR + "/" + DEFAULT_LOG_FILE + "_" + QDateTime::currentDateTime().toString("yyyyMMdd") + "." + DEFAULT_LOG_EXT;
}

inline void _print(QString &message, QtMsgType type)
{
    switch (type) {
    case QtDebugMsg:
    case QtInfoMsg:
        std::cout << message.toLocal8Bit().constData();
        break;
    case QtWarningMsg:
    case QtCriticalMsg:
    case QtFatalMsg:
        std::cerr << message.toLocal8Bit().constData();
        break;
    default:
        Q_UNREACHABLE();
    }
}

Logger::Logger(QObject *parent) :
    QObject(parent)
  , m_logFile(nullptr)
{
    _write(_getLogPrefix() + QStringLiteral("---- NEW SESSION ----\n"));
}

Logger::~Logger()
{
    if (m_logFile) {
        if (m_logFile->isOpen())
            m_logFile->close();
        delete m_logFile;
    }
}

void Logger::log(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QMutexLocker locker(&mutex);

    QString message = _getLogPrefix()
            + logLevel_str[type]
            + ", " + context.file
            + ", " + QString::number(context.line)
            + ", " + context.function
            + ", " + msg
            + "\n";

    Logger::instance()->_write(message);

    if (WRITE_ON_OUTPUT)
        _print(message, type);

    if (type == QtFatalMsg)
        abort();
}

void Logger::notice(const QString &msg)
{
    QString message = _getLogPrefix() + msg + "\n";

    _print(message, QtMsgType::QtInfoMsg);
    Logger::instance()->_write(message);
}

void Logger::_write(const QString &msg)
{
    if (!WRITE_IN_LOGFILE)
        return;

    if (m_logFile == nullptr || !m_logFile->exists()) {
        QDir dir(DEFAULT_LOG_DIR);
        if (dir.exists() == false)
            dir.mkpath(DEFAULT_LOG_DIR);
        if (m_logFile) {
            m_logFile->close();
            delete m_logFile;
        }
        m_logFile = new QFile(_getLogFileName());
        if (m_logFile->isOpen() == false)
            m_logFile->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    }

    m_logFile->write(msg.toLocal8Bit());
    m_logFile->flush();
}
