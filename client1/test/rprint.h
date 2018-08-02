#ifndef _RPRINT_H
#define _RPRINT_H
 /*
 Hill Side Solutions Limited - Custom Remmah Print Library
 Part of the Remmah Software packages.
 For Redistribution of this library please check with orders department.
 Officially written by: Nassanga Kabejja Remmah, Lule Moses, and Nalwoga Liz
 */

 /*
  the following declarations specify an export and import for print functions
 */

 #ifndef REMMAH_DLL
 #define REMMAH_PRINT __declspec(dllexport)
 #else
 #define REMMAH_PRINT __declspec(dllimport)
 #endif

 /*libraries depended on by Rprint library*/
 #pragma once
 #ifndef REMMAH_DLL
 #pragma comment(lib,"libmysql.lib")//link with mysql library
 #endif
 /*this header is only included when the dll is exporting*/
 #ifndef REMMAH_DLL
 #include <windows.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <stddef.h>
 #include <mysql.h>
 #include "rmtencrypt.h"
 #define REMMAH_PRINTER 1 //to disable redeclaration of mysql.h
 #include "initRemmah.h"
 #include "case.h"
 #define WM_RODDIALOG WM_USER + 1//this value only used in dll exports
 #endif
 #define WM_RODSOCKET WM_USER+2
 #ifdef __cplusplus
 extern "C" {
 #endif

 /*this structure is used by the select query routines*/

 typedef struct tagrQuery{
  int num;//the number of records returned,cant exceed 100
  int row;//value must be set when calling respective function
  /*field data, not exceeding seventeen fields*/

      char one[100][128];
      char two[100][128];
      char thr[100][128];
      char fou[100][128];
      char fiv[100][128];
      char six[100][128];
      char sev[100][128];
      char eig[100][128];
      char nin[100][128];
      char ten[100][128];
      char ele[100][128];
      char twe[100][128];
      char thi[100][128];
      char fot[100][128];
      char fif[100][128];
      char sit[100][128];
      char set[100][128];
 }RQUERY,*PTRQUERY;

 typedef struct tagDecrypt{
  int error;
  char out[1024];
 }DST,*PTRDST;

 //routines for sending warning / response message

 REMMAH_PRINT void warn(HWND _parent_window,const char * msg_to_echo);
 REMMAH_PRINT unsigned int pwarn(HWND _parent_window,const char * quest_msg_to_user);

 //routines for sending sql queries to server

 REMMAH_PRINT void qselect(MYSQL *conn,char * request,char *database,PTRQUERY qStructure);
 //REMMAH_PRINT void qselect(SOCKET *conn,char * request,char *database,PTRQUERY qStructure,HWND parent_container);
 REMMAH_PRINT void qselectEx(SOCKET *conn,char * request,char *database,PTRQUERY qStructure,HWND parent_container);
 REMMAH_PRINT void batchSend(SOCKET *conn,char * request,PTRQUERY qStructure,HWND parent_Container);
 REMMAH_PRINT int qupdate(MYSQL *conn,char * request,char *database);
 REMMAH_PRINT int qdelete(MYSQL *conn,char * request,char *database);
 REMMAH_PRINT unsigned long qinsert(MYSQL *conn,char * request,char *database);
 //REMMAH_PRINT int qupdate(SOCKET *conn,char * request,char *database,HWND parent_container);
 //REMMAH_PRINT int qdelete(SOCKET *conn,char * request,char *database,HWND parent_container);
 //REMMAH_PRINT unsigned long qinsert(SOCKET *conn,char * request,char *database,HWND parent_container);
 REMMAH_PRINT int OpenSocket(SOCKET *s,short port,int *loader);
 REMMAH_PRINT void RemmahSend(SOCKET sfd,char *fname);

 //this decrypt is an added feature as at may ptcsystem development
 REMMAH_PRINT void decrypt(char *in,struct tagDecrypt *st);
 REMMAH_PRINT void delay(unsigned int seconds);
 REMMAH_PRINT void RemmahSendOrdered(SOCKET sfd,PTRQUERY rq);
 REMMAH_PRINT void RemmahReadOrdered(PTRQUERY rq,char *fname);
 REMMAH_PRINT char* RemmahClean(char *fname);

 unsigned long __stdcall openI(PVOID params);
 unsigned long __stdcall openD(PVOID params);
 unsigned long __stdcall openU(PVOID params);
 unsigned long __stdcall openS(PVOID params);
 #ifdef __cplusplus
 }
 #endif
#endif