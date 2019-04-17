CC = /opt/compiler/gcc-4.8.2/bin/gcc
CXX = /opt/compiler/gcc-4.8.2/bin/g++

CFLAGS = -I../../../  -std=c++11 -lpthread


webbench : webbench.o socket.o
		   $(CXX) $(CFLAGS) -o webbench webbench.o socket.o
		   
webbench.o : webbench.cpp 	
			$(CXX) $(CFLAGS) -c webbench.cpp 

socket.o : socket.cpp 	
			$(CXX) $(CFLAGS) -c socket.cpp
	


			
