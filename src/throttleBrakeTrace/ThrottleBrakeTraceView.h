//
// Created by tbatt on 12/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEVIEW_H
#define IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEVIEW_H

// Standard Includes
#include <unordered_map>

// OpenGLPlotLive Includes
#include <openGLPlotLive/src/rendering/shader.h>
#include <openGLPlotLive/src/window/FramelessDraggableWindow.h>
#include <openGLPlotLive/src/plot/plot.h>
#include <openGLPlotLive/src/lines/Line2D2CircularVecsPosNeg.h>
#include <openGLPlotLive/src/shadedLines/ShadedLine2D2CircularVecs.h>

// Project Includes
#include <src/irData/IDataStrings.h>


class ThrottleBrakeTraceView : public GLPL::FramelessDraggableWindow, IDataStrings {
public:
    // Constructor
    ThrottleBrakeTraceView(std::unordered_map<VariableEnum, std::vector<float>*> varHistoryFloatPts, unsigned int pastSeconds);

    // Functions
    void drawView(unsigned int currStartIndex);

private:
    // Functions
    void setupPlot();
    void setupLines(std::unordered_map<VariableEnum, std::vector<float>*> varHistoryFloatPts);

    // Data
    float opacityRatio = 0.5;
    unsigned int pastSeconds = 0;
    glm::vec4 posCol = glm::vec4(1.0f, 1.0f, 0.0f, 1.0f);
    glm::vec4 negCol = glm::vec4(0.99f, 0.0f, 0.99f, 1.0f);
    std::shared_ptr<GLPL::Plot> plotTB;
    std::shared_ptr<GLPL::Plot> plotDelta;
    std::shared_ptr<GLPL::ShadedLine2D2CircularVecs> lineThrottle;
    std::shared_ptr<GLPL::ShadedLine2D2CircularVecs> lineBrake;
    std::shared_ptr<GLPL::Line2D2CircularVecsPosNeg> lineDelta;

};


#endif //IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEVIEW_H
