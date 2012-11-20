#include "wizardpagerequit.h"
#include "ui_wizardpagerequit.h"

#include <QCheckBox>
#include <QVBoxLayout>
#include <QGroupBox>

#include "asso.h"
#include "evenement.h"
#include "ressourcemanager.h"
#include "widgetrequit.h"

#include <QMessageBox>

WizardPageRequit::WizardPageRequit(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::WizardPageRequit)
{
    ui->setupUi(this);

    layout = NULL;
    m_widget = NULL;
}

WizardPageRequit::~WizardPageRequit()
{
    delete ui;
}

void WizardPageRequit::initializePage()
{
    //if(layout != NULL) {
    //    delete layout;
    //}

    if(m_widget != NULL)
    {
        m_widget->hide();
        m_listeRequits.clear();
    }

    m_widget = new QWidget();
    ui->verticalLayout_2->addWidget(m_widget);

    layout = new QVBoxLayout(m_widget);
    m_widget->setLayout(layout);

    foreach(Asso* asso, RessourceManager::getInstance()->getCurrentPersonne()->getListeAssos())
    {
        if(!asso->getRequits().isEmpty())
        {
            QGroupBox* groupBox = new QGroupBox(asso->getNom());
            QLayout* groupBoxLayout = new QVBoxLayout();
            groupBox->setLayout(groupBoxLayout);

            foreach (Requit* requit, asso->getRequits()) {
                WidgetRequit* requitWidget = new WidgetRequit(requit);
                groupBoxLayout->addWidget(requitWidget);
                m_listeRequits.append(requitWidget);
            }

            layout->addWidget(groupBox);
        }
    }

    foreach(Evenement* event, RessourceManager::getInstance()->getCurrentPersonne()->getListeEvents())
    {
        if(!event->getRequits().isEmpty())
        {
            QGroupBox* groupBox = new QGroupBox(event->getNom());
            QLayout* groupBoxLayout = new QVBoxLayout();
            groupBox->setLayout(groupBoxLayout);

            foreach (Requit* requit, event->getRequits()) {
                WidgetRequit* requitWidget = new WidgetRequit(requit);
                groupBoxLayout->addWidget(requitWidget);
                m_listeRequits.append(requitWidget);
            }

            layout->addWidget(groupBox);
        }
    }

    WidgetRequit* tmp = new WidgetRequit(new Requit(-1, "Commentaire", true, true));
    layout->addWidget(tmp);
    m_listeRequits.append(tmp);
}

bool WizardPageRequit::validatePage()
{
    if(m_listeRequits.empty())
    {
        return true;
    }

    bool valide = true;

    foreach (WidgetRequit* widget, m_listeRequits) {
        if(!widget->getRequit()->getOptionnel() && !widget->getCheckBox()->isChecked()) {
            return false;
        }
    }

    if(valide)
    {
        QList<RequitChoix*> liste;

        foreach (WidgetRequit* widget, m_listeRequits) {
            if(widget->getCheckBox()->isChecked()) {
                if(widget->getLineEdit() != NULL)
                    liste.append(new RequitChoix(widget->getRequit(), widget->getLineEdit()->text()));
                else
                    liste.append(new RequitChoix(widget->getRequit(), ""));
            }
        }

        RessourceManager::getInstance()->getCurrentPersonne()->setListeRequits(liste);
    }

    return valide;
}
