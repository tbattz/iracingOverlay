//
// Created by tbatt on 12/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_COMMONMODEL_H
#define IRACINGTRACEOVERLAY_PROJ_COMMONMODEL_H


// GLM Mathematics
#include <glm/vec3.hpp>

// Standard Includes
#include <vector>
#include <memory>



class CommonModel {
public:
    // Constructor
    CommonModel(unsigned int maxVectorLen);

    // Functions
    void setSessionTime(float newSessionTime);
    std::vector<float>* getSessionTimePt();
    void incrementIndex();
    unsigned int getCurrStartIndex();

protected:
    // Data
    float sessionStartTime = -1;
    std::vector<float> sessionTimeHist;
    unsigned int maxVectorLen = -1;
    unsigned int currStartIndex = 0; // The current start of the vector to split for using constant length vectors
    unsigned int currWriteIndex = 0;

};


#endif //IRACINGTRACEOVERLAY_PROJ_COMMONMODEL_H
