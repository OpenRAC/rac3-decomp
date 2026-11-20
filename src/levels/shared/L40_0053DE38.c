#include "common.h"

/* localdecomp:start func_L40_0053DE38 */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} E_0053DE38;

typedef struct {
    u8 pad0[0x40];
    s32 a40[8];
    s32 a60[8];
    s32 a80[2];
    s32 a88[8];
    s32 aA8[8];
} T_0053DE38;

typedef struct {
    u8 pad[0x20C];
    T_0053DE38 *p20C;
} S_0053DE38;

extern E_0053DE38 D_L40_00347AB0[];
extern S_0053DE38 D_L40_00357260;
extern u8 *D_L40_0024845C;
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L40_0053E000(f32 radius, s32 a0, u8 *a1, u8 a2);

s32 func_L40_0053DE38(s32 a0, u8 *a1, f32 radius) {
    s32 i;
    s32 r;

    for (i = 0; i < 15; i++) {
        if (D_L40_00347AB0[i].a == -1 && D_L40_00347AB0[i].b == -1) {
            return -1;
        }
        if (D_L40_00347AB0[i].a != -1) {
            T_0053DE38 *t = D_L40_00357260.p20C;
            if (t->a88[D_L40_00347AB0[i].a] != a0) {
                if (func_L01_0040E548(a1 + 0x10, D_L40_0024845C + (t->a40[D_L40_00347AB0[i].a] << 8) + 0x10) < radius) {
                    r = func_L40_0053E000(radius, a0, a1, D_L40_00347AB0[i].c);
                    if (r != -1 && r != 0) {
                        return r;
                    }
                }
            }
        } else if (D_L40_00347AB0[i].b != -1) {
            T_0053DE38 *t = D_L40_00357260.p20C;
            if (t->aA8[D_L40_00347AB0[i].b] != a0) {
                if (func_L01_0040E548(a1 + 0x10, D_L40_0024845C + (t->a60[D_L40_00347AB0[i].b] << 8) + 0x10) < radius) {
                    return func_L40_0053E000(radius, a0, a1, D_L40_00347AB0[i].c);
                }
            }
        }
    }
    return -1;
}
/* localdecomp:end func_L40_0053DE38 */

/* localdecomp:start func_L40_0053E000 */
extern u16 *D_L40_0028EA20[];
extern s32 D_L40_00248498;
extern u8 *D_L40_0024845C;
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L39_0061D780(void *);

s32 func_L40_0053E000(f32 radius, s32 a0, u8 *a1, u8 a2) {
    u16 *p;
    u8 *o;
    u8 *best;
    f32 bestd;
    f32 d;
    u32 k;

    best = 0;
    bestd = 99999.0f;
    p = D_L40_0028EA20[a2];
    if (a2 != 0xFF && a2 <= D_L40_00248498 && p != 0) {
        do {
            o = D_L40_0024845C + ((*p & 0x7FFF) << 8);
            if (o == 0) break;
            if (*(s16 *)(o + 0xAA) == 0x1A63) {
                k = (u8)(o[0x20] - 2) < 4;
            } else {
                k = (u8)(o[0x20] - 2) < 3;
            }
            if (k) {
                d = func_L01_0040E548(a1 + 0x10, o + 0x10);
                if (d < bestd) {
                    bestd = d;
                    best = o;
                }
            }
            p++;
            if (a2 == 0xFF || a2 > D_L40_00248498 || p == 0) break;
        } while ((s16)p[-1] >= 0 || p == D_L40_0028EA20[a2]);
    }
    if (best != 0) {
        if (!(radius * 0.75f < bestd)) {
            return func_L39_0061D780(best);
        }
    }
    return -1;
}
/* localdecomp:end func_L40_0053E000 */

INCLUDE_ASM("asm/levels", func_L40_0053E1A8);

INCLUDE_ASM("asm/levels", func_L40_0053E760);
