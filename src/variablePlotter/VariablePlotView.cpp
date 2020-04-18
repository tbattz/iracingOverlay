//
// Created by tbatt on 12/04/2020.
//


#include "VariablePlotView.h"

#include <utility>



VariablePlotView::VariablePlotView(std::unordered_map<VariableEnum, std::vector<float>*> varHistoryFloatPts,
                                   std::unordered_map<VariableEnum, std::vector<double>*> varHistoryDoublePts,
                                   std::unordered_map<VariableEnum, std::vector<int>*> varHistoryIntPts,
                                   unsigned int pastSeconds)
        : GLPL::FramelessDraggableWindow(800, 600, true, true) {
        // Set background color
        this->setBackgroundColor(0.25f, 0.25f, 0.25f, 0.75f);
        this->pastSeconds = pastSeconds;

        // Create plot
        VariablePlotView::setupPlot();

        // Create lines
        VariablePlotView::setupLines(std::move(varHistoryFloatPts), std::move(varHistoryDoublePts), std::move(varHistoryIntPts));

}

void VariablePlotView::drawView(unsigned int currStartIndex) {
    // Pre-loop draw
    preLoopDraw(true);

    // Update data
    // Ints
    for(unsigned int i=0; i < linesInt.size(); i++) {
        if(linesInt[i]) {
            linesInt[i]->updateInternalData(currStartIndex);
        }
    }
    // Floats
    for(unsigned int i=0; i < linesFloat.size(); i++) {
        if(linesFloat[i]) {
            linesFloat[i]->updateInternalData(currStartIndex);
        }
    }
    // Doubles
    for(unsigned int i=0; i < linesDouble.size(); i++) {
        if(linesDouble[i]) {
            linesDouble[i]->updateInternalData(currStartIndex);
        }

    }
    if(!linesFloat.empty()) {
        myplot->getAxes()->updateXAxesLimits(linesFloat[0]->getMinMax()[1] - (float) pastSeconds, linesFloat[0]->getMinMax()[1]);
    }

    // Draw Window
    myplot->Draw();

    // Post-loop draw
    postLoopDraw();
}

void VariablePlotView::setupPlot() {
    myplot = std::make_shared<GLPL::Plot>(0.15, 0.1, 0.8, 0.85, static_cast<std::shared_ptr<IWindow>>(this));
    myplot->setPlotOutlineOn(false);
    myplot->getAxes()->setFontScaling(0.5);
    myplot->getAxes()->setAutoScale(true);
    myplot->getAxes()->setPositionSize(0.0, 0.0, 1.0, 1.0);
}

template<typename T, typename U>
void VariablePlotView::setupLine(std::vector<std::shared_ptr<GLPL::Line2D2CircularVecs<T, U>>>* linesType,
                                 std::vector<float>* sessionTimePt,
                                 std::unordered_map<VariableEnum, std::vector<U>*> varHistoryTPts) {
    // Setup lines
    int i = -1;
    for(std::pair<VariableEnum, std::vector<U>*> element : varHistoryTPts) {
        if (element.first != SessionTime) {
            i += 1;
            lineCount += 1;
            linesType->push_back(std::make_shared<GLPL::Line2D2CircularVecs<T, U>>(sessionTimePt, element.second));
            linesType->at(i)->setLineColour(lineColors[lineCount]);

            // Add lines to axes
            myplot->addLine(linesType->at(i));
        }
    }
}

void VariablePlotView::setupLines(std::unordered_map<VariableEnum, std::vector<float>*> varHistoryFloatPts,
                                  std::unordered_map<VariableEnum, std::vector<double>*> varHistoryDoublePts,
                                  std::unordered_map<VariableEnum, std::vector<int>*> varHistoryIntPts) {

    std::vector<float>* sessionTimePt = varHistoryFloatPts.at(SessionTime);

    // Setup lines
    VariablePlotView::setupLine(&linesInt, sessionTimePt, varHistoryIntPts);
    VariablePlotView::setupLine(&linesFloat, sessionTimePt, varHistoryFloatPts);
    VariablePlotView::setupLine(&linesDouble, sessionTimePt, varHistoryDoublePts);
}



