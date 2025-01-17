/*
 * This code has been derived by Michael Schwendt <mschwendt@yahoo.com>
 * from original work by L. Peter Deutsch <ghost@aladdin.com>.
 *
 * The original C code (md5.c, md5.h) is available here:
 * ftp://ftp.cs.wisc.edu/ghost/packages/md5.tar.gz
 */

 /*
  * The original code is:

   Copyright (C) 1999 Aladdin Enterprises.  All rights reserved.

   This software is provided 'as-is', without any express or implied
   warranty.  In no event will the authors be held liable for any damages
   arising from the use of this software.

   Permission is granted to anyone to use this software for any purpose,
   including commercial applications, and to alter it and redistribute it
   freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
	  claim that you wrote the original software. If you use this software
	  in a product, an acknowledgment in the product documentation would be
	  appreciated but is not required.
   2. Altered source versions must be plainly marked as such, and must not be
	  misrepresented as being the original software.
   3. This notice may not be removed or altered from any source distribution.

   L. Peter Deutsch
   ghost@aladdin.com

  */

#include "MD5.h"

#include <string.h>

#define T1 0xd76aa478
#define T2 0xe8c7b756
#define T3 0x242070db
#define T4 0xc1bdceee
#define T5 0xf57c0faf
#define T6 0x4787c62a
#define T7 0xa8304613
#define T8 0xfd469501
#define T9 0x698098d8
#define T10 0x8b44f7af
#define T11 0xffff5bb1
#define T12 0x895cd7be
#define T13 0x6b901122
#define T14 0xfd987193
#define T15 0xa679438e
#define T16 0x49b40821
#define T17 0xf61e2562
#define T18 0xc040b340
#define T19 0x265e5a51
#define T20 0xe9b6c7aa
#define T21 0xd62f105d
#define T22 0x02441453
#define T23 0xd8a1e681
#define T24 0xe7d3fbc8
#define T25 0x21e1cde6
#define T26 0xc33707d6
#define T27 0xf4d50d87
#define T28 0x455a14ed
#define T29 0xa9e3e905
#define T30 0xfcefa3f8
#define T31 0x676f02d9
#define T32 0x8d2a4c8a
#define T33 0xfffa3942
#define T34 0x8771f681
#define T35 0x6d9d6122
#define T36 0xfde5380c
#define T37 0xa4beea44
#define T38 0x4bdecfa9
#define T39 0xf6bb4b60
#define T40 0xbebfbc70
#define T41 0x289b7ec6
#define T42 0xeaa127fa
#define T43 0xd4ef3085
#define T44 0x04881d05
#define T45 0xd9d4d039
#define T46 0xe6db99e5
#define T47 0x1fa27cf8
#define T48 0xc4ac5665
#define T49 0xf4292244
#define T50 0x432aff97
#define T51 0xab9423a7
#define T52 0xfc93a039
#define T53 0x655b59c3
#define T54 0x8f0ccc92
#define T55 0xffeff47d
#define T56 0x85845dd1
#define T57 0x6fa87e4f
#define T58 0xfe2ce6e0
#define T59 0xa3014314
#define T60 0x4e0811a1
#define T61 0xf7537e82
#define T62 0xbd3af235
#define T63 0x2ad7d2bb
#define T64 0xeb86d391

 //-----------------------------------------------------------------------------

MD5::MD5 ()
{
	reset ();
}
//-----------------------------------------------------------------------------

void MD5::reset ()
{
	count[ 0 ] = count[ 1 ] = 0;
	abcd[ 0 ] = 0x67452301;
	abcd[ 1 ] = 0xefcdab89;
	abcd[ 2 ] = 0x98badcfe;
	abcd[ 3 ] = 0x10325476;

	std::fill_n ( digest, std::size ( digest ), 0 );
	std::fill_n ( buf, std::size ( buf ), 0 );
}
//-----------------------------------------------------------------------------

