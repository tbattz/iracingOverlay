//
// Created by tbatt on 8/04/2020.
//

#ifndef IRSDK_DATAPARSER_H
#define IRSDK_DATAPARSER_H

// IRacing SDK Includes
#include <irsdk/irsdk_defines.h>
#include <irsdk/irsdk_client.h>
#include <irsdk/irsdk_diskclient.h>

// Standard Includes
#include <minwindef.h>
#include <vector>



enum IRDataMode {
    MEMFILE,
    IBTFILE
};

class IRData {
public:
    // Constructor
    IRData();
    IRData(int timeout);
    IRData(const char* ibtFile);

    // Functions
    void updateData();
    void parseClientData();
    void parseDiskClientData();
    float getVarFloat(const char* varName, int entry);
    double getVarDouble(const char* varName, int entry);
    int getVarInt(const char* varName, int entry);
    int getTimeout();
    float getSessionTime();
    float getLapDist();
    float getThrottle();
    float getBrake();
    void endSession();

private:
    // Functions
    void setupTiming();

    // Data
    // Setup
    IRDataMode mode;
    unsigned int timeout = 16; // ms
    const char* path;
    // Clients
    irsdkClient& client = irsdkClient::instance();
    irsdkDiskClient diskClient = irsdkDiskClient();
    // Variables
    float sessionTime = 0;
    float lapDist = 0;
    float throttle = 0;
    float brake = 0;
};


#endif //IRSDK_DATAPARSER_H
