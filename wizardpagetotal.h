#ifndef WIZARDPAGETOTAL_H
#define WIZARDPAGETOTAL_H

#include <QWizardPage>

namespace Ui {
    class WizardPageTotal;
}

class WizardPageTotal : public QWizardPage
{
    Q_OBJECT

public:
    explicit WizardPageTotal(QWidget *parent = 0);
    ~WizardPageTotal();

    void initializePage();

private:
    Ui::WizardPageTotal *ui;
};

#endif // WIZARDPAGETOTAL_H
