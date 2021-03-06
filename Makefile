.PHONY: build run clean

default: build run

build:
	g++	src/core/*.cpp	src/models/*.cpp	-o	output.out

run:
	./output.out

clean:
	rm	src/core/*.o	src/models/*.o *.out