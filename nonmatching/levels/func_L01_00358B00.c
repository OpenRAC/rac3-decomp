/* PAL near miss, round 27 W30. Level 01, 995 raw / 165 difflib-aligned differences (tools-w9 ad.py, check.py --no-context,
   file flags incl. @ps2as; the W6 draft measured 780 raw / 344 aligned with the same scorer).
   Levers found this round (see Data/sonnet-b41-w30-findings.md):
   - the 6th argument of func_L01_00358338 is the scalar D_L01_001E1A20 (assembler macro lw, no hoisted lui);
   - nin/one/lim are initialised locals in this order (priority order of the hoisted loop-1 constants: s3=-1, s4=1, s5=19);
   - i is initialised in its declaration; the loop-1 table is indexed by i (a giv, no p++);
   - D_001D66B0 and D_L01_001E1A24_00358B00 are small sized externs (u8[8] / u8 *[2]): unsplit `la`, not hoisted by loop.c;
   - the loop-3 divisor `six` is a local set at the top of the t loop (loop.c hoists it like retail);
   - the loop-1 compare is written `q->f14 >= D_L01_001DD650` (register order of the two lwc1), D_L01_001E1A3C/40 are sized small (macro lw), m is computed before C (one slt shared), the C/m block sits BEFORE the func_L01_004C7D98 call (C's live range 4 insns longer: priority 0.1636 < t's 0.1653, so t gets $s6 and C $s7 as in retail), m is declared in the block that uses it (its pseudo number decides the spill slot order).
   Still differs: conditional-move polarity in loop 1 (retail movn zero, ours movz), the k computation registers,
   saved registers of loops 2 and 3 (e/e2 copy, v20/w roles: retail v10 s3, w s5, v40 s6, v30 s7, v20 fp), spill slot of the k<2 flag (0x68 in retail, 0x70 ours), the hoisted D_L01_00221098 in $fp that retail rematerialises, 2 words missing in total.
   The scratch check used per-block aliases for names the file's later blocks declare differently, and the Vec4 typedef of block 1. */
/* localdecomp:start func_L01_00358B00 */
#include "vu0.h"


typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[0x6A];
    f32 f6C;
    u8 pad70[0x80];
} Row_00358B00;
typedef struct {
    u8 pad[0x24];
    u8 *p24;
} T_00358B00;
typedef struct {
    u8 pad[0x18];
    T_00358B00 *p18;
} D_00358B00;

extern u8 D_0014263F[];
extern u8 D_001425C0[];
extern Row_00358B00 D_L01_002C5600_00358B00[];
extern Vec4 D_L01_00284310[];
extern Vec4 D_L01_00284320_00358B00[];
typedef struct {
    u8 p0[0x80];
    Vec4 v80;
    u8 p90[0x128];
    s32 f1B8;
    u8 p1BC[0x2408];
    s32 f25C4;
    u8 p25C8[0x25];
    u8 b25ED;
} H_00358B00;
extern H_00358B00 D_001A4BE0_00358B00;
__asm__(".extern D_001A4BE0_00358B00, 16");
extern u8 *D_L01_001E1A20_00358B00[];
extern u8 *D_L01_001E1A24_00358B00[2];
extern s32 D_L01_001E1A20;
extern u8 *D_L01_001E1A24;
__asm__(".extern D_L01_001E1A24, 16");
extern u8 *D_L01_001E1A3C_00358B00[1];
extern u8 *D_L01_001E1A40_00358B00[1];
extern Vec4 D_L01_001E1A60;
extern Vec4 D_L01_001EAA20[];
extern D_00358B00 D_L01_001EAA00[];
extern u8 D_L01_002B2B00[];
extern u8 *D_L01_00221098[];
extern u8 D_001D66B0[8];
extern s32 D_L01_001DD658;
extern f32 D_L01_001DD650;
extern s32 D_L01_001DD688;
extern s32 D_L01_001DD68C;
__asm__(".extern D_L01_001DD658, 4");
__asm__(".extern D_L01_001DD650, 4");
__asm__(".extern D_L01_001DD688, 4");
__asm__(".extern D_L01_001DD68C, 4");

