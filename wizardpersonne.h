#ifndef WIZARDPERSONNE_H
#define WIZARDPERSONNE_H

#include <QWizard>

namespace Ui {
    class WizardPersonne;
}

class WizardPersonne : public QWizard
{
    Q_OBJECT

public:
    explicit WizardPersonne(QWidget *parent = 0);
    ~WizardPersonne();

private:
    Ui::WizardPersonne *ui;
};

#endif // WIZARDPERSONNE_H
