#variables
OBJECTS = main.c control_leds.c password.o inttochar.o menu_local.o fun_nointerrup.o juegosdeluces.o adc_load.o ComunicacionSerial.o menu_remoto.o control_leds_remote.o juegosdeluces_remote.o
HEADERS = my_header.h
NAME = ejecutable



all: ejecutable run

#corre programa
run: ejecutable
	clear
	-./$(NAME)

#compila el ejecutable linkeando los .o
ejecutable: $(OBJECTS) 
	gcc -o $(NAME) $(OBJECTS) $(HEADERS) -lwiringPi 


#crear objetos y unir sus librerias
#si no se le indica como make utilizara sus reglas implisitas, es decir sabe como crear objetos
#ahora si ese objeto requiere algo particular se recomienda aclarar

main.o: main.c my_header.h
	gcc  -c main.c 

control_leds.o: control_leds.c inttochar.o
	gcc -c control_leds.c -lwirinPi 

juegosdeluces.o:juegosdeluces.c
	gcc -c juegosdeluces.c -lwirinPi 

inttochar.o: inttochar.s

password.o: password.c

adc_load.o: adc_load.c


menu_local.o: menu_local.c

fun_nointerrup.o: fun_nointerrup.c

ComunicacionSerial.o: ComunicacionSerial.c
	gcc -c ComunicacionSerial.c -lwirinPi 

menu_remoto.o: menu_remoto.c

control_leds_remote.o: 
	gcc -c control_leds_remote.c -lwirinPi 

juegosdeluces_remote.o : juegosdeluces_remote.c
	gcc -c juegosdeluces_remote.c -lwirinPi

#limpiar
clean:
	rm -f $(NAME) *.o *.gch
