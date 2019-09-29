#include "StatesHandler.h"
#include <iostream>

// 状態通知対応リストの初期化
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
        case SAMPLE_STATE_A:
            currStates.sample_state_a = state;
            break;
        case SAMPLE_STATE_B:
            currStates.sample_state_b = state;
            break;
        case SAMPLE_STATE_C:
            currStates.sample_state_c = state;
            break;
        case SAMPLE_STATE_D:
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
        beep(getKey(SAMPLE_STATE_A));
    }
    if (currStates.sample_state_b) {
        beep(getKey(SAMPLE_STATE_B));
    }
    if (currStates.sample_state_c) {
        beep(getKey(SAMPLE_STATE_C));
    }
    if (currStates.sample_state_d) {
        beep(getKey(SAMPLE_STATE_D));
    }
}

const char* StatesHandler::getKey(const STATE_ID stateId)
{
    for (int i = 0; i < SAMPLE_STATE_NUM; ++i) {
        if (stateKeyMapList[i].stateId == stateId) {
            return stateKeyMapList[i].key;
        }
    }

    return nullptr;
}

void StatesHandler::beep(const char* key)
{
    std::cout << "Beep " << key << std::endl;
}

