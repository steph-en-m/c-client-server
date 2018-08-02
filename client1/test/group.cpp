#include "test.h"

void group_(char *buf,SOCKET st){
  int i,z,s,ilen,loop,type,error,priority,numCmd;
  unsigned long id,thid; DST dst;
  char req[1024]={"\0"},szReply[1024]={"\0"},nbuf[1024]={"\0"},pcmd[64]={"\0"},cmd[64]={"\0"},capture[1024]={"\0"},
  waste[64]={"\0"};
  FILE *fp;MYSQL con;
   z=0;
	for(i=6;i<(int)strlen(buf);i++)nbuf[z++]=buf[i];nbuf[z]='\0';

   sscanf(nbuf,"%s",cmd);
   if(cmd[2]!='=')goto error;
   cmd[2]=' ';
   sscanf(cmd,"%s%d",waste,&numCmd);
   ilen = strlen(cmd);
   if(nbuf[ilen]==' '&&nbuf[ilen+1]=='-'&&nbuf[ilen+2]=='c'&&nbuf[ilen+3]==' '){
    ilen = ilen + 4;
    fp = fopen("reply.txt","w");
    if(fp==NULL)goto error;
    for(loop = 0; loop <numCmd;loop++){
     s=0;
     sprintf(capture,"c\0");
     for(i=ilen;i<(int)strlen(nbuf);i++){
      if((nbuf[i]==' '&&nbuf[i+1]=='-')||i==(int)(strlen(nbuf)-1)){
       if(nbuf[i]==' ')capture[s]='\0';
       else{
        capture[s++]=nbuf[i];capture[s]='\0';
       }
       //continue
       sscanf(capture,"%s",pcmd);
       error = 0;
       //... to be continued
       if(!strcmp(pcmd,"double"))type =  5;
    else if(!strcmp(pcmd,"reverse"))type = 4;
    else if(!strcmp(pcmd,"replace"))type = 0;
    else if(!strcmp(pcmd,"delete"))type = 1;
    else if(!strcmp(pcmd,"encrypt"))type = 2;
    else if(!strcmp(pcmd,"decrypt"))type = 3;
    else {printf("\nserver: got unknown command: %s\n",pcmd);fprintf(fp,"unknown Command: %s\r\n",pcmd);error=1;}

    if(error)break;
    else{//   if(!error){
     priority = type - 3;
     if(priority<=0){
      priority = -1*priority;
      if(priority==0)priority = 1;
      else if(priority>=4)priority = priority - 3;
      }

    //now do the submission to database
    ZeroMemory(&dst,sizeof(dst));
    getBody((int)strlen(pcmd),capture,&dst);
    sprintf(req,"insert into pending set timepost = %u,typeOfTask=%d,priority=%d,status=0,body=\'%s\'\0",
    (unsigned)time(NULL),type,priority,dst.out);
    do{}while(Db::IsCaught());
    Db::Catch();
    if(Init(&con)==0){Db::Release();break;}
    if(mysql_select_db(&con,"wordserver")!=0){fprintf(fp,"Internal server failure\r\n");mysql_close(&con);Db::Release();}
    else{//3
     if(mysql_real_query(&con,req,(int)strlen(req))!=0){fprintf(fp,"%s\r\n",mysql_error(&con));mysql_close(&con);Db::Release();}
     else{ //2
       id = (unsigned long)mysql_insert_id(&con);
       if(id==0){fprintf(fp,"could not schedule your job\r\n");mysql_close(&con);Db::Release();}
       else{//1
        fprintf(fp,"use: reply %lu to get progress info\r\n",id);
        mysql_close(&con);
        Db::Release();
        break;
        }//1
       }//2
       } //3
       }

      }
      else capture[s++]=nbuf[i];
     }
     //after the inner loop
     ilen = ilen + s;
     if(ilen<(int)(strlen(nbuf)-4)){
      if(nbuf[ilen]==' '&&nbuf[ilen+1]=='-'&&nbuf[ilen+2]=='c'&&nbuf[ilen+3]==' ')ilen = ilen +4;

      else break;
     }
     else break;
    }
   fclose(fp);
   }
   else goto error;
   //out very first if stt

    fp= fopen("reply.txt","r");
    if(fp==NULL)goto error;
    fread(szReply,1,sizeof(szReply),fp);
    fclose(fp);
    send(st,szReply,(int)strlen(szReply),0);
    shutdown(st,SD_SEND);
   //after sending reply to client call order procedure
   if(Idle::Close()==FALSE)
   CreateThread(NULL,4096,orderProc,NULL,0,&thid);
   return;
   error:
   send(st,"Error! Improper use of group command.",(int)strlen("Error! Improper use of group command."),0);
   shutdown(st,SD_SEND);
   return;
}

