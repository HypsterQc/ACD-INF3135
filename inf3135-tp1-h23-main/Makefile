CC = gcc
CFLAGS = -Wall -Wextra
main = canvascii
fichier = nomdufichier

all: main

main: $(main).c
	$(CC) $(CFLAGS) -o $(main) -std=c11 $(main).c

debug: main
	gdb $(main)

clean:
	rm -rf *.o
	rm -rf $(main)
	rm -rf *.html

test:
	bats check.bats

html: README.md sujet.md
	pandoc README.md -f markdown -t html -s -o README.html
	pandoc sujet.md -f markdown -t html -s -o sujet.html