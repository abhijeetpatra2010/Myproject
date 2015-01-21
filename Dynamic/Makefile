##########################################################################################################
# Hi all, This is the make file for static compilation which will generate 
#1) sum.o amd mul.o
#2) Will create dynamic library libstatic.so
#3) Will generate executable dynamicout

#fpic-used for relocatable files

##########################################################################################################
dynamicout:main.o libdynamic.so
	cc -o dynamicout main.c libdynamic.so

libdynamic.so: mul.o sum.o 
	cc -shared -o libdynamic.so sum.o mul.o
	
sum.o:sum.c
	cc -c -fpic sum.c

mul.o:mul.c
	cc -c -fpic mul.c	

main.o:main.c
