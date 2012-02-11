#ifndef INITIALIZATION_HPP
#define INITIALIZATION_HPP

#include <QSplashScreen>
#include <QTranslator>

#include "Utilities/sharedobject.hpp"

class Initialization
{
public:
    Initialization(void);
    ~Initialization(void);
private:
    void    initDefault(void);
    void    initSettings(void);

    QTranslator*    _translator;
    QStringList     _arguments;
};

#endif // INITIALIZATION_HPP
