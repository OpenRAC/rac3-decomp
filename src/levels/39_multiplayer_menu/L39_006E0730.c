#include "common.h"

/* declared by functions of L39_006DC228.c, which this file was cut from */
extern u8 D_001A5CD0[];
extern void *D_001E2050_sda;
extern s32 func_L39_006D6E50(s32, s32, s32, s32 *);
extern void func_L39_006D6E30(s32, s32, s32 *);
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

/* localdecomp:start func_L39_006E0730 */
typedef struct { s16 v; s16 pad; } E_006E0730;
extern E_006E0730 D_001FD928[];

void func_L39_006E0730(s32 *min, s32 *max) {
    s32 i, j, sum;

    *max = 0;
    *min = 10000;
    for (i = 0; i < 8; i++) {
        if (D_001FD7E8.ent[i].count > 0) {
            sum = 0;
            for (j = 0; j < D_001FD7E8.ent[i].count; j++) {
                sum += (D_001FD928 + D_001FD7E8.ent[i].ids[j])->v;
            }
            if (sum < *min) {
                *min = sum;
            }
            if (sum > *max) {
                *max = sum;
            }
        }
    }
}
/* localdecomp:end func_L39_006E0730 */

/* localdecomp:start func_L39_006E07E8 */
void func_L39_006E07E8(s32 *min, s32 *max) {
    s32 i, j, v;

    *max = 0;
    *min = 10000;
    for (i = 0; i < 8; i++) {
        if (D_001FD7E8.ent[i].count > 0) {
            for (j = 0; j < D_001FD7E8.ent[i].count; j++) {
                v = (D_001FD928 + D_001FD7E8.ent[i].ids[j])->v;
                if (v < *min) {
                    *min = v;
                }
                if (v > *max) {
                    *max = v;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_006E07E8 */
