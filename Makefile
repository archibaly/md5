CC = gcc
EXE = md5
CFLAGS = -Wall

$(EXE): main.o md5.o
	$(CC) -o $@ $^

main.o: main.c
md5.o: md5.c

clean:
	-rm -f main.o md5.o $(EXE)
