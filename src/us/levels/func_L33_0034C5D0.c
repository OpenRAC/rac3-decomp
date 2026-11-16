#include "common.h"

/* NTSC-U counterpart of func_L33_0034D190 (src/levels/33_vidcomic_2/L33_0034D190.c) */
/* localdecomp:start func_L33_0034C5D0 */
#include "vu0.h"

extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00368E20(void *);
extern void func_00389158(void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00463938(void *, void *, s32, f32, f32);
typedef struct { u8 pad[0x25C0]; void *f25C0; } S_1A4BE0_0034D190;
extern S_1A4BE0_0034D190 D_001A4BE0;
extern vu0_v4 D_L33_001E96A0;
extern u8 D_L33_001E2780[];
extern u8 *D_L33_0021F618[];
extern f32 D_L33_001DD7F8_0034C5D0;
__asm__(".extern D_L33_001DD7F8_0034C5D0, 4");

void func_L33_0034C5D0(u8 *p, vu0_v4 *pos, vu0_v4 *vel) {
    vu0_v4 dir __attribute__((aligned(16)));
    vu0_v4 cur __attribute__((aligned(16)));
    vu0_v4 col __attribute__((aligned(16)));
    vu0_v4 end __attribute__((aligned(16)));
    s32 count = 2;
    s32 i;
    s32 j, k;
    u8 *r;
    f32 f;

    *(vu0_q *)&dir = 0;
    cur = *pos;
    dir.z = -5.0f;
    cur.x += *(f32 *)(p + 0xC0) * 2.5f;
    cur.z += 1.5f;
    for (j = 0; j < 10; j++) {
        vec_add_ab(&end, &cur, &dir);
        if (func_003CE740(&cur, &end, 2, D_001A4BE0.f25C0, 0) != 0) {
            col = D_L33_001E96A0;
            col.y += func_0037E250(-0.5f, 0.5f);
            func_L01_00368E20(&col);
        }
        cur.x -= *(f32 *)(p + 0xC0) * 0.5f;
    }

    for (i = 0; i < count * 4 + 2; i++) {
        func_00389158(vel, vel, D_L33_001E2780, func_0037E250(-2.0f, 1.0f) * 0.017453292f);
        func_00389158(vel, vel, D_L33_001E2780 + 0x20, func_0037E250(-3.0f, 3.0f) * 0.017453292f);
        func_00388830(vel, vel, func_0037E250(D_L33_001DD7F8_0034C5D0 * 0.25f, D_L33_001DD7F8_0034C5D0));
        r = func_L01_0046DCB8(pos, vel, func_0037E208(30, 50), 0x5A182, func_0037E208(1, 4), 0x30, 0, 0, 63000.004f, 42000.0f, 0.0013888889225199819f);
        if (r != 0) {
            r[3] = func_0037E1D8(2) ? 0x48 : 0x44;
            r[2] = *D_L33_0021F618[0x1A4 / 4];
        }
    }

    for (i = 0; i < count * 4; i++) {
        func_00389158(vel, vel, D_L33_001E2780, func_0037E250(-0.5f, 1.0f) * 0.017453292f);
        func_00389158(vel, vel, D_L33_001E2780 + 0x20, func_0037E250(-1.0f, 1.0f) * 0.017453292f);
        f = D_L33_001DD7F8_0034C5D0;
        func_00388830(vel, vel, func_0037E250(f * 0.25f, f - 0.1f));
        r = func_L01_0046DCB8(pos, vel, func_0037E208(30, 50), 0x5A182, func_0037E208(-1, -3), 0x20, 0, 0, 84000.0f, 168000.0f, 0.0013888889225199819f);
        if (r != 0) {
            r[3] = func_0037E1D8(2) ? 0x48 : 0x44;
            r[2] = *D_L33_0021F618[0x5C / 4];
        }
    }

    for (i = 0; i < count * 2 + 2; i++) {
        func_00389158(vel, vel, D_L33_001E2780, func_0037E250(-2.0f, 1.0f) * 0.017453292f);
        func_00389158(vel, vel, D_L33_001E2780 + 0x20, func_0037E250(-3.0f, 3.0f) * 0.017453292f);
        func_00388830(vel, vel, func_0037E250(D_L33_001DD7F8_0034C5D0 * 0.25f, D_L33_001DD7F8_0034C5D0));
        r = func_L01_0046DCB8(pos, vel, func_0037E208(30, 50), 0x5A182, -1, 0x30, 0, 0, 63000.004f, 21000.0f, 0.0011111111380159855f);
        if (r != 0) {
            r[3] = func_0037E1D8(2) ? 0x48 : 0x44;
            r[2] = *D_L33_0021F618[0x88 / 4];
        }
        f = D_L33_001DD7F8_0034C5D0;
        func_00388830(vel, vel, func_0037E250(f * 0.25f, f - 0.1f));
    }

    for (k = 0; k < count * 2 + 2; k++) {
        func_00389158(vel, vel, D_L33_001E2780, func_0037E250(-2.0f, 1.0f) * 0.017453292f);
        func_00389158(vel, vel, D_L33_001E2780 + 0x20, func_0037E250(-3.0f, 3.0f) * 0.017453292f);
        func_00388830(vel, vel, func_0037E250(D_L33_001DD7F8_0034C5D0 * 0.25f, D_L33_001DD7F8_0034C5D0 - 0.1f));
        func_L01_00463938(pos, vel, 0x4005A182, -1.0f, -0.0055555556900799274f);
    }
}
/* localdecomp:end func_L33_0034C5D0 */
