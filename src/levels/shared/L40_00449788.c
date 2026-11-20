#include "common.h"

/* localdecomp:start func_L40_00449788 */
typedef struct {
    u8 x0;
    u8 x1;
    u16 id;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
} E_00449788;
extern E_00449788 D_L40_00257CC0_00449788[];
extern E_00449788 D_L40_00257E00[];

s32 func_L40_00449788(s32 a0, u8 *a1) {
    s32 i = a0 & 0x3F;

    if (i >= 16) {
        i -= 16;
        if (D_L40_00257E00[i].id == a0) {
            if (D_L40_00257E00[i].x4 == D_L40_00257E00[i].xC) {
                *(s32 *)a1 = D_L40_00257E00[i].x10;
                return 1;
            }
        }
    } else {
        if (D_L40_00257CC0_00449788[i].id == a0) {
            if (D_L40_00257CC0_00449788[i].x1 != 0) {
                if (D_L40_00257CC0_00449788[i].x4 == D_L40_00257CC0_00449788[i].x8) {
                    *(s32 *)a1 = D_L40_00257CC0_00449788[i].x10;
                    return 1;
                }
            } else {
                if (D_L40_00257CC0_00449788[i].x4 == D_L40_00257CC0_00449788[i].xC) {
                    *(s32 *)a1 = D_L40_00257CC0_00449788[i].x10;
                    return 1;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L40_00449788 */

LINKER_REMNANT("asm/levels", func_L40_00449820);

/* localdecomp:start func_L40_00449828 */
typedef struct {
    s32 a;
    s32 b;
} R_00449828;

typedef struct {
    u8 pad0[6];
    s16 count;
    u8 pad8[4];
    s32 xC;
    u8 pad10[0x190];
    R_00449828 arr[1];
} S_00449828;

extern S_00449828 D_L40_003A8FB8;
extern long func_001306F8(long, long);

static __inline__ s32 adv_00449828(S_00449828 *s, s32 pos, s32 *pi) {
    R_00449828 *arr = s->arr;
    s32 count = s->count;
    s32 n;

    while (pos >= arr[*pi].b) {
        n = (*pi + 1) % count;
        pos += arr[n].a - arr[*pi].b;
        *pi = n;
    }
    return pos;
}

u8 func_L40_00449828(void *a0, s32 *o1, s32 *o2, u16 *o3) {
    s32 r = 0;
    s32 x;
    s32 y;
    s32 pos;
    s32 pos2;
    s32 idx;
    s32 loc[2];
    s32 *p0;
    s32 *p1;

    if ((u32)a0 & 1) {
        a0 = (void *)((u32)a0 >> 1);
        x = ((u32)a0 / 481) << 3;
        y = (((u32)a0 % 481) + 1) << 3;
        *o1 = x;
        if (*o1 > 0x2000000) {
            r = 1;
            *o1 -= 0x2000000;
            *o2 = *o1;
            *o1 += y;
        } else {
            *o2 = *o1 + y;
        }
        idx = -1;
        *o3 = idx;
    } else {
        pos = (s32)(func_001306F8(D_L40_003A8FB8.xC, ((u32)a0 >> 4) & 0xFFFF) >> 16) & ~7;
        pos += D_L40_003A8FB8.arr[0].a;
        p0 = &loc[0];
        loc[0] = 0;
        pos = adv_00449828(&D_L40_003A8FB8, pos, p0);
        loc[1] = loc[0];
        p1 = &loc[1];
        pos2 = ((D_L40_003A8FB8.xC >> 11) << 3) + ((((D_L40_003A8FB8.xC >> 11) << 3) + ((u32)a0 >> 20)) << 8) + pos;
        pos2 = adv_00449828(&D_L40_003A8FB8, pos2, p1);
        *o1 = pos;
        *o2 = pos2;
        *o3 = loc[0];
    }
    return r != 0;
}
/* localdecomp:end func_L40_00449828 */

/* localdecomp:start func_L40_00449A38 */
typedef struct {
    u8 b0;
    u8 b1;
    s16 id;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
} E_00449A38;
extern s32 D_001D6D14_sda;
extern s32 D_001D6D10_sda;
extern E_00449A38 D_L40_00257CC0[];
extern u8 func_L40_00449828(void *, s32 *, s32 *, u16 *);

s32 func_L40_00449A38(void *a0, s32 *o1, s32 *o2, u16 *o3, u8 *o4) {
    u16 c0;
    s32 s4;
    s32 s8;
    u8 r;
    s32 i;

    if (((D_001D6D14_sda + 1) & 0xF) == D_001D6D10_sda) {
        return 0;
    }
    r = func_L40_00449828(a0, &s4, &s8, &c0);
    for (i = 0; i < 16; i++) {
        if (s4 == D_L40_00257CC0[i].w8 && s8 == D_L40_00257CC0[i].wC) {
            return 0;
        }
    }
    if (o1 != 0) {
        *o1 = s4;
        *o2 = s8;
        *o3 = c0;
        *o4 = r;
    }
    return 1;
}
/* localdecomp:end func_L40_00449A38 */
