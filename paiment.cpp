#include "paiment.h"

Paiment::Paiment(QString login, int identifiant)
    : m_login(login), m_identifiant(identifiant), m_infoPersonne(NULL)
{

}

QString Paiment::getLogin()
{
    return m_login;
}

int Paiment::getIdentifiant()
{
    return m_identifiant;
}

InfoPersonne* Paiment::getInfoPersonne()
{
    return m_infoPersonne;
}

void Paiment::setInfoPersonne(InfoPersonne* infoPerso)
{
    m_infoPersonne = infoPerso;
}
