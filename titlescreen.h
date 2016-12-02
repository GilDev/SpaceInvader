#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include<QGraphicsScene>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QGraphicsRectItem>

class Screen : public QGraphicsScene
{
    Q_OBJECT
public:

    Screen(int type);
    void keyPressEvent(QKeyEvent *event);
    ~Screen();

signals:
    void react();


private:

    int x;
    QGraphicsPixmapItem *title;
};


#endif // TITLESCREEN_H
