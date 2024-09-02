CC = gcc
CFLAGS = -Wall -Wextra
BUILD_DIR = build
INCLUDE_DIR = include
SRC_DIR = src
TESTS_BATS_DIR = tests/bats
TESTS_CUNIT_DIR = tests/cunit
EXEC = bataille_navale
testCU = $(BUILD_DIR)/testCunit
cunitTests = $(wildcard $(TESTS_CUNIT_DIR)/*.c)
batsTests = $(TESTS_BATS_DIR)/checktest1.bats
readmeFile = docs/README.md
htmlFile = docs/README.html

.PHONY: all clean debug valgrind test bats html link start

# Cible par défaut
all: compile

# Compilation du programme principal
compile: $(EXEC)

$(EXEC): $(BUILD_DIR)/main.o $(BUILD_DIR)/bataille_navale.o $(BUILD_DIR)/stats.o | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< -std=c11 -I$(INCLUDE_DIR)

$(BUILD_DIR)/bataille_navale.o: $(SRC_DIR)/bataille_navale.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< -std=c11 -I$(INCLUDE_DIR)

$(BUILD_DIR)/stats.o: $(SRC_DIR)/stats.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< -std=c11 -I$(INCLUDE_DIR)

# Lancement du débogueur GDB
debug: $(EXEC)
	gdb $(EXEC)

# Lancement de l'analyse mémoire avec Valgrind
valgrind: $(EXEC)
	valgrind --leak-check=full ./$(EXEC)
	
# Nettoyage des fichiers de compilation et de l'exécutable
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(htmlFile)
	rm -rf $(EXEC)

# Exécution des tests unitaires avec CUnit
test: $(testCU)
	./$(testCU)

$(testCU): $(cunitTests) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ -std=c11 -I$(INCLUDE_DIR) $^ -lcunit

# Exécution des tests unitaires avec Bats
bats: $(batsTests)
	bats $^

# Génération du fichier HTML à partir du fichier README.md
html: $(readmeFile)
	pandoc $< -f markdown -t html -s -o $(htmlFile)

# Lier les fichiers objets générés
link: $(EXEC) $(testCU)
	$(CC) $(CFLAGS) -o $(EXEC) -std=c11 $^ -lcunit

# Exécution du logiciel
start: $(EXEC)
	./$(EXEC)

# Créer le dossier build s'il n'existe pas
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)