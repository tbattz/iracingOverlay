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
        view = std::make_shared<ThrottleBrakeTraceView>(model->CommonModel<float>::getVarHistoryPts(), pastSeconds);
}

void ThrottleBrakeTraceController::updateData() {
    // Update the vectors
    model->CommonModel<float>::setVar(SessionTime, irData->getVarFloat(sessionTimeStr, 0));
    model->CommonModel<float>::setVar(LapDist, irData->getVarFloat(lapDist, 0));
    model->CommonModel<float>::setVar(Throttle, irData->getVarFloat(throttleStr, 0));
    model->CommonModel<float>::setVar(Brake, irData->getVarFloat(brakeStr, 0));
    model->CommonModel<float>::setVar(LapDeltaToBestLap_DD, irData->getVarFloat(deltaStr, 0));
    model->CommonModel<float>::incrementIndex();
}

void ThrottleBrakeTraceController::drawWindow() {
    view->drawView(model->CommonModel<float>::getCurrStartIndex());
}

GLFWwindow* ThrottleBrakeTraceController::getWindow() {
    return view->getWindow();
}

void ThrottleBrakeTraceController::showWindow() {
    return view->showWindow();
}

void ThrottleBrakeTraceController::hideWindow() {
    view->hideWindow();
}
