/*
* Solucio P1_Fase1
* Curs 2018-2019
*
* @author l.martin
* @author blanca.marin
*
*/



#include "file.h"
#include "types.h"
#include "arxius.h"

#define NUM_ARGS      2



//missatges d'error
#define MSG_ERR_NUM_ARGS        "Número d'arguments incorrecte.\n"
#define MSG_ERR_READ            "No s'ha trobat directori files.\n "
#define MSG_WAIT                "Waiting...\n"
#define MSG_TESTING             "Testing files...\n"




int main(int argc, char *argv[]) {
  int ok = 0;
  if (argc != NUM_ARGS){
        write(2, MSG_ERR_NUM_ARGS, sizeof(MSG_ERR_NUM_ARGS));
        return EXIT_FAILURE;
  }
  char* file_name = argv[NUM_ARGS-1]; //nom del fitxer "ConfigT1"

  ConfigT1 configT1 = FILE_read_configT1(file_name);

  char aux[100];
  sprintf(aux, "Starting %s\n", configT1.name);
  write(1, aux, strlen(aux));

  write(1, MSG_WAIT, sizeof(MSG_WAIT);
  write(1, MSG_TESTING, sizeof(MSG_TESTING);


  ok = Arxius_read_arxius(configT1);
  if (ok == -1){
        write(2, MSG_ERR_READ, sizeof(MSG_ERR_NUM_ARGS));
        return EXIT_FAILURE;
  }



  return 0;
}
