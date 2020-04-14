//
// Created by tbatt on 12/04/2020.
//


#include "VariablePlotView.h"



VariablePlotView::VariablePlotView(std::vector<float>* sessionTimePt, std::vector<std::vector<float>*> varPts, unsigned int pastSeconds)
        : GLPL::FramelessDraggableWindow(800, 600, true, true) {
        // Set background color
        this->setBackgroundColor(0.25f, 0.25f, 0.25f, 0.75f);
        this->pastSeconds = pastSeconds;

        // Create plot
        VariablePlotView::setupPlot();

        // Create lines
        VariablePlotView::setupLines(sessionTimePt, varPts);

}

void VariablePlotView::drawView(unsigned int currStartIndex) {
    // Pre-loop draw
    preLoopDraw(true);

    // Update data
    for(unsigned int i=0; i < lines.size(); i++) {
        if(lines[i])
        lines[i]->updateInternalData(currStartIndex);
    }
    if(!lines.empty()) {
        myplot->getAxes()->updateXAxesLimits(lines[0]->getMinMax()[1] - (float) pastSeconds, lines[0]->getMinMax()[1]);
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

void VariablePlotView::setupLines(std::vector<float>* sessionTimePt, std::vector<std::vector<float>*> varPts) {
    // Setup lines
    for(unsigned int i=0; i<varPts.size(); i++) {
        lines.push_back(std::make_shared<GLPL::Line2D2CircularVecs>(sessionTimePt, varPts[i]));
        lines[i]->setLineColour(lineColors[i]);

        // Add lines to axes
        myplot->addLine(lines[i]);
    }
}
