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
//� Source module name: NWPS_NLM.H														  �
//藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様夕
*/
#ifndef NWPS_DEF_INC
#include <nwps_def.h>
#endif

#ifndef NWPS_NLM_INC
#define NWPS_NLM_INC
/****************************************************************************/
/*************** NLM - NLM Library Special Entry Points *********************/
/****************************************************************************/

/****************************************************************************/
/**  N W P S x x x x x x x x x	C a l l s  *********************************/
/****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*++++++++++++ Register and DeRegister a Client ++++++++++++++++++++++++++++*/
int NWPSRegisterLibraryClient( void );

int NWPSDeRegisterLibraryClient( void );

#ifdef __cplusplus
}
#endif

#endif

