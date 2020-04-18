//
// Created by tbatt on 16/04/2020.
//

// GLFW (Multi-platform library for OpenGL)
#include <GLFW/glfw3.h>

// Standard Includes
#include <cstdio>
#include <iostream>
#include <cmath>

// Project Includes
#include "WheelInput.h"


WheelInput::WheelInput(bool printEvents) {
    this->printEvents = printEvents;

    // Find Joysticks
    WheelInput::findJoySticks();

    // Get initial states
    for(unsigned int i=0; i < foundJoystickIds.size(); i++) {
        // Buttons
        buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);
        prevButtons.push_back(WheelInput::copyArray<int>(buttons, buttonCount)); // Copy to avoid overwriting
        newButtons.push_back(WheelInput::copyArray<int>(buttons, buttonCount)); // Copy to avoid overwriting
        // Axes
        axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);
        prevAxes.push_back(WheelInput::copyArray<float>(axes, axesCount)); // Copy to avoid overwriting
        newAxes.push_back(WheelInput::copyArray<float>(axes, axesCount)); // Copy to avoid overwriting
    }
}

void WheelInput::checkForWheelInputs() {
    // Iterate through the joysticks
    for(unsigned int i=0; i < foundJoystickIds.size(); i++) {
        // Check the buttons
        WheelInput::checkButtonUpdates(i);

        // Check the axes
        WheelInput::checkAxesUpdates(i);
    }
}

void WheelInput::findJoySticks() {
    for(int i=0; i<GLFW_JOYSTICK_LAST; i++) {
        if(glfwJoystickPresent(i)) {
            if (printEvents) {
                printf("Found joystick %d\n", i);
            }
            foundJoystickIds.push_back(i);
        }
    }
    if (printEvents) {
        std::cout << std::endl;
    }
}

template <typename T, typename U>
std::vector<T> WheelInput::copyArray(const U *oldArray, int oldArraySize) {
    std::vector<T> newArray;
    for(int i=0; i<oldArraySize; i++) {
        newArray.push_back((T)oldArray[i]);
    }

    return newArray;
}

void WheelInput::checkButtonUpdates(int joystickId) {
    // Get the new buttons
    buttons = glfwGetJoystickButtons(joystickId, &buttonCount);

    // Copy to avoid overwriting
    newButtons[joystickId] = WheelInput::copyArray<int>(buttons, buttonCount);

    // Check button states
    for(unsigned int j=0; j < newButtons[joystickId].size(); j++) {
        if(newButtons[joystickId][j] != prevButtons[joystickId][j]) {
            if(newButtons[joystickId][j] == 1) {
                if(printEvents) {
                    printf("Joystick %i - Buttons %i pressed!\n", joystickId, j);
                }
            } else {
                if(printEvents) {
                    printf("Joystick %i - Buttons %i released!\n", joystickId, j);
                }
            }
        }
    }

    // Update previous array
    prevButtons[joystickId] = newButtons[joystickId];
}

void WheelInput::checkAxesUpdates(int joystickId) {
    // Get the new buttons
    axes = glfwGetJoystickAxes(joystickId, &axesCount);

    // Copy to avoid overwriting
    newAxes[joystickId] = WheelInput::copyArray<float>(axes, axesCount);

    // Check button states
    for(unsigned int j=0; j < newAxes[joystickId].size(); j++) {
        if(fabs(newAxes[joystickId][j] - prevAxes[joystickId][j]) > 1e-5) {
            if(printEvents) {
                printf("Joystick %i - Axes %i value: %.3f\n", joystickId, j, newAxes[joystickId][j]);
            }
        }
    }

    // Update previous array
    prevAxes[joystickId] = newAxes[joystickId];
}







