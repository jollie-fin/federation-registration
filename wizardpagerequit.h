#ifndef WIZARDPAGEREQUIT_H
#define WIZARDPAGEREQUIT_H

#include <QWizardPage>
#include <QLayout>
#include <QList>

#include "widgetrequit.h"

namespace Ui {
    class WizardPageRequit;
}

class WizardPageRequit : public QWizardPage
{
    Q_OBJECT

public:
    explicit WizardPageRequit(QWidget *parent = 0);
    ~WizardPageRequit();
    void initializePage();
    bool validatePage();

private:
    Ui::WizardPageRequit *ui;
    QLayout* layout;
    QWidget* m_widget;
    QList<WidgetRequit*> m_listeRequits;
};

#endif // WIZARDPAGEREQUIT_H
