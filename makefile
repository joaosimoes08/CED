OBJS=farao.o\
f.o

CC=nvc++
CFLAGS= -fopenmp

all: farao

f.o: f.cpp
		$(CC) $(CFLAGS) f.cpp -c

farao.o: farao.cpp
		$(CC) $(CFLAGS) farao.cpp -c

farao: $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o farao

clean: 
		rm -f *.o
		rm -f farao
