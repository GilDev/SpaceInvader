#ifndef MENU_H
#define MENU_H

#include<QObject>
#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QKeyEvent>
#include<QGraphicsPixmapItem>



class Menu : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Menu();

    void addToScene(QGraphicsScene *scene);
    void keyPressEvent(QKeyEvent *event);

signals:
    void gameSelected();
    void settingsSelected();
    void exitSelected();
    void customSelected();

private:
    QGraphicsPixmapItem *menuScreen;
    QGraphicsPixmapItem *selectedMenu;
    int pos = 0;


};


#endif // MENU_H
