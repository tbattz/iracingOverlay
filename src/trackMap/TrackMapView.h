//
// Created by tbatt on 12/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_TRACKMAPVIEW_H
#define IRACINGTRACEOVERLAY_PROJ_TRACKMAPVIEW_H

// Standard Includes
#include <unordered_map>

// OpenGLPlotLive Includes
#include <openGLPlotLive/src/rendering/shader.h>
#include <openGLPlotLive/src/window/FramelessDraggableWindow.h>
#include <openGLPlotLive/src/plot/plot.h>
#include <openGLPlotLive/src/lines/Line2D2CircularVecs.h>

// Project Includes
#include <src/irData/IDataStrings.h>


class TrackMapView : public GLPL::FramelessDraggableWindow {
public:
    // Constructor
    TrackMapView(std::unordered_map<IDataStrings::VariableEnum, std::vector<float>*> varHistoryFloatPts, unsigned int pastSeconds);

    // Functions
    void drawView(unsigned int currStartIndex);

private:
    // Functions
    void setupPlot();
    void setupLines(std::unordered_map<IDataStrings::VariableEnum, std::vector<float>*> varHistoryFloatPts);

    // Data
    unsigned int pastSeconds = 0;
    std::shared_ptr<GLPL::Plot> myplot;
    std::shared_ptr<GLPL::Line2D2CircularVecs<float, float>> linePosition;
    std::vector<glm::vec3> lineColors = {LC_CYAN, LC_WHITE, LC_RED, LC_GREEN, LC_YELLOW,
                                            LC_CYAN, LC_WHITE, LC_RED, LC_GREEN, LC_YELLOW};

};


#endif //IRACINGTRACEOVERLAY_PROJ_TRACKMAPVIEW_H
