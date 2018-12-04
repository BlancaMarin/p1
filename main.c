/*
* Solucio P1_Fase1
* Curs 2018-2019
*
* @author l.martin
* @author blanca.marin


*/




#include "file.h"
#include "types.h"
#include "arxius.h"
#include "connect.h"

#define NUM_ARGS      2



//missatges d'error
#define MSG_ERR_NUM_ARGS        "Número d'arguments incorrecte.\n"
#define MSG_ERR_READ            "No s'ha trobat directori files.\n "
#define MSG_TESTING             "Testing files...\n"
#define MSG_CONNECTING          "Connecting to Lionel...\n"
#define MSG_CONNECT_READY       "Connection ready.\n"
#define MSG_WAIT                "Waiting...\n"
int fd_server;
ConfigT1 configT1;


void interrupt_connection() {
	close(fd_server);
	exit(0);
}

void llegint_Archius(void){
	alarm(configT1.wait_time);
}

int main(int argc, char *argv[]) {
	configT1.wait_time = 0;
  int ok = 0;
  char aux[100];

  if (argc != NUM_ARGS){
        write(2, MSG_ERR_NUM_ARGS, sizeof(MSG_ERR_NUM_ARGS));
        return EXIT_FAILURE;
  }
  char* file_name = argv[NUM_ARGS-1]; //nom del fitxer "ConfigT1"

	configT1 = FILE_read_configT1(file_name);




  sprintf(aux, "Starting %s.\n", configT1.telescope);
  write(1, aux, strlen(aux));

  write(1, MSG_CONNECTING, sizeof(MSG_CONNECTING));

  fd_server = CONNECT_to_server(configT1.ip, configT1.port);
  printf("surto de connexio\n");
  if (fd_server == -1) {
  		signal(SIGINT, interrupt_connection);
      return EXIT_FAILURE;
	}else{
    write(1, MSG_CONNECT_READY, sizeof(MSG_CONNECT_READY));
    write(1, MSG_TESTING, sizeof(MSG_TESTING));
		write(1, MSG_WAIT, sizeof(MSG_WAIT));


    ok = Arxius_read_arxius();
    if (ok == -1){
          write(2, MSG_ERR_READ, sizeof(MSG_ERR_NUM_ARGS));
          return EXIT_FAILURE;
    }
		signal(SIGALRM, (void*)llegint_Archius);
		alarm(configT1.wait_time);
		while (1){
			pause();
			Arxius_llegir_contingut();
			write(1, MSG_WAIT, sizeof(MSG_WAIT));

		}

	}







  return 0;
}
