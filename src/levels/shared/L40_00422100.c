#include "common.h"

/* declared by functions of L40_00420998.c, which this file was cut from */
extern s32 func_L39_005F33E0(s32, s32, u8 *);

/* localdecomp:start func_L40_00422100 */
extern u16 *D_L40_0028EA20[];
extern s32 D_L40_00248498;
extern u8 *D_L40_0024845C;

void func_L40_00422100(u8 *o) {
    s32 *v;
    u16 *p;
    s32 i;
    s32 *q;

    o[0x30] = 255;
    v = *(s32 **)(o + 0x68);
    if (v[0] != -1) {
        p = D_L40_0028EA20[v[0]];
        while ((v[0] & 0xFF) != 255 && v[0] <= D_L40_00248498 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L40_0028EA20[v[0]])) {
            u8 *m = D_L40_0024845C + ((*p & 0x7FFF) << 8);
            if (m == 0) {
                break;
            }
            p++;
            if (m[0x20] == 37) {
                m[0x20] = 38;
            }
        }
    }
    q = v + 4;
    for (i = 0; i < 8; i++) {
        s32 e = *q++;
        if (e != -1) {
            u8 *m = (u8 *)((e << 8) + (s32)D_L40_0024845C);
            if (m[0x20] == 37) {
                m[0x20] = 38;
            }
        }
    }
}
/* localdecomp:end func_L40_00422100 */

/* localdecomp:start func_L40_00422208 */
extern u16 *D_L40_0028EA20[];
extern s32 D_L40_00248498;
extern u8 *D_L40_0024845C;

void *func_L40_00422208(void *m, s32 type) {
    s32 *v = *(s32 **)((u8 *)m + 0x68);
    u8 *found = 0;
    u16 *p;
    s32 i;

    if (v[0] != -1) {
        p = D_L40_0028EA20[v[0]];
        while ((v[0] & 0xFF) != 255 && v[0] <= D_L40_00248498 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L40_0028EA20[v[0]])) {
            u8 *o = D_L40_0024845C + ((*p & 0x7FFF) << 8);
            if (o == 0) {
                break;
            }
            if (*(s16 *)(o + 0xAA) == type && (o[0x20] == 37 || o[0x20] == 38)) {
                if (type != 4255) {
                    return o;
                }
                if (*(s32 *)(*(u8 **)(o + 0x68) + 0x2B8) == -1) {
                    return o;
                }
                if (found == 0) {
                    found = o;
                }
            }
            p++;
        }
    }
    for (i = 0; i < 8; i++) {
        s32 e = v[i + 4];
        if (e != -1) {
            u8 *o = (u8 *)((e << 8) + (s32)D_L40_0024845C);
            if (*(s16 *)(o + 0xAA) == type && (o[0x20] == 37 || o[0x20] == 38)) {
                return o;
            }
        }
    }
    if (type == 4255) {
        return found;
    }
    return 0;
}
/* localdecomp:end func_L40_00422208 */
