all: driver.c
	gcc driver.c
run:
	./a.out
	make clear
clear:
	rm a.out
