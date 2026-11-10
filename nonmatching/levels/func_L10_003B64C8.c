/* func_L10_003B64C8: a level-10 (Zeldrin Starport) boss/enemy moby update: a switch on its mode
   (m+0x95: 0-5, jtbl_002BD350) and a 31-way switch on its state (m+0x20, cases 1-31, jtbl_002BD370),
   then func_L10_003B8F50. No COP2 instructions: a plain-C match is possible.
   Compiling draft (Opus, 2026-11-08), first pass: m2c on retail with both jump tables (kit
   m2cjt3.py, fixed copy), converted to the Mo/Pv/G union style, the mode switch restructured by
   hand (m2c had folded modes 1-3 into gotos after the state switch; mode 3 returns after the kill
   effect when pv+0x30 <= 0), the early returns (pv+0x33C with state 0x1D, func_L10_003B85A0),
   some m2c address temps inlined.
   Near miss: 2025 of retail's 2102 instructions; 1114 lines (53.0 percent) and 1698 opcodes
   (80.8 percent) equal (kit cd.py). The line count swings with the global allocation: retail keeps
   m in $s4 and pv in $s3, this draft $s3/$s2 (one temp inlining moved it to 75 percent before the
   pointer fixes below changed it back); compare opcodes until the gotos are gone.
   Needs on src/levels/10_zeldrin_starport/L10_003B5B48.c: "-O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as" (float constants built inline); the file has no other C.
   Notes:
   - D_L10_0021D1C0 is an array of path pointers (s32 count, then 0x10-byte points from +0x10);
     byte offsets are written through (u8 *) casts;
   - prototypes: fe_func_003C41A0 is (p, f32, p, f32, f32, f32) and func_L01_004468C8 s32 (...) as
     in func_L06_0034A7A8 (not used here); func_L01_00448728/004482A0/00448340 take their trailing
     arguments as floats (m2c printed the bits);
   - state 25's func_L01_004482A0 third argument is m2c's offset only (the record pointer plus
     pv->i[0x334/4] * 0x10, as in state 24): fix it.
   Left (as func_L24_00352060 went from 86 to 99.5 percent):
   - 19 m2c gotos: the shared tails (004450F0 with a state number, the record-follow block of
     states 19/20/26/18/23, 0x1B/0x13 kill-state calls) written per state as straight code;
   - per-case locals for the animation time, the m2c pointer temps inlined;
   - calls before constants in comparisons, if/else orders from retail's branch layout. */
