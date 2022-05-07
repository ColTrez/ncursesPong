#ifndef __NCURSES_H__
#define __NCURSES_H__
#include <ncurses.h>
#endif

#ifndef __PADDLE_H__
#define __PADDLE_H__
#include "paddle.h"
#endif

#ifndef __BALL_H__
#define __BALL_H__
#include "ball.h"
#endif

//define speed ball moves at
#define GAME_SPEED 20

int main(int argc, char *argv[]){
	
	int ch;

	initscr();
	timeout(GAME_SPEED);
	start_color();
	curs_set(0);//hide the cursor
	cbreak();//disable line buffering

	keypad(stdscr, true);//enable reading from keyboard
	noecho();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);

	attron(COLOR_PAIR(1));
	printw("Press F1 to exit");
	refresh();

	int middleOfScreen = getmaxy(stdscr)/2;
	int screenWidth = getmaxx(stdscr);

	struct paddle l;
	init_paddle(&l, middleOfScreen, 4, 2);
	init_pair(l.color, COLOR_RED, COLOR_RED);//red for l
	l.scoreWindow = newwin(5, 5, getmaxy(stdscr)-5, 0);
	box(l.scoreWindow, 0, 0);
	display_score(&l);

	struct paddle r;
	init_paddle(&r, middleOfScreen, screenWidth - 5, 3);
	init_pair(r.color, COLOR_BLUE, COLOR_BLUE);//blue for r
	r.scoreWindow = newwin(5, 5, getmaxy(stdscr)-5, getmaxx(stdscr)-5);
	box(r.scoreWindow, 0, 0);
	display_score(&r);

	//initial drawing of paddles
	draw_paddles(&l, &r);

	//draw ball
	struct pong_ball ball;
	ball.y = middleOfScreen;
	ball.x = screenWidth / 2;
	ball.rise = 0;
	ball.run = 1;
	ball.color = 4;
	init_pair(ball.color, COLOR_MAGENTA, COLOR_BLACK);

	attron(COLOR_PAIR(ball.color));
	mvaddch(ball.y, ball.x, ACS_DIAMOND);
	attroff(COLOR_PAIR(ball.color));

	while((ch = getch()) != KEY_F(1)){
		switch(ch){
			//cases for moving l paddle
			case 'w':
				move_paddle(&l, UP);
				break;

			case 's':
				move_paddle(&l, DOWN);
				break;

			//cases for moving r paddle
			case KEY_UP:
				move_paddle(&r, UP);
				break;

			case KEY_DOWN:
				move_paddle(&r, DOWN);
				break;

		}

		move_ball(&ball, &l, &r);
		draw_paddles(&l, &r);
		refresh();
	}

	endwin();
	return 0;
}

