#ifndef ITEMS_H
#define ITEMS_H
#include <SFML/Graphics.hpp>
#include "Colision.h"
#include "Hero_1.h"

class Items: public sf::Drawable, public Colision
{

    public:
        bool obtenido;
        Items();
        sf::Sprite _sprite_items;
        sf::Texture _texture_items;
        void update();
        void draw(sf::RenderTarget& target, sf::RenderStates state)const override;
        void respawn();
        sf::Sprite& getDraw();
        sf::FloatRect getBounds() const override;

    protected:

    private:


};

#endif // ITEMS_H
