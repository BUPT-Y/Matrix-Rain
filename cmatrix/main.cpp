#include <stdio.h>
#include <time.h>
#include "Config.h"
#include <stdlib.h>
#include "drop.h"
#include "winapi.h"
#include <Windows.h>

int num_x, count_y = 0, current_width, current_height;

int main()
{
	drop list[MAX_DROPS];
    int top = -1, bottom = 0;

    hide_cursor();
    system("color 0A");

    srand(time(NULL));
    while (true) 
    {
        Sleep(33);
		current_width = get_screen_width();
        current_height = get_screen_height();
        num_x = rand() % (current_width / 12);

        for (int i = 0; i < num_x; i++) //create new drops
        {
            top = (top + 1) % MAX_DROPS;
            list[top] = drop(rand() % current_width, 0);
	    }

        if(top != -1)
        {
            for (int i = bottom; i != top; i = (i + 1) % MAX_DROPS)//print drops
            {
				list[i].move();
            }
            list[top].move();
        }
        

        for (; list[bottom].get_y() - list[bottom].get_len() > current_height+1; bottom = (bottom + 1) % MAX_DROPS);//delete drops that are out of screen
	}

}




