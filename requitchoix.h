#ifndef REQUITCHOIX_H
#define REQUITCHOIX_H

#include "requit.h"

#include <QString>

class RequitChoix
{
public:
    RequitChoix(Requit* requit, QString commentaire);

    Requit* getRequit() const;
    QString getCommentaire() const;

private:
    Requit* m_requit;
    QString m_commentaire;
};

#endif // REQUITCHOIX_H
