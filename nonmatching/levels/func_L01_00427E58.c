/* near miss (open-rac-engine names it collision_load). Two things:
 * - the file needs @ps2as: retail stores the zero pointers with `lui $at` + `sw` but writes them through
 *   $gp in branch delay slots (Ps2EeAs before it knows their size); src/levels/shared/L01_00427E58.c
 *   uses the default assembler, which gives $gp everywhere. With --as ps2as:
 * - 5 words differ in the hero groups loop: retail computes the list into $v1 (stored to
 *   D_L01_001DFC00) and copies it to $a1 for the loop; ours computes it straight into $a1. */
#include "common.h"

typedef struct {
    s32 sphere[3];      /* bounding sphere in 1/64 u, triangle and vertex counts */
    s32 data;           /* offset of the group's data, made a pointer here */
} CollGroup_00427E58;

typedef struct {
    s32 count;
    u8 pad4[0xC];
    CollGroup_00427E58 groups[1];
} CollGroups_00427E58;

extern u8 *D_L01_001EAA00[];
extern CollGroups_00427E58 *D_L01_001DFC00;
extern CollGroups_00427E58 *D_L01_001DFC04;

/* collision_load: takes the level's collision file. Its three header offsets give the
   terrain coll_line uses, the hero's groups and the camera's groups, whose groups' data
   offsets it relocates. */
void func_L01_00427E58(s32 *header) {
    CollGroups_00427E58 *hero;
    CollGroups_00427E58 *camera;
    s32 i;
    s32 j;

    if (header[0] != 0) {
        D_L01_001EAA00[0] = (u8 *)header + header[0];
    }
    if (header[1] != 0) {
        hero = (CollGroups_00427E58 *)((u8 *)header + header[1]);
        D_L01_001DFC00 = hero;
        for (i = 0; i < hero->count; i++) {
            hero->groups[i].data = (s32)((u8 *)hero + hero->groups[i].data);
        }
    } else {
        D_L01_001DFC00 = 0;
    }
    if (header[2] != 0) {
        camera = (CollGroups_00427E58 *)((u8 *)header + header[2]);
        D_L01_001DFC04 = camera;
        for (j = 0; j < camera->count; j++) {
            camera->groups[j].data = (s32)((u8 *)camera + camera->groups[j].data);
        }
    } else {
        D_L01_001DFC04 = 0;
    }
}
