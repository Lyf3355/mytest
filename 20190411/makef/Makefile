SRCS:=$(wildcard *.c)
OBJS:=$(patsubst %*.c,%.o,$(SRCS))
ELF:=main
CFLAGS:=-g -Wall
$(ELF):$(OBJS)
	gcc $^ -o $@
.PHONY:clean
clean:
	rm -rf $(ELF) $(OBJS)
