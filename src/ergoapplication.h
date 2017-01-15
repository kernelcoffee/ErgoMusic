#ifndef ERGOAPPLICATION_H
#define ERGOAPPLICATION_H

#include <QApplication>
#include <QTranslator>

class SingleInstance;

class ErgoApplication : public QApplication
{
    Q_OBJECT
public:
    explicit ErgoApplication(int &argc, char **argv);
    ~ErgoApplication();

public slots:
    bool updateLanguage(const QString &lang);

private:
    QTranslator*    m_translator;
    SingleInstance* m_instance;

};

#endif // ERGOAPPLICATION_H
