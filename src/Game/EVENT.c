#include "common.h"

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_UpdateResetSignalArrayAndWaterMovement);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ResetAllOneTimeVariables);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_AddSignalToReset);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", HINT_ResetHint);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", HINT_StartHint);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", HINT_StopHint);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", HINT_KillSpecificHint);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", HINT_GetCurrentHint);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ProcessTimers);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ProcessHints);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_GetNextTimer);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_RemoveTimer);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_InitTimers);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_InitTerrainMovement);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_Init);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_GetNextTerrainMove);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ProcessMovingWater);

void EVENT_DoProcess()
{
    EVENT_ProcessMovingWater();

    EVENT_ProcessTimers();
}

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_BSPProcess);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_Process);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ProcessPuppetShow);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ProcessEvents);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_IsConditionTrue);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_WriteEventObject);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ResolveObjectSignal);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ResolveObjectIntro);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ResolveSFXMarker);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_AddGameObjectToStack);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_AddPlayerObjectToStack);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_AddObjectToStack);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_AddCharPointerToStack);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_AddShortPointerToStack);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_AddNumberToStack);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ChangeOperandToNumber);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ChangeOperandVector3d);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_Addvector3dToStack);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ChangeOperandRotation3d);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_AddSubListObjectToStack);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_StackDuplicate);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformTGroupAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformConstrictAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformInstanceAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformSoundObjectAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_GetGameValue);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformGameAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformAreaAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformEventAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformSavedEventAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformSubListObjectAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformListObjectAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformCameraObjectAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformSplineAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformIntroAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ParseOperand2);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoVMObjectAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_GetVMObjectValue);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoGameAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoSignalAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformSignalAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformRotation3dAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformVector3dAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ModifyObjectToStackWithAttribute);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoInstanceAnimateTextureAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ResetAllSplineFlags);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_SetSplineLoop);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoSplineAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoAnimateAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoInstanceAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_GetTGroupValue);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoTGroupAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoCameraAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoObjectSoundAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoSoundMarkerAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_GetSoundValue);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoAreaAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoIntroAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoStackOperationEquals);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_CompareVector3d);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_CompareRotationVectors);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_CompareListWithOperation);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_CompareSubListWithOperation);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_CompareOperandsWithOperation);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoStackMathOperation);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ParseOpcode);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_GetIntroValue);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_DoSubListAction);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_GetInstanceValue);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_GetSplineFrameNumber);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_GetSplineValue);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_GetAnimateTextureValue);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_GetAnimateValue);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformObjectOnStack);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_UpdatePuzzlePointers);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_SaveEventsFromLevel);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_LoadEventsForLevel);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_CreateSaveEvent);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_RemoveInstanceFromInstanceList);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_UpdatePuzzleWithInstance);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_AddInstanceToInstanceList);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_FindVMObject);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_FixPuzzlesForStream);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_AddStreamToInstanceList);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_RemoveStreamToInstanceList);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_RelocateInstanceList);

void EVENT_PrintVars(void)
{
}

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_ExecuteActionCommand);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_GetScalerValueFromOperand);

INCLUDE_ASM("asm/nonmatchings/Game/EVENT", EVENT_TransformOperand);
