snake: clean
	gcc src/main.c src/objects.c src/snake.c -g -lncurses -I./include -o snake

compile_objects: clean
	gcc -c src/objects.c -o src/objects.o -I./include   
	gcc -c src/snake.c -o src/snake.o -I./include   
	gcc -c src/main.c -o src/main.o -I./include   

clean:
	rm -f src/*.o
	rm -f snake