# Makefile
main: MatrixTest.c Matrix.c
	clang -o main.out MatrixTest.c Matrix.c
