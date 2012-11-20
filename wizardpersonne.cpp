#include "wizardpersonne.h"
#include "ui_wizardpersonne.h"

WizardPersonne::WizardPersonne(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::WizardPersonne)
{
    ui->setupUi(this);
}

WizardPersonne::~WizardPersonne()
{
    delete ui;
}
