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
    databaseFolderLabel->setText(settings.value("database/path").toString());

    checkBoxWatchFolder->setChecked(settings.value("watchFolderActivated").toBool());
    watchFolderLayer->setEnabled(checkBoxWatchFolder->isChecked());
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
    QSettings   settings;

    QDir dir = QFileDialog::getExistingDirectory(this, tr("open directory"), settings.value("watchFolder").toString());
    if (dir.exists())
    {
        watchFolderLabel->setText(dir.absolutePath());
    }
}

void SettingsWidget::on_databaseEditButton_clicked()
{
    QSettings   settings;

    QDir dir = QFileDialog::getExistingDirectory(this, tr("open directory"), settings.value("database/path").toString());
    if (dir.exists())
    {
        databaseFolderLabel->setText(dir.absolutePath());
    }

}


void SettingsWidget::on_buttonBox_clicked(QAbstractButton *button)
{
    // tried a switch, refused because it wasn't an integer
    if (button == buttonBox->button(QDialogButtonBox::Apply)) {
        apply();
    } else if (button == buttonBox->button(QDialogButtonBox::Reset)) {
        reset();
    } else if (button == buttonBox->button(QDialogButtonBox::Ok)) {
        apply();
        close();
    } else if (button == buttonBox->button(QDialogButtonBox::Cancel)) {
        reset();
        close();
    }
}

void    SettingsWidget::apply()
{
    QSettings   settings;

    Logger::log("Applying changes in settings", LOG_DEBUG);
    if (musicFolderLabel->text() != settings.value("musicFolder").toString())
    {
        settings.setValue("musicFolder", musicFolderLabel->text());
        Logger::log("Changed Music folder path to " + settings.value("musicFolder").toString());
        musicFolderPath_updated();
    }
    if (checkBoxWatchFolder->isChecked() != settings.value("watchFolderActivated").toBool())
    {
        Logger::log("WatchFolder status changed.");
        settings.setValue("watchFolderActivated", checkBoxWatchFolder->isChecked());
        watchFolderPath_updated();
    }
    if (watchFolderLabel->text() != settings.value("watchFolder").toString())
    {
        settings.setValue("watchFolder", watchFolderLabel->text());
        Logger::log("Changed Watch folder path to " + settings.value("watchFolder").toString());
        watchFolderPath_updated();
    }
    if (databaseFolderLabel->text() != settings.value("database/path").toString())
    {
        settings.setValue("database/path", databaseFolderLabel->text());
        Logger::log("Changed Database folder path to " + settings.value("database/path").toString());
        databaseFolderPath_updated();
    }
}

void    SettingsWidget::reset()
{
    QSettings   settings;

    musicFolderLabel->setText(settings.value("musicFolder").toString());
    watchFolderLabel->setText(settings.value("watchFolder").toString());
    databaseFolderLabel->setText(settings.value("database/path").toString());
}

void SettingsWidget::on_checkBoxWatchFolder_clicked(bool checked)
{
    QSettings settings;

    checkBoxWatchFolder->setChecked(checked);
    watchFolderLayer->setEnabled(checked);
}
