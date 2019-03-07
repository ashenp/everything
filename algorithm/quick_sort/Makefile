CC = /opt/compiler/gcc-4.8.2/bin/gcc
CXX = /opt/compiler/gcc-4.8.2/bin/g++


test : main.o  
	$(CXX) -g -std=c++11 main.o -o test 
main.o : main.cpp 
	$(CXX) -g -std=c++11 -c main.cpp -o main.o  

clean : 
	rm *.o test

			
