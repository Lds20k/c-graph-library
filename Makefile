.PHONY: test build clean headers

STD=-std=c11
FLAGS=-c -W -Wall -pedantic

debug: FLAGS += -g -O0
debug: build

test: debug src/test.c

build: bin/static/libcgraph.a bin/static/include bin/static/lib
	cp bin/static/libcgraph.a bin/static/lib/libcgraph.a
	cp -R src/cgraph bin/static/include
	rm $$(find bin/static/include -name "*.c")
	tar -C bin/static -cvzf bin/cgraph.tar.gz include lib

clean:
	rm -rf bin

src/test.c: bin/static/libcgraph.a
	gcc $(STD) -o bin/test.o src/test.c -g -O0 $(FLAGS)
	gcc $(STD) -o bin/test bin/test.o -Lbin/static -lcgraph -g -O0

bin/static/libcgraph.a: bin/list.o
	ar -rcs bin/static/libcgraph.a bin/static/list.o bin/static/node.o bin/static/data.o

bin/list.o: bin/node.o
	gcc $(STD) -o bin/static/list.o src/cgraph/list/list.c $(FLAGS)
	gcc $(STD) -o bin/shared/list.o src/cgraph/list/list.c -fPIC $(FLAGS)

bin/node.o: bin/data.o
	gcc $(STD) -o bin/static/node.o src/cgraph/node/node.c $(FLAGS)
	gcc $(STD) -o bin/shared/node.o src/cgraph/node/node.c -fPIC $(FLAGS)

bin/data.o: bin/static bin/shared
	gcc $(STD) -o bin/static/data.o src/cgraph/data/data.c $(FLAGS)
	gcc $(STD) -o bin/shared/data.o src/cgraph/data/data.c -fPIC $(FLAGS)

bin/static/lib:
	mkdir -p bin/static/lib

bin/static/include:
	mkdir -p bin/static/include

bin/shared: bin
	mkdir -p bin/shared

bin/static: bin
	mkdir -p bin/static

bin:
	mkdir -p bin
