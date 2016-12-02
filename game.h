#ifndef GAME_H
#define GAME_H

#include<QApplication>
#include<QGraphicsView>
#include<time.h>
#include<QGraphicsSceneMouseEvent>
#include<QFile>
#include<QUrl>
#include<QMediaPlayer>
#include<QMediaPlaylist>


#include"player.h"
#include"enemy.h"
#include"titlescreen.h"
#include"menu.h"
#include"selection.h"


class Game: public QObject
{
    Q_OBJECT

public:
    Game();
    ~Game();

public slots:
    void gameMenu();
    void launchGame();
    void customisation();
    void customReturn(int bonoboChoice);

    void createEnemy();
    void spawnRateSpeed(int score);
    void over(int fScore);
    void exitGame();

signals:
    void returnToMenu();


private:

     QMediaPlaylist *backPlaylist;
     QMediaPlayer *backMusic;

     Menu *mainMenu;
     QGraphicsScene *mainMenuScene;

     QGraphicsScene *customisationScene;
     QGraphicsPixmapItem *customBackground;
     Selection *chosenBonobo;
     int bonoboSelected = 1;

     Screen *title;
     Screen *end;
     QGraphicsView *watch;
     Player *joueur;
     QTimer *tmp;
     QGraphicsPixmapItem *background;
     QGraphicsScene *mainScene;
     QGraphicsScene *titleScreen;
     int rng = time(0);
     int speed = 1000;
     int enemyType = 1;

};



#endif // GAME_H
