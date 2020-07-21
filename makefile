# Makefile

INTERPRETE = interprete
SRC = main.c
CONJUNTO = conjunto
INTERVALO = intervalo
COMP = gcc
ARGSCOMP = -Wall -Wextra -Werror -std=c99 -g

all: $(INTERPRETE)

$(INTERPRETE): $(CONJUNTO).o $(INTERVALO).o $(SRC)
	$(COMP) $(ARGSCOMP) -o $(INTERPRETE) $(SRC) $(CONJUNTO).o $(INTERVALO).o 

$(INTERPRETE).o: $(INTERPRETE).c
	$(COMP) $(ARGSCOMP) -c $(INTERPRETE).c

$(CONJUNTO).o: ./Conjunto/$(CONJUNTO).c
	$(COMP) $(ARGSCOMP) -c ./Conjunto/$(CONJUNTO).c

$(INTERVALO).o: ./Intervalo/$(INTERVALO).c
	$(COMP) $(ARGSCOMP) -c ./Intervalo/$(INTERVALO).c

clean:
	rm *.o