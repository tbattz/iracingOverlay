//
// Created by tbatt on 12/04/2020.
//



#include <openGLPlotLive/src/lines/Line2D2CircularVecs.h>
#include "TrackMapView.h"



TrackMapView::TrackMapView(std::unordered_map<IDataStrings::VariableEnum, std::vector<float>*> varHistoryFloatPts, unsigned int pastSeconds)
        : GLPL::FramelessDraggableWindow(800, 600, true, true) {
        // Set background color
        this->setBackgroundColor(0.25f, 0.25f, 0.25f, 0.75f);
        this->pastSeconds = pastSeconds;

        // Create plot
        TrackMapView::setupPlot();

        // Create lines
        TrackMapView::setupLines(varHistoryFloatPts);

}

void TrackMapView::drawView(unsigned int currStartIndex) {
    // Pre-loop draw
    preLoopDraw(true);

    // Update internal data
    linePosition->updateInternalData(currStartIndex);

    // Draw Window
    myplot->Draw();

    // Post-loop draw
    postLoopDraw();
}

void TrackMapView::setupPlot() {
    myplot = std::make_shared<GLPL::Plot>(0.15, 0.1, 0.8, 0.85, static_cast<std::shared_ptr<IWindow>>(this));
    myplot->setPlotOutlineOn(false);
    myplot->getAxes()->setFontScaling(0.5);
    myplot->getAxes()->setEqualAxes(true);
    myplot->getAxes()->setAutoScale(true);
    myplot->getAxes()->setAutoScaleRound(false);
    myplot->getAxes()->setPositionSize(0.0, 0.0, 1.0, 1.0);
}

void
TrackMapView::setupLines(std::unordered_map<IDataStrings::VariableEnum, std::vector<float>*> varHistoryFloatPts) {
    // Setup lines
    std::vector<float>* posXPt = varHistoryFloatPts.at(IDataStrings::PositionX);
    std::vector<float>* posYPt = varHistoryFloatPts.at(IDataStrings::PositionY);
    linePosition = std::make_shared<GLPL::Line2D2CircularVecs<float, float>>(posXPt, posYPt);
    myplot->addLine(linePosition);
}
