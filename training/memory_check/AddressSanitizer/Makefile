all: off-by-one-error use-after-free

use-after-free: use-after-free.c
	gcc -fsanitize=address -O0 -fno-omit-frame-pointer -g -o $@ $^
off-by-one-error: off-by-one-error.c
	gcc -fsanitize=address -O0 -fno-omit-frame-pointer -g -o $@ $^
