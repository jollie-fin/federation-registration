#include <QtGui/QApplication>
#include "mainwindow.h"

#include "wizardpersonne.h"
#include "qsqlconnectiondialog.h"

#include "ressourcemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    while(!w.addConnection());
    w.show();

    RessourceManager::getInstance()->setCurrentPersonne(new Personne());

    //WizardPersonne test;
    //test.show();

    return a.exec();
}
