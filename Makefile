CC = gcc
CFLAGS = -c -O2 -Wall -Wextra -MMD
BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
INCLUDE_DIR = include

all: main

run: all
	./$(BIN_DIR)/main

main: $(OBJ_DIR)/systeminfo.o $(BIN_DIR)/main.o
	$(CC) -o $(BIN_DIR)/main $(OBJ_DIR)/systeminfo.o $(BIN_DIR)/main.o

$(OBJ_DIR)/systeminfo.o: $(SRC_DIR)/systeminfo.c $(INCLUDE_DIR)/systeminfo.h
	$(CC) $(CFLAGS) $(SRC_DIR)/systeminfo.c -o $(OBJ_DIR)/systeminfo.o

$(BIN_DIR)/main.o: $(BIN_DIR)/main.c
	$(CC) $(CFLAGS) $(BIN_DIR)/main.c -o $(BIN_DIR)/main.o

-include $(OBJ_DIR)/*.d

clean:
	rm $(OBJ_DIR)/*.o $(BIN_DIR)/*.o $(BIN_DIR)/main
