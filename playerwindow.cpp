#include "playerwindow.h"

playerWindow::playerWindow(int player, bool isFascist, QString n)
{
    playerNum = player;
    fascist = isFascist;
    name = n;

    nameLabel = new QLabel(name, this);
    nameLabel->setGeometry(30,10,300,100);

    if(isFascist){
        roleLabel = new QLabel("Fascist", this);
        roleLabel->setStyleSheet("color: red;");
    } else {
        roleLabel = new QLabel("Liberal", this);
        roleLabel->setStyleSheet("color: blue;");
    }
    roleLabel->setGeometry(30,60,300,100);

    QFont font = nameLabel->font();
    font.setPointSize(30);
    nameLabel->setFont(font);

    font = roleLabel->font();
    font.setPointSize(30);
    roleLabel->setFont(font);

    yesButton = new QPushButton("Yes",this);
    noButton = new QPushButton("No",this);
    yesButton->setStyleSheet("background-color: green; color:white;");
    noButton->setStyleSheet("background-color: red; color:white;");
    yesButton->setGeometry(400,10,180,50);
    noButton->setGeometry(400,80,180,50);
    noButton->setFont(font);
    yesButton->setFont(font);

    connect(yesButton, &QPushButton::clicked, this, &playerWindow::yesPressed);

    resize(600,150);
}

void playerWindow::yesPressed(){

}

void playerWindow::noPressed(){

}
