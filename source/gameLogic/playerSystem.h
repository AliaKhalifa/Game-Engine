

#ifndef GFX_LAB_PLAYERSYSTEM_H
#define GFX_LAB_PLAYERSYSTEM_H
#include "../common/Entity.h"
#include <application.hpp>
#include "../common/Components/TransformComponent.h"
#include <vector>
#include <iostream>
#include "../common/Components/CameraComponent.h"
using namespace std;
class playerSystem {
    private : 
        Entity* playerEntity;
        
        // Entity* powerCohol;
        // Entity* powerMask;
        int health = 100;
        int flag = 0;
        GAME::Application* application;
        vector<Entity*> AllEntities;  // coronas + powerups
        vector<Entity*> CoronaS;
      //  Entity* road;
      //  Entity corona;

        double delta_time;



    public:
      playerSystem(Entity* p, GAME::Application* app);
      void checkCollision(TransformComponent* p);
      void  movePlayer();
      int getHealth();
      int getFlag();
      void addObject(Entity* obj);
      vector<Entity*> getUpdatedVector();

     void addCorona(Entity* c);
    //////////generate ////////
    void generateCorona();
    void generateBottle();

      


};


#endif //GFX_LAB_PLAYERSYSTEM_H
