//
// Created by Ashish Aapan on 13/10/15.
//

#ifndef CGPROJECT_GAMEOBJECT_H
#define CGPROJECT_GAMEOBJECT_H



#include "TransformData.hpp"
#include "MainCamera.hpp"


namespace TerrainDemo {
    //forward declarations
    class AnimData;


    //base class for camera,lights and models
    class GameObject {


    public:
        //common constructors
        GameObject(const MainCamera *cam,const TransformData & transdata);


        //cam use to obtain the view matrix
        virtual ~GameObject();

        void update();//update yourself here(NVI IDIOM)




        void setCurrent_cam(MainCamera *current_cam);

    private:
        //Pure Virtual Functions
        virtual void InputUpdate() = 0;
        virtual void DrawGameObject() = 0;

    public:
        const TransformData &getTransdata() const {
            return transdata;
        }
    protected:

        //TODO cocos2d-x styled actions system for animations
        const AnimData *anim;
        //anim interface which points to the required implementaion
        //takes a pointer to Mesh to update it
        //data about orientation in 3d-space
        const MainCamera *current_cam;
        TransformData transdata;




    };


}
#endif //CGPROJECT_GAMEOBJECT_H
