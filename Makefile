OBJS=$(wildcard src/*.c)
CC=gcc
CC_OPTIONS=-std=c99
OBJ_NAME=pa2
BUILD_FOLDER=./build/

all: $(OBJS)
	if ! [ -d "./build" ]; then mkdir "./build"; fi
	$(CC) $(OBJS) $(CC_OPTIONS) -o $(BUILD_FOLDER)$(OBJ_NAME)

run: 
	@make all
	./$(BUILD_FOLDER)$(OBJ_NAME)

clean:
	rm -rf $(BUILD_FOLDER)$(OBJ_NAME)
