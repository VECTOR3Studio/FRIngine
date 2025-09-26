#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
    public:
        Player(float x, float y)
        {
            m_shape.setPointCount(3);
            m_shape.setRadius(30.f);
            m_shape.setFillColor(sf::Color::Cyan);
            m_pos = {x, y};
            m_speed = 200.f;
        }

        void handleInput()
        {
            sf::Vector2f velocity(0.f, 0.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) velocity.y = -1;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) velocity.y = 1;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) velocity.x = -1;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) velocity.x = 1;

            m_velocity = velocity;
        }

        void update(float dt)
        {
            m_pos += m_velocity * m_speed * dt;
            m_shape.setPosition(m_pos);
        }

        void draw(sf::RenderWindow& window)
        {
            window.draw(m_shape);
        }

    private:
        sf::Vector2f m_velocity;
        sf::CircleShape m_shape;
        sf::Vector2f m_pos;
        float m_speed;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "FRIngine");
    window.setFramerateLimit(60);

    Player player(400.f, 300.f);

    sf::Clock deltaClock;

    while(window.isOpen())
    {

        float dt = deltaClock.restart().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        player.handleInput();
        player.update(dt);

        window.clear(sf::Color::Black);
        player.draw(window);
        window.display();
        
    }

    return 0;
}