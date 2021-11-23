#include <iostream>
#include <SFML/Graphics.hpp>
#include "headers/HelpfulHeader.hpp"
#include "headers/Fps.hpp"

using namespace std;
using namespace sf;

const Vec2 wSize(100, 100);

void ResizedWindow(RenderWindow& window, View& cam){
    double rendererAspect = (double) wSize.x / (double) wSize.y,
            windowAspect = double(window.getSize().x) / double(window.getSize().y),
            scaleFactor = windowAspect > rendererAspect ?
                double(window.getSize().y) / wSize.y :
                double(window.getSize().x) / wSize.x;

        int rw = int(wSize.x * scaleFactor), rh = int(wSize.y * scaleFactor);

    float rwNormal = float(rw)/float(window.getSize().x);
    float rhNormal = float(rh)/float(window.getSize().y);

    cam.setViewport(FloatRect((1-rwNormal)/2, (1-rhNormal)/2, rwNormal, rhNormal));
}

float giveDt(Clock& dtClock){
    return dtClock.restart().asSeconds();
}

int main(){
    sf::RenderWindow window(sf::VideoMode(wSize.x, wSize.y), "Game");
    window.setFramerateLimit(240);
    window.setSize(Vector2u(900, 900));
    window.setPosition(Vector2i(VideoMode::getDesktopMode().width/2 - window.getSize().x/2, VideoMode::getDesktopMode().height/2 - window.getSize().y/2));
    View viewPort;
    viewPort.setSize(wSize.x, wSize.y);
    viewPort.setCenter(wSize.x/2, wSize.y/2);


    FPS fps;
    Clock dtClock;
    float deltaTime;

    while (window.isOpen())
    {
        deltaTime = giveDt(dtClock);
        fps.update();
        string ss(to_string(fps.getFPS()));
        
        window.setTitle("Game Fps: "+ ss);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized)
                ResizedWindow(window, viewPort);
        }

        window.setView(viewPort);
        window.clear();

        window.display();
    }

    return 0;
}