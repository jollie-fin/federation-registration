#ifndef WIZARDPAGEASSOS_H
#define WIZARDPAGEASSOS_H

#include <QWizardPage>

#include "widgetasso.h"

namespace Ui {
    class WizardPageAssos;
}

class WizardPageAssos : public QWizardPage
{
    Q_OBJECT

public:
    explicit WizardPageAssos(QWidget *parent = 0);
    ~WizardPageAssos();

    bool validatePage();

private:
    Ui::WizardPageAssos *ui;

    QList<WidgetAsso*> m_listeWidget;
};

#endif // WIZARDPAGEASSOS_H
