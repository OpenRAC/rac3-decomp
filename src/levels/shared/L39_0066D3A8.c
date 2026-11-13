#include "common.h"

/* localdecomp:start func_L39_0066D3A8 */
typedef struct {
    u8 pad0[0x2558];
    s32 *f2558;
} P_0066D3A8;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x2C - 8];
    u8 b2C;
    u8 pad2D[3];
    s32 w30;
    s32 w34;
    u8 pad38[0x44 - 0x38];
    s32 w44;
    s32 w48;
    s32 w4C;
    u8 b50;
    u8 b51;
    u8 pad52[2];
} E_0066D3A8;
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 pad0C[0x128 - 0xC];
    s32 w128;
} G_0066D3A8;

extern G_0066D3A8 D_001A5CD0;
extern s32 D_L39_00246334;
extern P_0066D3A8 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern E_0066D3A8 D_L39_00343328[];
extern void func_L39_0061E278(void *);
extern void func_L39_0066DA90(s32 *, s32, u8, u8);

void func_L39_0066D3A8(s32 n, s32 id)
{
    s32 best;
    s32 i;
    E_0066D3A8 *e;

    D_L39_00246334 = D_001A5CD0.w128;
    best = -1;
    for (i = n + 1; i < 8; i++) {
        if (D_L39_0024CE20[i] != 0) {
            s32 v = *D_L39_0024CE20[i]->f2558;
            if (v != id) {
                best = v;
            }
        }
    }
    if (best == -1) {
        for (i = 0; i < n; i++) {
            if (D_L39_0024CE20[i] != 0) {
                s32 v = *D_L39_0024CE20[i]->f2558;
                if (v != id) {
                    best = v;
                }
            }
        }
    }
    for (i = 0; i < 512; i++) {
        e = &D_L39_00343328[i];
        if (e->b2C == 0) {
            continue;
        }
        if (e->w44 == id) {
            if (e->w34 == D_001A5CD0.w8) {
                func_L39_0061E278(e);
            }
            e->w4 = -1;
            e->w34 = -1;
            e->w48 = -1;
            e->w4C = -1;
            e->b50 = 0;
            e->b51 = 1;
            e->w44 = best;
        } else if (e->w44 == D_001A5CD0.w8) {
            if (e->w4C == id) {
                func_L39_0066DA90((s32 *)e, e->w48, e->b51, *(u8 *)&D_001A5CD0.w8);
                e->w4C = -1;
                e->b51++;
            } else if (e->w48 == id) {
                e->w4 = -1;
                e->w34 = -1;
                e->w48 = -1;
                e->w4C = -1;
            }
        }
    }
}
/* localdecomp:end func_L39_0066D3A8 */

INCLUDE_ASM("asm/levels", func_L39_0066D580);
