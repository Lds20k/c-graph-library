.PHONY: test build

STD=-std=c11
FLAGS=-c -W -Wall -pedantic

build: bin/static/cgraph.a

test: src/test.c
test: FLAGS += -g -O0

clean:
	rm -rf bin

src/test.c: bin/static/cgraph.a
	gcc $(STD) -o bin/test.o src/test.c $(FLAGS)
	gcc $(STD) -o bin/test bin/test.o -Lbin/static -lcgraph

bin/static/cgraph.a: bin/list.o
	ar rcs bin/static/libcgraph.a bin/static/list.o bin/static/node.o bin/static/data.o

bin/list.o: bin/node.o
	gcc $(STD) -o bin/static/list.o src/cgraph/list/list.c $(FLAGS)
	gcc $(STD) -o bin/shared/list.o src/cgraph/list/list.c -fPIC $(FLAGS)

bin/node.o: bin/data.o
	gcc $(STD) -o bin/static/node.o src/cgraph/node/node.c $(FLAGS)
	gcc $(STD) -o bin/shared/node.o src/cgraph/node/node.c -fPIC $(FLAGS)

bin/data.o: bin/static bin/shared
	gcc $(STD) -o bin/static/data.o src/cgraph/data/data.c $(FLAGS)
	gcc $(STD) -o bin/shared/data.o src/cgraph/data/data.c -fPIC $(FLAGS)

bin/shared: bin
	mkdir -p bin/shared

bin/static: bin
	mkdir -p bin/static

bin:
	mkdir -p bin
