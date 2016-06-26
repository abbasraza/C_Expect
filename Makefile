EXEC = c_expect
SRC = c_expect.c test1.c

all:
	gcc -o $(EXEC) $(SRC)

clean:
	rm -rf $(EXEC) *.o

