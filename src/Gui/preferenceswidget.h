#ifndef PREFERENCESWIDGET_H
#define PREFERENCESWIDGET_H

#include "ui_preferenceswidget.h"

class PreferencesWidget : public QDialog, private Ui::PreferencesWidget
{
    Q_OBJECT
    
public:
    explicit PreferencesWidget(QWidget *parent = 0);
};

#endif // PREFERENCESWIDGET_H
