#ifndef __BALL_H__
#define __BALL_H__
#include "ball.h"
#endif

void move_ball(struct pong_ball* b, struct paddle* l, struct paddle* r){
	mvaddch(b->y, b->x, ' ');
	
	//check for collisions with paddles
	//right paddle
	if ((b->x == r->x)&&((b->y <= (r->y + 2))&&(r->y >= (r->y - 2))))  {
		b->run = b->run * (-1);
		if (b->y == r->y){
			b->rise = 0;
		}
		else {
			if (b->rise < 0)
				b->rise = 1;
			else
				b->rise = -1;
		}

	}
	//left paddle
	else if ((b->x == l->x)&&((b->y <= (l->y + 2))&&(b->y >= (l->y - 2))))  {
		b->run = b->run * (-1);
		if (b->y == l->y){
			b->rise = 0;
		}
		else {
			if (b->rise < 0)
				b->rise = 1;
			else
				b->rise = -1;
		}
		
	}

	if (b->y == 0 || b->y == getmaxy(stdscr))
		b->rise *= (-1);

	b->x += b->run;
	b->y += b->rise;

	if (b->x < 0){//r player scores
		b->x = getmaxx(stdscr)/2;
		b->y = getmaxy(stdscr)/2;
		b->rise = 0;
		r->score += 1;
		b->run *= -1;
		display_score(r);
	}
	else if (b->x > getmaxx(stdscr)){//l player scores
		b->x = getmaxx(stdscr)/2;
		b->y = getmaxy(stdscr)/2;
		b->rise = 0;
		l->score += 1;
		b->run *= -1;
		display_score(l);
	}

	attron(COLOR_PAIR(b->color));
	mvaddch(b->y, b->x, ACS_DIAMOND);
	attroff(COLOR_PAIR(b->color));
}

