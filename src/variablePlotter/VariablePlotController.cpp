//
// Created by tbatt on 11/04/2020.
//


// Standard Includes
#include <utility>

// Project Includes
#include "VariablePlotController.h"


VariablePlotController::VariablePlotController(std::shared_ptr<IRData> irData, unsigned int pastSeconds, std::vector<std::pair<IRDataType, const char*>> varList) {
        /* Displays the specified variables over the last x seconds. */
        // Setup IRacing Data
        this->irData = std::move(irData);
        this->varList = varList;
        unsigned int maxCount = ceil(1000.0 * pastSeconds/this->irData->getTimeout());
        unsigned int maxVars = varList.size();

        // Create Model
        model = std::make_shared<VariablePlotModel>(maxVars, maxCount);

        // Create view
        view = std::make_shared<VariablePlotView>(
                model->getSessionTimePt(),
                model->getVarPointers(),
                pastSeconds);

}

void VariablePlotController::updateData() {
    // Update the vectors
    model->setSessionTime(irData->getVarFloat(sessionTimeStr, 0));
    for(unsigned int i=0; i < varList.size(); i++) {
        switch(varList[i].first) {
            case IR_INT: {
                model->setVariable((float)irData->getVarInt(varList[i].second, 0), i);
                break;
            }
            case IR_FLOAT: {
                model->setVariable((float)irData->getVarFloat(varList[i].second, 0), i);
                break;
            }
            case IR_DOUBLE: {
                model->setVariable((float)irData->getVarDouble(varList[i].second, 0), i);
                break;
            }
            default: {}

        }

    }
    model->incrementIndex();
}

void VariablePlotController::drawWindow() {
    view->drawView(model->getCurrStartIndex());
}

GLFWwindow* VariablePlotController::getWindow() {
    return view->getWindow();
}

void VariablePlotController::showWindow() {
    return view->showWindow();
}

void VariablePlotController::hideWindow() {
    return view->hideWindow();

}
