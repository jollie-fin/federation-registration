#ifndef WIDGETASSO_H
#define WIDGETASSO_H

#include <QWidget>
#include <QGroupBox>
#include <QCheckBox>
#include <QList>

#include "asso.h"
#include "evenement.h"

class WidgetAsso : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetAsso(Asso* asso, QWidget *parent = 0);
    ~WidgetAsso();

    bool isChecked() const;
    QList<Evenement*> getEventPris() const;

    Asso* getAsso() const;

private:
    QGroupBox* m_groupBox;
    QCheckBox* m_checkBox;
    QList<QCheckBox*> m_listeCheckBox;
    Asso* m_asso;
};

#endif // WIDGETASSO_H
