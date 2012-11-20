#include "wizardpagelogin.h"
#include "ui_wizardpagelogin.h"

#include "ressourcemanager.h"

WizardPageLogin::WizardPageLogin(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageLogin)
{
    ui->setupUi(this);
}

WizardPageLogin::~WizardPageLogin()
{
    delete ui;
}

bool WizardPageLogin::validatePage()
{
    if(ui->loginLineEdit->text().size() < 2 && !ui->checkBox->isChecked())
        return false;
    else
    {
        if(!ui->checkBox->isChecked())
        {
            RessourceManager::getInstance()->getCurrentPersonne()->setLogin(ui->loginLineEdit->text().toLower());
        }

        return true;
    }
}

void WizardPageLogin::initializePage()
{
    delete RessourceManager::getInstance()->getCurrentPersonne();
    RessourceManager::getInstance()->setCurrentPersonne(new Personne());
}
