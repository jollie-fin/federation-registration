#include "personne.h"

Personne::Personne()
    : m_packCulture(false), m_packCithemuses(false)
{
}

QString Personne::getLogin()
{
    return m_login;
}

QString Personne::getNom()
{
    return m_nom;
}

QString Personne::getPrenom()
{
    return m_prenom;
}

QDate Personne::getNaissance()
{
    return m_naissance;
}

QString Personne::getEmail()
{
    return m_email;
}

Statut* Personne::getStatut()
{
    return m_statut;
}

QString Personne::getNumero()
{
    return m_numero;
}

QString Personne::getAdresse()
{
    return m_adresse;
}

QString Personne::getCp()
{
    return m_cp;
}

int Personne::getPromo()
{
    return m_promo;
}

Departement* Personne::getDepartement()
{
    return m_departement;
}

QString Personne::getCommentaireIdentite()
{
    return m_commentaireIdentite;
}

bool Personne::getListeFede()
{
    return m_listeFede;
}

bool Personne::getAnnuaire()
{
    return m_annuaire;
}

double Personne::getAPayer()
{
    return m_apayer;
}

QList<Asso*> Personne::getListeAssos()
{
    return m_listeAssos;
}

QList<Evenement*> Personne::getListeEvents()
{
    return m_listeEvents;
}

QList<RequitChoix*> Personne::getListeRequits()
{
    return m_listeRequits;
}

void Personne::setLogin(QString login)
{
    m_login = login;
}

void Personne::setNom(QString nom)
{
    m_nom = nom;
}

void Personne::setPrenom(QString prenom)
{
    m_prenom = prenom;
}

void Personne::setNaissance(QDate naissance)
{
    m_naissance = naissance;
}

void Personne::setEmail(QString email)
{
    m_email = email;
}

void Personne::setStatut(Statut* status)
{
    m_statut = status;
}

void Personne::setNumero(QString numero)
{
    m_numero = numero;
}

void Personne::setAdresse(QString adresse)
{
    m_adresse = adresse;
}

void Personne::setCp(QString cp)
{
    m_cp = cp;
}

void Personne::setPromo(int promo)
{
    m_promo = promo;
}

void Personne::setDepartement(Departement* departement)
{
    m_departement = departement;
}

void Personne::setCommentaireIdentite(QString commentaireIdentite)

{
    m_commentaireIdentite = commentaireIdentite;
}

void Personne::setlisteFede(bool listeFede)
{
    m_listeFede = listeFede;
}

void Personne::setAnnuaire(bool annuaire)
{
    m_annuaire = annuaire;
}

void Personne::setAPayer(double apayer)
{
    m_apayer = apayer;
}

void Personne::setListeAssos(QList<Asso*> listeAssos)
{
    m_listeAssos = listeAssos;
}

void Personne::setListeEvents(QList<Evenement*> listeEvents)
{
    m_listeEvents = listeEvents;
}

void Personne::setListeRequits(QList<RequitChoix*> listeRequits)
{
    m_listeRequits = listeRequits;
}

bool Personne::getPackCulture() const
{
    return m_packCulture;
}

bool Personne::getPackCithemuses() const
{
    return m_packCithemuses;
}

void Personne::setPackCulture(bool packCulture)
{
    m_packCulture = packCulture;
}

void Personne::setPackCithemuses(bool packCithemuses)
{
    m_packCithemuses = packCithemuses;
}
