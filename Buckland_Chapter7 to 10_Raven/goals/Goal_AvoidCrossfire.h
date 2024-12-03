#ifndef GOAL_AVOID_CROSSFIRE_H
#define GOAL_AVOID_CROSSFIRE_H

#include "Goals/Goal_Composite.h"
#include "../Raven_Bot.h"
#include "Raven_Goal_Types.h"

class Goal_AvoidCrossfire : public Goal_Composite<Raven_Bot>
{
private:
    Vector2D m_vSafePosition; // 안전한 위치를 저장

public:
    // 생성자: 봇과 안전한 위치를 설정
    Goal_AvoidCrossfire(Raven_Bot* pBot, const Vector2D& safePos)
        : Goal_Composite<Raven_Bot>(pBot, goal_avoid_crossfire), m_vSafePosition(safePos) {}

    // Goal 인터페이스 메서드 구현
    void Activate() override;  // 목표 활성화
    int Process() override;    // 목표 처리
    void Terminate() override; // 목표 종료
};

#endif
