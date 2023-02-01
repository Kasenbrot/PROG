OUTPUT=ps2
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
SOURCES=main.c k.c hof.c ui.c


all: ps2

codeanalysis: $(SOURCES)
	cppcheck --enable=unusedFunction --error-exitcode=1 $^

$(OUTPUT): main.o k.o hof.o ui.o
	echo "Running compilation"
	cppcheck --enable=unusedFunction --error-exitcode=1 $(SOURCES)
	$(CC) $(FLAGS) $^ $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	echo "Building object file main.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

k.o: k.c
	echo "Building object file k.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

hof.o: hof.c
	echo "Building object file hof.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@


ui.o: ui.c
	echo "Building object file ui.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

clean:
	rm -rf *.o $(OUTPUT)

push:
	astyle --mode=c --indent=spaces=4 $(SOURCES)
	git commit -a
	git push

