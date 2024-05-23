#include "common.h"
#include "Game/STRMLOAD.h"

static LoadQueueEntry LoadQueue[40];

EXTERN STATIC int numLoads;

EXTERN STATIC int loadFromHead;

EXTERN STATIC LoadQueueEntry *loadFree;

EXTERN STATIC LoadQueueEntry *loadHead;

EXTERN STATIC LoadQueueEntry *loadTail;

void STREAM_NextLoadFromHead()
{
    loadFromHead = 1;
}

void STREAM_NextLoadAsNormal()
{
    loadFromHead = 0;
}

void STREAM_InitLoader(char *bigFileName, char *voiceFileName)
{
    int i;

    LOAD_InitCdLoader(bigFileName, voiceFileName);

    loadFree = (LoadQueueEntry *)&LoadQueue->next;

    loadHead = NULL;

    loadTail = NULL;

    numLoads = 0;

    for (i = 38; i >= 0; i--)
    {
        LoadQueue[i].next = &LoadQueue[i + 1];
    }

    LoadQueue[39].next = NULL;
}

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", STREAM_RemoveQueueHead);

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", STREAM_RemoveQueueEntry);

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", STREAM_AddQueueEntryToTail);

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", STREAM_AddQueueEntryToHead);

int STREAM_IsCdBusy(long *numberInQueue)
{
    if (numberInQueue != NULL)
    {
        *numberInQueue = numLoads;
    }

    return numLoads;
}

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", STREAM_PollLoadQueue);

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", STREAM_SetUpQueueEntry);

void STREAM_QueueNonblockingLoads(char *fileName, unsigned char memType, void *retFunc, void *retData, void *retData2, void **retPointer, long relocateBinary)
{
    LoadQueueEntry *currentEntry;
    int fromhead;

    fromhead = loadFromHead;

    loadFromHead = 0;

    currentEntry = STREAM_SetUpQueueEntry(fileName, retFunc, retData, retData2, retPointer, fromhead);

    currentEntry->loadEntry.loadAddr = NULL;

    currentEntry->mempackUsed = 1;

    currentEntry->loadEntry.memType = memType;

    currentEntry->relocateBinary = (char)relocateBinary;

    if (memType == 0)
    {
        currentEntry->status = 5;
    }
    else
    {
        currentEntry->status = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", LOAD_LoadToAddress);

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", LOAD_NonBlockingBinaryLoad);

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", LOAD_NonBlockingFileLoad);

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", LOAD_NonBlockingBufferedLoad);

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", LOAD_IsXAInQueue);

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", LOAD_PlayXA);

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", LOAD_ReadFile);

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", LOAD_ChangeDirectory);

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", LOAD_AbortDirectoryChange);

INCLUDE_ASM("asm/nonmatchings/Game/STRMLOAD", LOAD_AbortFileLoad);
