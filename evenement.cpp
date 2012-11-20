#include "evenement.h"

Evenement::Evenement(int id, QString nom)
           : m_id(id), m_nom(nom)
{
}

QString Evenement::getNom() const
{
    return m_nom;
}

QList<Requit*> Evenement::getRequits() const
{
    return m_requits;
}

int Evenement::getId() const
{
    return m_id;
}


void Evenement::setListeRequits(QList<Requit*> listeRequit)
{
    m_requits = listeRequit;
}
