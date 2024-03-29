#ifndef STATESHANDLER_H_
#define STATESHANDLER_H_


// 通知種別
static const char* KEY_C = "Do";
static const char* KEY_D = "Re";
static const char* KEY_E = "Mi";
static const char* KEY_F = "Fa";
static const char* KEY_G = "Sol";
static const char* KEY_A = "La";
static const char* KEY_B = "Si";
static const char* KEY_X = "Xx";

// 状態名
enum STATE_NAME {
    SAMPLE_STATE_A = 0,
    SAMPLE_STATE_B,
    SAMPLE_STATE_C,
    SAMPLE_STATE_D,
    SAMPLE_STATE_NUM,
};

// 状態と通知種別の対応
typedef struct StateKeyMap_ {
    const STATE_NAME stateName;
    const char* key;
} StateKeyMap;

// 状態ハンドラクラス
class StatesHandler {

public:
    StatesHandler();
    bool getState(STATE_NAME stateName);                        // 現在の状態を取得する
    void setState(STATE_NAME stateName, bool state);            // 状態をセットする
    void checkStates();                                         // 現在の状態を確認する
    void informStates();                                        // 状態を通知する

private:
    const char* getKey(const STATE_NAME stateName);             // 通知種別を取得する
    void beep(const char* key);                                 // 通知する

    static const StateKeyMap stateKeyMapList[SAMPLE_STATE_NUM]; // 状態通知対応リスト
    bool currStates[SAMPLE_STATE_NUM];                          // 現在の状態
};

#endif //STATESHANDLER_H_
