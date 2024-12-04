// 2017180011 박정환
#include "AvoidCrossfireGoal_Evaluator.h"
#include "Goal_Think.h"
#include "Raven_Goal_Types.h"
#include "../Raven_Bot.h"
#include "misc/cgdi.h"

double AvoidCrossfireGoal_Evaluator::CalculateDesirability(Raven_Bot* pBot)
{
    double Desirability = 0.0;
    if (pBot->IsInCrossfireSituation())
    {
        double dangerLevel = pBot->GetCrossfireDangerLevel(); // 추가 메서드
        const double Tweaker = 2.0;

        Desirability = Tweaker * m_dCharacterBias * dangerLevel;

        Clamp(Desirability, 0.0, 1.0);
    }
    return Desirability;
}

void AvoidCrossfireGoal_Evaluator::SetGoal(Raven_Bot* pBot)
{
    Vector2D safePosition = pBot->CalculateSafePosition();
    pBot->GetBrain()->AddGoal_AvoidCrossfire(safePosition);
}

void AvoidCrossfireGoal_Evaluator::RenderInfo(Vector2D Position, Raven_Bot* pBot)
{
    gdi->TextAtPos(Position, "Avoid Crossfire: " + ttos(CalculateDesirability(pBot), 2));
}
