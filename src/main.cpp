#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.hpp"

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
            if(event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
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
    delete &player;
    return 0;
}