OUTPUT=ps1
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm
SOURCES=main.c bmp.c playfair.c


all: ps1

codeanalysis: $(SOURCES)
	cppcheck --enable=unusedFunction --error-exitcode=1 $^

$(OUTPUT): main.o bmp.o playfair.o
	echo "Running compilation"
	cppcheck --enable=unusedFunction --error-exitcode=1 $(SOURCES)
	$(CC) $(FLAGS) $^ $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	echo "Building object file main.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

bmp.o: bmp.c
	echo "Building object file bmp.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

playfair.o: playfair.c
	echo "Building object file playfair.o"
	$(CC) $(FLAGS) -c $^ $(LDLIBS) -o $@

clean:
	rm -rf *.o $(OUTPUT)

push:
	astyle --mode=c --indent=spaces=4 $(SOURCES)
	git commit -a
	git push
