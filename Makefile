snake: clean
	gcc src/game.c src/main.c src/objects.c src/snake.c -g -lncurses -I./include -o snake

snake_with_compiled_ncurses:
	gcc -static src/main.c src/objects.c src/snake.c -g -I./include -L/home/gvillanovanm/Github/c/workspace/ncurses/lib/ -lncurses -o snake

snake_stripped: clean
	gcc src/main.c src/objects.c src/snake.c -lncurses -I./include -o snake
	
compile_objects: clean
	gcc -I./include -c src/objects.c -o src/objects.o 
	gcc -I./include -c src/snake.c -o src/snake.o 
	gcc -I./include -c src/game.c -o src/game.o 
	gcc -I./include -c src/main.c -o src/main.o

clean:
	rm -f src/*.o
	rm -f snake
