run:
	gcc -Wall ortografia.c dicionario.c -o ortografia
	./ortografia < t.txt
