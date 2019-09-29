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
: currStates{0}
{}

bool StatesHandler::getState(STATE_NAME stateName)
{
    return currStates[stateName];
}

void StatesHandler::setState(STATE_NAME stateName, bool state)
{
    currStates[stateName] = state;
}

void StatesHandler::checkStates()
{
    std::cout << "sample_state_a : " << std::boolalpha << currStates[SAMPLE_STATE_A] << std::endl;
    std::cout << "sample_state_b : " << std::boolalpha << currStates[SAMPLE_STATE_B] << std::endl;
    std::cout << "sample_state_c : " << std::boolalpha << currStates[SAMPLE_STATE_C] << std::endl;
    std::cout << "sample_state_d : " << std::boolalpha << currStates[SAMPLE_STATE_D] << std::endl;
}

void StatesHandler::informStates()
{
    for (int i = 0; i < SAMPLE_STATE_NUM; ++i)
    {
        STATE_NAME stateName = (STATE_NAME)i;
        if (currStates[stateName])
        {
            const char* key = getKey(stateName);
            if (key != nullptr) beep(key);
        }
    }
}

const char* StatesHandler::getKey(const STATE_NAME stateName)
{
    for (int i = 0; i < SAMPLE_STATE_NUM; ++i)
    {
        if (stateKeyMapList[i].stateName == stateName)
        {
            return stateKeyMapList[i].key;
        }
    }

    return nullptr;
}

void StatesHandler::beep(const char* key)
{
    std::cout << "Beep " << key << std::endl;
}

