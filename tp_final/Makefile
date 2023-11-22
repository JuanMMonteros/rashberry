#variables
OBJECTS = main.c control_leds.c password.o
HEADERS = my_header.h
NAME = ejecutable



all: ejecutable run

#corre programa
run: ejecutable
	clean
	-./$(NAME)

#compila el ejecutable linkeando los .o
ejecutable: $(OBJECTS) 
	gcc -o $(NAME) $(OBJECTS) $(HEADERS) -lwiringPi 


#crear objetos y unir sus librerias
#si no se le indica como make utilizara sus reglas implisitas, es decir sabe como crear objetos
#ahora si ese objeto requiere algo particular se recomienda aclarar

main.o: main.c my_header.h
	gcc  -c main.c 

control_leds.o: control_leds.c
	gcc -c control_leds.c -lwirinPi 

password.o: password.c

#limpiar
clean:
	rm -f $(NAME) *.o *.gch
