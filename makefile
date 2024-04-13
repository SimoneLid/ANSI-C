FLAG:=-Wall -Wextra -Wno-unused-variable

ANSI-C: src/*.c
	gcc $(FLAG) src/*.c -o ANSI-C