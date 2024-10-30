#include "Game_play.h"


Game_play::Game_play(sf::RenderWindow& window)
{
    _states = STATES_GAME_PLAY::ACTION;
    // Inicializa el tiempo
    clock.restart(); // objeto clock
}

Game_play::~Game_play()
{

}

void Game_play::draw(sf::RenderWindow& window)
{
    window.draw(BG.getDraw());
    window.draw(Hro.getDraw());
    window.draw(Villano_1.getDraw());
    window.draw(items);

    for (auto& Shots: Hro._shots_array)
    {
        window.draw(Shots->getDraw());
    }
}

void Game_play::cmd()
{

    if(_states==STATES_GAME_PLAY::ACTION)
    {
        Hro.mobility();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            _states=STATES_GAME_PLAY::PAUSE;
        }
    }
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            _states=STATES_GAME_PLAY::ACTION;
        }
    }
}
void Game_play::update(sf::RenderTarget& window)
{
    BG.update();

    // Obtén el tiempo transcurrido desde el último frame
    sf::Time deltaTime = clock.restart(); // Reinicia el reloj y obtiene el tiempo transcurrido

    if (_states == STATES_GAME_PLAY::ACTION)
    {
        Hro.update();
        Villano_1.Update(Hro.getPosition(), deltaTime); //envio el deltatime
    }


    if(getLavel_I())
    {
        if((Hro.getDraw().getPosition().x<866&&Hro.getDraw().getPosition().y>485)||(Hro.getDraw().getPosition().x>1366&&Hro.getDraw().getPosition().x<4214&&Hro.getDraw().getPosition().y>485)||(Hro.getDraw().getPosition().x>4642&&Hro.getDraw().getPosition().x<5186&&Hro.getDraw().getPosition().y>485)||(Hro.getDraw().getPosition().x>5374&&Hro.getDraw().getPosition().x<9584&&Hro.getDraw().getPosition().y>485)||(Hro.getDraw().getPosition().x>9754&&Hro.getDraw().getPosition().x<10902&&Hro.getDraw().getPosition().y>485)||(Hro.getDraw().getPosition().x>11086&&Hro.getDraw().getPosition().y>485))//485 Suelo... limite de caida
        {
            Hro.floor(Hro.getDraw().getPosition().x,485);
            setLavel(true, false);
        }
        else
        {
            setLavel(false, true);
        }
    }
    else
    {
        if(getLavel_II())
        {
            if(Hro.getDraw().getPosition().y>1210)
            {
                Hro.floor(Hro.getDraw().getPosition().x,1210);
                setLavel(false, true);
            }
            else
            {
                setLavel(true, false);
            }
        }
    }


}

sf::Vector2f Game_play::get_camera_position()
{
    return Hro.getPosition();
}

void Game_play::setLavel(bool I, bool II)
{
    lavel_I=I;
    lavel_II=II;
}

