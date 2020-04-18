//
// Created by tbatt on 12/04/2020.
//

#include "ThrottleBrakeTraceModel.h"

ThrottleBrakeTraceModel::ThrottleBrakeTraceModel(unsigned int maxVectorLen) :
        CommonModel<float>(maxVectorLen), CommonModel<double>(maxVectorLen) {

    // Reserve vector sizes
    CommonModel<float>::addVar(SessionTime);
    CommonModel<float>::addVar(LapDist);
    CommonModel<float>::addVar(Throttle);
    CommonModel<float>::addVar(Brake);
    CommonModel<float>::addVar(LapDeltaToBestLap_DD);
}



