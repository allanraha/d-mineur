all : exec

exec : main.o function.o  
	gcc -o exec main.o function.o

main.o : main.c main.h
	gcc -o main.o -c main.c

function.o : function.c main.h
	gcc -o function.o -c function.c

clean :
	rm *.o exec
