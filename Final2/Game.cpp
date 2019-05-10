#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

#include "Game.h"

Game::Game(){

	// Some cross-platform compatimility stuff

	const char* shroomFileName;
	const char* fireballFileName;
    const char* backgroundFileName;

	// In Windows (Visual Studio only) the image files are found in the enclosing folder in relation to the project
	// In other environments the image files are in the same folder as the project

	#if defined WIN32
    backgroundFileName = "../bg.png";
	#else
	//shroomFileName = "mushroom.png";
	//fireballFileName = "fireball.bmp";
    backgroundFileName = "bg.png";
	#endif

    background = new TexRect(backgroundFileName, -2, 1, 4, 2);
    //mushroom = new TexRect(shroomFileName, -0.25, 0.5, 0.5, 0.5);
    projectile = new Rect(-(rand()%6)/18, -(rand()%6)/18, 0.35, 0.35);
    projectile2 = new Rect(-(rand()%6)/24, -(rand()%6)/24, 0.35, 0.35);
    projectile3 = new Rect(-(rand()%6)/30, -(rand()%6)/30, 0.35, 0.35);
    projectile4 = new Rect(-(rand()%6)/36, -(rand()%6)/36, 0.35, 0.35);
    //explosion = new AnimatedRect(fireballFileName, 6, 6, 64, false, false, -0.25, 0.8, 0.5, 0.5);
    

    up = false;
    up2 = false;
    up3 = false;
    up4 = false;

    left = true;
    projectileVisible = true;
    //mushroomVisible = true;
    backgroundVisible = true;
    checkMouse = false;
    theta = 0;
    deg = 0;


    setRate(1);
    start();
}

void Game::action(){
    float mx = 0.5;
    float my = 0;
    
    if (theta >= 2* M_PI) theta = 0;
    if (deg >= 360) deg = 0;
    
    mx = 0.5 * cos(theta);
    my = 0.5 * sin(theta);
    
//    if (left)
//        mx -= 0.0005;
//    else
//        mx += 0.0005;
//
//    if (mx < -1.6f){
//        left = false;
//    }
//    if (mx > 1.6 - mushroom->getW()){
//        left = true;
//    }
    
    
    //mushroom->setX(mx - mushroom->getW()/2);
    //mushroom->setY(my + mushroom->getH()/2);
    
    theta += 0.001;
    deg += 0.1;
    srand (static_cast <unsigned> (time(0)));
 
    while(checkMouse){
        
        if(up){
             float ypos = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX)); 
            projectile->setY(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX)));
            up = false;
        }
        else if(up2){
             float xpos = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
            projectile2->setX(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX)));
            up2 = false;
        }
        else if(up3){
             float ypos2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
            projectile3->setY(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX)));
            up3 = false;
        }
        else if(up4){
             float xpos2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
            projectile4->setX(static_cast <float> (rand()) / (static_cast <float> (RAND_MAX)));
            up4 = false;
        }
    }

}

void Game::draw() const {
    if(backgroundVisible){
        projectile->draw();
        projectile2->draw();
        projectile3->draw();
        projectile4->draw();
        background->draw(0.0);
    }
    /*
    if (projectileVisible){
        projectile->draw();
    }
    if (mushroomVisible){
        mushroom->draw(0.0);
    }

    explosion->draw(0.1);
    */
}

void Game::handleKeyDown(unsigned char key, float x, float y){
    if (key == ' '){
       exit(0);
    }
    else if (key == 'p'){
        stop();
    }
    else if (key == 'r'){
        start();
    }
}




void Game::handleLeftMouseDown(float x, float y){
    

	if (projectile->contains(x, y)) {
		projectileVisible = false;
		up = true;
		checkMouse = true;
	}
	if(projectile2->contains(x, y)) {
		projectileVisible = false;
		up2 = true;
		checkMouse = true;
	}
	if(projectile3->contains(x, y)) {
		projectileVisible = false;
		up3 = true;
		checkMouse = true;
	}
	if(projectile4->contains(x, y)) {
		projectileVisible = false;
		up4  = true;
		checkMouse = true;
	}
   
}


Game::~Game(){
    stop();
    delete projectile;
	delete projectile2;
	delete projectile3;
	delete projectile4;
}
