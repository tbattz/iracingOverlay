//
// Created by tbatt on 12/04/2020.
//

#include "ThrottleBrakeTraceModel.h"

ThrottleBrakeTraceModel::ThrottleBrakeTraceModel(unsigned int maxVectorLen) : CommonModel(maxVectorLen) {
    this->maxVectorLen = maxVectorLen;

    // Reserve vector sizes
    lapDistHist.reserve(maxVectorLen);
    throttleHist.reserve(maxVectorLen);
    brakeHist.reserve(maxVectorLen);
}

void ThrottleBrakeTraceModel::setLapDist(float newLapDist) {
    // Only add new elements if the vector isn't full
    if(lapDistHist.size() < lapDistHist.capacity()) {
        lapDistHist.push_back(newLapDist);
    } else {
        lapDistHist.at(currWriteIndex) = newLapDist;
    }
}

void ThrottleBrakeTraceModel::setThrottle(float newThrottle) {
    // Only add new elements if the vector isn't full
    if(throttleHist.size() < throttleHist.capacity()) {
        throttleHist.push_back(newThrottle);
    } else {
        throttleHist.at(currWriteIndex) = newThrottle;
    }
}

void ThrottleBrakeTraceModel::setBrake(float newBrake) {
    // Only add new elements if the vector isn't full
    if(brakeHist.size() < brakeHist.capacity()) {
        brakeHist.push_back(newBrake);
    } else {
        brakeHist.at(currWriteIndex) = newBrake;
    }
}

std::vector<float>* ThrottleBrakeTraceModel::getLapDistPt() {
    return &lapDistHist;
}

std::vector<float>* ThrottleBrakeTraceModel::getThrottlePt() {
    return &throttleHist;
}

std::vector<float>* ThrottleBrakeTraceModel::getBrakePt() {
    return &brakeHist;
}

