#include "Player.hpp"

Player::Player(float x, float y)
        {
            m_shape.setPointCount(3);
            m_shape.setRadius(30.f);
            m_shape.setFillColor(sf::Color::Cyan);
            m_pos = {x, y};
            m_speed = 200.f;
        }

        void Player::handleInput()
        {
            sf::Vector2f velocity(0.f, 0.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) velocity.y = -1;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) velocity.y = 1;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) velocity.x = -1;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) velocity.x = 1;

            m_velocity = velocity;
        }

        void Player::update(float dt)
        {
            m_pos += m_velocity * m_speed * dt;
            m_shape.setPosition(m_pos);
        }

        void Player::draw(sf::RenderWindow& window)
        {
            window.draw(m_shape);
        }