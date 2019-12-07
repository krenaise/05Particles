#pragma once


#include "ofMain.h"
#include "Particle.hpp"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    std::vector<Particle> particles;
    
    ofImage img;

};
