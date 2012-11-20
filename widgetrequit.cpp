#include "widgetrequit.h"

#include <QHBoxLayout>

WidgetRequit::WidgetRequit(Requit* requit, QWidget *parent) :
    QWidget(parent), m_requit(requit)
{
    QLayout* layout = new QHBoxLayout();
    setLayout(layout);

    if(requit->getOptionnel())
        m_checkBox = new QCheckBox(requit->getDescription());
    else
        m_checkBox = new QCheckBox("* " + requit->getDescription());

    layout->addWidget(m_checkBox);

    if(requit->getEditable()) {
        m_lineEdit = new QLineEdit();
        m_lineEdit->setEnabled(false);
        layout->addWidget(m_lineEdit);

        connect(m_checkBox, SIGNAL(toggled(bool)), m_lineEdit, SLOT(setEnabled(bool)));
    }
    else
        m_lineEdit = NULL;
}

Requit* WidgetRequit::getRequit() const
{
    return m_requit;
}

QCheckBox* WidgetRequit::getCheckBox() const
{
    return m_checkBox;
}

QLineEdit* WidgetRequit::getLineEdit() const
{
    return m_lineEdit;
}
