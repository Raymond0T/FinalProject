#ifndef Game_hpp
#define Game_hpp

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "Timer.h"
#include "GlutApp.h"

class Game: public AppComponent, private Timer{
    TexRect* mushroom;
    Rect* projectile;
    Rect* projectile2;
    Rect* projectile3;
    Rect* projectile4;
    TexRect* background;

    bool backgroundVisible;
    bool projectileVisible;
    bool mushroomVisible;
    bool checkMouse;
    bool up;
	bool up2;
	bool up3;
	bool up4;

    bool left;
    bool hit;
    float theta;
    float deg;
	//float score;
public:
    AnimatedRect* explosion;
    Game();
    
    void draw() const ;
    void handleKeyDown(unsigned char, float, float);
    void handleLeftMouseDown(float, float );
    

    
    void action();

    ~Game();

};

#endif 
