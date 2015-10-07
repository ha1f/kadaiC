# Makefile
main: main.c Vector3.c
	clang -o main.out main.c Vector3.c
