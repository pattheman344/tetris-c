tetris: main.c board.c piece.c terminal.c
	gcc main.c board.c piece.c terminal.c -o tetris

clean:
	rm -f tetris