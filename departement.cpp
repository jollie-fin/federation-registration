#include "departement.h"

Departement::Departement(int id, QString name, QString abreviation)
    : m_id(id), m_name(name), m_abreviation(abreviation)
{
}

int Departement::getId() const
{
    return m_id;
}

QString Departement::getName() const
{
    return m_name;
}

QString Departement::getAvreviation() const
{
    return m_abreviation;
}
