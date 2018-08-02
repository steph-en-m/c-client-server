#include "client.h"
void getCommand(char *ipAddress, char *portNumber){
char cmd[1024]={"\0"},icmd[128]={"\0"};
int ch;
int i;
     i=0;
     do
     {
     ch=getch();
     if(ch!=13){cmd[i++]=(unsigned char)ch;printf("%c",ch);}
     }
     while(ch!=13&&i<=1022);
     cmd[i]='\0';
     sscanf(cmd,"%s",icmd);
     if(strcmp(icmd,"double")==0)double_(icmd,cmd,ipAddress,portNumber);
     else if(strcmp(icmd,"delete")==0)delete_(icmd,cmd,ipAddress,portNumber);
     else if(strcmp(icmd,"replace")==0)replace_(icmd,cmd,ipAddress,portNumber);
     else if(strcmp(icmd,"reverse")==0)reverse_(icmd,cmd,ipAddress,portNumber);
     else if(strcmp(icmd,"encrypt")==0)encrypt_(icmd,cmd,ipAddress,portNumber);
     else if(strcmp(icmd,"decrypt")==0)decrypt_(icmd,cmd,ipAddress,portNumber);
     else if(strcmp(icmd,"reply")==0)reply_(icmd,cmd,ipAddress,portNumber);
     else if(strcmp(icmd,"group")==0)group_(icmd,cmd,ipAddress,portNumber);
     else if(strcmp(icmd,"clear")==0){clearScreen(80);welcome();getCommand(ipAddress,portNumber);return;}
     else if(strcmp(icmd,"exit")==0){printf("\nBye!");exit(EXIT_SUCCESS);}
     else printf("\nUnknown command!\n");
     printf(">");
     getCommand(ipAddress,portNumber);return;
}