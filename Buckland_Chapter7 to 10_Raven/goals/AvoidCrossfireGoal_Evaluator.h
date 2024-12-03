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

    // �� �Լ�
    double CalculateDesirability(Raven_Bot* pBot) override;

    // ��ǥ ����
    void SetGoal(Raven_Bot* pBot) override;

    // ����� ������ ȭ�鿡 ���
    void RenderInfo(Vector2D Position, Raven_Bot* pBot) override;
};

#endif
