// 2017180011 ¹ÚÁ¤È¯
#ifndef GOAL_AVOID_CROSSFIRE_H
#define GOAL_AVOID_CROSSFIRE_H

#include "Goals/Goal_Composite.h"
#include "../Raven_Bot.h"
#include "Raven_Goal_Types.h"

class Goal_AvoidCrossfire : public Goal_Composite<Raven_Bot>
{
private:
    Vector2D m_vSafePosition;

public:
    Goal_AvoidCrossfire(Raven_Bot* pBot, const Vector2D& safePos)
        : Goal_Composite<Raven_Bot>(pBot, goal_avoid_crossfire), m_vSafePosition(safePos) {}

    void Activate() override; 
    int Process() override;
    void Terminate() override;
};

#endif
