#include "dbmanager.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QVariant>
#include <QSqlError>
#include <QMessageBox>

#include "personne.h"
#include "paiment.h"

struct tarif
{
    tarif(double prix, int asso, int statut, int id)
        : m_prix(prix), m_asso(asso), m_statut(statut), m_id(id)
    {
    };

    double m_prix;
    int m_asso;
    int m_statut;
    int m_id;
};

DBManager::DBManager()
{
    m_db = QSqlDatabase::database();
}

DBManager::~DBManager()
{
    m_db.close();
}

QList<Asso*> DBManager::getListeAsso()
{
    QSqlQuery q("Select * from asso");
    QSqlRecord rec = q.record();

    qDebug() << "GetListeAsso";

    QList<Asso*> liste;

    int nameCol = rec.indexOf("name");
    int idCol = rec.indexOf("id");

    while (q.next()) {
        Asso* asso = new Asso(q.value(idCol).toInt(), q.value(nameCol).toString());
        qDebug() << q.value(nameCol).toString(); // output all names
        liste.append(asso);
    }

    return liste;
}

QList<Requit*> DBManager::getListeRequitAsso(int asso)
{
    QSqlQuery q("Select * from asso_requit where asso = " + QString::number(asso));
    QSqlRecord rec = q.record();

    qDebug() << "GetListeRequitAsso " << rec.count();

    QList<Requit*> liste;

    int requitCol = rec.indexOf("requit");

    while (q.next()) {
        liste.append( getRequit(q.value(requitCol).toInt()) );
    }

    return liste;
}


QList<Requit*> DBManager::getListeRequitEvent(int event)
{
    QSqlQuery q("Select * from evenement_requit where evenement = " + QString::number(event));
    QSqlRecord rec = q.record();

    qDebug() << "getListeRequitEvent " << rec.count();

    QList<Requit*> liste;

    int requitCol = rec.indexOf("requit");

    while (q.next()) {
        liste.append( getRequit(q.value(requitCol).toInt()) );
    }

    return liste;
}

QList<Evenement*> DBManager::getListeEvenement(int assoId)
{
    QSqlQuery q("Select * from evenement where asso = " + QString::number(assoId));
    QSqlRecord rec = q.record();

    qDebug() << "getListeEvenement " << rec.count();

    QList<Evenement*> liste;

    int nameCol = rec.indexOf("name");
    int idCol = rec.indexOf("id");

    while (q.next()) {
        Evenement* event = new Evenement(q.value(idCol).toInt(), q.value(nameCol).toString());
        qDebug() << q.value(nameCol).toString(); // output all names
        liste.append(event);
    }

    return liste;
}

QList<Statut*> DBManager::getListeStatut()
{
    QSqlQuery q("Select * from statut");
    QSqlRecord rec = q.record();

    qDebug() << "GetListeStatut";

    QList<Statut*> liste;

    int nameCol = rec.indexOf("name");
    int idCol = rec.indexOf("id");

    while (q.next()) {
        Statut* statut = new Statut(q.value(idCol).toInt(), q.value(nameCol).toString());
        qDebug() << q.value(nameCol).toString(); // output all names
        liste.append(statut);
    }

    return liste;
}

QList<Departement*> DBManager::getListeDepartement()
{
    QSqlQuery q("Select * from departement");
    QSqlRecord rec = q.record();

    qDebug() << "GetListeDepartement";

    QList<Departement*> liste;

    int nameCol = rec.indexOf("name");
    int idCol = rec.indexOf("id");
    int abreviationCol = rec.indexOf("abreviation");

    while (q.next()) {
        Departement* statut = new Departement(q.value(idCol).toInt(), q.value(nameCol).toString(), q.value(abreviationCol).toString());
        qDebug() << q.value(nameCol).toString(); // output all names
        liste.append(statut);
    }

    return liste;
}


Requit* DBManager::getRequit(int idRequit)
{
    QSqlQuery q("Select * from requit where id = " + QString::number(idRequit));
    QSqlRecord rec = q.record();

    int descriptionCol = rec.indexOf("description");
    int idCol = rec.indexOf("id");
    int editableCol = rec.indexOf("editable");
    int optionnelCol = rec.indexOf("optinnel");

    qDebug() << "getRequit " << rec.count();

    q.next();

        bool editable = false;
        bool optinnel = false;

        if(q.value(editableCol).toInt() == 1)
            editable = true;

        if(q.value(optionnelCol).toInt() == 1)
            optinnel = true;


        Requit* requit = new Requit(q.value(idCol).toInt(), q.value(descriptionCol).toString(), editable, optinnel);


    return requit;
}

