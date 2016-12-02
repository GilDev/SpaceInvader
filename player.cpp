#include"player.h"

Player::Player(int bonoboSkin) : QObject() ,QGraphicsRectItem(0,0, 49, 49)
{

    life1 = new QGraphicsPixmapItem(QPixmap(":/player/KOEUR 2.png"));
    life2 = new QGraphicsPixmapItem(QPixmap(":/player/KOEUR 2.png"));
    life3 = new QGraphicsPixmapItem(QPixmap(":/player/KOEUR 2.png"));


    score = new QGraphicsSimpleTextItem();
    score->setText(QString("Le score est de :") + QString(QString::number(nbPoint)));

    QPen penBlank = QPen(Qt::white);
    score->setPen(penBlank);

    comboText = new QGraphicsSimpleTextItem();
    comboText->setText(QString("Le combo est de :") + QString(QString::number(combo)));
    comboText->setPen(penBlank);



    playerSprite = new QGraphicsPixmapItem(this);
    playerSprite->setPixmap(QPixmap(QString(":/player/bonobo ") + QString::number(bonoboSkin) + QString(".png")));
    setFlag(QGraphicsItem::ItemIsFocusable);

    bulletTimer = new QTimer();
    pngTimer = new QTimer();
    pngTimer->setInterval(bulletTime);
    bulletTimer->setInterval(bulletTimeLong);
    powerUpTime = new QTimer();

    upCheckTimer = new QTimer();

    pngSprite = new QGraphicsPixmapItem(this);
    pngSprite->setPos(50,0);
    upCheckTimer->start(150);

    QObject::connect(powerUpTime,SIGNAL(timeout()),this,SLOT(endPower()));
    QObject::connect(upCheckTimer, SIGNAL(timeout()), this,SLOT(morePower()));
    QObject::connect(pngTimer, SIGNAL(timeout()),this, SLOT(changePngShot()));
    QObject::connect(bulletTimer, SIGNAL(timeout()),this, SLOT(fireAgain()));

}

void Player::addToScene(QGraphicsScene *scene)
{
    scene->addItem(this);
    playerScene = scene;
    scene->addItem(score);
    score->setPos(0,0);
    scene->addItem(comboText);
    comboText->setPos(350,0);
    scene->addItem(life1);
    life1->setPos(710,0);
    scene->addItem(life2);
    life2->setPos(740,0);
    scene->addItem(life3);
    life3->setPos(770,0);
}

void Player::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Left)
    {
        if(this->x() > 0)
        {
        this->setPos(this->x() - 50, this->y());
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(this->x() < 750)
        {
        this->setPos(this->x() + 50, this->y());
        }
    }
    else if(event->key() == Qt::Key_Space)
    {

        if(bulletTimer->isActive() == false)
        {
        Bullet *shoot = new Bullet(this->x() + 10, this->y() - 30, playerScene);
        QObject::connect(shoot, SIGNAL(enemyDestroyed()), this, SLOT(point()));
        QObject::connect(shoot,SIGNAL(comboBreaker()), this,SLOT(breakCombo()));


        pngSprite->setPixmap(QPixmap(":/player/emptyBar.png"));

        pngTimer->start();
        bulletTimer->start();
        }

    }

}

Player::~Player()
{

}

void Player::changePngShot()
{
    pngN++;
    switch(pngN)
    {
    case 1:
        pngSprite->setPixmap(QPixmap(":/player/bar1.png"));
        break;

    case 2:
        pngSprite->setPixmap(QPixmap(":/player/bar2.png"));
        break;

    case 3:
        pngSprite->setPixmap(QPixmap(":/player/bar3.png"));
        break;

    case 4:
        pngSprite->setPixmap(QPixmap(":/player/bar4.png"));
        break;

    case 5:
        pngSprite->setPixmap(QPixmap(":/player/fullBar.png"));
        pngTimer->stop();
        pngN = 0;
        break;
    }
}


void Player::fireAgain()
{
    bulletTimer->stop();
}


void Player::point()
{
    nbPoint+= combo;
    combo++;
    score->setText(QString("Le score est de :") + QString(QString::number(nbPoint)));
    comboText->setText(QString("Le combo est de :") + QString(QString::number(combo)));
    emit augmentDifficulty(nbPoint);
}

void Player::breakCombo()
{
    combo = 1;
    comboText->setText(QString("Le combo est de :") + QString(QString::number(combo)));
}

void Player::hpLoss()
{
    switch(hp)
    {
    case 3:
        life3->setPixmap(QPixmap(":/player/KOEUR.png"));
        break;
    case 2:
        life2->setPixmap(QPixmap(":/player/KOEUR.png"));
        break;
    case 1:
        life1->setPixmap(QPixmap(":/player/KOEUR.png"));
        emit gameOver(nbPoint);
        break;
    }

    combo = 1;
    comboText->setText(QString("Le combo est de :") + QString(QString::number(combo)));
    hp--;
    qDebug("%d", hp);
}

void Player::morePower()
{
    QList<QGraphicsItem *> playerTouched = collidingItems();
    int n = playerTouched.size();
    for(int i = 0; i < n; i++)
    {
        if(typeid(* playerTouched[i]) == typeid(Modifiers))
        {
            scene()->removeItem(playerTouched[i]);

            bulletTime = 20;
            bulletTimeLong = 100;

            pngTimer->setInterval(bulletTime);
            bulletTimer->setInterval(bulletTimeLong);
            powerUpTime->start(10000);

            break;
        }

    }

    if(y() == 600)
    {
        delete this;
    }
}

void Player::endPower()
{
    powerUpTime->stop();
    bulletTime = 100;
    bulletTimeLong = 500;

    pngTimer->setInterval(bulletTime);
    bulletTimer->setInterval(bulletTimeLong);
}

