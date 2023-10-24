/*
 * This file is part of libsidplayfp, a SID player engine.
 *
 * Copyright 2011-2019 Leandro Nini <drfiemost@users.sourceforge.net>
 * Copyright 2007-2010 Antti Lankila
 * Copyright 2000-2001 Simon White
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <algorithm>

#include "sidbuilder.h"
#include "sidemu.h"

 //-----------------------------------------------------------------------------

libsidplayfp::sidemu* sidbuilder::lock ( libsidplayfp::EventScheduler* env, SidConfig::sid_model_t model, bool digiboost )
{
	m_status = true;

	for ( auto sid : sidobjs )
	{
		if ( sid->lock ( env ) )
		{
			sid->model ( model, digiboost );
			return sid;
		}
	}

	// Unable to locate free SID
	m_status = false;
	m_errorBuffer.assign ( name () ).append ( " ERROR: No available SIDs to lock" );
	return nullptr;
}
//-----------------------------------------------------------------------------

void sidbuilder::unlock ( libsidplayfp::sidemu* device )
{
	if ( auto it = sidobjs.find ( device ); it != sidobjs.end () )
		device->unlock ();
}
//-----------------------------------------------------------------------------

void sidbuilder::remove ()
{
	for ( auto sid : sidobjs )
		delete sid;

	sidobjs.clear ();
}
//-----------------------------------------------------------------------------
