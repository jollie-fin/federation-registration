#include "infopersonne.h"

InfoPersonne::InfoPersonne(int identifiant, QString nom, QString prenom, double prix)
    : m_identifiant(identifiant), m_nom(nom), m_prenom(prenom), m_prix(prix), m_differe(false)
{
}

void InfoPersonne::setDiffere(bool differe)
{
    m_differe = differe;
}

void InfoPersonne::setModePaiment(int modePaiment)
{
    m_modePaiment = modePaiment;
}

QString InfoPersonne::getNom()
{
    return m_nom;
}

QString InfoPersonne::getPrenom()
{
    return m_prenom;
}

double InfoPersonne::getPrix()
{
    return m_prix;
}

bool InfoPersonne::getDiffere()
{
    return m_differe;
}

int InfoPersonne::getModePaiment()
{
    return m_modePaiment;
}

int InfoPersonne::getIdentifiant()
{
    return m_identifiant;
}
