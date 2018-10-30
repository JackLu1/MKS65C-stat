all: stat.c
	gcc stat.c

run: all
	./a.out stat.c
