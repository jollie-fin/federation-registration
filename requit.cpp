#include "requit.h"

Requit::Requit(int id, QString description, bool editable, bool optionnel)
    : m_id(id), m_description(description), m_editable(editable), m_optionnel(optionnel)
{
}

QString Requit::getDescription() const
{
    return m_description;
}

bool Requit::getEditable() const
{
    return m_editable;
}

bool Requit::getOptionnel() const
{
    return m_optionnel;
}

int Requit::getId() const
{
    return m_id;
}
