//
// Created by tbatt on 11/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_TRACKMAPCONTROLLER_H
#define IRACINGTRACEOVERLAY_PROJ_TRACKMAPCONTROLLER_H


// Project Includes
#include <src/irData/IDataReceiver.h>
#include <src/irData/IRData.h>
#include <memory>
#include "TrackMapModel.h"
#include "TrackMapView.h"



class TrackMapController : public IDataReceiver {
public:
    // Constructor
    TrackMapController(std::shared_ptr<IRData> irData, unsigned int pastSeconds);

    // Functions
    glm::vec3 calculatePosition(glm::vec3 prevVelocity, glm::vec3 newVelocity, float deltaT, float prevYaw, glm::vec3 prevPosition);
    void updateData();
    void drawWindow();
    GLFWwindow* getWindow();
    void showWindow();
    void hideWindow();

private:
    // Data
    std::shared_ptr<IRData> irData;
    
    // Model
    std::shared_ptr<TrackMapModel> model;

    // View
    std::shared_ptr<TrackMapView> view;

};


#endif //IRACINGTRACEOVERLAY_PROJ_TRACKMAPCONTROLLER_H
