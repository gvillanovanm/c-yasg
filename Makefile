include sources.mk

TARGET = snake

CC     = gcc
CFLAGS = -Wall -Werror -g -O0 $(INCLUDES)
CLIBS  = -lncurses

OBJS = $(SOURCES:.c=.o)

%.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CLIBS) -o $@

.PHONY: compile-objects
compile-objects: $(OBJS)

.PHONY: valgrind
valgrind:
	valgrind --leak-check=full ./$(TARGET)

.PHONY: clean
clean:
	rm -f src/*.o
	rm -f snake
