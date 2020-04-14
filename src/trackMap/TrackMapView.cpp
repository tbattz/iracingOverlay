//
// Created by tbatt on 12/04/2020.
//



#include "TrackMapView.h"



TrackMapView::TrackMapView(std::vector<glm::dvec3> *positionPt, unsigned int pastSeconds)
        : GLPL::FramelessDraggableWindow(800, 600, true, true) {
        // Set background color
        this->setBackgroundColor(0.25f, 0.25f, 0.25f, 0.75f);
        this->pastSeconds = pastSeconds;

        // Create plot
        TrackMapView::setupPlot();

        // Create lines
        TrackMapView::setupLines(positionPt);

}

void TrackMapView::drawView(unsigned int currStartIndex) {
    // Pre-loop draw
    preLoopDraw(true);

    // Update data
    linePosition->updateInternalData();

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
TrackMapView::setupLines(std::vector<glm::dvec3> *positionPt) {
    // Setup lines
    // TODO - Check if casting glm::dvec3 and glm::vec3 causes an issue
    linePosition = std::make_shared<GLPL::Line2DVecGLMV3>(positionPt, 0, 1);
    myplot->addLine(linePosition);
}
