//
// Created by tbatt on 12/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEVIEW_H
#define IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEVIEW_H


#include <openGLPlotLive/src/rendering/shader.h>
#include <openGLPlotLive/src/window/window.h>
#include <openGLPlotLive/src/plot/plot.h>
#include <openGLPlotLive/src/lines/Line2D2CircularVecs.h>


class ThrottleBrakeTraceView : public GLPL::Window {
public:
    // Constructor
    ThrottleBrakeTraceView(std::vector<float>* sessionTimePt,
                           std::vector<float>* throttlePt,
                           std::vector<float>* brakePt);

    // Functions
    void drawView(unsigned int currStartIndex);

private:
    // Functions
    void setupPlot();
    void setupLines(std::vector<float>* sessionTimePt,
                    std::vector<float>* throttlePt,
                    std::vector<float>* brakePt);

    // Data
    GLPL::Shader plot2dShader;
    GLPL::Shader textShader;
    std::shared_ptr<GLPL::Plot> myplot;
    std::shared_ptr<GLPL::Line2D2CircularVecs> lineThrottle;
    std::shared_ptr<GLPL::Line2D2CircularVecs> lineBrake;

};


#endif //IRACINGTRACEOVERLAY_PROJ_THROTTLEBRAKETRACEVIEW_H
