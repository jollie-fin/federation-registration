#ifndef WIZARDPAGEIDENTITE_H
#define WIZARDPAGEIDENTITE_H

#include <QWizardPage>

namespace Ui {
    class WizardPageIdentite;
}

class WizardPageIdentite : public QWizardPage
{
    Q_OBJECT

public:
    explicit WizardPageIdentite(QWidget *parent = 0);
    ~WizardPageIdentite();

    bool validatePage();
private slots:
     void generateEmail();

private:
    Ui::WizardPageIdentite *ui;
};

#endif // WIZARDPAGEIDENTITE_H