void MD5::process ( const uint8_t data[ 64 ] )
{
	uint32_t a = abcd[ 0 ], b = abcd[ 1 ], c = abcd[ 2 ], d = abcd[ 3 ];

	#ifdef __BIG_ENDIAN__

	/*
	 * On big-endian machines, we must arrange the bytes in the right
	 * order.  (This also works on machines of unknown byte order.)
	 */
	const uint8_t* xp = data;

	for ( int i = 0; i < 16; ++i, xp += 4 )
		tmpBuf[ i ] = ( xp[ 0 ] & 0xFF ) + ( ( xp[ 1 ] & 0xFF ) << 8 ) + ( ( xp[ 2 ] & 0xFF ) << 16 ) + ( ( xp[ 3 ] & 0xFF ) << 24 );

	X = tmpBuf;

	#else

	/*
	 * On little-endian machines, we can process properly aligned data
	 * without copying it.
	 */
	if ( !( (uintptr_t)data & 3 ) )
	{
		/* data are properly aligned */
		X = (const uint32_t*)data;
	}
	else
	{
		/* not aligned */
		memcpy ( tmpBuf, data, 64 );
		X = tmpBuf;
	}
	#endif

	/* Round 1. */
	/* Let [abcd k s i] denote the operation
	   a = b + ((a + F(b,c,d) + X[k] + T[i]) <<< s). */
	   /* Do the following 16 operations. */
	SET ( &MD5::F, a, b, c, d, 0, 7, T1 );
	SET ( &MD5::F, d, a, b, c, 1, 12, T2 );
	SET ( &MD5::F, c, d, a, b, 2, 17, T3 );
	SET ( &MD5::F, b, c, d, a, 3, 22, T4 );
	SET ( &MD5::F, a, b, c, d, 4, 7, T5 );
	SET ( &MD5::F, d, a, b, c, 5, 12, T6 );
	SET ( &MD5::F, c, d, a, b, 6, 17, T7 );
	SET ( &MD5::F, b, c, d, a, 7, 22, T8 );
	SET ( &MD5::F, a, b, c, d, 8, 7, T9 );
	SET ( &MD5::F, d, a, b, c, 9, 12, T10 );
	SET ( &MD5::F, c, d, a, b, 10, 17, T11 );
	SET ( &MD5::F, b, c, d, a, 11, 22, T12 );
	SET ( &MD5::F, a, b, c, d, 12, 7, T13 );
	SET ( &MD5::F, d, a, b, c, 13, 12, T14 );
	SET ( &MD5::F, c, d, a, b, 14, 17, T15 );
	SET ( &MD5::F, b, c, d, a, 15, 22, T16 );

	/* Round 2. */
	/* Let [abcd k s i] denote the operation
		 a = b + ((a + G(b,c,d) + X[k] + T[i]) <<< s). */
		 /* Do the following 16 operations. */
	SET ( &MD5::G, a, b, c, d, 1, 5, T17 );
	SET ( &MD5::G, d, a, b, c, 6, 9, T18 );
	SET ( &MD5::G, c, d, a, b, 11, 14, T19 );
	SET ( &MD5::G, b, c, d, a, 0, 20, T20 );
	SET ( &MD5::G, a, b, c, d, 5, 5, T21 );
	SET ( &MD5::G, d, a, b, c, 10, 9, T22 );
	SET ( &MD5::G, c, d, a, b, 15, 14, T23 );
	SET ( &MD5::G, b, c, d, a, 4, 20, T24 );
	SET ( &MD5::G, a, b, c, d, 9, 5, T25 );
	SET ( &MD5::G, d, a, b, c, 14, 9, T26 );
	SET ( &MD5::G, c, d, a, b, 3, 14, T27 );
	SET ( &MD5::G, b, c, d, a, 8, 20, T28 );
	SET ( &MD5::G, a, b, c, d, 13, 5, T29 );
	SET ( &MD5::G, d, a, b, c, 2, 9, T30 );
	SET ( &MD5::G, c, d, a, b, 7, 14, T31 );
	SET ( &MD5::G, b, c, d, a, 12, 20, T32 );

	/* Round 3. */
	/* Let [abcd k s t] denote the operation
		 a = b + ((a + H(b,c,d) + X[k] + T[i]) <<< s). */
		 /* Do the following 16 operations. */
	SET ( &MD5::H, a, b, c, d, 5, 4, T33 );
	SET ( &MD5::H, d, a, b, c, 8, 11, T34 );
	SET ( &MD5::H, c, d, a, b, 11, 16, T35 );
	SET ( &MD5::H, b, c, d, a, 14, 23, T36 );
	SET ( &MD5::H, a, b, c, d, 1, 4, T37 );
	SET ( &MD5::H, d, a, b, c, 4, 11, T38 );
	SET ( &MD5::H, c, d, a, b, 7, 16, T39 );
	SET ( &MD5::H, b, c, d, a, 10, 23, T40 );
	SET ( &MD5::H, a, b, c, d, 13, 4, T41 );
	SET ( &MD5::H, d, a, b, c, 0, 11, T42 );
	SET ( &MD5::H, c, d, a, b, 3, 16, T43 );
	SET ( &MD5::H, b, c, d, a, 6, 23, T44 );
	SET ( &MD5::H, a, b, c, d, 9, 4, T45 );
	SET ( &MD5::H, d, a, b, c, 12, 11, T46 );
	SET ( &MD5::H, c, d, a, b, 15, 16, T47 );
	SET ( &MD5::H, b, c, d, a, 2, 23, T48 );

	/* Round 4. */
	/* Let [abcd k s t] denote the operation
		 a = b + ((a + I(b,c,d) + X[k] + T[i]) <<< s). */
		 /* Do the following 16 operations. */
	SET ( &MD5::I, a, b, c, d, 0, 6, T49 );
	SET ( &MD5::I, d, a, b, c, 7, 10, T50 );
	SET ( &MD5::I, c, d, a, b, 14, 15, T51 );
	SET ( &MD5::I, b, c, d, a, 5, 21, T52 );
	SET ( &MD5::I, a, b, c, d, 12, 6, T53 );
	SET ( &MD5::I, d, a, b, c, 3, 10, T54 );
	SET ( &MD5::I, c, d, a, b, 10, 15, T55 );
	SET ( &MD5::I, b, c, d, a, 1, 21, T56 );
	SET ( &MD5::I, a, b, c, d, 8, 6, T57 );
	SET ( &MD5::I, d, a, b, c, 15, 10, T58 );
	SET ( &MD5::I, c, d, a, b, 6, 15, T59 );
	SET ( &MD5::I, b, c, d, a, 13, 21, T60 );
	SET ( &MD5::I, a, b, c, d, 4, 6, T61 );
	SET ( &MD5::I, d, a, b, c, 11, 10, T62 );
	SET ( &MD5::I, c, d, a, b, 2, 15, T63 );
	SET ( &MD5::I, b, c, d, a, 9, 21, T64 );

	/* Then perform the following additions. (That is increment each
	   of the four registers by the value it had before this block
	   was started.) */
	abcd[ 0 ] += a;
	abcd[ 1 ] += b;
	abcd[ 2 ] += c;
	abcd[ 3 ] += d;
}
//-----------------------------------------------------------------------------

