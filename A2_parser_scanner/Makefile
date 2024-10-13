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
	echo -e "\n" | ./parse
	echo -e "if x < y\n    write x\nend\n" | ./parse
	echo -e "x := 5\ny := 10\nif x <> y\n    write x\nend\n" | ./parse
	echo -e "x := 1\ny := 10\nwhile x < y\n    if x = 5\n        write x\n    end\n    x := x + 1\nend\n" | ./parse
	echo -e "x := 0\nwhile x <= 5\n    write x\n    x := x + 1\nend\n" | ./parse
	echo -e "x := 7\ny := 3\nif x > y * 2\n    write x\nend\n" | ./parse