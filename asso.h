#ifndef ASSO_H
#define ASSO_H

#include <QString>
#include <QList>

#include "requit.h"
#include "evenement.h"

class Asso
{
public:
    Asso(int id, QString nom);

    bool haveEvent() const;

    QString getNom() const;
    const QList<Evenement*> getEvents() const;
    const QList<Requit*> getRequits() const;
    int getId() const;

    void addEvent(Evenement* event);
    void addRequit(Requit* requit);

    void addEvent(QList<Evenement*> events);
    void addRequit(QList<Requit*> requits);

private:
    int m_id;
    QString m_nom;

    QList<Requit*> m_requits;
    QList<Evenement*> m_evenements;
};

#endif // ASSO_H
