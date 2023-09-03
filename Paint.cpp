#include <SFML/Graphics.hpp>

#include "Paint.h"


bool closeButton(sf::Event event)
{
    return event.type == sf::Event::Closed;
}

bool leftCLickIsPressed(sf::Event event)
{
    return event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left;
}

/*
void draw(sf::Vector2f lastPosition, sf::RenderWindow window, sf::RenderTexture canvasTexture)
{
    sf::Vector2f newPosition(sf::Mouse::getPosition(window));
    sf::VertexArray line(sf::Lines, POSITIONS);
    line[0].position = lastPosition;
    line[1].position = newPosition;
    canvasTexture.draw(line);
    lastPosition = newPosition;
}
*/
