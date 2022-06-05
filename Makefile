all : exec

exec : demineur.o function.o  
	gcc -o exec demineur.o function.o

main.o : demineur.c demineur.h
	gcc -o demineur.o -c demineur.c

function.o : function.c demineur.h
	gcc -o function.o -c function.c

clean :
	rm *.o exec
