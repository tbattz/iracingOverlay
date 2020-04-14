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
    std::vector<float>* getLapDistPt();
    std::vector<float>* getThrottlePt();
    std::vector<float>* getBrakePt();

private:
    // Data
    std::vector<float> lapDistHist;
    std::vector<float> throttleHist;
    std::vector<float> brakeHist;
};


#endif //IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEMODEL_H
