#include "wizardpageidentifiant.h"
#include "ui_wizardpageidentifiant.h"

#include "ressourcemanager.h"

WizardPageIdentifiant::WizardPageIdentifiant(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageIdentifiant)
{
    ui->setupUi(this);
}

WizardPageIdentifiant::~WizardPageIdentifiant()
{
    delete ui;
}

void WizardPageIdentifiant::initializePage()
{
    ui->label_2->setText(QString::number(RessourceManager::getInstance()->savePersonne(RessourceManager::getInstance()->getCurrentPersonne())));
}
