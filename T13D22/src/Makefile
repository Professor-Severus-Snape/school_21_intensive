FLAGS = -Wall -Werror -Wextra

.PHONY: all clean rebuild cipher

all: cipher

cipher:
	gcc $(FLAGS) cipher.c -o ../build/cipher

clean:
	rm -rf ../build/cipher

rebuild: clean all
