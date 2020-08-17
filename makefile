# Makefile

INTERPRETE = interprete
SRC = main.c
CONJUNTO = conjunto
INTERVALO = intervalo
HASH = hash
TREE = tree
COMP = gcc
ARGSCOMP = -Wall -Wextra -Werror -std=c99 -g

all: $(INTERPRETE)

$(INTERPRETE): $(CONJUNTO).o $(INTERVALO).o $(HASH).o $(TREE).o $(SRC)
	$(COMP) $(ARGSCOMP) -o $(INTERPRETE) $(SRC) $(CONJUNTO).o $(INTERVALO).o $(HASH).o $(TREE).o

$(INTERPRETE).o: $(INTERPRETE).c
	$(COMP) $(ARGSCOMP) -c $(INTERPRETE).c

$(CONJUNTO).o: ./Conjunto/$(CONJUNTO).c
	$(COMP) $(ARGSCOMP) -c ./Conjunto/$(CONJUNTO).c

$(INTERVALO).o: ./Intervalo/$(INTERVALO).c
	$(COMP) $(ARGSCOMP) -c ./Intervalo/$(INTERVALO).c

$(HASH).o: ./Hash/$(HASH).c
	$(COMP) $(ARGSCOMP) -c ./Hash/$(HASH).c

$(TREE).o: ./Tree/$(TREE).c
	$(COMP) $(ARGSCOMP) -c ./Tree/$(TREE).c

clean:
	rm *.o