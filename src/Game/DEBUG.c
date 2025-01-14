#include "common.h"
#include "Game/GAMELOOP.h"
#include "Game/SAVEINFO.h"
#include "Game/DEBUG.h"
#include "Game/RAZIEL/RAZIEL.h"
#include "Game/PSX/MAIN.h"
#include "Game/CAMERA.h"

// size: 0x8
typedef struct {
    // offset: 0000 (4 bytes)
    enum DEBUG_LINE_TYPE type;
    // offset: 0004
    void (*fn)();
}debug_dispatch_t;

// size: 0x10
typedef struct {
    // offset: 0000 (12 bytes)
    unsigned char cheatKeys[12];
    // offset: 000C
    short cheatLen;
    // offset: 000E
    short cheatStage;
}GameCheat;

void DEBUG_FillUpHealth(long *var);
void DEBUG_FogLoad();
void DEBUG_SetViewVram();
void DEBUG_KeepGameTime(long *var);
void DEBUG_SetGameTime(long *var);
void DEBUG_UpdateFog(long *var);
void DEBUG_FogRestore();
void DEBUG_UpdateHealth(long *var);
void DEBUG_UpdateMana(long *var);
void DEBUG_SendCinematicSwitch();
void DEBUG_LevelSelectNew();
void DEBUG_SendMoveTo();
void DEBUG_ReloadCurrentLevel();
void handle_line_type_bit(struct GameTracker *gt, DebugMenuLine *line);
void handle_line_type_long(struct GameTracker *gt, DebugMenuLine *line);
void handle_line_type_action(struct GameTracker *gt, DebugMenuLine *line);
void handle_line_type_action_with_line(struct GameTracker *gt, DebugMenuLine *line);
void handle_line_type_menu(struct GameTracker *gt, DebugMenuLine *line);

DebugMenuLine levelSelectMenu[];
DebugMenuLine debugRazielMenu[];
DebugMenuLine cameraMenu[];
DebugMenuLine fogMenu[];
DebugMenuLine debugHealthSystemMenu[];
DebugMenuLine debugSpecialAbilitiesMenu[];
DebugMenuLine debugForgedAbilitiesMenu[];
DebugMenuLine debugGlyphAbilitiesMenu[];
DebugMenuLine debugImbueSoulReaverMenu[];
DebugMenuLine mainMenu[];
DebugMenuLine BossAreasMenu[];
DebugMenuLine level2SelectMenu[];
DebugMenuLine pauseMenu[];

static char pauseFormatString[20] = "-abs 256 40 -center";
static char mainFormatString[20] = "-abs 160 40 -center";
static char *the_format_string = mainFormatString;
long menuPauseSel = 0;
long debug_cameraMode = 0xC;
long debugVoiceIndex = 0;
unsigned long debugTimeMult = 0x1000;
long debugFogFar = 0x2CEC;
long debugFogNear = 0x2904;
long debugGameTime = 0x4B0;
long debugFogRed = 0;
long debugFogGrn = 0;
long debugFogBlu = 0;
long debugHealthLevel = 1;
long debugManaLevel = 1;

