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

// 状態ID
enum STATE_ID {
    SAMPLE_STATE_A,
    SAMPLE_STATE_B,
    SAMPLE_STATE_C,
    SAMPLE_STATE_D,
    SAMPLE_STATE_NUM,
};

// 状態
typedef struct States_ {
    bool sample_state_a;
    bool sample_state_b;
    bool sample_state_c;
    bool sample_state_d;
} States_t;

// 状態と通知種別の対応
typedef struct StateKeyMap_ {
    const STATE_ID stateId;
    const char* key;
} StateKeyMap;

// 状態ハンドラクラス
class StatesHandler {

public:
    StatesHandler();
    States_t getStates();                                       // 現在の状態を取得する
    void setState(STATE_ID stateId, bool state);                // 状態をセットする
    void checkStates();                                         // 現在の状態を確認する
    void informStates();                                        // 状態を通知する

private:
    const char* getKey(const STATE_ID stateId);                 // 通知種別を取得する
    void beep(const char* key);                                 // 通知する

    static const StateKeyMap stateKeyMapList[SAMPLE_STATE_NUM]; // 状態通知対応リスト
    States_t currStates;                                        // 現在の状態
};

#endif //STATESHANDLER_H_
