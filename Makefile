run : build
	./reader

process_reader :
	ragel reader.ragel

clean : 
	rm -f ./reader

build : clean process_reader
	gcc -std=c99 -Wall -Werror -fnested-functions list.c reader.c main.c -o reader