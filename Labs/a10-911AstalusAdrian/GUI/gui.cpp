#include "gui.h"
#include "../Exceptions/exception.h"
#include "../userService/HTMLAdoption.h"
#include "../userService/CSVAdoption.h"
#include "../AbstractModel/abstract_model.h"
#include "../Delegate/delegate.h"
#include <QLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QStringListModel>
#include <QTableView>
#include <QShortcut>
#include <QDebug>

QT_CHARTS_USE_NAMESPACE

GUI::GUI(Service *s, userService *us, URService* urs, URService* adoption_urs): service{s}, uservice{us}, urservice{urs}, adoption_urservice{adoption_urs}
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
    this->undoButton = new QPushButton{"Undo"};
    this->redoButton = new QPushButton{"Redo"};

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
    actionButtons->addWidget(this->undoButton, 1, 0);
    actionButtons->addWidget(this->redoButton, 1, 2);
    actionButtons->addWidget(this->toUserButton, 1, 1);
    actionButtons->addWidget(this->exitButton, 2, 1);
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

    /// shortcuts
    QShortcut *undo = new QShortcut{QKeySequence(Qt::CTRL + Qt::Key_Z), this};
    QObject::connect(undo, &QShortcut::activated, this, &GUI::undo);
    QShortcut *redo = new QShortcut{QKeySequence(Qt::CTRL + Qt::Key_Y), this};
    QObject::connect(redo, &QShortcut::activated, this, &GUI::redo);


    /// connections
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
    QObject::connect(this->adoptionButton, &QPushButton::clicked, this, &GUI::showTableAdoption);
    QObject::connect(this->undoButton, &QPushButton::clicked, this, &GUI::undo);
    QObject::connect(this->redoButton, &QPushButton::clicked, this, &GUI::redo);
    QObject::connect(this->userUndo, &QPushButton::clicked, this, &GUI::adoptionUndo);
    QObject::connect(this->userRedo, &QPushButton::clicked, this, &GUI::adoptionRedo);

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
        AddCommand* a = new AddCommand(this->service, breed, name, age, link);
        urservice->Execute(a);
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
//    Dog new_dog = Dog(breed, name, age, link);
    try{
        UpdateCommand *u = new UpdateCommand(this->service, initial_dog, breed, name, age, link);
        urservice->Execute(u);
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
//        this->service->removeDogServiceByIndex(index);
        Dog d = this->service->getDogByIndex(index);
        RemoveCommand *r = new RemoveCommand(this->service, index, d);
        urservice->Execute(r);
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
    this->user->setMinimumSize(400,300);

    /// setting up LineEdits and PushButtons
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
    this->userUndo = new QPushButton{"Undo"};
    this->userRedo = new QPushButton{"Redo"};
    this->adoptionButton = new QPushButton{"Table Adoption List"};

    /// creating a vertical layout for the widget
    QVBoxLayout* userLayout = new QVBoxLayout{this->user};

    /// creating a form layout that goes inside the vertical one (for the LineEdits)
    QFormLayout* dogInfo = new QFormLayout{};
    dogInfo->addRow("Name", this->userDogName);
    dogInfo->addRow("Breed", this->userDogBreed);
    dogInfo->addRow("Age", this->userDogAge);
    dogInfo->addRow("Link", this->userDogLink);
    userLayout->addLayout(dogInfo);

    /// creating a grid layout for the PushButtons
    QGridLayout* userButtons = new QGridLayout{};
    userButtons->addWidget(this->adoptButton, 0, 0);
    userButtons->addWidget(this->nextButton, 0, 1);
    userButtons->addWidget(this->filterButton, 0, 2);
    userButtons->addWidget(this->csvButton, 2, 0);
    userButtons->addWidget(this->htmlButton, 2, 1);
    userButtons->addWidget(this->adoptionButton, 2, 2);
    userButtons->addWidget(this->userUndo, 3, 0);
    userButtons->addWidget(this->userRedo, 3, 2);
    userButtons->addWidget(this->toAdminButton, 4, 0);
    userButtons->addWidget(this->userExitButton, 4, 1);
    userButtons->addWidget(this->statisticsButton, 4, 2);

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
//            this->uservice->addToAdoption(d);
            AdoptCommand *ad = new AdoptCommand{uservice, d};
            adoption_urservice->Execute(ad);
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

void GUI::showTableAdoption() {
    std::vector<Dog> adoption = this->uservice->seeAdoptionList();
    if(adoption.empty())
        QMessageBox::critical(this, "Error", "Adoption list empty");
    else{
        QTableView* adoptionList = new QTableView{};
        adoptionList->setMinimumSize(625, 500);
//        adoptionList->setColumnWidth(3, 150);
//        adoptionList->setColumnWidth(2, 20);
//        adoptionList->setColumnWidth(4, 200);

        /// Hide scrollbar
        adoptionList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        /// Set the font to bold
        QFont bold = QFont();
        bold.setBold(true);
        adoptionList->setFont(bold);

        /// Hide the table grid
        adoptionList->setShowGrid(false);

        /// Setting the Abstract Model and custom Delegate
        AbstractModel* model = new AbstractModel{adoption};
        PictureDelegate* pd = new PictureDelegate{};
        adoptionList->setModel(model);
        adoptionList->setItemDelegate(pd);


        adoptionList->setColumnWidth(3, 150);
        adoptionList->setColumnWidth(2, 20);
        adoptionList->setColumnWidth(4, 200);
        adoptionList->resizeRowsToContents();
        adoptionList->show();
    }
}

void GUI::filterDogs() {
    std::string breed = this->userDogBreed->text().toStdString();
    int age = this->userDogAge->text().toInt();
    std::vector<Dog> filtered = this->uservice->filterDogs(breed, age);

    /// With widget
//    QListWidget *filteredDogsWidget = new QListWidget();
//    filteredDogsWidget->clear();
//    for (Dog &d: filtered){
//        filteredDogsWidget->addItem(QString::fromStdString(d.toGUIString()));
//    }
//    filteredDogsWidget->show();


    /// With view & abstract model (working)
    QTableView* filteredDogsView = new QTableView{};
    filteredDogsView->setMinimumSize(300, 200);
    AbstractModel *model = new AbstractModel{filtered};
    filteredDogsView->setModel(model);


    /// With StringListModel (working)
//    QListView* filteredDogsView = new QListView{};
//    QStringListModel *m = new QStringListModel{};
//    QStringList list;
//    for(auto &d: filtered){
//        list.append(QString::fromStdString(d.toString()));
//    }
//    m->setStringList(list);
//    filteredDogsView->setModel(m);


    filteredDogsView->show();
}

void GUI::statistics() {

    int nrOfDogs = this->service->getNumberOfDogs();
    std::vector<std::string> breeds = sortBreeds();
    std::vector<int> count;
    for (const std::string& each_breed: breeds){
        count.push_back(this->service->countBreed(each_breed));
    }

    QBarSet *set0 = new QBarSet("Count");
    set0->setColor(QColor(52, 152, 235));
    for (int c: count)
        set0->append(c);

    QBarSeries *series = new QBarSeries();
    series->append(set0);


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Dogs in the shelter");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;

    for (const std::string& breed: breeds)
        categories.append(QString::fromStdString(breed));

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

void GUI::undo() {
    try{
        this->urservice->Undo();
        this->populate();
    }
    catch (URException& ex) {
        QMessageBox::critical(this, "Error", QString::fromStdString(ex.print()));
    }
    catch (RepositoryException &re) {
        QMessageBox::critical(this, "Error", QString::fromStdString(re.getRepoError()));
    }
    catch (Exception &e){
        QMessageBox::critical(this, "Error", QString::fromStdString(e.getError()));
    }
}

void GUI::redo() {
    try{
        this->urservice->Redo();
        this->populate();
    }
    catch (URException& ex) {
        QMessageBox::critical(this, "Error", QString::fromStdString(ex.print()));
    }
    catch (RepositoryException &re) {
        QMessageBox::critical(this, "Error", QString::fromStdString(re.getRepoError()));
    }
    catch (Exception &e){
        QMessageBox::critical(this, "Error", QString::fromStdString(e.getError()));
    }
}

void GUI::adoptionUndo() {
    try{
        this->adoption_urservice->Undo();
    }
    catch (URException& ex) {
        QMessageBox::critical(this, "Error", QString::fromStdString(ex.print()));
    }
    catch (RepositoryException &re) {
        QMessageBox::critical(this, "Error", QString::fromStdString(re.getRepoError()));
    }
    catch (Exception &e){
        QMessageBox::critical(this, "Error", QString::fromStdString(e.getError()));
    }
}

void GUI::adoptionRedo() {
    try{
        this->adoption_urservice->Redo();
    }
    catch (URException& ex) {
        QMessageBox::critical(this, "Error", QString::fromStdString(ex.print()));
    }
    catch (RepositoryException &re) {
        QMessageBox::critical(this, "Error", QString::fromStdString(re.getRepoError()));
    }
    catch (Exception &e){
        QMessageBox::critical(this, "Error", QString::fromStdString(e.getError()));
    }
}


