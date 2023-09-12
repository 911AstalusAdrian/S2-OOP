#include "gui.h"
#include "../Exceptions/exception.h"
#include "../userService/HTMLAdoption.h"
#include "../userService/CSVAdoption.h"
#include "../AbstractModel/abstract_model.h"
#include <QLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QList>
#include <QStringListModel>

QT_CHARTS_USE_NAMESPACE

GUI::GUI(Service *s, userService *us): service{s}, uservice{us}
{
    this->startGUI();
    this->populate();
    this->setUser();
    this->connections();
}

void GUI::startGUI() {
    this->user = new QWidget{};
    this->dogsList = new QListWidget{};
    this->dogName = new QLineEdit{};
    this->dogBreed = new QLineEdit{};
    this->dogAge = new QLineEdit{};
    this->dogLink = new QLineEdit{};
    this->addButton = new QPushButton{"Add"};
    this->updateButton = new QPushButton{"Update"};
    this->deleteButton = new QPushButton{"Delete"};
    this->toUserButton = new QPushButton{"Switch to User"};
    this->exitButton = new QPushButton{"Exit"};

    QVBoxLayout* mainLayout = new QVBoxLayout{this};

    mainLayout->addWidget(this->dogsList);

    QFormLayout* dogInfo = new QFormLayout{};
    dogInfo->addRow("Name", this->dogName);
    dogInfo->addRow("Breed", this->dogBreed);
    dogInfo->addRow("Age", this->dogAge);
    dogInfo->addRow("Link", this->dogLink);
    mainLayout->addLayout(dogInfo);

    QGridLayout* actionButtons = new QGridLayout{};
    actionButtons->addWidget(this->addButton, 0, 0);
    actionButtons->addWidget(this->updateButton, 0, 1);
    actionButtons->addWidget(this->deleteButton, 0, 2);
    actionButtons->addWidget(this->toUserButton, 1, 0);
    actionButtons->addWidget(this->exitButton, 1, 2);
    mainLayout->addLayout(actionButtons);

}

void GUI::populate() {
    this->dogsList->clear();
    std::vector<Dog> allDogs = this->service->getArray();
    for(Dog& d: allDogs){
        this->dogsList->addItem(QString::fromStdString(d.toGUIString()));
    }
}

void GUI::connections() {

    QObject::connect(this->dogsList, &QListWidget::itemSelectionChanged, [this](){
        int index = this->getListIndex();
        if(index < 0)
            return ;
        Dog d = this->service->getDogByIndex(index);
        this->dogName->setText(QString::fromStdString(d.getName()));
        this->dogBreed->setText(QString::fromStdString(d.getBreed()));
        this->dogAge->setText(QString::fromStdString(std::to_string(d.getAge())));
        this->dogLink->setText(QString::fromStdString(d.getPhoto()));
    });


    QObject::connect(this->addButton, &QPushButton::clicked, this, &GUI::addDogGUI);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &GUI::removeDogGUI);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &GUI::updateDogGUI);
    QObject::connect(this->toUserButton, &QPushButton::clicked, this, &GUI::switchToUser);
    QObject::connect(this->exitButton, &QPushButton::clicked, this, &GUI::close);
    QObject::connect(this->userExitButton, &QPushButton::clicked, this->user, &GUI::close);
    QObject::connect(this->toAdminButton, &QPushButton::clicked, this, &GUI::switchToAdmin);
    QObject::connect(this->nextButton, &QPushButton::clicked, this, &GUI::nextDog);
    QObject::connect(this->adoptButton, &QPushButton::clicked, this, &GUI::addToAdoption);
    QObject::connect(this->csvButton, &QPushButton::clicked, this, &GUI::showCSVAdoption);
    QObject::connect(this->htmlButton, &QPushButton::clicked, this, &GUI::showHTMLAdoption);
    QObject::connect(this->filterButton, &QPushButton::clicked, this, &GUI::filterDogs);
    QObject::connect(this->statisticsButton, &QPushButton::clicked, this, &GUI::statistics);

}

int GUI::getListIndex() const {
    QModelIndexList allIndexes = this->dogsList->selectionModel()->selectedIndexes();
    if(allIndexes.empty()){
        this->dogName->clear();
        this->dogBreed->clear();
        this->dogAge->clear();
        this->dogLink->clear();
        return -1;
    }
    int selectedIndex = allIndexes.at(0).row();
    return selectedIndex;
}

