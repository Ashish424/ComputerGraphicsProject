//
// Created by Ashish Aapan on 13/10/15.
//

#include "MainCamera.hpp"
#include <cstdio>
#include <glm/gtx/string_cast.hpp>
namespace TerrainDemo {

    MainCamera::MainCamera(const glm::vec3 &pos, float fov, float aspect, float zNear, float zFar, const glm::vec3 &up,
                           const glm::vec3 &forward) :
            m_position(pos), m_forward(forward), m_up(up) {

        //default value of focus
        m_focusPoint = m_position + m_forward;
        m_perspective = glm::perspective(fov, aspect, zNear, zFar);


    }

    glm::mat4 MainCamera::GetViewProjection() const {

//        return m_perspective * glm::lookAt(m_position, m_focusPoint, m_up);
//    T left,
//    T right,
//    T bottom,
//    T top,
//    T zNear,
//    T zFar
        return glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 4.0f) * glm::lookAt(m_position, m_focusPoint, m_up);
    }

    void MainCamera::ApplyRotation(const glm::mat4 &transform) {
        //rotate the camera coordiante system
        using namespace ::glm;


        vec4 direction = transform * vec4(m_forward, 0.0f);
        m_forward = (vec3) direction;

        vec4 up = transform * (vec4(m_up, 0.0));
        m_up = (vec3) up;
        m_focusPoint = m_position + m_forward;


    }

}
