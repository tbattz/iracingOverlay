//
// Created by tbatt on 12/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEMODEL_H
#define IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEMODEL_H


// Standard Includes
#include <vector>


class ThrottleBrakeTraceModel {
public:
    // Constructor
    ThrottleBrakeTraceModel();

    // Functions
    void setSessionTime(float newSessionTime);
    void setLapDist(float newLapDist);
    void setThrottle(float newThrottle);
    void setBrake(float newBrake);
    std::vector<float>* getSessionTimePt();
    std::vector<float>* getLapDistPt();
    std::vector<float>* getThrottlePt();
    std::vector<float>* getBrakePt();


private:
    // Data
    float sessionStartTime = -1;
    std::vector<float> sessionTimeHist;
    std::vector<float> lapDistHist;
    std::vector<float> throttleHist;
    std::vector<float> brakeHist;
};


#endif //IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEMODEL_H
