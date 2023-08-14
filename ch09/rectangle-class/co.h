
#ifndef CO_H
#define CO_H

class CO
{
private:
    int c1x, c1y;

public:
    CO(int x1, int y1);
    ~CO();

    void createCO(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
};


#endif