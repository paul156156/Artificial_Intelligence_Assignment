// 2017180011 ¹ÚÁ¤È¯
#include "Goal_AvoidCrossfire.h"
#include "Goal_MoveToPosition.h"
#include "../navigation/Raven_PathPlanner.h"

void Goal_AvoidCrossfire::Activate()
{
    m_iStatus = active;

    RemoveAllSubgoals();

    if (m_pOwner->IsInCrossfireSituation())
    {
        m_vSafePosition = m_pOwner->CalculateSafePosition();

        AddSubgoal(new Goal_MoveToPosition(m_pOwner, m_vSafePosition));
    }
    else
    {
        m_iStatus = completed;
    }
}

int Goal_AvoidCrossfire::Process()
{
    ActivateIfInactive();

    m_iStatus = ProcessSubgoals();

    if (m_pOwner->isAtPosition(m_vSafePosition))
    {
        m_iStatus = completed;
    }

    return m_iStatus;
}

void Goal_AvoidCrossfire::Terminate()
{
    // Cleanup if needed
}
