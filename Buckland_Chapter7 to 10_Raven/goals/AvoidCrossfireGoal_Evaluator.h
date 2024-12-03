#ifndef AVOID_CROSSFIRE_GOAL_EVALUATOR_H
#define AVOID_CROSSFIRE_GOAL_EVALUATOR_H
#pragma warning (disable:4786)

#include "Goal_Evaluator.h"
#include "../Raven_Bot.h"
#include "misc/Stream_Utility_Functions.h"

class AvoidCrossfireGoal_Evaluator : public Goal_Evaluator
{
public:
    AvoidCrossfireGoal_Evaluator(double bias) : Goal_Evaluator(bias) {}

    // 평가 함수
    double CalculateDesirability(Raven_Bot* pBot) override;

    // 목표 설정
    void SetGoal(Raven_Bot* pBot) override;

    // 디버그 정보를 화면에 출력
    void RenderInfo(Vector2D Position, Raven_Bot* pBot) override;
};

#endif
