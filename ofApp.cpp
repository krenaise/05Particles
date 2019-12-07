#include "ofApp.h"


void ofApp::setup()
{
    ofBackground(0);

    ofTexture tex0;

    ofLoadImage(tex0, "firepng.png");

    std::vector<ofTexture> textures = { tex0 };

    int numParticles = 50;

    for (int i = 0; i < numParticles; i++)
    {
        Particle p;
        // Set initial positions.
        p.position.x = ofGetWidth() / 2;
        p.position.y = ofGetHeight() / 2;
        p.position.z = 0;

        // Set initial velocities.
        p.velocity.x = ofRandom(-2, 2);
        p.velocity.y = ofRandom(-5, 5);
        p.velocity.z = 0;

        // Set inital accelerations.
        p.acceleration.x = 0;
        p.acceleration.y = -0.1;
        p.acceleration.z = 0;

        // Set angular velocity.
        p.angularVelocity.x = 0;
        p.angularVelocity.y = 0;
        p.angularVelocity.z = ofRandom(-2, 2);

        // Set color.
        p.color = ofColor(ofRandom(180, 200), 100);

        // Assign a texture.
        std::size_t randomTextureIndex = ofRandom(0, textures.size());

        p.texture = textures[randomTextureIndex];

        // Add a copy to our vector.
        particles.push_back(p);
    }
}


void ofApp::update()
{
    for (Particle& p: particles)
    {
        p.update();

        ofRectangle screenRect(0, 0, ofGetWidth(), ofGetHeight());

        if (screenRect.inside(p.position) == false)
        {
            p.position = { ofGetWidth() / 2, ofGetHeight() / 2, 0 };

            p.velocity.x = ofRandom(-2, 2);
            p.velocity.y = ofRandom(-5, 5);
            p.velocity.z = 0;
        }
    }
}


void ofApp::draw()
{
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
//    for (Particle& p: particles)
//    {
//        p.draw();
//    }

    float x = ofMap( ofNoise( ofGetElapsedTimef()/2.0, -1000), 0, 1, 0, ofGetWidth());
    float y = ofMap( ofNoise( ofGetElapsedTimef()/2.0, 1000), 0, 1, 0, ofGetHeight());
    img.load("firepng.png");
    img.draw(ofGetWidth()/2, ofGetHeight()/2);
}



