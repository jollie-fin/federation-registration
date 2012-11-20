#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QString>
#include <QList>

#include "requit.h"

class Evenement
{
public:
    Evenement(int id, QString nom);

    QString getNom() const;
    QList<Requit*> getRequits() const;
    int getId() const;

    void setListeRequits(QList<Requit*> listeRequit);

private:
    int m_id;
    QString m_nom;
    QList<Requit*> m_requits;
};

#endif // EVENEMENT_H
