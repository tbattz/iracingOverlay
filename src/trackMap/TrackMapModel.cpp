//
// Created by tbatt on 12/04/2020.
//

#include <iostream>
#include "TrackMapModel.h"

TrackMapModel::TrackMapModel(unsigned int maxVectorLen) : CommonModel(maxVectorLen){
    this->maxVectorLen = maxVectorLen;

    // Reserve vector sizes
    CommonModel::addVar(VelocityX);
    CommonModel::addVar(VelocityY);
    CommonModel::addVar(VelocityZ);
    CommonModel::addVar(YawNorth);
    CommonModel::addVar(PositionX);
    CommonModel::addVar(PositionY);
    CommonModel::addVar(PositionZ);

    // Set initial position to zero
    CommonModel<float>::setVar(PositionX, 0.0);
    CommonModel<float>::setVar(PositionY, 0.0);
    CommonModel<float>::setVar(PositionZ, 0.0);
}

void TrackMapModel::setSessionTime(float newSessionTime) {
    CommonModel::setVar(SessionTime, newSessionTime);
    prevSessionTime = newSessionTime;
}

void TrackMapModel::setVelocity(glm::vec3 newVelocity) {
    // Only add new elements if the vector isn't full
    CommonModel<float>::setVar(VelocityX, newVelocity[0]);
    CommonModel<float>::setVar(VelocityY, newVelocity[1]);
    CommonModel<float>::setVar(VelocityZ, newVelocity[2]);
    prevVelocity = newVelocity;
}

void TrackMapModel::setYaw(float newYaw) {
    CommonModel<float>::setVar(YawNorth, newYaw);
    prevYaw = newYaw;
}

void TrackMapModel::setPosition(glm::dvec3 newPosition) {
    // Only add new elements if the vector isn't full
    CommonModel<float>::setVar(PositionX, newPosition[0]);
    CommonModel<float>::setVar(PositionY, newPosition[1]);
    CommonModel<float>::setVar(PositionZ, newPosition[2]);
    prevPosition = newPosition;
}

float TrackMapModel::getPrevSessionTime() {
    return prevSessionTime;
}

float TrackMapModel::getPrevYaw() {
    return prevYaw;
}

glm::vec3 TrackMapModel::getPrevVelocity() {
    return prevVelocity;
}

glm::vec3 TrackMapModel::getPrevPosition() {
    return prevPosition;
}




