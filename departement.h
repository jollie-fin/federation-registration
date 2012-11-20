#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

#include <QString>

class Departement
{
public:
    Departement(int id, QString name, QString abreviation);

    int getId() const;
    QString getName() const;
    QString getAvreviation() const;

private:
    int m_id;
    QString m_name;
    QString m_abreviation;
};

#endif // DEPARTEMENT_H
