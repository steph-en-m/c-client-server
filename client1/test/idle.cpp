#include "test.h"

BOOL Idle::idle = FALSE,Idle::close=FALSE,Idle::busy=FALSE;

void Idle::SetIdle(BOOL x){
 idle = x;
 return;
}

BOOL Idle::IsIdle(void){
 return idle;
}

void Idle::Close(BOOL e){
 close = e;
 return;
}

BOOL Idle::Close(void){
 return close;
}

void Idle::Busy(BOOL e){
 busy = e;
 return;
}

BOOL Idle::Busy(void){
 return busy;
}