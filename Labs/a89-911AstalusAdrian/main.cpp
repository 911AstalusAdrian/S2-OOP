#include "FileRepo/filerepo.h"
#include "Service/service.h"
#include "userService/userservice.h"
#include "GUI/gui.h"
#include <QApplication>


int main(int argc, char *argv[]){
    QApplication a(argc, argv);


    FileRepository repo = FileRepository("textfile.txt");
    Service service = Service(&repo);
    userService uservice = userService(&repo);

    GUI gui{&service, &uservice};
    gui.show();

//    UI ui = UI(&service, &us);
//    ui.start();


    return a.exec();
}