#pragma once
/*
 * This file is part of libsidplayfp, a SID player engine.
 *
 * Copyright 2012-2015 Leandro Nini <drfiemost@users.sourceforge.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "SidTuneBase.h"

namespace libsidplayfp
{

struct X00Header;

//-----------------------------------------------------------------------------

class p00 final : public SidTuneBase
{
public:
	/**
	 * @return pointer to a SidTune or 0 if not a PC64 file
	 * @throw loadError if PC64 file is corrupt
	 */
	[[ nodiscard ]] static SidTuneBase* load ( const char* fileName, buffer_t& dataBuf );

protected:
	p00 () = default;

private:
	void load ( const char* format, const X00Header* pHeader );

	// prevent copying
	p00 ( const p00& ) = delete;
	p00& operator=( p00& ) = delete;
};
//-----------------------------------------------------------------------------

}
