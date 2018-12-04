
#include "arxius.h"


#define MSG_NOT_FOUND           "No files found.\n"




void enviar_arxiu (char* name){
  //enviare archiu
  char aux[300];
  sprintf(aux, "./Files/%s", name);
  //elimino archivo que acabo de leer
  remove(aux);

}

int Arxius_read_arxius (){

  // Con un puntero a DIR abrimos el directorio
  DIR *dir;
  //en *ent habrá información sobre el archivo que se está "sacando" a cada momento

  dir = opendir ("./Files");
  // Miramos que no haya error
  if (dir == NULL){
    return -1;
  }else{
    return 1;
  }
}

void Arxius_llegir_contingut(){


  char aux[300];
  // Con un puntero a DIR abrimos el directorio
  DIR *dir;
  //en *ent habrá información sobre el archivo que se está "sacando" a cada momento
  struct dirent *ent;

  dir = opendir ("./Files");


  // Empezaremos a leer en el directorio actual *
  //Una vez nos aseguramos de que no hay error
  // Leemos uno a uno todos los archivos que hay

  if ((ent = readdir (dir)) != NULL) {

      // Nos devolverá el directorio actual (.) y el anterior (..), como hace ls
      if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) ){
          //Espero tiempo de espera

          sprintf(aux, "File: %s.\n", ent->d_name);
          write(1, aux, strlen(aux));

          // Una vez tenemos el archivo, lo pasamos a una función para procesarlo.
          enviar_arxiu(ent->d_name);

      }else{
      //miramos si se ha encontrado elgun fichero, si no es asi lo comunicamos al usuario
        write(1, MSG_NOT_FOUND, sizeof(MSG_NOT_FOUND));
        

      }
  }
  closedir (dir);

}
