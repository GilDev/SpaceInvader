#include"game.h"



Game::Game() : QObject()
{

    title = new Screen(1);
    QObject::connect(title,SIGNAL(react()), this, SLOT(gameMenu()));
    QObject::connect(this,SIGNAL(returnToMenu()),this,SLOT(gameMenu()));
    watch = new QGraphicsView(title);
    watch->setFixedSize(800,600);

    //Scroll Bar off
    watch->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    watch->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    watch->show();

}


void Game::gameMenu()
{
    title = new Screen(1);
    delete title;
    mainMenu = new Menu();
    mainMenuScene = new QGraphicsScene(0,0,800,600);
    watch->setScene(mainMenuScene);
    mainMenu->addToScene(mainMenuScene);
    mainMenu->setFocus();
    QObject::connect(mainMenu, SIGNAL(gameSelected()), this, SLOT(launchGame()));
    QObject::connect(mainMenu, SIGNAL(exitSelected()), this, SLOT(exitGame()));
    QObject::connect(mainMenu, SIGNAL(customSelected()), this, SLOT(customisation()));
}

void Game::customisation()
{
    customisationScene = new QGraphicsScene();
    watch->setScene(customisationScene);

    customBackground = new QGraphicsPixmapItem(QPixmap(":/game/Ecran_custom.png"));
    customisationScene->addItem(customBackground);

    chosenBonobo = new Selection();
    chosenBonobo->addToScene(customisationScene);
    chosenBonobo->setFocus();

    QObject::connect(chosenBonobo,SIGNAL(selected(int)),this,SLOT(customReturn(int)));

}

void Game::customReturn(int bonoboChoice)
{
    bonoboSelected = bonoboChoice;
    emit returnToMenu();
}


void Game::launchGame()
{
    mainScene = new QGraphicsScene();
    mainScene->setSceneRect(0,0,800,600);
    background = new QGraphicsPixmapItem();
    background->setPixmap(QPixmap(":/game/BackGround.png"));


    backPlaylist = new QMediaPlaylist();
    backPlaylist->addMedia(QUrl("qrc:/musics/MLG Darude Sandstorm.mp3"));
    backPlaylist->setPlaybackMode(QMediaPlaylist::Loop);


    backMusic = new QMediaPlayer();
    backMusic->setPlaylist(backPlaylist);
    backMusic->play();
    backMusic->setPosition(0);


    mainScene->addItem(background);
    background->setPos(0,0);

    watch->setScene(mainScene);
    joueur = new Player(bonoboSelected);
    joueur->addToScene(mainScene);
    joueur->setRect(0,0,50,50);
    joueur->setPos(350,550);
    joueur->setFocus();


    tmp = new QTimer();
    tmp->setInterval(speed);
    tmp->start();

    speed = 1000;
    tmp->setInterval(speed);
    enemyType = 1;
    QObject::connect(tmp, SIGNAL(timeout()), this, SLOT(createEnemy()));
    QObject::connect(joueur, SIGNAL(augmentDifficulty(int)), this, SLOT(spawnRateSpeed(int)));
    QObject::connect(joueur, SIGNAL(gameOver(int)), this, SLOT(over(int)));




}

void Game::createEnemy()
{


    int rX = 0;

        srand(rng);
        rng = rand();
        rX = rand() % 16;
        Enemy *enemy = new Enemy(rX * 50 + 10, 0, enemyType,mainScene);
        QObject::connect(enemy, SIGNAL(touchPlayer()), joueur, SLOT(hpLoss()));


}

void Game::spawnRateSpeed(int score)
{
    if(score < 10)
    {
        speed = 1000;
        tmp->setInterval(speed);
        enemyType = 1;
    }
    else if(score < 100 && score > 10)
    {
        speed = 500;
        tmp->setInterval(speed);
        enemyType = 2;
    }
    else if(score < 300 && score > 100)
    {
        speed = 300;
        tmp->setInterval(speed);
        enemyType = 4;
    }
    else if(score > 500)
    {
        speed = 200;
        tmp->setInterval(speed);
        enemyType = 3;
    }
}

void Game::over(int fScore)
{

    QGraphicsSimpleTextItem *finalScore = new QGraphicsSimpleTextItem();
    finalScore->setPen(QPen(Qt::white));
    finalScore->setText(QString("Le score est de :") + QString(QString::number(fScore)));
    finalScore->setPos(200,150);

    end = new Screen(2);
    end->addItem(finalScore);
    watch->setScene(end);
    tmp->stop();



    delete joueur;
    delete background;
    delete backMusic;
    delete backPlaylist;
    //delete mainScene;

    QObject::connect(end,SIGNAL(react()), this, SLOT(gameMenu()));

}

void Game::exitGame()
{
    qApp->exit();
}

Game::~Game()
{

}
