CC=gcc

make:
	$(CC) pong.c ball.c paddle.c -o pong -L /usr/lib32 -I /usr/include -lncurses

clean:
	rm ./pong
