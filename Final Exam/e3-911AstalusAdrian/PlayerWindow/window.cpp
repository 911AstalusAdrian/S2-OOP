#include "window.h"
//#include "../TableModel/model.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableView>
#include <QMessageBox>


userWindow::userWindow(Service &s, Player &p): serv(s), player(p) {
    this->serv.addObserver(this);
    initGUI();
    connect();
    this->show();
    this->resize(1,1);
}

void userWindow::updateObserver() {
    this->minefield->setModel(nullptr);
    this->minefield->setModel(model);
}

void userWindow::initGUI() {
    std::string title;
    title.append(player.getName());
    this->setWindowTitle(QString::fromStdString(title));
    this->setFixedSize(850, 325);

    int turn = this->serv.getTurn();

    this->revealBtn = new QPushButton{"Reveal"};
    this->markBtn = new QPushButton{"Mark Mine"};
    this->coordinate = new QLineEdit{};




    QVBoxLayout* mainLayout = new QVBoxLayout{this};
    QHBoxLayout *buttonLayout = new QHBoxLayout{};

    buttonLayout->addWidget(revealBtn);
    buttonLayout->addWidget(markBtn);
    buttonLayout->addWidget(coordinate);

    std::vector<Player> players = serv.getServicePlayers();
    int mineNr = serv.getNrOfMines();
    int size = serv.getMinefieldSize();
    this->minefield = new QTableView{};
    this->model = new TModel{serv, mineNr, size, players};
    minefield->setModel(model);
    mainLayout->addWidget(minefield);
    mainLayout->addLayout(buttonLayout);

}


void userWindow::connect() {
    QObject::connect(this->markBtn, &QPushButton::clicked, this, &userWindow::markCell);
    QObject::connect(this->revealBtn, &QPushButton::clicked, this, &userWindow::revealCell);
}

void userWindow::markCell() {
    std::string cell =this->coordinate->text().toStdString();
    if(cell.length() != 2){
        QMessageBox::critical(this, "Error", "Invalid cell!");
    }
    else{
        int col = cell[0] - 'A';
        int line = cell[1] - '1';
        try {
            this->serv.markMine(col, line);
        }
        catch (Exception& e) {
            QMessageBox::critical(this, "Error", QString::fromStdString(e.getError()));
        }
    }
    this->coordinate->clear();
}

void userWindow::revealCell() {
    std::string cell =this->coordinate->text().toStdString();
    if(cell.length() != 2){
        QMessageBox::critical(this, "Error", "Invalid cell!");
    }
    else{
        int col = cell[0] - 'A';
        int line = cell[1] - '1';
        try {
            this->serv.revealCell(col, line, this);
        }
        catch (Exception &e) {
            QMessageBox::critical(this, "Error", QString::fromStdString(e.getError()));
        }
        catch (EndException& ee){
            QMessageBox::critical(this, "Error", QString::fromStdString(ee.getError()));
            this->close();
        }
    }
    this->coordinate->clear();
}