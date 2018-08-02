#ifndef _DBPROTECT_H
#define _DBPROTECT_H
      class Db{
      static BOOL db;
      public:
      static BOOL IsCaught(void);
      static void Catch(void);
      static void Release(void);
      };
#endif