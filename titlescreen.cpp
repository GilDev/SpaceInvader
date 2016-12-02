#include"titlescreen.h"

Screen::Screen(int type): QGraphicsScene()
{
    x = type;
    setSceneRect(0,0,800,600);
    title = new QGraphicsPixmapItem();
    if(x == 1)
    {
    title->setPixmap(QPixmap(":/game/Title.png"));
    }
    else if (x == 2)
    {
    title->setPixmap(QPixmap(":/game/GameOver.png"));
    }
    title->setPos(0,0);
    addItem(title);

    setFocus();

}

void Screen::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space && x == 1)
    {
        emit react();
    }
    else if(event->key() == Qt::Key_Escape && x == 2)
    {
        emit react();
    }
}

Screen::~Screen()
{
    delete title;
}
