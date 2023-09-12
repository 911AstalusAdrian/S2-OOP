#include <iostream>
#include <QApplication>
#include "Service/service.h"
#include "EthnologistWindow/eWindow.h"
#include "Repo/repo.h"

int main(int arg, char *argv[]){
    QApplication a(arg, argv);

    Repo r;
    Service s(r);
    for (auto m: s.getEthnologistsServ()){
        eWindow *uw = new eWindow{s, m};
    }

    return a.exec();
}
