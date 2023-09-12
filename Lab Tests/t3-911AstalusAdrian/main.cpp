#include "Repo/repo.h"
#include "Weather/weather.h"
#include "GUI/gui.h"
#include <QApplication>


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Repo repo = Repo("input.txt");
    GUI gui{&repo};
    return a.exec();
}