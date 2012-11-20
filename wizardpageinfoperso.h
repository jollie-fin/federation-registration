#ifndef WIZARDPAGEINFOPERSO_H
#define WIZARDPAGEINFOPERSO_H

#include <QWizardPage>

#include "infopersonne.h"

namespace Ui {
    class WizardPageInfoPerso;
}

class WizardPageInfoPerso : public QWizardPage
{
    Q_OBJECT

public:
    explicit WizardPageInfoPerso(QWidget *parent = 0);
    ~WizardPageInfoPerso();

    void initializePage();
    bool validatePage();

private:
    Ui::WizardPageInfoPerso *ui;
    InfoPersonne* m_infoPersonne;
};

#endif // WIZARDPAGEINFOPERSO_H
