#include "headers/Fps.hpp"
#include <SFML/Graphics.hpp>

const unsigned int FPS::getFPS() { return mFps; }

void FPS::update()
{
    if(mClock.getElapsedTime().asSeconds() >= 1.f)
    {
        mFps = mFrame;
        mFrame = 0;
        mClock.restart();
    }

    ++mFrame;
}