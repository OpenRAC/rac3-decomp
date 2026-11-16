/* Near miss (open-rac-engine: agent_comet_spawn). Same instructions as retail (the lock-on call takes the
 * position too: func_L01_00457588(target, pos, len, dir), pointers before the float), 68 words differ, all
 * from two allocation choices and the scheduling that follows them: retail has the pvars in $s0 and the moby
 * in $s1 (here the moby, 14 refs against 12, outranks the pvars), and dir in $s2 with a5 and the hero base
 * sharing $s3 (here the hero base, priority 0.136, outranks dir, 0.128); -0.15/0.15 are $f20/$f21 in retail,
 * $f21/$f20 here. Tried: the pvar load before or after the first stores, an early return. */
#include "common.h"
typedef int u128_t_396 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3968F8;
typedef struct {
    u128_t_396 vel;                /* 0x00 */
    u8 pad10[0x50 - 0x10];
    s32 x50;
    f32 rand_a;                    /* 0x54 */
    f32 rand_b;                    /* 0x58 */
    s32 x5c;
    s32 x60;
    s32 x64;
    s32 x68;
    s32 x6c;
    s32 x70;
    s32 x74;
} P_3968F8;
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
    P_3968F8 *pvar;                /* 0x68 */
    u8 pad6c[0x78 - 0x6c];
    u32 colour;                    /* 0x78 */
} M_3968F8;
typedef struct { u8 pad0[0xBD8]; void *lock_target; } H_3968F8;
extern s32 D_L01_001DE0B0;
__asm__(".extern D_L01_001DE0B0, 4");
extern f32 D_L01_001DE0B4;
__asm__(".extern D_L01_001DE0B4, 4");
extern f32 D_L01_001DE0B8;
__asm__(".extern D_L01_001DE0B8, 4");
extern s32 D_L01_001E2030;
__asm__(".extern D_L01_001E2030, 4");
extern s32 D_L01_001E2034;
__asm__(".extern D_L01_001E2034, 4");
extern s32 D_L01_001E2038;
__asm__(".extern D_L01_001E2038, 4");
extern H_3968F8 D_001A4BE0;
extern void *func_003C24B0(s32 class_id, s32 flags);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32 a, f32 b);
extern f32 func_0038CEA8(V4_3968F8 *v);
extern void func_L01_00457588(void *target, void *from, f32 s, V4_3968F8 *v);
extern void func_0038CF68(void *dst, void *src, f32 s);
extern s32 func_L01_004C85C8(void *moby, void *a1, f32 a2, f32 a3, f32 a4);

/* agent_comet_spawn: the agents' comet (class 0x1893), scale 0.025 */
M_3968F8 *func_L01_003968F8(M_3968F8 *owner, s32 a1, u128_t_396 *pos, V4_3968F8 *dir, s32 a4, s32 a5) {
    M_3968F8 *m;
    P_3968F8 *pv;
    V4_3968F8 v;
    f32 len, r;
    s32 s, a, b;

    m = (M_3968F8 *)func_003C24B0(0x1893, 0x80);
    if (m != 0) {
        m->state = 0;
        pv = m->pvar;
        m->x30 = 0xFF;
        m->draw_dist = 0xFF;
        pv->rand_a = func_00382538();
        pv->rand_b = func_003824E0(0.446804314852f, 0.753982305527f);
        pv->x74 = a5;
        pv->x64 = *(s16 *)((u8 *)owner + 0xAA);
        pv->x6c = 0;
        m->flags |= 0x100;
        m->opacity = 0x50;
        m->pos = *pos;
        m->scale = 0.0250000003725f;
        m->colour = 0x7F4080FF;
        pv->x70 = a4;
        pv->x60 = a1;
        if (D_L01_001DE0B0 == 0) {
            s = *(s32 *)((u8 *)owner->pvar + 8);
            D_L01_001E2030 = s;
            a = func_L01_00395498(s + 0x100);
            D_L01_001E2034 = a;
            b = func_L01_00395498(a + 0x4B00);
            D_L01_001E2038 = b;
            func_L01_00395498(b + 0xA0);
            D_L01_001DE0B0 = 1;
        }
        if (D_001A4BE0.lock_target != 0) {
            len = func_0038CEA8(dir);
            if (len == 0.0f) len = 1.0f;
            func_L01_00457588(D_001A4BE0.lock_target, pos, len, dir);
        }
        pv->vel = *(u128_t_396 *)dir;
        v = *dir;
        v.x += func_003824E0(-0.150000005960f, 0.150000005960f);
        v.y += func_003824E0(-0.150000005960f, 0.150000005960f);
        func_0038CF68(&v, &v, func_003824E0(D_L01_001DE0B8 * 0.0200000014156f, D_L01_001DE0B4 * 0.0200000014156f) * 0.5f);
        pv->x5c = 0x60;
        pv->x50 = 0x237;
        pv->x68 = func_L01_004C85C8(m, 0, 1.0f, 1.0f, 1.0f);
    }
    return m;
}
