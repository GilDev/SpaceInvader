#include"bullet.h"

Bullet::Bullet(int x, int y, QGraphicsScene *sceneRect): QObject(), QGraphicsRectItem(0,0,29,19)
{


    opacity();
    sprite = new QGraphicsPixmapItem(this);
    sprite->setPixmap(QPixmap(":/player/BANANE 1.png"));


    sceneRect->addItem(this);
    setPos(x, y);
    QTimer *sped = new QTimer ();
    sped->start(50);


    QObject::connect(sped, SIGNAL(timeout()), this, SLOT(tireUp()));
}

void Bullet::tireUp()
{
    QList<QGraphicsItem *> enemyTouched = collidingItems();
    int n = enemyTouched.size();
    int deleted = 0;
    for(int i = 0; i < n; i++)
    {
        if(typeid(* enemyTouched[i]) == typeid(Enemy))
        {
            emit enemyDestroyed();
            srand(rand());

            int rng = rand() % 100;
            if(rng < 10)
            {
                Modifiers *bonus = new Modifiers();
                scene()->addItem(bonus);
                bonus->setPos(this->x(), this->y());
            }

            scene()->removeItem(enemyTouched[i]);
            scene()->removeItem(this);
            deleted = 1;
            break;
        }

    }

    setPos(x(),y() - 10);
    if(y() == -60)
    {
        emit comboBreaker();
    }

    if(y() == -60 || deleted ==  1)
    {
        delete this;
    }


}



Bullet::~Bullet()
{
}
