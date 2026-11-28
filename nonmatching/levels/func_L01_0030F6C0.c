/* func_L01_0030F6C0 (Claude wave 14 r53, 2026-11-28). Replaces the earlier draft of this function (round 30 W7 near miss (TheBoso, #159)). */
/* wr53 (wave 14): the collision test is now `if (func_L01_003FA5F0(..) != 0) k = 1; else k =
 * func_L01_003FB640(..) != 0;` (retail materialises k: li v0,1 in the bnez slot, sltu after the second call),
 * which restores retail's length (888 words) and drops the raw count from 672 to 138 under the file's line.
 * Still differs: the position copy (retail `move s6,s0`: t in s0, pos a copy in s6; cse merges every t/pos
 * wording tried here, so ours has one register and an extra loop-alignment nop before the la/lb loop), and
 * the register numbers the earlier header lists (s0/s6/s7 roles, state-2 float constants, spawn-loop
 * counters, the D_001EAA00 base in s7). The `k = A != 0 || B != 0` and ternary forms give 687 / 139. */
/* First draft, written from scratch (round 30 W7): 104 aligned diffs against retail with the owner file's flags
 * (887 words; check.py shows ~670 raw rows because of shifts). The frame (0x130), the stack slots, the state
 * switch, the 3-iteration p+0x30/p+0x40 loops, the three burst loops (retail order: collision, same-owner
 * hit, no moby) and the 4/3/2-iteration spawn loops match structurally.
 * Still differs: register numbers only, mostly: retail keeps the position in two registers (t=$s0 reused for
 * the &local pointers, pos=$s6 copy), reuses $s7 for p+0xC0 and D_001EAA00, f20=rand in state 2 with the
 * constants 0.75/1.2 in f21/f22 (ours f22 for the rand), spawn loops count in $s1 with the constants in
 * $s3/$s6; two li order (func_00443978 0x7F,0xFF), the store vs move in the func_0040E3C0 delay slot.
 * Needs __asm__(".extern D_001DC694, 4") (float read through $gp) and `unsigned long` for the 64-bit flag test.
 * Tried: pointer locals la/lb, c0/d sharing, separate p2/pp locals for state 2 / the spawn section, a
 * separate spawn counter j (worse, 109), a kp pointer for the s32 table, pos/t/c0 declaration and
 * assignment order, t reassigned to &v20/&v50 (no change).
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_0030F6C0 */
__asm__(".extern D_001DC694, 4");
extern f32 D_001DC694;
extern u8 D_001EAA00[];
extern u8 D_001EAA20[];
extern u8 D_001EAA40[];
extern u8 D_001D66B0;
extern u8 D_001425D1[];
extern u8 D_002C5600[];
extern f32 func_L01_004439C0(f32, f32);
extern s32 func_L01_00443978(s32, s32);
extern s32 func_L01_00443948(s32);
extern f32 func_00443A78(void);
extern s32 func_0013D3E0(void);
extern void func_L01_004CAB30(void *, void *);
extern void func_L01_004C8688(s32, void *, s32);
extern void func_L01_004C7D40(void *, void *, f32);
extern void func_L01_004C8668(s32);
extern void func_L01_0040E398(void *, void *, void *, f32);
extern f32 func_L01_0040F3F8(f32, f32);
extern void func_L01_0040EB68(void *, void *);
extern f32 func_L01_0040E910(f32);
extern f32 func_L01_0040E8F8(f32);
extern void func_L01_0040E3C0(void *, void *, f32);
extern void func_L01_0040E620(void *, void *, f32);
extern void func_L01_0040E450(void *, void *, void *);
extern void func_L01_0040F1D0(void *, void *, void *, f32);
extern void func_L01_00466F50(void *, void *, s32, f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern s32 func_L01_0040DFC0(void *);
extern s32 func_L01_003FA5F0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_00446760(void *, void *, s32, f32, void *);
extern void func_L01_00446978(void *, void *);
extern void func_L01_0031B090(void *, s32, void *);
extern void func_L01_00310538(void *, s32, void *, void *, f32);
extern void func_L01_00310C38(void *, f32, s32, s32, f32, s32, s32, void *);
extern void func_L01_003104B8(void *);
extern s32 func_L01_00457458(s32, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00439300(void *);
extern void func_L01_003107C8(void);
extern u8 *func_L01_004729D8(void *, void *, void *, s32, s32, u8, u8, u8, f32, s32, s32);


void func_L01_0030F6C0(u8 *self)
{
    u8 *pos;
    u8 *pt;
    u8 *q0;
    s32 *kp;
    u8 *p2;
    u8 *pp;
    u8 *q2;
    u8 *c0;
    u8 *d;
    u8 *la;
    u8 *lb;
    u8 *t;
    vu0_v4 *w;
    u8 *p;
    u8 *q;
    u8 *m;
    u8 *r;
    s32 i;
    s32 n;
    s32 k;
    s32 sgn;
    f32 a;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60[3];
    vu0_v4 v90;

    p = *(u8 **)(self + 0x68);
    if (self[0x20] != 0) {
        func_L01_004CAB30(self + 0x10, self + 0x10);
        q = p + 0x10;
        for (i = 3; i >= 0; i--) {
            func_L01_004CAB30(q, q);
            q += 0x10;
        }
    }
    switch (self[0x20]) {
    case 0:
        q0 = p + 0x10;
        for (i = 3; i >= 0; i--) {
            *(s128 *)q0 = *(s128 *)(self + 0x10);
            q0 += 0x10;
        }
        self[0x20] = 1;
    case 1:
        v10 = *(vu0_v4 *)(self + 0x10);
        t = self + 0x10;
        pt = p + 0x60;
        c0 = self + 0xC0;
        pos = t;
        la = p + 0x30;
        lb = p + 0x40;
        func_L01_004C8688(*(s32 *)(p + 0x78), p, 0);
        vec_add_ab(t, t, p);
        func_L01_004C7D40(t, p, D_001DC694 * 0.00040000002f);
        for (i = 3; i > 0; i--) {
            func_L01_0040E398(lb, lb, la, 0.2f);
            la -= 0x10;
            lb -= 0x10;
        }
        *(s128 *)(p + 0x10) = *(s128 *)(self + 0x10);
        *(f32 *)(p + 0x64) = func_L01_0040F3F8(*(f32 *)(p + 0x64), *(f32 *)(p + 0x68));
        qzero(&v20);
        v20.y = *(f32 *)(p + 0x64) * 0.5f;
        v20.x = *(f32 *)(p + 0x64) * 0.25f;
        v20.z = *(f32 *)(p + 0x64) * 0.375f;
        t = (u8 *)&v20;
        func_L01_0040EB68(c0, t);
        *(f32 *)(self + 0xC0) *= (func_L01_0040E910(*(f32 *)(p + 0x64)) + 2.0f) * 0.4f;
        *(f32 *)(self + 0xD4) *= (func_L01_0040E8F8(*(f32 *)(p + 0x64)) + 2.0f) * 0.5f;
        *(f32 *)(self + 0xE8) *= (func_L01_0040E910(*(f32 *)(p + 0x64)) + 2.0f) * 0.75f;
        {
            s32 c = func_L01_00443978(0x7F, 0xFF);
            *(s32 *)(self + 0x78) = (c << 16) + (c << 8) + c | 0x7F000000;
        }
        func_L01_0040E3C0(&v30, p, -0.125f);
        if (func_0013D3E0() % 10 == 0) {
            qzero(&v50);
            v40.x = *(f32 *)(self + 0x10) + func_L01_004439C0(-0.15f, 0.15f);
            v40.y = *(f32 *)(self + 0x14) + func_L01_004439C0(-0.15f, 0.15f);
            v40.z = *(f32 *)(self + 0x18) + func_L01_004439C0(-0.15f, 0.15f);
            v50.x = func_L01_004439C0(-0.025f, 0.025f);
            v50.y = func_L01_004439C0(-0.025f, 0.025f);
            v50.z = func_L01_004439C0(0.0f, 0.025f);
            t = (u8 *)&v50;
            func_L01_0040E620(t, t, 0.05f);
            func_L01_00466F50(&v40, t, 0, -1.0f, 0.0f);
        }
        if (func_L01_0040DFC0(pt) != 0) {
            goto kill;
        }
        if (func_L01_003FA5F0(&v10, pos, 0, self, 0) != 0) {
            k = 1;
        } else {
            k = func_L01_003FB640(pos, 0, self, 0.05f) != 0;
        }
        if (k != 0) {
            c0 = D_001EAA00;
            d = c0;
            m = *(u8 **)(d + 0x18);
            if (m != 0) {
                if ((*(unsigned long *)(m + 0x30) & ((unsigned long)0xA000 << 31)) != 0 && m != (u8 *)D_001A71A0[0] && *(s16 *)(m + 0xAA) != 0x5C9) {
                    vec_sub_ab(&v40, m + 0x10, (u8 *)D_001A71A0[0] + 0x10);
                    func_L01_0040E620(&v40, &v40, 1.0f);
                    func_L01_0040E620(v60, v60, 0.14000002f);
                    func_L01_00446760(v60, self, 0x1110000,
                                      *(f32 *)(D_002C5600 + D_001425D1[0] * 0xF0 + 0x6C), &v40);
                    *(s128 *)v60 = *(s128 *)&v40;
                    *(f32 *)((u8 *)v60 + 0xC) = 5627.925f;
                    ((u8 *)v60)[0x18] = 5;
                    *(s32 *)((u8 *)v60 + 0x20) = 1;
                    ((u8 *)v60)[0x19] = 1;
                    *(s16 *)((u8 *)v60 + 0x1A) = *(u16 *)(*(u8 **)(d + 0x18) + 0xAA);
                    func_L01_00446978(*(u8 **)(d + 0x18), v60);
                    func_L01_0031B090(*(u8 **)(d + 0x18), 0xA1, *(void **)(self + 0xB8));
                    m = *(u8 **)(d + 0x18);
                    self[0x20] = 2;
                    *(u16 *)(self + 0x34) |= 0x41;
                    *(s128 *)&v50 = *(s128 *)(m + 0x10);
                    v50.z += 5.0f;
                    *(s128 *)(self + 0x10) = *(s128 *)(d + 0x20);
                    *(s128 *)&v40 = *(s128 *)&v50;
                    v40.z -= 10.0f;
                    *(s128 *)(p + 0x50) = *(s128 *)(d + 0x40);
                    *(s32 *)(p + 0x7C) = 1;
                    for (i = 2; i >= 0; i--) {
                        func_L01_0040E620(&v90, D_001EAA40, func_L01_004439C0(0.20000002f, 0.40000004f));
                        v90.x += func_L01_004439C0(-0.15f, 0.15f);
                        v90.y += func_L01_004439C0(-0.15f, 0.15f);
                        v90.z += func_L01_004439C0(-0.15f, 0.15f);
                        func_L01_0040E620(&v90, &v90, func_L01_004439C0(0.040000003f, 0.120000005f));
                        func_L01_00466F50(pos, &v90, 0, -1.0f, 0.0f);
                    }
                } else {
                    *(u16 *)(self + 0x34) |= 0x41;
                    self[0x20] = 2;
                    *(s128 *)(self + 0x10) = *(s128 *)D_001EAA20;
                    *(s128 *)(p + 0x50) = *(s128 *)(D_001EAA20 + 0x20);
                    for (i = 5; i >= 0; i--) {
                        func_L01_0040E620(&v40, D_001EAA40, func_L01_004439C0(0.20000002f, 0.40000004f));
                        v40.x += func_L01_004439C0(-0.15f, 0.15f);
                        v40.y += func_L01_004439C0(-0.15f, 0.15f);
                        v40.z += func_L01_004439C0(-0.15f, 0.15f);
                        func_L01_0040E620(&v40, &v40, func_L01_004439C0(0.040000003f, 0.120000005f));
                        func_L01_00466F50(pos, &v40, 0, -1.0f, 0.0f);
                    }
                }
            } else {
                *(s128 *)(self + 0x10) = *(s128 *)(d + 0x20);
                *(u16 *)(self + 0x34) |= 0x41;
                self[0x20] = 2;
                *(s128 *)(p + 0x50) = *(s128 *)(d + 0x40);
                for (i = 5; i >= 0; i--) {
                    func_L01_0040E620(&v40, D_001EAA40, func_L01_004439C0(0.20000002f, 0.40000004f));
                    v40.x += func_L01_004439C0(-0.15f, 0.15f);
                    v40.y += func_L01_004439C0(-0.15f, 0.15f);
                    v40.z += func_L01_004439C0(-0.15f, 0.15f);
                    func_L01_0040E620(&v40, &v40, func_L01_004439C0(0.040000003f, 0.120000005f));
                    func_L01_00466F50(pos, &v40, 0, -1.0f, 0.0f);
                }
            }
            *(s32 *)(p + 0x60) = 0xC;
            func_L01_00310538(self, 0xC, pos, D_001EAA40, 0.10000001f);
        }
        break;
    case 2:
        w = &v50;
        ((s32 *)&v40)[0] = 0x44;
        ((s32 *)&v40)[1] = 0x48;
        func_L01_0040E620(w, p, 2.0f);
        p2 = self + 0x10;
        vec_add_ab(&v50, &v50, p2);
        func_L01_0040E450(v60, p2, &v50);
        func_L01_0040E620(v60, v60, 1.0f);
        func_L01_0040F1D0(v60, v60, p, func_00443A78());
        a = func_L01_004439C0(0.010000001f, 0.060000002f);
        kp = (s32 *)&v40 + func_0013D3E0() % 2;
        n = func_L01_00443978(0x19, 0x2A);
        func_L01_004729D8(p2, p, v60, *kp, n, 0, 0, 0, a, 0, 0);
        a = func_L01_004439C0(0.75f, 1.2f);
        n = func_L01_00443978(0x3F, 0x5F);
        func_L01_00310C38(p2, a, 0x103080, n, func_00443A78(), 0xB, 2, p);
        a = func_L01_004439C0(0.75f, 1.2f) * 0.75f;
        n = func_L01_00443978(0x4F, 0x6F);
        func_L01_00310C38(p2, a, 0x103080, n, func_00443A78(), 0xB, 2, p);
        a = func_L01_004439C0(0.75f, 1.2f) * 0.5f;
        n = func_L01_00443978(0x5F, 0x7F);
        func_L01_00310C38(p2, a, 0x103080, n, func_00443A78(), 0xB, 2, p);
        if (func_L01_0040DFC0(p + 0x60) != 0) {
            goto kill;
        }
        if (*(s32 *)(p + 0x7C) == 0) {
            la = p + 0x30;
            lb = p + 0x40;
            for (i = 3; i > 0; i--) {
                func_L01_0040E398(lb, lb, la, 0.2f);
                la -= 0x10;
                lb -= 0x10;
            }
        } else {
            la = p + 0x30;
            lb = p + 0x40;
            for (i = 3; i > 0; i--) {
                func_L01_0040E398(lb, lb, la, 0.5f);
                la -= 0x10;
                lb -= 0x10;
            }
        }
        *(s128 *)(p + 0x10) = *(s128 *)(self + 0x10);
        *(f32 *)(self + 0x2C) += 0.0005f;
        break;
    }
    if (self[0x20] == 1) {
        pp = self + 0x10;
        for (i = 3; i >= 0; i--) {
            n = func_L01_00443948(5);
            sgn = func_L01_00443948(2);
            r = func_L01_004669B0(pp, 0.2f, 1.0f, 0.9f, 210000.0f, sgn ? -n : n, &D_001D66B0, 0x7F204080, 1);
            if (r != 0) {
                *(s16 *)(r + 0xA) = 4;
                r[9] = 0x44;
                q2 = r + 0x20;
                *(s32 *)(q2 + 4) = 2;
                q2[0xA] = 0x30;
                q2[0xB] = r[0xA];
            }
        }
        for (i = 2; i >= 0; i--) {
            n = func_L01_00443948(3);
            sgn = func_L01_00443948(2);
            r = func_L01_004669B0(pp, 0.05f, 1.0f, 0.9f, 157500.0f, sgn ? -n : n, &D_001D66B0, 0x7F4080FF, 1);
            if (r != 0) {
                *(s16 *)(r + 0xA) = 2;
                r[9] = 0x44;
                q2 = r + 0x20;
                *(s32 *)(q2 + 4) = 2;
                q2[0xA] = 0x40;
                q2[0xB] = r[0xA];
            }
        }
        for (i = 1; i >= 0; i--) {
            n = func_L01_00443948(3);
            sgn = func_L01_00443948(2);
            r = func_L01_004669B0(pp, 0.05f, 1.0f, 0.9f, 105000.0f, sgn ? -n : n, &D_001D66B0, 0x7FFFFFFF, 1);
            if (r != 0) {
                *(s16 *)(r + 0xA) = 2;
                r[9] = 0x44;
                q2 = r + 0x20;
                *(s32 *)(q2 + 4) = 2;
                q2[0xA] = 0x60;
                q2[0xB] = r[0xA];
            }
        }
    }
    func_L01_003104B8(self);
    if (func_L01_00457458(*(s32 *)(p + 0x74), *(s32 *)(p + 0x70)) == 0) {
    kill:
        func_L01_004C8668(*(s32 *)(p + 0x78));
        func_L01_00439300(self);
    } else {
        func_L01_00404A10(func_L01_003107C8, self);
    }
}
/* localdecomp:end func_L01_0030F6C0 */
