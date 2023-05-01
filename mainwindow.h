
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>


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

private slots:
    void on_voteNo_clicked();

    void on_voteYes_clicked();

    void on_vetoButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    int totalPlayers = 0;

    QVector<QString> playerNames;
    QVector<QString> playerRoles;
};

#endif // MAINWINDOW_H
