CC = gcc
CXX = g++

CFLAGS = -I./ -I /usr/local/include -L /usr/local/lib -lyaml-cpp -std=c++11  -lpthread -lstdc++ -g3 -O0
TARGET := batchdo

PARSER_DIR = ./parser/

SRCS := $(wildcard *.cpp $(PARSER_DIR)*.cpp)
OBJS := $(patsubst %cpp, %o, $(SRCS))

all:$(TARGET)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $<
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) -o $@ *.o
clean:
	rm -rf $(TARGET) *.o


			
