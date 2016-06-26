EXEC = testf
SRC = testf.c

all:
	gcc -o $(EXEC) $(SRC)

clean:
	rm -rf $(EXEC) *.o

