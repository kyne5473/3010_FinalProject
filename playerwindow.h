#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QLabel>
#include <QPushButton>

class playerWindow: public QWidget
{
    Q_OBJECT
public:
    playerWindow(int player, bool isFascist, QString n);
    int getVote(){return vote;};
public slots:
    void enableButtons();
signals:
    void yesPressed();
    void noPressed();
private:
    QPushButton* voteNo;
    QPushButton* voteYes;
    QLabel* nameLabel;
    QLabel* roleLabel;
    QPushButton* yesButton;
    QPushButton* noButton;

    int playerNum;
    bool fascist;
    QString name;

    int vote = -1; //1 for true, 0 for false, -1 initialize
};

#endif // PLAYERWINDOW_H
