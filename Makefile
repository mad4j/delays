
all:
	g++ -Wall delays.cpp -o delays

clean:
	rm delays

test:
	./delays 10
