#include "file.h"

char* read_string(int fd, char end) {
    char* buffer = malloc(sizeof(char));
    int i = 0;

    while ((read(fd, &buffer[i], 1)) > 0 && buffer[i++] != end){
        buffer = (char *) realloc(buffer, i + 1);

    }
    /*
    char aux;
    int i=0;
     read(fd, &aux, 1);
     buffer = (char *)malloc(sizeof(char));
     while(aux != '\n'){
       buffer[i]=aux;
       i++;
       buffer = (char *) realloc(buffer, sizeof(char)*(i+1));

       read(fd, &aux,1);
     }
     read(fd, &aux,1);
     //buffer = (char *) realloc(buffer, i+1);*/
    //buffer[i] = '\0';
    return buffer;
}

ConfigT1 FILE_read_configT1(char *file_name) {
  ConfigT1 configT1;
  char* aux;


  //init configT1
  configT1.telescope = "";
  configT1.wait_time = -1;
  configT1.ip = "";
  configT1.port = -1;


  //obro i llegeixo fitxer de text
  int fd = open(file_name, O_RDONLY);
  if (fd < 0) { //error a l'obrir el fitxer
  	write(2, ERR_MSG_OPEN, sizeof(ERR_MSG_OPEN));

  }else{
    //llegeixo nom
    configT1.telescope = read_string(fd,'\n');
    //llegeixo temps espera (faig atoi)
    aux = read_string(fd, '\n');
    configT1.wait_time = atoi(aux);
    //printf("\n%d: wait_time\n", configT1.wait_time);
    //legeixo ip
    configT1.ip = read_string(fd,'\n');
    //llegeixo port (faig atoi)
    aux = read_string(fd, '\n');
    configT1.port = atoi(aux);
    close(fd);
  }

  return configT1;

}
