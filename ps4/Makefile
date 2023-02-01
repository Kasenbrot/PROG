OUTPUT=ps4
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
SOURCES=main.c bmp.c transformations.c


all: ps4

codeanalysis: $(SOURCES)
	cppcheck --enable=unusedFunction --error-exitcode=1 $^

$(OUTPUT): main.o bmp.o transformations.o
	echo "Running compilation"
	cppcheck --enable=unusedFunction --error-exitcode=1 $(SOURCES)
	$(CC) $(FLAGS) $^ $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	echo "Building object file main.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

bmp.o: bmp.c
	echo "Building object file bmp.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

transformations.o: transformations.c
	echo "Building object file transformations.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@


clean:
	rm -rf *.o $(OUTPUT)

push:
	astyle --mode=c --indent=spaces=4 $(SOURCES)
	git commit -a
	git push


