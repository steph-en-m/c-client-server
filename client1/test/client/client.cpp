#include "client.h"
 int main(int argc, char **argv){

 clearScreen(80);
 if(argc!=3){
 printf("error: invalid command syntax!\n Expected: progname xxx.xxx.xxx.xxx xxxx or progname www.xxx.xxx xxxx\n");
 return 0;
 }

 welcome();
 getCommand(argv[1],argv[2]);

 return 0;
 }