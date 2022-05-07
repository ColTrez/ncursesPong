#ifndef __NCURSES_H__
#define __NCURSES_H__
#include <ncurses.h>
#endif

#ifndef __PADDLE_H__
#define __PADDLE_H__
#include "paddle.h"
#endif

//define char to draw paddle with
#define PADDLE ACS_VLINE

void init_paddle(struct paddle* p, int init_y, int init_x, int init_color){
	p->y = init_y;
	p->x = init_x;
	p->color = init_color;
	p->score = 0;
}

void move_paddle(struct paddle* p, enum direction d){
	switch(d){
		case UP:
			mvaddch(p->y+2, p->x, ' ');
			p->y -= 1;
			break;
		case DOWN:
			mvaddch(p->y-2, p->x, ' ');
			p->y += 1;
			break;
	}
}

void display_score(struct paddle* p){

	mvwaddstr(p->scoreWindow, 0, 0, "score");
	mvwprintw(p->scoreWindow, 2, 2, "%d", p->score);
	wrefresh(p->scoreWindow);
}


void draw_paddle(struct paddle* p){

	mvaddch(p->y-2, p->x, PADDLE);
	mvaddch(p->y-1, p->x, PADDLE);
	mvaddch(p->y, p->x, PADDLE);
	mvaddch(p->y+1, p->x, PADDLE);
	mvaddch(p->y+2, p->x, PADDLE);

}

void draw_paddles(struct paddle* l, struct paddle* r){

	//draw left paddle
	attron(COLOR_PAIR(l->color));
	draw_paddle(l);
	attroff(COLOR_PAIR(l->color));

	//draw right paddle
	attron(COLOR_PAIR(r->color));
	draw_paddle(r);
	attroff(COLOR_PAIR(r->color));

	refresh();

}
