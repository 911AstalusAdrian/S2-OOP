#include "eWindow.h"
#include "../AbstractModel/model.h"
#include <QMatrix>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTableWidget>
#include <QLabel>
#include <sstream>

eWindow::eWindow(Service &s, Ethnologist &e): serv(s), eth(e) {
    this->serv.addObserver(this);
    init();
    populate();
    connections();
    this->show();

}

eWindow::~eWindow() {
    this->serv.removeObserver(this);
}

void eWindow::init() {
    std::string title;
    title.append(eth.getName());
    this->setWindowTitle(QString::fromStdString(title));
    this->setPalette(QPalette(QColor(rand()%255,rand()%255,rand()%255)));

    QVBoxLayout *mainLayout = new QVBoxLayout{this};


    this->zone = new QTableView{};
    TableModel *tm = new TableModel{serv};
    zone->setModel(tm);

    mainLayout->addWidget(zone);

    this->buildingIdx = new QLineEdit{};
    this->buildingDesc = new QLineEdit{};
    this->buildingCorresp = new QLineEdit{};
    this->buildingSquares = new QLineEdit{};
    this->addBtn = new QPushButton{"Add"};
    this->updateBtn = new QPushButton{"Update"};
    mainLayout->addWidget(buildingIdx);
    mainLayout->addWidget(buildingDesc);
    mainLayout->addWidget(buildingCorresp);
    mainLayout->addWidget(buildingSquares);

    QHBoxLayout* buttons = new QHBoxLayout{};
    buttons->addWidget(addBtn);
    buttons->addWidget(updateBtn);
    mainLayout->addLayout(buttons);
}

void eWindow::populate() {

}

void eWindow::connections() {
    QObject::connect(this->addBtn, &QPushButton::clicked, this, &eWindow::addBuilding);
}

int eWindow::getListIndex() const {
    QModelIndexList allIndexes = this->zone->selectionModel()->selectedIndexes();
    if (allIndexes.empty()) {
        this->buildingIdx->clear();
        this->buildingDesc->clear();
        this->buildingCorresp->clear();
        this->buildingSquares->clear();
        return -1;
    }
    int selectedIndex = allIndexes.at(0).row();
    return selectedIndex;
}
void eWindow::update() {
    this->populate();
}

void eWindow::addBuilding() {
    int id = buildingIdx->text().toInt();
    std::string desc = buildingDesc->text().toStdString();
    std::string area = buildingCorresp->text().toStdString();
    std::string squares = buildingSquares->text().toStdString();
    std::vector<std::string> areas;

    std::stringstream check1(squares);
    std::string intermediate;
    while(std::getline(check1, intermediate, ';')){
        areas.push_back(intermediate);
    }
    this->serv.addBuilding(id, desc,area,areas);
}

