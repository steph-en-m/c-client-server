#ifndef _TEST_H
#define _TEST_H
   //will include all libraries and their header files
   #define WIN32_LEAN_AND_MEAN 1
   #define REMMAH_DLL 1
   #pragma comment(lib,"ws2_32.lib")
   #pragma comment(lib,"remmahclass.lib")

   #include <windows.h>
   #include <stdio.h>
   #include <conio.h>
   #include <winsock2.h>
   #include <stdlib.h>
   #include <mysql.h>
   #include <case.h>
   #include <initremmah.h>
   #include <rclasses.h>
   #include <rmtencrypt.h>
   #include <rprint.h>
   #include <validator.h>
   
   //start including my custom headers
   #include "myerror.h"
   #include "idle.h"
   #include "dbprotect.h"
   #include "socketserver.h"
   #include "commands.h"
#endif