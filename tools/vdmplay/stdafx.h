#ifndef __STDAFX_H__
#define __STDAFX_H__
#pragma once

#pragma warning (disable : 4201)

#define WIN32_LEAN_AND_MEAN
#if !defined(NOSTRICT) && !defined(STRICT)
#define STRICT
#endif
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <afxwin.h> // used to be windows.h
#undef STRICT
#ifndef CONST
#define CONST const
#endif 
#define IN
#define OUT
#define INOUT

#ifndef WIN32
# define USHORT unsigned short
# define APIENTRY FAR PASCAL __export
# define GWL_USERDATA 0
# define MAKEWORD(a, b)   ((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))
#endif


#if 0
#include <mmsystem.h>
#include <nb30.h>
#include <afx.h>
#include <afxcoll.h>
#endif 

//#include <generic.h> // generic.h is OLD. DO NOT USE

#ifndef ASSERT
#include <assert.h>
#define ASSERT assert 
#endif

#include "tdlog.h"
#include "vdmplay.h"
#include "vplist.h"
#include "vpnet.h"

#ifdef WIN32
#define _fmemcpy memcpy
#endif 

#include "winsock.h"

//////////////////////
// generic.h stuff
//////////////////////

#define name2(a, b) _rwname2(a,b) /* to force the args to be evaluated here */
#define _rwname2(a, b) a##b
#define name3(a, b, c) _rwname3(a,b,c)
#define _rwname3(a, b, c) a##b##c
#define name4(a, b, c, d) _rwname4(a,b,c,d)
#define _rwname4(a, b, c, d) a##b##c##d

#define declare(Class, type)     name2(Class,declare)(type)
#define implement(Class, type)   name2(Class,implement)(type)
#define declare2(a, type1, type2)  a##declare2(type1,type2)
#define implement2(a, type1, type2) a##implement2(type1,type2)

#define callerror(Class, type, iarg, csarg) \
           (*errorhandler(Class,type))(iarg,csarg)
#define set_handler(Class, type, hrt) name4(set_,type,Class,_handler)(hrt)
#define errorhandler(Class, type) name3(type,Class,handler)

#pragma warning (disable : 4704)

#ifndef AFX_API_EXPORT
#define AFX_API_EXPORT  __declspec (dllexport)
#endif

#endif
          
