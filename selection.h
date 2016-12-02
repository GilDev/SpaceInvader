#ifndef SELECTION_H
#define SELECTION_H

#include<QObject>
#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QKeyEvent>
#include<QGraphicsPixmapItem>



class Selection : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Selection();
    void addToScene(QGraphicsScene *scene);
    void keyPressEvent(QKeyEvent *event);

signals:
    void selected(int);

private:
    int selectedChara = 1;
    QGraphicsPixmapItem *bonoboSprite;


};


#endif // SELECTION_H
