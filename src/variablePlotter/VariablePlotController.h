//
// Created by tbatt on 11/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTCONTROLLER_H
#define IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTCONTROLLER_H

// Standard Includes
#include <memory>

// Project Includes
#include <src/irData/IDataReceiver.h>
#include <src/irData/IRData.h>

#include "VariablePlotModel.h"
#include "VariablePlotView.h"
#include "VarSetup.h"


class VariablePlotController : public IDataReceiver {
public:
    // Constructor
    VariablePlotController(std::shared_ptr<IRData> irData, unsigned int pastSeconds, std::vector<VarSetup> varList);

    // Functions
    void updateData();
    void drawWindow();
    GLFWwindow* getWindow();
    void showWindow();
    void hideWindow();

private:
    // Data
    std::vector<VarSetup> varList;
    std::shared_ptr<IRData> irData;
    
    // Model
    std::shared_ptr<VariablePlotModel> model;

    // View
    std::shared_ptr<VariablePlotView> view;

};


#endif //IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTCONTROLLER_H
