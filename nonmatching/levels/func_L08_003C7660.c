/* NTSC-U draft (2026-11-14, Claude worker): C of func_L08_003C5360, the NTSC-U twin of func_L08_003C7660, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/08_aquatos/L08_003C7660.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L08_003C7660 (src/levels/08_aquatos/L08_003C7660.c) */
/* localdecomp:start func_L08_003C5360 */
typedef struct { u8 b[0x80]; } Snd80_003C5360;
extern Snd80_003C5360 D_001A30B0[];
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L08_003C50F0(void *, void *, void *);
extern s32 func_00388398(void *);
extern void func_0039FB08(s32);

void func_L08_003C5360(u8 *self) {
    u8 *s = *(u8 **)(self + 0x68);
    vu0_v4 v;
    s32 i;
    s32 j;
    Snd80_003C5360 *e;

    switch (self[0x20]) {
    case 0:
        *(f32 *)(s + 0x14) = *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
        func_003886E8(s, self + 0xD0, -1.0f);
        *(s32 *)(s + 0x10) = func_0037E208(0x5A, 0xAA);
        func_L01_00441FB8(self, 1, -1);
        break;
    case 1:
        i = *(s32 *)(s + 0x18);
        if (i == -1 || (e = &D_001A30B0[i], *(u8 **)&e->b[0xDC] != self) || e->b[0xD0] == 0) {
            *(s32 *)(s + 0x18) = func_0039FE80(0, 4, self);
        }
        func_003886E8(&v, self + 0xD0, *(f32 *)(s + 0x14) * -0.752f);
        vec_add_ba(&v, self + 0x10, &v);
        func_L08_003C50F0(self, &v, s);
        if (func_00388398(s + 0x10) != 0) {
            func_L01_00441FB8(self, 2, -1);
        }
        /* falls into case 2 */
    case 2:
        j = *(s32 *)(s + 0x18);
        if (j != -1 && (e = &D_001A30B0[j], *(u8 **)&e->b[0xDC] == self) && e->b[0xD0] != 0) {
            func_0039FB08(j);
        }
        *(s32 *)(s + 0x18) = -1;
        break;
    }
    self[0xA8] = 0xFF;
}
/* localdecomp:end func_L08_003C5360 */
