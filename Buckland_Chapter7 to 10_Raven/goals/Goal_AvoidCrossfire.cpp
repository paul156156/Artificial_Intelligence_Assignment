#include "Goal_AvoidCrossfire.h"
#include "Goal_MoveToPosition.h"
#include "../navigation/Raven_PathPlanner.h"

void Goal_AvoidCrossfire::Activate()
{
    m_iStatus = active;

    // Remove any existing subgoals
    RemoveAllSubgoals();

    // Add a subgoal to move to the calculated safe position
    AddSubgoal(new Goal_MoveToPosition(m_pOwner, m_vSafePosition));
}

int Goal_AvoidCrossfire::Process()
{
    ActivateIfInactive();

    // Process the subgoals
    m_iStatus = ProcessSubgoals();

    // If the bot reaches the safe position, mark the goal as completed
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
