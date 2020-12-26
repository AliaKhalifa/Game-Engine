#ifndef GFX_LAB_RENDERERSYSTEM_H
#define GFX_LAB_RENDERERSYSTEM_H

#include <vector>
#include <Components/CameraComponent.h>
#include <Components/MeshRenderer.h>
#include <Components/TransformComponent.h>
#include <Components/Component.h>
#include <glm/gtx/string_cast.hpp>

#include "Entity.h"

using namespace std;

class RendererSystem  {
private:

    vector<Entity*> Entities;
    Entity* worldEntity;
public:
    void setEntityVector(vector<Entity*> Ent)
    {
        this->Entities = Ent;
    }
    void setworldEntity(Entity* world)
    {
        this->worldEntity = world;
    }
    void RenderAll(vector<Entity*> Ent,Entity* world)
    {
    // vector[0] -> Transform , vector[1] -> MeshRenderer ,

            CameraComponent* cam;
           vector<Component*> w = world->getComponents(); // camera
            for (int j =0;j< w.size();j++)
            {
                cam = dynamic_cast<CameraComponent*>(w[j]);
                if (cam != NULL)
                    break;
            }
        for (int i =1;i< Ent.size();i++)
        {

            MeshRenderer* mesh;
            TransformComponent* tranf;
            vector<Component*> m = Ent[i]->getComponents();

            for (int j =0;j< m.size();j++)
            {
                 tranf = dynamic_cast<TransformComponent*>(m[j]);
                if (tranf != NULL)
                    break;
            }

            for (int j =0;j< m.size();j++)
            {
                mesh = dynamic_cast<MeshRenderer*>(m[j]);
                if (mesh != NULL)
                    break;
            }
            if (mesh !=NULL && tranf !=NULL)
            {

               glUseProgram(*(mesh->getMaterial()->getShader())); 
               glm::vec4 s = std::any_cast<glm::vec4>( mesh->getMaterial()->getUniforms("tint"));
               mesh->getMaterial()->getShader()->set("tint", s);

                mesh->getMaterial()->getShader()->set("transform", cam->getVPMatrix() * tranf->to_mat4());
                mesh->getMesh()->draw(); 
            }


        }

    }
};

                             //  mesh->getMaterial()->AddUniforms("tint", glm::vec4(1,1, 1, 1));

#endif //GAME_MESH_H
