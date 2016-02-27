#ifndef ERGOAPPLICATION_H
#define ERGOAPPLICATION_H

#include <QApplication>
#include <QTranslator>

class ErgoApplication : public QApplication
{
    Q_OBJECT
public:
    explicit ErgoApplication(int &argc, char **argv);

public slots:
    bool updateLanguage(const QString &lang);

private:
    QTranslator*    m_translator;

};

#endif // ERGOAPPLICATION_H
