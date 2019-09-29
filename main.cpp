#include "StatesHandler.h"
#include <iostream>

int main(int argc, char** argv)
{
    StatesHandler* statesHandler = new StatesHandler();

    std::cout << "Hello StatesHandler!" << std::endl;

    // 現在の状態を確認する
    statesHandler->checkStates();

    // 状態を通知する
    statesHandler->informStates();

    // 一部の状態を変更する
    statesHandler->setState(SAMPLE_STATE_B, true);
    statesHandler->setState(SAMPLE_STATE_C, true);
    std::cout << "States were changed" << std::endl;

    statesHandler->checkStates();

    statesHandler->informStates();

    return 0;
}

