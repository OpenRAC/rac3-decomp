/* NTSC-U draft (Claude wave K): C of func_L01_0044A0E8, the NTSC-U twin of func_L01_0044D360, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 681 words differ on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as (the entry's flags lack -mvu0-use-vf0-vf2)" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L01_0044A0E8", whose code is not the PAL one).
 * Worker's note: 681 diff words of 744 (331 structural instructions after alignment; same length 744/744, same frame 0x120) with '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (the entry's flags LACK -mvu0-use-vf0-vf2: without it the vu0.h helpers ...
 */
/* NEAR (681 diff words, 331 structural; lengths 744/744): flags needed '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (the PAL line has @ps2as but NOT -mvu0-use-vf0-vf2: the vec_add/vec_sub helpers do not compile without it) + no div.s rows needed? (check: it has `div` integer ops only). Bolt-spawn function: breaks `cnt` into denominations 30000,10000,3000,1000,500,100,50,20,5,1 (c0..c9) and spawns one func_L01_002F8F60 per unit in a do-while. Remaining blockers: parameter/saved-register numbering (retail o=$s3, flags=$s4, lo=$s0, maxn=$s1, &v10=$s2, fl5=$s5, c8=$s6, c0=$s7, c1=$fp), spill-slot order of c2..c9 (declare c9 first, c0 last), amount-scaling block 0x130-0x2C8, decomposition block, spawn loop. */
#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_44A0E8;
typedef struct { u8 p0[0x18]; f32 f18; } G_44A0E8;
typedef struct { u8 p0[0x30]; u32 w30; u8 p34[3]; u8 b33; u8 p37[5]; } X_44A0E8;

