#include "wizardpageloginiden.h"
#include "ui_wizardpageloginiden.h"

#include "ressourcemanager.h"

WizardPageLoginIden::WizardPageLoginIden(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageLoginIden)
{
    ui->setupUi(this);
}

WizardPageLoginIden::~WizardPageLoginIden()
{
    delete ui;
}

bool WizardPageLoginIden::validatePage()
{
    delete RessourceManager::getInstance()->getPaiment();
    RessourceManager::getInstance()->setPaiment(new Paiment(ui->loginLineEdit->text(), ui->identifiantSpinBox->value()));

    return true;
}
