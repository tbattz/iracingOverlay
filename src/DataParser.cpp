//
// Created by tbatt on 8/04/2020.
//


// Standard Includes
#include <windows.h>
#include <cstdio>

// for timeBeginPeriod
#pragma comment(lib, "Winmm")

// Project Includes
#include "DataParser.h"



DataParser::DataParser(int timeout) {
    this->timeout = timeout;
}

void DataParser::parserLoop() {
    // Wait for new data, copying it to a buffer
    if(irsdk_waitForDataReady(timeout, gData)) {
        const irsdk_header* pHeader = irsdk_getHeader();
        if(pHeader) {
            // If header changes in size, assumes a new connection
            if(!gData || gNData != pHeader->bufLen) {
                // Reallocate buffer to fit, lookup data offsets
                DataParser::initData(pHeader, gData, gNData);
            } else if (gData) {
                // We have some data
                if(counter++ % 1 == 0) {
                    DataParser::parseData(pHeader, gData);
                }
            }
        }
    } else if(!irsdk_isConnected()) {
        // Session has ended
        DataParser::endSession(false);
    }

}

void DataParser::initData(const irsdk_header *header, char* &data, int &nData)
{
    if(data) {
        delete [] data;
    }
    nData = header->bufLen;
    data = new char[nData];
}

void DataParser::parseData(const irsdk_header *header, const char *data) {
    if (header && data) {
        // Loop through headers
        double newTime = -1;
        float newThrottle = -1;
        float newBrake = -1;
        for(int i = 0; i < header->numVars; i++) {
            // Get entry
            const irsdk_varHeader *rec = irsdk_getVarHeaderEntry(i);

            // Check for required data
            if (!strcmp(rec->name, sessionTimeName)) {
                newTime = ((double *) (data + rec->offset))[0];
                printf("s: %0.5f", ((float *) (data + rec->offset))[0]);
            } else if (!strcmp(rec->name, throttleName)) {
                newThrottle = ((float *) (data + rec->offset))[0];
                printf("T: %0.5f", ((float *) (data + rec->offset))[0]);
            } else if (!strcmp(rec->name, brakeName)) {
                newBrake = ((float *) (data + rec->offset))[0];
                printf("B: %0.5f", ((float *) (data + rec->offset))[0]);
            }
        }
        printf("\n");

        if(startTime < 0) {
            startTime = newTime;
        }
        if (newTime > -1 && newThrottle > -1) {
            throttle.push_back((float)(newTime - startTime));
            throttle.push_back(newThrottle);
        }
        if (newTime > -1 && newBrake > -1) {
            brake.push_back((float)(newTime - startTime));
            brake.push_back(newBrake);
        }
        lastTime = (float)(newTime - startTime);
    }
}

void DataParser::endSession(bool shutdown)
{
    // Clean up pointer
    if(gData) {
        delete[] gData;
    }
    gData = NULL;

    // Shutdown connection
    if(shutdown)
    {
        irsdk_shutdown();
        timeEndPeriod(1);
    }
}

std::vector<float> *DataParser::getTimeVector() {
    return &time;
}

std::vector<float> *DataParser::getThrottleVector() {
    return &throttle;
}

std::vector<float> *DataParser::getBrakeVector() {
    return &brake;
}

void DataParser::setStartTime(float startTime) {
    this->startTime = startTime;
}





