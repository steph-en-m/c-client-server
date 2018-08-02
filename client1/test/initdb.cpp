#include "test.h"

//init database

int Init(MYSQL *con){

 mysql_init(con);
 if(con==NULL)return 0;
 if(mysql_real_connect(con,"127.0.0.1","root","hassan",NULL,3306,NULL,NULL)==NULL)return 0;
 return 1;
}