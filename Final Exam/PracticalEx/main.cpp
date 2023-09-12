#include <QApplication>
#include "Service/service.h"
#include "Repo/repo.h"
#include "UserWindo/uWindow.h"

int main(int arg, char *argv[]){
    QApplication a(arg, argv);

    Repo r;
    Service s(r);
    for (auto m: s.getServiceUsers()){
        userWindow *uw = new userWindow{s, m};
    }

    return a.exec();
}