CC = gcc
CFLAGS = -Wall 
TARGET = exec

SRCS = main.c vie.c jeu.c affichage.c jeuJoueur.c jeuOrdi.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) -fsanitize=address -o $(TARGET) $(OBJS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
