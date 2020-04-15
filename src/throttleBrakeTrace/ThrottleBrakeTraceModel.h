//
// Created by tbatt on 12/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEMODEL_H
#define IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEMODEL_H


// Standard Includes
#include <vector>
#include <memory>

// Project Includes
#include "../common/CommonModel.h"


class ThrottleBrakeTraceModel : public CommonModel {
public:
    // Constructor
    ThrottleBrakeTraceModel(unsigned int maxVectorLen);

    // Functions
    void setLapDist(float newLapDist);
    void setThrottle(float newThrottle);
    void setBrake(float newBrake);
    void setDelta(float newDelta);
    std::vector<float>* getLapDistPt();
    std::vector<float>* getThrottlePt();
    std::vector<float>* getBrakePt();
    std::vector<float>* getDeltaPt();
    float getLastDelta();

private:
    // Data
    float lastDelta = 0;
    std::vector<float> lapDistHist;
    std::vector<float> throttleHist;
    std::vector<float> brakeHist;
    std::vector<float> deltaHist;
};


#endif //IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEMODEL_H
