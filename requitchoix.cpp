#include "requitchoix.h"

RequitChoix::RequitChoix(Requit* requit, QString commentaire)
    : m_requit(requit), m_commentaire(commentaire)
{
}

Requit* RequitChoix::getRequit() const
{
    return m_requit;
}

QString RequitChoix::getCommentaire() const
{
    return m_commentaire;
}
