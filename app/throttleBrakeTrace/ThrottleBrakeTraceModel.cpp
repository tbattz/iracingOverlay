//
// Created by tbatt on 12/04/2020.
//

#include "ThrottleBrakeTraceModel.h"

ThrottleBrakeTraceModel::ThrottleBrakeTraceModel() {

}

void ThrottleBrakeTraceModel::setSessionTime(float newSessionTime) {
    if(sessionStartTime < 0) {
        sessionStartTime = newSessionTime;
    }
    sessionTimeHist.push_back(newSessionTime - sessionStartTime);
}

void ThrottleBrakeTraceModel::setLapDist(float newLapDist) {
    lapDistHist.push_back(newLapDist);
}

void ThrottleBrakeTraceModel::setThrottle(float newThrottle) {
    throttleHist.push_back(newThrottle);
}

void ThrottleBrakeTraceModel::setBrake(float newBrake) {
    brakeHist.push_back(newBrake);
}

std::vector<float> *ThrottleBrakeTraceModel::getSessionTimePt() {
    return &sessionTimeHist;
}

std::vector<float> *ThrottleBrakeTraceModel::getLapDistPt() {
    return &lapDistHist;
}

std::vector<float> *ThrottleBrakeTraceModel::getThrottlePt() {
    return &throttleHist;
}

std::vector<float> *ThrottleBrakeTraceModel::getBrakePt() {
    return &brakeHist;
}
