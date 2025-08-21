CC=gcc
CFLAGS=-Iinclude
OBJ=src/main.o

shell: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

src/%.o: src/%.c include/shell.h
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f shell $(OBJ)
