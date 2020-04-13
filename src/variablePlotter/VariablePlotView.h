//
// Created by tbatt on 12/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTVIEW_H
#define IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTVIEW_H


#include <openGLPlotLive/src/rendering/shader.h>
#include <openGLPlotLive/src/window/FramelessDraggableWindow.h>
#include <openGLPlotLive/src/plot/plot.h>
#include <openGLPlotLive/src/lines/Line2D2CircularVecs.h>


class VariablePlotView : public GLPL::FramelessDraggableWindow {
public:
    // Constructor
    VariablePlotView(std::vector<float>* sessionTimePt, std::vector<std::vector<float>*> varPts, unsigned int pastSeconds);

    // Functions
    void drawView(unsigned int currStartIndex);

private:
    // Functions
    void setupPlot();
    void setupLines(std::vector<float>* sessionTimePt, std::vector<std::vector<float>*> varPts);

    // Data
    unsigned int pastSeconds = 0;
    std::shared_ptr<GLPL::Plot> myplot;
    std::vector<std::shared_ptr<GLPL::Line2D2CircularVecs>> lines;
    std::vector<glm::vec3> lineColors = {LC_CYAN, LC_WHITE, LC_RED, LC_GREEN, LC_YELLOW,
                                            LC_CYAN, LC_WHITE, LC_RED, LC_GREEN, LC_YELLOW};

};


#endif //IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTVIEW_H
