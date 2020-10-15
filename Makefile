CC=g++
CFLAGS=-Wall -Wextra
EXEC=./tp3


run: main.cpp memoria.o cache.o cpu.o
	$(CC) $(CFLAGS) main.cpp memoria.o cache.o cpu.o -o $(EXEC)
	./$(EXEC)

cache.o: headers/cache.cpp memoria.o
	$(CC) $(CFLAGS) -c headers/cache.cpp -o cache.o

memoria.o: headers/memoria.cpp
	$(CC) $(CFLAGS) -c headers/memoria.cpp -o memoria.o

cpu.o: headers/cpu.cpp cache.o memoria.o
	$(CC) $(CFLAGS) -c headers/cpu.cpp -o cpu.o

clean:
	rm -rf *.o
