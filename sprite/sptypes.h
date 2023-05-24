#ifndef SPTYPES_H
#define SPTYPES_H

#include "common.h"

enum TSpriteType
{
	INVALID_SPRITE = 0,
	TERRAIN_SPRITE,
	FLAT_LAND_SPRITE,
	TREE_SPRITE,
	BUILDING_SPRITE,
	VEHICLE_SPRITE,
	MAX_SPRITE,
};

#define USER_ERROR				( 1 << 29 )
#define USER_ERROR_NO_FILES		( USER_ERROR | 0 )
#define USER_ERROR_BAD_FILE		( USER_ERROR | 1 )

#endif