extern s32 func_0013D3E0(void);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003A52A0(s32, s32, void *);
extern void func_003C2F58(s32, s32, void *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_00358338(void *, void *, s32, void *, s32, s32);
extern void func_L01_003586F8(f32 *);
extern s32 func_L01_003589B0(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f12, f32 f13);
extern void func_L01_0035AC28(s32, f32 *, Vec4 *, Vec4 *);
extern s32 func_L01_003F2058(void *, void *);
extern void func_L01_003F2278(s32, void *);
extern void func_L01_00404808(void *, void *);
extern void func_L01_0044FD88(void *, void *, s32, s32);
extern void func_L01_004C7D98(void *, void *);
extern u8 *func_L01_004669B0(f32, f32, f32, f32, void *, s32, void *, u32, s32);
extern void func_L01_00466F50(void *, void *, s32, f32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004739D8(void *, void *, s32, f32, s32, s16, s32);
extern void func_L01_00359E10(u8 *);

void func_L01_00358B00(u8 *a0) {
    Vec4 v0, v10, v20, v30, v40;
    u8 *q = *(u8 **)(a0 + 0x68);
    s32 k = D_L01_002C5600_00358B00[D_0014263F[0]].b1;
    u8 *obj;
    s32 particle_col;
    s32 i = 1, j, t, col, n;
    u8 **p;
    s32 nin = 19;
    s32 one = 1;
    s32 lim = -1;
    s32 C;
    Vec4 *w;
    f32 *e;
    f32 *e2;

    for (; i < 10; i++) {
        s32 skip = 0;
        if (D_L01_001DD658 != 0 && D_001A4BE0_00358B00.f25C4 == nin) {
            skip = (i > lim) ? 0 : one;
        }
        if (*(f32 *)(q + 0x14) >= D_L01_001DD650 && skip == 0) {
            v0.q = D_L01_00284320_00358B00[i].q;
            func_L01_00358338(D_L01_001E1A24_00358B00[i - 2], D_L01_001E1A24_00358B00[i - 1], 0, &v0, i, D_L01_001E1A20);
        } else {
            func_L01_0044FD88(D_L01_001E1A24_00358B00[i - 2], D_L01_001E1A24_00358B00[i - 1], 0, 0);
        }
    }
    if ((D_001A4BE0_00358B00.f25C4 == 19 && D_001A4BE0_00358B00.f1B8 >= 6) ||
        (D_001A4BE0_00358B00.f25C4 == 20 && D_001A4BE0_00358B00.f1B8 >= 18) ||
        *(s32 *)(q + 0x20) != 0) {
        w = D_L01_001EAA20;
        for (j = 1; j < 10; j++) {
            Vec4 *local_v20 = &v20;
            col = 0x10000;
            if ((k == 0 || k == 1)) {
                col = 0x110000;
            } else if (k == 2 || k == 3) {
                col = 0x210000;
            } else if (k >= 4) {
                col = 0x210000;
            }
            func_003C2F58((s32)D_L01_001E1A20_00358B00[j - 1], 0, &v0);
            func_003C2F58((s32)D_L01_001E1A20_00358B00[j], 1, &v10);
            if (D_L01_001E1A24 != 0 && (D_L01_001E1A24[0x34] ^ 1) & 1) {
                if (j == 8) {
                    func_003C2F58((s32)D_L01_001E1A3C_00358B00[0], 0, local_v20);
                    func_003C2F58((s32)D_L01_001E1A40_00358B00[0], 1, &v30);
                    vec_sub_ba(&v40, &v30, &v20);
                    func_0038CE20(v40.f, &v40, 1.5f);
                    vec_add_ab(&v30, &v40, &v20);
                    func_L01_003589B0(a0, (s32)local_v20, (s32)&v30, col, 1, 3, 0, (D_L01_002C5600_00358B00 + D_001425C0[0x7F])->f6C, 0.75f);
                }
                if (func_L01_003589B0(a0, (s32)&v0, (s32)&v10, col, 1, 3, 0, (D_L01_002C5600_00358B00 + D_001425C0[0x7F])->f6C, 0.75f)) {
                    D_L01_001E1A60.q = w[0].q;
                    v20.q = w[2].q;
                    e = v30.f;
                    e2 = e;
                    for (n = 9; n >= 0; n--) {
                        func_0038CDF8(e2, &D_L01_001E1A60, D_L01_001EAA20, func_003824E0(0.0f, 1.0f));
                        func_L01_003586F8(e2);
                    }
                    func_0038CDF8(e, &D_L01_001E1A60, w, func_003824E0(0.0f, 1.0f));
                    if (!(D_L01_001EAA00[0].p18 != 0 && D_L01_001EAA00[0].p18->p24 != 0 && D_L01_001EAA00[0].p18->p24[0x46] == 5)) {
                        func_L01_0035AC28((s32)a0, e, local_v20, (Vec4 *)D_001D66B0);
                    }
                    func_003A52A0(6, 0, a0);
                    if (*(s32 *)(q + 0x20) == 0) {
                        *(s32 *)(q + 0x2C) = func_L01_003F2058(D_L01_002B2B00, 0);
                    }
                }
            }
        }
    }
    if (D_001A4BE0_00358B00.b25ED == 0 && D_L01_001E1A24 != 0 && (D_L01_001E1A24[0x34] ^ 1) & 1) {
        s32 m;
        m = 0;
        if ((k == 0 || k == 1)) {
            C = k < 4;
        } else if (k == 2 || k == 3) {
            C = k < 4;
            m = 1;
        } else {
            m = (k < 4) ^ 1;
            C = k < 4;
        }
        func_L01_004C7D98(&D_001A4BE0_00358B00.v80, &v0);
        for (j = 2; j < 10; j++) {
            if (D_001A4BE0_00358B00.f25C4 == 19 || D_001A4BE0_00358B00.f25C4 == 20 || *(s32 *)(q + 0x20) != 0) {
                for (t = 7; t >= 0; t--) {
                    s32 six = 6;
                    obj = 0;
                    if (C) {
                        func_0038CDF8(&v10, &D_L01_00284310[j], &D_L01_00284320_00358B00[j], func_003824E0(0.0f, 1.0f));
                        if ((k == 0 || k == 1)) {
                            obj = func_L01_004713C8(&v10, D_001D66B0, (func_00382498(2, 3) * 5 + 2) / six, func_00382498(0x40, 0x64) | 0x5F404000, 1, 0x4F, 0, 1, 42000.0f, 63000.004f, 0.0f);
                        } else if (k == 2 || k == 3) {
                            obj = func_L01_004713C8(&v10, D_001D66B0, (func_00382498(2, 3) * 5 + 2) / six, 0x5FC8C8C8, 1, 0x4F, 0, 1, 52500.0f, 73500.0f, 0.0f);
                        }
                    }
                    if (obj != 0) {
                        obj[2] = D_L01_00221098[91][m];
                        if (k >= 2) {
                            obj[3] = func_00382468(4) ? 0x48 : 0x44;
                        }
                    }
                    if (!C) {
                        func_0038CDF8(&v10, &D_L01_00284310[j], &D_L01_00284320_00358B00[j], func_003824E0(0.0f, 1.0f));
                        obj = func_L01_004713C8(&v10, D_001D66B0, (func_00382498(2, 3) * 5 + 2) / six, 0, (s32)func_L01_00443A18(2.0f, 3.0f), 0x7F, 0x7F, 6, func_003824E0(0.4f, 0.7f) * 210000.0f, 6300.0f, 0.0f);
                        if (obj != 0) {
                            obj[3] = 0x44;
                            obj[2] = *D_L01_00221098[53];
                        }
                        obj = func_L01_004713C8(&v10, D_001D66B0, (func_00382498(2, 3) * 5 + 2) / six, 0x7C0030, (s32)func_L01_00443A18(2.0f, 3.0f), 0x30, 0x30, 0, func_003824E0(0.4f, 0.7f) * 210000.0f * 1.3f, 12600.0f, 0.0f);
                        if (obj != 0) {
                            obj[3] = 0x44;
                            obj[2] = *D_L01_00221098[53];
                        }
                    }
                }
                for (t = 0; t < 2; ++t) {
                    func_0038CDF8(&v10, &D_L01_00284310[j], &D_L01_00284320_00358B00[j], func_003824E0(0.0f, 1.0f));
                    func_0038CF68(&v0, &v0, func_003824E0(0.0025f, 0.01f));
                    if ((k == 0 || k == 1)) {
                        if (func_0013D3E0() % 100 == 0) {
                            func_L01_00466F50(&v10, &v0, 0, -1.0f, 0.0f);
                        }
                    } else if (k == 2 || k == 3) {
                        if (func_0013D3E0() % 200 == 0) {
                            func_L01_004739D8(&v10, &v0, (func_00382498(0x40, 0x64) << 16) | 0x64004040, func_003824E0(0.1f, 0.2f) * 210000.0f, 0xFF0A0A, (s16)((func_00382498(0x78, 0xF0) * 5 + 2) / 6), 0);
                        }
                    } else if (!C) {
                        if (func_0013D3E0() % 200 == 0) {
                            func_L01_004739D8(&v10, &v0, (func_00382498(0x40, 0x64) << 16) | 0x64004040, func_003824E0(0.1f, 0.2f) * 210000.0f, 0xFF0A0A, (s16)((func_00382498(0x78, 0xF0) * 5 + 2) / 6), 0);
                        }
                    }
                }
            } else {
                if (*(s32 *)(q + 0x2C) >= 0) {
                    func_L01_003F2278(*(s32 *)(q + 0x2C), 0);
                    *(s32 *)(q + 0x2C) = -1;
                }
                for (t = 0; t < 2; t++) {
                    f32 fa, fb;
                    particle_col = func_00382498(0x40, 0x64) | 0x5F404000;
                    fa = 0.1f;
                    fb = 0.22f;
                    if (!C) {
                        particle_col = 0x3F804020;
                        fa = 0.11f;
                        fb = 0.2f;
                    }
                    if (t == 0 && !C) {
                        func_0038CDF8(&v10, &D_L01_00284310[j], &D_L01_00284320_00358B00[j], func_003824E0(0.0f, 1.0f));
                        obj = func_L01_004713C8(&v10, D_001D66B0, (func_00382498(6, 12) * 5 + 2) / 6, particle_col, 1, 0x3F, 0, 1, fa * 210000.0f, fb * 210000.0f, 0.0f);
                        if (obj != 0) {
                            obj[2] = D_L01_00221098[104][func_00382498(0, 3)];
                        }
                    } else {
                        func_0038CDF8(&v10, &D_L01_00284310[j], &D_L01_00284320_00358B00[j], func_003824E0(0.0f, 1.0f));
                        obj = func_L01_004713C8(&v10, D_001D66B0, (func_00382498(6, 12) * 5 + 2) / 6, particle_col, 1, 0x3F, 0, 1, fa * 210000.0f, fb * 210000.0f, 0.0f);
                        if (obj != 0) {
                            obj[2] = D_L01_00221098[91][m];
                        }
                    }
                    if (!C) {
                        func_0038CDF8(&v10, &D_L01_00284310[j], &D_L01_00284320_00358B00[j], func_003824E0(0.0f, 1.0f));
                        obj = func_L01_004713C8(&v10, D_001D66B0, 7, 0, (s32)func_L01_00443A18(2.0f, 3.0f), 0x7F, 0x7F, 6, func_003824E0(0.25f, 0.35f) * 210000.0f, 2100.0f, 0.0f);
                        if (obj != 0) {
                            obj[3] = 0x44;
                            obj[2] = D_L01_00221098[D_L01_001DD688][D_L01_001DD68C];
                        }
                        obj = func_L01_004713C8(&v10, D_001D66B0, 7, 0x7C0030, (s32)func_L01_00443A18(2.0f, 3.0f), 0x30, 0, 0, func_003824E0(0.25f, 0.35f) * 210000.0f * 1.1f, 4200.0f, 0.0f);
                        if (obj != 0) {
                            obj[3] = 0x44;
                            obj[2] = D_L01_00221098[D_L01_001DD688][D_L01_001DD68C];
                        }
                    }
                    if (t == 0 && k != 4) {
                        func_0038CF68(&v0, &v0, func_003824E0(0.0025f, 0.01f));
                        if ((k == 0 || k == 1)) {
                            n = func_00382468(5) + 1;
                            obj = func_L01_004669B0(0.0f, 0.99f, 0.995f, func_003824E0(0.1f, 0.2f) * 210000.0f, &v10, n, &v0, func_00382498(0x46, 0x96) | 0x404000, 2);
                        } else if (k == 2 || k == 3) {
                            n = func_00382468(5) + 1;
                            obj = func_L01_004669B0(0.0f, 0.99f, 0.995f, func_003824E0(0.1f, 0.2f) * 210000.0f, &v10, n, &v0, 0x606060, 2);
                            if (obj != 0) {
                                obj[2] = D_L01_00221098[91][m];
                            }
                        } else if (!C) {
                            n = func_00382468(5) + 1;
                            obj = func_L01_004669B0(0.0f, 0.99f, 0.995f, func_003824E0(0.1f, 0.2f) * 210000.0f, &v10, n, &v0, 0x606060, 2);
                            if (obj != 0) {
                                obj[2] = D_L01_00221098[91][m];
                            }
                        }
                        if (obj != 0) {
                            obj[3] = func_00382468(3) ? 0x48 : 0x44;
                        }
                    }
                    func_0038CF68(&v0, &v0, func_003824E0(0.0025f, 0.01f));
                    if ((k == 0 || k == 1)) {
                        if (func_0013D3E0() % 100 == 0) {
                            func_L01_00466F50(&v10, &v0, 0, -1.0f, 0.0f);
                        }
                    } else if (k == 2 || k == 3) {
                        if (func_0013D3E0() % 200 == 0) {
                            func_L01_004739D8(&v10, &v0, (func_00382498(0x40, 0x64) << 16) | 0x64004040, func_003824E0(0.1f, 0.2f) * 210000.0f, 0xFF4646, (s16)((func_00382498(0x78, 0xF0) * 5 + 2) / 6), 1);
                        }
                    } else if (!C) {
                        if (func_0013D3E0() % 200 == 0) {
                            func_L01_004739D8(&v10, &v0, (func_00382498(0x40, 0x64) << 16) | 0x64004040, func_003824E0(0.1f, 0.2f) * 210000.0f, 0xFF4646, (s16)((func_00382498(0x78, 0xF0) * 5 + 2) / 6), 1);
                        }
                    }
                }
            }
        }
        func_L01_00404808(func_L01_00359E10, a0);
    }
}
/* localdecomp:end func_L01_00358B00 */
