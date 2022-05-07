#ifndef __PADDLE_H__
#define __PADDLE_H__
#include "paddle.h"
#endif


struct pong_ball {
	int y;
	int x;
	int run;
	int rise;
	int color;
};

void move_ball(struct pong_ball* b, struct paddle* l, struct paddle* r);
