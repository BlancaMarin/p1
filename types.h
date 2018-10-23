#ifndef _TYPES_H_
#define _TYPES_H_

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

typedef struct {
    char* telescope;
    int  wait_time;
    char* ip;
    int  port;
} ConfigT1;

#endif
