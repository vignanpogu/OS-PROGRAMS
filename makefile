CC =gcc

main: main.o push.o pop.o
	$(CC) -o main main.o push.o pop.o

main.o: main.c
	$(CC) -o main.o -c main.c

push.o: push.c
	$(CC) -o push.o -c push.c

pop.o: pop.c
	$(CC) -o pop.o -c pop.c

lib:
	ar -crv libstack.a push.o pop.o

sharelib:
	$(CC) -o libstack.so push.o pop.o -shared -fPIC

clean:
	rm -rf *.o main