void MD5::append ( const void* data, int nbytes )
{
	const uint8_t* p = (const uint8_t*)data;
	auto	left = nbytes;
	auto	offset = ( count[ 0 ] >> 3 ) & 63;
	auto	nbits = uint32_t ( nbytes << 3 );

	if ( nbytes <= 0 )
		return;

	// Update the message length
	count[ 1 ] += nbytes >> 29;
	count[ 0 ] += nbits;
	if ( count[ 0 ] < nbits )
		count[ 1 ]++;

	// Process an initial partial block
	if ( offset )
	{
		int	copy = ( offset + nbytes > 64 ) ? ( 64 - offset ) : nbytes;
		std::copy_n ( p, copy, buf + offset );
		if ( offset + copy < 64 )
			return;

		p += copy;
		left -= copy;
		process ( buf );
	}

	// Process full blocks
	for ( ; left >= 64; p += 64, left -= 64 )
		process ( p );

	// Process a final partial block
	if ( left )
		std::copy_n ( p, left, buf );
}
//-----------------------------------------------------------------------------

void MD5::finish ()
{
	static const uint8_t pad[ 64 ] = {
		0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};
	uint8_t data[ 8 ];

	// Save the length before padding
	for ( auto i = 0; i < 8; ++i )
		data[ i ] = (uint8_t)( count[ i >> 2 ] >> ( ( i & 3 ) << 3 ) );

	// Pad to 56 bytes mod 64
	append ( pad, ( ( 55 - ( count[ 0 ] >> 3 ) ) & 63 ) + 1 );

	// Append the length
	append ( data, 8 );

	for ( auto i = 0; i < 16; ++i )
		digest[ i ] = (uint8_t)( abcd[ i >> 2 ] >> ( ( i & 3 ) << 3 ) );
}
//-----------------------------------------------------------------------------

const uint8_t* MD5::getDigest ()
{
	return digest;
}
//-----------------------------------------------------------------------------

std::string MD5::getAscIIDigest ()
{
	std::string	result;

	const auto  rawDigest = getDigest ();
	if ( ! rawDigest )
		return result;

	// Construct fingerprint
	static const char digits[] = "0123456789abcdef";

	for ( auto i = 0; i < 16; i++ )
	{
		result += digits[ rawDigest[ i ] >> 4 ];
		result += digits[ rawDigest[ i ] & 15 ];
	}

	return result;
}
//-----------------------------------------------------------------------------
