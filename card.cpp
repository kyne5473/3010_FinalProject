#include "card.h"

LCard::LCard(){
    QPixmap pixCard("C:/Users/kylen/OneDrive/Documents/Intensive Programming/FinalProject/secretHitler/libCard.png");
    QGraphicsPixmapItem* libCardItem = new QGraphicsPixmapItem(pixCard);
    card = libCardItem;
}
FCard::FCard(){
    QPixmap pixCard("C:/Users/kylen/OneDrive/Documents/Intensive Programming/FinalProject/secretHitler/facCard.png");
    QGraphicsPixmapItem* facCardItem = new QGraphicsPixmapItem(pixCard);
    card = facCardItem;
}
