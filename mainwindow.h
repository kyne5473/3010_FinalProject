
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QVBoxLayout>
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

    void increaseVote(){voteCount ++;};

    void endGame(bool w);



private slots:

    void button1();
    void button2();
    void button3();

    void voteYes();
    void voteNo();

    void on_pushButton_clicked();

    void button12();
    void button22();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    int totalPlayers = 0;

    QVector<QString> playerNames;
    QVector<bool> playerRoles;
    QVector<playerWindow*> windows;

    int voteCount = 0;

    int presidentIndex = 0;

    bool deck[17] = {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1};

    playerWindow* myWindow;

    std::vector <bool> vote2;

    QPushButton* buttonPress1;
    QPushButton* buttonPress2;
    QPushButton* buttonPress3;

    std::vector <bool> output;

    QVBoxLayout *layout;
    QDialog *popup;

    QDialog *popup2;

    void popUp2();

    int libs = 0;
    int facs = 0;

    QGraphicsScene* liberalScene;
    QGraphicsScene* facistScene;

    QGraphicsRectItem* libRect1;
    QGraphicsRectItem* libRect2;
    QGraphicsRectItem* libRect3;
    QGraphicsRectItem* libRect4;
    QGraphicsRectItem* libRect5;

    QGraphicsRectItem* facRect1;
    QGraphicsRectItem* facRect2;
    QGraphicsRectItem* facRect3;
    QGraphicsRectItem* facRect4;
    QGraphicsRectItem* facRect5;
    QGraphicsRectItem* facRect6;


};

#endif // MAINWINDOW_H
