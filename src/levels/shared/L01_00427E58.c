#include "common.h"

/* localdecomp:start func_L01_00427E58 */
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
    s32 i;
    s32 j;

    if (header[0] != 0) {
        D_L01_001EAA00[0] = (u8 *)header + header[0];
    }
    if (header[1] != 0) {
        D_L01_001DFC00 = (CollGroups_00427E58 *)((u8 *)header + header[1]);
        for (i = 0; i < D_L01_001DFC00->count; i++) {
            D_L01_001DFC00->groups[i].data = (s32)((u8 *)D_L01_001DFC00 + D_L01_001DFC00->groups[i].data);
        }
    } else {
        D_L01_001DFC00 = 0;
    }
    if (header[2] != 0) {
        D_L01_001DFC04 = (CollGroups_00427E58 *)((u8 *)header + header[2]);
        for (j = 0; j < D_L01_001DFC04->count; j++) {
            D_L01_001DFC04->groups[j].data = (s32)((u8 *)D_L01_001DFC04 + D_L01_001DFC04->groups[j].data);
        }
    } else {
        D_L01_001DFC04 = 0;
    }
}
/* localdecomp:end func_L01_00427E58 */

/* localdecomp:start func_L01_00427F18 */
typedef struct {
    f32 x;
    f32 y;
} P_00425170;

void func_L01_00427F18(s32 *a0, s32 n, s32 *a2) {
    P_00425170 arr[512];
    s32 cnt;
    s32 m;
    s32 i;
    s32 k;
    s32 l;
    s32 j;
    s32 sorted;
    f32 tx;
    f32 ty;

    cnt = 0;
    for (i = 0; i < n; i++) {
        if (a0[0] != 0) {
            arr[cnt].x = a0[1];
            arr[cnt].y = a0[0];
            cnt++;
        }
        a0 += 8;
    }
    for (l = 0; l < cnt - 1; l++) {
        arr[l].y = (arr[l + 1].y - arr[l].y) * 0.0009765625f;
    }
    m = cnt - 1;
    arr[m].y = (*a2 - arr[m].y) * 0.0009765625f;
    do {
        sorted = 1;
        for (j = 0; j < cnt - 1; j++) {
            if (arr[j].y < arr[j + 1].y) {
                tx = arr[j].x;
                ty = arr[j].y;
                arr[j].x = arr[j + 1].x;
                arr[j].y = arr[j + 1].y;
                arr[j + 1].x = tx;
                arr[j + 1].y = ty;
                sorted = 0;
            }
        }
    } while (sorted == 0);
    for (k = 0; k < cnt; k++) {
    }
}
/* localdecomp:end func_L01_00427F18 */

/* localdecomp:start func_L01_00428090 */
void func_L01_00428090(void) {

}
/* localdecomp:end func_L01_00428090 */

INCLUDE_ASM("asm/levels", func_L01_00428098);
