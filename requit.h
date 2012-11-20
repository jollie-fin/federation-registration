#ifndef REQUIT_H
#define REQUIT_H

#include <QString>

class Requit
{
public:
    Requit(int id, QString description, bool editable, bool optionnel);

    QString getDescription() const;
    bool getEditable() const;
    bool getOptionnel() const;
    int getId() const;

private:
    int m_id;
    QString m_description;
    bool m_editable;
    bool m_optionnel;
};

#endif // REQUIT_H
