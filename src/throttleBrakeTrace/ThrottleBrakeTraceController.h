//
// Created by tbatt on 11/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACECONTROLLER_H
#define IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACECONTROLLER_H


// Project Includes
#include <src/irData/IDataReceiver.h>
#include <src/irData/IRData.h>
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
    void showWindow();
    void hideWindow();

private:
    // Functions

    // Data
    std::shared_ptr<IRData> irData;
    
    // Model
    std::shared_ptr<ThrottleBrakeTraceModel> model;

    // View
    std::shared_ptr<ThrottleBrakeTraceView> view;

};


#endif //IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACECONTROLLER_H
