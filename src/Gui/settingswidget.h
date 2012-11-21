#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include "ui_settingswidget.h"

class SettingsWidget : public QDialog, private Ui::SettingsWidget
{
    Q_OBJECT
    
public:
    explicit SettingsWidget(QWidget *parent = 0);
    ~SettingsWidget();
};

#endif // SETTINGSWIDGET_H
