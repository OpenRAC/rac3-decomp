#include "common.h"
/* localdecomp:start func_U_L01_00395480 */
typedef int u128_t_396 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3968F8;
typedef struct {
    u8 pad0[0x10];
    u128_t_396 pos;                /* 0x10 */
    s8 state;                      /* 0x20 */
    u8 pad21[2];
    u8 opacity;                    /* 0x23 */
    u8 pad24[8];
    f32 scale;                     /* 0x2C */
    u8 x30;
    u8 pad31;
    s16 draw_dist;                 /* 0x32 */
    u16 flags;                     /* 0x34 */
    u8 pad36[0x68 - 0x36];
    u8 *pvar;                      /* 0x68 */
    u8 pad6c[0x78 - 0x6c];
    u32 colour;                    /* 0x78 */
} M_3968F8;
typedef struct { u8 pad0[0xBD8]; void *lock_target; } H_3968F8;
extern s32 D_L01_001DE0F0_00395480;
__asm__(".extern D_L01_001DE0F0_00395480, 4");
extern f32 D_L01_001DE0F4;
__asm__(".extern D_L01_001DE0F4, 4");
extern f32 D_L01_001DE0F8;
__asm__(".extern D_L01_001DE0F8, 4");
extern s32 D_L01_001E20B0_00395480;
__asm__(".extern D_L01_001E20B0_00395480, 4");
extern s32 D_L01_001E20B4;
__asm__(".extern D_L01_001E20B4, 4");
extern s32 D_L01_001E20B8;
__asm__(".extern D_L01_001E20B8, 4");
extern H_3968F8 D_001A4BE0;
extern void *func_003BCFB0(s32 class_id, s32 flags);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32 a, f32 b);
extern f32 func_00388770(V4_3968F8 *v);
extern void func_L01_00454298(void *target, void *from, f32 s, V4_3968F8 *v);
extern void func_00388830(void *dst, void *src, f32 s);
extern s32 func_L01_00394020(s32 n);
extern s32 func_L01_004C4A18(void *moby, void *a1, f32 a2, f32 a3, f32 a4);

/* from rac2-decomp's func_L00_003DBF50 */
/* agent_comet_spawn: the agents' comet (class 0x1893), scale 0.025 */
M_3968F8 *func_U_L01_00395480(M_3968F8 *owner, s32 a1, u128_t_396 *pos, V4_3968F8 *dir, s32 a4, s32 a5) {
    M_3968F8 *m;
    u8 *pv;
    V4_3968F8 v;
    f32 len;
    s32 s, a, b;

    m = (M_3968F8 *)func_003BCFB0(0x1893, 0x80);
    if (m != 0) {
        m->state = 0;
        pv = m->pvar;
        m->x30 = 0xFF;
        m->draw_dist = 0xFF;
        *(f32 *)(pv + 0x54) = func_0037E2A8();
        *(f32 *)(pv + 0x58) = func_0037E250(0.372336924f, 0.628318548f);
        *(s32 *)(pv + 0x64) = *(s16 *)((u8 *)owner + 0xAA);
        *(s32 *)(pv + 0x6C) = 0;
        *(s32 *)(pv + 0x74) = a5;
        *(u128_t_396 *)((u8 *)m + 0x10) = *pos;
        m->opacity = 0x50;
        m->flags |= 0x100;
        m->scale = 0.0250000003725f;
        m->colour = 0x7F4080FF;
        *(s32 *)(pv + 0x70) = a4;
        *(s32 *)(pv + 0x60) = a1;
        {
            u8 *ps = owner->pvar;

            if (D_L01_001DE0F0_00395480 == 0) {
                s = *(s32 *)(ps + 8);
                D_L01_001E20B0_00395480 = s;
                a = func_L01_00394020(s + 0x100);
                D_L01_001E20B4 = a;
                b = func_L01_00394020(a + 0x4B00);
                D_L01_001E20B8 = b;
                func_L01_00394020(b + 0xA0);
                D_L01_001DE0F0_00395480 = 1;
            }
        }
        if (D_001A4BE0.lock_target != 0) {
            len = func_00388770(dir);
            if (len == 0.0f) {
                len = 1.0f;
            }
            func_L01_00454298(D_001A4BE0.lock_target, pos, len, dir);
            *(u128_t_396 *)pv = *(u128_t_396 *)dir;
        } else {
            *(u128_t_396 *)pv = *(u128_t_396 *)dir;
        }
        v = *dir;
        v.x += func_0037E250(-0.150000005960f, 0.150000005960f);
        v.y += func_0037E250(-0.150000005960f, 0.150000005960f);
        func_00388830(&v, &v, func_0037E250(D_L01_001DE0F8 * 0.0166666675f, D_L01_001DE0F4 * 0.0166666675f) * 0.5f);
        *(s32 *)(pv + 0x5C) = 0x60;
        *(s32 *)(pv + 0x50) = 0x2A8;
        *(s32 *)(pv + 0x68) = ((s32 (*)(void *, f32, f32, f32, s32))func_L01_004C4A18)(m, 1.0f, 1.0f, 1.0f, 0);
    }
    return m;
}
/* localdecomp:end func_U_L01_00395480 */
