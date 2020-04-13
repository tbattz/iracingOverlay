//
// Created by tbatt on 12/04/2020.
//


#include "ThrottleBrakeTraceView.h"



ThrottleBrakeTraceView::ThrottleBrakeTraceView(std::vector<float>* sessionTimePt,
                                               std::vector<float>* throttlePt,
                                               std::vector<float>* brakePt)
        : GLPL::Window(900, 125, true) {
        // Set background color
        this->setBackgroundColor(0.25f, 0.25f, 0.25f, 0.75f);
        //this->setFrameless(true);
        this->setAlwaysOnTop(true);

        // Create plot
        ThrottleBrakeTraceView::setupPlot();

        // Create lines
        ThrottleBrakeTraceView::setupLines(sessionTimePt, throttlePt, brakePt);

}

void ThrottleBrakeTraceView::drawView(unsigned int currStartIndex) {
    // Pre-loop draw
    preLoopDraw(true);

    // Update data
    lineThrottle->updateInternalData(currStartIndex);
    lineBrake->updateInternalData(currStartIndex);
    myplot->getAxes()->updateXAxesLimits(lineThrottle->getMinMax()[1] - 10, lineThrottle->getMinMax()[1]);

    // Draw Window
    myplot->Draw();

    // Post-loop draw
    postLoopDraw();
}

void ThrottleBrakeTraceView::setupPlot() {
    myplot = std::make_shared<GLPL::Plot>(0.0, 0.0, 1.0, 1.0, static_cast<std::shared_ptr<IWindow>>(this));
    myplot->setPlotOutlineOn(false);
    myplot->getAxes()->setXYAxesOn(false);
    myplot->getAxes()->setAutoScale(false);
    myplot->getAxes()->setPositionSize(0.0, 0.0, 1.0, 1.0);
    myplot->getAxes()->setAxesLabelsOn(false);
    myplot->getAxes()->setMajorTickSize(0.0);
    myplot->getAxes()->setMinorTickSize(0.0);
    myplot->getAxes()->updateYAxesLimits(0.0, 1.0);
    myplot->getAxes()->setAxesAreaOutlineOn(false);
}

void ThrottleBrakeTraceView::setupLines(std::vector<float>* sessionTimePt,
                                        std::vector<float>* throttlePt,
                                        std::vector<float>* brakePt) {
    // Setup lines
    lineThrottle = std::make_shared<GLPL::ShadedLine2D2CircularVecs>(sessionTimePt, throttlePt);
    lineThrottle->setShadeColour(LC_GREEN);
    lineThrottle->setOpacityRatio(opacityRatio);
    lineBrake = std::make_shared<GLPL::ShadedLine2D2CircularVecs>(sessionTimePt, brakePt);
    lineBrake->setShadeColour(LC_RED);
    lineBrake->setOpacityRatio(opacityRatio);

    // Add lines to axes
    myplot->addShadedLine(lineThrottle);
    myplot->addShadedLine(lineBrake);
}
