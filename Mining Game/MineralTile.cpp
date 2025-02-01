#include"MineralTile.h"

MineralTile::MineralTile( const sf::Vector2f position, Mineral mineral, sf::Texture& tex ) : Tile( position ) {
	this->mineral_ = mineral;
	this->texture_ = tex;
	this->timer_ = 0;
	this->position_ = position;

	this->sprite_.setTexture( texture_ );
	this->sprite_.setPosition( position_.x - 8.f, position_.y - 9.f );
	this->sprite_.setScale( 1.2f, 1.2f );
}