QVector< QVector<double> > getTarifsAsso()
{
    QSqlQuery q("Select * from tarifAsso");
    QSqlRecord rec = q.record();

    int assoCol = rec.indexOf("asso");
    int idCol = rec.indexOf("id");
    int prixCol = rec.indexOf("prix");
    int statutCol = rec.indexOf("statut");

    int maxAsso = 1;
    int maxStatut = 1;

    QList<tarif> liste;

    while(q.next())
    {
        int tmpAsso = q.value(assoCol).toInt();
        int tmpStatut = q.value(statutCol).toInt();

        liste.append(tarif(q.value(prixCol).toDouble(), tmpAsso, tmpStatut, q.value(idCol).toInt()));

        if(tmpAsso > maxAsso)
            maxAsso = tmpAsso;

        if(tmpStatut > maxStatut)
            maxStatut = tmpStatut;
    }

    QVector< QVector<double> > tarifs(maxAsso + 1, QVector<double>(maxStatut + 1));

    foreach (const tarif& tmp, liste) {
        tarifs[tmp.m_asso][tmp.m_statut] = tmp.m_prix;
    }

    qDebug() << "TarifAsso";


    return tarifs;
}

QVector< QVector<double> > getTarifsEvent()
{
    QSqlQuery q("Select * from tarifEvent");
    QSqlRecord rec = q.record();

    int eventCol = rec.indexOf("event");
    int idCol = rec.indexOf("id");
    int prixCol = rec.indexOf("prix");
    int statutCol = rec.indexOf("statut");

    int maxEvent = 1;
    int maxStatut = 1;

    QList<tarif> liste;

    while(q.next())
    {
        int tmpEvent = q.value(eventCol).toInt();
        int tmpStatut = q.value(statutCol).toInt();

        liste.append(tarif(q.value(prixCol).toDouble(), tmpEvent, tmpStatut, q.value(idCol).toInt()));

        if(tmpEvent > maxEvent)
            maxEvent = tmpEvent;

        if(tmpStatut > maxStatut)
            maxStatut = tmpStatut;
    }

    QVector< QVector<double> > tarifs(maxEvent + 1, QVector<double>(maxStatut + 1));

    foreach (const tarif& tmp, liste) {
        tarifs[tmp.m_asso][tmp.m_statut] = tmp.m_prix;
    }


    qDebug() << "TarifEvent";

    return tarifs;
}

Prix* DBManager::getPrix()
{
    return new Prix(getTarifsAsso(), getTarifsEvent());
}


