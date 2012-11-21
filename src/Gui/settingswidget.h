#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include "ui_settingswidget.h"

class SettingsWidget : public QDialog, private Ui::SettingsWidget
{
    Q_OBJECT
    
public:
    explicit SettingsWidget(QWidget *parent = 0);
    ~SettingsWidget();
private slots:
    void on_musicFolderEditButton_clicked();
    void on_watchFolderEditButton_clicked();
    void on_databaseEditButton_clicked();
    void on_validationBox_clicked(QAbstractButton *button);

    void on_validationBox_accepted();

signals:
    void    musicFolderPath_changed();
    void    watchFolderPath_changed();
    void    databaseFolderPath_changed();
private:
    void    apply();
};

#endif // SETTINGSWIDGET_H
