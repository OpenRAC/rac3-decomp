#include "common.h"

/* NTSC-U counterpart of func_L20_004026A0 (src/levels/20_final_boss/L20_004026A0.c) */
/* localdecomp:start func_L20_004002F8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x24];
    f32 scale;
    s16 n1max, n1min;
    s16 n2max, n2min;
    f32 f30;
    f32 f34;
    u8 pad38[0x40 - 0x38];
    s32 i40;
    s32 i44;
    u8 pad48[0x4C - 0x48];
    s16 chance;
    u8 pad4E[2];
    s16 timer;
} S_004026A0;
extern u8 D_L20_00220258_004002F8[];
extern u8 *func_003BCFB0(s32, s32);
extern void func_L20_004001F0(void *, void *);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_0044C900(s32, s32, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L20_00400140(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);

void *func_L20_004002F8(void *arg) {
    S_004026A0 *a = arg;
    u8 *m = func_003BCFB0(0x1F8C, 0x30);
    if (a != 0 && m != 0) {
        vu0_v4 pos;
        vu0_v4 dir;
        f32 spd;
        s32 n;
        s32 i;
        s32 j;
        u8 *p;
        func_L20_004001F0(m, a);
        n = func_0037E208(a->n1min, a->n1max);
        spd = a->scale * func_0037E250(0.0f, 0.015f);
        for (i = 0; i < n; i++) {
            s32 k = func_0037E208(0x50, 0x64);
            f32 r = func_0037E250(0.9f, 1.5f);
            f32 s = a->scale * r;
            f32 d = a->scale * a->f30;
            f32 s2;
            f32 yaw;
            pos = *(vu0_v4 *)(m + 0x10);
            yaw = func_0037E250(-3.1415927f, 3.1415927f);
            s2 = s + s;
            func_L01_0044C900((s32)&pos, (s32)&pos, d, yaw, func_0037E250(-3.1415927f, 3.1415927f));
            vec_sub_ab(&dir, &pos, m + 0x10);
            func_00388830(&dir, &dir, spd);
            p = func_L01_00472438(&pos, &dir, k, func_0037E208(-1, 1), a->i40, 0, 0, s * 210000.0f, s2 * 210000.0f, 0.0f);
            if (p != 0) {
                u8 *g = D_L20_00220258_004002F8;
                p[9] = 0xF2;
                p[2] = (*(u8 **)(g + 0x184))[3];
                if (a->chance > 0 && func_0037E1D8(a->chance) == 0) {
                    p[3] = 0x44;
                }
            }
        }
        n = func_0037E208(a->n2min, a->n2max);
        for (j = 0; j < n; j++) {
            f32 d;
            f32 yaw;
            s32 life;
            s32 k;
            pos = *(vu0_v4 *)(m + 0x10);
            d = a->scale * a->f30;
            yaw = func_0037E250(-3.1415927f, 3.1415927f);
            func_L01_0044C900((s32)&pos, (s32)&pos, d, yaw, func_0037E250(-3.1415927f, 3.1415927f));
            vec_sub_ab(&dir, &pos, m + 0x10);
            func_00388830(&dir, &dir, a->scale * func_0037E250(0.15f, 0.3f));
            life = func_L01_00440918(2.0f, 5.0f);
            k = func_0037E208(0x1E, 0x28);
            p = func_L01_0046DCB8(&pos, &dir, k, a->i44, life, 0x7F, 0x7F, a->scale * (func_0037E250(0.1f, 0.2f) * 210000.0f), 0.0f, 0.0f, 1);
            if (p != 0) {
                p[9] = 0xF2;
            }
        }
        if (a->f34 > 0.0f) {
            func_L20_00400140(m, a);
        }
        if (a->timer <= 0) {
            func_L01_00441FB8(m, 2, -1);
        } else {
            func_L01_00441FB8(m, 1, -1);
            *(u16 *)(m + 0x96) = a->timer;
        }
    }
    return m;
}
/* localdecomp:end func_L20_004002F8 */
