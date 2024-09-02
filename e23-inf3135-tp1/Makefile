CC = gcc
CFLAGS = -Wall -Wextra 
EXEC = motdedyck

.PHONY : clean 

all: $(EXEC)

$(EXEC): $(EXEC).c
	$(CC) $(CFLAGS) -o $(EXEC) -std=c11 $(EXEC).c

debug: $(EXEC)
	gdb $(EXEC)

clean:
	rm -rf *.o
	rm -rf $(EXEC)
	rm -rf *.html

test:
	bats check.bats

html: README.md sujet.md
	pandoc README.md -f markdown -t html -s -o README.html
	pandoc sujet.md -f markdown -t html -s -o sujet.html