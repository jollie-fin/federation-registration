#ifndef RESSOURCEMANAGER_H
#define RESSOURCEMANAGER_H

#include <QList>

#include "asso.h"
#include "personne.h"
#include "wizardpagerequit.h"

#include "dbmanager.h"
#include "statut.h"

#include "paiment.h"

class RessourceManager
{
public:
    static RessourceManager* getInstance();
    static void detruire();

    const QList<Asso*> getAssos() const;

    Personne* getCurrentPersonne();

    void setCurrentPersonne(Personne* personne);

    void setWizardPageRequit(WizardPageRequit* pageRequit);
    WizardPageRequit* getWizardPageRequit();

    QList<Statut*> getListeStatut() const;
    void setListeStatut(QList<Statut*> listeStatut);

    QList<Departement*> getListeDepartement() const;
    void setListeDepartement(QList<Departement*> listeDepartement);

    Prix* getPrix();

    Paiment* getPaiment();
    void setPaiment(Paiment* paiment);

    int savePersonne(Personne* perso);

    bool afficheTrac();

    DBManager* getDBManager();
private:
    RessourceManager();

    QList<Asso*> m_assos;
    Personne* m_currentPersonnes;
    WizardPageRequit* m_pageRequit;
    QList<Statut*> m_listeStatut;
    QList<Departement*> m_listeDepartement;
    Prix* m_prix;

    Paiment* m_paiment;

    DBManager m_dbManager;

    static RessourceManager * m_instance;
};

#endif // RESSOURCEMANAGER_H
