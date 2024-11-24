#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
  perror(msg);
  exit(1);
}

int main(int argc, char * argv[])
{
  if(argc < 2)
  {
    fprintf(stderr,"Port No. not provided. Program terminated \n");
    exit(1);
  }

  int sockfd, newsockfd, portno, n;
  char buffer[255];

  struct sockaddr_in serv_addr, cli_addr;
  socklen_t clilen;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if(sockfd < 0)
  {
    error("Error opening socket.");
  }

  bzero((char *) &serv_addr , sizeof(serv_addr));
  
  portno = atoi(argv[1]);

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if(bind(sockfd, (struct sockaddr *) & serv_addr, sizeof(serv_addr)) < 0){
  error("Binding failed.");
  }

  listen(sockfd, 5);
  clilen = sizeof(cli_addr);

  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

  if(newsockfd < 0)
    error("Erorr on Accept");

 FILE *fp;
 int ch = 0;
 fp = fopen("file_server.txt","w");
 int words;

 read(newsockfd, &words, sizeof(int));

 while(ch != words)
 {
  read(newsockfd, buffer, 255);
  fprintf(fp, "%s ", buffer);
  ch++;
 }

 printf("The file has been received successfully. It is saved by the name file_server.txt.");
  
 
  close(newsockfd);
  close(sockfd);

  return 0;
}
