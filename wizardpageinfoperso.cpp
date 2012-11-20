#include "wizardpageinfoperso.h"
#include "ui_wizardpageinfoperso.h"

#include "ressourcemanager.h"

#include <QMessageBox>

WizardPageInfoPerso::WizardPageInfoPerso(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageInfoPerso)
{
    ui->setupUi(this);
}

WizardPageInfoPerso::~WizardPageInfoPerso()
{
    delete ui;
}

void WizardPageInfoPerso::initializePage()
{
    RessourceManager* rm = RessourceManager::getInstance();

    if(!rm->getPaiment()->getLogin().isEmpty())
    {
        m_infoPersonne = rm->getDBManager()->getByLogin(rm->getPaiment()->getLogin());
    }
    else{
        m_infoPersonne = rm->getDBManager()->getByIdentifiant(rm->getPaiment()->getIdentifiant());
    }

    ui->nom->setText(m_infoPersonne->getNom());
    ui->prenom->setText(m_infoPersonne->getPrenom());
    ui->paiment->setText(QString::number(m_infoPersonne->getPrix()));
}

bool WizardPageInfoPerso::validatePage()
{
    if(m_infoPersonne->getIdentifiant() == -1)
        return false;

    if(!RessourceManager::getInstance()->getDBManager()->savePaiment(m_infoPersonne->getIdentifiant(), ui->comboBox->currentText(), ui->checkBox->isChecked()))
    {
        QMessageBox::warning(this, "Erreur !!!", "Le paiment n'a pas été enregistré.\nContacté Damien Reimert.");
        return false;
    }

    return true;
}
