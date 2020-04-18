//
// Created by tbatt on 12/04/2020.
//

// Standard Includes
#include <iostream>
#include <utility>

// Project Includes
#include <src/irData/IRData.h>
#include "VariablePlotModel.h"


VariablePlotModel::VariablePlotModel(unsigned int maxVectorLen, std::vector<VarSetup> varList) :
        CommonModel<float>(maxVectorLen),
        CommonModel<double>(maxVectorLen),
        CommonModel<int>(maxVectorLen) {
    this->varList = std::move(varList);

    // Create variables
    VariablePlotModel::setupVarList();
}

void VariablePlotModel::setupVarList() {
    // Create the variables specified in the varList
    for(const auto& i : varList) {
        switch(i.irDataType) {
            case IR_INT: {
                CommonModel<int>::addVar(i.varEnum);
                break;
            }
            case IR_FLOAT: {
                CommonModel<float>::addVar(i.varEnum);
                break;
            }
            case IR_DOUBLE: {
                CommonModel<double>::addVar(i.varEnum);
                break;
            }
            default: {}
        }
    }
}



