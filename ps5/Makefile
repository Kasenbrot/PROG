OUTPUT=ps5
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
SOURCES=main.c backpack.c command.c container.c game.c item.c parser.c room.c world.c

all: ps5

codeanalysis: $(SOURCES)

$(OUTPUT): main.o backpack.o command.o container.o game.o item.o parser.o room.o world.o
	echo "Running compilation"

	$(CC) $(FLAGS) $^ $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	echo "Building object file main.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

backpack.o: backpack.c
	echo "Building object file xxx.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

command.o: command.c
	echo "Building object file xxx.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

container.o: container.c
	echo "Building object file xxx.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

game.o: game.c
	echo "Building object file xxx.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

item.o: item.c
	echo "Building object file xxx.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

parser.o: parser.c
	echo "Building object file xxx.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

room.o: room.c
	echo "Building object file xxx.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

world.o: world.c
	echo "Building object file xxx.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@
