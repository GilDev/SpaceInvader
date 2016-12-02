#ifndef PLAYER_H
#define PLAYER_H

#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>
#include<QGraphicsItem>
#include<QEvent>
#include<QKeyEvent>
#include<QObject>
#include<QTimer>
#include<QGraphicsSimpleTextItem>
#include<QPen>
#include<QList>
#include<typeinfo>

#include"modifiers.h"
#include"bullet.h"
#include"modifiers.h"


class Player : public QObject, public QGraphicsRectItem
{

    Q_OBJECT
public:

    Player(int bonoboSkin);
    void addToScene(QGraphicsScene *scene);

    void keyPressEvent(QKeyEvent *event);
    ~Player();

signals:
    void augmentDifficulty(int);
    void gameOver(int point);



public slots:
    void point();
    void breakCombo();
    void morePower();
    void endPower();
    void hpLoss();
    void fireAgain();
    void changePngShot();


private:

     QGraphicsPixmapItem *life1;
     QGraphicsPixmapItem *life2;
     QGraphicsPixmapItem *life3;

     QTimer *powerUpTime;
     QTimer *upCheckTimer;
     int bulletTime = 100;
     int bulletTimeLong = 500;

     QTimer *bulletTimer;
     QTimer *pngTimer;
     int pngN = 0;
     QGraphicsPixmapItem *pngSprite;

     QGraphicsSimpleTextItem *score;
     QGraphicsSimpleTextItem *comboText;
     QGraphicsScene *playerScene;
     QGraphicsRectItem *player;
     QGraphicsPixmapItem *playerSprite;
     int nbPoint = 0;
     int combo = 1;
     int hp = 3;


};



#endif // PLAYER_H
