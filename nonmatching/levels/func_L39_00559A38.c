/* Wave 13c (c41, 2026-11-28): measured under the line it needs, "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 * -mno-check-zero-division @ps2as" (existing; the file's two C functions give 23/29 diff under it, so it needs
 * its own object, 0x00559A38-0x0055A880 with the 4 pad bytes before L39_0055A880.c): 705 positional / 336
 * aligned differences (r28's draft: 888 / 446). Changed against r28: the VU0 sequences are include/vu0.h's
 * vec_add_ab/vec_sub_ab (one asm per instruction, so they schedule as retail's do), the $gp globals use their
 * slot names (D_001DFC90/94/98/9C_sda, D_001DFC8C_sda, D_001DFBE4/E8/EC_sda with `.extern X, 4`, as retail
 * reads them gp-relative), retail's literals 0.040000003f/0.060000002f/0.14000001f, the base copy before
 * state = 1, the two state-1 passes as for loops (retail walks v->mobys with a pointer and keeps 0x109D in a
 * register), and half/zero set at the top of the moby loop (loop.c hoists them into the preheader after the
 * count guard, as retail's blezl delay slot shows). Still differs: register allocation (j in s1 vs retail s4,
 * 0x109D in s3 vs s1), one float callee-saved register fewer (f20-f25 vs f20-f26, frame 0x120 vs 0x130), and the
 * body of the 0x109D/0x109F branches.
 * Earlier header (r28): first draft (fresh entry, written from the retail assembly): 880
 * positional diff under the file's line, 29 words short. Blockers under L39_005598D8.c's line (no @ps2as, no
 * -mvu0-use-vf0-vf2): GNU as turns the li.s literals with a non-zero low half (0.04, 0.017453292, 0.3, 0.06, 0.14)
 * into $gp .lit4 loads where retail has lui/ori/mtc1, and the 64 VU0 instructions are asm blocks here while retail
 * schedules other insns between lqc2/vadd/sqc2 (e.g. 0x5AC-0x5C4); it can only match with an @ps2as VU0 line.
 * Control flow, callees and argument order follow retail: the empty-player cleanup loop, the state/distance block
 * (state 0 -> 1 with the base copy), the two 0x109F/0x109D lookups, the all-in-range state-1 pass, then per moby
 * the 0x109D branch (target, func_L39_00558DB8 hit, the angle search loop with func_L39_00558D80, the z clamp, the
 * k-dependent radius, the random height) and the 0x109F branch (approach, angle search, func_L39_00558A58 steer,
 * the frame & 0x3F throttle of func_L39_00558CA0). Left besides the blockers: retail hoists 0.5/0.0 into f25/f26
 * (frame 0x130, ours 0x120 with f20-f24), register allocation and the spill slots (obj at 0x80, next i at 0x98). */
#include "common.h"

/* localdecomp:start func_L39_00559A38 */
#include "vu0.h"
typedef int Q_00559A38 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00559A38;
typedef struct M_00559A38 {
    u8 pad0[0x10];
    V_00559A38 pos;
    u8 pad20[0x48];
    u8 *vars;
    u8 pad6C[0x24];
    u8 *x90;
    u8 pad94[0x16];
    s16 hAA;
    u8 padAC[0x4C];
    f32 fF8;
} M_00559A38;
typedef struct G_00559A38 {
    s32 count;
    u8 pad4[4];
    u8 *player;
    u8 padC[4];
    M_00559A38 *mobys[0x18];
    s32 state;
    u8 pad74[4];
    s32 x78;
    f32 f7C;
    V_00559A38 base;
    V_00559A38 out[5];
    V_00559A38 offs[5];
    u8 pad130[0x14];
    f32 *x144;
} G_00559A38;

extern f32 D_001DFC94_sda;
__asm__(".extern D_001DFC94_sda, 4");
extern f32 D_001DFC90_sda;
__asm__(".extern D_001DFC90_sda, 4");
extern f32 D_001DFC98_sda;
__asm__(".extern D_001DFC98_sda, 4");
extern f32 D_001DFC9C_sda;
__asm__(".extern D_001DFC9C_sda, 4");
extern f32 D_001DFBEC_sda;
__asm__(".extern D_001DFBEC_sda, 4");
extern f32 D_001DFC8C_sda;
__asm__(".extern D_001DFC8C_sda, 4");
extern f32 D_001DFBE8_sda;
__asm__(".extern D_001DFBE8_sda, 4");
extern f32 D_L39_0024B310[1];
extern f32 D_L39_0024B330[1];
extern f32 D_L39_0024B350[1];
extern f32 *D_001DFBE4_sda;
__asm__(".extern D_001DFBE4_sda, 4");
extern f32 D_L39_0024B2C8[];
extern s32 D_L39_0024112C;

