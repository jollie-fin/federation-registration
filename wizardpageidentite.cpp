#include "wizardpageidentite.h"
#include "ui_wizardpageidentite.h"

#include <QMessageBox>

#include "ressourcemanager.h"

WizardPageIdentite::WizardPageIdentite(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageIdentite)
{
    ui->setupUi(this);

    connect(ui->emailLineEdit, SIGNAL(selectionChanged()), this, SLOT(generateEmail()));

    foreach (Statut* statut, RessourceManager::getInstance()->getListeStatut()) {
        ui->statutComboBox->addItem(statut->getName(), statut->getId());
    }

    foreach (Departement* statut, RessourceManager::getInstance()->getListeDepartement() ) {
        ui->dPartementComboBox->addItem(statut->getName(), statut->getId());
    }
}

WizardPageIdentite::~WizardPageIdentite()
{
    delete ui;
}

void WizardPageIdentite::generateEmail()
{
    if(ui->emailLineEdit->text().isEmpty())
    {
        QString adresse = ui->prenomLineEdit->text().toLower().remove(' ').remove('\'').remove('-');
        adresse += "." + ui->nomLineEdit->text().toLower().remove(' ').remove('\'').remove('-');
        adresse += "@ens-lyon.fr";

        ui->emailLineEdit->setText(adresse);
    }
}

bool WizardPageIdentite::validatePage()
{
    //QMessageBox::information(this, "ValidatePage", "ValidatePage");

    if(ui->nomLineEdit->text().isEmpty() || ui->prenomLineEdit->text().isEmpty() || ui->emailLineEdit->text().isEmpty())
        return false;
    else
    {
        Personne* perso = RessourceManager::getInstance()->getCurrentPersonne();

        perso->setNom(ui->nomLineEdit->text());
        perso->setPrenom(ui->prenomLineEdit->text());
        perso->setNaissance(ui->dateDeNaissanceDateEdit->date());
        perso->setEmail(ui->emailLineEdit->text());
        perso->setNumero(ui->numeroLineEdit->text());
        perso->setAdresse(ui->adresseLineEdit->text());
        perso->setCp(ui->codePostaleVilleLineEdit->text());

        foreach (Statut* statut, RessourceManager::getInstance()->getListeStatut()) {
            if(ui->statutComboBox->itemData(ui->statutComboBox->currentIndex()).toInt() == statut->getId())
            {
                perso->setStatut(statut);
            }
        }

        perso->setPromo(ui->promoSpinBox->value());

        foreach (Departement* dep, RessourceManager::getInstance()->getListeDepartement()) {
            if(ui->dPartementComboBox->itemData(ui->dPartementComboBox->currentIndex()).toInt() == dep->getId())
            {
                perso->setDepartement(dep);
            }
        }

        perso->setCommentaireIdentite(ui->commentaireLineEdit->text());
        perso->setlisteFede(ui->diffusionFederationCheckBox->isChecked());
        perso->setAnnuaire(ui->annuaireCheckBox->isChecked());

        return true;
    }
}

