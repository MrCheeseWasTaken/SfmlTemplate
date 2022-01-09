#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(900, 750), "Sfml Template");

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();


        window.display();
    }

    return 0;
}