CC = /opt/compiler/gcc-4.8.2/bin/gcc
CXX = /opt/compiler/gcc-4.8.2/bin/g++

CFLAGS =  -g -O0 -lstdc++ -std=c++11

test : test.o
		   $(CXX) $(CFLAGS) -o test test.o
test.o : test.cpp 	
			$(CXX) $(CFLAGS) -c test.cpp



			
