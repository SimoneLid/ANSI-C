FLAG:=-Wall -Wextra -Wno-unused-variable

ANSI-C: src/*.c
	gcc $(FLAG) -p src/*.c -o ANSI-C