#include "Goal_AvoidCrossfire.h"
#include "Goal_MoveToPosition.h"
#include "../navigation/Raven_PathPlanner.h"

void Goal_AvoidCrossfire::Activate()
{
    m_iStatus = active;

    // Remove any existing subgoals
    RemoveAllSubgoals();

    // Check if the bot is in a crossfire situation
    if (m_pOwner->IsInCrossfireSituation())
    {
        // Calculate a safe position to avoid crossfire
        m_vSafePosition = m_pOwner->CalculateSafePosition();

        // Add a subgoal to move to the safe position
        AddSubgoal(new Goal_MoveToPosition(m_pOwner, m_vSafePosition));
    }
    else
    {
        // If not in crossfire, mark the goal as completed
        m_iStatus = completed;
    }
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
