#include <stdlib.h>
#include "Hero_1.h"
#include "Items.h"
Items::Items()
{
    obtenido=false;
    _texture_items.loadFromFile("Resourses/flechas.png");
    _sprite_items.setOrigin(_sprite_items.getGlobalBounds().width/2,_sprite_items.getGlobalBounds().height/2);//Para que se de vuelta
    _sprite_items.setTexture(_texture_items);
    _sprite_items.setPosition(250,500); // posicion inicial

}
void Items::update()
{
}
sf::FloatRect Items::getBounds()const
{
    return _sprite_items.getGlobalBounds();
}
void Items::draw(sf::RenderTarget& target, sf::RenderStates state)const
{
    target.draw(_sprite_items,state);
}
void Items::respawn()
{

    _sprite_items.setPosition(std::rand()%200+_sprite_items.getGlobalBounds().width,std::rand()%100+_sprite_items.getGlobalBounds().width);
}

