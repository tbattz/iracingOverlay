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
#include <unordered_map>

// Project Includes
#include <src/irData/IDataStrings.h>


template  <typename T>
class CommonModel : public IDataStrings {
public:
    // Constructor
    CommonModel(unsigned int maxVectorLen);

    // Functions
    void addVar(VariableEnum varName);
    void setVar(VariableEnum varName, T newVal);
    std::vector<T>* getPtVar(VariableEnum varName);
    void incrementIndex();
    unsigned int getCurrStartIndex();
    std::unordered_map<VariableEnum, std::vector<T>*> getVarHistoryPts();

protected:
    // Data
    float sessionStartTime = -1;
    unsigned int maxVectorLen = -1;
    unsigned int currStartIndex = 0; // The current start of the vector to split for using constant length vectors
    unsigned int currWriteIndex = 0;

    std::unordered_map<VariableEnum, std::vector<T>> varHistory;
    std::unordered_map<VariableEnum, std::vector<T>*> varHistoryPts;
};


#endif //IRACINGTRACEOVERLAY_PROJ_COMMONMODEL_H
