//
// Created by tbatt on 12/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_TRACKMAPMODEL_H
#define IRACINGTRACEOVERLAY_PROJ_TRACKMAPMODEL_H


// GLM Mathematics
#include <glm/vec3.hpp>

// Standard Includes
#include <vector>
#include <memory>

// Project Includes
#include <src/common/CommonModel.h>


class TrackMapModel : public CommonModel<float> {
public:
    // Constructor
    TrackMapModel(unsigned int maxVectorLen);

    // Functions
    void setSessionTime(float newSessionTime);
    void setVelocity(glm::vec3 newVelocity);
    void setYaw(float newYaw);
    void setPosition(glm::dvec3 newPosition);
    float getPrevSessionTime();
    float getPrevYaw();
    glm::vec3 getPrevVelocity();
    glm::vec3 getPrevPosition();

private:
    // Data
    float prevSessionTime = 0.0;
    float prevYaw = 0.0;
    glm::vec3 prevVelocity = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 prevPosition = glm::vec3(0.0f, 0.0f, 0.0f);
};


#endif //IRACINGTRACEOVERLAY_PROJ_TRACKMAPMODEL_H
