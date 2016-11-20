CC = gcc
CFLAGS = -ansi -g -c -fPIC -I. -I../lib
LD = gcc
LDFLAGS = -g -L../lib -ltriangulation

objs = main.o coord.o between.o notify.o

default: test
test: $(objs)
	$(LD) $(objs) $(LDFLAGS) -o $@
main.o: main.c coord.h between.h notify.h
	$(CC) $(CFLAGS) main.c -o $@
coord.o: coord.c coord.h
	$(CC) $(CFLAGS) coord.c -o $@
between.o: between.c between.h coord.h
	$(CC) $(CFLAGS) between.c -o $@
notify.o: notify.c notify.h
	$(CC) $(CFLAGS) notify.c -o $@
clean:
	rm -f $(objs)

