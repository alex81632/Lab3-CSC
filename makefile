CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJFILES = main.o coins.o combinations.o sequential.o paralel.o
TARGET = programa

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

.PHONY: clean
clean:
	rm -f $(OBJFILES)

.PHONY: run
run: $(TARGET)
	./$(TARGET)