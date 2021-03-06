#include "test.h"
int execute(void);
/*
  when the executor is called, it will pick any task for which ordering flag is
  set and status flag is off. during execution, the task is put in the busy table.
  after execution the job is put in the ready table for dispatch.

*/

unsigned long __stdcall execProc(PVOID p){
 do{
 execute();
 }
 while(Idle::IsIdle());
 UNUSED(p);
 return 0;
}

int execute(void){
 char req[1024]={"\0"},reply[1024]={"\0"},body[512]={"\0"};
 unsigned long id,idbusy; MYSQL_RES *res;MYSQL_ROW row;
 int status,type;FILE *fp;
 MYSQL con;

do{}while(Idle::Busy());
 Idle::Busy(1);
 do{}while(Db::IsCaught());
 Db::Catch();
 if(Init(&con)==0){Db::Release();Idle::Busy(0);mysql_close(&con);return 0;}
 sprintf(req,"select idno,typeOfTask,body from pending where status = 0 and ordering = 1 limit 1\0");
 if(mysql_select_db(&con,"wordserver")!=0){Db::Release();Idle::Busy(0);mysql_close(&con);return 0;}
 if(mysql_real_query(&con,req,(int)strlen(req))!=0){Db::Release();Idle::Busy(0);mysql_close(&con);return 0;}
 res = mysql_store_result(&con);
 if(res == NULL){Db::Release();Idle::Busy(0);mysql_close(&con);return 0;}
 row = mysql_fetch_row(res);
 if(row == NULL){mysql_free_result(res);Db::Release();Idle::Busy(0);mysql_close(&con);return 0;}
 sscanf(row[0],"%lu",&id);
 sscanf(row[1],"%d",&type);
 sprintf(body,"%s\0",row[2]);
 mysql_free_result(res);
 sprintf(req,"update pending set status = 1 where idno = %lu\0",id);
 qupdate(&con,req,"wordserver");
 sprintf(req,"insert into busy set taskid = %lu\0",id);
 idbusy = qinsert(&con,req,"wordserver");
 switch(type){
  case 0:sprintf(reply,"%s\0",replace_(body,&status));break;
  case 1:sprintf(reply,"%s\0",delete_(body,&status));break;
  case 2:sprintf(reply,"%s\0",encrypt_(body,&status));break;
  case 3:sprintf(reply,"%s\0",decrypt_(body,&status));break;
  case 4:sprintf(reply,"%s\0",reverse_(body,&status));break;
  case 5:sprintf(reply,"%s\0",double_(body,&status));break;
  }
 //first delete task from busy table
  sprintf(req,"delete busy.* from busy where idno=%lu\0",idbusy);
  qdelete(&con,req,"wordserver");
 //update task staus to terminated
  sprintf(req,"update pending set status = 2 where idno = %lu\0",id);
  qupdate(&con,req,"wordserver");
 //insert the task in the ready jobs table together with the reply codes
 sprintf(req,"insert into ready set taskid=%lu,status=%d,timecomplete=%lu,output=\'%s\'\0",
 id,status,(unsigned)time(NULL),reply);
 qinsert(&con,req,"wordserver");
 fp = fopen("ready.dat","w");
 if(fp!=NULL)fprintf(fp,"%s\n",req);
 if(fp!=NULL)fclose(fp);
 Idle::Busy(0);Db::Release();mysql_close(&con);
 return 0;
}