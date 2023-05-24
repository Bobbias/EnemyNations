#ifndef  __RWQUEUECOL_H__
#define  __RWQUEUECOL_H__

/*
 * Declarations for a Queue of RWCollectables, implemented as a Singly-linked list.
 *
 * $Id: queuecol.h,v 6.2 1994/07/12 19:58:19 vriezen Exp $
 *
 ****************************************************************************
 *
 * Rogue Wave Software, Inc.
 * P.O. Box 2328
 * Corvallis, OR 97339
 * Voice: (503) 754-3010	FAX: (503) 757-6650
 *
 * (c) Copyright 1989, 1990, 1991, 1992, 1993, 1994 Rogue Wave Software, Inc.
 * ALL RIGHTS RESERVED
 *
 * The software and information contained herein are proprietary to, and
 * comprise valuable trade secrets of, Rogue Wave Software, Inc., which
 * intends to preserve as trade secrets such software and information.
 * This software is furnished pursuant to a written license agreement and
 * may be used, copied, transmitted, and stored only in accordance with
 * the terms of such license and with the inclusion of the above copyright
 * notice.  This software and information or any other copies thereof may
 * not be provided or otherwise made available to any other person.
 *
 * Notwithstanding any other lease or license that may pertain to, or
 * accompany the delivery of, this computer software and information, the
 * rights of the Government regarding its use, reproduction and disclosure
 * are as set forth in Section 52.227-19 of the FARS Computer
 * Software-Restricted Rights clause.
 * 
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 52.227-7013.
 * 
 * This computer software and information is distributed with "restricted
 * rights."  Use, duplication or disclosure is subject to restrictions as
 * set forth in NASA FAR SUP 18-52.227-79 (April 1985) "Commercial
 * Computer Software-Restricted Rights (April 1985)."  If the Clause at
 * 18-52.227-74 "Rights in Data General" is specified in the contract,
 * then the "Alternate III" clause applies.
 *
 ***************************************************************************
 *
 *
 ***************************************************************************
 *
 * $Log: queuecol.h,v $
 * Revision 6.2  1994/07/12  19:58:19  vriezen
 * Update Copyright notice
 *
 * Revision 6.1  1994/04/15  19:10:37  vriezen
 * Move all files to 6.1
 *
 * Revision 2.8  1994/03/04  01:04:16  jims
 * Override isEqual member function from RWCollectable to return
 * TRUE or FALSE based on operator==
 *
 * Revision 2.7  1993/09/10  02:56:53  keffer
 * Switched RCS idents to avoid spurious diffs
 *
 * Revision 2.6  1993/04/13  23:05:00  keffer
 * Now allows functions find(), contains().
 *
 * Revision 2.5  1993/04/09  19:35:45  keffer
 * Indexing is now done using size_t
 *
 * Revision 2.3  1993/01/25  18:12:13  keffer
 * RW_NO_CONST_OVERLOADS->RW_NO_CONST_OVERLOAD
 *
 * Revision 2.1  1992/11/19  05:45:01  keffer
 * Introduced new <rw/compiler.h> macro directives
 *
 * Revision 2.0  1992/10/23  03:27:32  keffer
 * RCS Baseline version
 *
 *    Rev 1.4   22 May 1992 17:04:14   KEFFER
 * Now uses RWDECLARE_COLLECTABLE() macro
 * 
 *    Rev 1.3   04 Mar 1992 09:04:20   KEFFER
 * nil changed to rwnil
 * 
 *    Rev 1.1   28 Oct 1991 09:08:20   keffer
 * Changed inclusions to <rw/xxx.h>
 * 
 *    Rev 1.0   28 Jul 1991 08:16:04   keffer
 * Tools.h++ V4.0.5 PVCS baseline version
 *
 */

#include "rw/slistcol.h"

/****************************************************************
 *								*
 *		RWSlistCollectablesQueue			*
 *								*
 ****************************************************************/

class RWExport RWSlistCollectablesQueue : public RWSlistCollectables {

  RWDECLARE_COLLECTABLE(RWSlistCollectablesQueue)

public:	 

  RWSlistCollectablesQueue();
  RWSlistCollectablesQueue(RWCollectable* a) : RWSlistCollectables(a) { }

  /************* Virtual functions inherited from RWSlistCollectables ***********/
//virtual void			append(RWCollectable* a)	// Add at tail of queue.
//virtual void			apply(RWapplyCollectable ap, void* x) 
//virtual RWCollectable*&	at(size_t i)
//virtual const RWCollectable*	at(size_t) const
//virtual void 			clear() 
//virtual void			clearAndDestroy();
//virtual RWBoolean 		contains(const RWCollectable* a) const
//RWBoolean			containsReference(const RWCollectable* a) const
//virtual size_t		entries() const 
//virtual RWCollectable*	find(const RWCollectable*) const
//RWCollectable*		findReference(const RWCollectable*)const
//virtual RWCollectable* 	first() const	// First item in queue
//virtual RWCollectable*	get()		// Remove & return first item in queue
//virtual size_t		index(const RWCollectable*) const;
//virtual RWCollectable*	insert(RWCollectable* a); // Add item to end of queue
//virtual RWBoolean		isEmpty() const 
  virtual RWBoolean		isEqual(const RWCollectable*) const;
//virtual RWCollectable*	last() const	// Last item in queue
//virtual size_t	 	occurrencesOf(const RWCollectable* a) const
//size_t		 	occurrencesOfReference(const RWCollectable* a) const
  virtual RWCollectable*	remove(const RWCollectable*) // Treated as get(); argument ignored.
    {return RWSlistCollectables::get();}

  /******************** Disallowed functions ************************/

private:

  RWCollectable*		prepend(RWCollectable*)			{return rwnil;  }
  RWCollectable*		removeReference(const RWCollectable*)	{return rwnil;  }
  virtual void			removeAndDestroy(const RWCollectable*)	{;}
};

#endif /* __RWQUEUECOL_H__ */
