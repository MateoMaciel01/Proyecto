#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Mago : public sf::Drawable
{
private:
    sf::Sprite _spriteMago;
    sf::Texture _textureMago;
    bool STILL_LEFT;
    float speed;
    float _width_texture;
    float _xtexture = 0;
    sf::IntRect _current_frame;
    sf::IntRect _first_frame_of_sheet;
    int _end_of_frames_sheet;
    int _height_texture;
    int distanciaPersonajes;

public:
    Mago();
    virtual ~Mago();
    void Update(const sf::Vector2f& heroPosition, sf::Time deltaTime);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override; // Usar override para mayor claridad
    void respawn();
    sf::FloatRect getBounds() const;
    sf::Sprite& getDraw();
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    int TiempoCambioDireccion;
    int CambioDireccion;
    void Ataque();
    void Disparo();

};

