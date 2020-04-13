//
// Created by tbatt on 11/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTCONTROLLER_H
#define IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTCONTROLLER_H


// Project Includes
#include <src/irData/IDataReceiver.h>
#include <src/irData/IRData.h>
#include <memory>
#include "VariablePlotModel.h"
#include "VariablePlotView.h"


enum IRDataType {
    IR_INT,
    IR_FLOAT,
    IR_DOUBLE
};


class VariablePlotController : public IDataReceiver {
public:
    // Constructor
    VariablePlotController(std::shared_ptr<IRData> irData, unsigned int pastSeconds, std::vector<std::pair<IRDataType, const char*>> varList);

    // Functions
    void updateData();
    void drawWindow();
    GLFWwindow* getWindow();

private:

    // Data
    std::vector<std::pair<IRDataType, const char*>> varList;
    std::shared_ptr<IRData> irData;
    
    // Model
    std::shared_ptr<VariablePlotModel> model;

    // View
    std::shared_ptr<VariablePlotView> view;

};


#endif //IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTCONTROLLER_H
