#ifdef my_header
#define my_header

int control_leds(int);
void GPIOEstadoLEDs(struct LedField leds);
void LEDsOFF();
void pinINIT();
int password();
int menu_local();

//modo remoto
void remoteMode();
void refresh ();
int condition_end_remote();
int up_dw_remote();


//leer ADC
int adc_load();
//limpia consola
void clean_consol();
//Syncronizacion de la comunicacion 
void serialInit();
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
// 
void sendKey();
//
char * reciveKey();

//lectura teclas sin espera activa
int condition_end();
int up_dw();

//lee caracter y lo escribe en pantalla
char read_keyboard();

//juegos luces por algoritmo
void jump(int vel)
void bounce(int vel)

//juego de luces en remoto
int control_leds_remote(char)

#endif
