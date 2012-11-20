#include "wizardpaiment.h"
#include "ui_wizardpaiment.h"

WizardPaiment::WizardPaiment(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::WizardPaiment)
{
    ui->setupUi(this);
}

WizardPaiment::~WizardPaiment()
{
    delete ui;
}
