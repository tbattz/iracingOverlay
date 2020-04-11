//
// Created by tbatt on 8/04/2020.
//

#ifndef IRSDK_DATAPARSER_H
#define IRSDK_DATAPARSER_H

// IRacing SDK Includes
#include "../irsdk/irsdk_defines.h"

// Standard Includes
#include <minwindef.h>
#include <vector>


class IRData {
public:
    // Constructor
    IRData();

    // Functions
    void parserLoop();
    void endSession(bool shutdown);
    std::vector<float>* getTimeVector();
    std::vector<float>* getThrottleVector();
    std::vector<float>* getBrakeVector();
    void setStartTime(float startTime);

    float lastTime = 0;

private:
    // Functions
    void initData(const irsdk_header *header, char* &data, int &nData);
    void parseData(const irsdk_header *header, const char *data);

    // Parsing Data
    int timeout = 16; // ms
    char* gData = NULL;
    int gNData = 0;
    int counter = 0;
    double startTime = -1;
    char sessionTimeName[32] = "SessionTime";
    char throttleName[32] = "Throttle";
    char brakeName[32] = "Brake";
    // Stored data
    std::vector<float> time;
    std::vector<float> throttle;
    std::vector<float> brake;
};


#endif //IRSDK_DATAPARSER_H
