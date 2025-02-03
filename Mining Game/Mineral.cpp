#include "Mineral.h"

Mineral::Mineral( const MineralType& type ) : type_( type ) {
	this->item_id_ = type.id;
}
