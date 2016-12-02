#include"menu.h"

Menu::Menu() :QObject(), QGraphicsRectItem(0,0,800,600)
{
    menuScreen = new QGraphicsPixmapItem(QPixmap(":/game/firstscreen.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);

    selectedMenu = new QGraphicsPixmapItem(QPixmap(":/game/entourerplay.png"));

}

void Menu::addToScene(QGraphicsScene *scene)
{
    scene->addItem(this);
    scene->addItem(menuScreen);
    scene->addItem(selectedMenu);
}


void Menu::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(pos == 0)
        {
            pos = 1;
            selectedMenu->setPixmap(QPixmap(":/game/entourersetting.png"));
        }
        if(pos == 2)
        {
            pos = 0;
            selectedMenu->setPixmap(QPixmap(":/game/entourerplay.png"));
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(pos == 0)
        {
            pos = 2;
            selectedMenu->setPixmap(QPixmap(":/game/entourerquiter.png"));
        }
        else if(pos == 1)
        {
            pos = 0;
            selectedMenu->setPixmap(QPixmap(":/game/entourerplay.png"));
        }

    }
    else if(event->key() == Qt::Key_Up)
    {
        if(pos == 3)
        {
            pos = 0;
            selectedMenu->setPixmap(QPixmap(":/game/entourerplay.png"));
        }
    }
    else if(event->key() == Qt::Key_Down)
    {
        if(pos == 0)
        {
            pos = 3;
            selectedMenu->setPixmap(QPixmap(":/game/entourercustom.png"));
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        if(pos == 0)
        {
            emit gameSelected();
        }
        else if(pos == 1)
        {
            emit settingsSelected();
        }
        else if(pos == 2)
        {
            emit exitSelected();
        }
        else if(pos == 3)
        {
            emit customSelected();
        }
    }

}
