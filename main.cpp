#include <SFML/Graphics.hpp>
#include <iostream>
// <variant> is not strictly needed if you use sf::Event::is and sf::Event::getIf
// #include <variant>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "FRIngine");

    sf::CircleShape playerShape(50.f);

    playerShape.setFillColor(sf::Color::Green);

    sf::Vector2f playerPosition(400.f, 300.f);
    float playerSpeed = 100.f;

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            playerPosition.y -= playerSpeed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            playerPosition.y += playerSpeed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            playerPosition.x -= playerSpeed * dt;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            playerPosition.x += playerSpeed * dt;
        }

        playerShape.setPosition(playerPosition);

        window.clear(sf::Color::Black);

        window.draw(playerShape);

        window.display();
        
    }

    return 0;
}