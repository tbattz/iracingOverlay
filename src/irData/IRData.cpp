//
// Created by tbatt on 8/04/2020.
//

#define MIN_WIN_VER 0x0501

#ifndef WINVER
#	define WINVER			MIN_WIN_VER
#endif

#ifndef _WIN32_WINNT
#	define _WIN32_WINNT		MIN_WIN_VER
#endif

#pragma warning(disable:4996) //_CRT_SECURE_NO_WARNINGS


// Standard Includes
#include <windows.h>
#include <cstdio>
#include <iostream>

// for timeBeginPeriod
#pragma comment(lib, "Winmm")

// Project Includes
#include "IRData.h"



IRData::IRData() {
    this->mode = MEMFILE;
    IRData::setupTiming();
}

IRData::IRData(int timeout) {
    this->mode = MEMFILE;
    this->timeout = timeout;
    IRData::setupTiming();
}

IRData::IRData(const char* ibtFile) {
    this->mode = IBTFILE;
    this->path = ibtFile;
    IRData::setupTiming();
}

void IRData::setupTiming() {
    // Increase process priority to avoid sim taking all the cpu time
    SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);

    // Set minuimum resolution on periodic timers
    timeBeginPeriod(1);

}

void IRData::updateData() {
    switch(mode) {
        case MEMFILE: {
            client.waitForData(timeout);
            break;
        }
        case IBTFILE: {
            if(!diskClient.isFileOpen()) {
                // Try to open the file
                diskClient.openFile(path);
            }
            if(diskClient.isFileOpen()) {
                diskClient.getNextData();
            }
            break;
        }
        default: {
            std::cout << "Undefined IRData mode!" << std::endl;
        }
    }
}

float IRData::getVarFloat(const char* varName, int entry) {
    float value = 0;
    switch(mode) {
        case MEMFILE: {
            value = client.getVarFloat(varName, entry);
            break;
        }
        case IBTFILE: {
            value = diskClient.getVarFloat(varName, entry);
            break;
        }
        default: {
            std::cout << "Undefined IRData mode!" << std::endl;
        }
    }
    return value;
}

double IRData::getVarDouble(const char* varName, int entry) {
    double value = 0;
    switch(mode) {
        case MEMFILE: {
            value = client.getVarDouble(varName, entry);
            break;
        }
        case IBTFILE: {
            value = diskClient.getVarDouble(varName, entry);
            break;
        }
        default: {
            std::cout << "Undefined IRData mode!" << std::endl;
        }
    }
    return value;
}

int IRData::getVarInt(const char* varName, int entry) {
    int value = 0;
    switch(mode) {
        case MEMFILE: {
            value = client.getVarInt(varName, entry);
            break;
        }
        case IBTFILE: {
            value = diskClient.getVarInt(varName, entry);
            break;
        }
        default: {
            std::cout << "Undefined IRData model" << std::endl;
        }
    }
    return value;
}

int IRData::getTimeout() {
    return this->timeout;
}



bool IRData::isConnected() {
    switch(mode) {
        case MEMFILE: {
            return client.isConnected();
        }
        case IBTFILE: {
            return diskClient.isFileOpen();
        }
        default: {
            return false;
        }
    }
}

bool IRData::isCarOnTrack() {
    switch(mode) {
        case MEMFILE: {
            return (client.getVarInt(isCarOnTrackStr, 0) != 0);
        }
        case IBTFILE: {
            return (diskClient.getVarInt(isCarOnTrackStr, 0) != 0);
            break;
        }
        default: {
           return false;
        }
    }
}

void IRData::endSession() {
    switch(mode) {
        case MEMFILE: {
            break;
        }
        case IBTFILE: {
            diskClient.closeFile();
            break;
        }
        default: {
            break;
        }
    }
}





