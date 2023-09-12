
#include <QVBoxLayout>
#include "gui.h"

void GUI::start() {
    this->list = new QListWidget{};
    this->overcast = new QCheckBox("Overcast", this);
    this->foggy = new QCheckBox{"Foggy", this};
    this->sunny = new QCheckBox{"Sunny", this};
    this->rain = new QCheckBox{"Rain", this};
    this->thunderstorm = new QCheckBox{"Thunderstorm", this};
    this->reset = new QPushButton{"Reset filters", this};
    QVBoxLayout* mainLayout = new QVBoxLayout{this};
    mainLayout->addWidget(this->list);
    this->spinner = new QSpinBox{};
    QFont font("Courier", 50, 10, true);
	spinner->setFont(font);
	this->slider = new QSlider{ Qt::Horizontal };
	slider->setMinimumHeight(50);
	slider->setMinimumWidth(400);
	mainLayout->addWidget(spinner);
	mainLayout->addWidget(slider);
    mainLayout->addWidget(overcast);
    mainLayout->addWidget(foggy);
    mainLayout->addWidget(sunny);
    mainLayout->addWidget(rain);
    mainLayout->addWidget(thunderstorm);
    mainLayout->addWidget(reset);
}

void GUI::populate(std::vector<Weather> repo) {
    this->list->clear();
    std::vector<Weather> all_w = this->repo->getRepo();
    for (Weather& w: all_w)
        this->list->addItem(QString::fromStdString(w.toString()));
}

void GUI::connections() {
    QObject::connect(this->list, &QListWidget::itemSelectionChanged, [this](){
        int index = this->getListIndex();
        if(index < 0)
            return ;
    });
    QObject::connect(spinner, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
	QObject::connect(spinner, QOverload<int>::of(&QSpinBox::valueChanged), slider, &QSlider::setValue);
	QObject::connect(slider, &QSlider::valueChanged, spinner, &QSpinBox::setValue);
	QObject::connect(this->reset, &QPushButton::clicked, this, &GUI::resetSlider);
	QObject::connect(spinner, SIGNAL(valueChanged(int)), this, SLOT(setFValue(int)));

}

GUI::GUI(Repo *r): repo{r}{
    this->start();
    this->populate(this->repo->getRepo());
    this->connections();
    this->show();
}

int GUI::getListIndex() const {
    QModelIndexList allIndexes = this->list->selectionModel()->selectedIndexes();
    int selectedIndex = allIndexes.at(0).row();
    return selectedIndex;
}

void GUI::resetSlider() {
    this->slider->setValue(0);
    this->spinner->setValue(0);
    this->overcast->setChecked(false);
    this->foggy->setChecked(false);
    this->sunny->setChecked(false);
    this->rain->setChecked(false);
    this->thunderstorm->setChecked(false);
}

void GUI::setFValue(int val) {
    this->value = val;
    this->filter(val);
}

void GUI::filter(int val) {
    std::vector<Weather> all_w = this->repo->getRepo();
    std::vector<Weather> new_w;
    for(Weather& w: all_w){
        if(w.getProb() < val)
            new_w.push_back(w);
    }
    this->populate(new_w);
}
