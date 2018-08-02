#ifndef _MYCLIENT_H
#define _MYCLIENT_H
extern void welcome(void);
extern void getCommand(char *ipAddress, char *portNumber);
extern void double_(char *icmd, char *cmd, char *ipAddress, char *portNumber);
extern void group_(char *icmd, char *cmd, char *ipAddress, char *portNumber);
extern void delete_(char *icmd, char *cmd, char *ipAddress, char *portNumber);
extern void replace_(char *icmd, char *cmd, char *ipAddress, char *portNumber);
extern void reverse_(char *icmd, char *cmd, char *ipAddress, char *portNumber);
extern void encrypt_(char *icmd, char *cmd, char *ipAddress, char *portNumber);
extern void decrypt_(char *icmd, char *cmd, char *ipAddress, char *portNumber);
extern void reply_(char *icmd, char *cmd, char *ipAddress, char *portNumber);
extern void openSocket(char *ipAddess, char *portNumber,char * cmd);
#endif