void GUI::addDogGUI() {
    std::string name = this->dogName->text().toStdString();
    std::string breed = this->dogBreed->text().toStdString();
    int age = this->dogAge->text().toInt();
    std::string link = this->dogLink->text().toStdString();
    try {
        this->service->addDogService(breed, name, age, link);
        this->populate();
        int lastEl = this->service->getArray().size() - 1;
        this->dogsList->setCurrentRow(lastEl);
    }
    catch (RepositoryException &re) {
        QMessageBox::critical(this, "Error", QString::fromStdString(re.getRepoError()));
    }
    catch (Exception &e){
        QMessageBox::critical(this, "Error", QString::fromStdString(e.getError()));
    }
}

void GUI::updateDogGUI() {
    int index = this->getListIndex();
    Dog initial_dog = this->service->getDogByIndex(index);
    std::string name = this->dogName->text().toStdString();
    std::string breed = this->dogBreed->text().toStdString();
    int age = this->dogAge->text().toInt();
    std::string link = this->dogLink->text().toStdString();
    Dog new_dog = Dog(breed, name, age, link);
    try{
        this->service->updateDogService(initial_dog, new_dog);
        this->populate();
        int lastEl = this->service->getArray().size() - 1;
        this->dogsList->setCurrentRow(lastEl);
    }
    catch (RepositoryException &re) {
        QMessageBox::critical(this, "Error", QString::fromStdString(re.getRepoError()));
    }
    catch (Exception &e){
        QMessageBox::critical(this, "Error", QString::fromStdString(e.getError()));
    }
}

void GUI::removeDogGUI() {
    int index = this->getListIndex();
    try{
        this->service->removeDogServiceByIndex(index);
        this->populate();
        int lastEl = this->service->getArray().size() - 1;
        this->dogsList->setCurrentRow(lastEl);
    }
    catch (RepositoryException &re) {
        QMessageBox::critical(this, "Error", QString::fromStdString(re.getRepoError()));
    }
    catch (Exception &e){
        QMessageBox::critical(this, "Error", QString::fromStdString(e.getError()));
    }
}

void GUI::switchToUser() {
    this->user->show();
    this->hide();
}

void GUI::switchToAdmin() {
    this->user->hide();
    this->show();
}

void GUI::setUser() {
    this->userDogName = new QLineEdit{};
    this->userDogBreed = new QLineEdit{};
    this->userDogAge = new QLineEdit{};
    this->userDogLink = new QLineEdit{};
    this->adoptButton = new QPushButton{"Adopt"};
    this->nextButton = new QPushButton{"Next"};
    this->filterButton = new QPushButton{"Filter"};
    this->toAdminButton = new QPushButton{"Switch to Admin"};
    this->csvButton = new QPushButton{"CSV Adoption List"};
    this->htmlButton = new QPushButton{"HTML Adoption List"};
    this->userExitButton = new QPushButton{"Exit"};
    this->statisticsButton = new QPushButton{"Statistics"};

    QVBoxLayout* userLayout = new QVBoxLayout{this->user};

    QFormLayout* dogInfo = new QFormLayout{};
    dogInfo->addRow("Name", this->userDogName);
    dogInfo->addRow("Breed", this->userDogBreed);
    dogInfo->addRow("Age", this->userDogAge);
    dogInfo->addRow("Link", this->userDogLink);
    userLayout->addLayout(dogInfo);

    QGridLayout* userButtons = new QGridLayout{};
    userButtons->addWidget(this->adoptButton, 0, 0);
    userButtons->addWidget(this->nextButton, 0, 1);
    userButtons->addWidget(this->filterButton, 1, 0);
    userButtons->addWidget(this->toAdminButton, 1, 1);
    userButtons->addWidget(this->csvButton, 2, 0);
    userButtons->addWidget(this->htmlButton, 2, 1);
    userButtons->addWidget(this->userExitButton, 3, 0);
    userButtons->addWidget(this->statisticsButton, 3, 1);

    userLayout->addLayout(userButtons);

}

void GUI::nextDog() {
    if(this->dogIndex == this->service->getNumberOfDogs())
        this->dogIndex = 0;

    Dog d = this->service->getDogByIndex(this->dogIndex);
    this->userDogName->setText(QString::fromStdString(d.getName()));
    this->userDogBreed->setText(QString::fromStdString(d.getBreed()));
    this->userDogAge->setText(QString::fromStdString(to_string(d.getAge())));
    this->userDogLink->setText(QString::fromStdString(d.getPhoto()));
    this->dogIndex += 1;
}

