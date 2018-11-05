IDIR =../include
CC=g++
CFLAGS=-I $(IDIR)
ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = header.hpp lista.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = intercalacao.o teste_inter.o interface.o indicesecundario.o indiceprimario.o lista.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

teste: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
