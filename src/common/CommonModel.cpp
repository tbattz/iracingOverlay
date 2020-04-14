//
// Created by tbatt on 12/04/2020.
//


#include "CommonModel.h"

CommonModel::CommonModel(unsigned int maxVectorLen) {
    this->maxVectorLen = maxVectorLen;

    // Reserve vector sizes
    sessionTimeHist.reserve(maxVectorLen);
}

void CommonModel::setSessionTime(float newSessionTime) {
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

std::vector<float>* CommonModel::getSessionTimePt() {
    return &sessionTimeHist;
}

void CommonModel::incrementIndex() {
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

unsigned int CommonModel::getCurrStartIndex() {
    return (unsigned int)(this->currStartIndex);
}




