#include "headers/HelpfulHeader.hpp"
#include <math.h>
#include <iostream>

using namespace std;

Vec2::Vec2(float x0 ,float y0){
    x = x0; y = y0;
}

void Vec2::set(Vec2 otherVec){
    x=otherVec.x; y=otherVec.y;
}

void Vec2::cAdd(Vec2 otherVec){
    x+=otherVec.x; y+=otherVec.y;
}

void Vec2::cSubtract(Vec2 otherVec){
    x-=otherVec.x; y-=otherVec.y;
}

void Vec2::cMultiply(float value){
    x*=value; y*=value;
}

void Vec2::cDivide(float value){
    x/=value; y/=value;
}

Vec2 Vec2::Add(Vec2 otherVec){
    return Vec2(x+otherVec.x, y+otherVec.y);
}

Vec2 Vec2::Subtract(Vec2 otherVec){
    return Vec2(x-otherVec.x, y-otherVec.y);
}

Vec2 Vec2::Multiply(float value){
    return Vec2(x*value, y*value);
}

Vec2 Vec2::Divide(float value){
    return Vec2(x/value, y/value);
}

float Vec2::magnitude(){
    return sqrt(pow(x, 2) + pow(y, 2));
}

Vec2 Vec2::normalize(){
    return Vec2(x/magnitude(), y/magnitude());
}

Vec2 Vec2::lerp(Vec2 otherVec, float t){
    return Vec2(Lerp(x, otherVec.x, t), Lerp(y, otherVec.y, t));
}

void Vec2::moveTowards(Vec2 target, float speed, float deltaTime){
    Vec2 dir = Vec2(x, y).Subtract(target).normalize();
    x += dir.x*speed*deltaTime;
    y += dir.y*speed*deltaTime;
}

void Vec2::printCoords(){
    cout << x << " " << y << endl;
}

bool Vec2::isEqualTo(Vec2 otherVec){
    return (x==otherVec.x and y==otherVec.y) ? true : false;
}

int * HsvToRgb(float H, float S,float V){
    H = fmax(0, fmin(H, 360));
    S = fmax(0, fmin(S, 100));
    V = fmax(0, fmin(V, 100));

    float s = S/100;
    float v = V/100;
    float C = s*v;
    float X = C*(1-abs(fmod(H/60.0, 2)-1));
    float m = v-C;
    float r,g,b;
    if(H >= 0 && H < 60){
        r = C,g = X,b = 0;
    }
    else if(H >= 60 && H < 120){
        r = X,g = C,b = 0;
    }
    else if(H >= 120 && H < 180){
        r = 0,g = C,b = X;
    }
    else if(H >= 180 && H < 240){
        r = 0,g = X,b = C;
    }
    else if(H >= 240 && H < 300){
        r = X,g = 0,b = C;
    }
    else{
        r = C,g = 0,b = X;
    }

    int R = (r+m)*255;
    int G = (g+m)*255;
    int B = (b+m)*255;

    int *value = new int[3]{R, G, B};
    return value;
}

float Lerp(float a, float b, float t){
    return a + (b -a ) * t;
}

bool linesIntersect(Vec2 a, Vec2 b, Vec2 c, Vec2 d){
    Vec2 r = b.Subtract(a);
    Vec2 s = d.Subtract(c);
    float e = (r.x * s.y) - (r.y * s.x);
    float u = ((c.x - a.x) * r.y - (c.y - a.y) * r.x) / e;
    float t = ((c.x - a.x) * s.y - (c.y - a.y) * s.x) / e;
    
    return (0 <= u and u <= 1 and 0 <= t and t <= 1);
}