#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(20.f);
    shape.setPosition(100, 100);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {                       
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) shape.setPosition(shape.getPosition() + sf::Vector2f(-0.1, 0));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) shape.setPosition(shape.getPosition() + sf::Vector2f(0.1, 0));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) shape.setPosition(shape.getPosition() + sf::Vector2f(0, 0.1));
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) shape.setPosition(shape.getPosition() + sf::Vector2f(0, -0.1));

        if ((shape.getPosition().x + 2 * shape.getRadius() >= window.getSize().x) || (shape.getPosition().x - 2 * shape.getRadius() <= -50)) shape.setPosition(375, 275);
        if ((shape.getPosition().y + 2 * shape.getRadius() >= window.getSize().y) || (shape.getPosition().y - 2 * shape.getRadius() <= -50)) shape.setPosition(375, 275);


        window.draw(shape);
        window.display();
    }

    return 0;
}