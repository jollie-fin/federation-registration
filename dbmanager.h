#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QList>

#include "asso.h"
#include "requit.h"
#include "evenement.h"
#include "statut.h"
#include "departement.h"
#include "prix.h"
#include "infopersonne.h"

class DBManager
{
public:
    DBManager();
    ~DBManager();

    QList<Asso*> getListeAsso();
    QList<Evenement*> getListeEvenement(int asso);
    QList<Requit*> getListeRequitAsso(int asso);
    QList<Requit*> getListeRequitEvent(int event);
    QList<Statut*> getListeStatut();
    QList<Departement*> getListeDepartement();

    Requit* getRequit(int idRequit);

    Prix* getPrix();

    int savePersonne(Personne* perso);

    bool afficheTrac();

    InfoPersonne* getByLogin(QString login);
    InfoPersonne* getByIdentifiant(int identifiant);

    bool savePaiment(int id, QString modePaiment, bool differe);

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
