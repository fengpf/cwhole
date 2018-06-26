#所有的源文件--  .c文件列表
SRCS = $(wildcard *.c)
#
#所有的.o文件列表
OBJS =$(SRCS:.c=.r)

all: $(OBJS)

%.r: %.c
	gcc -g -pthread -o $@ $^
#	gcc -fuse-ld=gold -fsanitize=thread -g -o $@ $^
