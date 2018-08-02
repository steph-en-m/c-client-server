#ifndef _IDLE_H
#define _IDLE_H
      class Idle{
       static BOOL idle,close,busy;
       public:
       static void SetIdle(BOOL e);
       static BOOL IsIdle(void);
       static void Close(BOOL e);
       static BOOL Close(void);
       static void Busy(BOOL e);
       static BOOL Busy(void);
      };
#endif