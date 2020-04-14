//
// Created by tbatt on 12/04/2020.
//

#include <iostream>
#include "VariablePlotModel.h"

VariablePlotModel::VariablePlotModel(unsigned int maxVars, unsigned int maxVectorLen) : CommonModel(maxVectorLen) {
    this->maxVectorLen = maxVectorLen;
    this->maxVars = maxVars;

    // Reserve vector sizes
    sessionTimeHist.reserve(maxVectorLen);
    vectorHist.reserve(this->maxVars); // Maximum x lines before vector pointers move and causes crash
    for(unsigned int i=0; i<maxVars; i++) {
        std::vector<float> newVec;
        vectorHist.push_back(newVec);
        vectorHist[i].reserve(maxVectorLen);
    }
}

void VariablePlotModel::setVariable(float newValue, unsigned int varIndex) {
    // Only add new elements if the vector isn't full
    if(vectorHist[varIndex].size() < vectorHist[varIndex].capacity()) {
        vectorHist[varIndex].push_back(newValue);
    } else {
        vectorHist[varIndex].at(currWriteIndex) = newValue;
    }
}

std::vector<float>* VariablePlotModel::getVarPointer(unsigned int varIndex) {
    return &vectorHist[varIndex];
}

std::vector<std::vector<float>*> VariablePlotModel::getVarPointers() {
    std::vector<std::vector<float>*> varPt{};
    for(unsigned int i=0; i < vectorHist.size(); i++) {
        varPt.push_back(VariablePlotModel::getVarPointer(i));
    }
    return varPt;
}

