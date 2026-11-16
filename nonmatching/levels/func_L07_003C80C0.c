/* PAL level-07 reconstruction from the owned retail ELF (Wave2 P04).
 * Near miss: stock tools/check.py reports 4 diff with the owning-file flags.
 * Two stack stores are interchanged; the flag load/test uses v0 rather than v1. Three formulations retained these same wrong instructions.
 * Checked with the owning file's normal prelude/earlier declarations; not linked.
 */
#include "common.h"
typedef int Q_003C80C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003C80C0;
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32,
    f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L07_003C86D0(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
extern void func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L07_004522E8(void *, s32, void *, f32);
extern f32 D_L07_001E1EC0[];
extern s32 D_L07_001DEF40;
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
void func_L07_003C80C0(u8 *self) {
    u8 *p = *(u8 **)(self + 0x68);
    V_003C80C0 pos;
    if (func_L01_00452FB0(self, p + 0x70, 0, 0, 0)) *(s32 *)(p + 0x188) &= ~0x10;
    if (*(f32 *)(p + 0x30) <= 0.0f) {
        *(Q_003C80C0 *)&pos = *(Q_003C80C0 *)(self + 0x10);
        pos.z += *(f32 *)(p + 0x40);
        func_L01_003303B8(&pos, 0, 10, 5, 4, 10, 15, 0, 0.5f, 0.0f, 0.0f, 2.0f,
            0, 0, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L01_00451FE0(self, 0x7FFF, D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 255,
            -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
        func_L01_004443E8(self, 0, 3);
        func_L07_003C86D0(self);
        func_003A52A0(8, 0, self);
        return;
    }
    if (*(s32 *)(p + 0x228) == 1 || *(s32 *)(p + 0x228) == 11) {
        qzero(&pos);
        func_L01_00446A70(self, self, 0x10000, &pos, &pos, (f32)*(s16 *)(p + 0x34));
    } else if (p[0x5E] || p[0x60] || p[0x3E] == 2) {
        func_L01_004443E8(self, 0, 3);
        func_L07_003C86D0(self);
        return;
    }
    func_L01_00452860(self, p + 0x30, 0);
    if (p[0x5F]) {
        func_L01_00456BD0(self, 5);
        if ((D_L07_001DEF40 & 15) == (((s32)self >> 8) & 15))
            func_L01_00456C98(self, self[0x20] >= 8 ? *(s32 *)(p + 0x498) : *(s32 *)(p + 0x490),
                0, 0, 0, 0, 3, 0, 0, 0, self[0x20] >= 8 ? *(f32 *)(p + 0x49C) : *(f32 *)(p + 0x494), 10.0f, 1.0f);
    } else {
        func_L01_00456BD0(self, 3);
        if ((D_L07_001DEF40 & 15) == (((s32)self >> 8) & 15))
            func_L01_00456C98(self, self[0x20] >= 8 ? *(s32 *)(p + 0x498) : *(s32 *)(p + 0x490),
                0, 0, 0, 0, 1, 0, 0, 0, self[0x20] >= 8 ? *(f32 *)(p + 0x49C) : *(f32 *)(p + 0x494), 10.0f, 1.0f);
    }
    func_L07_004522E8(self, 8, p + 0x400, 2.5f);
    if (self[0x31] && func_L01_0040E548(D_L07_001E1EC0, self + 0x10) < 576.0f) {
        func_L01_004472C0(self);
        self[0x6F] = 22;
    }
    if (self[0x20] >= 24) {
        if (*(s32 *)(p + 0x4D8) == -1) *(s32 *)(p + 0x4D8) = func_003A52A0(11, 4, self);
    } else if (*(s32 *)(p + 0x4D8) != -1) {
        func_003A4F28(*(s32 *)(p + 0x4D8));
        *(s32 *)(p + 0x4D8) = -1;
    }
}
