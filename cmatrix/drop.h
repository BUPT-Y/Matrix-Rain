#pragma once
#include <stdlib.h>

class drop {

private:
    int x;
    int y;
    int current_len;
public:
    drop();
    drop(int, int);
    int get_x() const{ return x; }
    int get_y() const{ return y; }
    void move();
    int get_len() const{ return current_len; }
};