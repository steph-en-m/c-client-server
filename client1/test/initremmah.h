#ifndef _INITREMMAH_H
#define _INITREMMAH_H
  /*
  this module initializes remmah class and should be declared once
  */

  #ifndef REMMAH_DLL
  #define REMMAH_INIT __declspec(dllexport)
  #else
  #define REMMAH_INIT __declspec(dllimport)
  #endif

  #ifndef REMMAH_PRINTER
  #pragma comment(lib,"libmysql.lib")//link with mysql library only if not already linked
  #endif
  #ifndef REMMAH_PRINTER
  #include <windows.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <mysql.h>
  #include "rmtencrypt.h"
  #include "rprint.h"
  #define UNREFERENCED(a) a
  #endif

  #ifdef __cplusplus
  extern "C" {
  #endif
  #pragma once
  //this module opens a mysql database connection and should be defined like so
  //call to this routine requires the reference to an existent structure bundled on the stack
  //otherwise it will fail

    REMMAH_INIT int RemmahDbStartup(MYSQL *conn_reference,char *path,char *usn,char *pswd,int port);
    REMMAH_INIT int startup(char *fpin);
  #ifdef __cplusplus
  }
  #endif
#endif