#include "common.h"

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", SetNoPtCollideInFamily);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", ResetNoPtCollideInFamily);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PHYSICS_CheckLineInWorld);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PHYSICS_CheckLineInWorldMask);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsCheckLinkedMove);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsDefaultLinkedMoveResponse);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsCheckGravity);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsDefaultGravityResponse);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsCheckEdgeGrabbing);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsDefaultEdgeGrabResponse);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsCheckSliding);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsUpdateTface);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsCheckBlockers);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsCheckSwim);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsDefaultCheckSwimResponse);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsForceSetWater);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsCheckLOS);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsCheckDropHeight);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsCheckDropOff);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsFollowWall);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsMoveLocalZClamp);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsMove);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsSetVelFromZRot);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PhysicsSetVelFromRot);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PHYSICS_SetVAndAFromRot);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PHYSICS_FindAFromDAndT);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PHYSICS_FindVFromAAndD);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PHYSICS_StopIfCloseToTarget);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PHYSICS_CheckForTerrainCollide);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PHYSICS_CheckForObjectCollide);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PHYSICS_CheckForValidMove);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PHYSICS_CheckFaceStick);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PHYSICS_CheckDontGrabEdge);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PHYSICS_GenericLineCheckSetup);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PHYSICS_GenericLineCheck);

INCLUDE_ASM("asm/nonmatchings/Game/PHYSICS", PHYSICS_GenericLineCheckMask);
