//DoSFTP
/*libs padrão para uso da socket*/
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
/*libs adicionais*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
// lib para usar para converter host para ip
#include <netdb.h>



#define PORT 21
#define LENGTH 4096

//teste de filho da puta mudança
int main(void){
    //cria estrutura do tipo sockaddr_in
    struct sockaddr_in serv;

    //Cria um file descriptor para receber status do socket
    int socketFD;

    //Cria buffer para o recebimento de mensagens
    char ip[16];
    char reply_buff[LENGTH],
        recv_buff[LENGTH];

    //cria o socket e verifica se tem algum error
    socketFD=socket(AF_INET,SOCK_STREAM,0);
    if (socketFD==-1){
        perror("Error na Criação do Socket!");
        exit(1);
    } else{
        printf("Socket criado com sucesso!");
    }

    serv.sin_addr.s_addr=inet_addr(ip);
    serv.sin_family=AF_INET;
    serv.sin_port=htons(21);
    memset(serv.sin_zero,0x0,8);
    memset(recv_buff, '\0', sizeof(char)*LENGTH);
    memset(reply_buff, '\0', sizeof(char)*LENGTH);

    //nessa parte do "*)&" ele ta 'tranformando' a struct
    // de tipo sockaddr_in para sockaddr para que a struc
    //sockaddr possa ler a sockaddr_in
    if (connect(socketFD,(struct sockaddr *)&serv, sizeof(struct sockaddr)) !=0){
        perror("Erro na conexao com o servidor");
        exit(1);

    }
    recv(socketFD, recv_buff, LENGTH, 0);
    printf("%s",recv_buff);


}
