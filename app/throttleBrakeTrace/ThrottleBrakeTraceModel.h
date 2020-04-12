//
// Created by tbatt on 12/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEMODEL_H
#define IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEMODEL_H


// Standard Includes
#include <vector>
#include <memory>


class ThrottleBrakeTraceModel {
public:
    // Constructor
    ThrottleBrakeTraceModel(unsigned int maxVectorLen);

    // Functions
    void setSessionTime(float newSessionTime);
    void setLapDist(float newLapDist);
    void setThrottle(float newThrottle);
    void setBrake(float newBrake);
    std::vector<float>* getSessionTimePt();
    std::vector<float>* getLapDistPt();
    std::vector<float>* getThrottlePt();
    std::vector<float>* getBrakePt();
    void incrementIndex();
    unsigned int getCurrStartIndex();


private:
    // Data
    float sessionStartTime = -1;
    unsigned int maxVectorLen = -1;
    unsigned int currStartIndex = 0; // The current start of the vector to split for using constant length vectors
    unsigned int currWriteIndex = 0;
    std::vector<float> sessionTimeHist;
    std::vector<float> lapDistHist;
    std::vector<float> throttleHist;
    std::vector<float> brakeHist;
};


#endif //IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEMODEL_H
