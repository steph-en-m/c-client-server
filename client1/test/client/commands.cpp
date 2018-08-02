#include "client.h"

void double_(char *icmd, char *cmd, char *ipAddress, char *portNumber){
      int i;
      int j=0;
      char buff[512] = {"\0"},out[1024];
      for(i=(int)strlen(icmd)+1;i<(int)strlen(cmd);i++)buff[j++]=cmd[i];
      buff[j]='\0';
      if((int)strlen(buff)>=51){printf("\nError: command argument greater than 50 characters\n");
      return; }
      //call function to open socket
      sprintf(out,"%s %s\0",icmd,buff);
      printf("\nPreparing to send: %s\n",out);
      openSocket(ipAddress, portNumber,out);
      return;

}

//Define Function openSocket
void openSocket(char *ipAddress, char *portNumber, char *cmd){
WSADATA wsa;char buff[1024]={"\0"};
//int WSAstartup;
struct sockaddr_in server;
struct in_addr addr;
struct hostent *host;
SOCKET s;
int port;
sscanf(portNumber,"%d",&port);
if(WSAStartup(MAKEWORD(2,0),&wsa)!=0)
{
printf("\nError:initializing data failed\n");return ;}
s = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
if(s==INVALID_SOCKET){
printf("\nError: creating socket descriptor failed\n");
WSACleanup();
return ;
}
server.sin_family = AF_INET;
server.sin_port = htons((short)port);
host = gethostbyname(ipAddress);
if(host==NULL)
{WSACleanup();
printf("\nError: resolving host name failed\n");
return ;
}
addr.s_addr =*(u_long *) host -> h_addr_list[0];
server.sin_addr.s_addr = inet_addr(inet_ntoa(addr));
//call function connect
if(connect(s,(struct sockaddr *) &server, sizeof(server))==SOCKET_ERROR)
{
WSACleanup();
printf("\nError: connection failed\n");
return ;
}
//start now reading data
send(s, cmd, (int)strlen(cmd), 0);
shutdown(s, SD_SEND);

//now recieve data

printf("\nWaiting for server reply.....\n");
recv(s,buff,sizeof(buff),0);
shutdown(s,SD_RECEIVE);
closesocket(s);
WSACleanup();
printf("\nServer response: %s \n\n", buff);
return ;
 }

void delete_(char *icmd, char *cmd, char *ipAddress, char *portNumber){
      int i;
      int j=0;
      char buff[512] = {"\0"},out[1024];
      for(i=(int)strlen(icmd)+1;i<(int)strlen(cmd);i++)buff[j++]=cmd[i];
      buff[j]='\0';
      if((int)strlen(buff)>=51){printf("\nError: command argument greater than 50 characters\n");
      return; }
      //call function to open socket
      sprintf(out,"%s %s\0",icmd,buff);
      printf("\nPreparing to send: %s\n",out);
      openSocket(ipAddress, portNumber,out);
      return;

}

void replace_(char *icmd, char *cmd, char *ipAddress, char *portNumber){
      int i;
      int j=0;
      char buff[512] = {"\0"},out[1024];
      for(i=(int)strlen(icmd)+1;i<(int)strlen(cmd);i++)buff[j++]=cmd[i];
      buff[j]='\0';
      if((int)strlen(buff)>=51){printf("\nError: command argument greater than 50 characters\n");
      return; }
      //call function to open socket
      sprintf(out,"%s %s\0",icmd,buff);
      printf("\nPreparing to send: %s\n",out);
      openSocket(ipAddress, portNumber,out);
      return;

}

void reverse_(char *icmd, char *cmd, char *ipAddress, char *portNumber){
      int i;
      int j=0;
      char buff[512] = {"\0"},out[1024];
      for(i=(int)strlen(icmd)+1;i<(int)strlen(cmd);i++)buff[j++]=cmd[i];
      buff[j]='\0';
      if((int)strlen(buff)>=51){printf("\nError: command argument greater than 50 characters\n");
      return; }
      //call function to open socket
      sprintf(out,"%s %s\0",icmd,buff);
      printf("\nPreparing to send: %s\n",out);
      openSocket(ipAddress, portNumber,out);
      return;

}

void encrypt_(char *icmd, char *cmd, char *ipAddress, char *portNumber){
      int i;
      int j=0;
      char buff[512] = {"\0"},out[1024];
      for(i=(int)strlen(icmd)+1;i<(int)strlen(cmd);i++)buff[j++]=cmd[i];
      buff[j]='\0';
      if((int)strlen(buff)>=51){printf("\nError: command argument greater than 50 characters\n");
      return; }
      //call function to open socket
      sprintf(out,"%s %s\0",icmd,buff);
      printf("\nPreparing to send: %s\n",out);
      openSocket(ipAddress, portNumber,out);
      return;

}

void decrypt_(char *icmd, char *cmd, char *ipAddress, char *portNumber){
      int i;
      int j=0;
      char buff[512] = {"\0"},out[1024];
      for(i=(int)strlen(icmd)+1;i<(int)strlen(cmd);i++)buff[j++]=cmd[i];
      buff[j]='\0';
      if((int)strlen(buff)>=51){printf("\nError: command argument greater than 50 characters\n");
      return; }
      //call function to open socket
      sprintf(out,"%s %s\0",icmd,buff);
      printf("\nPreparing to send: %s\n",out);
      openSocket(ipAddress, portNumber,out);
      return;

}

void reply_(char *icmd, char *cmd, char *ipAddress, char *portNumber){
      int i;
      int j=0;
      char buff[512] = {"\0"},out[1024];
      for(i=(int)strlen(icmd)+1;i<(int)strlen(cmd);i++)buff[j++]=cmd[i];
      buff[j]='\0';
      if((int)strlen(buff)>=51){printf("\nError: command argument greater than 50 characters\n");
      return; }
      //call function to open socket
      sprintf(out,"%s %s\0",icmd,buff);
      printf("\nPreparing to send: %s\n",out);
      openSocket(ipAddress, portNumber,out);
      return;

}


void group_(char *icmd, char *cmd, char *ipAddress, char *portNumber){
      int i;
      int j=0;
      char buff[512] = {"\0"},out[1024];
      for(i=(int)strlen(icmd)+1;i<(int)strlen(cmd);i++)buff[j++]=cmd[i];
      buff[j]='\0';
      if((int)strlen(buff)>=51){printf("\nError: command argument greater than 50 characters\n");
      return; }
      //call function to open socket
      sprintf(out,"%s %s\0",icmd,buff);
      printf("\nPreparing to send: %s\n",out);
      openSocket(ipAddress, portNumber,out);
      return;

}

