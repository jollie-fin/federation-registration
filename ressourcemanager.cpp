#include "ressourcemanager.h"

RessourceManager::RessourceManager()
{
    //Asso* tmp = new Asso(1, "BDE");
    //tmp->addEvent(new Evenement(1, "WEI"));
    //tmp->addRequit(new Requit(1, "Cheque de caution", false, false));
    //tmp->addRequit(new Requit(2, "Test", true, true));
    //m_assos.append(tmp);

    ////m_assos.append(new Asso(2, QString("ENSCENE")));
    ////m_assos.append(new Asso(3, "Rolf"));
    //m_assos.append(new Asso(4, "Chose"));

    m_currentPersonnes = NULL;

    foreach (Asso* asso, m_dbManager.getListeAsso()) {
        QList<Evenement*> listeEvent = m_dbManager.getListeEvenement(asso->getId());

        if(!listeEvent.isEmpty())
        {
            foreach (Evenement* event, listeEvent) {
                event->setListeRequits(m_dbManager.getListeRequitEvent(event->getId()));

                asso->addEvent(event);
            }
        }

        asso->addRequit(m_dbManager.getListeRequitAsso(asso->getId()));

        m_assos.append(asso);
    }

    setListeStatut(m_dbManager.getListeStatut());
    setListeDepartement(m_dbManager.getListeDepartement());

    m_prix = m_dbManager.getPrix();
    m_paiment = new Paiment("", 0);
}

RessourceManager* RessourceManager::getInstance()
{
    if(m_instance == NULL) {
        m_instance = new RessourceManager();
    }

    return m_instance;
}

void RessourceManager::detruire()
{
    if(m_instance != NULL)
        delete m_instance;
    m_instance = NULL;
}

const QList<Asso*> RessourceManager::getAssos() const
{
    return m_assos;
}

Personne* RessourceManager::getCurrentPersonne()
{
    return m_currentPersonnes;
}

void RessourceManager::setCurrentPersonne(Personne* personne)
{
    m_currentPersonnes = personne;
}

void RessourceManager::setWizardPageRequit(WizardPageRequit* pageRequit)
{
    m_pageRequit = pageRequit;
}

WizardPageRequit* RessourceManager::getWizardPageRequit()
{
    return m_pageRequit;
}

QList<Statut*> RessourceManager::getListeStatut() const
{
    return m_listeStatut;
}

void RessourceManager::setListeStatut(QList<Statut*> listeStatut)
{
    m_listeStatut = listeStatut;
}

QList<Departement*> RessourceManager::getListeDepartement() const
{
    return m_listeDepartement;
}

void RessourceManager::setListeDepartement(QList<Departement*> listeDepartement)
{
    m_listeDepartement = listeDepartement;
}

RessourceManager *RessourceManager::m_instance = NULL;

Prix* RessourceManager::getPrix()
{
    return m_prix;
}

int RessourceManager::savePersonne(Personne* perso)
{
    return m_dbManager.savePersonne(perso);
}

bool RessourceManager::afficheTrac()
{
    return m_dbManager.afficheTrac();
}

Paiment* RessourceManager::getPaiment()
{
    return m_paiment;
}

void RessourceManager::setPaiment(Paiment* paiment)
{
    m_paiment = paiment;
}


DBManager* RessourceManager::getDBManager()
{
    return &m_dbManager;
}
