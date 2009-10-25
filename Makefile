run : build
	./reader

process_reader :
	ragel scanner.ragel

clean : 
	rm -f ./reader

build : clean process_reader
	gcc -std=c99 -Wall -Werror -fnested-functions token.c scanner.c main.c -L/usr/local/lib -lgdsl -o reader