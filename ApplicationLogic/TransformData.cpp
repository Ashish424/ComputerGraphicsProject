//
// Created by Ashish Aapan on 13/10/15.
//

#include "TransformData.hpp"
#include <glm/gtx/transform.hpp>
#include <utility>
#include <QDebug>

TransformData::TransformData(const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec3 &scale):
        m_pos(pos),m_rot(rot),m_scale(scale)
{

}

TransformData::~TransformData() {

}

glm::mat4 TransformData::GetModel() const {
    glm::mat4 positionMatrix =  glm::translate(m_pos);
    glm::mat4 rotxMatrix = glm::rotate(m_rot.x,glm::vec3(1,0,0));
    glm::mat4 rotyMatrix = glm::rotate(m_rot.y,glm::vec3(0,1,0));
    glm::mat4 rotzMatrix = glm::rotate(m_rot.z,glm::vec3(0,0,1));
    glm::mat4 scaleMatrix = glm::scale(m_scale);
    glm::mat4 rotMatrix = rotzMatrix*rotyMatrix*rotxMatrix;
//    return rotMatrix*positionMatrix*scaleMatrix;
    return positionMatrix*rotMatrix*scaleMatrix;

}
TransformData::TransformData(const TransformData &other):m_pos(other.m_pos),m_scale(other.m_scale),m_rot(other.m_rot)
{

}




TransformData &TransformData::operator=(TransformData other) {
    this->swap(other);
    return *this;



}
void TransformData::swap(TransformData &other) {
    using std::swap;
    swap(this->m_pos, other.m_pos);
    swap(this->m_rot,other.m_rot);
    swap(this->m_scale,other.m_scale);


}
