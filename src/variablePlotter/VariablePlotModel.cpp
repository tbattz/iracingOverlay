//
// Created by tbatt on 12/04/2020.
//

#include <iostream>
#include "VariablePlotModel.h"

VariablePlotModel::VariablePlotModel(unsigned int maxVars, unsigned int maxVectorLen) {
    this->maxVectorLen = maxVectorLen;
    this->maxVars = maxVars;

    // Reserve vector sizes
    sessionTimeHist.reserve(maxVectorLen);
    vectorHist.reserve(maxVars); // Maximum 10 lines before vector pointers move and causes crash
    for(unsigned int i=0; i<maxVars; i++) {
        std::vector<float> newVec;
        vectorHist.push_back(newVec);
        vectorHist[i].reserve(maxVectorLen);
    }
}

void VariablePlotModel::setSessionTime(float newSessionTime) {
    if(sessionStartTime < 0) {
        sessionStartTime = newSessionTime;
    }
    // Only add new elements if the vector isn't full
    if(sessionTimeHist.size() < sessionTimeHist.capacity()) {
        sessionTimeHist.push_back(newSessionTime - sessionStartTime);
    } else {
        sessionTimeHist.at(currWriteIndex) = newSessionTime - sessionStartTime;
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

std::vector<float>* VariablePlotModel::getSessionTimePt() {
    return &sessionTimeHist;
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

void VariablePlotModel::incrementIndex() {
    // Update write index
    this->currWriteIndex += 1;
    if(currWriteIndex > maxVectorLen - 1) {
        currWriteIndex = 0;
    }
    // Update start index
    if(sessionTimeHist.size() < maxVectorLen ) {
        currStartIndex = 0;
    } else {
        currStartIndex = currWriteIndex;
    }
}

unsigned int VariablePlotModel::getCurrStartIndex() {
    return (unsigned int)(this->currStartIndex);
}




