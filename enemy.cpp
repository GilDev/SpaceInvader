#include"enemy.h"

Enemy::Enemy(int x, int y, int type, QGraphicsScene *sceneRect): QObject(), QGraphicsRectItem(0,0,49,49)
{


    thisScene = sceneRect;
    srand(time(0));

    sprite = new QGraphicsPixmapItem(this);
    if(type == 1)
    {
        sprite->setPixmap(QPixmap(":/enemy/REDA.png"));
    }
    else if(type == 2)
    {
        sprite->setPixmap(QPixmap(":/enemy/patate.png"));
    }
    else if(type == 3 || type == 4)
    {
        sprite->setPixmap(QPixmap(":/enemy/kriper.png"));
    }



    sceneRect->addItem(this);
    setPos(x, y);
    QTimer *sped = new QTimer ();
    sped->start(50);


    enemyPattern = new Pattern (type);
    QObject::connect(sped, SIGNAL(timeout()), this, SLOT(moveDown()));
}

void Enemy::moveDown()
{

    setPos(x() + enemyPattern->posX(),y() + enemyPattern->posY());
    enemyPattern->nextPos();

    QList<QGraphicsItem *> playerTouched = collidingItems();
    int n = playerTouched.size();
    for(int i = 0; i < n; i++)
    {
        if(typeid(* playerTouched[i]) == typeid(Player))
        {
            emit touchPlayer();
            scene()->removeItem(this);
        }

    }

    if(y() == 600)
    {
        delete this;
    }

}

Enemy::~Enemy()
{

}
