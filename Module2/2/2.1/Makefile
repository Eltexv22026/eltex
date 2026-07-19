CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = app

all: $(TARGET)

$(TARGET): main.o phone.o
	$(CC) $(CFLAGS) main.o phone.o -o $(TARGET)

main.o: main.c phone.h
	$(CC) $(CFLAGS) -c main.c

phone.o: phone.c phone.h
	$(CC) $(CFLAGS) -c phone.c

clean:
	rm -f *.o $(TARGET)