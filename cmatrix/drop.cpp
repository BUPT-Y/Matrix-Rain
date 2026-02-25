#include "drop.h"
#include <stdio.h>
#include "winapi.h"

extern int current_width, current_height;

//const char set[] = "0123456789qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM@#$%&";
const char set[] = "01";

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

	for(int i = 0; i < MAX_LENGTH; i++) 
		str[i] = 0;
}

void drop::move()
{
	int i;
	for (i = 0; i < current_len; i++)
	{
		if (y - i >= 0 && y - i < current_height)
		{
			if(str[i] == 0 || rand() % 3 == 1) str[i] = random_char();
			gotoxy(x, y - i);
			printf("%c", str[i]);
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