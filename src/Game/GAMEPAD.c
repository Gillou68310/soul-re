#include "common.h"
#include "Game/GAMEPAD.h"
#include "Game/GAMELOOP.h"
#include "Game/FONT.h"
#include "Game/MENU/MENU.h"
#include "Game/LOCAL/LOCALSTR.h"

STATIC int gpSaved;

STATIC long overrideData[5][2];

STATIC long overrideCommand[5][2];

int gamePadControllerOut;

STATIC short dualshock_onflag;

STATIC int dualShock;

STATIC short align_flag;

STATIC int ignoreFind;

unsigned short psxData[2];

ControllerPacket readGPBuffer1;

ControllerPacket readGPBuffer2;

ControllerPacket gpbuffer1;

ControllerPacket gpbuffer2;

unsigned char controllerType[2];

unsigned short lastData[2];

long gDummyCommand[2][2];

STATIC long dualshock0_time;

STATIC long dualshock1_time;

unsigned char dualshock_motors[8924 + 2];

INCLUDE_ASM("asm/nonmatchings/Game/GAMEPAD", GAMEPAD_Commands);

int GAMEPAD_ControllerIsDualShock()
{
    return dualShock;
}

int GAMEPAD_DualShockEnabled()
{
    return dualshock_onflag;
}

// Matches 100% on decomp.me but differs on this project
#ifndef NON_MATCHING
INCLUDE_ASM("asm/nonmatchings/Game/GAMEPAD", GAMEPAD_DisableDualShock);
#else
void GAMEPAD_DisableDualShock()
{
    dualshock_onflag = 0;

    dualshock_motors[1] = 0;
    dualshock_motors[0] = 0;

    dualshock0_time = 0;
    dualshock1_time = 0;

    // PadSetAct(0, dualshock_motors, sizeof(dualshock_motors));
    PadSetAct(0, dualshock_motors, 2);
}
#endif

void GAMEPAD_EnableDualShock()
{
    dualshock_onflag = 1;

    align_flag = 0;
}

INCLUDE_ASM("asm/nonmatchings/Game/GAMEPAD", GAMEPAD_HandleDualShock);

void GAMEPAD_Shock(int motor0_speed, int motor0_time, int motor1_speed, int motor1_time)
{
    if (dualshock_onflag != 0)
    {
        dualshock0_time = motor0_time;
        dualshock_motors[0] = motor0_speed;

        dualshock1_time = motor1_time;
        dualshock_motors[1] = motor1_speed;

        // PadSetAct(0, dualshock_motors, sizeof(dualshock_motors));
        PadSetAct(0, dualshock_motors, 2);
    }
}

void GAMEPAD_Shock0(int motor0_speed, int motor0_time)
{
    if (dualshock_onflag != 0)
    {
        dualshock0_time = motor0_time;

        dualshock_motors[0] = motor0_speed;

        // PadSetAct(0, dualshock_motors, sizeof(dualshock_motors));
        PadSetAct(0, dualshock_motors, 2);
    }
}

void GAMEPAD_Shock1(int motor1_speed, int motor1_time)
{
    if (dualshock_onflag != 0)
    {
        dualshock1_time = motor1_time;

        dualshock_motors[1] = motor1_speed;

        // PadSetAct(0, dualshock_motors, sizeof(dualshock_motors));
        PadSetAct(0, dualshock_motors, 2);
    }
}

INCLUDE_ASM("asm/nonmatchings/Game/GAMEPAD", GAMEPAD_Detect);

void GAMEPAD_Init()
{
    PadInitDirect(&readGPBuffer1.transStatus, &readGPBuffer2.transStatus);

    PadStartCom();

    GAMEPAD_Detect();

    memset(&gDummyCommand, 0, sizeof(gDummyCommand));
    memset(&readGPBuffer1, 0, sizeof(readGPBuffer1));
    memset(&readGPBuffer2, 0, sizeof(readGPBuffer2));

    readGPBuffer1.data.pad = -1;
    readGPBuffer1.transStatus = 0;

    readGPBuffer2.data.pad = -1;
    readGPBuffer2.transStatus = 0;

    gpbuffer1.data.pad = -1;
    gpbuffer1.transStatus = 0;

    gpbuffer2.data.pad = -1;
    gpbuffer2.transStatus = 0;
}

INCLUDE_ASM("asm/nonmatchings/Game/GAMEPAD", PSXPAD_TranslateData);
// TODO: function needs .sdata migration to be implemented
/*void PSXPAD_TranslateData(long *data, unsigned short padData, unsigned short lastData)
{
    int i;
    JoypadMapping table[16] = {0x0010, 0x0001,
                               0x0040, 0x0002,
                               0x0080, 0x0004,
                               0x0020, 0x0008,
                               0x1000, 0x0010,
                               0x4000, 0x0080,
                               0x8000, 0x0020,
                               0x2000, 0x0040,
                               0x0400, 0x0100,
                               0x0100, 0x0400,
                               0x0800, 0x0200,
                               0x0200, 0x0800,
                               0x0002, 0x1000,
                               0x0004, 0x2000,
                               0x0008, 0x4000,
                               0x0001, 0x8000};
    unsigned short padButton;
    unsigned short logicalButton;

    for (i = 0; i < 16; i++)
    {
        padButton = table[i].psxData;

        logicalButton = table[i].translation;

        if (!(padData & padButton))
        {
            data[0] |= logicalButton;

            if ((lastData & padButton))
            {
                data[1] |= logicalButton;
            }
        }
        else if (!(lastData & padButton))
        {
            data[2] |= logicalButton;
        }
    }
}*/

