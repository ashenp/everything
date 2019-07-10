CC = /opt/compiler/gcc-4.8.2/bin/gcc
CXX = /opt/compiler/gcc-4.8.2/bin/g++

all: tail test

tail : tail.o  
	$(CXX) -g -O0 -std=c++11 tail.o -o tail 
tail.o : tail.cpp 
	$(CXX) -g -O0 -std=c++11 -c tail.cpp -o tail.o  

test : test.o  
	$(CXX) -g -O0 -std=c++11 test.o -o test 
test.o : test.cpp 
	$(CXX) -g -O0 -std=c++11 -c test.cpp -o test.o  

clean : 
	rm *.o tail test

			
