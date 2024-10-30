#ifndef HERO_1_H
#define HERO_1_H
#include <SFML/Graphics.hpp>
#include "Shots.h"
#include <iostream>
#include <vector>
#include <memory>
#include "Colision.h"


class Hero_1
{
public:
    Hero_1();
    //virtual ~Hero_1();
    enum STATES
    {
        STILL_RIGHT,
        STILL_LEFT,
        WALKING_RIGHT,
        WALKING_LEFT,
        JUMPING,
        WALKING_RIGHT_JUMPING,
        WALKING_LEFT_JUMPING,
        SHOOTING_RIGHT,
        SHOOTING_LEFT,
        ATTACK_RIGHT,
        ATTACK_LEFT,
        COLISION_RIGHT,
        COLISION_LEFT,
        DEATH,

    };
    void update();
    void updateAnimation();
    void mobility();
    sf::Sprite& getDraw();
    void floor(float x, float y);
    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    void initVariables();
    void initAnimation();
    Shots* shootig;
    std::vector<std::unique_ptr<Shots>> _shots_array;
    bool isDPressed = false;
    bool yaDisparo = false;
    sf::FloatRect getBounds() const;
    bool obtenido;

protected:

private:
    sf::Sprite _sprite_hero;
    sf::Texture _texture_hero;
    STATES _state;
    float _jump_force;
    int _xtexture=0;
    float _width_texture;

    sf::Clock _animationTimer;
    sf::IntRect _current_frame;
    sf::IntRect _first_frame_of_sheet;      //me sirve para saber las coordenadas donde arranca el frame de cada tipo de disparo
    int _end_of_frames_sheet;               //me sirve para saber hasta donde va cada sprite en los distintos tipos de disparos
    int _height_texture;

    sf::Clock _shoot_timer;
    sf::Time _time_shoot;



};

#endif // HERO_1_H
