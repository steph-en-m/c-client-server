#ifndef _VALIDATORS_H
#define _VALIDATORS_H
     /*section that defines the use dll export or import
     */
     #ifndef REMMAH_DLL
     #define REMMAH_VAL __declspec(dllexport)
     #else
     #define REMMAH_VAL __declspec(dllimport)
     #endif
      #ifdef __cplusplus
      extern "C" {
      #endif
     #pragma once
     REMMAH_VAL int ValidateName(char *in_name);
     REMMAH_VAL int ValidateUserName(char *in_name);
     REMMAH_VAL int ValidateNameEx(char *in_name);
     REMMAH_VAL int ValidateMail(char *in_mail);
     REMMAH_VAL int ValidateURL(char *in_url);
     REMMAH_VAL int ValidateNIN(char *in_NIN);
     REMMAH_VAL int ValidateMobile(char *in_mobile);
     REMMAH_VAL int ValidateDOB(char *in_DOB);
     REMMAH_VAL int ValidateCurrency(char *in_currency_ug_shs);
     REMMAH_VAL char *addCommas(char *in_char);//returns NULL if comma cannot be added
     REMMAH_VAL char *removeCommas(char *in_char);
     #ifdef __cplusplus
     }
     #endif
#endif