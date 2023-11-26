#ifdef my_header
#define my_header

int control_leds(int);
int password();
int menu_local();

void remoteMode();
//leer ADC
int adc_load();
//limpia consola
void clean_consol();
//Syncronizacion de la comunicacion 
int sync();
//Menu Remoto
int menu_remoto();
// send 
void send(char);
// recive
char recive();
//esclavo
int esclavo();
//maestro
int maestro();

//lectura teclas sin espera activa
int condition_end();
int up_dw();

//lee caracter y lo escribe en pantalla
char read_keyboard();

//juegos luces por algoritmo
void jump(int vel)
void bounce(int vel)

#endif
