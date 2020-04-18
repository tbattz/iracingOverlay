//
// Created by tbatt on 17/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_VARSETUP_H
#define IRACINGTRACEOVERLAY_PROJ_VARSETUP_H

// Standard Includes
#include <string>

// Project Includes
#include <src/irData/IDataStrings.h>
#include <src/irData/IRData.h>


struct VarSetup {
    IRDataType irDataType;
    std::string varString;
    IDataStrings::VariableEnum varEnum;
};


#endif //IRACINGTRACEOVERLAY_PROJ_VARSETUP_H
