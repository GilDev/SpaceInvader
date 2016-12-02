#ifndef ENEMY_H
#define ENEMY_H

#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QObject>
#include<QTimer>
#include<QList>
#include<typeinfo>

#include"player.h"
#include"pattern.h"
#include"modifiers.h"



class Enemy : public QObject, public QGraphicsRectItem
{

       Q_OBJECT

public:
    Enemy(int x, int y, int type, QGraphicsScene *sceneRect);
    ~Enemy();

signals:
    void touchPlayer();

public slots:

    void moveDown();

private:


    Pattern *enemyPattern;
    QGraphicsScene *thisScene;
    int rng;
    QGraphicsPixmapItem *sprite;
    QGraphicsRectItem *bullet;

};

#endif // ENEMY_H
