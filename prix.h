#ifndef PRIX_H
#define PRIX_H

#include <QVector>

#include "personne.h"

class Prix
{
public:
    Prix(QVector< QVector<double> > prixAsso, QVector< QVector<double> > prixEvent);

    double getPrixAsso(int asso, Statut* statut) const;
    double getPrixEvent(int event, Statut* statut) const;
private:
    QVector< QVector<double> > m_prixAsso;
    QVector< QVector<double> > m_prixEvent;
};

#endif // PRIX_H
