#include "common.h"

typedef struct {
    f32 value;
    s32 pad;
} Item_408D28;

LINKER_REMNANT("asm/levels", func_L01_0040A8B8);

INCLUDE_ASM("asm/levels", func_L01_0040A8C0);

INCLUDE_ASM("asm/levels", func_L01_0040AAC8);

LINKER_REMNANT("asm/levels", func_L01_0040AF50);

/* localdecomp:start func_L01_0040AF60 */
extern s32 D_L01_001D6694[];

s32 func_L01_0040AF60(void) {
    return D_L01_001D6694[0] == 0;
}
/* localdecomp:end func_L01_0040AF60 */

/* localdecomp:start func_L01_0040AF70 */
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
extern void func_0038CE20(f32 *, f32 *, f32);
extern f32 D_L01_001DFA60[];
extern f32 D_L01_001DFA64[];
extern f32 D_L01_001DFA68[];

void func_L01_0040AF70(f32 *dir, f32 *a, f32 *b, f32 *p, f32 lo, f32 hi) {
    s32 i;
    f32 va[4];
    f32 vb[4];
    f32 t;

    for (i = 0; i < 4; i++) {
        func_0038CDF8(va, a, b, p[i * 2]);
        t = p[i * 2 + 1] - 0.5f;
        func_0038CE20(vb, dir, (lo + (hi - lo) * p[i * 2]) * (t + t));
        D_L01_001DFA60[i * 3] = va[0] + vb[0];
        D_L01_001DFA64[i * 3] = va[1] + vb[1];
        D_L01_001DFA68[i * 3] = va[2] + vb[2];
    }
}
/* localdecomp:end func_L01_0040AF70 */

INCLUDE_ASM("asm/levels", func_L01_0040B0B0);

/* localdecomp:start func_L01_0040B138 */

extern u32 D_L01_001DBCA0;
extern s32 D_L01_001DFA90[];

extern s32 func_0038DBD8(u32 a, u32 b, f32 f);

void func_L01_0040B138(u32 a, u32 b, Item_408D28 *items) {
    s32 i;
    if ((a & 0xFF000000) > 0x80000000 || (b & 0xFF000000) > 0x80000000) {
        D_L01_001DBCA0 |= 1;
    }
    for (i = 0; i < 4; i++) {
        D_L01_001DFA90[i] = func_0038DBD8(a, b, items[i].value);
    }
}
/* localdecomp:end func_L01_0040B138 */

INCLUDE_ASM("asm/levels", func_L01_0040B1F0);

/* localdecomp:start func_L01_0040B300 */
extern s32 D_L01_001DFA90[];
extern f32 D_L01_001DFA60[];
extern u8 D_L01_001DFAA0[];
extern f32 func_L01_0040B0B0(s32 a0, f32 f12, f32 *a1, s32 a2);
extern void func_003A9440(s32 a0, long a1);
extern void func_003D3A24(s32 a0, u8 *a1, u8 *a2, u8 *a3, s32 t0);
void func_L01_0040B300(s32 a0, f32 *a1, f32 *a2, s32 a3, s32 t0, s32 t1, f32 f12) {
    f32 f;
    f = func_L01_0040B0B0(a0, f12, a1, t0);
    if (a3 != 0) {
        *a1 = f;
    }
    func_003A9440(66, 0x8000000048UL);
    f = func_L01_0040B0B0(a0, f12, a2, t1);
    if (a3 != 0) {
        *a2 = f;
    }
    func_003D3A24(4, ((u8 *)&D_L01_001DFA60), ((u8 *)&D_L01_001DFA90), D_L01_001DFAA0, 1);
}
/* localdecomp:end func_L01_0040B300 */

INCLUDE_ASM("asm/levels", func_L01_0040B3C0);

INCLUDE_ASM("asm/levels", func_L01_0040B858);

INCLUDE_ASM("asm/levels", func_L01_0040BE10);
