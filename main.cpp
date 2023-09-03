#include <SFML/Graphics.hpp>

#include "Paint.h"

int main(void) 
{
    sf::RenderWindow window(sf::VideoMode(BASIC_WIDTH, BASIC_HEIGHT), "Paint in C++");

    sf::RenderTexture canvasTexture;
    canvasTexture.create(BASIC_WIDTH, BASIC_HEIGHT);

    bool isDrawing = false;
    sf::Vector2f lastPosition;
    sf::Event event;

    while (window.isOpen()) 
    {
        
        while (window.pollEvent(event)) 
        {
            if (closeButton(event))
            {
                window.close();
            }        

            if (leftCLickIsPressed(event)) 
            {
                isDrawing = true;
                lastPosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
            }

            if (event.type == sf::Event::MouseButtonReleased) 
            {
                isDrawing = false;
            }
        }

        if (isDrawing) 
        {
            sf::Vector2f newPosition(sf::Mouse::getPosition(window));
            sf::VertexArray line(sf::Lines, POSITIONS);
            line[0].position = lastPosition;
            line[1].position = newPosition;
            canvasTexture.draw(line);
            lastPosition = newPosition;
        }

      //  window.clear();
        canvasTexture.display();
        sf::Sprite canvasSprite(canvasTexture.getTexture());
        window.draw(canvasSprite);
        window.display();
    }

    return 0;
}
