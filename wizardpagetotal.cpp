#include "wizardpagetotal.h"
#include "ui_wizardpagetotal.h"

#include "ressourcemanager.h"
#include "asso.h"
#include "prix.h"

WizardPageTotal::WizardPageTotal(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageTotal)
{
    ui->setupUi(this);
}

WizardPageTotal::~WizardPageTotal()
{
    delete ui;
}

// Todo : evenement
void WizardPageTotal::initializePage()
{

    double somme = 0;
    Prix* prix = RessourceManager::getInstance()->getPrix();

    bool cithemuses = false;
    bool enscene = false;
    bool ensplastik = false;
    bool transitor = false;
    bool champLibre = false;

    foreach (Asso* asso, RessourceManager::getInstance()->getCurrentPersonne()->getListeAssos()) {
        if(asso->getId() == 14)
        {
            cithemuses = true;
        }
        else if(asso->getId() == 2)
        {
            enscene = true;
        }
        else if(asso->getId() == 6)
        {
            ensplastik = true;
        }
        else if(asso->getId() == 5)
        {
            transitor = true;
        }
        else if(asso->getId() == 8)
        {
            champLibre = true;
        }

        somme += prix->getPrixAsso(asso->getId(), RessourceManager::getInstance()->getCurrentPersonne()->getStatut());
    }

    foreach (Evenement* asso, RessourceManager::getInstance()->getCurrentPersonne()->getListeEvents()) {
        somme += prix->getPrixEvent(asso->getId(), RessourceManager::getInstance()->getCurrentPersonne()->getStatut());
    }

    if(enscene && cithemuses)
    {
        if(RessourceManager::getInstance()->getCurrentPersonne()->getStatut()->getId() == 1)
        {
            somme -= 5;
        }
        else
        {
            somme -= 10;
        }

        RessourceManager::getInstance()->getCurrentPersonne()->setPackCithemuses(true);
   }

   if(enscene && ensplastik && champLibre && transitor)
   {
       if(RessourceManager::getInstance()->getCurrentPersonne()->getStatut()->getId() == 1)
       {
           somme -= 4;
       }
       else
       {
           somme -= 4;
       }

       RessourceManager::getInstance()->getCurrentPersonne()->setPackCulture(true);
   }

    ui->label_2->setText(QString::number(somme) + QString(" euro"));

    RessourceManager::getInstance()->getCurrentPersonne()->setAPayer(somme);
}
