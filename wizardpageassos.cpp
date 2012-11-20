#include "wizardpageassos.h"
#include "ui_wizardpageassos.h"

#include "ressourcemanager.h"
#include "widgetasso.h"

WizardPageAssos::WizardPageAssos(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageAssos)
{
    ui->setupUi(this);

    const QList<Asso*>& listAssos = RessourceManager::getInstance()->getAssos();

    foreach (Asso* asso, listAssos ) {
        if(asso->getId() == 13 && !RessourceManager::getInstance()->afficheTrac())
        {
            continue;
        }

        WidgetAsso* tmp = new WidgetAsso(asso);
        m_listeWidget.append(tmp);
        ui->verticalLayout->addWidget(tmp);
    }
}

WizardPageAssos::~WizardPageAssos()
{
    delete ui;
}

bool WizardPageAssos::validatePage()
{
    QList<Asso*> listeAssos;
    QList<Evenement*> listeEvents;

    foreach (WidgetAsso* widget, m_listeWidget) {
        if(widget->isChecked()) {
            listeAssos.append(widget->getAsso());
            listeEvents.append(widget->getEventPris());
        }
    }

    if(listeAssos.isEmpty())
    {
        return false;
    }

    RessourceManager::getInstance()->getCurrentPersonne()->setListeAssos(listeAssos);
    RessourceManager::getInstance()->getCurrentPersonne()->setListeEvents(listeEvents);

    return true;
}
