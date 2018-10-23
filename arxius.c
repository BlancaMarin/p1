
#include "arxius.h"


void enviar_arxiu (char* name){
  //enviare archiu
}

int Arxius_read_arxius (ConfigT1 configT1){
printf("ets retressada\n");
  /* Con un puntero a DIR abriremos el directorio */
  DIR *dir;
  /* en *ent habrá información sobre el archivo que se está "sacando" a cada momento */
  struct dirent *ent;

  /* Empezaremos a leer en el directorio actual */
  dir = opendir ("./Files");

  /* Miramos que no haya error */
  if (dir == NULL){
    return -1;

  }


  /* Una vez nos aseguramos de que no hay error, ¡vamos a jugar! */
  /* Leyendo uno a uno todos los archivos que hay */
  while ((ent = readdir (dir)) != NULL) {
      /* Nos devolverá el directorio actual (.) y el anterior (..), como hace ls */
      if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) ){
      /* Una vez tenemos el archivo, lo pasamos a una función para procesarlo. */
          printf("\n%s\n", ent->d_name);
          enviar_arxiu(ent->d_name);
          sleep(configT1.wait_time);
      }
  }
  closedir (dir);

  return 1;
}
