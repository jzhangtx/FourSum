FourSum: FourSum.o
	g++ -g -o FourSum.exe FourSum.o -pthread    

FourSum.o: FourSum/FourSum.cpp
	g++ -g  -c -pthread FourSum/FourSum.cpp