void func_L39_00559A38(u8 *obj) {
    extern void func_L39_005596B0(u8 *);
    extern void func_L39_0066C470(s32);
    extern void func_L39_005593F8(u8 *);
    extern void func_L39_00559018(u8 *);
    extern M_00559A38 *func_L39_005589F0(u8 *, s32);
    extern void func_L39_005591C8(M_00559A38 *, u8 *);
    extern void func_L39_00559268(M_00559A38 *, u8 *, s32);
    extern s32 func_L39_00558E68(u8 *);
    extern s32 func_L39_00559740(u8 *);
    extern s32 func_L39_00558DB8(u8 *, M_00559A38 *, V_00559A38 *);
    extern s32 func_L39_00558D80(V_00559A38 *, V_00559A38 *);
    extern f32 func_L39_00558A58(f32, M_00559A38 *, u8 *, u8 *);
    extern void func_L39_00558CA0(M_00559A38 *, u8 *, u8 *);
    extern void func_L39_00558118(u8 *);
    extern f32 func_L39_005B4410(f32, f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    G_00559A38 *v = *(G_00559A38 **)(obj + 0x68);
    V_00559A38 t0;
    V_00559A38 t10;
    V_00559A38 t20;
    V_00559A38 t30;
    V_00559A38 t40;
    V_00559A38 t50;
    V_00559A38 t60;
    V_00559A38 t70;
    M_00559A38 *m1;
    M_00559A38 *m2;
    u8 *d88;
    u8 *d8C;
    M_00559A38 *target;
    M_00559A38 *m;
    u8 *mv;
    s32 k;
    s32 i;
    s32 j;
    f32 zero;
    f32 half;

    func_L39_005596B0(obj);
    if (v->player == 0 || *(u8 **)(v->player + 0x2558) == 0) {
        for (j = 0; j < v->count; j++) {
            u8 *e = v->mobys[j]->x90;
            if (e[0x31] == 1) {
                func_L39_0066C470(*(s32 *)e);
            }
        }
        v->count = 0;
        return;
    }
    if (*(f32 *)(v->player + 0x1A4) < 0.040000003f || v->state == 1) {
        if (v->state == 0) {
            *(Q_00559A38 *)&v->base = *(Q_00559A38 *)&(*(M_00559A38 **)(v->player + 0x2524))->pos;
            v->state = 1;
        }
        if (D_001DFC94_sda < func_0038CF38((u8 *)&v->base, (u8 *)&(*(M_00559A38 **)(v->player + 0x2524))->pos)) {
            v->state = 0;
        }
    } else {
        v->state = 0;
        func_L39_005593F8(obj);
    }
    func_L39_00559018(obj);
    if (v->count > 0) {
        v->player[0x1A11] = 1;
    } else {
        v->player[0x1A11] = 0;
    }
    func_L39_00559980(obj);
    m1 = func_L39_005589F0(obj, 0x109F);
    m2 = func_L39_005589F0(obj, 0x109D);
    if (m1 == 0 && m2 == 0) {
        return;
    }
    d88 = 0;
    d8C = 0;
    if (m2 != 0) {
        d8C = m2->vars;
    }
    if (m1 != 0) {
        d88 = m1->vars;
    }
    target = m1;
    v->x78 = -1;
    if (m2 != 0) {
        target = m2;
    }
    if (m1 != 0) {
        func_L39_005591C8(m1, obj);
    }
    if (m2 != 0) {
        func_L39_00559268(m2, obj, 0);
    }
    if (v->x144 == 0) {
        v->x144 = D_L39_0024B2C8;
    }
    D_001DFBE4_sda = v->x144;
    if (func_L39_00558E68(obj) != 0) {
        for (j = 0; j < v->count; j++) {
            m = v->mobys[j];
            if (m->hAA == 0x109F) {
                m->vars[0x2D3] = 1;
            }
        }
    }
    if (v->state == 1) {
        for (j = 0; j < v->count && v->mobys[j]->hAA == 0x109D; j++) {
            if (D_001DFC90_sda < func_0038CF38((u8 *)&v->mobys[j]->pos, *(u8 **)(v->player + 0x2558) + 0x180)) {
                break;
            }
        }
        if (j == v->count) {
            for (j = 0; j < v->count && v->mobys[j]->hAA == 0x109D; j++) {
                u8 *e = v->mobys[j]->vars;
                *(s16 *)(e + 0x254) = 1;
                *(Q_00559A38 *)(e + 0x2E0) = *(Q_00559A38 *)&v->mobys[j]->pos;
                *(s32 *)(e + 0x354) = 0;
            }
            v->x78 = 0;
            return;
        }
    }
    k = func_L39_00559740(obj);
    for (i = 0; i < v->count; i++) {
        half = 0.5f;
        zero = 0.0f;
        m = v->mobys[i];
        if (m->hAA == 0x109D) {
            mv = m->vars;
            *(u16 *)(mv + 0x254) = v->state;
            if (m == target) {
                *(Q_00559A38 *)(d8C + 0x2E0) = *(Q_00559A38 *)(d8C + 0x3A0);
                *(s32 *)(d8C + 0x354) = 1;
                vec_add_ab(d8C + 0x2E0, d8C + 0x2E0, &v->offs[i]);
                *(Q_00559A38 *)&t20 = *(Q_00559A38 *)&m2->pos;
                *(Q_00559A38 *)&t30 = *(Q_00559A38 *)(d8C + 0x2E0);
                if (4.0f < m2->pos.z - v->f7C) {
                    t30.z = m2->pos.z + half;
                } else if (4.0f < v->f7C - m2->pos.z) {
                    t20.z = v->f7C + half;
                }
                *(f32 *)(d8C + 0x350) = func_0038D160(t30.x - t20.x, t30.y - t20.y);
                if (v->player == 0 || *(s16 *)(v->player + 0x2D8) == 0) {
                    *(f32 *)(mv + 0x2E8) = v->f7C + D_001DFBEC_sda + func_L39_005B4410(D_001DFC98_sda, D_001DFC9C_sda);
                } else {
                    *(f32 *)(mv + 0x2E8) = v->f7C;
                    *(Q_00559A38 *)&t40 = *(Q_00559A38 *)(v->player + 0x250);
                    func_0038CF68((u8 *)&t40, (u8 *)&t40, -(D_001DFBEC_sda + func_L39_005B4410(D_001DFC98_sda, D_001DFC9C_sda)));
                    vec_add_ab(mv + 0x2E0, mv + 0x2E0, &t40);
                }
                if (*(s32 *)(mv + 0x354) == 0) {
                    *(Q_00559A38 *)(mv + 0x2E0) = *(Q_00559A38 *)&m->pos;
                }
                if (d8C == 0) {
                    break;
                }
                if (*(s32 *)(d8C + 0x354) == 1) {
                    *(f32 *)(d8C + 0x350) = func_0038DAB8(zero, *(f32 *)(d8C + 0x350));
                    *(Q_00559A38 *)&v->out[i] = *(Q_00559A38 *)(mv + 0x2E0);
                } else {
                    v->x78 = 0;
                }
                continue;
            }
            if (func_L39_00558DB8(v->player, m, &t20) != 0) {
                *(f32 *)(mv + 0x350) = func_0038D160(t20.x - m->pos.x, t20.y - m->pos.y);
                *(s32 *)(mv + 0x354) = 1;
                continue;
            }
            {
                f32 r;
                f32 f;
                f32 ang;
                f32 tab;
                s32 hit;

                vec_sub_ab(&t0, d8C + 0x3A0, &v->base);
                f = 1.0f;
                ang = func_0038DAB8(func_0038D160(t0.x, t0.y), D_L39_0024B310[i] * 0.017453292f);
                tab = D_001DFBE4_sda[i];
                for (;;) {
                    r = f * tab;
                    t10.x = func_0038D098(ang) * r;
                    t10.y = func_0038D0B0(ang) * r;
                    t10.z = 0.0f;
                    f += 0.3f;
                    vec_add_ab(mv + 0x2E0, &v->base, &t10);
                    *(f32 *)(mv + 0x2E8) = v->f7C;
                    vec_sub_ab(&t60, mv + 0x2E0, &m->pos);
                    *(Q_00559A38 *)&t50 = *(Q_00559A38 *)&t60;
                    *(Q_00559A38 *)&t30 = *(Q_00559A38 *)&t60;
                    vec_sub_ab(&t60, &(*(M_00559A38 **)(v->player + 0x2524))->pos, &v->base);
                    *(Q_00559A38 *)&t40 = *(Q_00559A38 *)&t60;
                    *(Q_00559A38 *)&t50 = *(Q_00559A38 *)&t60;
                    t40.z = 0.0f;
                    if (1.0f <= f) {
                        if (func_L39_00558D80(&t30, &t40) == 1) {
                            if (func_0038CF38((u8 *)&m->pos, mv + 0x2E0) < zero) {
                                *(f32 *)(mv + 0x2E0) = func_0038D098(m->fF8) * 1.5f;
                                *(f32 *)(mv + 0x2E8) = 0.0f;
                                *(f32 *)(mv + 0x2E4) = func_0038D0B0(m->fF8) * 1.5f;
                                vec_add_ab(mv + 0x2E0, mv + 0x2E0, &m->pos);
                            }
                        }
                        break;
                    }
                    if (*(f32 *)(v->player + 0x1A4) < 0.060000002f || func_L39_00558D80(&t30, &t40) != 1) {
                        break;
                    }
                }
                *(s32 *)(mv + 0x354) = 1;
                vec_add_ab(mv + 0x2E0, mv + 0x2E0, &v->offs[i]);
                *(Q_00559A38 *)&t50 = *(Q_00559A38 *)&m->pos;
                *(Q_00559A38 *)&t60 = *(Q_00559A38 *)(mv + 0x2E0);
                if (4.0f < m->pos.z - v->f7C) {
                    t60.z = m->pos.z + half;
                } else if (4.0f < v->f7C - m->pos.z) {
                    t50.z = v->f7C + half;
                }
                if (k == 0) {
                    *(f32 *)(mv + 0x350) = func_0038D160(t60.x - t50.x, t60.y - t50.y);
                }
                if (k != 0) {
                    func_0038CF68((u8 *)&t0, (u8 *)&t0, (f32)i * D_001DFC8C_sda + func_0038CF38(d8C + 0x3A0, (u8 *)&v->base));
                    vec_add_ab(mv + 0x2E0, &t0, &v->base);
                    *(f32 *)(mv + 0x2E8) = v->f7C;
                    *(Q_00559A38 *)&t50 = *(Q_00559A38 *)&m->pos;
                    *(Q_00559A38 *)&t60 = *(Q_00559A38 *)(mv + 0x2E0);
                    if (4.0f < m->pos.z - v->f7C) {
                        t60.z = m->pos.z + half;
                    } else if (4.0f < v->f7C - m->pos.z) {
                        t50.z = v->f7C + half;
                    }
                    *(f32 *)(mv + 0x350) = func_0038D160(t60.x - t50.x, t60.y - t50.y);
                    if (k != 1) {
                        v->x78 = 0;
                    }
                }
                if (v->player == 0 || *(s16 *)(v->player + 0x2D8) == 0) {
                    *(f32 *)(mv + 0x2E8) = v->f7C + D_001DFBEC_sda + func_L39_005B4410(D_001DFC98_sda, D_001DFC9C_sda);
                } else {
                    *(f32 *)(mv + 0x2E8) = v->f7C;
                    *(Q_00559A38 *)&t70 = *(Q_00559A38 *)(v->player + 0x250);
                    func_0038CF68((u8 *)&t70, (u8 *)&t70, -(D_001DFBEC_sda + func_L39_005B4410(D_001DFC98_sda, D_001DFC9C_sda)));
                    vec_add_ab(mv + 0x2E0, mv + 0x2E0, &t70);
                }
                if (*(s32 *)(mv + 0x354) == 0) {
                    *(Q_00559A38 *)(mv + 0x2E0) = *(Q_00559A38 *)&m->pos;
                }
                if (*(s32 *)(mv + 0x354) == 1) {
                    *(f32 *)(mv + 0x350) = func_0038DAB8(zero, *(f32 *)(mv + 0x350));
                    *(Q_00559A38 *)&v->out[i] = *(Q_00559A38 *)(mv + 0x2E0);
                } else {
                    v->x78 = 0;
                }
            }
        } else if (m->hAA == 0x109F) {
            f32 t;
            f32 ang;
            f32 f;
            f32 r;
            s32 key;

            mv = m->vars;
            *(u16 *)(mv + 0x264) = v->state;
            if (v->state == 1) {
                if (func_0038CF38((u8 *)&m->pos, *(u8 **)(v->player + 0x2558) + 0x180) < 5.0f) {
                    *(s32 *)(mv + 0x2EC) = 0;
                    *(Q_00559A38 *)(mv + 0x310) = *(Q_00559A38 *)&m->pos;
                    v->x78 = 0;
                    continue;
                }
            }
            vec_sub_ab(&t20, d88 + 0x350, &v->base);
            ang = func_0038D160(t20.x, t20.y);
            t = *(f32 *)(v->player + 0x1A4);
            if (v->state == 1 || t < 0.060000002f) {
                t = 0.0f;
            }
            t = t / 0.14000001f;
            if (1.0f < t) {
                t = 1.0f;
            } else if (t < zero) {
                t = 0.0f;
            }
            key = (s32)m >> 8;
            f = 1.0f;
            ang = func_0038DAB8(ang, ((D_L39_0024B330[i] - D_L39_0024B350[i]) + t * D_L39_0024B350[i]) * 0.017453292f);
            func_0038CF38((u8 *)&m->pos, (u8 *)&v->base);
            for (;;) {
                r = f * D_001DFBE8_sda;
                t30.x = func_0038D098(ang) * r;
                t30.y = func_0038D0B0(ang) * r;
                t30.z = 0.0f;
                f += 0.3f;
                vec_add_ab(mv + 0x310, &v->base, &t30);
                *(f32 *)(mv + 0x318) = v->f7C;
                vec_sub_ab(&t70, mv + 0x310, &m->pos);
                *(Q_00559A38 *)&t60 = *(Q_00559A38 *)&t70;
                *(Q_00559A38 *)&t40 = *(Q_00559A38 *)&t70;
                vec_sub_ab(&t70, &(*(M_00559A38 **)(v->player + 0x2524))->pos, &v->base);
                *(Q_00559A38 *)&t50 = *(Q_00559A38 *)&t70;
                *(Q_00559A38 *)&t60 = *(Q_00559A38 *)&t70;
                t50.z = 0.0f;
                if (1.0f <= f) {
                    if (func_L39_00558D80(&t40, &t50) == 1) {
                        if (func_0038CF38((u8 *)&m->pos, mv + 0x310) < 1.5f) {
                            *(f32 *)(mv + 0x310) = func_0038D098(m->fF8) * 1.5f;
                            *(f32 *)(mv + 0x318) = 0.0f;
                            *(f32 *)(mv + 0x314) = func_0038D0B0(m->fF8) * 1.5f;
                            vec_add_ab(mv + 0x310, mv + 0x310, &m->pos);
                        }
                    }
                    break;
                }
                if (*(f32 *)(v->player + 0x1A4) < 0.060000002f || func_L39_00558D80(&t40, &t50) != 1) {
                    break;
                }
            }
            *(s32 *)(mv + 0x2EC) = 1;
            *(f32 *)(mv + 0x2E4) = func_0038D160(*(f32 *)(mv + 0x310) - m->pos.x, *(f32 *)(mv + 0x314) - m->pos.y);
            if (*(s32 *)(mv + 0x374) == 0) {
                *(s32 *)(mv + 0x374) = 1;
                *(Q_00559A38 *)&t60 = *(Q_00559A38 *)&m->pos;
                *(Q_00559A38 *)&t70 = *(Q_00559A38 *)(mv + 0x310);
                if (4.0f < v->f7C - t60.z) {
                    t60.z = v->f7C + half;
                } else if (4.0f < t60.z - v->f7C) {
                    t70.z = t60.z + half;
                }
            }
            *(Q_00559A38 *)&v->out[i] = *(Q_00559A38 *)(mv + 0x310);
            if (*(s32 *)(mv + 0x2EC) == 1) {
                f32 g = func_L39_00558A58(*(f32 *)(mv + 0x2E4), m, mv + 0x3A0, v->player);

                *(f32 *)(mv + 0x2E4) = func_0038DAB8(g, *(f32 *)(mv + 0x2E4));
                if (g != zero) {
                    t40.x = func_0038D098(*(f32 *)(mv + 0x2E4)) * 3.0f;
                    t40.y = func_0038D0B0(*(f32 *)(mv + 0x2E4)) * 3.0f;
                    t40.z = 0.0f;
                    vec_add_ab(&t40, &m->pos, &t40);
                    *(Q_00559A38 *)(mv + 0x310) = *(Q_00559A38 *)&t40;
                }
            }
            if ((D_L39_0024112C & 0x3F) == (key & 0x3F)) {
                func_L39_00558CA0(m, mv + 0x3A0, obj);
            }
            if (i == 1) {
                func_L39_00558118(obj);
            }
        }
    }
    if (v->x78 == -1) {
        v->x78 = 1;
    }
}
/* localdecomp:end func_L39_00559A38 */
