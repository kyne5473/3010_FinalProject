
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
#include "playerwindow.h"


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
    QGraphicsScene* liberalScene = new QGraphicsScene();
    liberalScene->addItem(liberalItem);
    liberalView->setScene(liberalScene);

    QGraphicsView * facistView = ui->facistView;
    facistView->setStyleSheet("background: transparent");
    QPixmap pixmap2("C:/Users/kylen/OneDrive/Documents/Intensive Programming/FinalProject/secretHitler/facists.png");
    QGraphicsPixmapItem* facistItem = new QGraphicsPixmapItem(pixmap2);
    facistItem->setPos(0, 0);
    QRectF rect2 = facistView->viewport()->rect();
    facistItem->setScale(qMin(rect2.width() / pixmap2.width(), rect2.height() / pixmap2.height()));
    QGraphicsScene* facistScene = new QGraphicsScene();
    facistScene->addItem(facistItem);
    facistView->setScene(facistScene);


//    QWidget * wdg = new QWidget(this);
//    QVBoxLayout *vlay = new QVBoxLayout(wdg);
//    QPushButton *btn1 = new QPushButton("btn1");
//    vlay->addWidget(btn1);
////    wdg->setLayout(vlay);
//    setCentralWidget(wdg);
//    wdg->show();

    //create a view for each player
    for(int i = 0; i < totalPlayers; i++){
        playerWindow* myWindow = new playerWindow(i, playerRoles[i], playerNames[i]);
        myWindow->setWindowTitle("Player: " + playerNames[i]);
        windows.push_back(myWindow);
        connect(myWindow, &playerWindow::yesPressed, this, &MainWindow::voteYes);
        myWindow->show();
    }
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
    preisdentIndex += 1;
    initiateVote();
    showCards(showCards());
    playCard();
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
    QPushButton *yesButton = findChild<QPushButton*>("yesButton");
    yesButton->setEnabled(true);

    return true;
}

void MainWindow::playCard(){

}

