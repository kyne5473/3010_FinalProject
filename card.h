#ifndef CARD_H
#define CARD_H

#include <QGraphicsItem>

class Card {
public:
    Card(){};
    void setCard(QGraphicsPixmapItem* p){card = p;}
    virtual QGraphicsPixmapItem* getCard(){return card;};
private:
    QGraphicsPixmapItem* card;
};

#endif // CARD_H

#ifndef FCARD_H
#define FCARD_H

#include <QGraphicsItem>

class FCard : public Card{
public:
    FCard();

    virtual QGraphicsPixmapItem* getCard() override {return card;};
private:
    QGraphicsPixmapItem* card;
};

#endif // CARD_F

#ifndef LCARD_H
#define LCARD_H

#include <QGraphicsItem>

class LCard : public Card{
public:
    LCard();

    virtual QGraphicsPixmapItem* getCard() override {return card;};
private:
    QGraphicsPixmapItem* card;
};

#endif // CARD_L

