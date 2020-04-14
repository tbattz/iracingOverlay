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


enum IRDataType {
    IR_INT,
    IR_FLOAT,
    IR_DOUBLE
};

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
    float getVarFloat(const char* varName, int entry);
    double getVarDouble(const char* varName, int entry);
    int getVarInt(const char* varName, int entry);
    int getTimeout();
    bool isConnected();
    bool isCarOnTrack();
    void endSession();

private:
    // Functions
    void setupTiming();

    // Data
    // Strings
    const char* isCarOnTrackStr = "IsOnTrack";
    // Setup
    IRDataMode mode;
    int timeout = 16; // ms
    const char* path;
    // Clients
    irsdkClient& client = irsdkClient::instance();
    irsdkDiskClient diskClient = irsdkDiskClient();
};


#endif //IRSDK_DATAPARSER_H
