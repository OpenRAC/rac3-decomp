#include "common.h"

/* NTSC-U counterpart of func_L03_003D02A0 (src/levels/shared/L03_003D02A0.c) */
/* localdecomp:start func_L03_003CE270 */
#include "vu0.h"
typedef int Q_003CE270 __attribute__((mode(TI)));
extern f32 D_L01_001D66B0;
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_00426140(void *, void *, s32, s32, void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L03_003CE160(u8 *, s32, s32);
void func_L03_003CE270(u8 *m, s32 cls, s32 row, s32 spawn, s32 fx1, s32 fx2, s32 fx3, s32 flip, s32 color, f32 a, f32 b) {
    f32 pos[4];
    f32 off[4];
    s16 r = row;
    f32 *p;
    func_0039FE80(0, 0, m);
    func_L01_0044ED60(m, cls, &D_L01_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    if (spawn) {
        func_L03_003CE160(m, spawn, flip);
    }
    p = pos;
    *(Q_003CE270 *)p = *(Q_003CE270 *)(m + 0x10);
    *(Q_003CE270 *)off = ((Q_003CE270 *)m)[r + 12];
    func_00388830(off, off, *(f32 *)(m + 0x2C) / (*(f32 **)(m + 0x24))[0x24 / 4] * a);
    pos[2] += *(f32 *)(m + 0x2C) / (*(f32 **)(m + 0x24))[0x24 / 4] * b;
    vec_add_ab(p, p, off);
    if (fx1) {
        func_L02_00426140(m, p, 0x14, 0, &D_L01_001D66B0, color, 0, 0x5A, 4.0f, 0.1666666716f, 0.7f, 1.3f);
    }
    if (fx2) {
        func_L02_003E0520(m, p, 1.0f, &D_L01_001D66B0, 0xF, 0, 0.04166666791f, 2.5f, 5.0f, 1.0f, 1);
    }
    if (fx3) {
        func_L01_0032FE90(p, 0, 0, 0, 0, 2, 5, 0, 1.0f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x7FD68F, 0xFF8400, 0, 0, 0, 0, 0x7F60A0FF, 0x280000FF, 0, 0);
    }
    func_L01_0044EBF8(m, 1, 0.0f);
    func_003BD360(m);
}
/* localdecomp:end func_L03_003CE270 */
