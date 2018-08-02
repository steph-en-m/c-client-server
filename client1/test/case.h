#ifndef _CASE_H
#define _CASE_H
  #ifndef REMMAH_DLL
  #define REMMAH_CASE __declspec(dllexport)
  #else
  #define REMMAH_CASE __declspec(dllimport)
  #endif
 
   #ifdef __cplusplus
   extern "C" {
   #endif
  #pragma once
  REMMAH_CASE char *CapitalizeFirstChar(char *in_char);
  REMMAH_CASE char *CapitalizeFirstChars(char *in_char);
  #ifdef __cplusplus
  }
  #endif
#endif