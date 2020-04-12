// Standard Includes
#include <windows.h>
#include <cstdio>
#include <conio.h>
#include <csignal>
#include <algorithm>
#include <iostream>
#include <vector>


// GLFW (Multi-platform library for OpenGL)
#include <GLFW/glfw3.h>

// Standard Includes
#include <memory>
#include <thread>
#include <chrono>

// Project Includes
#include "IRData.h"
#include <openGLPlotLive/src/rendering/fonts.h>
#include <app/throttleBrakeTrace/ThrottleBrakeTraceController.h>


int main() {
    std::cout << "Starting IRacingOverlay Version 0.2." << std::endl;

    // Create IRData
    //std::shared_ptr<IRData> irData = std::shared_ptr<IRData>(new IRData());
    const char* filepath = "C:\\Users\\tbatt\\Documents\\iRacing\\telemetry\\dallaraf3_brandshatch indy 2020-04-09 21-32-00.ibt";
    std::shared_ptr<IRData> irData = std::shared_ptr<IRData>(new IRData(filepath));


    // Create ThrottleBrakeTrace Controller
    ThrottleBrakeTraceController throttleBrakeTraceController = ThrottleBrakeTraceController(irData, 10);


    // Check for no keystrokes
    while(!glfwWindowShouldClose(throttleBrakeTraceController.getWindow())) {
        // Update data
        irData->updateData();
        throttleBrakeTraceController.updateData();

        // Update Windows
        throttleBrakeTraceController.drawWindow();

        // Sleep for a little
        std::this_thread::sleep_for (std::chrono::milliseconds(10));
    }

    glfwTerminate();

    // exited with a keyboard hit
    printf("Shutting down.\n\n");

    // End connection
    irData->endSession();

    return 0;
}