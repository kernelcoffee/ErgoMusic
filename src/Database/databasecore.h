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

    void    init() override;
    void    initSettings() override;
    void    initArguments(QCommandLineParser &parser) override;
    void    processArguments(QCommandLineParser &parser) override;

    int     currentMigration() const;   //< Get the current migration number

    DbHandlers* handlers() const;
signals:

public slots:
    void    delayedInit() override;
    void    onAboutToQuit() override;

private:
    void    _openDatabase();
    void    _initDBInterfaces();

    QSqlDatabase    m_db;
    DbHandlers      *m_handlers;
};

#endif // DATABASECORE_H
