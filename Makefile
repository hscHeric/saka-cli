all: main

run: all
	./bin/main

main: obj/systeminfo.o bin/main.o
	gcc -o bin/main obj/systeminfo.o bin/main.o

obj/systeminfo.o: src/systeminfo.c include/systeminfo.h
	gcc -c src/systeminfo.c -o obj/systeminfo.o

bin/main.o: bin/main.c
	gcc -c bin/main.c -o bin/main.o

clean:
	rm obj/.o bin/.o bin/main