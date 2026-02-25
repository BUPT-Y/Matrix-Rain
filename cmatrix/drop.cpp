#include "drop.h"
#include <stdio.h>

#include "Config.h"
#include "winapi.h"

extern int current_width, current_heght;

const char set[] = "0123456789qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM@#$%&";
//const char set[] = "01";

inline char random_char() {
	return set[rand() % (sizeof(set) - 1)];
}

drop::drop(int x_arg, int y_arg)
{
	x = x_arg;
	y = y_arg;
	current_len = rand() % (MAX_LENGTH-MIN_LENGTH) + MIN_LENGTH;
}

drop::drop()
{
	x = 0;
	y = 0;
	current_len = 0;
}

void drop::move()
{
	int i;
	for (i = 0; i < current_len; i++)
	{
		if (y - i >= 0 && y - i < current_heght)
		{
			gotoxy(x, y - i);
			printf("%c", random_char());
		}
	}

	if (i == current_len)
	{
		gotoxy(x, y - i);
		printf(" ");
		gotoxy(x, y - i - 1);
		printf(" ");
	}
	y++;
}