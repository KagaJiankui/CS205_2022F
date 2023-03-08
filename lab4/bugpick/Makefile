source=$(wildcard *.cpp)
exe=$(patsubst %.cpp, %, $(source))
cc=clang++
cflags= -g -Wall -O0

all:$(source)
	$(cc) $(cflags) $(source) -o $(exe)