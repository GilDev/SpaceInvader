#ifndef MODIFIERS_H
#define MODIFIERS_H

#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsPixmapItem>
#include<QTimer>
#include<time.h>
#include<QList>
#include<typeinfo>

#include"player.h"

class Modifiers : public QObject, public QGraphicsRectItem
{
    Q_OBJECT


public:

    Modifiers();

public slots:
    void fall();


private:
    QGraphicsPixmapItem *lootbox;
    QTimer *tmp;
};



#endif // MODIFIERS_H
