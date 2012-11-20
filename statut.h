#ifndef STATUT_H
#define STATUT_H

#include <QString>

class Statut
{
public:
    Statut(int id, QString name);

    int getId() const;
    QString getName() const;

private:
    int m_id;
    QString m_name;
};

#endif // STATUT_H
