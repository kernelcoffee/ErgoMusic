#include "settingswidget.h"
#include "Utilities/logger.h"

SettingsWidget::SettingsWidget(QWidget *parent) :
    QDialog(parent)
{
    Logger::log("init SettingsWidget", LOG_DEBUG);

    setupUi(this);
}

SettingsWidget::~SettingsWidget()
{
    Logger::log("destroying SettingsWidget", LOG_DEBUG);
}
