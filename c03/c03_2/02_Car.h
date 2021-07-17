#ifndef __CAR_H__ // 헤더파일의 중복포함 문제를 해결하기 위한 매크로
#define __CAR_H__
#include <iostream> // string 자료형을 쓰기위해 필요
using namespace std; // 원래는 std::string임

namespace CAR_CONST{
    enum{
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
}

class Car{
    private:
        string gamerID;
        int fuelGauge;
        int curSpeed;

    public:
        void InitMembers(string ID, int fuel);
        void ShowCarState();
        void Accel();
        void Break();
};

#endif

// 클래스의 선언은 헤더에 저장.