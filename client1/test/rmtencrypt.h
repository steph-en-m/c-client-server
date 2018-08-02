#ifndef _RMTENCRYPT_H
#define _RMTENCRYPT_H

/*
this section determines whether you need to import or export a function
one is entitled to define the REMMAH_DLL constant across all headers
that ship with Hill Side Solutions Limited
*/

#ifndef REMMAH_DLL
#define REMMAH_RMTE __declspec(dllexport)
#else
#define REMMAH_RMTE __declspec(dllimport)
#endif

/*
this section determines the use cplusplus code for prevention of name
mangling
*/

#ifdef __cplusplus
extern "C" {
#endif
 
  REMMAH_RMTE unsigned char decode(const char *);
  REMMAH_RMTE unsigned char decode1(const char *);
  REMMAH_RMTE unsigned char decode2(const char *);
  REMMAH_RMTE unsigned char decode3(const char *);

  REMMAH_RMTE const char *encode(unsigned char);
  REMMAH_RMTE const char *encode1(int);
  REMMAH_RMTE const char *encode2(int);
  REMMAH_RMTE const char *encode3(int);
  /*
  the first argument is the string to be decrypted
  the second argument is the string that has been decrypted
  ensure that out is a valid buffer otherwise you will get access violation
  write of address 0x0.
  */
  #ifdef _MSVCPP
  REMMAH_RMTE void decryptc(char *in,char **out);
  #else
  REMMAH_RMTE void decryptc(char *in,char *out);
  #endif
  //works like above, but instead extracts an integer
  REMMAH_RMTE void decrypti(char *in,int *out);
  REMMAH_RMTE void encrypt(char *in,char **out,int *status);
  //you must make sure out is big enough to handle the string
  
#ifdef __cplusplus
}
#endif



#endif
/*
this is the end of the rmtencrypt.h header file
*/
 