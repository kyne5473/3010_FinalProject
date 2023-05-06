
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QTime>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <QGraphicsLineItem>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QInputDialog>
#include <QLCDNumber>
#include <algorithm>
#include <QVBoxLayout>
#include <QTimer>
#include <vector>
#include "playerwindow.h"
#include "card.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int numPlayers = QInputDialog::getInt(this, "Number of Players", "Number of Players:", 5,5,10);
    setTotalPlayers(numPlayers);
    for (int i = 0; i < numPlayers; i++) {
        QDialog dialog;
        QLabel nameLabel("Enter player " + QString::number(i + 1) + " name:");
        QLineEdit nameLineEdit;
        QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

        QVBoxLayout layout(&dialog);
        layout.addWidget(&nameLabel);
        layout.addWidget(&nameLineEdit);
        layout.addWidget(&buttonBox);

        connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
        connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

        if (dialog.exec() == QDialog::Accepted) {
            addPlayerName(nameLineEdit.text());
        } else {
            break;
        }
    }

    int f = totalPlayers/2;
    int count = totalPlayers;
    for(int i = 0; i < totalPlayers; i++){
        int num = rand() % count;
        count--;
        if(num < f){
            playerRoles.push_back(true);
            f--;
        }else{
            playerRoles.push_back(false);
        }
    }


    QGraphicsView * liberalView = ui->liberalsView;
    liberalView->setStyleSheet("background: transparent");
    QPixmap pixmap("C:/Users/kylen/OneDrive/Documents/Intensive Programming/FinalProject/secretHitler/liberals.png");
    QGraphicsPixmapItem* liberalItem = new QGraphicsPixmapItem(pixmap);
    liberalItem->setPos(0, 0);
    QRectF rect = liberalView->viewport()->rect();
    liberalItem->setScale(qMin(rect.width() / pixmap.width(), rect.height() / pixmap.height()));
    liberalScene = new QGraphicsScene();
    liberalScene->addItem(liberalItem);
    liberalView->setScene(liberalScene);

    QGraphicsView * facistView = ui->facistView;
    facistView->setStyleSheet("background: transparent");
    QPixmap pixmap2("C:/Users/kylen/OneDrive/Documents/Intensive Programming/FinalProject/secretHitler/facists.png");
    QGraphicsPixmapItem* facistItem = new QGraphicsPixmapItem(pixmap2);
    facistItem->setPos(0, 0);
    QRectF rect2 = facistView->viewport()->rect();
    facistItem->setScale(qMin(rect2.width() / pixmap2.width(), rect2.height() / pixmap2.height()));
    facistScene = new QGraphicsScene();
    facistScene->addItem(facistItem);
    facistView->setScene(facistScene);

    //create a view for each player
    for(int i = 0; i < totalPlayers; i++){
        myWindow = new playerWindow(i, playerRoles[i], playerNames[i]);
        myWindow->setWindowTitle("Player: " + playerNames[i]);
        windows.push_back(myWindow);
        connect(myWindow, &playerWindow::yesPressed, this, &MainWindow::voteYes);
        connect(myWindow, &playerWindow::noPressed, this, &MainWindow::voteNo);
        connect(ui->pushButton, &QPushButton::clicked, myWindow, &playerWindow::enableButtons);
        myWindow->show();
    }

    QDialog *popup = new QDialog;
    popup->setWindowTitle("Vote");
//    popup->setFixedSize(200, 100);
    QVBoxLayout *layout = new QVBoxLayout;
    popup->setLayout(layout);
    QString text = "Vote for Presidential candidate: " + getPlayerName(presidentIndex);
    QLabel *label = new QLabel(text);
    layout->addWidget(label);
    setWindowFlag(Qt::WindowStaysOnTopHint);
    popup->show();
    fc = new FCard();
    lc = new LCard();


//    initiateVote();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::voteYes(){
    voteCount++;
}

void MainWindow::voteNo(){
    voteCount--;
}

void MainWindow::gameLoop(){
    presidentIndex += 1;
//    initiateVote();
//    showCards(showCards());
//    playCard();
//    std::cout << "Vote in loop: " << voteCount << std::endl;
}

int MainWindow::showCards(){

}

int MainWindow::showCards(int c){
//    switch (c){
//        case 0:

//        case 1:

//        case 2:

//    }
}

bool MainWindow::initiateVote(){
    for(int i = 0; i < windows.size(); i ++){
        if(windows[i]->getVote()){
            voteYes();
        }else if(windows[i]->getVote() == 0){
            voteNo();
        }
    }
    return true;
}

