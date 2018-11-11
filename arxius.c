
#include "arxius.h"

#define MSG_WAIT                "Waiting...\n"
#define MSG_NOT_FOUND           "No files found.\n"


void enviar_arxiu (char* name){
  //enviare archiu
  char aux[300];
  sprintf(aux, "./Files/%s", name);
  //elimino archivo que acabo de leer
  remove(aux);

}

int Arxius_read_arxius (ConfigT1 configT1){
  char aux[300];
  int  i=0;
  // Con un puntero a DIR abrimos el directorio
  DIR *dir;
  //en *ent habrá información sobre el archivo que se está "sacando" a cada momento
  struct dirent *ent;
  // Empezaremos a leer en el directorio actual *
  dir = opendir ("./Files");
  // Miramos que no haya error
  if (dir == NULL){
    return -1;
  }

  write(1, MSG_WAIT, sizeof(MSG_WAIT));
  //Una vez nos aseguramos de que no hay error
  // Leemos uno a uno todos los archivos que hay

  while ((ent = readdir (dir)) != NULL) {
      // Nos devolverá el directorio actual (.) y el anterior (..), como hace ls
      if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) ){
          //Espero tiempo de espera
          sleep(configT1.wait_time);
          sprintf(aux, "File: %s.\n", ent->d_name);
          write(1, aux, strlen(aux));
          write(1, MSG_WAIT, sizeof(MSG_WAIT));
          // Una vez tenemos el archivo, lo pasamos a una función para procesarlo.
          enviar_arxiu(ent->d_name);
          i++;
      }
  }
  //miramos si se ha encontrado elgun fichero, si no es asi lo comunicamos al usuario
  if(i == 0){
          sleep(configT1.wait_time);
          write(1, MSG_NOT_FOUND, sizeof(MSG_NOT_FOUND));
  }
  closedir (dir);

  return 1;
}
