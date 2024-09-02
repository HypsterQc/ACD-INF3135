CC = gcc
CFLAGS = -Wall -Wextra
main = motcache
testCU = testCunit

# Cible par défaut
all: main

# Compilation du programme principal
main: $(main).c $(testCU).c
	$(CC) $(CFLAGS) -o $(main) -std=c11 $(main).c
#	$(CC) $(CFLAGS) -o $(testCU) -std=c11 $(testCU).c -lcunit

# Lancement du débogueur GDB
debug: main
	gdb $(main)

# Nettoyage des fichiers de compilation et de l'exécutable
clean:
	rm -rf $(main)
#	rm -rf $(testCU)

# Exécution des tests unitaires avec Bats
test: main
	bats check.bats
#	./testCunit