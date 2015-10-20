//
// Created by Ashish Aapan on 13/10/15.
//


#include "GameObject.hpp"



namespace TerrainDemo {

    GameObject::GameObject(const MainCamera *cam, const TransformData & transdata):current_cam(cam),transdata(transdata){


    }

    void GameObject::update() {

        this->InputUpdate();
        this->DrawGameObject();



    }



    void GameObject::setCurrent_cam(MainCamera *cam){
        this->current_cam = cam;
    }



    //you delete no pinter,you dont have ownership
    GameObject::~GameObject() {

    }


}