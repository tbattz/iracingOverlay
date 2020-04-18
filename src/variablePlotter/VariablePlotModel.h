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
#include "VarSetup.h"


class VariablePlotModel : public CommonModel<float>, public CommonModel<double>, public CommonModel<int> {
public:
    // Constructor
    VariablePlotModel(unsigned int maxVectorLen, std::vector<VarSetup> varList);

    // Functions
    void setupVarList();

private:
    // Data
    std::vector<VarSetup> varList;

};


#endif //IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTMODEL_H
