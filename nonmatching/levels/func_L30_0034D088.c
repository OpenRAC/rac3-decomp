/* NTSC-U draft (Claude wave B): C of func_L30_0034C1A8, the NTSC-U twin of func_L30_0034D088, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 68 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L30_0034C1A8", whose code is not the PAL one).
 * Worker's note: 68 diff (a shifted word-for-word diff; structure and every constant/offset right): level-clear bookkeeping: idx = D_001D545C-0x1E; if ((u32)idx<6) best[D_001D545C+0x2C] = max(...); if (flag) { D_001D55B0[idx] = min(0xFF, +amount); D_001D55A0[idx] = (<10 ? ...
 */
#include "common.h"

/* localdecomp:start func_L30_0034C1A8 */
typedef struct {
    u8 pad00[0x238];
    s32 w238;
    u8 pad23C[0x1B38 - 0x23C];
    s32 w1B38;
    u8 pad1B3C[0x25F2 - 0x1B3C];
    u8 b25F2;
} G_0034C1A8;

typedef struct {
    u8 pad00[0x60];
    s32 w60[4];
    s16 h70;
    s16 h72;
    u8 b74;
    u8 b75;
    u8 b76;
    u8 b77;
} S_00142660;

extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001426E0[];
extern u8 D_001D55B0[];
extern u16 D_001D55A0[];
extern G_0034C1A8 D_001A4BE0;
extern S_00142660 D_00142660;
extern void func_0038E5B8(s32, s32);
extern void func_00385B60(s32);

void func_L30_0034C1A8(s32 flag, s32 amount, s32 time) {
    s32 idx = D_001D545C - 0x1E;
    u8 *p;
    s32 slot;
    u8 *q;
    u16 *t;
    s32 i;
    s32 a;

    if ((u32)idx < 6) {
        slot = D_001D545C + 0x2C;
        p = &D_001426E0[slot];
        if (*p < amount) {
            *p = amount;
        }
    }
    if (flag != 0) {
        q = &D_001D55B0[idx];
        amount += *q;
        if (amount >= 0xFF) {
            *q = 0xFF;
        } else {
            *q = amount;
        }
        t = &D_001D55A0[idx];
        if (*t < 10) {
            *t = 35999;
        }
        if (time < *t) {
            *t = time;
        }
    }
    D_001426E0[0x52] = 0;
    D_001A4BE0.w238 = 0;
    D_00142660.h72 = 0;
    D_00142660.h70 = 0;
    D_00142660.b74 = 0;
    D_00142660.b76 = 0;
    D_00142660.b75 = 0;
    D_00142660.b77 = 0;
    D_001A4BE0.w1B38 = 0;
    for (i = 3; i >= 0; i--) {
        D_00142660.w60[i] = 0;
    }
    a = D_001426E0[0x50];
    if (a != 0) {
        func_0038E5B8(a == 0xFF ? -1 : a, 1);
    } else {
        func_00385B60(0x10);
        D_001A4BE0.b25F2 = 1;
    }
}
/* localdecomp:end func_L30_0034C1A8 */
