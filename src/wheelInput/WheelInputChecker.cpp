//
// Created by tbatt on 16/04/2020.
//


// GLFW (Multi-platform library for OpenGL)
#include <GLFW/glfw3.h>

// Standard Includes
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

// Project Includes
#include "WheelInput.h"


int main(int argc, char* argv[]) {
    std::cout << "Starting IRacingOverlay Wheel Checker - Version 0.2" << std::endl;
    std::cout << "Press a key on the keyboard to exit." << std::endl;

    // Intialise glfw
    if(!glfwInit()) {
        std::cout << "GLFW Failed to Initialise." << std::endl;
        return 1;
    }

    // Initialise WheelInput
    WheelInput wheelInput = WheelInput(true);

    while(!kbhit()) {
        // Check for Wheel Input
        wheelInput.checkForWheelInputs();

        // Sleep for a little
        std::this_thread::sleep_for (std::chrono::milliseconds(1));
    }
}