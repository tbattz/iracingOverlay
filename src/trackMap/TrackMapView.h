//
// Created by tbatt on 12/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_TRACKMAPVIEW_H
#define IRACINGTRACEOVERLAY_PROJ_TRACKMAPVIEW_H


#include <openGLPlotLive/src/rendering/shader.h>
#include <openGLPlotLive/src/window/FramelessDraggableWindow.h>
#include <openGLPlotLive/src/plot/plot.h>
#include <openGLPlotLive/src/lines/Line2DVecGLMV3.h>


class TrackMapView : public GLPL::FramelessDraggableWindow {
public:
    // Constructor
    TrackMapView(std::vector<glm::dvec3> *positionPt, unsigned int pastSeconds);

    // Functions
    void drawView(unsigned int currStartIndex);

private:
    // Functions
    void setupPlot();
    void setupLines(std::vector<glm::dvec3> *positionPt);

    // Data
    unsigned int pastSeconds = 0;
    std::shared_ptr<GLPL::Plot> myplot;
    std::shared_ptr<GLPL::Line2DVecGLMV3> linePosition;
    std::vector<glm::vec3> lineColors = {LC_CYAN, LC_WHITE, LC_RED, LC_GREEN, LC_YELLOW,
                                            LC_CYAN, LC_WHITE, LC_RED, LC_GREEN, LC_YELLOW};

};


#endif //IRACINGTRACEOVERLAY_PROJ_TRACKMAPVIEW_H
