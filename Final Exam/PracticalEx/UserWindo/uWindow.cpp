#include <QVBoxLayout>
#include <QMessageBox>
#include "uWindow.h"

userWindow::userWindow(Service &s, User &u): serv(s), user(u) {
    this->serv.addObserver(this);
    initGUI();
    populateIssues();
    connect();
    this->show();
}

userWindow::~userWindow() {
    this->serv.removeObserver(this);
}

void userWindow::initGUI() {
    std::string title;
    title.append(user.getName());
    title.append(" - ");
    title.append(user.getType());
    this->setWindowTitle(QString::fromStdString(title));


    QVBoxLayout *mainLayout = new QVBoxLayout{this};
    issuesList = new QListWidget{};
    issueDescription = new QLineEdit{};
    mainLayout->addWidget(issuesList);
    mainLayout->addWidget(issueDescription);

    QHBoxLayout *buttonLayout = new QHBoxLayout{};
    addBtn = new QPushButton{"Add Issue"};
    if(user.getType() == "programmer"){
        addBtn->setEnabled(false);
    }
    resolveBtn = new QPushButton{"Resolve Issue"};
    if(user.getType() == "tester"){
        resolveBtn->setEnabled(false);
    }
    removeBtn = new QPushButton{"Remove Issue"};
    buttonLayout->addWidget(addBtn);
    buttonLayout->addWidget(resolveBtn);
    buttonLayout->addWidget(removeBtn);

    mainLayout->addLayout(buttonLayout);
}

void userWindow::connect() {
    QObject::connect(this->addBtn, &QPushButton::clicked, this, &userWindow::AddIssue);
    QObject::connect(this->resolveBtn, &QPushButton::clicked, this, &userWindow::ResolveIssue);
    QObject::connect(this->removeBtn, &QPushButton::clicked, this, &userWindow::RemoveIssue);
    QObject::connect(this->issuesList, &QListWidget::itemSelectionChanged, [this](){
        int index = this->getListIndex();
        if(index < 0)
            return ;
        Issue i = this->serv.getIssueIndex(index);
        this->issueDescription->setText(QString::fromStdString(i.getDesc()));
    });
}

int userWindow::getListIndex() {
    QModelIndexList allIndexes = this->issuesList->selectionModel()->selectedIndexes();
    if(allIndexes.empty()){
        this->issueDescription->clear();
        return -1;
    }
    int selectedIndex = allIndexes.at(0).row();
    return selectedIndex;
}

void userWindow::update() {
    this->populateIssues();
}

void userWindow::populateIssues() {
    this->issuesList->clear();
    std::vector<Issue> issues = this->serv.getServiceIssues();
    for(auto i: issues){
        this->issuesList->addItem(QString::fromStdString(i.toStr()));
    }
}

void userWindow::AddIssue() {
    std::string issueName = issueDescription->text().toStdString();
    if (issueName.empty()){
        QMessageBox error;
        error.setText("No issue description!");
        error.exec();
    }
    else {
        this->serv.addServiceIssue(issueName, "open", user.getName(), "-");
    }
}

void userWindow::ResolveIssue() {
    int idx = this->getListIndex();
    Issue is = this->serv.getIssueIndex(idx);
    if(is.getStatus() == "open"){
        this->serv.updateServiceIssue(is, user.getName());
    }
    else{
        QMessageBox error;
        error.setText("This issue is already solved!");
        error.exec();
    }
}

void userWindow::RemoveIssue() {
    int idx = this->getListIndex();
    Issue is = this->serv.getIssueIndex(idx);
    if(is.getStatus() == "closed"){
        this->serv.deleteServiceIssue(is);
    }
    else{
        QMessageBox error;
        error.setText("You cannot remove this issue as it's not closed!");
        error.exec();
    }
}
