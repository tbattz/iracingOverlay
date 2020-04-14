//
// Created by tbatt on 11/04/2020.
//


// Standard Includes
#include <utility>

// Project Includes
#include "TrackMapController.h"


TrackMapController::TrackMapController(std::shared_ptr<IRData> irData, unsigned int pastSeconds, std::vector<std::pair<IRDataType, const char*>> varList) {
        /* Displays the specified variables over the last x seconds. */
        // Setup IRacing Data
        this->irData = std::move(irData);
        this->varList = varList;
        unsigned int maxCount = ceil(1000.0 * pastSeconds/this->irData->getTimeout());

        // Create Model
        model = std::make_shared<TrackMapModel>(maxCount);

        // Create view
        view = std::make_shared<TrackMapView>(model->getPositionPt(), pastSeconds);

}

glm::vec3 TrackMapController::calculatePosition(glm::vec3 prevVelocity, glm::vec3 newVelocity, float deltaT, float prevYaw, glm::vec3 prevPosition) {
    // Calculate position offsets in body (vehicle) axes
    glm::vec3 posOffsets = (0.5f*deltaT)*(prevVelocity + newVelocity);
    // Rotate position offsets to be in world axes
    glm::vec3 rotPosOffsets = glm::rotate(posOffsets, -prevYaw, glm::vec3(0.0f, 0.0f, 1.0f));
    // Calculate new position
    glm::vec3 newPosition = prevPosition + rotPosOffsets;

    return newPosition;
}

void TrackMapController::updateData() {
    // Get previous values
    float prevYaw = model->getPrevYaw();
    glm::vec3 prevVelocity = model->getPrevVelocity();
    glm::vec3 prevPosition = model->getPrevPosition();
    // Update the vectors
    // Session Time
    float prevSessionTime = model->getPrevSessionTime();
    float newSessionTime = irData->getVarFloat(sessionTimeStr, 0);
    float deltaT = newSessionTime - prevSessionTime;
    model->TrackMapModel::setSessionTime(newSessionTime);
    // Velocity
    float velX = irData->getVarFloat(velXStr, 0);
    float velY = irData->getVarFloat(velYStr, 0);
    float velZ = irData->getVarFloat(velZStr, 0);
    glm::vec3 newVelocity = glm::vec3(velX, velY, velZ);
    model->setVelocity(newVelocity);
    // Yaw
    model->setYaw(irData->getVarFloat(yawStr, 0));
    // Calculate Position
    if(model->getSessionTimePt()->size() > 1) {
        glm::dvec3 newPosition = TrackMapController::calculatePosition(prevVelocity, newVelocity, deltaT, prevYaw,
                                                                      prevPosition);
        model->setPosition(newPosition);
    }

    // Increment the stored index
    model->incrementIndex();
}

void TrackMapController::drawWindow() {
    view->drawView(model->getCurrStartIndex());
}

GLFWwindow* TrackMapController::getWindow() {
    return view->getWindow();
}

void TrackMapController::showWindow() {
    return view->showWindow();
}

void TrackMapController::hideWindow() {
    return view->hideWindow();
}

