CC = gcc
CFLAGS = -ansi -g -c -fPIC
LD = gcc
LDFLAGS = -shared

lib_objs = fractal.o fractal_round_step.o fractal_single_step.o fractal_aux.o fractal_stack_algorithm.o

default: libtriangulation.so
libtriangulation.so: $(lib_objs)
	$(LD) $(LDFLAGS) $(lib_objs) -o $@
fractal.o: fractal.c fractal.h fractal_types.h fractal_round_step.h
	$(CC) $(CFLAGS) fractal.c -o $@
fractal_round_step.o: fractal_round_step.c fractal_round_step.h fractal_types.h fractal_single_step.h
	$(CC) $(CFLAGS) fractal_round_step.c -o $@
fractal_single_step.o: fractal_single_step.c fractal_single_step.h fractal_types.h fractal_aux.h fractal_stack_algorithm.h
	$(CC) $(CFLAGS) fractal_single_step.c -o $@
fractal_aux.o: fractal_aux.c fractal_aux.h fractal_types.h
	$(CC) $(CFLAGS) fractal_aux.c -o $@
fractal_stack_algorithm.o: fractal_stack_algorithm.c fractal_stack_algorithm.h fractal_types.h
	$(CC) $(CFLAGS) fractal_stack_algorithm.c -o $@
clean:
	rm -f $(lib_objs)
	rm -f $(bin_objs)
