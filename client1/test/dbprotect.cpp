#include "test.h"

BOOL Db::db = FALSE;

BOOL Db::IsCaught(void){
 return db;
}

void Db::Catch(void){
 db = !db;
}

void Db::Release(void){
 Catch();
}