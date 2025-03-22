all: build run clean

build:
	@gcc src/main.c -o geometry-crays -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

run:
	@./geometry-crays

clean:
	rm ./geometry-crays