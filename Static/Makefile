##########################################################################################################
# Hi all, This is the make file for static compilation which will generate 
#1) sum.o amd mul.o
#2) Will create static library libstatic.a
#3) Will generate executable staticout 
##########################################################################################################
staticout:main.o libstatic.a
	cc -o staticout main.c libstatic.a

libstatic.a: mul.o sum.o 
	ar rcs libstatic.a sum.o mul.o

sum.o:sum.c
	cc -c sum.c

mul.o:mul.c
	cc -c mul.c	

main.o:main.c

clean:
	rm -rf *.o libstatic.a staticout
