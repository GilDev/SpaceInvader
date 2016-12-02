#ifndef PATTERN_H
#define PATTERN_H

#include<QObject>
#include<time.h>

class Pattern
{
public:
    Pattern(int x);
    int posX();
    int posY();
    void nextPos();

private:
    int pattN = 1;
    int pos = 0;
    int rng;
};


#endif // PATTERN_H