void GUI::addToAdoption() {

    /// If the textboxes are empty
    if(this->dogIndex == 0)
        QMessageBox::critical(this, "Error", "Invalid!");
    else {
        Dog d = this->service->getDogByIndex(this->dogIndex - 1);
        try {
            this->uservice->addToAdoption(d);
            this->nextDog();
        }
        catch (RepositoryException &re) {
            QMessageBox::critical(this, "Error", QString::fromStdString(re.getRepoError()));
        }
        catch (Exception &e) {
            QMessageBox::critical(this, "Error", QString::fromStdString(e.getError()));
        }
    }
}

void GUI::showCSVAdoption() {
    this->ad = new CSVAdoptionList();
    std::vector<Dog> adoption = this->uservice->seeAdoptionList();
    if(adoption.empty())
        QMessageBox::critical(this, "Error", "Adoption list empty");
    else{
        ad->createList(adoption);
        ad->write();
        ad->open();
    }
}

void GUI::showHTMLAdoption() {
    this->ad = new HTMLAdoptionList();
    std::vector<Dog> adoption = this->uservice->seeAdoptionList();
    if(adoption.empty())
        QMessageBox::critical(this, "Error", "Adoption list empty");
    else{
        ad->createList(adoption);
        ad->write();
        ad->open();
    }
}

void GUI::filterDogs() {
    std::string breed = this->userDogBreed->text().toStdString();
    int age = this->userDogAge->text().toInt();
    int index = 0;
    bool done = false;
    std::vector<Dog> filtered = this->uservice->filterDogs(breed, age);

    /// With widget
//    QListWidget *filteredDogsWidget = new QListWidget();
//    filteredDogsWidget->clear();
//    for (Dog &d: filtered){
//        filteredDogsWidget->addItem(QString::fromStdString(d.toGUIString()));
//    }
//    filteredDogsWidget->show();


    QListView* filteredDogsView = new QListView{};
    filteredDogsView->setMinimumSize(500, 250);

    /// With view & abstract model (not working)
//    AbstractModel *model = new AbstractModel{filtered};
//    filteredDogsView->setModel(model);


    /// With StringListModel (working)
    QStringListModel *m = new QStringListModel{};
    QStringList list;
    for(auto &d: filtered){
        list.append(QString::fromStdString(d.toString()));
    }
    m->setStringList(list);
    filteredDogsView->setModel(m);


    filteredDogsView->show();
}

void GUI::statistics() {

    int nrOfDogs = this->service->getNumberOfDogs();
    std::vector<std::string> breeds = sortBreeds();
    std::vector<int> count;
    for (const std::string& each_breed: breeds){
        count.push_back(this->service->countBreed(each_breed));
    }


    /// Create another function that returns a vector<string>with the breeds (?)
    /// And another one that counts the dogs of a given breed (?)
    /// Store the values into a vector<int> (?)
    /// This looks like the obvious way tbh


    QBarSet *set0 = new QBarSet("Count");
    set0->setColor(QColor(52, 152, 235));
    for (int c: count)
        set0->append(c);

    /// Add the counts here ( set0 << val1 << val2 << ...) - with a for(?)

    QBarSeries *series = new QBarSeries();
    series->append(set0);


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Dogs in the shelter");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;

    for (const std::string& breed: breeds)
        categories.append(QString::fromStdString(breed));
    /// Add the Breeds here ( categories << b1 << b2 << ...) - again with a for(?)


    // TODO -> Get the statistics for the Dogs in the Shelter
    //      -> Each Breed and a count
    //      -> Add them to the Set and Chart



    /// The part below is OK; does not need modifications

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTickCount(nrOfDogs + 1);
    axisY->setRange(0,nrOfDogs);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(false);

    QChartView *chartView = new QChartView(chart);
    chartView->setMinimumSize(750, 500);
    chartView->show();

}

std::vector<std::string> GUI::sortBreeds() {
    std::vector<std::string> breeds;
    std::vector<Dog> allDogs = this->service->getArray();
    for (Dog &d: allDogs){
        std::string breed = d.getBreed();
        bool found = false;
        int i=0;
        if (breeds.size() == 0)
            breeds.push_back(breed);
        while(!found && i<breeds.size())
        {
            std::string storedBreed = breeds[i];
            if (breed == storedBreed)
                found = true;
            i++;
        }
        if (found == false)
            breeds.push_back(breed);
    }
    return breeds;
}


