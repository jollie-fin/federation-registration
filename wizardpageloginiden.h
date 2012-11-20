#ifndef WIZARDPAGELOGINIDEN_H
#define WIZARDPAGELOGINIDEN_H

#include <QWizardPage>

namespace Ui {
    class WizardPageLoginIden;
}

class WizardPageLoginIden : public QWizardPage
{
    Q_OBJECT

public:
    explicit WizardPageLoginIden(QWidget *parent = 0);
    ~WizardPageLoginIden();

    bool validatePage();

private:
    Ui::WizardPageLoginIden *ui;
};

#endif // WIZARDPAGELOGINIDEN_H
