//
// Created by Ashish Aapan on 13/10/15.
//

#ifndef CGPROJECT_TRANSFORMDATA_H
#define CGPROJECT_TRANSFORMDATA_H

#include <glm/glm.hpp>
class TransformData {






public:
    TransformData(const glm::vec3& pos = glm::vec3(),const glm::vec3& rot = glm::vec3(),const glm::vec3& scale = glm::vec3(1.0,1.0,1.0));
    TransformData(const TransformData & other);
    TransformData & operator=(TransformData other);
    void swap(TransformData & other);
    ~TransformData();
    glm::mat4 GetModel()const;

    glm::vec3 &getM_pos()  {return m_pos;}
    glm::vec3 &getM_rot()  { return m_rot; }
    glm::vec3 &getM_scale() { return m_scale; }

    void setM_pos(const glm::vec3 &m_pos) { TransformData::m_pos = m_pos; }
    void setM_rot(const glm::vec3 &m_rot) { TransformData::m_rot = m_rot; }
    void setM_scale(const glm::vec3 &m_scale) { TransformData::m_scale = m_scale; }

private:
    glm::vec3 m_pos;
    glm::vec3 m_rot;
    glm::vec3 m_scale;

};


#endif //CGPROJECT_TRANSFORMDATA_H
