GCC = gcc
CFLAGS = -g -Wall -Wshadow
OBJS = countmain.o

countPixels: $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

$(OBJS): CountMain.c
	$(GCC) $(CFLAGS) -c CountMain.c

clean:
	rm -f *.o
	rm -f countPixels
