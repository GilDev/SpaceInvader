#include"pattern.h"

Pattern::Pattern(int x)
{
    srand(time(0));
    pattN = x;



}

int Pattern::posX()
{
    int xSet = 0;

    srand(rng);
    rng = rand();
    int m = 0;

    switch(pattN)
    {
    case 1:
        xSet = 0;
        break;

    case 2:
        if(pos < 3)
        {
            xSet = -10;
        }
        else if(pos >= 3)
        {
            xSet = 10;
        }

        break;

    case 3:
        m = rand() % 3;
        m--;
        xSet = m * 10;

        break;

    case 4:
        if(pos < 3)
        {
            xSet = 0;
        }
        else if(pos < 5)
        {
            xSet = 10;
        }
        else if(pos < 7)
        {
            xSet = 0;
        }
        else if(pos < 9)
        {
            xSet = -10;
        }
        else if(pos < 12)
        {
            xSet = 0;
        }
        break;

    }


    return xSet;
}

int Pattern::posY()
{
    int ySet = 0;

    srand(rng);
    rng = rand();
    int m = 0;


    switch(pattN)
    {
    case 1:
        ySet = 10;
        break;

    case 2:
        ySet = 10;
        break;

    case 3:
        ySet = 10;
        break;

    case 4:
        if(pos < 3)
        {
            ySet = 10;
        }
        else if(pos < 5)
        {
            ySet = 0;
        }
        else if(pos < 7)
        {
            ySet = -10;
        }
        else if(pos < 9)
        {
            ySet = 0;
        }
        else if(pos < 12)
        {
            ySet = 10;
        }
    }


    return ySet;
}

void Pattern::nextPos()
{
    pos++;
    switch(pattN)
    {
    case 2:
        if(pos == 6)
        {
            pos = 0;
        }
        break;

    case 4:
        if(pos == 11)
        {
            pos = 0;
        }
        break;
    }
}
