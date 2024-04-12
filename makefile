FLAG:=-Wall -Wextra -Wno-unused-variable

ANSI-C: src/*.c
	gcc $(FLAG) src/*.c -o ANSI-C

try_fork: src/try_fork.c
	gcc $(FLAG) src/try_fork.c -o try_fork