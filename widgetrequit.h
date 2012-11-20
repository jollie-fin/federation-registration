#ifndef WIDGETREQUIT_H
#define WIDGETREQUIT_H

#include <QWidget>
#include <QCheckBox>
#include <QLineEdit>

#include "requit.h"

class WidgetRequit : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetRequit(Requit* requit, QWidget *parent = 0);

    Requit* getRequit() const;
    QCheckBox* getCheckBox() const;
    QLineEdit* getLineEdit() const;

private:
    Requit* m_requit;
    QCheckBox* m_checkBox;
    QLineEdit* m_lineEdit;
};

#endif // WIDGETREQUIT_H
