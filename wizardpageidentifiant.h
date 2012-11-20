#ifndef WIZARDPAGEIDENTIFIANT_H
#define WIZARDPAGEIDENTIFIANT_H

#include <QWizardPage>

namespace Ui {
    class WizardPageIdentifiant;
}

class WizardPageIdentifiant : public QWizardPage
{
    Q_OBJECT

public:
    explicit WizardPageIdentifiant(QWidget *parent = 0);
    ~WizardPageIdentifiant();

    void initializePage();

private:
    Ui::WizardPageIdentifiant *ui;
};

#endif // WIZARDPAGEIDENTIFIANT_H
