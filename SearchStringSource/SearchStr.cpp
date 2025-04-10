// SearchStr.cpp : Defines the exported functions for the DLL.
//
#pragma warning( disable : 4068)// GCC

// canot use both at the same time and share both functions in same DLL
#define USE_AVX2 1
// #define USE_AVX512 1
#ifdef USE_AVX2
#define SZ_USE_X86_AVX2 1
#endif
#ifdef USE_AVX512
#define SZ_USE_X86_AVX512 1
#endif


#include <inttypes.h>
#include "C:\Program Files\National Instruments\LabVIEW 2025\cintools\extcode.h"
#include "stringzilla.h"
#include "framework.h"
#include "SearchStr.h"

#define GUARD(s, p) if (!s || !p) return -1; \
              if (!(*s)->str || !(*p)->str || !(*s)->cnt) return -1; \
              if (!(*p)->cnt) return 0;

#ifdef USE_AVX2
SEARCHSTR_API int32_t fnSearchStrAVX2(LStrHandle str, LStrHandle pattern)
{
    GUARD(str, pattern)
    // Initialize your haystack and needle
    sz_string_view_t haystack = { (sz_cptr_t)((*str)->str), (sz_size_t)(*str)->cnt };
    sz_string_view_t needle = { (sz_cptr_t)((*pattern)->str), (sz_size_t)(*pattern)->cnt };
    
    sz_cptr_t substring_position = sz_find_avx2(haystack.start, haystack.length, needle.start, needle.length);
    sz_find_t* res = (sz_find_t*)substring_position;
    int64_t offset = (substring_position - haystack.start);

    if (substring_position) return (int32_t)offset;
    else return -1;
}
#endif

#ifdef USE_AVX512
SEARCHSTR_API int32_t fnSearchStrAVX512(LStrHandle str, LStrHandle pattern)
{
    GUARD(str, pattern)
    sz_string_view_t haystack = { (sz_cptr_t)((*str)->str), (sz_size_t)(*str)->cnt };
    sz_string_view_t needle = { (sz_cptr_t)((*pattern)->str), (sz_size_t)(*pattern)->cnt };

    sz_cptr_t substring_position = sz_find_avx512(haystack.start, haystack.length, needle.start, needle.length);
    sz_find_t* res = (sz_find_t*)substring_position;
    int64_t offset = (substring_position - haystack.start);

    if (substring_position) return (int32_t)offset;
    else return -1;
}
#endif