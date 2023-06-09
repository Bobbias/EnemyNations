/*
//浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様融
//� (c) 1993 Novell, Inc.	All rights reserved.                              �
//�																								  �
//� THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND		  �
//� TREATIES.																					  �
//�																								  �
//� NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED, COPIED,			  �
//� DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED, CONDENSED,         �
//� EXPANDED, COLLECTED, COMPILED, LINKED, RECAST, TRANSFORMED OR ADAPTED	  �
//� WITHOUT THE PRIOR WRITTEN CONSENT OF NOVELL, INC.                        �
//�																								  �
//� ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION COULD SUBJECT �
//� THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.								  �
//麺様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様郵
//� Source module name: NWPSCOMX.H														  �
//藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様夕
*/
#ifdef __cplusplus
extern "C" {
#endif

/*====================== Print Server Communications ======================*/
/*---------------------------------------------------------------
  The connType and connID fields are used to determine the context
  in which to run this library.	The connType and connID used by
  NWPSComLoginToPrintServer are used only to acquire rights.
  ---------------------------------------------------------------*/
NWCCODE NWAPI NWPSComAttachToPrintServer(
  WORD  connType,                      /* Connection type to use				*/
  DWORD connID,								/* Connection ID to file server		*/
  WORD  timeOut,								/* Number of seconds before timeout */
  char  NWPTR pServerName,             /* Print server name                */
  WORD  NWPTR spxID);						/* SPX Connection number				*/

/*---------------------------------------------------------------
  The connType and connID fields are used only to acquire rights.
  The connType and connID used by NWPSComAttachToPrintServer are
  used to determine the context in which to run this library.
  ---------------------------------------------------------------*/
NWCCODE NWAPI NWPSComLoginToPrintServer(
  WORD  connType,                      /* Connection type to use				*/
  DWORD connID,								/* Connection ID to file server		*/
  WORD  spxID,                         /* SPX Connection number				*/
  BYTE  NWPTR accessLevel);				/* Client's access level				*/


#ifdef __cplusplus
}
#endif
