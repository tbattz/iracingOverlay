//
// Created by tbatt on 11/04/2020.
//


// Standard Includes
#include <utility>

// Project Includes
#include "ThrottleBrakeTraceController.h"


ThrottleBrakeTraceController::ThrottleBrakeTraceController(std::shared_ptr<IRData> irData, unsigned int pastSeconds) : model(),
    view(model.getSessionTimePt(), model.getThrottlePt(), model.getBrakePt()) {
        this->irData = std::move(irData);
        this->maxCount = ceil(1000.0 * pastSeconds/this->irData->getTimeout());
}

void ThrottleBrakeTraceController::updateData() {
    // Update the vectors
    model.setSessionTime(irData->getSessionTime());
    model.setLapDist(irData->getLapDist());
    model.setThrottle(irData->getThrottle());
    model.setBrake(irData->getBrake());
}

void ThrottleBrakeTraceController::drawWindow() {
    view.drawView();
}

GLFWwindow* ThrottleBrakeTraceController::getWindow() {
    return view.getWindow();
}
