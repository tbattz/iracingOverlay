//
// Created by tbatt on 12/04/2020.
//


#include <iostream>
#include "CommonModel.h"

template <typename T>
CommonModel<T>::CommonModel(unsigned int maxVectorLen) {
    this->maxVectorLen = maxVectorLen;

    // Reserve vector sizes
    CommonModel::addVar(SessionTime);
}

template <typename T>
void CommonModel<T>::addVar(VariableEnum varName) {
    std::vector<T> varHist;
    varHistory.insert({varName, varHist});
    varHistory.at(varName).reserve(maxVectorLen);
    varHistoryPts.insert({varName, CommonModel::getPtVar(varName)});
}

template <typename T>
void CommonModel<T>::setVar(VariableEnum varName, T newVal) {
    // Handle specific cases
    if (varName == SessionTime) {
        if(sessionStartTime < 0) {
            sessionStartTime = newVal;
        }
        newVal = newVal - sessionStartTime;
    }

    // Only add new elements if the vector isn't full
    auto varHistIt = varHistory.find(varName);
    if(varHistIt->second.size() < varHistIt->second.capacity()) {
        varHistory.at(varName).push_back(newVal);
    } else {
        varHistory.at(varName).at(currWriteIndex) = newVal;
    }
}

template <typename T>
std::unordered_map<IDataStrings::VariableEnum, std::vector<T> *> CommonModel<T>::getVarHistoryPts() {
    return this->varHistoryPts;
}

template <typename T>
std::vector<T>* CommonModel<T>::getPtVar(VariableEnum varName) {
    return &(varHistory.at(varName));
}

template <typename T>
void CommonModel<T>::incrementIndex() {
    // Update write index
    this->currWriteIndex += 1;
    if(currWriteIndex > maxVectorLen - 1) {
        currWriteIndex = 0;
    }
    // Update start index
    auto sessionTimeHist = varHistory.at(SessionTime);
    if(sessionTimeHist.size() < maxVectorLen ) {
        currStartIndex = 0;
    } else {
        currStartIndex = currWriteIndex;
    }
}

template <typename T>
unsigned int CommonModel<T>::getCurrStartIndex() {
    return this->currStartIndex;
}


// Force the compiler to generate templates of these types - fixes undefined reference error
template class CommonModel<int>;
template class CommonModel<float>;
template class CommonModel<double>;




