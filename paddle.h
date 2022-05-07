#ifndef __NCURSES_H__
#include <ncurses.h>
#endif

struct paddle{
	int y;
	int x;
	int color;
	int score;
	WINDOW* scoreWindow;
};


enum direction{ UP, DOWN };

void init_paddle(struct paddle* p, int init_y, int init_x, int init_color);

void move_paddle(struct paddle* p, enum direction d);

void display_score(struct paddle* p);

void draw_paddle(struct paddle* p);

void draw_paddles(struct paddle* l, struct paddle* r);
