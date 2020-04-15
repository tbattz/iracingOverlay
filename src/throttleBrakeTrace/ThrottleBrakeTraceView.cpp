//
// Created by tbatt on 12/04/2020.
//


#include "ThrottleBrakeTraceView.h"



ThrottleBrakeTraceView::ThrottleBrakeTraceView(std::vector<float>* sessionTimePt,
                                               std::vector<float>* throttlePt,
                                               std::vector<float>* brakePt,
                                               std::vector<float>* deltaPt,
                                               unsigned int pastSeconds)
        : GLPL::FramelessDraggableWindow(700, 80, true, true) {
        // Set background color
        this->setBackgroundColor(0.25f, 0.25f, 0.25f, 0.75f);
        this->pastSeconds = pastSeconds;

        // Create plot
        ThrottleBrakeTraceView::setupPlot();

        // Create lines
        ThrottleBrakeTraceView::setupLines(sessionTimePt, throttlePt, brakePt, deltaPt);

}

void ThrottleBrakeTraceView::drawView(unsigned int currStartIndex, float lastDelta) {
    // Pre-loop draw
    preLoopDraw(true);

    // Update data
    lineThrottle->updateInternalData(currStartIndex);
    lineBrake->updateInternalData(currStartIndex);
    lineDelta->updateInternalData(currStartIndex);
    plotTB->getAxes()->updateXAxesLimits(lineThrottle->getMinMax()[1] - (float)pastSeconds, lineThrottle->getMinMax()[1]);
    plotDelta->getAxes()->updateXAxesLimits(lineDelta->getMinMax()[1] - (float)pastSeconds, lineDelta->getMinMax()[1]);
    plotDelta->getAxes()->updateYAxesLimits(- 0.2f, 0.2f);

    // Draw Window
    plotTB->Draw();
    plotDelta->Draw();

    // Post-loop draw
    postLoopDraw();
}

void ThrottleBrakeTraceView::setupPlot() {
    plotTB = std::make_shared<GLPL::Plot>(0.0, 0.0, 1.0, 1.0, static_cast<std::shared_ptr<IWindow>>(this));
    plotTB->setPlotOutlineOn(false);
    plotTB->getAxes()->setXYAxesOn(false);
    plotTB->getAxes()->setAutoScale(false);
    plotTB->getAxes()->setPositionSize(0.0, 0.0, 1.0, 1.0);
    plotTB->getAxes()->setAxesLabelsOn(false);
    plotTB->getAxes()->setMajorTickSize(0.0);
    plotTB->getAxes()->setMinorTickSize(0.0);
    plotTB->getAxes()->updateYAxesLimits(0.0, 1.0);
    plotTB->getAxes()->setAxesAreaOutlineOn(false);

    plotDelta = std::make_shared<GLPL::Plot>(0.0, 0.0, 1.0, 1.0, static_cast<std::shared_ptr<IWindow>>(this));
    plotDelta->setPlotOutlineOn(false);
    plotDelta->getAxes()->setXYAxesOn(true);
    plotDelta->getAxes()->setAutoScale(false);
    plotDelta->getAxes()->setPositionSize(0.0, 0.0, 1.0, 1.0);
    plotDelta->getAxes()->setAxesLabelsOn(false);
    plotDelta->getAxes()->setMajorTickSize(0.0);
    plotDelta->getAxes()->setMinorTickSize(0.0);
    plotDelta->getAxes()->updateYAxesLimits(0.0, 1.0);
    plotDelta->getAxes()->setAxesAreaOutlineOn(false);

}

void ThrottleBrakeTraceView::setupLines(std::vector<float>* sessionTimePt,
                                        std::vector<float>* throttlePt,
                                        std::vector<float>* brakePt,
                                        std::vector<float>* deltaPt) {
    // Plot 1
    // Setup lines
    lineThrottle = std::make_shared<GLPL::ShadedLine2D2CircularVecs>(sessionTimePt, throttlePt);
    lineThrottle->setShadeColour(0.9*LC_GREEN);
    lineThrottle->setOpacityRatio(opacityRatio);
    lineBrake = std::make_shared<GLPL::ShadedLine2D2CircularVecs>(sessionTimePt, brakePt);
    lineBrake->setShadeColour(0.9*LC_RED);
    lineBrake->setOpacityRatio(opacityRatio);

    // Add lines to axes
    plotTB->addShadedLine(lineThrottle);
    plotTB->addShadedLine(lineBrake);

    // Plot 2
    // Setup lines
    lineDelta = std::make_shared<GLPL::Line2D2CircularVecsPosNeg>(sessionTimePt, deltaPt, posCol, negCol);
    lineDelta->setLineWidth(2);

    // Add lines to axes
    plotDelta->addPosNegLine(lineDelta);
}
