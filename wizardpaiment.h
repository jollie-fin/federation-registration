#ifndef WIZARDPAIMENT_H
#define WIZARDPAIMENT_H

#include <QWizard>

namespace Ui {
    class WizardPaiment;
}

class WizardPaiment : public QWizard
{
    Q_OBJECT

public:
    explicit WizardPaiment(QWidget *parent = 0);
    ~WizardPaiment();

private:
    Ui::WizardPaiment *ui;
};

#endif // WIZARDPAIMENT_H
