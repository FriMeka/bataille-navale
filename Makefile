SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
INC=$(wildcard *.h)

all : out

%.o : %.c $(INC)
	gcc -c $< -o $@

out : $(OBJ)
	gcc $^ -o $@ -fsanitize=address

clean :
	rm -f *.o
	rm -f out
