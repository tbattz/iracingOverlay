//
// Created by tbatt on 16/04/2020.
//

#ifndef IRACINGTRACEOVERLAY_PROJ_WHEELINPUT_H
#define IRACINGTRACEOVERLAY_PROJ_WHEELINPUT_H

// Standard Includes
#include <vector>



class WheelInput {
public:
    // Constructor
    WheelInput(bool printEvents);

    // Functions
    void checkForWheelInputs();

private:
    // Functions
    void findJoySticks();
    template <typename T, typename  U>
    std::vector<T> copyArray(const U* oldArray, int oldArraySize);
    void checkButtonUpdates(int joystickId);
    void checkAxesUpdates(int joystickId);

    // Data
    bool printEvents;
    std::vector<int> foundJoystickIds;
    // Buttons
    int buttonCount = 0;
    const unsigned char* buttons;
    std::vector<std::vector<int>> prevButtons;
    std::vector<std::vector<int>> newButtons;
    // Axes
    int axesCount = 0;
    const float* axes;
    std::vector<std::vector<float>> prevAxes;
    std::vector<std::vector<float>> newAxes;

};


#endif //IRACINGTRACEOVERLAY_PROJ_WHEELINPUT_H
