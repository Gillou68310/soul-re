#ifndef _QUATG2_H_
#define _QUATG2_H_

#include "common.h"
#include "Game/G2/ANIMG2.h"

typedef struct _G2Quat_Type {
    // offset: 0000
    short x;
    // offset: 0002
    short y;
    // offset: 0004
    short z;
    // offset: 0006
    short w;
} G2Quat;

void G2EulerAngles_FromMatrix(G2EulerAngles *euler, G2Matrix *matrix, long order);

#endif
