/* functional: high. EXACT MATCH (byte-identical per tools/check.py). EXACT: tools/check.py reports MATCH at its only place (level 35) with the file's own flags. Ported from the NTSC-U draft shape, every constant, callee and global re-derived from PAL asm (0.005f, 105000, 630000, D_L35_0021F3C4[0][1], D_L35_0021F32C[0][0]). */
#include "common.h"
#include "vu0.h"

extern void func_00382580(void *, f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 *D_L35_0021F32C[];

void func_L35_003A5238(u8 *o) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    u8 *q;
    s32 col;

    func_00382580(a, 0.0f, 0.25f);
    col = 0x00FFE69B;
    vec_add_ab(a, a, o + 0x10);
    func_00382580(b, 0.0f, 0.0050000004f);
    if (func_00382468(3) != 0) {
        col = 0x00FFCD36;
    }
    q = func_L01_00475C60(a, b, 0x19, func_00382498(-2, 2), col | 0x7F000000, col, 210000.0f, 105000.0f, 0.0f, 0);
    if (q != 0) {
        q[2] = D_L35_0021F3C4[0][1];
        q[3] = (func_00382468(2) != 0) ? 0x44 : 0x48;
    }
    q = func_L01_00475C60(o + 0x10, D_L35_001D66B0, 2, 1, 0x7FFFCD36, 0x7FFFCD36, 630000.0f, 630000.0f, 0.0f, 0);
    if (q != 0) {
        q[2] = D_L35_0021F32C[0][0];
        q[3] = (func_00382468(2) != 0) ? 0x44 : 0x48;
    }
}
