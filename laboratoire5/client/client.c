///////////////////////////Hiver 2020//////////////////////////////


#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{   
    int n_noyau;
    int fdPath;
    char bufferPath[256];    
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        perror("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        perror("ERROR connecting");
    bzero(buffer,256);
    int i = 0;
    while(1){
     // bzero(buffer,256);
    // while(count < n)  {
        n = read(sockfd,buffer,256);
        if (n < 0) 
            error("ERROR reading from socket");
        fdPath = open(argv[3], O_RDWR);
        if(fdPath < 0){
           perror("Erreur open file");
           exit(1);
         }
        n_noyau = write(fdPath, buffer, strlen(buffer));
      //  n_noyau = write(fdPath, bufferPath, strlen(bufferPath));
        read(fdPath, bufferPath, n_noyau);
        
       // count += n;
        if (n < 0) 
            perror("ERROR reading from socket");
        i++;
        puts(bufferPath);
      //  close(fdPath);
      //  close(sockfd);
      close(fdPath);
    }

    close(sockfd);
    return 0;
}
