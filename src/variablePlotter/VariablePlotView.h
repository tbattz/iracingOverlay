//
// Created by tbatt on 12/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTVIEW_H
#define IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTVIEW_H

// Standard Includes
#include <unordered_map>

// OpenGLPlotLive Includes
#include <openGLPlotLive/src/rendering/shader.h>
#include <openGLPlotLive/src/window/FramelessDraggableWindow.h>
#include <openGLPlotLive/src/plot/plot.h>
#include <openGLPlotLive/src/lines/Line2D2CircularVecs.h>

// Project Includes
#include <src/irData/IDataStrings.h>


class VariablePlotView : public GLPL::FramelessDraggableWindow, IDataStrings {
public:
    // Constructor
    VariablePlotView(std::unordered_map<VariableEnum, std::vector<float>*> varHistoryFloatPts,
                     std::unordered_map<VariableEnum, std::vector<double>*> varHistoryDoublePts,
                     std::unordered_map<VariableEnum, std::vector<int>*> varHistoryIntPts,
                     unsigned int pastSeconds);

    // Functions
    void drawView(unsigned int currStartIndex);

private:
    // Functions
    void setupPlot();
    template <typename T, typename U>
    void setupLine(std::vector<std::shared_ptr<GLPL::Line2D2CircularVecs<T, U>>>* linesType,
                   std::vector<float>* sessionTimePt,
                   std::unordered_map<VariableEnum, std::vector<U>*> varHistoryTPts);
    void setupLines(std::unordered_map<VariableEnum, std::vector<float>*> varHistoryFloatPts,
                    std::unordered_map<VariableEnum, std::vector<double>*> varHistoryDoublePts,
                    std::unordered_map<VariableEnum, std::vector<int>*> varHistoryIntPts);

    // Data
    unsigned int pastSeconds = 0;
    int lineCount = -1;
    std::shared_ptr<GLPL::Plot> myplot;
    std::vector<std::shared_ptr<GLPL::Line2D2CircularVecs<float, int>>> linesInt;
    std::vector<std::shared_ptr<GLPL::Line2D2CircularVecs<float, float>>> linesFloat;
    std::vector<std::shared_ptr<GLPL::Line2D2CircularVecs<float, double>>> linesDouble;
    std::vector<glm::vec3> lineColors = {LC_CYAN, LC_WHITE, LC_RED, LC_GREEN, LC_YELLOW,
                                            LC_CYAN, LC_WHITE, LC_RED, LC_GREEN, LC_YELLOW};

};


#endif //IRACINGTRACEOVERLAY_PROJ_VARIABLEPLOTVIEW_H
