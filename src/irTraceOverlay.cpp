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
#include <conio.h>
#include <csignal>
#include <algorithm>
#include <iostream>
#include <vector>

// IRacing SDK Includes
#include "../irsdk/irsdk_defines.h"

// Project Includes
#include "DataParser.h"


// GLFW (Multi-platform library for OpenGL)
#include <GLFW/glfw3.h>

// Standard Includes
#include <memory>

// Project Includes
#include <openGLPlotLive/src/rendering/fonts.h>
#include <openGLPlotLive/src/window/window.h>
#include <openGLPlotLive/src/plot/plot.h>
#include <openGLPlotLive/src/lines/Line2DVec.h>



bool stopLoop = false;

// exited with ctrl-c
void ex_program(int sig)
{
    (void)sig;

    printf("recieved ctrl-c, exiting\n\n");

    stopLoop = true;

    //signal(SIGINT, SIG_DFL);
    //exit(0);
}


int main() {
    std::cout << "Starting iracingTraceOverlay Version 0.1." << std::endl;

    // Trap ctrl+c to exit
    signal(SIGINT, ex_program);

    // Increase process priority to avoid sim taking all the cpu time
    SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);

    // Set minuimum resolution on periodic timers
    timeBeginPeriod(1);

    // Create IRData
    DataParser dataParser = DataParser();

    /* ======================================================
	 *                     Setup Window
	   ====================================================== */
    // Window Size
    int windowWidth  = 900;
    int windowHeight = 125;

    // Init GLFW
    std::shared_ptr<GLPL::IWindow> window = std::shared_ptr<GLPL::IWindow>(new GLPL::Window(windowWidth, windowHeight, 1));
    std::shared_ptr<GLPL::Window> window2 = std::dynamic_pointer_cast<GLPL::Window>(window);
    //window2->setFrameless(true);
    window2->setAlwaysOnTop(true);

    /* ======================================================
     *                  	  Shaders
       ====================================================== */
    // Setup and compile shaders
    GLPL::Shader plot2dShader("../../Shaders/plot2d.vs","../../Shaders/plot2d.frag");
    GLPL::Shader textShader("../../Shaders/font.vs", "../../Shaders/font.frag");

    /* ======================================================
	 *                	    Create Plot
	   ====================================================== */
    // Create Plot
    GLPL::Plot myplot(0.0, 0.0, 1.0, 1.0, window, &textShader);
    myplot.getAxes()->updateYAxesLimits(0.0, 1.0);

    // Create lines
    std::shared_ptr<GLPL::Line2DVec<float>> lineThrottle = std::shared_ptr<GLPL::Line2DVec<float>>(new GLPL::Line2DVec<float>(dataParser.getThrottleVector()));
    std::shared_ptr<GLPL::Line2DVec<float>> lineBrake = std::shared_ptr<GLPL::Line2DVec<float>>(new GLPL::Line2DVec<float>(dataParser.getBrakeVector()));
    lineThrottle->setLineColour(LC_GREEN);
    lineBrake->setLineColour(LC_RED);

    // Add lines to axes
    myplot.addLine(lineThrottle);
    myplot.addLine(lineBrake);


    // Check for no keystrokes
    while(!_kbhit()) {
        // Update data
        dataParser.parserLoop();

        // Pre-loop draw
        window2->preLoopDraw(true);

        // Update axes
        myplot.getAxes()->updateXAxesLimits(dataParser.lastTime - 10, dataParser.lastTime);

        // Draw Plot
        myplot.Draw(plot2dShader);

        // Post-loop draw
        window2->postLoopDraw();
    }

    // exited with a keyboard hit
    printf("Shutting down.\n\n");

    // End connection
    dataParser.endSession(true);

    return 0;
}