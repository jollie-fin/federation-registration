#ifndef INFOPERSONNE_H
#define INFOPERSONNE_H

#include <QString>

class InfoPersonne
{
public:
    InfoPersonne(int indentifiant, QString nom, QString prenom, double prix);

    void setDiffere(bool differe);
    void setModePaiment(int modePaiment);

    int getIdentifiant();
    QString getNom();
    QString getPrenom();
    double getPrix();
    bool getDiffere();
    int getModePaiment();

private:
    int m_identifiant;
    QString m_nom;
    QString m_prenom;
    double m_prix;
    bool m_differe;
    int m_modePaiment;
};

#endif // INFOPERSONNE_H
