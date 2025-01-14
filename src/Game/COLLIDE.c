#include "common.h"
#include "Game/COLLIDE.h"

long dyna_clddyna[8] = {
    0x0C, 0x0D, 0x0E, 0x0F, 0x1C, 0x1D, 0x1E, 0x1F};

long stat_clddyna[8] = {
    0x04, 0x05, 0x06, 0x07, 0x14, 0x15, 0x16, 0x17};

long dyna_cldstat[8] = {
    0x0A, 0x0B, 0x0E, 0x0F, 0x1A, 0x1B, 0x1E, 0x1F};

long collide_ignoreAttr = 0;

long collide_acceptAttr = 0;

int COLLIDE_PointInTriangle(struct _SVector *v0, struct _SVector *v1, struct _SVector *v2, struct _SVector *point, struct _SVector *normal)
{
    struct _Triangle2D *triangle;
    int nx;
    int ny;
    short tx;
    short ty;
    int inside_flag;
    int line_flag;
    struct DVECTOR *vert1;
    struct DVECTOR *vert0;
    int yflag1;
    int yflag0;
    int j;
    long ydist;
    long xdist;
    long xdiff;
    long ydiff;
    long ix;
    int temp; // not from decls.h

    nx = normal->x > 0 ? normal->x : -normal->x;
    ny = normal->y > 0 ? normal->y : -normal->y;

    triangle = (struct _Triangle2D *)getScratchAddr(0);

    if (ny < nx)
    {
        if (abs(normal->z) < nx)
        {
            tx = point->y;
            ty = point->z;

            *(int *)&triangle->x0 = (unsigned short)v0->y | (v0->z << 16);
            *(int *)&triangle->x1 = (unsigned short)v1->y | (v1->z << 16);
            *(int *)&triangle->x2 = (unsigned short)v2->y | (v2->z << 16);
        }
        else
        {
            tx = point->x;
            ty = point->y;

            *(int *)&triangle->x0 = (unsigned short)v0->x | (v0->y << 16);
            *(int *)&triangle->x1 = (unsigned short)v1->x | (v1->y << 16);
            *(int *)&triangle->x2 = (unsigned short)v2->x | (v2->y << 16);
        }
    }
    else
    {
        if (abs(normal->z) < ny)
        {
            tx = point->x;
            ty = point->z;

            *(int *)&triangle->x0 = (unsigned short)v0->x | (v0->z << 16);
            *(int *)&triangle->x1 = (unsigned short)v1->x | (v1->z << 16);
            *(int *)&triangle->x2 = (unsigned short)v2->x | (v2->z << 16);
        }
        else
        {
            tx = point->x;
            ty = point->y;

            *(int *)&triangle->x0 = (unsigned short)v0->x | (v0->y << 16);
            *(int *)&triangle->x1 = (unsigned short)v1->x | (v1->y << 16);
            *(int *)&triangle->x2 = (unsigned short)v2->x | (v2->y << 16);
        }
    }

    vert1 = (struct DVECTOR *)triangle;
    vert0 = (struct DVECTOR *)vert1 + 2;

    yflag0 = (vert0->vy >= ty);
    inside_flag = 0;
    line_flag = 0;

    for (j = 3; j != 0; j--)
    {
        yflag1 = (vert1->vy >= ty);

        if (yflag0 != yflag1)
        {
            temp = (vert0->vx >= tx);

            if (temp == (vert1->vx >= tx))
            {
                if (temp != 0)
                {
                    inside_flag = !inside_flag;
                }
            }
            else
            {
                xdist = vert1->vx - tx;
                ydiff = vert0->vy - vert1->vy;
                xdiff = vert0->vx - vert1->vx;
                ydist = vert1->vy - ty;

                ix = xdist * ydiff - ydist * xdiff;

                if (ydiff < 0)
                {
                    ydiff = -ydiff;
                    ix = -ix;
                }

                ydiff = ydiff / 2;

                if (ydiff < ix)
                {
                    inside_flag = !inside_flag;
                }
                else if (ix >= -ydiff)
                {
                    return 1;
                }
            }

            if (line_flag != 0)
            {
                return inside_flag;
            }

            line_flag = 1;
        }
        else
        {
            if ((yflag1 != 0) && (ty == vert0->vy))
            {
                if (ty == vert1->vy)
                {
                    if (((vert0->vx < tx) != (vert1->vx < tx) == 0) && (tx != vert0->vx))
                    {
                        if (tx == vert1->vx)
                        {
                            return 1;
                        }
                    }
                    else
                    {
                        return 1;
                    }
                }
                else if (tx == vert0->vx)
                {
                    return 1;
                }
            }
        }

        yflag0 = yflag1;
        vert0 = vert1;
        vert1++;
    }

    return inside_flag;
}

int COLLIDE_PointInTriangle2DPub(short *v0, short *v1, short *v2, short *point)
{
    struct _SVector normal = {.x = 0, .y = 0, .z = 4096};

    return COLLIDE_PointInTriangle((struct _SVector *)v0, (struct _SVector *)v1, (struct _SVector *)v2, (struct _SVector *)point, (struct _SVector *)&normal);
}

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_GetNormal);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_MakeNormal);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_UpdateAllTransforms);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_MoveAllTransforms);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_WithinYZBounds);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_WithinXZBounds);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_WithinXYBounds);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_LineWithBoxFace);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_IntersectLineAndBox);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_PointAndTerrain);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_PointAndTerrainFunc);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_PointAndHFace);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_PointAndInstance);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_PointAndInstanceTrivialReject);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_PointAndWorld);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_ClosestPointInBoxToPoint);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_SphereAndPoint);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_SphereAndHBox);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_Instance1SpheresToInstance2);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_Instances);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_InstanceList);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_SphereAndHFace);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_SAndT);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_SphereAndTerrain);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_InstanceTerrain);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_LineWithSignals);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_InstanceTerrainSignal);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_CameraWithStreamSignals);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_InstanceListWithSignals);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_InstanceListTerrain);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_SegmentCollisionOn);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_SegmentCollisionOff);

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_FindCollisionFaceNormal);

short *COLLIDE_GetBSPTreeFlag(struct _CollideInfo *collideInfo);
INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_GetBSPTreeFlag);

void COLLIDE_SetBSPTreeFlag(struct _CollideInfo *collideInfo, short flag)
{
    short *bspTreeFlags;

    bspTreeFlags = COLLIDE_GetBSPTreeFlag(collideInfo);

    *bspTreeFlags |= flag;
}

INCLUDE_ASM("asm/nonmatchings/Game/COLLIDE", COLLIDE_PointAndTfaceFunc);
