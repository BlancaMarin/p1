#include "connect.h"

#define MSG_ERR_SOCKET      "No s'ha pogut crear el socket.\n"
#define MSG_ERR_CONN        "s'ha produit un error durant la connexió amb el servidor.\n"

int CONNECT_to_server(char *ip, int port) {
    struct sockaddr_in s_addr;
    int socket_conn = -1;

    socket_conn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (socket_conn < 0) write(1, MSG_ERR_SOCKET, sizeof(MSG_ERR_SOCKET));
    else {

        memset(&s_addr, 0, sizeof(s_addr));
        s_addr.sin_family   = AF_INET;
        s_addr.sin_port     = htons(port);
        s_addr.sin_addr.s_addr = inet_addr(ip);

        if (connect(socket_conn, (void *) &s_addr, sizeof(s_addr)) < 0) {
            char buff[128];
            write(1, MSG_ERR_CONN, sizeof(MSG_ERR_CONN));
            int bytes = sprintf(buff, "errno says: %s\n", strerror(errno)); // molt útil
            write(1, buff, bytes);
			      close(socket_conn);
            socket_conn = -1;
        }
    }

    return socket_conn;
}
