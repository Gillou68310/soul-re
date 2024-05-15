#ifndef _COLIDE_H_
#define _COLIDE_H_

#include "TYPES.h"

// size: 0x8
struct _Normal {
	// offset: 0000
	short x;
	// offset: 0002
	short y;
	// offset: 0004
	short z;
	// offset: 0006
	short pad;
};

// size: 0x30
struct _CollideInfo {
	// offset: 0000
	void *level;
	// offset: 0004
	char flags;
	// offset: 0005
	char segment;
	// offset: 0006
	char type0;
	// offset: 0007
	char type1;
	// offset: 0008
	void *prim0;
	// offset: 000C
	void *prim1;
	// offset: 0010
	void *inst0;
	// offset: 0014
	void *inst1;
	// offset: 0018 (8 bytes)
	struct SVECTOR point0;
	// offset: 0020 (8 bytes)
	struct SVECTOR point1;
	// offset: 0028 (6 bytes)
	struct _Position offset;
	// offset: 002E
	short bspID;
};

#endif
