//
// Created by tbatt on 12/04/2020.
//


#include "ThrottleBrakeTraceView.h"

#include <memory>



ThrottleBrakeTraceView::ThrottleBrakeTraceView(std::vector<float>* sessionTimePt,
                                               std::vector<float>* throttlePt,
                                               std::vector<float>* brakePt)
        : GLPL::Window(900, 125, true),
          plot2dShader("../../Shaders/plot2d.vs","../../Shaders/plot2d.frag"),
          textShader("../../Shaders/font.vs", "../../Shaders/font.frag")
        {
        // Set background color
        this->setBackgroundColor(0.25f, 0.25f, 0.25f, 0.75f);
        //this->setFrameless(true);
        this->setAlwaysOnTop(true);

        // Create plot
        ThrottleBrakeTraceView::setupPlot();

        // Create lines
        ThrottleBrakeTraceView::setupLines(sessionTimePt, throttlePt, brakePt);

}

void ThrottleBrakeTraceView::drawView() {
    // Pre-loop draw
    preLoopDraw(true);

    // Update data
    lineThrottle->updateInternalData();
    lineBrake->updateInternalData();
    myplot->getAxes()->updateXAxesLimits(lineThrottle->getMinMax()[1] - 10, lineThrottle->getMinMax()[1]);

    // Draw Window
    myplot->Draw(plot2dShader);

    // Post-loop draw
    postLoopDraw();
}

void ThrottleBrakeTraceView::setupPlot() {
    myplot = std::make_shared<GLPL::Plot>(0.0, 0.0, 1.0, 1.0, static_cast<std::shared_ptr<IWindow>>(this), &textShader);
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
    lineThrottle = std::make_shared<GLPL::Line2D2Vecs>(sessionTimePt, throttlePt);
    lineBrake = std::make_shared<GLPL::Line2D2Vecs>(sessionTimePt, brakePt);
    lineThrottle->setLineColour(LC_GREEN);
    lineBrake->setLineColour(LC_RED);

    // Add lines to axes
    myplot->addLine(lineThrottle);
    myplot->addLine(lineBrake);
}
