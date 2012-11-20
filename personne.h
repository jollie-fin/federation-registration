#ifndef PERSONNE_H
#define PERSONNE_H

#include <QString>
#include <QList>
#include <QDate>

#include "asso.h"
#include "evenement.h"
#include "statut.h"
#include "departement.h"
#include "requitchoix.h"

class Personne
{
public:
    Personne();

    QString getLogin();
    QString getNom();
    QString getPrenom();
    QDate getNaissance();
    QString getEmail();
    Statut*  getStatut();
    QString getNumero();
    QString getAdresse();
    QString getCp();
    int getPromo();
    Departement* getDepartement();
    QString getCommentaireIdentite();
    bool getListeFede();
    bool getAnnuaire();

    double getAPayer();

    bool getPackCulture() const;
    bool getPackCithemuses() const;

    QList<Asso*> getListeAssos();
    QList<Evenement*> getListeEvents();
    QList<RequitChoix*> getListeRequits();

    void setLogin(QString login);
    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setNaissance(QDate naissance);
    void setEmail(QString email);
    void setStatut(Statut* status);
    void setNumero(QString numero);
    void setAdresse(QString adresse);
    void setCp(QString cp);
    void setPromo(int promo);
    void setDepartement(Departement* departement);
    void setCommentaireIdentite(QString commentaireIdentite);
    void setlisteFede(bool listeFede);
    void setAnnuaire(bool annuaire);

    void setAPayer(double apayer);

    void setPackCulture(bool packCulture);
    void setPackCithemuses(bool packCithemuses);

    void setListeAssos(QList<Asso*> listeAssos);
    void setListeEvents(QList<Evenement*> listeEvents);
    void setListeRequits(QList<RequitChoix*> listeRequits);
private:
    QString m_login;

    QString m_nom;
    QString m_prenom;

    QDate m_naissance;

    Statut* m_statut;

    QString m_email;

    QString m_numero;
    QString m_adresse;
    QString m_cp;

    int m_promo;

    Departement* m_departement;

    QString m_commentaireIdentite;

    bool m_listeFede;
    bool m_annuaire;

    double m_apayer;

    bool m_packCulture;
    bool m_packCithemuses;

    QList<Asso*> m_listeAssos;
    QList<Evenement*> m_listeEvents;
    QList<RequitChoix*> m_listeRequits;
};

#endif // PERSONNE_H
