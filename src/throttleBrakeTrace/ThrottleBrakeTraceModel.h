//
// Created by tbatt on 12/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEMODEL_H
#define IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEMODEL_H


// Standard Includes
#include <vector>
#include <memory>

// Project Includes
#include "../common/CommonModel.h"


class ThrottleBrakeTraceModel : public CommonModel<float>, CommonModel<double> {
public:
    // Constructor
    ThrottleBrakeTraceModel(unsigned int maxVectorLen);

};


#endif //IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEMODEL_H
