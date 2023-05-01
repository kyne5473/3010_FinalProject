
#ifndef PLAYERS_H
#define PLAYERS_H




#include <QObject>
#include <QColor>
#include <QGraphicsItem>



class players : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    players(QColor color, const int x, const int y);

    int get_x() const { return x_; }
    int get_y() const { return y_; }
    bool getStart(){ return start_; }
    int getSquare(){return squareNum;}

    void set_x(int x) { x_ = x; }
    void set_y(int y) { y_ = y; }
    void setStart(){start_ = true;}
    void setSquare(int squareNumber){squareNum = squareNumber;}

    QGraphicsItem* getPlayerItem() {return playerItem;}

    bool hasStarted = false;

    int lastPos;

    int getReRolls(){return reRolls;};
    void setReRolls(){reRolls --;};

    int getUndo(){return undo;};
    void setUndo(){undo --;};

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

private:
    std::string name;
};

#endif // PLAYERS_H
