#ifndef DATABASECORE_H
#define DATABASECORE_H

#include "Abstracts/abstractcore.h"
#include "Handlers/dbhandlers.h"
#include <QSqlDatabase>

class DatabaseCore : public AbstractCore
{
    Q_OBJECT
public:
    explicit DatabaseCore(QObject *parent = 0);
    ~DatabaseCore();

    void    init();
    void    initSettings();
    void    initArguments(QCommandLineParser &cmd);
    void    processArguments(QCommandLineParser &cmd);

    int     currentMigration() const;   //< Get the current migration number

    DbHandlers* handlers() const;
signals:

public slots:
    void    delayedInit();
    void    aboutToQuit();

private:
    void    _openDatabase();
    void    _initDBInterfaces();

    QSqlDatabase    m_db;
    DbHandlers      *m_handlers;
};

#endif // DATABASECORE_H
