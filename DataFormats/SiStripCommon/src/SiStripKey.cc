// Last commit: $Id: SiStripKey.cc,v 1.4 2007/06/19 12:16:53 bainbrid Exp $

#include "DataFormats/SiStripCommon/interface/SiStripKey.h"
#include "DataFormats/SiStripCommon/interface/Constants.h" 
#include "DataFormats/SiStripCommon/interface/SiStripEnumsAndStrings.h"
#include <iomanip>
#include <sstream>

// -----------------------------------------------------------------------------
// 
SiStripKey::SiStripKey( const uint32_t& key ) :
  key_(key),
  path_(sistrip::null_),
  granularity_(sistrip::UNDEFINED_GRAN),
  channel_(sistrip::invalid_)
{;}

// -----------------------------------------------------------------------------
// 
SiStripKey::SiStripKey( const std::string& path ) :
  key_(sistrip::invalid32_),
  path_(path),
  granularity_(sistrip::UNDEFINED_GRAN),
  channel_(sistrip::invalid_)
{;}

// -----------------------------------------------------------------------------
// 
SiStripKey::SiStripKey( const SiStripKey& input ) :
  key_( input.key() ),
  path_( input.path() ),
  granularity_( input.granularity() ),
  channel_( input.channel() )
{;}

// -----------------------------------------------------------------------------
// 
const SiStripKey& SiStripKey::operator=( const SiStripKey& rhs ) {
  if ( this == &rhs ) { return *this; }
  key_ = rhs.key();
  path_ = rhs.path();
  granularity_ = rhs.granularity();
  channel_ = rhs.channel();
  return *this;
}

// -----------------------------------------------------------------------------
// 
SiStripKey::SiStripKey() : 
  key_(sistrip::invalid32_),
  path_(sistrip::null_),
  granularity_(sistrip::UNDEFINED_GRAN),
  channel_(sistrip::invalid_)
{;}

// -----------------------------------------------------------------------------
// 
bool SiStripKey::isEqual( const SiStripKey& input ) const {
  if ( !(&input) ) { return false; }
  if ( key_ == input.key() &&
       path_ == input.path() &&
       granularity_ == input.granularity() &&
       channel_ == input.channel() ) { 
    return true;
  } else { return false; }
}

// -----------------------------------------------------------------------------
// 
bool SiStripKey::isConsistent( const SiStripKey& input ) const {
  return isEqual(input); 
}

// -----------------------------------------------------------------------------
//
bool SiStripKey::isValid() const { 
  return ( key_ != sistrip::invalid32_ &&
	   path_ != sistrip::null_ &&
	   granularity_ != sistrip::UNDEFINED_GRAN &&
	   channel_ != sistrip::invalid_ );
}

// -----------------------------------------------------------------------------
//
bool SiStripKey::isValid( const sistrip::Granularity& gran ) const { 
  return isValid();
}

// -----------------------------------------------------------------------------
//
bool SiStripKey::isInvalid() const { 
  return ( key_ == sistrip::invalid32_ ||
	   path_ == sistrip::null_ ||
	   granularity_ == sistrip::UNDEFINED_GRAN ||
	   channel_ == sistrip::invalid_ );
}

// -----------------------------------------------------------------------------
//
bool SiStripKey::isInvalid( const sistrip::Granularity& gran ) const { 
  return isInvalid();
}

// -----------------------------------------------------------------------------
//
std::ostream& operator<< ( std::ostream& os, const SiStripKey& input ) {
  return os << std::endl
	    << " [SiStripKey::print]" << std::endl
	    << std::hex
	    << " 32-bit key  : 0x" 
	    << std::setfill('0') 
	    << std::setw(8) << input.key() << std::endl
	    << std::setfill(' ') 
	    << std::dec
	    << " Directory   : " << input.path() << std::endl
	    << " Granularity : " 
	    << SiStripEnumsAndStrings::granularity( input.granularity() ) << std::endl
	    << " Channel     : " << input.channel();
  
}
