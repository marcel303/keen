/* Keen Dreams Source Code
 * Copyright (C) 2014 Javier M. Chavez
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "SL_FILE.h"
#include "id_mm.h"

///////////////////////////////////////////////////////////////////////////
//
// Defines
//

#pragma pack(push)
#pragma pack(2)

struct BitMapHeader {
	uint16_t	w,h,x,y;
	uint8_t		d,trans,comp,pad;
};

struct BitMap {
	uint16_t Width;
	uint16_t Height;
	uint16_t Depth;
	uint16_t BytesPerRow;
	char far *Planes[8];
};

struct Shape {
	memptr Data;
	int32_t size;
	uint16_t BPR;
	struct BitMapHeader bmHdr;
};

#pragma pack(pop)

void FreeShape(struct Shape *shape);
short UnpackEGAShapeToScreen(struct Shape *SHP, short startx, short starty);
