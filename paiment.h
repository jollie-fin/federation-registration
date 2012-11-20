#ifndef PAIMENT_H
#define PAIMENT_H

#include <QString>

#include "infopersonne.h"

class Paiment
{
public:
    Paiment(QString login, int identifiant);

    QString getLogin();
    int getIdentifiant();
    InfoPersonne* getInfoPersonne();

    void setInfoPersonne(InfoPersonne* infoPerso);

private:
    QString m_login;
    int m_identifiant;
    InfoPersonne* m_infoPersonne;
};

#endif // PAIMENT_H
