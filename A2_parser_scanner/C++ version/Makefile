# Makefile for the C++ calculator scanner/parser.

parse: parse.o scan.o
	g++ -o parse parse.o scan.o

parse.o: parse.cpp scan.h
	g++ -c parse.cpp

scan.o: scan.cpp scan.h
	g++ -c scan.cpp

clean:
	rm -f *.o parse scantest

# Type make test to run the test cases
test: parse
	echo -e "x := 10 + 20 - 5\nwrite x\n" | ./parse
	echo -e "read x\nx := 73\nwrite x * 1\n" | ./parse
	echo -e "x := 5 3 + 4\nwrite x\n" | ./parse
	echo -e "\n" | ./parse