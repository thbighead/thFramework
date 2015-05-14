all:THFRAMEWORK
	gcc main.c thFramework.o -o main -lpthread -lm -Wall
THFRAMEWORK:
	gcc -c thFramework.c -lpthread -lm -Wall