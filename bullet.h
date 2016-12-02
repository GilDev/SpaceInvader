#ifndef BULLET_H
#define BULLET_H

#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QObject>
#include<QTimer>
#include<QList>
#include"enemy.h"
#include"modifiers.h"
#include <typeinfo>


class Bullet : public QObject, public QGraphicsRectItem
{

       Q_OBJECT

public:
    Bullet(int x, int y, QGraphicsScene *sceneRect);
    ~Bullet();


signals:
    void enemyDestroyed();
    void comboBreaker();

public slots:

    void tireUp();

private:



    QGraphicsPixmapItem *sprite;
    QGraphicsRectItem *bullet;

};



#endif // BULLET_H
