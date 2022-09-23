SRC_DIR=.
SRC=$(wildcard $(SRC_DIR)/*.cpp)
OBJ=$(patsubst %.cpp,%.o,$(SRC))
TARGET=main

CC=clang++ -c
LD=clang++ -o
CFLAGS=-O3 -march=native -Wall -std=c++11

%.o:%.cpp
	$(CC) $(CFLAGS) $< -o $@

$(TARGET):$(OBJ)
	$(LD) $@ $(OBJ)

.PHONY:clean
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)