#include "StatesHandler.h"
#include <iostream>


const StateKeyMap StatesHandler::stateKeyMapList[] = {
    { SAMPLE_STATE_A, KEY_C },
    { SAMPLE_STATE_B, KEY_D },
    { SAMPLE_STATE_C, KEY_E },
    { SAMPLE_STATE_D, KEY_F },
};

StatesHandler::StatesHandler()
: currStates({0})
{}

States_t StatesHandler::getStates()
{
    return currStates;
}

void StatesHandler::setState(STATE_ID stateId, bool state)
{
    switch (stateId)
    {
        case 0:
            currStates.sample_state_a = state;
            break;
        case 1:
            currStates.sample_state_b = state;
            break;
        case 2:
            currStates.sample_state_c = state;
            break;
        case 3:
            currStates.sample_state_d = state;
            break;
        default:
            break;
    }
}

void StatesHandler::checkStates()
{
    std::cout << "sample_state_a : " << std::boolalpha << currStates.sample_state_a << std::endl;
    std::cout << "sample_state_b : " << std::boolalpha << currStates.sample_state_b << std::endl;
    std::cout << "sample_state_c : " << std::boolalpha << currStates.sample_state_c << std::endl;
    std::cout << "sample_state_d : " << std::boolalpha << currStates.sample_state_d << std::endl;
}

void StatesHandler::informStates()
{
    if (currStates.sample_state_a) {
        beep(stateKeyMapList[SAMPLE_STATE_A].key);
    }
    if (currStates.sample_state_b) {
        beep(stateKeyMapList[SAMPLE_STATE_B].key);
    }
    if (currStates.sample_state_c) {
        beep(stateKeyMapList[SAMPLE_STATE_C].key);
    }
    if (currStates.sample_state_d) {
        beep(stateKeyMapList[SAMPLE_STATE_D].key);
    }
}

void StatesHandler::beep(const char* key)
{
    std::cout << "Beep " << key << std::endl;
}