DebugMenuLine standardMenu[] = {
    {DEBUG_LINE_TYPE_ACTION,  0, 0, "FILL ER UP", (long *)DEBUG_FillUpHealth, 0},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "keep info between loads", &gameTrackerX.streamFlags, 0x200000},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "LEVELS", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "SHORT SHORT STATS", &gameTrackerX.debugFlags, 0x04000000},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "RAZIEL MENU...", (long *)debugRazielMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "CAMERA MENU...", (long *)cameraMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "FOG MENU...", (long *)fogMenu, (long)DEBUG_FogLoad},
    {DEBUG_LINE_TYPE_ACTION,  0, 0, "VIEW VRAM", (long *)DEBUG_SetViewVram, 0},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Show Warp Gate Info", &gameTrackerX.debugFlags2, 0x01000000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Activate All WarpGates", &gameTrackerX.streamFlags, 0x400000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "MUSIC ON", &gameTrackerX.debugFlags2, 0x1000},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine saveMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "MAIN MENU...", (long *)standardMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  0, 0, "Save Current Game", (long *)SAVE_DebugSaveGame, 0},
    {DEBUG_LINE_TYPE_ACTION,  0, 0, "Restore Game", (long *)SAVE_LoadSaveGame, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine eventMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "MAIN MENU...", (long *)standardMenu, 0},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Show Event Vars", &gameTrackerX.debugFlags, 0x40000000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "SHOW EVENT DEBUG", &gameTrackerX.debugFlags2, 0x100},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "SHOW Spline Info", &gameTrackerX.debugFlags2, 0x400000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "SHOW GAME TIME", &gameTrackerX.debugFlags2, 0x10000},
    {DEBUG_LINE_TYPE_LONG,    0, 0x4000, "GAME TIME MULT", &gameTrackerX.multGameTime, (long)DEBUG_KeepGameTime},
    {DEBUG_LINE_TYPE_LONG,    0, 0x960, "SET GAME TIME", &debugGameTime, (long)DEBUG_SetGameTime},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Show Warp Gate Info", &gameTrackerX.debugFlags2, 0x01000000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Activate All WarpGates", &gameTrackerX.streamFlags, 0x400000},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine fogMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0,  0, "MAIN MENU...", (long *)standardMenu, 0},
    {DEBUG_LINE_TYPE_LONG,    -1, 0x2CEC,"FOG FAR", &debugFogFar, (long)DEBUG_UpdateFog},
    {DEBUG_LINE_TYPE_LONG,    -1, 0x2CEC,"FOG NEAR", &debugFogNear, (long)DEBUG_UpdateFog},
    {DEBUG_LINE_TYPE_LONG,    0,  0xFF,"FOG RED", &debugFogRed, (long)DEBUG_UpdateFog},
    {DEBUG_LINE_TYPE_LONG,    0,  0xFF,"FOG GREEN", &debugFogGrn, (long)DEBUG_UpdateFog},
    {DEBUG_LINE_TYPE_LONG,    0,  0xFF,"FOG BLUE", &debugFogBlu, (long)DEBUG_UpdateFog},
    {DEBUG_LINE_TYPE_ACTION,  0,  0, "RESTORE FOG", (long *)DEBUG_FogRestore, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0,  0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine goodiesMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "MAIN MENU...", (long *)standardMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "FOG MENU...", (long *)fogMenu, (long)DEBUG_FogLoad},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "SHRINK CELS", &gameTrackerX.debugFlags, 0x40},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "DECOUPLE", &gameTrackerX.decoupleGame, 1},
    {DEBUG_LINE_TYPE_LONG,    0, 2, "FRAME RATE LOCK", &gameTrackerX.frameRateLock, 0},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "IGNORE OBJECT SCRIPTS", &gameTrackerX.debugFlags, 0x10},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "C CODE", &gameTrackerX.debugFlags, 0x800},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "STOP ACTION", &gameTrackerX.debugFlags, 0x200000},
    {DEBUG_LINE_TYPE_ACTION,  0, 0, "VIEW VRAM", (long *)DEBUG_SetViewVram, 0},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "CAPTURE SCREEN", &gameTrackerX.debugFlags, 0x4000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "SIGNAL STATS", &gameTrackerX.debugFlags, 0x800000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "SIGNAL LOGIC VALUES", &gameTrackerX.debugFlags, 0x01000000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "NO OPTIONAL SIGNALS", &gameTrackerX.gameFlags, 0x40},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "VV STATS", &gameTrackerX.debugFlags, 0x02000000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "VOICE ON", &gameTrackerX.debugFlags, 0x80000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "SHOW MUSIC VARS", &gameTrackerX.debugFlags, 0x10000000},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine debugRazielMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "MAIN MENU...", (long *)standardMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "HEALTH SYSTEM    ...", (long *)debugHealthSystemMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Special Abilities...", (long *)debugSpecialAbilitiesMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Forged  Abilities...", (long *)debugForgedAbilitiesMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Glyph   Abilities...", (long *)debugGlyphAbilitiesMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "IMBUE SOUL REAVER...", (long *)debugImbueSoulReaverMenu, 0},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "SHIFT ANY TIME", &debugRazielFlags1, 0x50},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine debugHealthSystemMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "MAIN MENU...", (long *)standardMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "RAZIEL MENU...", (long *)debugRazielMenu, 0},
    {DEBUG_LINE_TYPE_LONG,    1, 4,"HEALTH LEVEL", &debugHealthLevel, (long)DEBUG_UpdateHealth},
    {DEBUG_LINE_TYPE_LONG,    1, 6,"MANA LEVEL", &debugManaLevel, (long)DEBUG_UpdateMana},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "INVINCIBLE", &gameTrackerX.debugFlags2, 0x100000},
    {DEBUG_LINE_TYPE_ACTION,  0, 0, "HURT RAZIEL", (long *)RAZIEL_DebugHurtRaziel, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine debugSpecialAbilitiesMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "MAIN MENU...", (long *)standardMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "RAZIEL MENU...", (long *)debugRazielMenu, 0},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "ALL", &debugRazielFlags1, 0x3F},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "PASS THROUGH BARRIERS", &debugRazielFlags1,1},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "WALL CRAWLING", &debugRazielFlags1, 0xB},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "FORCE", &debugRazielFlags1, 0xF},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "SOUL REAVER", &debugRazielFlags1,9},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "SWIM", &debugRazielFlags1, 0x1F},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "CONSTRICT", &debugRazielFlags1, 0x3F},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine debugForgedAbilitiesMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "MAIN MENU...", (long *)standardMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "RAZIEL MENU...", (long *)debugRazielMenu, 0},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "ALL", &debugRazielFlags1, 0x3FC00},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Spectral Reaver", &debugRazielFlags1, 0x400},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Material Reaver", &debugRazielFlags1, 0x800},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Fire Reaver", &debugRazielFlags1, 0x8000},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine debugGlyphAbilitiesMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "MAIN MENU...", (long *)standardMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "RAZIEL MENU...", (long *)debugRazielMenu, 0},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "ALL", &debugRazielFlags1, 0x01FC0000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Sunlight Glyph", &debugRazielFlags1, 0x400000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Water Glyph", &debugRazielFlags1, 0x200000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Fire Glyph", &debugRazielFlags1, 0x800000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Stone Glyph", &debugRazielFlags1, 0x80000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Force Glyph", &debugRazielFlags1, 0x40000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Sound Glyph", &debugRazielFlags1, 0x100000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Plane Shift Glyph", &debugRazielFlags1, 0x01000000},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine debugImbueSoulReaverMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "MAIN MENU...", (long *)standardMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "RAZIEL MENU...", (long *)debugRazielMenu, 0},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Hold Soul Reaver", &debugRazielFlags1, 8},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Spectral Reaver", &debugRazielFlags2, 0x400},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Material Reaver", &debugRazielFlags2, 0x800},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Fire Reaver", &debugRazielFlags2, 0x8000},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine cheatsMenu[] = {
    {DEBUG_LINE_TYPE_ACTION,  0, 0, "Start Game", (long *)MAIN_StartGame, 0},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Activate All WarpGates", &gameTrackerX.streamFlags, 0x400000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Disable Monsters Loading", &gameTrackerX.debugFlags2, 0x8000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Skip First Puppet Show", &gameTrackerX.streamFlags, 0x800000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Skip All Puppet Shows", &gameTrackerX.debugFlags2, 0x800000},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Show Warp Gate Info", &gameTrackerX.debugFlags2, 0x01000000},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Main Menu", (long *)mainMenu, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine optsMenu[] = {
    {DEBUG_LINE_TYPE_FORMAT,  0, 0, mainFormatString, NULL, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine gpadConfigMenu[] = {
    {DEBUG_LINE_TYPE_FORMAT,  0, 0, mainFormatString, NULL, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine keybConfigMenu[] = {
    {DEBUG_LINE_TYPE_FORMAT,  0, 0, mainFormatString, NULL, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine demoMenu[] = {
    {DEBUG_LINE_TYPE_FORMAT,  0, 0, mainFormatString, NULL, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine mainMenu[] = {
    {DEBUG_LINE_TYPE_FORMAT,  0, 0, mainFormatString, NULL, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine cameraMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "MAIN MENU...", (long *)standardMenu, 0},
    {DEBUG_LINE_TYPE_LONG,    0, 0x400, "Center Delay", (long *)&CameraCenterDelay, 0},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "Camera Override", &gameTrackerX.debugFlags2, 0x02000000},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine AIMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "MAIN MENU...", (long *)standardMenu, 0},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "DISABLE MONSTER AI", &gameTrackerX.debugFlags2, 8},
    {DEBUG_LINE_TYPE_BIT,     0, 0, "MONSTER STATS", &gameTrackerX.debugFlags2, 2},
    {DEBUG_LINE_TYPE_ACTION,  0, 0, "CINEMATIC SWITCH", (long *)DEBUG_SendCinematicSwitch, 0},
    {DEBUG_LINE_TYPE_ACTION,  0, 0, "SEND CINEMATIC COMMAND", (long *)DEBUG_SendMoveTo, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine AlukaMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0,    0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  1,    0, "ALUKA 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  4,    0, "ALUKA 4", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  6,    0, "ALUKA 6", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  8,    0, "ALUKA 8", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0xC,  0, "ALUKA 12", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0x13, 0, "ALUKA 19", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0x1B, 0, "ALUKA 27", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0x1D, 0, "ALUKA 29", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0,    0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine AshVillageMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "NIGHTA 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  2, 0, "NIGHTA 2", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  4, 0, "NIGHTA 4", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  3, 0, "NIGHTB 3", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  5, 0, "NIGHTB 5", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine OracleMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0,    0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  3,    0, "ORACLE 3", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  5,    0, "ORACLE 5", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0xA,  0, "ORACLE 10", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0xD,  0, "ORACLE 13", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0xF,  0, "ORACLE 15", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0x11, 0, "ORACLE 17", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0x12, 0, "ORACLE 18", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0x16, 0, "ORACLE 22", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0,    0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine PillarsMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  3, 0, "Pillars 3", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  4, 0, "Pillars 4", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  9, 0, "Pillars 9", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  3, 0, "Tompil 3", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine SilencedCathedralMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0,    0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  1,    0, "Cathy 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  3,    0, "Cathy 3", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  5,    0, "Cathy 5", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  8,    0, "Cathy 8", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0x13, 0, "Cathy 19", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0x2A, 0, "Cathy 42", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0x2F, 0, "Cathy 47", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0x31, 0, "Cathy 49", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0x44, 0, "Cathy 68", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0,    0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine SkinnerMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "OUT 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  4, 0, "OUT 4", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  7, 0, "SKINNR 7", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "SKINNR 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  9, 0, "SKINNR 9", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine StoneMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0,   0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  1,   0, "STONE 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  5,   0, "STONE 5", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0xA, 0, "STONE 10", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0,   0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine SunLightMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "FILL 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "INTVALY 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "SUNRM 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "PISTON 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "HTORM 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine TombMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  2, 0, "BOSS 2", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "TOMB 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "CONECTC 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "Add 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine WaterMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "TOWER 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  7, 0, "TOWER 7", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine CityMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0,   0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  2,   0, "CITY 2", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  9,   0, "CITY 9", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0xE, 0, "CITY 14", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0,   0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine CliffMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "CLIFF 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine UnderMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "UNDER 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine MorlockMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "Mrlock 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine HubAMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0,   0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  1,   0, "Huba 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  6,   0, "Huba 6", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0xA, 0, "Huba 10", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0,   0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine HubBMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "Hubb 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine TrainingMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  1, 0, "Train 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  7, 0, "Train 7", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  9, 0, "Train 9", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine DarkEdenMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  3, 0, "Fire 3", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine AnteRoomsMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0,    0, "Boss Menu...", (long *)BossAreasMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  0xC,  0, "Skinnr 12", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0x36, 0, "Cathy 54", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  2,    0, "Pillars 2", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0x2E, 0, "Aluka 46", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  8,    0, "Nightb 8", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  2,    0, "Chrono 2", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0,    0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine BossAreasMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0,    0, "More Areas Menu...", (long *)level2SelectMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0,    0, "Anterooms...", (long *)AnteRoomsMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  9,    0, "Skinnr 9", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  0x37, 0, "Cathy 55", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  1,    0, "Pillars 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  6,    0, "Aluka 6", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  3,    0, "Nightb 3", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ACTION,  1,    0, "Chrono 1", (long *)DEBUG_LevelSelectNew, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0,    0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine level2SelectMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "AREA MENU...", (long *)levelSelectMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "City...", (long *)CityMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Cliff...", (long *)CliffMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Under...", (long *)UnderMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Morlock...", (long *)MorlockMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "HubA...", (long *)HubAMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "HubB...", (long *)HubBMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Training...", (long *)TrainingMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Dark Eden...", (long *)DarkEdenMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Boss Areas...", (long *)BossAreasMenu, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine levelSelectMenu[] = {
    {DEBUG_LINE_TYPE_MENU,    0, 0, "MAIN MENU...", (long *)standardMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  0, 0, "RELOAD CURRENT LEVEL", (long *)DEBUG_ReloadCurrentLevel, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Aluka...", (long *)AlukaMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Ash Village...", (long *)AshVillageMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Oracle's Cave...", (long *)OracleMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Pillars...", (long *)PillarsMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Silenced Cathedral...", (long *)SilencedCathedralMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Skinner...", (long *)SkinnerMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Stone Glyph...", (long *)StoneMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Sunlight Glyph... ", (long *)SunLightMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Tomb Of Seven...", (long *)TombMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Water Glyph...", (long *)WaterMenu, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "More Areas..", (long *)level2SelectMenu, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine mcardMenu[] = {
    {DEBUG_LINE_TYPE_FORMAT,  0, 0, mainFormatString, NULL, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine mcardSaveMenu[] = {
    {DEBUG_LINE_TYPE_FORMAT,  0, 0, pauseFormatString, NULL, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine pauseSaveMenu[] = {
    {DEBUG_LINE_TYPE_FORMAT,  0, 0, pauseFormatString, NULL, 0},
    {DEBUG_LINE_TYPE_MENU,    0, 0, "Back...", (long *)pauseMenu, 0},
    {DEBUG_LINE_TYPE_ACTION,  0, 0, "Save Current Game", (long *)SAVE_DebugSaveGame, 0},
    {DEBUG_LINE_TYPE_ACTION,  0, 0, "Restore Game", (long *)SAVE_LoadSaveGame, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
DebugMenuLine pauseMenu[] = {
    {DEBUG_LINE_TYPE_FORMAT,  0, 0, pauseFormatString, NULL, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
    {DEBUG_LINE_TYPE_ENDLIST, 0, 0, "", &gameTrackerX.debugFlags, 0},
};
static debug_dispatch_t debug_dispatch_table[] = {
    {DEBUG_LINE_TYPE_BIT,              handle_line_type_bit},
    {DEBUG_LINE_TYPE_LONG,             handle_line_type_long},
    {DEBUG_LINE_TYPE_ACTION,           handle_line_type_action},
    {DEBUG_LINE_TYPE_ACTION_WITH_LINE, handle_line_type_action_with_line},
    {DEBUG_LINE_TYPE_MENU,             handle_line_type_menu},
};

/*Unused*/ static char D_800CFF80[] = "dbg_cam_";
/*Unused*/ static char D_800CFF8C[] = "box_____";
/*Unused*/ static char D_800CFF98[] = "sphere__";

DebugMenuLine *currentMenu = standardMenu;
static long debugMenuChoice = 0;
static long cheatCodeLastCommand = 0;
static long CheatKeyMap[10] = {4, 8, 2, 1, 0x10, 0x40, 0x80, 0xC00, 0x400, 0x800};
static GameCheat GameCheats[23] = {
    { { 2, 4, 7, 1, 1, 2, 2, 0, 4, 2, 1, 0}, 0xB, 0},
    { { 3, 3, 2, 1, 1, 0, 5, 1, 0, 2, 0, 0}, 0xA, 0},
    { { 2, 3, 1, 3, 2, 0, 5, 1, 2, 0, 0, 0}, 0x9, 0},
    { { 6, 1, 3, 3, 4, 0, 0, 1, 3, 0, 0, 0}, 0x9, 0},
    { { 2, 3, 1, 1, 5, 3, 3, 2, 0, 0, 0, 0}, 0x8, 0},
    { { 6, 5, 1, 4, 0, 0, 1, 3, 0, 0, 0, 0}, 0x8, 0},
    { { 0, 5, 0, 1, 1, 3, 3, 0, 0, 0, 0, 0}, 0x8, 0},
    { { 4, 1, 2, 1, 3, 4, 0, 0, 0, 0, 0, 0}, 0x7, 0},
    { { 2, 5, 5, 0, 1, 4, 3, 0, 0, 0, 0, 0}, 0x7, 0},
    { { 3, 5, 2, 1, 5, 0, 3, 0, 0, 0, 0, 0}, 0x7, 0},
    { { 2, 5, 3, 0, 2, 1, 1, 0, 0, 0, 0, 0}, 0x7, 0},
    { { 1, 1, 2, 5, 3, 3, 2, 0, 0, 0, 0, 0}, 0x7, 0},
    { { 3, 3, 1, 3, 4, 7, 1, 0, 0, 0, 0, 0}, 0x7, 0},
    { { 2, 5, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0}, 0x6, 0},
    { { 1, 6, 0, 4, 3, 2, 0, 0, 0, 0, 0, 0}, 0x6, 0},
    { { 1, 5, 2, 3, 2, 3, 0, 0, 0, 0, 0, 0}, 0x6, 0},
    { { 1, 1, 0, 4, 1, 2, 0, 0, 0, 0, 0, 0}, 0x6, 0},
    { { 4, 2, 7, 1, 3, 2, 0, 0, 0, 0, 0, 0}, 0x6, 0},
    { { 0, 1, 5, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 0x6, 0},
    { { 0, 5, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0}, 0x5, 0},
    { { 4, 1, 2, 5, 3, 0, 0, 0, 0, 0, 0, 0}, 0x5, 0},
    { { 2, 0, 4, 2, 3, 0, 0, 0, 0, 0, 0, 0}, 0x5, 0},
    { { 2, 5, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0}, 0x5, 0},
};

DebugMenuLine *the_previous_menu = NULL;
static int cem_x_base = 0x28;
static int cem_y_base = 0x14;
static int cem_cursor_width = 0x14;
static int cem_line_width = 0xF0;
static int cem_line_leading = 0xC;
static int cem_item_leading = 0x10;

void DEBUG_SetGameTime(long *var)
{
    GAMELOOP_SetGameTime(*var);
}

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_KeepGameTime);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_UpdateFog);

void DEBUG_UpdateHealth(long *var)
{
    RAZIEL_DebugHealthSetScale(debugHealthLevel);
}

void DEBUG_UpdateMana(long *var)
{
    RAZIEL_DebugManaSetMax(debugManaLevel);
}

void DEBUG_FillUpHealth(long *var)
{
    RAZIEL_DebugHealthFillUp();

    RAZIEL_DebugManaFillUp();
}

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_FogLoad);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_FogRestore);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_SendCinematicSwitch);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_SendMoveTo);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", process_cheat_codes);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_Process);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_Draw);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_MenuCountLength);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_ExitMenus);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", get_last_menu_line);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", num_menu_items);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", maybe_change_menu_choice);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", handle_line_type_long);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", handle_line_type_bit);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", handle_line_type_action);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", handle_line_type_action_with_line);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", handle_line_type_menu);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", process_menu_line);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", pre_process_functions);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", post_process_functions);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", set_debug_leading);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", set_user_leading);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", isdigit);

/*TODO: migrate to adjust_format*/
static char D_800D0164[] = "-abs ";
static char D_800D016C[] = "-rel ";
static char D_800D0174[] = "-center";
static char D_800D017C[] = "unknown format control: %s\n";
INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", adjust_format);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", find_eol);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", draw_menu_item);

/*TODO: migrate to draw_menu*/
static char D_800D0198[] = ">";
static char D_800D019C[] = "YES";
static char D_800D01A0[] = "NO";
static char D_800D01A4[] = "%d";
INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", draw_menu);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_Menu);

/*TODO: migrate to DEBUG_DisplayStatus*/
static char D_800D01A8[] = "$@EF\n FRTE %d ";
static char D_800D01B8[] = " INS  %d";
static char D_800D01C4[] = "/%d\n";
static char D_800D01CC[] = "$@KG\n FRTE %d\n";
static char D_800D01DC[] = " Focus XYZ(%d,%d,%d)\n";
static char D_800D01F4[] = " IDLE %d PCT\n";
static char D_800D0204[] = " IDLE ZERO\n";
static char D_800D0210[] = " DRAW %d\n";
static char D_800D021C[] = " Far Plane =%d\n";
static char D_800D022C[] = " Fog Near = %d Fog Far = %d\n";
static char D_800D024C[] = "Military Time %04d\n";
static char D_800D0260[] = " FMEM %d  FreeSaveMem %d\n";
static char D_800D027C[] = " AREA DRM = %s\n";
static char D_800D028C[] = " CAM TILT %d DIST %d\n";
static char D_800D02A4[] = "Loading From CD: In Queue(%d)\n";
INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_DisplayStatus);

void DEBUG_DrawShrinkCels(void)
{
}

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_ContinueGame);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_ExitGame);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_ReloadCurrentLevel);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_LevelSelectNew);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_SetViewVram);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_EndViewVram);

/*Unused*/ short AXIS_LENGTH = 0x012C;
/*Unused*/ static char D_800D02C8[] = "hub";
/*Unused*/ static char D_800D02CC[] = "\nSound RAM usage...\n\n";
/*Unused*/ static char D_800D02E4[] = "Sfx ID %3d loaded  Ref count=%d  Using wave ID %3d  \n";
/*Unused*/ static char D_800D031C[] = "Sfx ID %3d **LOAD ERROR**\n";
/*Unused*/ static char D_800D0338[] = "\n%ld sfx loaded (%ld waves) using %ld bytes SRAM\nFree Sram:%ld  Largest Free Sram Block:%ld\n";

/*TODO: migrate to DEBUG_ViewVram*/
static long D_800D0398 = 0;
static long D_800D039C = 0;
INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_ViewVram);

void DEBUG_CaptureScreen(void)
{
}

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_PageFlip);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_FatalError);

void DEBUG_ProcessSecondController(void)
{
}

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_ProcessCheat);

INCLUDE_ASM("asm/nonmatchings/Game/DEBUG", DEBUG_DoAreaProtection);
