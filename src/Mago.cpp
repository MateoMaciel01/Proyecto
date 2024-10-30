#include "Mago.h"
Mago::Mago()
{
    speed = 1.5f;
    _textureMago.loadFromFile("Resourses/Mago_spritever2.png");
    _spriteMago.setTexture(_textureMago);
    _spriteMago.setPosition(250, 535);
    _spriteMago.setTextureRect({ 14,154,60,104 });
    _spriteMago.setOrigin(_spriteMago.getGlobalBounds().width / 2, _spriteMago.getGlobalBounds().height / 2);
    STILL_LEFT = true;


    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    TiempoCambioDireccion = 0;
    CambioDireccion = 800;
}

Mago::~Mago() {
}

void Mago::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_spriteMago, states);
}


sf::FloatRect Mago::getBounds() const
{
    return _spriteMago.getGlobalBounds();
}

sf::Sprite& Mago::getDraw()
{
    return _spriteMago;
}
sf::Vector2f Mago::getPosition()
{
    return _spriteMago.getPosition();
}

void Mago::Update(const sf::Vector2f& heroPosition, sf::Time deltaTime)
{

    //el mago no sale de la pantalla
    if (_spriteMago.getPosition().x < 150) {
        _spriteMago.setPosition(150, getPosition().y);

    }
    if (_spriteMago.getPosition().x > 12250) {
        _spriteMago.setPosition(12250, getPosition().y);

    }

    //volteo de personaje
    TiempoCambioDireccion += deltaTime.asMilliseconds();

    _width_texture = 70;
    _xtexture = (int)_spriteMago.getPosition().x / 8 % 6;
    _xtexture = _xtexture * 75;
    _spriteMago.setTextureRect(sf::IntRect(_xtexture, 154, _width_texture, 104));

    // Cambia de dirección aleatoriamente
    if (TiempoCambioDireccion >= CambioDireccion)
    {
        // Decide si cambiar de dirección
        if (std::rand() % 2 == 0)
        {
            // Cambia la dirección
            speed = -speed; // Invierte la dirección
            STILL_LEFT = !STILL_LEFT; // Cambia el estado de dirección
            // Cambia la escala del sprite
            _spriteMago.setScale(STILL_LEFT ? sf::Vector2f(-1.5, 1.5) : sf::Vector2f(1.5, 1.5));
        }
        TiempoCambioDireccion = 0; // Reinicia el tiempo
    }


    // Comprueba si el héroe está a la izquierda o a la derecha del mago
    if (heroPosition.x < _spriteMago.getPosition().x)
    {
        // Héroe a la izquierda
        if (STILL_LEFT)
        {
            _spriteMago.move(-speed, 0);
        }
        else
        {
            // Si el mago está mirando a la derecha, mueve hacia la izquierda
            _spriteMago.setScale(sf::Vector2f(-1.5, 1.5));
            STILL_LEFT = false;
            _spriteMago.move(-speed, 0);
        }
    }
    else
    {
        // Héroe a la derecha
        if (!STILL_LEFT)
        {
            _spriteMago.move(speed, 0);
        }
        else
        {
            // Si el mago está mirando a la izquierda, mueve hacia la derecha
            _spriteMago.setScale(sf::Vector2f(1.5, 1.5));
            STILL_LEFT = true;
            _spriteMago.move(speed, 0);
        }
    }
    distanciaPersonajes = _spriteMago.getPosition().x - heroPosition.x;

    if (distanciaPersonajes == 0)
    {
        Ataque();
    }
}

void Mago::Ataque() {
    _width_texture = 94;  // Ancho de cada frame de la animación de disparo
    _height_texture = 101;   // Altura de cada frame de la animación de disparo
    _end_of_frames_sheet = 951.0; // Posición final de los frames de la hoja de sprites
    _spriteMago.setScale(sf::Vector2f(-1.5, 1.5));  // Escala para disparar hacia la derecha
    _first_frame_of_sheet = sf::IntRect(0, 824, _width_texture, _height_texture); // Primer frame del disparo hacia la derecha
    _current_frame = _first_frame_of_sheet;  // Inicializar el frame actual
}

void Mago::Disparo() {
    _width_texture = 94;  // Ancho de cada frame de la animación de disparo
    _height_texture = 101;   // Altura de cada frame de la animación de disparo
    _end_of_frames_sheet = 951.0; // Posición final de los frames de la hoja de sprites
    _spriteMago.setScale(sf::Vector2f(-1.5, 1.5));  // Escala para disparar hacia la derecha
    _first_frame_of_sheet = sf::IntRect(0, 824, _width_texture, _height_texture); // Primer frame del disparo hacia la derecha
    _current_frame = _first_frame_of_sheet;  // Inicializar el frame actual
}

