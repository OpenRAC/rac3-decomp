/* func_L01_003036D8 (Claude wave 14 r55, 2026-11-28). First draft kept here. */
/* First draft of func_L01_003036D8 (fresh entry; worker r55, wave 14), from the retail assembly and the
 * native port's functional C. Not a match under its file's line: retail is split-address code (the
 * %hi of D_L01_001EAA18 is built with lui $v0 in three delay slots and used at the join, 0x388-0x3C4),
 * so it needs the existing line '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2'
 * (tools/check.py --mode S). With --mode S the opcode sequence is right except: the spark block computes
 * &q.pos (s0 = sp+0x30, s6 = s0) before the 0.04/0.08 call where retail does it at the 0.2/0.99 call
 * (one nop left in that call's delay slot); func_L01_003FB640's argument order (retail: li.s 0.3 first);
 * the tail: retail cross-jumps the two func_L01_0044AF78 calls (common tail from mov.s f14), keeps the
 * -1 stack argument in a1 and branches beql to the shared p restore; this C keeps two full calls.
 * Layout: q is the collision record (0x30 bytes at sp+0x30) whose later quadwords hold the spark
 * temporaries, as retail's one stack area. The thresholds are copied before the store of the spin
 * (retail loads D_L01_001DFB4C before the swc1), and the owner and &p are taken before
 * func_L01_004CB320 (retail: lw s0 in its delay slot, addiu s1 before it). */
#include "common.h"

/* localdecomp:start func_L01_003036D8 */
/* The collision query record that func_003D3CB0 / func_003D4D00 read: its first
   vector is the spark position, and the spark code keeps its two temporaries in
   the record's later quadwords (retail's one stack area at 0x30..0x5F). */
typedef struct {
    vu0_v4 pos;                     /* 0x00 */
    union {
        vu0_v4 v;                   /* spark velocity */
        struct {
            s32 pad10[2];
            u8 b18;
            u8 pad19;
            s16 h1A;
            s32 pad1C;
        } r;
    } u10;                          /* 0x10 */
    union {
        vu0_v4 v;                   /* spark direction */
        struct {
            s32 flags;
            s32 pad24[3];
        } r;
    } u20;                          /* 0x20 */
} S_003036D8;

extern f32 D_L01_001DFB4C;
extern f32 D_L01_001DFB50;
extern s32 D_001DFB40_sda;
__asm__(".extern D_001DFB40_sda, 4");
extern u8 *D_L01_001EAA18[];
extern u8 D_L01_001D66B0[];

