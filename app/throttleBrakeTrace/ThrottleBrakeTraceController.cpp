//
// Created by tbatt on 11/04/2020.
//


// Standard Includes
#include <utility>

// Project Includes
#include "ThrottleBrakeTraceController.h"


ThrottleBrakeTraceController::ThrottleBrakeTraceController(std::shared_ptr<IRData> irData, unsigned int pastSeconds) {
        // Setup IRacing Data
        this->irData = std::move(irData);
        unsigned int maxCount = ceil(1000.0 * pastSeconds/this->irData->getTimeout());

        // Create Model
        model = std::make_shared<ThrottleBrakeTraceModel>(maxCount);

        // Create view
        view = std::make_shared<ThrottleBrakeTraceView>(
                model->getSessionTimePt(),
                model->getThrottlePt(),
                model->getBrakePt());

}

void ThrottleBrakeTraceController::updateData() {
    // Update the vectors
    model->setSessionTime(irData->getSessionTime());
    model->setLapDist(irData->getLapDist());
    model->setThrottle(irData->getThrottle());
    model->setBrake(irData->getBrake());
    model->incrementIndex();
}

void ThrottleBrakeTraceController::drawWindow() {
    view->drawView(model->getCurrStartIndex());
}

GLFWwindow* ThrottleBrakeTraceController::getWindow() {
    return view->getWindow();
}
