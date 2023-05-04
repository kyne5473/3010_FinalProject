
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include "playerwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int getTotalPlayers(){return totalPlayers;};
    void setTotalPlayers(int num){totalPlayers = num;};

    void addPlayerName(QString name){playerNames.append(name);};
    QString getPlayerName(int index){return playerNames[index];};

    void addPlayerRole(QString name){playerNames.append(name);};
    QString getPlayerRole(int index){return playerNames[index];};

    int currentPlayer = 0;

    void yesClickedButton();

    void gameLoop();

    int showCards();

    int showCards(int c);

    bool initiateVote();

    void playCard();


private slots:
    void voteYes();
    void voteNo();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    int totalPlayers = 0;

    QVector<QString> playerNames;
    QVector<bool> playerRoles;
    QVector<playerWindow*> windows;

    int voteCount = 0;

    int preisdentIndex = -1;

    bool deck[17] = {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1};

};

#endif // MAINWINDOW_H
