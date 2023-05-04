
#ifndef CARDFACTORY_H
#define CARDFACTORY_H

#include "card.h"
#include <QVector>


class cardFactory
{
public:
    cardFactory();
    card getLiberal(int powerup);
    card getFascist(int powerup);
private:
    QVector <card> deck;
};

#endif // CARDFACTORY_H
