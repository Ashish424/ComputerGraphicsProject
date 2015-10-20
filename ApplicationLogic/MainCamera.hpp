//
// Created by Ashish Aapan on 13/10/15.
//

#ifndef CGPROJECT_CAMERA_H
#define CGPROJECT_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "glew.h"

//TODO add projection matrix different from view matrix
namespace TerrainDemo {


    class MainCamera {

    public:
        MainCamera(const glm::vec3 &pos, float fov, float aspect, float zNear, float zFar, const glm::vec3 &up,
                   const glm::vec3 &forward);

        glm::mat4 GetViewProjection() const;

        const glm::vec3 &getM_position() const {
            return m_position;
        }

        void setM_position(const glm::vec3 &m_position) {
            MainCamera::m_position = m_position;
            m_focusPoint = m_position + m_forward;
        }

        glm::vec3 &getM_focusPoint() {
            return m_focusPoint;
        }

        void setM_focusPoint(const glm::vec3 &m_focusPoint) {
            MainCamera::m_focusPoint = m_focusPoint;
        }

        void ApplyRotation(const glm::mat4 &transform);

    private:
        glm::mat4 m_perspective;
        glm::vec3 m_focusPoint;
        glm::vec3 m_position;
        glm::vec3 m_forward;
        glm::vec3 m_up;


    };
}


#endif //CGPROJECT_CAMERA_H
