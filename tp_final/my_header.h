#ifdef my_header
#define my_header

int control_leds(int);
int password();
int menu_local();

//limpia consola
void clean_consol();

//lectura teclas sin espera activa
int condition_end();
int up_dw();

//lee caracter y lo escribe en pantalla
char read_keyboard();

//juegos luces por algoritmo
void jump(int vel)
void bounce(int vel, volatile int vel_flecha, volatile int salida)

#endif
