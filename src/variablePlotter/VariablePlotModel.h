//
// Created by tbatt on 12/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTMODEL_H
#define IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTMODEL_H


// Standard Includes
#include <vector>
#include <memory>


class VariablePlotModel {
public:
    // Constructor
    VariablePlotModel(unsigned int maxVars, unsigned int maxVectorLen);

    // Functions
    void setSessionTime(float newSessionTime);
    void setVariable(float newValue, unsigned int varIndex);
    std::vector<float>* getSessionTimePt();
    std::vector<float>* getVarPointer(unsigned int varIndex);
    std::vector<std::vector<float>*> getVarPointers();
    void incrementIndex();
    unsigned int getCurrStartIndex();


private:
    // Data
    float sessionStartTime = -1;
    unsigned int maxVars = 10;
    std::vector<float> sessionTimeHist;
    std::vector<std::vector<float>> vectorHist;
    unsigned int maxVectorLen = -1;
    unsigned int currStartIndex = 0; // The current start of the vector to split for using constant length vectors
    unsigned int currWriteIndex = 0;

};


#endif //IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTMODEL_H
