all: countWords 

countWords: countWords.o
	gcc -m32 -g -Wall -o countWords countWords.o 

countWords.o: count-words.c
	gcc -g -Wall -m32 -c -o countWords.o count-words.c 

.PHONY: clean

clean:
	rm -f *.o