#ifndef __RWCACHEMAN_H__
#define __RWCACHEMAN_H__

/*
 * RWCacheManager --- caches fixed length blocks to and from disk
 *
 * $Id: cacheman.h,v 6.2 1994/07/12 18:45:56 vriezen Exp $
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
 * $Log: cacheman.h,v $
 * Revision 6.2  1994/07/12  18:45:56  vriezen
 * Update Copyright notice
 *
 * Revision 6.1  1994/04/15  19:09:33  vriezen
 * Move all files to 6.1
 *
 * Revision 2.4  1994/02/15  18:37:29  jims
 * Change return types from unsigned to size_t
 *
 * Revision 2.3  1993/09/10  02:56:53  keffer
 * Switched RCS idents to avoid spurious diffs
 *
 * Revision 2.2  1993/03/23  02:21:53  keffer
 * Eliminated int to unsigned conversions.
 *
 * Revision 2.0  1992/10/23  03:27:32  keffer
 * RCS Baseline version
 *
 * 
 *    Rev 1.2   18 Feb 1992 09:54:10   KEFFER
 * 
 *    Rev 1.1   28 Oct 1991 09:08:08   keffer
 * Changed inclusions to <rw/xxx.h>
 * 
 *    Rev 1.0   28 Jul 1991 08:12:58   keffer
 * Tools.h++ V4.0.5 PVCS baseline version
 *
 */

#include "rw/tooldefs.h"

class RWExport RWCacheManager
{

public:

  RWCacheManager(RWFile* file, unsigned blocksz, unsigned mxblks = 10);
  ~RWCacheManager();

  RWBoolean		flush();	// Perform any pending writes.
  void			invalidate();	// Invalidate the entire cache
  RWBoolean		read(RWoffset locn, void* dat);
  RWBoolean		write(RWoffset locn, void* dat);

private:

  RWCacheManager(const RWCacheManager&); // Private to insure no copies
  void			operator=(const RWCacheManager&); // Ditto
  size_t		ageAndFindSlot(RWoffset);
  RWBoolean		flush(unsigned);
  size_t		getFreeSlot();
  size_t		LRU() const; // Find least recently used block

private:

  RWFile*		theFile_;
  unsigned		maxblocks_; // Max # blocks in buff_er
  unsigned		nused_;	    // Number being used.
  unsigned		blocksize_; // Size of a block
  RWoffset*		diskAddrs_; // Its disk address
  unsigned*		useCounts_; // Use count for the block
  char*			buff_;	    // The set of blocks.
};

#endif
