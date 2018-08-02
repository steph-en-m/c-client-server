#include "test.h"

void reply_(char *buf,SOCKET s){
  char waste[1024]={"\0"},req[1024]={"\0"},body[1024]={"\0"},ans[1024]={"\0"},bff[1024]={"\0"};
  unsigned long id; RQUERY rq;MYSQL con;
  MYSQL_RES *res;MYSQL_ROW row;
  int status,type;
  unsigned long timein,fintime;
  printf("\nPreparing to reply user:");

  sscanf(buf,"%s%lu",waste,&id);
  do{}while(Db::IsCaught());
  Db::Catch();
  if(Init(&con)==0){send(s,"",(int)strlen(""),0);shutdown(s,SD_SEND);Db::Release();return;}
  printf("\nHas acquired database connection:");
  //first check to see whether the task is in execution
  sprintf(req,"select idno from busy where taskid=%lu\0",id);
  ZeroMemory(&rq,sizeof(rq));rq.row=1;
  qselect(&con,req,"wordserver",&rq);
  if(rq.num>=1){
   sprintf(req,"Reply: Task %lu is still executing...\0",id);
   send(s,req,(int)strlen(req),0);shutdown(s,SD_SEND);
   mysql_close(&con);
   Db::Release();
   return;
  }
  //now select from ready jobs if command is successful
  sprintf(req,"select status,timecomplete,output from ready where taskid=%lu\0",id);
  if(mysql_select_db(&con,"wordserver")==0){
   if(mysql_real_query(&con,req,(int)strlen(req))==0){
    res = mysql_store_result(&con);
    if(res!=NULL){
     row = mysql_fetch_row(res);
     if(row!=NULL){
      sscanf(row[0],"%d",&status);
      sscanf(row[1],"%lu",&fintime);
      sprintf(ans,"%s\0",row[2]);
      mysql_free_result(res);
      //now get other particulars
      sprintf(req,"select typeOfTask,timepost,body from pending where idno=%lu\0",id);
      if(mysql_real_query(&con,req,(int)strlen(req))==0){
       res = mysql_store_result(&con);
       if(res!=NULL){
        row = mysql_fetch_row(res);
        if(row!=NULL){
          sscanf(row[0],"%d",&type);
          sscanf(row[1],"%lu",&timein);
          sprintf(body,"%s\0",row[2]);
          mysql_free_result(res);
          sprintf(bff,"Server Respose:\nJob: %s %s %s\nResult: %s\nTime spent on job: %d seconds\0",
          type==0?"replace":(type==1?"delete":(type==2?"encrypt":(type==3?"decrypt":(type==4?"reverse":"double")))),
          body,status==0?"Failed":(status==1?"Successful":"rejected"),ans,fintime - timein);
          send(s,bff,(int)strlen(bff),0);
          shutdown(s,SD_SEND);
          mysql_close(&con);
          Db::Release();
          return;
        }
        else mysql_free_result(res);
       }
      }
     }
     else mysql_free_result(res);
    }
   }
  }
  //now check to see if job is still waiting
  sprintf(req,"select status from pending where idno=%lu\0",id);
  ZeroMemory(&rq,sizeof(rq));rq.row = 1;
  qselect(&con,req,"wordserver",&rq);
  if(rq.num<=0)send(s,"Response unknown...",(int)strlen("Response unknown..."),0);
  else{
   sscanf(rq.one[0],"%d",&status);
   sprintf(req,"Reply: Task %lu status: %s\0",id,status==0?"waiting for scheduler":(status==1?"Running":"Finished Execution, but does not know why misses in ready jobs"));
   send(s,req,(int)strlen(req),0);
  }
  shutdown(s,SD_SEND);
  mysql_close(&con);
  Db::Release();
}