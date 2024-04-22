#Nome do seu programa
TARGET = pilha

#Compilador a ser utilizado
CC = gcc

#Opções de compilação
CFLAGS = -Wall -std=c99 -g

#Lista de arquivos fonte
SOURCES = *.c

#Lista de arquivos objetos gerados a partir dos arquivos fonte
OBJECTS = $(SOURCES:.c=.o)

#Regra default
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

#Regra para a criação dos arquivos objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $<

#Regra para limpar os arquivos objetos e o executável
clean:
	rm -f $(OBJECTS) $(TARGET)