#include "settingswidget.h"
#include "Utilities/logger.h"

#include <QTabWidget>
#include <QDialogButtonBox>

SettingsWidget::SettingsWidget(QWidget *parent) :
    QDialog(parent)
{
    Logger::log("init SettingsWidget", LOG_DEBUG);

    setupUi(this);
//    QTabWidget *tabView = new QTabWidget();
//    tabView->addTab()

//    QDialogButtonBox *buttonBox = new QDialogButtonBox();
//    buttonBox->setOrientation(Qt::Horizontal);
//    buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::Reset);

//    layout()->addWidget(tabViewb);
//    layout()->addWidget(buttonBox);
}

SettingsWidget::~SettingsWidget()
{
    Logger::log("destroying SettingsWidget", LOG_DEBUG);
}
