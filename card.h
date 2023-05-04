#ifndef CARD_H
#define CARD_H


class card
{
public:
    card(int powerUp, bool isFascist){this->powerUp = powerUp; fascist = isFascist;}
    int getPowerUp(){return powerUp;}
    void setPowerUp(int i){powerUp = i;}
    bool isFascist(){return fascist;}
    void setFasctist(){fascist=true;}
private:
    bool fascist;
    int powerUp;
};

#endif // CARD_H
