TARGET = myx86
OBJS = main.o
CC = gcc
CFLAGS += -Wall -m32

.PHONY: all
all :
	make $(TARGET)
%.o : %c Makefile
	$(CC) $(CFLAGS) -c $<

$(TARGET) : $(OBJS) Makefile
	$(CC) -o -m32 $@ $(OBJS)
