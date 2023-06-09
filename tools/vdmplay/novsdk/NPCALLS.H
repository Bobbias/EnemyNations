/*****************************************************************************
 *
 * Filename:	  npcalls.h
 *
 * COPYRIGHT (c) 1987, 1988, 1989 by Novell, Inc.  All Rights Reserved.
 *
 ****************************************************************************/

#define NPCALLS_INCLUDED

#ifndef BYTE
#define BYTE unsigned char
#endif

#ifndef WORD
#define WORD unsigned int
#endif

#ifndef DWORD
#define DWORD unsigned long
#endif

#ifndef NULL
#if (!defined(M_I86CM) && !defined(M_I86LM))
#define  NULL    0
#else
#define  NULL    0L
#endif
#endif

#ifndef TRUE
#define TRUE	1
#endif

#ifndef FALSE
#define FALSE	0
#endif


/****************************************************************************/
/* Error Codes for NPGetFirstNmPipeServer, NPGetNextNmPipeServer */
#define	GET_NEXT_WITHOUT_GET_FIRST	0xB001
#define	INVALID_SEARCH_HANDLE		0xB002
#define  NPDAEMON_NOT_LOADED			0xB003
#define	END_OF_SERVERS					0xFFFF


/****************************************************************************/
/* Stuctures used in the NPGetServer calls */
typedef	struct
{
 	char		serverBuf[16];
	WORD		searchHandle;
	WORD		searchCount;
} NP_FIND_SERVER;


/****************************************************************************/
/* Routines in the NPCALLS module */
	 	
WORD	far pascal NPGetComputerName(
		char far *);						/* Named Pipe Server Name */


WORD	far pascal NPGetFirstNmPipeServer(
		NP_FIND_SERVER	far *fndfrst); 		/* Buffer to hold server name */



WORD	far pascal NPGetNextNmPipeServer(
		NP_FIND_SERVER	far *fndnext);		/* Buffer to hold server name */

WORD	far pascal NPLoaded(
		void);								// Checks if nmpipe.sys loaded

WORD	far pascal NPServerLoaded(
		void); 								// Checks if npserver.sys loaded

WORD	far pascal NPGetClientSessions(
		void far *);						// Buffer to hold sessions count

WORD	far pascal NPGetServerConnections(
		void far *);						// Buffer to hold connections count



/****************************************************************************/
/****************************************************************************/

