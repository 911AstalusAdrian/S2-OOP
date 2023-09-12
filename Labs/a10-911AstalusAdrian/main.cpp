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
    URService admin_urservice = URService();
    URService adoption_urservice = URService();
    GUI gui{&service, &uservice, &admin_urservice, &adoption_urservice};
    gui.show();

//    UI ui = UI(&service, &us);
//    ui.start();


    return a.exec();
}