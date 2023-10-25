/* Configuración y uso de termios para acceder al puerto serie de PC en GNU/Linux */
/* Envia caracter por puerto serie en modo no canonico, con lectura de teclado no bloqueante */
/* Compila: gcc -Wall escrituraUART.c -o escritura */
/* Ejecuta: ./escritura */

#include<fcntl.h>
#include<termios.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

void estadolinea(char *puerto, struct termios opciones);
int velocidad(int speed);
void setup_port(int *fd, char *puerto);
int init_keyboard();
void close_keyboard();
int readch();
void comunicacion(int *fd);
static struct termios initial_settings, new_settings;

int main(){
	int fd;
	char puerto[20] = "/dev/ttyAMA0";

	//Apertura del puerto 
	fd = open(puerto, O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);
	if (fd == -1){
		printf("Error: no se puede abrir el dispositivo.\n");
		return -1;
	}
	else
		fcntl(fd, F_SETFL, O_NDELAY);
	
	setup_port(&fd,puerto);
	comunicacion(&fd);
	close(fd);
	exit(0);
}

void setup_port(int *fd, char *puerto){
	struct termios opciones;

	//lectura del estado de linea por la estructura termios
	tcgetattr(*fd, &opciones);

	//Fijando velocidad del puerto
	cfsetispeed(&opciones, velocidad(115200));

	//Habilitacion del receptor y modo local
	opciones.c_cflag |= (CLOCAL | CREAD);

	//Tamaño de palabra
	opciones.c_cflag &= ~CSIZE; /*limpia mascara de bits por caracter*/
	opciones.c_cflag |= CS8; /*8 bits de dato*/

	//Fijando Paridad 
	opciones.c_cflag &= ~PARENB; /*sin control de paridad*/

	//Fijando la cantidad de stop bits
	opciones.c_cflag &= ~CSTOPB; /*un bit de STOP */

	//Condicion para que lea de a un elemento en modo NO CANONICO
	opciones.c_lflag &= ~(ECHO | ICANON | ISIG);
	opciones.c_oflag &= ~OPOST;
	opciones.c_cc[VTIME] = 0;
	opciones.c_cc[VMIN] = 1;

	//Fijacion de los parametros del puerto
	tcsetattr(*fd, TCSANOW, &opciones);

	//Obtencion de los parametros del puerto
	tcgetattr(*fd, &opciones);

	printf("Despues de la configuracion del puerto: \n");
	estadolinea(puerto, opciones);
}

void estadolinea(char *puerto, struct termios opciones){
	int speed;
	printf("%s: ", puerto);
	//Bits de cada palabra
	if((opciones.c_cflag & CSIZE) == CS5) printf("5");
	if((opciones.c_cflag & CSIZE) == CS6) printf("6");
	if((opciones.c_cflag & CSIZE) == CS7) printf("7");
	if((opciones.c_cflag & CSIZE) == CS8) printf("8");
	//Paridad
	if((opciones.c_cflag & PARENB) == 0) printf("N");
	else{
		if((opciones.c_cflag & PARODD) == PARODD) printf("O");
		else printf("E");
	}
	//Velocidad de transmision
	printf(" ");
	speed = cfgetispeed(&opciones);
	switch(speed){
		case B50: printf("50"); break;
		case B75: printf("75"); break;
		case B110: printf("110"); break;
		case B134: printf("134"); break;
		case B150: printf("150"); break;
		case B200: printf("200"); break;
		case B300: printf("300"); break;
		case B600: printf("600"); break;
		case B1200: printf("1200"); break;
		case B1800: printf("1800"); break;
		case B2400: printf("2400"); break;
		case B4800: printf("4800"); break;
		case B9600: printf("9600"); break;
		case B19200: printf("19200"); break;
		case B38400: printf("38400"); break;
		case B57600: printf("57600"); break;
		case B115200: printf("115200"); break;
		default: printf("Error");break;
	}
	printf(" bps\n");
}

int velocidad(int speed){
	switch(speed){
		case 50:return( B50 );       
		case 75:return( B75 );
		case 110:return( B110 );
		case 134:return( B134 );
		case 150:return( B150 );
		case 200:return( B200 );
		case 300:return( B300 );
		case 600:return( B600 );
		case 1200:return( B1200 );
		case 1800:return( B1800 );
		case 2400:return( B2400 );
		case 4800:return( B4800 );
		case 9600:return( B9600 );
		case 19200:return( B19200 );
		case 38400:return( B38400 );
		case 57600:return( B57600 );
		case 115200: return( B115200 );
		default: printf("Error");
			 exit(1);
			 break;
	}
}


void comunicacion(int *fd){
	char letraout = 0;

	if(init_keyboard()){
		while(letraout != 3){ //<CTRL-C>
				letraout = readch();
				if (letraout == 10){
				letraout = 13;
				}
				if (letraout != 0) 
				write(*fd, &letraout,1);
				}
	close_keyboard();
	}
}

int init_keyboard(){
	if(tcgetattr(0,&initial_settings)<0)
		return 0;
	new_settings = initial_settings;
	new_settings.c_lflag &= ~ICANON;
	new_settings.c_lflag &= ~ECHO;
	new_settings.c_lflag &= ~ISIG;
	new_settings.c_cc[VMIN] = 1;
	new_settings.c_cc[VTIME] = 0;
	if(tcsetattr(0,TCSANOW, &new_settings)<0)
		return 0;
	return 1;
}

void close_keyboard(){
	tcsetattr(0,TCSANOW, &initial_settings);
}


int readch(){
	char ch[3];
	char character;
	int nread;
	new_settings.c_cc[VMIN] = 0;
	tcsetattr(0,TCSANOW,&new_settings);
	nread = read(0,&ch,3);
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW,&new_settings);
	if(nread == 1){
		character = ch[0];
		write(1,&character,1);
		return character;
	}
	if(nread == 3){
		character = ch[2];
		write(1,&character,1);
		return character;
	}
	return 0;
}
