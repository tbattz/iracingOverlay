//
// Created by tbatt on 17/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_IDATASTRINGS_H
#define IRACINGTRACEOVERLAY_PROJ_IDATASTRINGS_H


class IDataStrings {
public:
    IDataStrings();

    // Data Strings
    const char* sessionTimeStr = "SessionTime";
    const char* throttleStr = "Throttle";
    const char* brakeStr = "Brake";
    const char* lapDist = "LapDist";
    const char* deltaStr = "LapDeltaToBestLap_DD";
    const char* velXStr = "VelocityX";
    const char* velYStr = "VelocityY";
    const char* velZStr = "VelocityZ";
    const char* yawStr = "YawNorth";
    const char* gear = "Gear";

    enum VariableEnum {
        SessionTime,
        Throttle,
        Brake,
        LapDist,
        LapDeltaToBestLap_DD,
        VelocityX,
        VelocityY,
        VelocityZ,
        YawNorth,
        Gear,
        PositionX,
        PositionY,
        PositionZ
    };

};


#endif //IRACINGTRACEOVERLAY_PROJ_IDATASTRINGS_H
