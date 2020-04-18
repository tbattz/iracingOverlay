//
// Created by tbatt on 11/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_IDATARECEIVER_H
#define IRACINGTRACEOVERLAY_PROJ_IDATARECEIVER_H

// Project Includes
#include "IDataStrings.h"


class IDataReceiver : public IDataStrings {
public:
    IDataReceiver();

    virtual void updateData() = 0;

};

#endif //IRACINGTRACEOVERLAY_PROJ_IDATARECEIVER_H
