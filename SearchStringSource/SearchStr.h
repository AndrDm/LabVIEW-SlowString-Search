// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the SEARCHSTR_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// SEARCHSTR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SEARCHSTR_EXPORTS
#define SEARCHSTR_API  extern "C" __declspec(dllexport)
#else
#define SEARCHSTR_API __declspec(dllimport)
#endif
#include "stringzilla.h"


// This is an example of an exported function.
SEARCHSTR_API int32_t fnSearchStrAVX512(LStrHandle str, LStrHandle pattern);
SEARCHSTR_API int32_t fnSearchStrAVX2(LStrHandle str, LStrHandle pattern);