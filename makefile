# _*_ Makefile _*_
build:
	gcc -Wall -std=c99 ./src/*.c -lSDL2  -o game && ./game

run:
	./game

clean:
	rm game
