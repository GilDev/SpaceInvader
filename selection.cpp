#include<selection.h>

Selection::Selection() : QObject(), QGraphicsRectItem(0,0,199,199)
{
    opaqueArea();
    setFlag(QGraphicsItem::ItemIsFocusable);
    bonoboSprite = new QGraphicsPixmapItem(QPixmap(QString(":/player/bonobo ") + QString::number(selectedChara) + QString(" 200.png")));

}

void Selection::addToScene(QGraphicsScene *scene)
{
    scene->addItem(this);
    this->setPos(300,200);
    scene->addItem(bonoboSprite);
    bonoboSprite->setPos(300,200);
}

void Selection::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(selectedChara == 1)
        {
            selectedChara = 6;
        }
        else
        {
            selectedChara--;
        }
        bonoboSprite->setPixmap(QPixmap(QString(":/player/bonobo ") + QString::number(selectedChara) + QString(" 200.png")));
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(selectedChara == 6)
        {
            selectedChara = 1;
        }
        else
        {
            selectedChara++;
        }
        bonoboSprite->setPixmap(QPixmap(QString(":/player/bonobo ") + QString::number(selectedChara) + QString(" 200.png")));
    }
    else if(event->key() == Qt::Key_Space)
    {
        emit selected(selectedChara);
    }
}
