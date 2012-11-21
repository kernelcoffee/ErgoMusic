#include "settingswidget.h"
#include "Utilities/logger.h"

#include <QTabWidget>
#include <QFileDialog>
#include <QDialogButtonBox>
#include <QSettings>

SettingsWidget::SettingsWidget(QWidget *parent) :
    QDialog(parent)
{
    QSettings settings;

    Logger::log("init SettingsWidget", LOG_DEBUG);

    setupUi(this);

    tabWidget->setCurrentIndex(0);
    tabWidget->setTabText(0, tr("&general"));
    tabWidget->setTabText(1, tr("&playback"));

    tabWidget->setTabText(2, tr("&advanced"));
    watchFolderLabel->setText(settings.value("watchFolder").toString());
    musicFolderLabel->setText(settings.value("musicFolder").toString());
    databaseFolderLabel->setText(settings.value("dbPath").toString());
}

SettingsWidget::~SettingsWidget()
{
    Logger::log("destroying SettingsWidget", LOG_DEBUG);
}

void SettingsWidget::on_musicFolderEditButton_clicked()
{
    QSettings   settings;

    QDir dir = QFileDialog::getExistingDirectory(this, tr("open directory"), settings.value("musicFolder").toString());
    if (dir.exists())
    {
        musicFolderLabel->setText(dir.absolutePath());
    }
}

void SettingsWidget::on_watchFolderEditButton_clicked()
{

}

void SettingsWidget::on_databaseEditButton_clicked()
{

}

void SettingsWidget::on_validationBox_clicked(QAbstractButton *button)
{
    Logger::log("Cliqued on button");
}

void    SettingsWidget::apply()
{
    QSettings   settings;

    if (musicFolderLabel->text() != settings.value("musicFolder").toString())
    {
        settings.setValue("musicFolder", QVariant(musicFolderLabel->text()));
        musicFolderPath_changed();
    }
    if (watchFolderLabel->text() != settings.value("watchFolder").toString())
    {
        settings.setValue("watchFolderLabel", QVariant(musicFolderLabel->text()));
        watchFolderPath_changed();
    }
    if (databaseFolderLabel->text() != settings.value("dbPath").toString())
    {
        settings.setValue("dbPath", QVariant(databaseFolderLabel->text()));
        databaseFolderPath_changed();
    }
}



void SettingsWidget::on_validationBox_accepted()
{
    Logger::log("Settings validated");
}
