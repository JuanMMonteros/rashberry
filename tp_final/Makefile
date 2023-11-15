#variables
OBJECTS = main.o
NAME = ejecutable


all: ejecutable run

#corre programa
run: ejecutable
	.\$(NAME)

#compila el ejecutable linkeando los .o
ejecutable: $(OBJECTS)
	gcc -o $(NAME) $(OBJECTS)


#crear objetos y unir sus librerias
#si no se le indica como make utilizara sus reglas implisitas, es decir sabe como crear objetos

main.o: main.c



#limpiar
clean:
	rm -f $(NAME) *.o
