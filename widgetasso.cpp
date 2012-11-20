#include "widgetasso.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QCheckBox>

#include "ressourcemanager.h"

WidgetAsso::WidgetAsso(Asso* asso, QWidget *parent) :
    QWidget(parent)
{
    m_groupBox = NULL;
    m_checkBox = NULL;
    m_asso = asso;

    setLayout(new QHBoxLayout());

//    Prix* prix = RessourceManager::getInstance()->getPrix();

    if(asso->haveEvent())
    {
        m_groupBox = new QGroupBox(asso->getNom() /*+ " (" + prix->getPrixAsso(asso->getId(), RessourceManager::getInstance()->getCurrentPersonne()->getStatut()) + ")"*/);
        m_groupBox->setCheckable(true);
        m_groupBox->setChecked(false);

        m_groupBox->setLayout(new QVBoxLayout());

        foreach (const Evenement* event, asso->getEvents()) {
            QCheckBox* tmp = new QCheckBox(event->getNom());
            m_listeCheckBox.append(tmp);
            m_groupBox->layout()->addWidget(tmp);
        }

        layout()->addWidget(m_groupBox);
    }
    else
    {
        m_checkBox = new QCheckBox(asso->getNom());
        layout()->addWidget(m_checkBox);
    }
}

WidgetAsso::~WidgetAsso()
{
}

bool WidgetAsso::isChecked() const
{
    if(m_groupBox != NULL)
    {
        return m_groupBox->isChecked();
    }

    if(m_checkBox != NULL)
    {
        return m_checkBox->isChecked();
    }

    return false;
}

QList<Evenement*> WidgetAsso::getEventPris() const
{
    QList<Evenement*> liste;

    foreach (const QCheckBox* checkBox, m_listeCheckBox) {
        if(checkBox->isChecked())
        {
            foreach (Evenement* event, m_asso->getEvents()) {
                if(event->getNom() == checkBox->text())
                {
                    liste.append(event);
                }
            }
        }
    }

    return liste;
}

Asso* WidgetAsso::getAsso() const
{
    return m_asso;
}
