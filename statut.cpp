#include "statut.h"

Statut::Statut(int id, QString name)
    : m_id(id), m_name(name)
{
}

int Statut::getId() const
{
    return m_id;
}

QString Statut::getName() const
{
    return m_name;
}
