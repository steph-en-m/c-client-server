#ifndef _RCLASSES_H
#define _RCLASSES_H
   #ifndef REMMAH_DLL
   #define REMMAH_CLASS __declspec(dllexport)
   #else
   #define REMMAH_CLASS __declspec(dllimport)
   #endif
   #include <windows.h>
   #ifdef __cplusplus
   extern "C" {
   #endif
   #pragma once
   //constants used by the remmah class resource file

   REMMAH_CLASS HWND RemmahClass(UINT ptrhMenu,UINT ico,UINT bg,LRESULT CALLBACK(*)(HWND ,UINT,WPARAM,LPARAM),HINSTANCE);
   REMMAH_CLASS int getDimensionX(int dlgdimension,int windimension,int factor);
   REMMAH_CLASS int getDimensionY(int dlgdimension,int windimension,int factor);
   REMMAH_CLASS void ChangeTxtColor(HDC *hdc,int red,int green,int blue,unsigned long mode);
    //this routine is used to display all image formats
   void showPhoto(HDC hdc,WCHAR *filename,int x,int y,int ix,int iy);
   #ifdef __cplusplus
   }
   #endif
#endif