extern s32 func_0037E1D8(s32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_L01_00443080(f32 *, f32 *, f32, f32, f32);
extern void func_L01_00473E10(s32, void *, void *, void *);
extern void func_L01_002F8F60(void *, void *, void *, s32, s32, s32);

/* localdecomp:start func_L01_0044A0E8 */
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_L01_001D6714[];
__asm__(".extern D_L01_001D6714, 16");
extern u8 D_L01_001DFF00[];
__asm__(".extern D_L01_001DFF00, 16");
extern s32 D_L01_001A91E8[];
__asm__(".extern D_L01_001A91E8, 16");
extern s32 D_L01_001A9280[];
__asm__(".extern D_L01_001A9280, 16");
extern u8 D_00142660[];
__asm__(".extern D_00142660, 16");
extern G_44A0E8 *D_L01_0021F740[];
__asm__(".extern D_L01_0021F740, 16");
extern u8 D_00000258[];
__asm__(".extern D_00000258, 16");

void func_L01_0044A0E8(u8 *o, s32 lo, s32 hi, s32 flags, s32 idx, s32 maxn, f32 zadd) {
    V4_44A0E8 vz;
    V4_44A0E8 v10;
    V4_44A0E8 v20;
    V4_44A0E8 v30;
    V4_44A0E8 v40;
    V4_44A0E8 v50;
    V4_44A0E8 v60;
    f32 f70;
    f32 f74;
    s32 c9 = 0;
    s32 c8 = 0;
    s32 c7 = 0;
    s32 c6 = 0;
    s32 c5 = 0;
    s32 c4 = 0;
    s32 c3 = 0;
    s32 c2 = 0;
    s32 c1 = 0;
    s32 c0 = 0;
    s32 fl5;
    s32 cnt;
    s32 left;
    s32 rem;
    s32 t0;
    s32 a2;
    s32 K;
    s32 k;
    f32 ang;
    f32 tt;
    f32 s0;
    f32 s1;
    f32 s2;
    f32 s3;
    f32 s4;
    f32 fa;
    V4_44A0E8 *pv10;
    V4_44A0E8 *pv20;
    V4_44A0E8 *pv40;

    qzero(&vz);
    if (!(flags & 0x20)) {
        if (o[0xB0] != 0xFF) {
            if ((u16)(*(u16 *)(o + 0xAA) - 0x1F4) >= 0x29) {
                D_L01_001D6714[0] = D_L01_001DFF00[o[0xB0]] >> 7;
            }
        }
    }
    fl5 = D_L01_001D6714[0] ? (((flags >> 5) ^ 1) & 1) : 0;
    if (flags == 0) {
        return;
    }
    if (lo == 0 && hi == 0) {
        return;
    }
    if (!(0 < lo)) {
        lo = 1;
    }
    cnt = func_0037E1D8(hi - lo + 1) + lo;
    if (cnt < 0x1F4 && fl5) {
        t0 = D_L01_001A91E8[D_001D545C_sda];
        if (t0 != 0) {
            a2 = D_L01_001A9280[D_001D545C_sda] * 0xE10 / t0;
            if (*(u32 *)(D_00142660 + 0x30) & 0xFFFF0000) {
                a2 = a2 / 2;
            }
            K = (s32)D_00000258;
            if (a2 < K / 2) {
                if (K * 3 / 10 < a2) {
                    cnt = cnt * (K * 19 / 30 - a2) / (K / 15);
                } else {
                    cnt = cnt * 5;
                }
                if (D_00142660[0x33] != 0) {
                    k = (K + 0) * 10 / 3;
                    if (k < cnt) cnt = k;
                } else {
                    k = K * 5 / 3;
                    if (k < cnt) cnt = k;
                }
            } else if (K < a2) {
                if (K * 7 / 6 < a2) {
                    cnt = cnt / 10;
                } else {
                    cnt = cnt * (K * 6 / 5 - a2) / (K * 4 / 15);
                }
                if (!(0 < cnt)) {
                    cnt = 1;
                }
            }
        }
    }
    rem = cnt;
    if (flags & 8) {
        c0 = rem / 30000;
        if (maxn < c0) c0 = maxn;
        rem -= c0 * 30000;
        left = maxn - c0;
        if (left > 0) {
            c1 = rem / 10000;
            if (left < c1) c1 = left;
            rem -= c1 * 10000;
            left -= c1;
            if (left > 0) {
                c2 = rem / 3000;
                if (left < c2) c2 = left;
                rem -= c2 * 3000;
                left -= c2;
                if (left > 0) {
                    c3 = rem / 1000;
                    if (left < c3) c3 = left;
                    rem -= c3 * 1000;
                    left -= c3;
                    if (left > 0) {
                        c4 = rem / 500;
                        if (left < c4) c4 = left;
                        rem -= c4 * 500;
                        left -= c4;
                        if (left > 0) {
                            c5 = rem / 100;
                            if (left < c5) c5 = left;
                            rem -= c5 * 100;
                            left -= c5;
                            if (left > 0) {
                                c6 = rem / 50;
                                if (left < c6) c6 = left;
                                rem -= c6 * 50;
                                left -= c6;
                                if (left > 0) {
                                    c7 = rem / 20;
                                    if (left < c7) c7 = left;
                                    rem -= c7 * 20;
                                    left -= c7;
                                    if (left > 0) {
                                        c8 = rem / 5;
                                        if (left < c8) c8 = left;
                                        rem -= c8 * 5;
                                        left -= c8;
                                        if (left > 0) {
                                            c9 = rem;
                                            if (left < rem) c9 = left;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        *(s32 *)(D_00142660 + 0x3C) += rem / (D_00142660[0x5A] + 1);
    } else {
        if (rem >= 30000) {
            c0 = rem / 30000;
            rem -= c0 * 30000;
        }
        if (rem >= 10000) {
            c1 = rem / 10000;
            rem -= c1 * 10000;
        }
        if (rem >= 3000) {
            c2 = rem / 3000;
            rem -= c2 * 3000;
        }
        if (rem >= 1000) {
            c3 = rem / 1000;
            rem -= c3 * 1000;
        }
        if (rem >= 500) {
            c4 = rem / 500;
            rem -= c4 * 500;
        }
        if (rem >= 100) {
            c5 = rem / 100;
            rem -= c5 * 100;
        }
        if (rem >= 50) {
            c6 = rem / 50;
            rem -= c6 * 50;
        }
        if (rem >= 20) {
            c7 = rem / 20;
            rem -= c7 * 20;
        }
        if (rem >= 5) {
            c8 = rem / 5;
            rem -= c8 * 5;
        }
        c9 = rem;
        if (c0 < 0 || c1 < 0 || c2 < 0 || c3 < 0 || c4 < 0 || c5 < 0 || c6 < 0 || c7 < 0 || c8 < 0 || c9 < 0) {
            if (c0 < 0) c0 = 0;
            if (c1 < 0) c1 = 0;
            if (c2 < 0) c2 = 0;
            if (c3 < 0) c3 = 0;
            if (c4 < 0) c4 = 0;
            if (c5 < 0) c5 = 0;
            if (c6 < 0) c6 = 0;
            if (c7 < 0) c7 = 0;
            if (c8 < 0) c8 = 0;
            if (c9 < 0) c9 = 0;
        }
    }
    if (c9 != 0 || c8 != 0 || c7 != 0 || c6 != 0 || c5 != 0 || c4 != 0 || c3 != 0 || c2 != 0 || c1 != 0 || c0 != 0) {
        do {
            pv10 = &v10;
            func_003886E8(pv10, o, 0.0009765625f);
            s4 = 0.0f;
            ang = func_0037E2A8();
            s3 = 3.0f;
            s2 = 0.016666668f;
            s0 = func_00388960(ang);
            s0 = s0 * (func_0037E250(s4, s3) * s2);
            v20.x = s0;
            s0 = func_00388978(ang);
            s0 = s0 * (func_0037E250(s4, s3) * s2);
            v20.y = s0;
            v20.z = s4;
            v20.z = func_0037E250(3.7f, 6.0f) * s2;
            v30.x = v20.x;
            v30.y = v20.y;
            v30.z = s4;
            func_00388830(&v30, &v30, 0.5f);
            vec_add_ab(&v10, &v10, &v30);
            v10.z = v10.z + zadd;
            pv20 = &v20;
            if (idx >= 0) {
                fa = 120.0f;
                if (func_L01_00443080(&f70, &f74, -0.0015f, v20.z + 0.0015f, v10.z - D_L01_0021F740[idx]->f18) >= 1) {
                    if (0.0f < f70) {
                        if (f70 < fa) {
                            fa = f70;
                        }
                    }
                }
                pv40 = &v40;
                func_003886E8(pv40, pv20, fa);
                vec_add_ab(pv40, pv40, (V4_44A0E8 *)(o + 0x10));
                func_L01_00473E10(idx, o + 0x10, pv40, &v50);
                vec_sub_ba(pv40, &v50, &v10);
                v40.z = 0.0f;
                func_00388830(&v60, pv40, 0.25f);
                tt = 1.0f / fa;
                vec_sub_ab(pv40, pv40, &v60);
                func_003886E8(pv40, pv40, tt);
                v20.x = v40.x;
                v20.y = v40.y;
            }
            vec_add_ba(&v20, &v20, &vz);
            if (c0 != 0) {
                func_L01_002F8F60(o, pv10, pv20, flags, 30000, fl5);
                c0 = c0 - 1;
            } else if (c1 != 0) {
                func_L01_002F8F60(o, pv10, pv20, flags, 10000, fl5);
                c1 = c1 - 1;
            } else if (c2 != 0) {
                func_L01_002F8F60(o, pv10, pv20, flags, 3000, fl5);
                c2 = c2 - 1;
            } else if (c3 != 0) {
                func_L01_002F8F60(o, pv10, pv20, flags, 1000, fl5);
                c3 = c3 - 1;
            } else if (c4 != 0) {
                func_L01_002F8F60(o, pv10, pv20, flags, 500, fl5);
                c4 = c4 - 1;
            } else if (c5 != 0) {
                func_L01_002F8F60(o, pv10, pv20, flags, 100, fl5);
                c5 = c5 - 1;
            } else if (c6 != 0) {
                func_L01_002F8F60(o, pv10, pv20, flags, 50, fl5);
                c6 = c6 - 1;
            } else if (c7 != 0) {
                func_L01_002F8F60(o, pv10, pv20, flags, 20, fl5);
                c7 = c7 - 1;
            } else if (c8 != 0) {
                func_L01_002F8F60(o, pv10, pv20, flags, 5, fl5);
                c8 = c8 - 1;
            } else {
                func_L01_002F8F60(o, pv10, pv20, flags, 1, fl5);
                c9 = c9 - 1;
            }
        } while (c9 != 0 || c8 != 0 || c7 != 0 || c6 != 0 || c5 != 0 || c4 != 0 || c3 != 0 || c2 != 0 || c1 != 0 || c0 != 0);
    }
}
/* localdecomp:end func_L01_0044A0E8 */
