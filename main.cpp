#include<QApplication>
#include"game.h"




int main(int argc, char *argv[]){

  QApplication app(argc, argv);
  Game *joy = new Game();


    return app.exec();
}
