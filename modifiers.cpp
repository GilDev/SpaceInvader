#include"modifiers.h"

Modifiers::Modifiers() : QObject(), QGraphicsRectItem(0,0,50,50)
{
    lootbox = new QGraphicsPixmapItem(this);
    lootbox->setPixmap(QPixmap(":/player/coffredemerde.png"));
    tmp = new QTimer();
    QObject::connect(tmp,SIGNAL(timeout()),this,SLOT(fall()));

    tmp->start(200);
}


void Modifiers::fall()
{
    setPos(x(),y() + 10);
}