typedef int u128_t __attribute__((mode(TI)));
typedef union Mo_ { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; long d[0x20]; u128_t q[0x10]; } Mo;
typedef union Pv_ { u8 b[0x1000]; s8 c[0x1000]; s16 h[0x800]; u16 uh[0x800]; s32 i[0x400]; u32 u[0x400]; f32 f[0x400]; void *p[0x400]; long d[0x200]; u128_t q[0x100]; } Pv;
typedef union G_ { u8 b[0x4000]; s8 c[0x4000]; s16 h[0x2000]; u16 uh[0x2000]; s32 i[0x1000]; u32 u[0x1000]; f32 f[0x1000]; void *p[0x1000]; long d[0x800]; u128_t q[0x400]; } G;
typedef union { f32 f[4]; s32 i[4]; s8 c[16]; u8 b[16]; s16 h[8]; u16 uh[8]; u128_t q; } __attribute__((aligned(16))) U16;
extern s32 *D_L10_0021D1C0[];
extern f32 D_L10_001DE75C;
__asm__(".extern D_L10_001DE75C, 4");
extern f32 D_L10_001DE764;
__asm__(".extern D_L10_001DE764, 4");
extern f32 D_L10_001DE768;
__asm__(".extern D_L10_001DE768, 4");
extern f32 D_L10_001DE76C;
__asm__(".extern D_L10_001DE76C, 4");
extern s32 func_00382498(s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 func_L01_004395E0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_L01_00447878(void *, void *, s32, f32, f32);
extern s32 func_L01_004482A0(void *, void *, void *, f32, f32, f32, f32);
extern s32 func_L01_00448340(void *, void *, void *, f32, f32, f32);
extern s32 func_L01_00448728(void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004561E0(void *);
extern void func_L01_0045A748(void *, void *);
extern s32 func_L01_0045A898(void *, void *, f32);
extern void func_L01_0045A9F0(void *);
extern s32 func_L01_0045BD10(void *, f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0045BDE8(void *, s32);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern s32 func_L01_0045C2A0(void *, f32, f32, f32);
extern s32 func_L05_0032B880(void *, void *, void *, f32);
extern s32 func_L10_003B85A0(void *);
extern s32 func_L10_003B8ED0(void *, s32);
extern s32 func_L10_003B8F50(void *);
extern s32 func_L10_003B9078(void *, s32, s32, s32);
extern s32 func_L10_003B9D28(void *);
#include "vu0.h"
void func_L10_003B64C8(Mo *m) {
    U16 sp90;
    U16 spA0;
    s32 var_4;
    s32 var_5;
    s32 var_5_3;
    s32 var_5_4;
    s32 var_5_5;
    f32 temp_4_2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 var_f0;
    f32 var_f0_2;
    u128_t *temp_16_3;
    s32 *temp_16_6;
    s32 *temp_17_11;
    s32 *temp_17_3;
    s32 *temp_17_4;
    s32 *temp_17_5;
    s32 *temp_17_6;
    s32 temp_2_10;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_5;
    s32 temp_6_2;
    u32 temp_4;
    u8 temp_2;
    u8 temp_3;
    u8 temp_3_5;
    void *temp_16;
    void *temp_16_10;
    void *temp_16_11;
    void *temp_16_12;
    void *temp_16_13;
    void *temp_16_14;
    void *temp_16_15;
    void *temp_16_16;
    void *temp_16_17;
    void *temp_16_18;
    void *temp_16_19;
    void *temp_16_20;
    void *temp_16_21;
    void *temp_16_22;
    void *temp_16_2;
    void *temp_16_4;
    void *temp_16_5;
    void *temp_16_7;
    void *temp_16_8;
    void *temp_16_9;
    void *temp_17;
    void *temp_17_10;
    void *temp_17_2;
    void *temp_17_7;
    void *temp_17_8;
    void *temp_17_9;
    Pv *pv;
    void *temp_2_2;
    void *temp_2_7;
    void *temp_2_8;
    void *temp_2_9;
    void *temp_3_4;
    void *temp_4_3;
    void *temp_4_4;
    void *temp_4_5;
    void *temp_4_6;
    void *temp_4_7;
    void *temp_4_8;
    void *temp_4_9;
    void *temp_5_2;
    void *temp_6;
    void *var_16;
    void *var_21;
    void *var_21_2;
    void *var_21_3;
    void *var_2;
    void *var_5_2;

    pv = m->p[0x68/4];
    if ((pv->i[0x33C/4] != 0) && (m->b[0x20] == 0x1D)) {
        return;
    }
    if (func_L10_003B85A0(m) != 0) {
        return;
    }
    switch (m->b[0x95]) {
    case 0:
        if (func_L01_004561E0(m) != 0) {
            pv->h[0x2D6/2] = (func_00382498(0, 0x1E) * 5 + 2) / 6;
        }
        if (pv->h[0x234/2] == 1) {
                func_L10_003B9078(m, 6, 0, 8);
                func_L01_004450F0(m, 9, 2);
                temp_3_2 = pv->i[0x310/4];
                if (temp_3_2 != -1) {
                    func_L01_004450F0(m, 0xC, 2);
                    func_L10_003B9078(m, 6, 0, 8);
                    if (pv->i[0x320/4] != 0) {
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 8);
                        if (m->b[0x43] != 6) {
                            func_003C3A10(m, 6, 0, 8);
                        }
                        func_L01_004450F0(m, 0x11, -1);
                    }
                } else if (pv->i[0x314/4] != temp_3_2) {
                    func_L01_004450F0(m, 0xD, 2);
                    func_L10_003B9078(m, 6, 0, 8);
                    if (pv->i[0x320/4] != 0) {
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 8);
                        if (m->b[0x43] != 6) {
                            func_003C3A10(m, 6, 0, 8);
                        }
                        func_L01_004450F0(m, 0xF, -1);
                    }
                }
                if (pv->i[0x328/4] != 0) {
                    func_L01_004450F0(m, 0xE, -1);
                    func_L10_003B9078(m, 0xD, 0, 2);
                    func_003C3A10(pv->p[0x2DC/4], 2, 0, 8);
                    if (pv->i[0x320/4] != 0) {
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 8);
                        func_L01_004450F0(m, 0x10, -1);
                    }
                    if (pv->i[0x310/4] != -1) {
                        func_003C3A10(pv->p[0x2DC/4], 2, 0, 8);
                        func_L01_004450F0(m, 0x10, -1);
                    }
                }
        } else if ((pv->i[0x2D8/4] != 0) && (func_0038CB00(pv->b + 0x2D6) != 0)) {
            pv->i[0x2D8/4] = 0;
            if (pv->i[0x2D0/4] < 0xFA) {
                pv->i[0x2D0/4] = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    case 1:
        if (pv->h[0x234/2] == 1) {
            func_L01_004450F0(m, 9, 2);
        } else if (pv->i[0x2D0/4] == 0) {
            func_L01_004450F0(m, 1, 0);
        }
        break;
    case 2:
        if ((pv->h[0x234/2] != 1) && (m->b[0x20] != 0x10) && (m->b[0x20] != 0xE)) {
            func_L10_003B9078(m, 0, 0, 8);
            func_L01_004450F0(m, 2, 1);
            pv->i[0x2D0/4] = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
        }
        break;
    case 3:
        {
            s32 r = func_L01_00454370(m, pv->b + 0x160);
            if (pv->f[0x30/4] <= 0.0f) {
                func_L10_003B8ED0(m, 0);
                func_003A52A0(4, 0, m);
                func_L01_003303B8(m->b + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 2.0f, 1, 1, 1, 0, 1, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                func_003C2880(m);
                return;
            }
            if (r & 2) {
                if (pv->h[0x234/2] == 1) {
                    func_L10_003B9078(m, 6, 0, 8);
                    func_L01_004450F0(m, 9, 2);
                } else {
                    func_L10_003B9078(m, 0, 0, 8);
                    func_L01_004450F0(m, 2, 1);
                    pv->i[0x2D0/4] = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
                }
            }
        }
        break;
    case 5:
        break;
    }
                switch (m->b[0x20]) {                   /* switch 2 */
                case 1:
                    break;
                case 12:                            /* switch 2 */
                    func_L01_00448728(pv->p[0x2DC/4] + 0xF8, pv->b + 0x330, 0, m->f[0xF8/4], 0.0030717796f, 0.0008377581f, 0.15358898f);
                    if (func_L01_004561B8(m) != 0) {
                        pv->i[0x2D8/4] = 0;
                    }
                    if (func_L01_0045BDE8(m, pv->i[0x310/4]) != 0) {
                        func_L10_003B9078(m, 9, 0, 8);
                        func_L01_004450F0(m, 0x1B, 2);
                    }
                    if ((func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) < 10.0f) && ((u16) m->uh[0x96/2] >= 5U) && (pv->i[0x348/4] == 0)) {
block_158:
                        func_L10_003B9078(m, 9, 0, 8);
                        func_L01_004450F0(m, 0x1B, 2);
                    }
                    break;
                case 17:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        pv->i[0x2D8/4] = 0;
                    }
                    temp_16 = pv->p[0x2DC/4] + 0xF8;
                    func_L01_00448728(temp_16, pv->b + 0x330, 0, func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]), 0.0030717796f, 0.0008377581f, 0.15358898f);
                    if (func_L01_0045BDE8(m, pv->i[0x310/4]) != 0) {
                        func_L10_003B9078(m, 9, 0, 8);
                        func_L01_004450F0(m, 0x1B, 2);
                    }
                    if (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) < 8.0f) {
                        if ((u16) m->uh[0x96/2] >= 5U) {
                            func_L10_003B9078(m, 9, 0, 8);
                            func_L01_004450F0(m, 0x1B, 2);
                        }
                    }
                    if ((m->uh[0x96/2] >= 0x5BU) && (func_L10_003B9D28(m) != 0)) {
                        func_003C3A10(pv->p[0x2DC/4], 0xA, 0, 5);
                        var_5 = 0x13;
block_188:
                        func_L01_004450F0(m, var_5, -1);
                    }
                    break;
                case 19:                            /* switch 2 */
                    temp_16_2 = pv->p[0x2DC/4] + 0xF8;
                    func_L01_00448728(temp_16_2, pv->b + 0x330, 0, func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]), 0.0030717796f, 0.0008377581f, 0.15358898f);
                    if (((G *)(pv->p[0x2DC/4]))->b[0x60] & 2) {
                        func_L01_004450F0(m, 0x11, 2);
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 5);
                    }
                    if ((func_L01_0045BDE8(m, pv->i[0x310/4]) != 0) && (m->b[0x43] != 9)) {
                        func_003C3A10(m, 9, 0, 8);
                    }
                    if (func_L01_0044E1B8(pv->p[0x2DC/4], 0.5f) != 0) {
                        temp_4_3 = pv->p[0x2DC/4];
                        if (((G *)temp_4_3)->b[0x42] == 0xA) {
                            func_003C2F58(temp_4_3, 0, &sp90);
                            if (!(fabs_asm(m->f[0x18/4] - pv->f[0x228/4]) < 2.0f)) {
block_176:
                                temp_17 = m->b + 0x10;
                                var_f0 = func_0038CF38(temp_17, ((G *)pv->p[0x230/4])->b + 0x10);
                                var_21 = temp_17;
                                var_5_2 = pv->p[0x2DC/4] + 0xC0;
block_177:
                                func_0038CF68(&spA0, var_5_2, (var_f0 / 1.3f) * 0.020000001f);
                            } else {
block_174:
                                temp_2_2 = m->b + 0x10;
                                var_16 = pv->p[0x2DC/4] + 0xC0;
                                var_21 = temp_2_2;
                                var_f0_2 = func_0038CF38(temp_2_2, ((G *)pv->p[0x230/4])->b + 0x10);
block_175:
                                func_0038CF68(&spA0, var_16, (var_f0_2 / 1.3f) * 0.020000001f);
                            }
block_178:
                            spA0.f[2] = func_L01_00447878(&sp90, pv->b + 0x220, 0, func_0038CF38(var_21, ((G *)pv->p[0x230/4])->b + 0x10) * 0.020000001f, 0xBB902DE0);
                            func_L05_0032B880(&sp90, &spA0, m, 5.0f);
                        }
                    }
                    break;
                case 14:                            /* switch 2 */
                    temp_17_2 = m->b + 0x10;
                    temp_16_3 = (u8 *)D_L10_0021D1C0[pv->i[0x314/4]] + 0x10;
                    func_L01_00448340(temp_17_2, temp_16_3, pv->b + 0x2E8, 0.0032000002f, 0.014400001f, 0.080000006f);
                    if (func_0038CF00(temp_17_2, temp_16_3) < 0.25f) {
                        if (pv->i[0x32C/4] != 0) {
                            func_003C3A10(pv->p[0x2DC/4], 9, 0, 8);
                            var_5 = 0x1B;
                            goto block_188;
                        }
                        func_L10_003B9078(m, 0xE, 0, 8);
                        func_L01_004450F0(m, 8, -1);
                        pv->i[0x334/4] = 0;
                    }
                    break;
                case 16:                            /* switch 2 */
                    temp_16_4 = m->b + 0x10;
                    temp_17_3 = D_L10_0021D1C0[pv->i[0x310/4]];
                    func_L01_00448340(temp_16_4, (u8 *)temp_17_3 + ((pv->i[0x334/4] * 0x10) + 0x10), pv->b + 0x2E8, 0.0032000002f, 0.014400001f, 0.080000006f);
                    if (func_0038CF00(temp_16_4, (u8 *)temp_17_3 + ((pv->i[0x334/4] * 0x10) + 0x10)) < 0.25f) {
                        temp_2_3 = pv->i[0x334/4] + 1;
                        pv->i[0x334/4] = temp_2_3;
                        if (temp_2_3 >= *temp_17_3) {
                            if (pv->i[0x32C/4] != 0) {
                                func_003C3A10(pv->p[0x2DC/4], 9, 0, 8);
                                func_L01_004450F0(m, 0x1B, -1);
                            } else {
                                func_L10_003B9078(m, 0xE, 0, 8);
                                func_L01_004450F0(m, 8, -1);
                                pv->i[0x334/4] = 0;
                            }
                        }
                    }
                    if (((u16) m->uh[0x96/2] >= 0x5BU) && (func_L10_003B9D28(m) != 0) && (((G *)(pv->p[0x2DC/4]))->b[0x42] == 9)) {
                        var_5_3 = 0x14;
block_108:
                        func_L01_004450F0(m, var_5_3, -1);
                        func_003C3A10(pv->p[0x2DC/4], 0xA, 0, 3);
                    }
                    break;
                case 20:                            /* switch 2 */
                    temp_16_5 = m->b + 0x10;
                    temp_17_4 = D_L10_0021D1C0[pv->i[0x310/4]];
                    var_21_2 = temp_16_5;
                    func_L01_00448340(temp_16_5, (u8 *)temp_17_4 + ((pv->i[0x334/4] * 0x10) + 0x10), pv->b + 0x2E8, 0.0032000002f, 0.014400001f, 0.080000006f);
                    if (func_0038CF00(temp_16_5, (u8 *)temp_17_4 + ((pv->i[0x334/4] * 0x10) + 0x10)) < 0.25f) {
                        pv->i[0x334/4] = (pv->i[0x334/4] + 1);
                        temp_3_3 = *temp_17_4;
                        if ((pv->i[0x334/4] + 1) >= temp_3_3) {
                            pv->i[0x334/4] = (s32) (temp_3_3 - 1);
                        }
                    }
                    if (func_L01_0044E1B8(pv->p[0x2DC/4], 0.5f) != 0) {
                        temp_4_4 = pv->p[0x2DC/4];
                        if (((G *)temp_4_4)->b[0x42] == 0xA) {
                            func_003C2F58(temp_4_4, 0, &sp90);
                            if (!(fabs_asm(m->f[0x18/4] - pv->f[0x228/4]) < 2.0f)) {
block_116:
                                func_0038CF68(&spA0, pv->p[0x2DC/4] + 0xC0, (func_0038CF38(var_21_2, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                            } else {
block_115:
                                func_0038CF68(&spA0, pv->p[0x2DC/4] + 0xC0, (func_0038CF38(var_21_2, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                            }
block_117:
                            spA0.f[2] = func_L01_00447878(&sp90, pv->b + 0x220, 0, func_0038CF38(var_21_2, ((G *)pv->p[0x230/4])->b + 0x10) * 0.020000001f, 0xBB902DE0);
                            func_L05_0032B880(&sp90, &spA0, m, 5.0f);
                        }
                    }
block_118:
                    if (((G *)(pv->p[0x2DC/4]))->b[0x60] & 2) {
                        func_L01_004450F0(m, 0x10, 2);
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 5);
                    }
                    break;
                case 24:                            /* switch 2 */
                    pv->i[0xA8/4] = (s32) (pv->i[0xA8/4] | 4);
                    temp_16_6 = D_L10_0021D1C0[pv->i[0x314/4]];
                    temp_6 = (u8 *)temp_16_6 + (pv->i[0x334/4] * 0x10);
                    func_L01_004482A0(m->b + 0x18, pv->b + 0x2E8, temp_6, ((G *)temp_6)->f[0x18/4], 0.0032000002f, 0.014400001f, 0.080000006f);
                    if (func_L01_0045BDE8(m, pv->i[0x314/4]) != 0) {
                        temp_2_5 = pv->i[0x334/4] + 1;
                        pv->i[0x334/4] = temp_2_5;
                        if (temp_2_5 >= *temp_16_6) {
                            func_003C3A10(pv->p[0x2DC/4], 9, 0, 8);
                            var_5 = 0x1B;
                            goto block_188;
                        }
                    }
                    break;
                case 25:                            /* switch 2 */
                    temp_6_2 = pv->i[0x334/4] * 0x10;
                    func_L01_004482A0(m->b + 0x18, pv->b + 0x2E8, (void *) temp_6_2, ((G *)(((u8 *)D_L10_0021D1C0[pv->i[0x314/4]] + temp_6_2)))->f[0x18/4], 0.0032000002f, 0.014400001f, 0.080000006f);
                    pv->i[0xA8/4] = (s32) (pv->i[0xA8/4] | 4);
                    temp_16_7 = m->b + 0x10;
                    if (func_L01_0045BDE8(m, pv->i[0x314/4]) != 0) {
                        temp_17_5 = D_L10_0021D1C0[pv->i[0x314/4]];
                        temp_f20 = func_0038CF38(temp_16_7, (u8 *)temp_17_5 + 0x10);
                        if (func_0038CF38(temp_16_7, (u8 *)temp_17_5 + (*temp_17_5 * 0x10)) < temp_f20) {
                            func_L01_0045C150(m, D_L10_0021D1C0[pv->i[0x314/4]], 0, *temp_17_5 - 1);
                        } else {
                            func_L01_0045C150(m, D_L10_0021D1C0[pv->i[0x314/4]], *temp_17_5 - 1, 0);
                        }
                    }
                    if (((u16) m->uh[0x96/2] >= 0x5BU) && (func_L10_003B9D28(m) != 0)) {
                        var_5_3 = 0x1A;
                        goto block_108;
                    }
                    break;
                case 26:                            /* switch 2 */
                    pv->i[0xA8/4] = (s32) (pv->i[0xA8/4] | 4);
                    temp_17_6 = D_L10_0021D1C0[pv->i[0x314/4]];
                    temp_16_8 = m->b + 0x10;
                    var_21_2 = temp_16_8;
                    func_L01_00448340(temp_16_8, (u8 *)temp_17_6 + ((pv->i[0x334/4] * 0x10) + 0x10), pv->b + 0x2E8, 0.0032000002f, 0.014400001f, 0.080000006f);
                    if (func_0038CF00(temp_16_8, (u8 *)temp_17_6 + ((pv->i[0x334/4] * 0x10) + 0x10)) < 0.25f) {
                        temp_2_6 = pv->i[0x334/4] + 1;
                        pv->i[0x334/4] = temp_2_6;
                        temp_5 = *temp_17_6;
                        if (temp_2_6 >= temp_5) {
                            pv->i[0x334/4] = (s32) (temp_5 - 1);
                        }
                    }
                    if (func_L01_0044E1B8(pv->p[0x2DC/4], 0.5f) != 0) {
                        temp_4_5 = pv->p[0x2DC/4];
                        if (((G *)temp_4_5)->b[0x42] == 0xA) {
                            func_003C2F58(temp_4_5, 0, &sp90);
                            if (fabs_asm(m->f[0x18/4] - pv->f[0x228/4]) < 2.0f) {
                                goto block_115;
                            }
                            goto block_116;
                            goto block_117;
                        }
                    }
                    goto block_118;
                case 3:                             /* switch 2 */
                    if (m->b[0x60] & 2) {
                        pv->i[0x338/4] = 1;
                        if (pv->i[0x314/4] != -1) {
                            func_L01_004450F0(m, 0x18, -1);
                            func_L10_003B9078(m, 0xD, 0, 5);
                            pv->i[0x334/4] = 1;
                        }
                    }
                    break;
                case 8:                             /* switch 2 */
                    if (func_L01_0044E1B8(m, 8.0f) != 0) {
                        pv->i[0x338/4] = 0;
                        func_L01_004450F0(m, 0x1B, -1);
                        func_L10_003B9078(m, 9, 0, 8);
                    }
                    if (func_L01_004395E0(m) > 4.0f) {
                        temp_f0 = func_003C3D30((m->b + 0x10), 0, 0, 0.5f);
                        sp90.q = m->q[0x10/16];
                        sp90.f[2] = temp_f0;
                        func_L01_00448340((m->b + 0x10), &sp90, pv->b + 0x2E8, 0.0072000003f, 0.010400001f, 0.28000003f);
                    }
                    break;
                case 13:                            /* switch 2 */
                    func_L01_00448728(pv->p[0x2DC/4] + 0xF8, pv->b + 0x330, 0, m->f[0xF8/4], 0.0030717796f, 0.0008377581f, 0.15358898f);
                    if (func_L01_004561B8(m) != 0) {
                        pv->i[0x2D8/4] = 0;
                    }
                    temp_17_7 = m->b + 0x10;
                    temp_16_10 = (u8 *)D_L10_0021D1C0[pv->i[0x314/4]] + 0x10;
                    func_L01_0045A748(m, temp_16_10);
                    if (func_0038CF38(temp_17_7, temp_16_10) < 0.5f) {
                        func_L10_003B9078(m, 9, 0, 8);
                        func_L01_004450F0(m, 0x1B, 2);
                    }
                    if ((func_0038CF38(temp_17_7, ((G *)pv->p[0x230/4])->b + 0x10) < 10.0f) && ((u16) m->uh[0x96/2] >= 5U)) {
                        goto block_158;
                    }
                    break;
                case 15:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        pv->i[0x2D8/4] = 0;
                    }
                    temp_17_8 = m->b + 0x10;
                    temp_16_11 = pv->p[0x2DC/4] + 0xF8;
                    func_L01_00448728(temp_16_11, pv->b + 0x330, 0, func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]), 0.0030717796f, 0.0008377581f, 0.15358898f);
                    func_L01_0045A748(m, ((u8 *)D_L10_0021D1C0[pv->i[0x314/4]] + 0x10));
                    if (func_0038CF38(temp_17_8, ((u8 *)D_L10_0021D1C0[pv->i[0x314/4]] + 0x10)) < 0.5f) {
                        func_L10_003B9078(m, 9, 0, 8);
                        func_L01_004450F0(m, 0x1B, 2);
                    }
                    if (func_0038CF38(temp_17_8, ((G *)pv->p[0x230/4])->b + 0x10) < 8.0f) {
                        if ((u16) m->uh[0x96/2] >= 5U) {
                            func_L10_003B9078(m, 9, 0, 8);
                            func_L01_004450F0(m, 0x1B, 2);
                        }
                    }
                    if ((m->uh[0x96/2] >= 0x5BU) && (func_L10_003B9D28(m) != 0)) {
                        func_003C3A10(pv->p[0x2DC/4], 0xA, 0, 5);
                        var_5 = 0x12;
                        goto block_188;
                    }
                    break;
                case 18:                            /* switch 2 */
                    temp_16_13 = pv->p[0x2DC/4] + 0xF8;
                    func_L01_00448728(temp_16_13, pv->b + 0x330, 0, func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]), 0.0030717796f, 0.0008377581f, 0.15358898f);
                    if (((G *)(pv->p[0x2DC/4]))->b[0x60] & 2) {
                        func_L01_004450F0(m, 0xF, 2);
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 5);
                    }
                    temp_17_9 = m->b + 0x10;
                    var_21 = temp_17_9;
                    temp_16_14 = (u8 *)D_L10_0021D1C0[pv->i[0x314/4]] + 0x10;
                    func_L01_0045A748(m, temp_16_14);
                    if ((func_0038CF38(temp_17_9, temp_16_14) < 0.5f) && (m->b[0x43] != 9)) {
                        func_003C3A10(m, 9, 0, 8);
                    }
                    if (func_L01_0044E1B8(pv->p[0x2DC/4], 0.5f) != 0) {
                        temp_4_6 = pv->p[0x2DC/4];
                        if (((G *)temp_4_6)->b[0x42] == 0xA) {
                            func_003C2F58(temp_4_6, 0, &sp90);
                            if (fabs_asm(m->f[0x18/4] - pv->f[0x228/4]) < 2.0f) {
                                var_16 = pv->p[0x2DC/4] + 0xC0;
                                var_f0_2 = func_0038CF38(var_21, ((G *)pv->p[0x230/4])->b + 0x10);
                                goto block_175;
                            }
                            temp_16_15 = pv->p[0x2DC/4] + 0xC0;
                            var_f0 = func_0038CF38(var_21, ((G *)pv->p[0x230/4])->b + 0x10);
                            var_5_2 = temp_16_15;
                            goto block_177;
                            goto block_178;
                        }
                    }
                    break;
                case 21:                            /* switch 2 */
                    func_L01_00448728(pv->p[0x2DC/4] + 0xF8, pv->b + 0x330, 0, m->f[0xF8/4], 0.0030717796f, 0.0008377581f, 0.15358898f);
                    if (func_L01_004561B8(m) != 0) {
                        pv->i[0x2D8/4] = 0;
                    }
                    func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10);
                    if (func_L01_0045BDE8(m, pv->i[0x314/4]) != 0) {
                        goto block_158;
                    }
                    break;
                case 22:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        pv->i[0x2D8/4] = 0;
                    }
                    temp_16_16 = pv->p[0x2DC/4] + 0xF8;
                    func_L01_00448728(temp_16_16, pv->b + 0x330, 0, func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]), 0.0030717796f, 0.0008377581f, 0.15358898f);
                    if (func_L01_0045BDE8(m, pv->i[0x314/4]) != 0) {
                        func_L10_003B9078(m, 9, 0, 8);
                        func_L01_004450F0(m, 0x1B, 2);
                    }
                    if (((u16) m->uh[0x96/2] >= 0x5BU) && (func_L10_003B9D28(m) != 0)) {
                        func_003C3A10(pv->p[0x2DC/4], 0xA, 0, 5);
                        var_5 = 0x17;
                        goto block_188;
                    }
                    break;
                case 23:                            /* switch 2 */
                    temp_16_17 = pv->p[0x2DC/4] + 0xF8;
                    func_L01_00448728(temp_16_17, pv->b + 0x330, 0, func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]), 0.0030717796f, 0.0008377581f, 0.15358898f);
                    if (((G *)(pv->p[0x2DC/4]))->b[0x60] & 2) {
                        func_L01_004450F0(m, 0x16, 2);
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 5);
                    }
                    if ((func_L01_0045BDE8(m, pv->i[0x314/4]) != 0) && (m->b[0x43] != 9)) {
                        func_003C3A10(m, 9, 0, 8);
                    }
                    if (func_L01_0044E1B8(pv->p[0x2DC/4], 0.5f) != 0) {
                        temp_4_7 = pv->p[0x2DC/4];
                        if (((G *)temp_4_7)->b[0x42] == 0xA) {
                            func_003C2F58(temp_4_7, 0, &sp90);
                            if (fabs_asm(m->f[0x18/4] - pv->f[0x228/4]) < 2.0f) {
                                goto block_174;
                            }
                            goto block_176;
                            goto block_178;
                        }
                    }
                    break;
                case 27:                            /* switch 2 */
                    temp_16_18 = pv->p[0x2DC/4] + 0xF8;
                    func_L01_00448728(temp_16_18, pv->b + 0x330, 0, func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]), 0.0050265486f, 0.0050265486f, 0.25132743f);
                    if (((u16) m->uh[0x96/2] >= 0x5BU) && (func_L10_003B9D28(m) != 0)) {
                        if (m->b[0x42] == 0xD) {
                            func_003C3A10(pv->p[0x2DC/4], 0xA, 0, 8);
                        } else {
block_186:
                            func_L10_003B9078(m, 0xA, 0, 8);
                        }
                        var_5 = 0xA;
                        goto block_188;
                    }
                    break;
                case 9:                             /* switch 2 */
                    func_L10_003B9078(m, 6, 0, 8);
                    func_L01_00448728(pv->p[0x2DC/4] + 0xF8, pv->b + 0x330, 0, m->f[0xF8/4], 0.0030717796f, 0.0008377581f, 0.15358898f);
                    func_L01_0045A748(m, pv->b + 0x220);
                    if (((func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) < 14.0f) || (fabs_asm(m->f[0x18/4] - pv->f[0x228/4]) > 3.0f)) && (func_0038DBA0(m->f[0xF8/4], func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.5235988f)) {
                        goto block_186;
                    }
                    break;
                case 10:                            /* switch 2 */
                    temp_16_19 = pv->p[0x2DC/4] + 0xF8;
                    func_L01_00448728(temp_16_19, pv->b + 0x330, 0, func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]), 0.0050265486f, 0.0050265486f, 0.25132743f);
                    if (func_L01_0044E1B8(pv->p[0x2DC/4], 5.0f) != 0) {
                        func_003C2F58(pv->p[0x2DC/4], 0, &sp90);
                        if (fabs_asm(m->f[0x18/4] - pv->f[0x228/4]) < 2.0f) {
                            temp_16_20 = pv->p[0x2DC/4] + 0xC0;
                            var_21_3 = (m->b + 0x10);
                            func_0038CF68(&spA0, temp_16_20, (func_0038CF38((m->b + 0x10), ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                        } else {
                            temp_17_10 = m->b + 0x10;
                            temp_16_21 = pv->p[0x2DC/4] + 0xC0;
                            var_21_3 = temp_17_10;
                            func_0038CF68(&spA0, temp_16_21, (func_0038CF38(temp_17_10, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                        }
                        spA0.f[2] = func_L01_00447878(&sp90, pv->b + 0x220, 0, func_0038CF38(var_21_3, ((G *)pv->p[0x230/4])->b + 0x10) * 0.020000001f, 0xBB902DE0);
                        func_L05_0032B880(&sp90, &spA0, m, 5.0f);
                    }
                    temp_4_8 = pv->p[0x2DC/4];
                    if (((G *)temp_4_8)->b[0x60] & 2) {
                        if (pv->i[0x32C/4] == 0) {
                            func_L10_003B9078(m, 9, 0, 8);
                            func_L01_004450F0(m, 0x1B, 2);
                        } else {
                            func_003C3A10(temp_4_8, 9, 0, 8);
                            func_L01_004450F0(m, 0x1B, 2);
                        }
                        if (pv->i[0x314/4] != -1) {
                            temp_16_22 = m->b + 0x10;
                            func_L01_004450F0(m, 0x15, -1);
                            func_L10_003B9078(m, 6, 0, 8);
                            temp_17_11 = D_L10_0021D1C0[pv->i[0x314/4]];
                            temp_f20_2 = func_0038CF38(temp_16_22, (u8 *)temp_17_11 + 0x10);
                            if (func_0038CF38(temp_16_22, (u8 *)temp_17_11 + (*temp_17_11 * 0x10)) < temp_f20_2) {
                                func_L01_0045C150(m, D_L10_0021D1C0[pv->i[0x314/4]], 0, *temp_17_11 - 1);
                            } else {
                                func_L01_0045C150(m, D_L10_0021D1C0[pv->i[0x314/4]], *temp_17_11 - 1, 0);
                            }
                            if (pv->i[0x324/4] != 0) {
                                func_003C3A10(pv->p[0x2DC/4], 9, 0, 8);
                                func_L01_004450F0(m, 0x16, -1);
                            }
                            if (pv->i[0x32C/4] != 0) {
                                if (pv->i[0x338/4] == 0) {
                                    func_L01_004450F0(m, 3, -1);
                                    var_5_4 = 0xC;
                                } else {
                                    func_L01_004450F0(m, 0x18, -1);
                                    var_5_4 = 0xD;
                                }
                                func_L10_003B9078(m, var_5_4, 0, 5);
                                pv->i[0x334/4] = 1;
                            }
                        }
                    }
                    break;
                case 30:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        pv->f[0x1BC/4] = 2.0f;
                        pv->f[0x1B8/4] = 2.0f;
                    }
                    temp_f1 = pv->f[0x2F8/4];
                    if (temp_f1 < 1.0f) {
                        temp_f0_2 = temp_f1 + D_L10_001DE75C;
                        pv->f[0x2F8/4] = temp_f0_2;
                        if (temp_f0_2 > 1.0f) {
                            pv->f[0x2F8/4] = 1.0f;
                        }
                        m->f[0x2C/4] = (f32) (((G *)(m->p[0x24/4]))->f[0x24/4] * pv->f[0x2F8/4]);
                        temp_3_4 = pv->p[0x2DC/4];
                        ((G *)temp_3_4)->f[0x2C/4] = (f32) (((G *)(((G *)temp_3_4)->p[0x24/4]))->f[0x24/4] * pv->f[0x2F8/4]);
                    }
                    temp_2_8 = pv->p[0x2F4/4];
                    if (temp_2_8 != 0) {
                        ((G *)temp_2_8)->i[0x98/4] = 0;
                    }
                    if (func_L01_0045C2A0(m, D_L10_001DE764, D_L10_001DE768, D_L10_001DE76C) != 0) {
                        m->f[0x48/4] = 1.0f;
                        ((G *)(pv->p[0x2DC/4]))->f[0x48/4] = 1.0f;
                        func_L01_0045A9F0(m);
                        pv->f[0x1BC/4] = 0.75f;
                        pv->f[0x1B8/4] = 0.2f;
                        if (pv->i[0x2F0/4] != 0) {
                            func_L01_004450F0(m, 0x1F, 5);
                            var_5_5 = 4;
                        } else {
                            func_L01_004450F0(m, 1, 0);
                            var_5_5 = 0;
                        }
                        func_L10_003B9078(m, var_5_5, 0, 8);
                    } else {
                        temp_2_9 = pv->p[0x2DC/4];
                        if (temp_2_9 != 0) {
                            ((G *)temp_2_9)->f[0x48/4] = (f32) m->f[0x48/4];
                        }
                    }
                    temp_4_9 = pv->p[0x2F4/4];
                    if (temp_4_9 != 0) {
                        ((G *)temp_4_9)->i[0x98/4] = (s32) ((G *)(((G *)temp_4_9)->p[0x24/4]))->i[0x10/4];
                    }
                    break;
                case 31:                            /* switch 2 */
                    var_2 = m->b + 0x10;
                    if (func_L01_004561B8(m) != 0) {
                        func_L01_0045BD78(m, 0.0064000003f, 0.060000002f, 0.010053097f, 0.25132743f);
                        var_2 = m->b + 0x10;
                    }
                    if (func_0038CF38(var_2, (pv->b + 0x300)) > 0.5f) {
                        func_L01_0045A748(m, (pv->b + 0x300));
                    } else {
                        func_L01_0045A898(m, (pv->b + 0x300), pv->f[0x2FC/4]);
                    }
                    if (pv->h[0x234/2] == 1) {
                        func_L01_0045BD78(m, 0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f);
                        func_L01_004450F0(m, 2, 1);
                        func_L10_003B9078(m, 0, 0, 8);
                        pv->i[0x2D0/4] = (s32) ((s32) ((func_00382498(0x244, 0x258) * 5) + 2) / 6);
                    } else if (func_0038CF38(var_2, (pv->b + 0x300)) <= pv->f[0xA4/4]) {
                        if (pv->f[0xA0/4] < fabs_asm(func_0038DBA0(m->f[0xF8/4], pv->f[0x2FC/4]))) {
                            func_L01_0045BD10(m, pv->f[0x2FC/4]);
                        } else {
                            func_L01_0045BD78(m, 0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f);
                            func_L01_004450F0(m, 1, 0);
                            func_L10_003B9078(m, 0, 0, 8);
                        }
                    }
                    break;
                }
            func_L10_003B8F50(m);
}