unsigned short GAMEPAD_RemapAnalogueButtons(unsigned short in)
{
    in = ~in;

    return ~(((in & 0x800) << 1) | ((in & 0x400) << 5) | ((in & 0x200) << 1) | ((in & 0x8000) >> 6) | ((in & 0x1000) >> 1) | (in & 0x61F9));
}

void GAMEPAD_DetectInit()
{
    int orgdualshock_onflag;

    orgdualshock_onflag = dualshock_onflag;

    GAMEPAD_Detect();

    if ((dualShock != 0) && (orgdualshock_onflag != 0))
    {
        GAMEPAD_EnableDualShock();
    }
}

void GAMEPAD_GetData(long (*data)[5])
{
    long analogue_x;
    long analogue_y;
    int padState;
    int temp; // not from decls.h

    temp = ignoreFind;

    data[0][2] = 0;
    data[0][1] = 0;
    data[0][0] = 0;

    data[1][2] = 0;
    data[1][1] = 0;
    data[1][0] = 0;

    psxData[0] = 0;
    psxData[1] = 0;

    data[0][3] = 0;
    data[0][4] = 0;

    data[1][3] = 0;
    data[1][4] = 0;

    if (temp != 0)
    {
        memcpy(&gpbuffer1, &readGPBuffer1, sizeof(gpbuffer1));
        memcpy(&gpbuffer2, &readGPBuffer2, sizeof(gpbuffer2));
    }
    else
    {
        padState = PadGetState(0);

        if ((padState != PadStateFindPad) && (padState != PadStateReqInfo) && (padState != PadStateExecCmd))
        {
            GAMEPAD_HandleDualShock();

            memcpy(&gpbuffer1, &readGPBuffer1, sizeof(gpbuffer1));
            memcpy(&gpbuffer2, &readGPBuffer2, sizeof(gpbuffer2));
        }
        else if (padState == PadStateFindPad)
        {
            GAMEPAD_DetectInit();
        }
    }

    if (gpbuffer1.transStatus != 0xFF)
    {
        if (gamePadControllerOut >= 6)
        {
            GAMEPAD_DetectInit();
        }

        psxData[0] = gpbuffer1.data.pad;

        gamePadControllerOut = 0;

        if (controllerType[0] == 0x53)
        {
            psxData[0] = GAMEPAD_RemapAnalogueButtons(psxData[0]);
        }

        PSXPAD_TranslateData((long *)data, psxData[0], lastData[0]);

        controllerType[0] = gpbuffer1.dataFormat;

        lastData[0] = psxData[0];

        if ((gpbuffer1.dataFormat == 115) || (gpbuffer1.dataFormat == 83))
        {
            analogue_x = gpbuffer1.data.analogue.xL;
            analogue_y = gpbuffer1.data.analogue.yL;

            if ((analogue_x >= 74) && (analogue_x < 183) && (analogue_y >= 74) && (analogue_y < 183))
            {
                analogue_x = 128;
                analogue_y = 128;
            }

            data[0][3] = analogue_x - 128;
            data[0][4] = analogue_y - 128;
        }
    }
    else
    {
        gamePadControllerOut++;
    }
}

void GAMEPAD_DisplayControllerStatus(int msgY)
{
    char *noCtrlStr;

    if (gamePadControllerOut >= 6)
    {
        noCtrlStr = localstr_get(LOCALSTR_no_controller);

        FONT_FontPrintCentered(noCtrlStr, msgY);

        DisplayHintBox(FONT_GetStringWidth(noCtrlStr), msgY);
    }
}

void GAMEPAD_Process(GameTracker *gameTracker)
{
    GAMEPAD_GetData((long(*)[5])gameTracker->controlData);

    GAMEPAD_Commands((long(*)[5])gameTracker->controlCommand, (long(*)[5])gameTracker->controlData, 0);
    GAMEPAD_Commands((long(*)[5])gameTracker->controlCommand, (long(*)[5])gameTracker->controlData, 1);
}

void GAMEPAD_SaveControllers()
{
    gpSaved = 1;

    memcpy(&overrideCommand, &gameTrackerX.controlCommand, sizeof(overrideCommand));
    memcpy(&overrideData, &gameTrackerX.controlData, sizeof(overrideData));
}

void GAMEPAD_RestoreControllers()
{
    if (gpSaved != 0)
    {
        gpSaved = 0;

        memcpy(&gameTrackerX.controlData, &overrideData, sizeof(overrideData));
        memcpy(&gameTrackerX.controlCommand, &overrideCommand, sizeof(overrideCommand));

        gameTrackerX.controlCommand[0][0] |= 0x80;
    }
}
