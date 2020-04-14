//
// Created by tbatt on 11/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_IDATARECEIVER_H
#define IRACINGTRACEOVERLAY_PROJ_IDATARECEIVER_H


class IDataReceiver {
public:
    IDataReceiver();

    virtual void updateData() = 0;

protected:
    // Data Strings
    const char* sessionTimeStr = "SessionTime";
    const char* throttleStr = "Throttle";
    const char* brakeStr = "Brake";
    const char* lapDist = "LapDist";
    const char* velXStr = "VelocityX";
    const char* velYStr = "VelocityY";
    const char* velZStr = "VelocityZ";
    const char* yawStr = "YawNorth";
};

#endif //IRACINGTRACEOVERLAY_PROJ_IDATARECEIVER_H
