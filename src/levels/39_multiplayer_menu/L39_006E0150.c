#include "common.h"

/* localdecomp:start func_L39_006E0150 */
typedef struct {
    s32 ids[8];
    f32 a[8];
    f32 b[8];
    char pad[0x8C - 0x60];
    s32 count;
    char pad2[0xA4 - 0x90];
} S_006E0150_Ent;
typedef struct {
    char pad[0x100];
    s32 active[8];
    char pad2[0x2E8 - 0x120];
    S_006E0150_Ent ent[8];
} S_006E0150;
extern S_006E0150 D_001FD7E8;

void func_L39_006E0150(s32 *total, s32 *num, s32 *key, s32 *out) {
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        if (D_001FD7E8.active[i] != 0 && *key == -1) {
            *key = i;
        }
        if (D_001FD7E8.ent[i].count > 0) {
            *total += D_001FD7E8.ent[i].count;
            (*num)++;
        }
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < D_001FD7E8.ent[i].count; j++) {
            if (D_001FD7E8.ent[i].ids[j] == *key) {
                *out = j;
                break;
            }
        }
    }
}
/* localdecomp:end func_L39_006E0150 */

/* localdecomp:start func_L39_006E0220 */
extern u8 D_L39_001A5D8D[];
extern u8 D_L39_001A6950[];

s32 func_L39_006E0220(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a3 = 0;
    f32 *p;

    if (D_L39_001A5D8D[0] != 0) {
        if (arg0 >= 2) {
            temp_a3 = arg1 >= 2;
        }
    }
    arg1 = temp_a3;
    if (arg1 != 0) {
        p = (f32 *)D_L39_001A6950;
        if (p[0x110 / 4] <= 0.0f) {
            arg1 = 0;
        } else if (arg2 >= 2) {
            if (p[0x10C / 4] <= 0.0f) {
                arg1 = 0;
            }
        }
    }
    return arg1;
}
/* localdecomp:end func_L39_006E0220 */
