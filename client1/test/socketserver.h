#ifndef _SOCKETSERVER_H
#define _SOCKETSERVER_H
     #define PORT 4050
     class myServer{
      static BOOL status;
      public:
      static void SetStatus(BOOL e);
      static BOOL GetStartup();
     };
     extern void server(void);
#endif