executable:main.o substring.o
	g++ -Wall -g main.o substring.o -o executable
main.o:main.cpp substring.h
	g++ -Wall -g -c main.cpp -o main.o
substring.o:substring.cpp substring.h
	g++ -Wall -g -c substring.cpp -o substring.o
clean:
	rm -f *.o executable