void MainWindow::playCard(){
    if(!output[0]){
        std::cout<<"Placing lib";
        QGraphicsPixmapItem* libCardItem = lc->getCard(); //FLYWEIGHT HERE
        if(libs == 0){
            libCardItem->setPos(65, 45);
            libCardItem->setScale(0.43);
            liberalScene->addItem(libCardItem);
        } else if(libs == 1){
            liberalScene->addItem(libCardItem);
            libCardItem->setPos(153, 45);
            libCardItem->setScale(0.43);
        } else if(libs == 2){
            liberalScene->addItem(libCardItem);
            libCardItem->setPos(241, 45);
            libCardItem->setScale(0.43);
        } else if (libs == 3){
            liberalScene->addItem(libCardItem);
            libCardItem->setPos(330, 45);
            libCardItem->setScale(0.43);
        } else {
            liberalScene->addItem(libCardItem);
            libCardItem->setPos(417, 45);
            libCardItem->setScale(0.43);
            endGame(true);
        }
        libs++;
    } else {
        std::cout<<"Placing fac";
        QGraphicsPixmapItem* facCardItem = fc->getCard();
        if(facs == 0){
            facCardItem->setPos(15, 45);
            facCardItem->setScale(0.43);
            facistScene->addItem(facCardItem);
        } else if(facs == 1){
            facCardItem->setPos(105, 45);
            facCardItem->setScale(0.43);
            facistScene->addItem(facCardItem);

            int temp = rand() % totalPlayers;

                    QDialog *popup = new QDialog;
                    popup->setWindowTitle("Role of Random Player");
                        popup->setFixedSize(1300, 600);
                    popup->setStyleSheet("font-size:40px;");
                    QVBoxLayout *layout = new QVBoxLayout;
                    popup->setLayout(layout);
                    QString role;
                    if(getPlayerRole(temp)){
                        role = " facist";
                    }else{
                        role = " liberal";
                    }
                    QString text = "Player " + getPlayerName(temp) + " has the role of: " + role;
                    QLabel *label = new QLabel(text);
                    label->setAlignment(Qt::AlignCenter);
                    layout->addWidget(label);
                    setWindowFlag(Qt::WindowStaysOnTopHint);
                    popup->show();


        } else if(facs == 2){
            facCardItem->setPos(195, 45);
            facCardItem->setScale(0.43);
            facistScene->addItem(facCardItem);

            int temp = rand() % totalPlayers;

            QDialog *popup = new QDialog;
            popup->setWindowTitle("Role of Random Player");
            popup->setFixedSize(1300, 600);
            popup->setStyleSheet("font-size:40px;");
            QVBoxLayout *layout = new QVBoxLayout;
            popup->setLayout(layout);
            QString role;
            if(getPlayerRole(temp)){
                        role = " facist";
            }else{
                        role = " liberal";
            }
            QString text = "Player " + getPlayerName(temp) + " has the role of: " + role;
            QLabel *label = new QLabel(text);
            label->setAlignment(Qt::AlignCenter);
            layout->addWidget(label);

            setWindowFlag(Qt::WindowStaysOnTopHint);
            popup->show();

        } else if (facs == 3){
            facCardItem->setPos(285, 45);
            facCardItem->setScale(0.43);
            facistScene->addItem(facCardItem);
            int temp = rand() % totalPlayers;
            windows[temp]->close();
            totalPlayers --;

        } else if(facs == 4){
            facCardItem->setPos(375, 45);
            facCardItem->setScale(0.43);
            facistScene->addItem(facCardItem);
            int temp = rand() % totalPlayers;
            windows[temp]->close();
            totalPlayers --;
        } else {
            facCardItem->setPos(465, 45);
            facCardItem->setScale(0.43);
            facistScene->addItem(facCardItem);
            endGame(false);
        }
        facs++;
    }
    popup2->close();
}

void MainWindow::endGame(bool w){
    QDialog *popup = new QDialog;
    popup->setWindowTitle("Game over!");
    QString text;
    if(w){
        text = "Liberals won!";
    } else {
        text = "Fascists won!";
    }
    popup->setFixedSize(200, 100);
    QVBoxLayout *layout = new QVBoxLayout;
    popup->setLayout(layout);
    QLabel *label = new QLabel(text);
    layout->addWidget(label);
    setWindowFlag(Qt::WindowStaysOnTopHint);
    popup->show();
}

void MainWindow::button1(){
    output.erase(output.begin());
    popup->close();
    popUp2();

}
void MainWindow::button2(){
    output.erase(output.begin()+1);
    popup->close();
    popUp2();
}
void MainWindow::button3(){
    output.erase(output.begin()+2);
    popup->close();
    popUp2();
}

