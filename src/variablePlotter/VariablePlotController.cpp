//
// Created by tbatt on 11/04/2020.
//


// Standard Includes
#include <utility>

// Project Includes
#include "VariablePlotController.h"


VariablePlotController::VariablePlotController(std::shared_ptr<IRData> irData, unsigned int pastSeconds, std::vector<VarSetup> varList) {
        /* Displays the specified variables over the last x seconds. */
        // Setup IRacing Data
        this->irData = std::move(irData);
        this->varList = varList;
        unsigned int maxCount = ceil(1000.0 * pastSeconds/this->irData->getTimeout());

        // Create Model
        model = std::make_shared<VariablePlotModel>(maxCount, varList);

        // Create view
        view = std::make_shared<VariablePlotView>(model->CommonModel<float>::getVarHistoryPts(),
                                                  model->CommonModel<double>::getVarHistoryPts(),
                                                  model->CommonModel<int>::getVarHistoryPts(),
                                                  pastSeconds);
}

void VariablePlotController::updateData() {
    // Update the vectors
    model->CommonModel<float>::setVar(SessionTime, irData->getVarFloat(sessionTimeStr, 0));
    for(unsigned int i=0; i < varList.size(); i++) {
        switch((varList[i]).irDataType) {
            case IR_INT: {
                model->CommonModel<int>::setVar(varList[i].varEnum, irData->getVarInt(varList[i].varString.c_str(), 0));
                break;
            }
            case IR_FLOAT: {
                model->CommonModel<float>::setVar(varList[i].varEnum,  irData->getVarFloat(varList[i].varString.c_str(), 0));
                break;
            }
            case IR_DOUBLE: {
                model->CommonModel<double>::setVar(varList[i].varEnum, irData->getVarDouble(varList[i].varString.c_str(), 0));
                break;
            }
            default: {}
        }
    }
    model->CommonModel<int>::incrementIndex();
    model->CommonModel<float>::incrementIndex();
    model->CommonModel<double>::incrementIndex();
}

void VariablePlotController::drawWindow() {
    view->drawView(model->CommonModel<float>::getCurrStartIndex());
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
