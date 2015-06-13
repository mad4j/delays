
all:
	(CXX) -Wall delays.cpp -o delays -lrt

clean:
	rm delays

test:
	./delays 10
