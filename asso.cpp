#include "asso.h"

Asso::Asso(int id, QString nom)
    : m_id(id), m_nom(nom)
{
}

bool Asso::haveEvent() const
{
    return !m_evenements.isEmpty();
}

QString Asso::getNom() const
{
    return m_nom;
}

int Asso::getId() const
{
    return m_id;
}

const QList<Evenement*> Asso::getEvents() const
{
    return m_evenements;
}

const QList<Requit*> Asso::getRequits() const
{
    return m_requits;
}

void Asso::addEvent(Evenement* event)
{
    m_evenements.append(event);
}

void Asso::addRequit(Requit* requit)
{
    m_requits.append(requit);
}


void Asso::addEvent(QList<Evenement*> events)
{
    m_evenements.append(events);
}

void Asso::addRequit(QList<Requit*> requits)
{
    m_requits.append(requits);
}
