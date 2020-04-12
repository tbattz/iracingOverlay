//
// Created by tbatt on 11/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACECONTROLLER_H
#define IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACECONTROLLER_H


// Project Includes
#include <app/IDataReceiver.h>
#include <app/IRData.h>
#include <memory>
#include "ThrottleBrakeTraceModel.h"
#include "ThrottleBrakeTraceView.h"


class ThrottleBrakeTraceController : public IDataReceiver {
public:
    // Constructor
    ThrottleBrakeTraceController(std::shared_ptr<IRData> irData, unsigned int pastSeconds);

    // Functions
    void updateData();
    void drawWindow();
    GLFWwindow* getWindow();

private:
    // Functions

    // Data
    int maxCount;
    std::shared_ptr<IRData> irData;
    
    // Model
    ThrottleBrakeTraceModel model;

    // View
    ThrottleBrakeTraceView view;

};


#endif //IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACECONTROLLER_H
