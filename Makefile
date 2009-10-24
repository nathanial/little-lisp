run : build
	./reader

build : 
	gcc -std=c99 -Wall -Werror -fnested-functions list.c reader.c main.c -o reader