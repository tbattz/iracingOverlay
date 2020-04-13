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
    bool foundData = false;
    switch(mode) {
        case MEMFILE: {
            foundData = client.waitForData(timeout);
            if (foundData) {
                IRData::parseClientData();
            }
            break;
        }
        case IBTFILE: {
            if(!diskClient.isFileOpen()) {
                // Try to open the file
                diskClient.openFile(path);
            }
            if(diskClient.isFileOpen()) {
                foundData = diskClient.getNextData();
            }
            if(foundData) {
                IRData::parseDiskClientData();
            }
            break;
        }
        default: {
            std::cout << "Undefined IRData mode!" << std::endl;
        }
    }
}

void IRData::parseClientData() {
    sessionTime = client.getVarFloat("SessionTime", 0);
    lapDist = client.getVarDouble("LapDist", 0);
    throttle = client.getVarFloat("Throttle", 0);
    brake = client.getVarFloat("Brake", 0);
    //std::cout << throttle << std::endl;
}

void IRData::parseDiskClientData() {
    sessionTime = diskClient.getVarDouble("SessionTime", 0);
    lapDist = diskClient.getVarFloat("LapDist", 0);
    throttle = diskClient.getVarFloat("Throttle", 0);
    brake = diskClient.getVarFloat("Brake", 0);
    //std::cout << throttle << std::endl;
}

int IRData::getTimeout() {
    return this->timeout;
}

float IRData::getSessionTime() {
    return sessionTime;
}

float IRData::getLapDist() {
    return lapDist;
}

float IRData::getThrottle() {
    return throttle;
}

float IRData::getBrake() {
    return brake;
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





