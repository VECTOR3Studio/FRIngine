#pragma once
#include <SFML/Graphics.hpp>

class Player
{
    public:
        Player(float x, float y);

        void handleInput();
        void update(float dt);
        void draw(sf::RenderWindow& window);

    private:
        sf::CircleShape m_shape;
        sf::Vector2f m_pos;
        sf::Vector2f m_velocity;
        float m_speed;
};