#include "common.h"
#include "Game/INSTANCE.h"
#include "Game/MONSTER/MONAPI.h"

INCLUDE_ASM("asm/nonmatchings/Game/MONSTER/HUMAN", HUMAN_WaitForWeapon);

INCLUDE_ASM("asm/nonmatchings/Game/MONSTER/HUMAN", HUMAN_CreateWeapon);

INCLUDE_ASM("asm/nonmatchings/Game/MONSTER/HUMAN", HUMAN_Init);

void HUMAN_CleanUp(Instance *instance)
{
    MON_CleanUp(instance);
}

INCLUDE_ASM("asm/nonmatchings/Game/MONSTER/HUMAN", HUMAN_Query);

void HUMAN_DeadEntry(Instance *instance)
{
    MonsterVars *mv;

    mv = (MonsterVars *)instance->extraData;

    mv->soulJuice /= 4;

    if (mv->soulJuice >= 4097)
    {
        mv->soulJuice = 4096;
    }

    MON_DeadEntry(instance);

    mv->damageTimer = MON_GetTime(instance);

    MON_BirthMana(instance);
}

INCLUDE_ASM("asm/nonmatchings/Game/MONSTER/HUMAN", HUMAN_Dead);

INCLUDE_ASM("asm/nonmatchings/Game/MONSTER/HUMAN", HUMAN_StunnedEntry);

INCLUDE_ASM("asm/nonmatchings/Game/MONSTER/HUMAN", HUMAN_Stunned);

INCLUDE_ASM("asm/nonmatchings/Game/MONSTER/HUMAN", HUMAN_EmbraceEntry);

INCLUDE_ASM("asm/nonmatchings/Game/MONSTER/HUMAN", HUMAN_Embrace);

INCLUDE_ASM("asm/nonmatchings/Game/MONSTER/HUMAN", HUMAN_IdleEntry);

INCLUDE_ASM("asm/nonmatchings/Game/MONSTER/HUMAN", HUMAN_Idle);

INCLUDE_ASM("asm/nonmatchings/Game/MONSTER/HUMAN", HUMAN_Flee);

INCLUDE_ASM("asm/nonmatchings/Game/MONSTER/HUMAN", HUMAN_GetAngry);

int HUMAN_TypeOfHuman(Instance *instance)
{
    int type;
    MonsterVars *mv;

    type = INSTANCE_Query(instance, 1);

    mv = (MonsterVars *)instance->extraData;

    if ((type & 0x4000))
    {
        return 1;
    }

    if ((type & 0x2000))
    {
        return 4;
    }

    if (!(type & 0x8000))
    {
        return 0;
    }

    if ((mv->auxFlags & 0x20))
    {
        return 3;
    }

    return 2;
}
