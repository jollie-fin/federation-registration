#include "prix.h"

Prix::Prix(QVector< QVector<double> > prixAsso, QVector< QVector<double> > prixEvent)
    : m_prixAsso(prixAsso), m_prixEvent(prixEvent)
{
}




double Prix::getPrixAsso(int asso, Statut* statut) const
{
    return m_prixAsso[asso][statut->getId()];
}

double Prix::getPrixEvent(int event, Statut* statut) const
{
    return m_prixEvent[event][statut->getId()];
}
