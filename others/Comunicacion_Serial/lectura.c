/* Configuración y uso de termios para acceder al puerto serie de PC en GNU/Linux */
/* Recibe caracter por puerto serie */
/* Compila: gcc -Wall lecturaUART.c -o lectura */
/* Ejecuta: ./lectura */  

# include <stdio.h>  /* Definiciones de la entrada/salida estandar */
# include <fcntl.h>  /* File control definitions */
# include <unistd.h> /* Definiciones de funciones estandar de UNIX */
# include <termios.h> /* Definiciones de funciones de termios para configurar comunicacion serial */
# define BAUDRATE B115200 /* Definicion de cte de velocidad de comnicacion serial*/

int main ( void )
{
  int fd ; /* Descriptor de archivo del puerto serie*/
  struct termios oldtty , newtty ; /* Definicion de estructuras termios para configurar parametros de comunicacion serial*/
  char dato;

  fd = open ("/dev/ttyUSB0", O_RDWR | O_NOCTTY ); /* Apertura del puerto serie */
  if ( fd == -1)
  {
  printf ("ERROR : no se pudo abrir el dispositivo.\n");
  return -1;
  }
  tcgetattr(fd,&oldtty); /* Lectura de los parametros de configuracion actuales*/

  /* BAUDRATE: Fija la tasa bps. Podria tambien usar cfsetispeed y cfsetospeed.*/
  /* CS8: especifica 8 bits de dato por byte*/
  /* CLOCAL: conexion local, sin control de modem*/
  /* CREAD: activa recepcion de caracteres*/
  /* IGNPAR:  ignora los bytes con error de paridad (en caso que este activo el control de paridad)*/
  /* para mas informacion ver https://man7.org/linux/man-pages/man3/termios.3.html */
  
  newtty = oldtty;
  newtty.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
  newtty.c_iflag = IGNPAR;
  newtty.c_oflag = 0;
  newtty.c_lflag = 0;		/* desactiva todas las funcionalidades del eco y modo canonico, y no envia segnales al programa llamador*/
  newtty.c_cc[VTIME]    = 0;	/* temporizador entre caracter */
  newtty.c_cc[VMIN]    = 1;	/* bloquea lectura hasta llegada de un caracter */ 


  tcflush(fd, TCIFLUSH); /* Descarta datos recibidos en el buffer del puerto serie pero no leido aun*/
  tcsetattr(fd,TCSANOW,&newtty); /* Seteo de los parametros de configuracion nuevos*/
  
  while(1){

    printf("recibiendo dato serial: ");
    read(fd, &dato, 1);	/*lectura del puerto serie*/
    printf("%c\n", dato);
    //tcdrain(fd); 
  }
  
  tcsetattr(fd,TCSANOW,&oldtty); /* Configura el puerto serie con los parametros originales*/
close (fd); /*cierre del puerto serie*/
return 0;
}
