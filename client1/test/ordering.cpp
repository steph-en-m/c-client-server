#include "test.h"
 int order();
//the ordering thread will schedule the tasks and only calls the executor thread
//when idle flag is off

unsigned long __stdcall orderProc(PVOID p){

 do{}while(Idle::Close());
 Idle::Close(1);
 do{order();}while(Idle::IsIdle());
 //Idle::Close(0);
 UNUSED(p);
 return 0;
 }

 int order(){
 MYSQL con;
 char req[1024]={"\0"};
 RQUERY rq;int i;unsigned long id,thid;

 do{}while(Db::IsCaught());
 Db::Catch();
  if(Init(&con)==0){Db::Release();Idle::Close(0);return 0;}
 sprintf(req,"select idno from pending where status=0 and ordering=1\0");
 ZeroMemory(&rq,sizeof(rq));rq.row=1;
 qselect(&con,req,"wordserver",&rq);
 if(rq.num>=1){mysql_close(&con);Db::Release();Idle::Close(0);return 0;}

 sprintf(req,"select idno from pending where status = 0 and ordering = 0 and priority = 1\0");
 ZeroMemory(&rq,sizeof(rq));rq.row=1;
 qselect(&con,req,"wordserver",&rq);
 if(rq.num>=1){
  i = rq.num<3?(rq.num-1):(rq.num%3);
  sscanf(rq.one[i],"%lu",&id);
 sprintf(req,"update pending set ordering = 1 where idno = %lu \0",id);
 if(!qupdate(&con,req,"wordserver")){mysql_close(&con);Db::Release();return 0;}

  mysql_close(&con); Db::Release();
  CreateThread(NULL,4096,execProc,NULL,0,&thid);
  return 0;
  }
 //now chk for second order priorities
 sprintf(req,"select idno from pending where status = 0 and ordering = 0 and priority = 2\0");
 ZeroMemory(&rq,sizeof(rq));rq.row=1;
 qselect(&con,req,"wordserver",&rq);
 if(rq.num>=1){
  i = rq.num<3?(rq.num-1):(rq.num%3);
  sscanf(rq.one[i],"%lu",&id);
 sprintf(req,"update pending set ordering = 1 where idno = %lu \0",id);
 if(!qupdate(&con,req,"wordserver")){mysql_close(&con);Db::Release();return 0;}
  mysql_close(&con);Db::Release();
  CreateThread(NULL,4096,execProc,NULL,0,&thid);

  return 0;

 }

 //now check for third order priorities
 sprintf(req,"select idno from pending where status = 0 and ordering = 0 and priority = 3\0");
 ZeroMemory(&rq,sizeof(rq));rq.row=1;
 qselect(&con,req,"wordserver",&rq);
 if(rq.num>=1){
  i = rq.num<3?(rq.num-1):(rq.num%3);
  sscanf(rq.one[i],"%lu",&id);
 sprintf(req,"update pending set ordering = 1 where idno = %lu \0",id);
 if(!qupdate(&con,req,"wordserver")){mysql_close(&con);Db::Release();return 0;}
 mysql_close(&con);Db::Release();
  CreateThread(NULL,4096,execProc,NULL,0,&thid);

  return 0;

 }
 mysql_close(&con);
 Db::Release();Idle::Close(0);
 return 0;
}