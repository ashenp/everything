CC = /opt/compiler/gcc-4.8.2/bin/gcc
CXX = /opt/compiler/gcc-4.8.2/bin/g++


test : test.o  
	$(CXX) -g -std=c++11 test.o -o test 
test.o : test.cpp 
	$(CXX) -g -std=c++11 -c test.cpp -o test.o  

clean : 
	rm *.o test

			
