#include "AvoidCrossfireGoal_Evaluator.h"
#include "Goal_Think.h"
#include "Raven_Goal_Types.h"
#include "../Raven_Bot.h"
#include "misc/cgdi.h"

//------------------ CalculateDesirability ------------------------------------
//
//  ������ ũ�ν����̾� ��Ȳ���� �Ǵ��Ͽ� ������ ��ȯ.
//  ������ 0~1 ������ ���� ������, �������� ũ�ν����̾� ȸ�� ��ǥ�� �켱������ ����.
//
double AvoidCrossfireGoal_Evaluator::CalculateDesirability(Raven_Bot* pBot)
{
    double Desirability = 0.0;

    // ���� ������ ũ�ν����̾� ��Ȳ�� �ִ� ��츸 ���
    if (pBot->IsInCrossfireSituation())
    {
        const double Tweaker = 1.0; // �켱���� ���� ���
        Desirability = Tweaker * m_dCharacterBias;

        // ������ 1�� �ʰ����� �ʵ��� ����
        if (Desirability < 0.0) Desirability = 0.0;
        else if (Desirability > 1.0) Desirability = 1.0;
    }

    return Desirability;
}

//----------------------------- SetGoal ---------------------------------------
//
//  AvoidCrossfire ��ǥ�� �߰�.
//
void AvoidCrossfireGoal_Evaluator::SetGoal(Raven_Bot* pBot)
{
    Vector2D safePosition = pBot->CalculateSafePosition();
    pBot->GetBrain()->AddGoal_AvoidCrossfire(safePosition);
}

//-------------------------- RenderInfo ---------------------------------------
//
//  �� ����� ȭ�鿡 ���.
//
void AvoidCrossfireGoal_Evaluator::RenderInfo(Vector2D Position, Raven_Bot* pBot)
{
    gdi->TextAtPos(Position, "Avoid Crossfire: " + ttos(CalculateDesirability(pBot), 2));
}
