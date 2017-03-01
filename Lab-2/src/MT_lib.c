#include "MT_lib.h"

int mt_clrscr()
{
	write(1, "\E[H\E[J", sizeof(char) * strlen("\E[H\E[J"));
	return 0;
}

int mt_gotoXY(int x, int y)
{
	char buf[18] = "\E[0", x1[5] = {0} , y1[5] = {0};
	sprintf(x1, "%d", x);
	sprintf(y1, "%d", y);
	strcat(buf, x1);
	strcat(buf, ";");
	strcat(buf, y1);
	strcat(buf, "H");
	write(1, buf, 18);

	return 0;
}

int mt_getscreensize(int *rows, int *cols)
{
	struct winsize
	{
		unsigned short ws_row;
		unsigned short ws_cols;
		unsigned short ws_xpixel;
		unsigned short ws_ypixel;
	} ws;
	
	if (!ioctl(1, TIOCGWINSZ, &ws))
	{
		*rows = ws.ws_row;
		*cols = ws.ws_cols;
		return 0;
	} else {
		write(2, "Error getting size\n", strlen("Error getting size\n") * sizeof(char));
		return -1;
	}
}

int mt_setfgcolor(enum colors)
{

}

int mt_setbgcolor(enum colors)
{

}

void CONSOLE_TEST()
{
	int rows, cols;

	mt_clrscr();
	mt_gotoXY(20, 20);
	mt_getscreensize(&rows, &cols);
	mt_setfgcolor(red);
	mt_setbgcolor(cyan);
	
	printf("Size of the console: %dx%d\n", rows, cols);
}