/* func_L04_00325C08: Promises (task 2790, 2026-11-21; retried in tasks 2907, 2026-11-22, and 3013,
 * 2026-11-23; closeout attempt 1 of 2 in task 3055 and attempt 2 of 2 in task 3060, 2026-11-24), from
 * upstream's nonmatching/functional/func_L04_00325C08.c. CLOSEOUT attempt 2 of 2: 21 -> 3; DONE.
 * Near miss: 3 differences (tools/check.py --no-context), level 04, with
 * -O2 -G8 -fopt-stack -mno-check-zero-division -mvu0-use-vf0-vf2 @ps2as on L04_00325C08.c (the file has
 * neither the VU0 flag nor @ps2as yet; it has no other function). The file's own line does not compile it
 * (VU0 "vf17 spilled"). -fopt-stack stays: retail saves with sd in a 0xF0 frame.
 *
 * Task 3055 (381 -> 21). Each step is plain C; the counts are check.py at level 04:
 * - q10's tail through its own pointer `sub = q10 + 0x20` (retail: addiu $s0, $s1, 0x20). q10 and sub
 *   both conflict with vars, so vars drops from $s1 to $s2 and the 6 takes $s1 (381 -> 259);
 * - three loop counters: j for the two opening loops (retail $s0), i for the bursts ($s4), k for the
 *   last loop ($s5) (259 -> 248);
 * - q1..q4 one variable q (retail keeps all four in $a2) (248 -> 240);
 * - the last loop: the player angle in its own variable yaw ($f24), the 1.396 random in ang ($f20) and
 *   the 1.571 random passed straight to func_0038DAB8 (240 -> 225); burst loop 4: the 15..20 random
 *   inline, its two angles in ang and spd (225 -> 224);
 * - each of burst loops 1-3 declares its own ang, spd and ang2, with ang2 = func_0038DAB8(ang, ...)
 *   feeding the cos/sin. ang2 is short and dense, so it takes $f20 before spd; spd gets $f21 and the
 *   D160 angle, which does not conflict with ang2, also gets $f20 (224 -> 194);
 * - the madd: *mul_acc_si_r5900 needs the mult and the add adjacent when combine runs. With
 *   `Pl_325C08 *base = D_L04_001E2840; pl = &base[D_001D52F0];` in the loop, base's lo_sum lives
 *   4 insns, so the loop pass moves it out (life 4, savings 1, moved); the mult and the add become
 *   adjacent and combine makes the madd. All callee-saved registers are busy in loop 1, so base gets
 *   none and reload rematerialises lui/addiu in the loop, as retail has it. Loops 2 and 3 take the same
 *   form; there base gets $s5 and stays mult + addu, as in retail;
 * - q5/q6 one variable (the function's p) (retail $a0); pl declared in each burst loop, which lets
 *   local-alloc tie the madd's result to the index ($v0) (-> 30);
 * - the opening loops written `for (j = 0; j < 2; j++)`: the loop pass reverses them and emits the
 *   count-down start after the hoisted 6 and 0xF0, as retail orders them (30 -> 24);
 * - func_L01_0044AF78 declared (void *, void *, void *, f32, f32, s32, s32, s32, f32 x5, s32 x6), an
 *   EABI-equivalent order upstream uses at other call sites; it changes the argument schedule (24 -> 21).
 *
 * Task 3060 (21 -> 3): D_001D66B0 through a local `tbl`, assigned in the first opening block and passed
 * to func_L01_0044AF78. tbl gets no hard register and reload rematerialises it at the call as one insn,
 * (set $a1 (symbol_ref D_001D66B0)) in the -dR dump, which prints as retail's adjacent lui/addiu; sgn = 1
 * and k = 0 fall back to retail's places (21 -> 3). Where the assignment goes only
 * moves which block's $v0/$v1 choice it disturbs: at the function's top 10, before the opening loops 5,
 * before each burst loop 5, just before the call 21 (tbl gets a register), before the if 85; 3 inside
 * the first opening block (here), inside the burst loops or inside the if.
 *
 * Left (3, the call block): our la $a1 issues one slot before sw $zero, 0($sp); retail has the sw first.
 * Our reading of the -fsched-verbose-5 trace: sched1 orders the two equal-priority insns by register
 * weight. Our (set $a1 tbl) is tbl's last use, so it frees a register (weight -1) and goes ahead of the
 * store (weight 0); sched2 then keeps that order.
 * With tbl kept live after the call (a test store `D_L04_0021FD88[0] = tbl;` before the last loop) the
 * block comes out in retail's order, so retail's $a1 move did not free a register there. No form found
 * that keeps it live without extra code. Also tried: the ten argument orders upstream declares for this
 * callee, with tbl (3 for four of them, 6-8 for the rest), and the assignment at 108 statement positions
 * (3 at best).
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_00325C08 */
__asm__(".extern D_L04_001DC7B0, 4");
__asm__(".extern D_L04_001DC7A8, 4");
__asm__(".extern D_L04_001DC7AC, 4");
typedef int u128_00325C08 __attribute__((mode(TI)));
extern s32 D_L04_001DC7B0;
extern f32 D_L04_001DC7A8;
extern f32 D_L04_001DC7AC;
typedef struct {
    f32 x, y, z, w;
    u8 pad10[0x460 - 0x10];
} Pl_325C08;
extern s32 D_001D52F0;
extern Pl_325C08 D_L04_001E2840[];
extern u8 D_001D66B0[];
extern u8 *D_L04_0021FD88[];
extern u8 *D_L04_0021FC18[];
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_00470668(void *, void *, s32, f32);
extern void func_L01_002F9578(void *, void *, void *, s32, s32, s32, s32, s32, f32);
extern void func_L01_0044AF78(void *, void *, void *, f32, f32, s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern void func_00382760(void *, f32, f32, f32);
void func_L04_00325C08(u8 *m, void *basis, f32 *off, f32 extra) {
    u8 *vars = *(u8 **)(m + 0x68);
    f32 pos[4] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 fa, fb, scale;
    f32 ang, spd, up, yaw;
    s32 i, j, k, n, rs, sgn;
    u8 *p;
    u8 *q;
    Pl_325C08 *pl;
    u8 *tbl;

    scale = *(f32 *)(vars + 0x14);
    fa = D_L04_001DC7A8 * scale * 210000.0f;
    fb = D_L04_001DC7AC * scale * 210000.0f;
    {
        q = func_L01_0046FB40(m + 0x10, off, (D_L04_001DC7B0 * 5 + 2) / 6, 0x388EF7, 0, 100, 0, fa, fb, 0.0f, 0);
        tbl = D_001D66B0;
        if (q) {
            q[2] = *D_L04_0021FD88[0];
            q[9] = 0xF0;
        }
    }
    {
        q = func_L01_0046FB40(m + 0x10, off, (D_L04_001DC7B0 * 5 + 2) / 6, 0x63F7, 0, 100, 0, fa, fb, 0.0f, 0);
        if (q) {
            q[2] = *D_L04_0021FD88[0];
            q[9] = 0xF0;
        }
    }
    for (j = 0; j < 2; j++) {
        {
            q = func_L01_0046FB40(m + 0x10, off, (D_L04_001DC7B0 * 5 + 2) / 6, 0x388EF7, 0, 0x7F, 0, fa, fb, 0.0f, 0);
            if (q) {
                q[2] = D_L04_0021FC18[0x170 / 4][5];
                q[9] = 0xF0;
            }
        }
    }
    for (j = 0; j < 2; j++) {
        {
            q = func_L01_0046FB40(m + 0x10, off, (D_L04_001DC7B0 * 5 + 2) / 6, 0x388EF7, 0, 0x7F, 0, fa, fb, 0.0f, 0);
            if (q) {
                q[2] = D_L04_0021FC18[0x170 / 4][6];
                q[9] = 0xF0;
            }
        }
    }

    /* burst type 1 (count at +0x20): two particles per round */
    for (i = 0; i < *(s32 *)(vars + 0x20); i++) {
        f32 ang, spd, ang2;
        Pl_325C08 *base = D_L04_001E2840;
        Pl_325C08 *pl = &base[D_001D52F0];
        ang = func_0038D160(pl->x - *(f32 *)(m + 0x10), pl->y - *(f32 *)(m + 0x14));
        rs = (s32)func_L01_00443A18(2.0f, 5.0f);
        n = func_00382498(30, 50);
        pos[0] = *(f32 *)(m + 0x10) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[1] = *(f32 *)(m + 0x14) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[2] = *(f32 *)(m + 0x18) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        up = func_003824E0(0.6f, 1.0f) * *(f32 *)(vars + 0x14);
        spd = func_003824E0(9.0f, 12.0f) * *(f32 *)(vars + 0x14);
        ang2 = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        spd = spd * 0.020000001f;
        v[0] = func_0038D098(ang2) * spd;
        v[1] = func_0038D0B0(ang2) * spd;
        v[2] = 0.0f;
        spd = func_003824E0(0.0f, 12.0f) * *(f32 *)(vars + 0x14);
        v[2] = spd * 0.020000001f;
        vec_add_ab(v, v, off);
        {
            p = func_L01_004713C8(pos, v, (n * 5 + 2) / 6, 0x407FFF, rs, 0x7F, 0x7F, 1, up * 210000.0f, *(f32 *)(vars + 0x14) * 0.01f * 210000.0f, 0.00584f);
            if (p) {
                p[9] = 0xF4;
            }
        }
        {
            p = func_L01_004713C8(pos, v, (n * 5 + 2) / 6, 0x20FF, -(rs * 2), 0x30, 0x30, 0, up * 6.0f * 210000.0f, *(f32 *)(vars + 0x14) * 0.02f * 210000.0f, 0.00584f);
            if (p) {
                p[2] = *D_L04_0021FC18[0xD4 / 4];
                p[9] = 0xF4;
            }
        }
    }

    /* burst type 2 (count at +0x24) */
    for (i = 0; i < *(s32 *)(vars + 0x24); i++) {
        f32 ang, spd, ang2;
        Pl_325C08 *base = D_L04_001E2840;
        Pl_325C08 *pl = &base[D_001D52F0];
        ang = func_0038D160(pl->x - *(f32 *)(m + 0x10), pl->y - *(f32 *)(m + 0x14));
        rs = (s32)func_L01_00443A18(2.0f, 5.0f);
        n = func_00382498(30, 50);
        pos[0] = *(f32 *)(m + 0x10) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[1] = *(f32 *)(m + 0x14) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[2] = *(f32 *)(m + 0x18) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        up = func_003824E0(0.75f, 1.5f) * *(f32 *)(vars + 0x14);
        spd = func_003824E0(9.0f, 12.0f) * *(f32 *)(vars + 0x14);
        ang2 = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        spd = spd * 0.020000001f;
        v[0] = func_0038D098(ang2) * spd;
        v[1] = func_0038D0B0(ang2) * spd;
        v[2] = 0.0f;
        spd = func_003824E0(0.0f, 12.0f) * *(f32 *)(vars + 0x14);
        v[2] = spd * 0.020000001f;
        vec_add_ab(v, v, off);
        {
            u8 *q7 = func_L01_004713C8(pos, v, (n * 5 + 2) / 6, 0x8FFF, rs, 0x7F, 0x7F, 5, up * 210000.0f, *(f32 *)(vars + 0x14) * 0.01f * 210000.0f, 0.00584f);
            if (q7) {
                q7[9] = 0xF4;
            }
        }
    }

    /* burst type 3 (count at +0x28) */
    for (i = 0; i < *(s32 *)(vars + 0x28); i++) {
        f32 ang, spd, ang2;
        Pl_325C08 *base = D_L04_001E2840;
        Pl_325C08 *pl = &base[D_001D52F0];
        ang = func_0038D160(pl->x - *(f32 *)(m + 0x10), pl->y - *(f32 *)(m + 0x14));
        rs = (s32)func_L01_00443A18(2.0f, 5.0f);
        n = func_00382498(30, 50);
        pos[0] = *(f32 *)(m + 0x10) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[1] = *(f32 *)(m + 0x14) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[2] = *(f32 *)(m + 0x18) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        up = func_003824E0(0.6f, 1.0f) * *(f32 *)(vars + 0x14);
        spd = func_003824E0(9.0f, 12.0f) * *(f32 *)(vars + 0x14);
        ang2 = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        spd = spd * 0.020000001f;
        v[0] = func_0038D098(ang2) * spd;
        v[1] = func_0038D0B0(ang2) * spd;
        v[2] = 0.0f;
        spd = func_003824E0(0.0f, 12.0f) * *(f32 *)(vars + 0x14);
        v[2] = spd * 0.020000001f;
        vec_add_ab(v, v, off);
        {
            u8 *q8 = func_L01_004713C8(pos, v, (n * 5 + 2) / 6, 0x3064FF, rs, 0x7F, 0x7F, 3, up * 210000.0f, *(f32 *)(vars + 0x14) * 2100.0f, 0.00584f);
            if (q8) {
                q8[9] = 0xF4;
            }
        }
    }

    /* burst type 4 (count at +0x30): sparks along the basis vectors at m+0xC0 / m+0xD0 */
    for (i = 0; i < *(s32 *)(vars + 0x30); i++) {
        func_0038CE20(pos, m + 0xC0, func_003824E0(15.0f, 20.0f) * *(f32 *)(vars + 0x14) * 0.020000001f);
        ang = func_L01_00443A18(0.2617994f, 1.3962634f);
        spd = func_L01_00443A18(0.2617994f, 1.3962634f);
        func_003C4840(w, m + 0xD0, ang);
        func_0038D850(v, pos, w);
        func_003C4840(w, m + 0xC0, spd);
        func_0038D850(v, v, w);
        vec_add_ab(v, v, off);
        n = func_00382498(20, 35);
        {
            u8 *q9 = func_L01_00470668(m + 0x10, v, (n * 5 + 2) / 6, 0.00584f);
            if (q9) {
                q9[9] = 0xF4;
            }
        }
    }

    if (*(s32 *)(vars + 0x34) != 0) {
        *(u128_00325C08 *)v = 0;
        v[2] = *(f32 *)(vars + 0x14) * 8.0f * 0.020000001f;
        *(u128_00325C08 *)pos = *(u128_00325C08 *)v;
        vec_add_ab(pos, pos, off);
        func_L01_002F9578(m, m + 0x10, pos, 0xD, 0xFF, 0, 0, 0x28, *(f32 *)(vars + 0x14) * 3.5f);
    }

    func_L01_0044AF78(m, tbl, m + 0x10, 0.0f, 0.0f, 0, 0, 0, 0.0f, 0.0f, 9.0f, 0.0f, extra * *(f32 *)(vars + 0x14), -1, 0, 0, -1, 0, 0x1010001);

    sgn = 1;
    pl = &D_L04_001E2840[D_001D52F0];
    yaw = func_0038D160(pl->x - *(f32 *)(m + 0x10), pl->y - *(f32 *)(m + 0x14));
    for (k = 0; k < *(s32 *)(vars + 0x2C); k++) {
        sgn = -sgn;
        pos[0] = *(f32 *)(m + 0x10) + func_L01_00443A18(0.0f, 1.0f) * *(f32 *)(vars + 0x14);
        pos[1] = *(f32 *)(m + 0x14) + func_L01_00443A18(0.0f, 1.0f) * *(f32 *)(vars + 0x14);
        pos[2] = *(f32 *)(m + 0x18) + func_L01_00443A18(0.0f, 1.0f) * *(f32 *)(vars + 0x14);
        spd = func_003824E0(0.020000001f, 0.040000003f) * *(f32 *)(vars + 0x14);
        ang = func_L01_00443A18(0.0f, 1.3962634f);
        func_00382760(v, spd, func_0038DAB8(yaw, func_L01_00443A18(0.0f, 1.5707964f)), ang);
        vec_add_ab(v, v, off);
        {
            u8 *q10 = func_L01_004669B0(pos, 0.0f, 1.0f, 1.01f, *(f32 *)(vars + 0x14) * 1.5f * 210000.0f, sgn, v, 0x7F60A0FF, 0);
            if (q10) {
                u8 *sub = q10 + 0x20;
                n = func_00382498(40, 70);
                q10[9] = 0xF4;
                *(s16 *)(q10 + 0xA) = (n * 5 + 2) / 6;
                *(s32 *)(sub + 4) = 3;
                n = func_00382498(1, 10);
                sub[0xA] = 0x40;
                *(f32 *)(sub + 0x1C) = (f32)((n * 5 + 2) / 6);
                sub[0xB] = q10[0xA];
            }
        }
    }
}
/* localdecomp:end func_L04_00325C08 */