void func_L01_003036D8(u8 *self) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038CEA8(void *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern s32 func_0013D3E0(void);
    extern void func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_L01_00466588(void *, void *, s32, s32, s32, s32, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_004CB320(void);
    extern void func_L01_004CB358(void);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    extern s32 func_0038CAD0(void *);
    extern void func_003D4D00(void *, s32, void *, void *, f32);
    extern void func_L01_0044AF78(void *, void *, s32, f32, f32, s32, s32, s32, f32, f32, f32, f32, f32,
                                  s32, s32, s32, s32, s32, s32);
    extern s32 func_003A52A0(s32, s32, void *);
    vu0_v4 p;
    S_003036D8 q;
    u8 *st;
    u8 *target;
    u8 *owner;
    vu0_v4 *pp;
    s32 flag;
    s32 hit;
    f32 len;
    f32 rot;
    f32 d;

    st = *(u8 **)(self + 0x68);
    if (self[0x20] != 0) {
        return;
    }
    rot = func_0038DAB8(*(f32 *)(self + 0xF0), 0.12566371f);
    d = D_L01_001DFB4C;
    flag = 0;
    *(f32 *)(self + 0xF0) = rot;
    vec_add_ba(&p, self + 0x10, st);
    if (d > 0.9f) {
        flag = 1;
    } else if (D_L01_001DFB50 > 0.9f) {
        flag = 1;
    }
    if (flag == 0 || (D_001DFB40_sda & 1) == 0) {
        len = func_0038CEA8(st);
        *(vu0_q *)&q.u20.v = 0;
        q.u20.v.x = func_003824E0(-1.0f, 1.0f);
        q.u20.v.y = func_003824E0(-1.0f, 1.0f);
        q.u20.v.z = func_003824E0(-1.0f, 1.0f);
        q.u10.v = q.u20.v;
        func_0038CF68(&q.u10.v, &q.u10.v, func_003824E0(0.04f, 0.08f) * 0.020000001f);
        func_0038CE20(&q.pos, st, func_003824E0(0.2f, 0.99f));
        vec_add_ba(&q.u10.v, &q.u10.v, &q.pos);
        func_0038CF68(&q.pos, st, func_003824E0(0.0f, 1.0f) * len);
        vec_add_ab(&q.pos, &q.pos, self + 0x10);
        func_L01_0046A610(self + 0x10, &q.u10.v, 6, 0x7F, 0xB0B0B0, 3, 40000.0f, 1000.0f, 1.0f, -0.0004f, 0.0f);
        *(vu0_q *)&q.u20.v = 0;
        q.u20.v.z = 0.01f;
        func_0038D000(&q.u20.v, &q.u20.v, self + 0xC0);
        func_0038D890(&q.u20.v, &q.u20.v, self + 0xC0, func_00382538());
        if (func_0013D3E0() & 1) {
            func_L01_00466588(&q.pos, &q.u20.v, 0x4F007FFF, 0x1FFFFFFF, 0xB, 1, 25000.0f);
        }
    }
    func_L01_00446760(&q.pos, *(u8 **)(st + 0x3C), 0x10001, st, *(f32 *)(st + 0x40));
    q.u10.r.h1A = *(u16 *)(self + 0xAA);
    vec_sub_ab(&q.pos, self + 0x10, *(u8 **)(st + 0x3C) + 0x10);
    q.pos.z = 0.0f;
    func_0038CF68(&q.pos, &q.pos, 2.0000002f);
    q.u10.r.b18 = 4;
    q.pos.w = 5627.9248f;
    q.u20.r.flags |= 1;
    owner = *(u8 **)(st + 0x3C);
    pp = &p;
    func_L01_004CB320();
    hit = func_003D3CB0(self + 0x10, pp, 0, owner, &q);
    if (hit != 0) {
        target = D_L01_001EAA18[0];
        if (target != 0 && *(s16 *)(target + 0xAA) == 0x186D && target[0x20] != 2 && target[0x20] != 5) {
            target[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (hit != 0 || func_L01_003FB640(self + 0x10, 1, *(u8 **)(st + 0x3C), 0.3f) != 0
        || func_0038CAD0(st + 0x38) != 0) {
        target = D_L01_001EAA18[0];
        if (target != 0) {
            if (target == *(u8 **)(st + 0x3C)) {
                *(vu0_v4 *)(self + 0x10) = p;
                return;
            }
            if (*(s16 *)(target + 0xAA) != 0x4E) {
                func_003D4D00(self + 0x10, 0, *(u8 **)(st + 0x3C), &q, 0.5f);
            }
            func_L01_0044AF78(self, D_L01_001D66B0, 0, 0.0f, 0.0f, 0, 2, 0xA, 0.0f, 0.0f, 9.0f, 0.666f, 0.0f,
                              -1, 0, 1, -1, 0, 0x1010001);
        } else {
            func_L01_0044AF78(self, D_L01_001D66B0, 0, 0.0f, 0.0f, 0, 2, 8, 0.0f, 0.0f, 9.0f, 0.5f, 0.0f,
                              -1, 0, 1, -1, 0, 0x1010001);
        }
        func_003A52A0(0, 0, self);
        func_003C2880(self);
    } else {
        *(vu0_v4 *)(self + 0x10) = p;
    }
}
/* localdecomp:end func_L01_003036D8 */