void MainWindow::popUp2(){
    popup2 = new QDialog;
    popup2->setWindowTitle("Eliminate a card");
    popup2->setFixedSize(200, 100);
    QVBoxLayout *layout = new QVBoxLayout;
    popup2->setLayout(layout);

    if(output[0] == false){
        buttonPress1 = new QPushButton("Liberal");
        buttonPress1->setStyleSheet("background-color: blue; color:white;");
    }else{
        buttonPress1 = new QPushButton("Facist");
        buttonPress1->setStyleSheet("background-color: red; color:white;");
    }
    if(output[1] == false){
        buttonPress2 = new QPushButton("Liberal");
        buttonPress2->setStyleSheet("background-color: blue; color:white;");
    }else{
        buttonPress2 = new QPushButton("Facist");
        buttonPress2->setStyleSheet("background-color: red; color:white;");
    }
    connect(buttonPress1, &QPushButton::clicked, this, &MainWindow::button12);
    connect(buttonPress2, &QPushButton::clicked, this, &MainWindow::button22);
    layout->addWidget(buttonPress1);
    layout->addWidget(buttonPress2);
    popup2->setLayout(layout);
    popup2->show();
}

void MainWindow::button12(){
    output.erase(output.begin());
    playCard();
}

void MainWindow::button22(){
    output.erase(output.begin()+1);
    playCard();
}

void MainWindow::on_pushButton_clicked()
{
    initiateVote();
    if(voteCount >= 0){
//        QDialog *popup = new QDialog;
//        popup->setWindowTitle("Vote Passed");
//        popup->setFixedSize(200, 100);
//        QVBoxLayout *layout = new QVBoxLayout;
//        popup->setLayout(layout);
//        QString text = "Vote Passed. New President: " + getPlayerName(presidentIndex);
//        QLabel *label = new QLabel(text);
//        layout->addWidget(label);
//        setWindowFlag(Qt::WindowStaysOnTopHint);
//        popup->show();
//        voteCount = 0;

        //Do Something to president

        //Determine card role

        for(int i = 0; i < 3; i ++){
            int temp = rand() % 10;
            if(temp > 5){
                output.push_back(false);
            }else{
                output.push_back(true);
            }
        }

        popup = new QDialog;
        popup->setWindowTitle("Vote Passed");
        popup->setFixedSize(200, 100);
        layout = new QVBoxLayout;
        popup->setLayout(layout);

        if(output[0] == false){
            buttonPress1 = new QPushButton("Liberal");
            buttonPress1->setStyleSheet("background-color: blue; color:white;");
        }else{
            buttonPress1 = new QPushButton("Facist");
            buttonPress1->setStyleSheet("background-color: red; color:white;");
        }
        if(output[1] == false){
            buttonPress2 = new QPushButton("Liberal");
            buttonPress2->setStyleSheet("background-color: blue; color:white;");
            layout->addWidget(buttonPress2);
        }else{
            buttonPress2 = new QPushButton("Facist");
            buttonPress2->setStyleSheet("background-color: red; color:white;");
        }
        if(output[2] == false){
            buttonPress3 = new QPushButton("Liberal");
            buttonPress3->setStyleSheet("background-color: blue; color:white;");
        }else{
            buttonPress3 = new QPushButton("Facist");
            buttonPress3->setStyleSheet("background-color: red; color:white;");
        }
        connect(buttonPress1, &QPushButton::clicked, this, &MainWindow::button1);
        connect(buttonPress2, &QPushButton::clicked, this, &MainWindow::button2);
        connect(buttonPress3, &QPushButton::clicked, this, &MainWindow::button3);

        layout->addWidget(buttonPress1);
        layout->addWidget(buttonPress2);
        layout->addWidget(buttonPress3);
        popup->setLayout(layout);
        popup->show();
        voteCount = 0;

    } else{
        presidentIndex ++;
        presidentIndex %= 6;
        voteCount = 0;
        QDialog *popup = new QDialog;
        popup->setWindowTitle("Vote Failed");
//        popup->setFixedSize(400, 200);
        QVBoxLayout *layout = new QVBoxLayout;
        popup->setLayout(layout);
        QString text = "Vote Failed. Presidential candidate: " + getPlayerName(presidentIndex);
        QLabel *label = new QLabel(text);
        setWindowFlag(Qt::WindowStaysOnTopHint);
        layout->addWidget(label);
        popup->show();

    }
    std::cout << "End: " << voteCount << std::endl;
    //Do something
    //Then reset voteCount to 0
}

