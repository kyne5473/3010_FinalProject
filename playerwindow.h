#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QLabel>
#include <QPushButton>

class playerWindow: public QWidget
{
    Q_OBJECT
public:
    playerWindow(int player, bool isFascist, QString n);
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
};

#endif // PLAYERWINDOW_H
