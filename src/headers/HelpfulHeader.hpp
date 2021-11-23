#pragma once

struct  Vec2
{
    float x;
    float y;

    Vec2(float x0=0, float y0=0);

    void set(Vec2 otherVec);

    void cAdd(Vec2 otherVec);
    void cSubtract(Vec2 otherVec);
    void cMultiply(float value);
    void cDivide(float value);

    Vec2 Add(Vec2 otherVec);
    Vec2 Subtract(Vec2 otherVec);
    Vec2 Multiply(float value);
    Vec2 Divide(float value);

    float magnitude();
    Vec2 normalize();
    Vec2 lerp(Vec2 otherVec, float t);

    void moveTowards(Vec2 target, float speed, float deltaTime=0);
    void printCoords();

    bool isEqualTo(Vec2 otherVec);
};

int * HsvToRgb(float H, float S, float V);

static const double Pi = 3.14159265359;

float Lerp(float a,float b,float t);

bool linesIntersect(Vec2 a, Vec2 b, Vec2 c, Vec2 d);
