//
// Created by tbatt on 12/04/2020.
//

#include <iostream>
#include "TrackMapModel.h"

TrackMapModel::TrackMapModel(unsigned int maxVectorLen) : CommonModel(maxVectorLen){
    this->maxVectorLen = maxVectorLen;

    // Reserve vector sizes
    velocityHist.reserve(maxVectorLen);
    yawHist.reserve(maxVectorLen);
    positionHist.reserve(maxVectorLen);
}

void TrackMapModel::setSessionTime(float newSessionTime) {
    CommonModel::setSessionTime(newSessionTime);
    prevSessionTime = newSessionTime;
}


void TrackMapModel::setVelocity(glm::vec3 newVelocity) {
    // Only add new elements if the vector isn't full
    if(velocityHist.size() < velocityHist.capacity()) {
        velocityHist.push_back(newVelocity);
    } else {
        velocityHist.at(currWriteIndex) = newVelocity;
    }
    prevVelocity = newVelocity;
}

void TrackMapModel::setYaw(float newYaw) {
    // Only add new elements if the vector isn't full
    if(yawHist.size() < yawHist.capacity()) {
        yawHist.push_back(newYaw);
    } else {
        yawHist.at(currWriteIndex) = newYaw;
    }
    prevYaw = newYaw;
}

void TrackMapModel::setPosition(glm::dvec3 newPosition) {
    // Only add new elements if the vector isn't full
    if(positionHist.size() < positionHist.capacity()) {
        positionHist.push_back(newPosition);
    } else {
        positionHist.at(currWriteIndex) = newPosition;
    }
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

std::vector<glm::vec3>* TrackMapModel::getVelocityPt() {
    return &velocityHist;
}

std::vector<float>* TrackMapModel::getYawPt() {
    return &yawHist;
}

std::vector<glm::dvec3> *TrackMapModel::getPositionPt() {
    return &positionHist;
}


