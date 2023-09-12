#include <QApplication>
#include "Service/service.h"
#include "Repo/repo.h"
#include "PlayerWindow/window.h"

int main(int arg, char *argv[]){
    QApplication a(arg, argv);

    Repo r;
    Service s(r);
    for (auto m: s.getServicePlayers()){
        userWindow *uw = new userWindow{s, m};
    }

    return a.exec();
}