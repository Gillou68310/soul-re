#include "common.h"

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_FillOutFileNames);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_AbortAreaLoad);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_Init);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", FindObjectName);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", FindObjectInTracker);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", FindStreamUnitFromLevel);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_LoadObjectReturn);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_DumpMonster);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_InList);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_IsSpecialMonster);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_DumpSomeMonsters);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_NoMonsters);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_YesMonsters);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_IsMonster);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_TryAndDumpANonResidentObject);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", InsertGlobalObject);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_GetObjectTracker);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", LoadLevelObjects);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_IsAnInstanceUsingObject);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_StreamLoadObjectAbort);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_DumpLoadingObjects);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_DumpObject);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_IsObjectInAnyUnit);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_RemoveAllObjectsNotInUse);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", RemoveAllObjects);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_GetLevelWithID);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_GetStreamUnitWithID);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_CalculateWaterLevel);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_IsMorphInProgress);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_GetWaterZLevel);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_SetMainFog);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_SetStreamFog);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_ConnectStream);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_StreamLoadLevelAbort);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_DoObjectLoadAndDump);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_FinishLoad);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_LoadLevelReturn);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_StreamLoadLevelReturn);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_UpdateLevelPointer);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_WhichUnitPointerIsIn);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_UpdateObjectPointer);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_UpdateInstanceCollisionInfo);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_LoadMainVram);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_MoveIntoNewStreamUnit);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_LoadLevel);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", RemoveIntroducedLights);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_RemoveInstancesWithIDInInstanceList);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_MarkUnitNeeded);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_DumpUnit);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_DumpAllUnitsNotNeeded);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_DumpAllLevels);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_LoadCurrentWarpRoom);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_RelocateLoadedWarpRooms);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_GetWarpRoomIndex);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_UpdateAddToArray);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_RemoveFromArray);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_Init);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_StartUsingWarpgate);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_EndUsingWarpgate);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_IsWarpgateInUse);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_IsWarpgateActive);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_IsWarpgateUsable);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_IsWarpgateReady);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_IsWarpgateSpectral);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_IsObjectOnWarpSide);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_IsItActive);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_IsUnitWarpRoom);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_FixUnit);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_MarkWarpUnitsNeeded);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_IncrementIndex);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_CalcWarpFade);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_DecrementIndex);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", PreloadAllConnectedUnits);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", RelocateLevel);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", RelocateCameras);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", RelocateSavedCameras);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", RelocateLevelWithInstances);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", RelocateTerrain);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", RelocateVMObjects);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", RelocateBGObjects);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", RelocatePlanPool);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", RelocatePlanMarkers);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", RelocateSFXMarkers);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_AdjustMultiSpline);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_RelocateInstance);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_OffsetInstancePosition);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_SetInstancePosition);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", RelocateInstances);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", RelocateStreamPortals);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_PackVRAMObject);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_SetupInstanceFlags);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_SetupInstanceListFlags);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_InMorphInstanceListFlags);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_InMorphDoFadeValues);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_UpdateTimeMult);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_UpdateNormals);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_BringBackNormals);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_AddOffsets);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_SubtractOffsets);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_GetComponentsForTrackingPoint);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_AveragePoint);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_UpdateTrackingPoint);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_ToggleMorph);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_DoStep);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_SetFog);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_UpdateTextures);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", MORPH_Continue);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_MORPH_Relocate);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", AddVertex);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", GetPlaneDist);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", CalcVert);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", AddClippedTri);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_GetClipRect);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", GetFogColor);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", DrawFogRectangle);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_RenderAdjacantUnit);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_GetBspTree);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_BlockWarpGateEntrance);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_DrawWarpGateRim);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_HideAllCloudCovers);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_UnHideCloudCoverInUnit);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_RenderWarpGate);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", WARPGATE_RenderWarpUnit);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_DumpNonResidentObjects);

INCLUDE_ASM("asm/nonmatchings/Game/STREAM", STREAM_TryAndDumpNonResident);
