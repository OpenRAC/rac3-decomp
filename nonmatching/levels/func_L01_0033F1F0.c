/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_0033EA68, the NTSC-U twin of func_L01_0033F1F0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0033E0C8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_0033F1F0 (src/levels/shared/L01_0033E0C8.c).
 * Byte-exact only with -mvu0-use-vf0-vf2 and @ps2as ADDED and -mno-split-addresses DROPPED on the PAL line (L01_0033E0C8.c:
 * -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses), plus the divs row 'func_L01_0033EA68 2'. The four floats of
 * func_L01_004633E8 sit before the last two integer arguments in its prototype so the float loads are emitted first. */
/* localdecomp:start func_L01_0033EA68 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[2];
    u8 bA;
    u8 bB;
} __attribute__((aligned(16))) Inner_0033EA68;

typedef struct {
    u8 pad0[0xA];
    s16 hA;
    u8 padC[0x14];
    Inner_0033EA68 in;
} __attribute__((aligned(16))) Part_0033EA68;

extern vu0_v4 D_L01_001E2A40;
extern f32 D_001DD0A8_sda;
extern s32 D_001DD0B8_sda;
extern u16 D_001DD0BC_sda;
extern f32 D_001DD0C0_sda;
extern f32 D_001DD0C4_sda;
extern s32 D_001DD0C8_sda;
extern u8 D_001DD0CC_sda;
extern f32 D_001DD0D0_sda;
__asm__(".extern D_001DD0A8_sda, 4");
__asm__(".extern D_001DD0B8_sda, 4");
__asm__(".extern D_001DD0BC_sda, 2");
__asm__(".extern D_001DD0C0_sda, 4");
__asm__(".extern D_001DD0C4_sda, 4");
__asm__(".extern D_001DD0C8_sda, 4");
__asm__(".extern D_001DD0CC_sda, 1");
__asm__(".extern D_001DD0D0_sda, 4");
extern void func_00389158(void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern Part_0033EA68 *func_L01_004633E8(void *, s32, void *, f32, f32, f32, f32, u32, s32);

void func_L01_0033EA68(u8 *self) {
    f32 axis[4] __attribute__((aligned(16)));
    f32 dir[4] __attribute__((aligned(16)));
    f32 rot[4] __attribute__((aligned(16)));
    f32 vel[4] __attribute__((aligned(16)));
    f32 step;
    s32 i;
    s32 r;
    s32 s;
    u32 fl;
    Part_0033EA68 *p;
    Inner_0033EA68 *in;

    *(s128 *)axis = 0;
    axis[2] = D_001DD0A8_sda;
    vec_sub_ab(dir, &D_L01_001E2A40, self + 0x10);
    step = 6.2831855f / (f32)D_001DD0B8_sda;
    for (i = 0; i < D_001DD0B8_sda; i++) {
        func_00389158(rot, axis, dir, (f32)i * step);
        func_00388830(vel, rot, D_001DD0C0_sda * 0.016666668f);
        r = func_0037E1D8(0x10);
        s = func_0037E1D8(2);
        fl = D_001DD0C8_sda;
        p = func_L01_004633E8(self + 0x10, s == 0 ? r : -r, vel, 0.5f, 1.0f, D_001DD0D0_sda, D_001DD0C4_sda * 210000.0f, fl, 0);
        if (p != 0) {
            in = &p->in;
            p->hA = D_001DD0BC_sda;
            in->w4 = 2;
            in->bA = D_001DD0CC_sda;
            in->bB = p->hA;
        }
    }
}
/* localdecomp:end func_L01_0033EA68 */
