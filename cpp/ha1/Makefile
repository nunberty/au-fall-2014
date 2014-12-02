CPP_FLAGS=-O2 -Wall -Werror -std=c++11 -D_GLIBCXX_DEBUG

all: bin/huffman

bin/utils.o: src/utils.cpp src/utils.h
	clang++ $(CPP_FLAGS) -c src/utils.cpp -o bin/utils.o

bin/treeutils.o: src/treeutils.cpp src/treeutils.h
	clang++ $(CPP_FLAGS) -c src/treeutils.cpp -o bin/treeutils.o

bin/binaryio.o: src/binaryio.cpp src/binaryio.h
	clang++ $(CPP_FLAGS) -c src/binaryio.cpp -o bin/binaryio.o

bin/huffman.o: src/huffman.cpp src/huffman.h
	clang++ $(CPP_FLAGS) -c src/huffman.cpp -o bin/huffman.o

bin/main.o: src/main.cpp src/treeutils.h
	clang++ $(CPP_FLAGS) -c src/main.cpp -o bin/main.o

bin/huffman: bin/main.o bin/treeutils.o bin/huffman.o bin/binaryio.o bin/utils.o
	clang++ $(CPP_FLAGS) bin/treeutils.o bin/main.o bin/huffman.o bin/utils.o bin/binaryio.o -o bin/huffman

clean:
	rm -rf bin/*
