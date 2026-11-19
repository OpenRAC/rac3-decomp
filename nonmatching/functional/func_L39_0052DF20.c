/* functional: medium. Per-frame four-corner ground-contact/suspension step of the multiplayer vehicle controller (arg is the controller's state block): raycasts each corner, accumulates spring pushes into s+0x660[i] / s+0x6A0, tracks per-corner compression s+0x6B0[i], reacts to special surface ids, and updates the airborne/landing flags. Raw offsets (no struct layout known) */
#include "vu0.h"
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(s32);
extern void func_L39_00626D18(void *);
extern void func_L39_00667208(void *, s32, s32, s32);
extern void func_003C4138(void *, f32, f32);
extern vu0_v4 D_L39_00243F20;
extern f32 D_L39_0024D510[];
extern f32 D_L39_0024AC68[];
extern f32 D_L39_0024AC58[];
__asm__(".extern D_L39_0024AB40, 16");
extern vu0_v4 D_L39_0024AB40[] __attribute__((section(".sdata")));
typedef struct {
    u8 pad0[0x18];
    u8 *f18;
    u8 pad1C[4];
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
} Hit_0052DF20;
extern Hit_0052DF20 D_L39_0025F740;

void func_L39_0052DF20(u8 *s) {
    vu0_v4 v0 __attribute__((aligned(16)));
    vu0_v4 v10 __attribute__((aligned(16)));
    vu0_v4 v20 __attribute__((aligned(16)));
    vu0_v4 v30 __attribute__((aligned(16)));
    vu0_v4 v40 __attribute__((aligned(16)));
    vu0_v4 v50 __attribute__((aligned(16)));
    u8 *q = *(u8 **)(s + 0x6D0);
    u8 *r = *(u8 **)(q + 0x2D0);
    s32 flag0 = s[0x713];
    s32 grounded = 1;
    s32 fp = (*(s32 *)(q + 0x2F8) >> 2) & 1;
    s32 remaining;
    s32 i;
    s32 hit;
    s32 kind;
    s32 id;
    u8 *t;
    u8 *p;
    f32 sum = 0.0f;
    f32 f20, f21, f22;
    f32 *cmp;

    func_0038CE20(&v40, &D_L39_00243F20, -0.002f);
    qzero(&v20);
    if (*(s32 *)(s + 0x7A8) != 0) {
        *(f32 *)(r + 0x18) += *(f32 *)(s + 0x7A4);
        *(s32 *)(s + 0x7A8) = 0;
    }
    s[0x713] = 0;
    q[0x300] = grounded;
    remaining = 4;
    for (i = 0; i < 4; i++) {
        *(vu0_q *)&v30 = *(vu0_q *)&D_L39_0024AB40[i];
        func_0038D000(&v0, &v30, r + 0xC0);
        vec_add_ab(&v0, &v0, r + 0x10);
        *(vu0_q *)&v10 = *(vu0_q *)&v0;
        v0.z += 1.5f;
        v10.z -= D_L39_0024D510[i];
        hit = func_003D3CB0(&v0, &v10, 0xC24, r, 0);
        cmp = (f32 *)(s + 0x6B0) + i;
        if (hit != 0) {
            kind = func_003D5630(flag0);
            remaining--;
            t = D_L39_0025F740.f18;
            id = -1;
            if (t != 0) {
                id = *(s16 *)(t + 0xAA);
            }
            if (id >= 0 && fp != 0) {
                if (id == 0x1B23 || id == 0x19AF || id == 0x19B2 || id == 0x1A29) {
                    grounded = 0;
                }
            }
            if (!(D_L39_0025F740.f18 != 0 && id == 0x10C4)) {
                if (kind == 0xD || kind == 3 || kind == 0xB) {
                    if (0.0f < *(f32 *)(q + 0x308)) {
                        *(u16 *)(s + 0x710) |= 8;
                        if ((u32)(r[0xBC] - 9) >= 2) {
                            if (*(u8 **)(q + 0x2D8) != 0) {
                                func_L39_00626D18(*(u8 **)(q + 0x2D8));
                            }
                            if (*(u8 **)(q + 0x2DC) != 0) {
                                func_L39_00626D18(*(u8 **)(q + 0x2DC));
                            }
                        }
                        if (fp != 0) {
                            func_L39_00667208(q, -1, 0xE, -1);
                        }
                    }
                }
            }
            *(vu0_q *)&v30 = *(vu0_q *)&D_L39_0025F740.v40;
            func_0038CF68(&v20, &v30, 1.0f);
            if (v20.z < 0.707f) {
                continue;
            }
            if (s[0x715] == 1 && *(s16 *)(s + 0x71A) >= 0x26) {
                if (kind == 5) {
                    s[0x713] = 1;
                }
            }
            q[0x300] = 0;
            vec_sub_ab(&v30, &D_L39_0025F740.v20, &v0);
            f20 = func_0038CEA8(&v30) - 1.5f;
            if (f20 < 0.0f) {
                *(f32 *)(r + 0x18) -= f20;
                f20 = 0.0f;
            }
            f22 = D_L39_0024AC68[i] - f20;
            func_0038D028(&v50, &v20, q + 0x1B0);
            f20 = D_L39_0024D510[i] - f20;
            f21 = f20 / D_L39_0024D510[i];
            f20 = f20 * 0.025f;
            if (s[0x713] != 0 && i >= 2 && *(s16 *)(s + 0x71A) >= 0x26) {
                f20 = f20 * 0.5f;
            }
            func_0038CE20(&v30, &v50, f20);
            vec_add_ab((f32 *)(s + 0x660) + i * 4, (f32 *)(s + 0x660) + i * 4, &v30);
            func_0038CE20(&v30, &D_L39_00243F20, f20 * (f21 * 0.275f * f21));
            vec_add_ab(s + 0x6A0, s + 0x6A0, &v30);
            *cmp = f22;
        } else {
            if (flag0 == 0 || *(s16 *)(q + 0x302) >= 9) {
                vec_add_ab((f32 *)(s + 0x660) + i * 4, (f32 *)(s + 0x660) + i * 4, &v40);
            }
            func_003C4138(cmp, D_L39_0024AC58[i], 0.04f);
        }
        sum += D_L39_0024D510[i] - *cmp;
    }
    if (remaining >= 2 && fp != 0) {
        *(s32 *)(q + 0x2F8) &= ~0x800;
    }
    if (flag0 != 0 && q[0x300] != 0 && *(s16 *)(q + 0x302) < 0x25) {
        s[0x713] = 1;
    }
    if (*(s16 *)(s + 0x754) == 0) {
        *(s32 *)(s + 0x7A8) = 1;
        func_003C4138(s + 0x7A4, (1.0f - (sum * 0.25f) / D_L39_0024D510[0]) * -0.8f, 0.04f);
        *(f32 *)(r + 0x18) -= *(f32 *)(s + 0x7A4);
    }
    if (fp != 0 && grounded != 0) {
        *(s32 *)(q + 0x2F8) |= 0x800;
    } else {
        *(s32 *)(q + 0x2F8) &= ~0x800;
    }
}
