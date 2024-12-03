#include "AvoidCrossfireGoal_Evaluator.h"
#include "Goal_Think.h"
#include "Raven_Goal_Types.h"
#include "../Raven_Bot.h"
#include "misc/cgdi.h"

//------------------ CalculateDesirability ------------------------------------
//
//  위험한 크로스파이어 상황인지 판단하여 점수를 반환.
//  점수는 0~1 사이의 값을 가지며, 높을수록 크로스파이어 회피 목표의 우선순위가 높음.
//
double AvoidCrossfireGoal_Evaluator::CalculateDesirability(Raven_Bot* pBot)
{
    double Desirability = 0.0;

    // 봇이 위험한 크로스파이어 상황에 있는 경우만 계산
    if (pBot->IsInCrossfireSituation())
    {
        const double Tweaker = 1.0; // 우선순위 조정 상수
        Desirability = Tweaker * m_dCharacterBias;

        // 점수가 1을 초과하지 않도록 제한
        if (Desirability < 0.0) Desirability = 0.0;
        else if (Desirability > 1.0) Desirability = 1.0;
    }

    return Desirability;
}

//----------------------------- SetGoal ---------------------------------------
//
//  AvoidCrossfire 목표를 추가.
//
void AvoidCrossfireGoal_Evaluator::SetGoal(Raven_Bot* pBot)
{
    Vector2D safePosition = pBot->CalculateSafePosition();
    pBot->GetBrain()->AddGoal_AvoidCrossfire(safePosition);
}

//-------------------------- RenderInfo ---------------------------------------
//
//  평가 결과를 화면에 출력.
//
void AvoidCrossfireGoal_Evaluator::RenderInfo(Vector2D Position, Raven_Bot* pBot)
{
    gdi->TextAtPos(Position, "Avoid Crossfire: " + ttos(CalculateDesirability(pBot), 2));
}