int DBManager::savePersonne(Personne* perso)
{
    QSqlQuery query;
    query.prepare("INSERT INTO personne (login, nom, prenom, email, naissance, numero, adresse, cp, statut, promo, departement, commentaireIdentite, listeFede, annuaire, apayer, packCulture, packCithemuse) "
                  "VALUES (:login, :nom, :prenom, :email, :naissance, :numero, :adresse, :cp, :statut, :promo, :departement, :commentaireIdentite, :listeFede, :annuaire, :apayer, :packCulture, :packCithemuse)");
    query.bindValue(":login", perso->getLogin());
    query.bindValue(":nom", perso->getNom());
    query.bindValue(":prenom", perso->getPrenom());
    query.bindValue(":email", perso->getEmail());
    query.bindValue(":naissance", perso->getNaissance().toString());
    query.bindValue(":numero", perso->getNumero());
    query.bindValue(":adresse", perso->getAdresse());
    query.bindValue(":cp", perso->getCp());
    query.bindValue(":statut", perso->getStatut()->getId());
    query.bindValue(":promo", perso->getPromo());
    query.bindValue(":departement", perso->getDepartement()->getId());
    query.bindValue(":commentaireIdentite", perso->getCommentaireIdentite());
    query.bindValue(":listeFede", perso->getListeFede());
    query.bindValue(":annuaire", perso->getAnnuaire());
    query.bindValue(":apayer", perso->getAPayer());
    query.bindValue(":packCulture", perso->getPackCulture());
    query.bindValue(":packCithemuse", perso->getPackCithemuses());
    query.exec();

    if(query.lastError().type() != QSqlError::NoError)
    {
        qDebug() << query.lastError().text();
        return -1;
    }

    QSqlQuery query2;
    query2.prepare("Select id from personne where login = :login AND nom = :nom AND prenom = :prenom AND naissance = :naissance");
    query2.bindValue(":login", perso->getLogin());
    query2.bindValue(":nom", perso->getNom());
    query2.bindValue(":prenom", perso->getPrenom());
    query2.bindValue(":naissance", perso->getNaissance().toString());
    query2.exec();

    if(query2.lastError().type() != QSqlError::NoError)
    {
        return -2;
    }

    query2.next();

    int id = query2.value(0).toInt();

    QSqlQuery query3;
    query3.prepare("INSERT INTO perso_asso (perso, asso) "
                   "VALUES (:perso, :asso)");

    foreach (Asso* asso, perso->getListeAssos()) {
        query3.bindValue(":perso", id);
        query3.bindValue(":asso", asso->getId());
        query3.exec();

        if(query3.lastError().type() != QSqlError::NoError)
        {
            return -3;
        }

    }

    if(!perso->getListeEvents().isEmpty())
    {
        QSqlQuery query4;
        query4.prepare("INSERT INTO perso_event (perso, event) "
                       "VALUES (:perso, :event)");

        foreach (Evenement* event, perso->getListeEvents()) {
            query4.bindValue(":perso", id);
            query4.bindValue(":event", event->getId());
            query4.exec();

            if(query4.lastError().type() != QSqlError::NoError)
            {
                return -4;
            }

        }
    }

    if(!perso->getListeRequits().isEmpty())
    {
        QSqlQuery query5;
        query5.prepare("INSERT INTO perso_requit (perso, requit, commentaire) "
                       "VALUES (:perso, :requit, :commentaire)");

        foreach (RequitChoix* requit, perso->getListeRequits()) {
            query5.bindValue(":perso", id);
            query5.bindValue(":requit", requit->getRequit()->getId());
            query5.bindValue(":commentaire", requit->getCommentaire());
            query5.exec();

            if(query5.lastError().type() != QSqlError::NoError)
            {
                return -5;
            }

        }
    }
    return id;
}

bool DBManager::afficheTrac()
{
    QSqlQuery q("Select count(*) from perso_asso where asso = 13");

    q.next();

    if(q.value(0).toInt() >= 80)
        return false;
    else
        return true;
}

InfoPersonne* DBManager::getByLogin(QString login)
{
    QSqlQuery q("Select id, nom, prenom, apayer from personne where login = '" + login +"'");
    QSqlRecord rec = q.record();

    qDebug() << "GetByLogin : " << "Select id, nom, prenom, apayer from personne where login = " + login;

    int nameCol = rec.indexOf("nom");
    int idCol = rec.indexOf("id");
    int prenomCol = rec.indexOf("prenom");
    int apayerCol = rec.indexOf("apayer");

    InfoPersonne* infoPersonne;

    if(q.next()) {
        infoPersonne = new InfoPersonne(q.value(idCol).toInt(), q.value(nameCol).toString(), q.value(prenomCol).toString(), q.value(apayerCol).toDouble());
        qDebug() << q.value(nameCol).toString(); // output all names
    }
    else{
        infoPersonne = new InfoPersonne(-1, "inconnu", "inconnu", 0);
    }

    return infoPersonne;
}

InfoPersonne* DBManager::getByIdentifiant(int identifiant)
{
    QSqlQuery q("Select id, nom, prenom, apayer from personne where id = " + QString::number(identifiant));
    QSqlRecord rec = q.record();

    qDebug() << "GetByID";

    int nameCol = rec.indexOf("nom");
    int idCol = rec.indexOf("id");
    int prenomCol = rec.indexOf("prenom");
    int apayerCol = rec.indexOf("apayer");

    InfoPersonne* infoPersonne;

    if(q.next()) {
        infoPersonne = new InfoPersonne(q.value(idCol).toInt(), q.value(nameCol).toString(), q.value(prenomCol).toString(), q.value(apayerCol).toDouble());
        qDebug() << q.value(nameCol).toString(); // output all names
    }
    else{
        infoPersonne = new InfoPersonne(-1, "inconnu", "inconnu", 0);
    }

    return infoPersonne;
}

bool DBManager::savePaiment(int id, QString modePaiment, bool differe)
{
    QSqlQuery query;
    query.prepare("Update personne SET paye = 1, modePaiment = :modePaiment, differe = :differe where id = :id");

    query.bindValue(":modePaiment", modePaiment);
    query.bindValue(":differe", differe);
    query.bindValue(":id", id);
    query.exec();

    if(query.lastError().type() != QSqlError::NoError)
    {
        return false;
    }

    return true;
}
