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

#define NUM_ARGS      2



//missatges d'error
#define MSG_ERR_NUM_ARGS        "Número d'arguments incorrecte.\n"





int main(int argc, char *argv[]) {
    if (argc != NUM_ARGS){
          write(2, MSG_ERR_NUM_ARGS, sizeof(MSG_ERR_NUM_ARGS));
          return EXIT_FAILURE;
  }
  char* file_name = argv[NUM_ARGS-1]; //nom del fitxer "ConfigT1"

  ConfigT1 configT1 = FILE_read_configT1(file_name);

  //comprobo que hagi llegit be!!!
  printf("\n%s\n", configT1.telescope);
  printf("\n%d\n",configT1.wait_time);
  printf("\n%s\n", configT1.ip);
  printf("\n%d\n",configT1.port);




  return 0;
}
