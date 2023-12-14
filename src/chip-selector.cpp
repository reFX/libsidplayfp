#include "chip-selector.h"

#include <algorithm>

namespace libsidplayfp
{

//-----------------------------------------------------------------------------

ChipSelector::settings ChipSelector::getChipProfile ( const char* _path, const char* _filename )
{
	auto	path = std::string ( _path );

	// Normalize path separators
	std::replace ( path.begin (), path.end (), '\\', '/' );

	// Remove root
	auto	pos = path.rfind ( "/MUSICIANS/" );

	// If tune is not from a "/MUSICIANS/" folder, return default values
	if ( pos == std::string::npos )
		return {};

	path = path.substr ( pos );

	// Identify author by folder
	for ( const auto& [ name, set ] : chipProfiles )
	{
		if ( ! set.folder.starts_with ( path ) )
			continue;

		if ( set.exceptions.empty () )
			return set;

		// Get filename without extension
		auto	filename = std::string ( _filename );
		filename.erase ( filename.length () - 4 );

		// Find new author if exception matches
		if ( auto exception = set.exceptions.find ( filename ); exception != set.exceptions.end () )
			return chipProfiles.at ( exception->second );

		return set;
	}

	// Default
	return {};
}
//-----------------------------------------------------------------------------

}