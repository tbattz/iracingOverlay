//
// Created by tbatt on 12/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTMODEL_H
#define IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTMODEL_H


// Standard Includes
#include <vector>
#include <memory>

// Project Includes
#include "../common/CommonModel.h"


class VariablePlotModel : public CommonModel {
public:
    // Constructor
    VariablePlotModel(unsigned int maxVars, unsigned int maxVectorLen);

    // Functions
    void setVariable(float newValue, unsigned int varIndex);
    std::vector<float>* getVarPointer(unsigned int varIndex);
    std::vector<std::vector<float>*> getVarPointers();

private:
    // Data
    unsigned int maxVars = 10;
    std::vector<std::vector<float>> vectorHist;

};


#endif //IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTMODEL_H
