#ifndef WIZARDPAGELOGIN_H
#define WIZARDPAGELOGIN_H

#include <QWizardPage>

namespace Ui {
    class WizardPageLogin;
}

class WizardPageLogin : public QWizardPage
{
    Q_OBJECT

public:
    explicit WizardPageLogin(QWidget *parent = 0);
    ~WizardPageLogin();

    bool validatePage();

    void initializePage();
private:
    Ui::WizardPageLogin *ui;
};

#endif // WIZARDPAGELOGIN_H
