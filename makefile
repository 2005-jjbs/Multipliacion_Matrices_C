# Compilador
GCC = gcc

BIBLIOTECAS =


MODULOS = ballesterosMatrices.c


PROGRAMAS = ejecutable


all: $(PROGRAMAS)

# Cómo compilar el ejecutable
$(PROGRAMAS): $(MODULOS)
	$(GCC) $(MODULOS) -o $(PROGRAMAS) $(BIBLIOTECAS)

# Limpiar ejecutables y objetos
clean:
	rm -f $(PROGRAMAS) *.o
