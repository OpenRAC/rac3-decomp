/* func_L24_00352060: the Insomniac Museum enemy's per-frame update (level 24 only): a switch on its
   mode (m+0x95: 0-4) and a 26-way switch on its state (m+0x20, cases 1-26) through jtbl_002BCCA0,
   then a shared tail (stuck test on the start-of-frame position, the fall-out-of-world burst,
   func_L24_003552F8). Same family of AI as func_L06_0034A7A8 (the same callees and helpers).
   Written from retail (Opus, 2026-11-08): m2c with both jump tables (the kit's m2cjt3.py misses
   jtbl_002BCCA0, whose first target is a .word VU0 line without an address; fixed in a copy),
   converted to the Mo/Pv/G union style, VU0 ops through include/vu0.h, then every m2c goto
   written out as straight code.
   Near miss: 2617 instructions, the same as retail; 2605 lines (99.5 percent) and 2610 opcodes
   (99.7 percent) equal (kit cd.py); the stock checker reports 65 diff.
   Needs on src/levels/24_insomniac_museum/L24_003519E8.c: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as" (VU0 helpers; float constants built inline), include/vu0.h.
   What mattered:
   - no gotos: the mode switch by hand (m2c folded modes 1-4 after the state switch), the shared
     "attack or approach" and animation-change tails written per state (the compiler cross-jumps
     them as retail does); state 13's target test with the dead/absent case first;
   - per-case locals for the animation time (states 20, 21, 24), the record chosen with
     "t < 17 ? pv->i[0x324/4] : pv->i[0x328/4]" from an array of 0x80-byte records
     (D_L24_001DF600); m2c's address temps inlined;
   - calls before constants in comparisons (state 18: "CF38(...) > D" and "DBA0(...) > D * deg");
   - fe_func_003C41A0 is (p, f32, p, f32, f32, f32), func_L01_004468C8 s32 (m, s32, f32, f32, s32,
     f32, s32, s32, s32) as in func_L06_0034A7A8, func_L01_0045AA10 returns s32;
   - the mode-3/4 test as nested ifs (one && chain folds into a range test); func_003D5630 called
     without arguments both times (retail passes $a0 through); D_L24_001E8F58 is .data;
   - the $gp floats D_L24_001DD518..001DD568 (the enemy's tunables) are scalars with .extern size
     hints; D_L24_001DF0C0 is read as a word (state 6) and as its low byte (state 13);
   - the timer values are (rand * 5 + 2) / 6.
   Left (17 rows):
   - state 13, the 0x1663 branch's 8/9 animation choice: retail cross-jumps both of its tails into
     the next branch's (falls through to the 8 test); here only the 9 tail is shared;
   - state 18: the m+0x60 flag test in v1 (here v0);
   - the fall-out burst: retail hoists m+0x18 (the loop's 0046A938 argument) above the 003016B0 call;
   - m2c's remaining names (temp_*, var_*) and the tunables' honest declarations. */
typedef int u128_t __attribute__((mode(TI)));
typedef union Mo_ { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; long d[0x20]; u128_t q[0x10]; } Mo;
typedef union Pv_ { u8 b[0x1000]; s8 c[0x1000]; s16 h[0x800]; u16 uh[0x800]; s32 i[0x400]; u32 u[0x400]; f32 f[0x400]; void *p[0x400]; long d[0x200]; u128_t q[0x100]; } Pv;
typedef union G_ { u8 b[0x4000]; s8 c[0x4000]; s16 h[0x2000]; u16 uh[0x2000]; s32 i[0x1000]; u32 u[0x1000]; f32 f[0x1000]; void *p[0x1000]; long d[0x800]; u128_t q[0x400]; } G;
typedef union { f32 f[4]; s32 i[4]; s8 c[16]; u8 b[16]; s16 h[8]; u16 uh[8]; u128_t q; } __attribute__((aligned(16))) U16;
extern s32 D_L24_001DF0C0;
extern u8 *D_L24_001DF51C;
typedef struct { u8 pad0[0x80]; } E80;
extern E80 *D_L24_001DF600;
extern G *D_L24_001E8F58 __attribute__((section(".data")));
extern void *D_L24_0021D600[];
extern f32 D_L24_001DD518;
__asm__(".extern D_L24_001DD518, 4");
extern f32 D_L24_001DD51C;
__asm__(".extern D_L24_001DD51C, 4");
extern f32 D_L24_001DD520;
__asm__(".extern D_L24_001DD520, 4");
extern f32 D_L24_001DD524;
__asm__(".extern D_L24_001DD524, 4");
extern f32 D_L24_001DD528;
__asm__(".extern D_L24_001DD528, 4");
extern f32 D_L24_001DD52C;
__asm__(".extern D_L24_001DD52C, 4");
extern f32 D_L24_001DD530;
__asm__(".extern D_L24_001DD530, 4");
extern f32 D_L24_001DD534;
__asm__(".extern D_L24_001DD534, 4");
extern f32 D_L24_001DD538;
__asm__(".extern D_L24_001DD538, 4");
extern f32 D_L24_001DD53C;
__asm__(".extern D_L24_001DD53C, 4");
extern f32 D_L24_001DD540;
__asm__(".extern D_L24_001DD540, 4");
extern f32 D_L24_001DD544;
__asm__(".extern D_L24_001DD544, 4");
extern f32 D_L24_001DD550;
__asm__(".extern D_L24_001DD550, 4");
extern f32 D_L24_001DD554;
__asm__(".extern D_L24_001DD554, 4");
extern f32 D_L24_001DD558;
__asm__(".extern D_L24_001DD558, 4");
extern f32 D_L24_001DD55C;
__asm__(".extern D_L24_001DD55C, 4");
extern f32 D_L24_001DD560;
__asm__(".extern D_L24_001DD560, 4");
extern f32 D_L24_001DD564;
__asm__(".extern D_L24_001DD564, 4");
extern f32 D_L24_001DD568;
__asm__(".extern D_L24_001DD568, 4");
extern f32 *func_00382348(void *);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C2880(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_003C4138(void *, f32, f32);
extern void func_003C41A0(void *, f32, void *, f32, f32, f32);
extern s32 func_003D5630();
extern void func_L01_003016B0(void *, s32, f32, f32);
extern void func_L01_00315900(void *, s32, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern f32 func_L01_004395E0(void *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004468C8(void *, s32, f32, f32, s32, f32, s32, s32, s32);
extern f32 func_L01_00447878(void *, void *, s32, f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_L01_004513A8(void *, s32, s32);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004561E0(void *);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00458F78(void *, void *, s32, s32);
extern void func_L01_00459188(void *, void *, void *);
extern void func_L01_0045A748(void *, void *);
extern void func_L01_0045A7A8(void *, void *, f32);
extern void func_L01_0045A9F0(void *);
extern s32 func_L01_0045AA10(void *, f32);
extern s32 func_L01_0045AA30(void *, void *);
extern s32 func_L01_0045BD10(void *, f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0045BE38(void *, void *);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L01_00468A68(void *, void *, s32, s32);
extern void func_L01_0046A938(void *, void *, s32, f32, f32);
extern void func_L02_003516A8(void *);
extern void func_L24_0034E250(void *, void *, void *, void *, s32, f32, f32);
extern s32 func_L24_00351FD8(void *);
extern s32 func_L24_00354948(void);
extern void func_L24_003552F8(void *);
extern s32 func_L24_003554A8();
extern s32 func_L24_003556A8(void *);
#include "vu0.h"
void func_L24_00352060(Mo *m) {
    U16 sp00;
    U16 sp10;
    U16 sp20;
    U16 sp30;
    U16 sp40;
    s32 var_4;
    s32 var_5;
    s32 var_5_2;
    s32 var_5_3;
    s32 var_5_4;
    s32 var_5_5;
    s32 var_5_6;
    s32 var_5_7;
    s32 var_5_9;
    s32 var_f13;
    s32 var_f14;
    s32 var_f15;
    f32 *temp_4_8;
    f32 temp_4_2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f21;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f12;
    f32 var_f20;
    s32 *temp_18;
    s32 temp_16_9;
    s32 temp_2_7;
    s32 temp_4_3;
    s32 var_16_2;
    s32 var_18;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_condition_bit;
    u16 temp_3_3;
    u16 temp_3_4;
    u32 var_3;
    u8 temp_3;
    u8 temp_3_2;
    u8 temp_3_5;
    u8 temp_3_6;
    u8 temp_3_7;
    u8 temp_3_8;
    u8 temp_4;
    void *temp_16;
    void *temp_16_2;
    void *temp_16_3;
    void *temp_16_4;
    void *temp_16_5;
    void *temp_16_6;
    void *temp_16_7;
    void *temp_16_8;
    void *temp_18_2;
    Pv *pv;
    void *temp_2;
    void *temp_2_2;
    void *temp_2_3;
    void *temp_2_4;
    void *temp_2_5;
    void *temp_2_6;
    void *temp_4_4;
    void *temp_4_5;
    void *temp_4_6;
    void *temp_4_7;
    void *temp_5;
    void *temp_5_2;
    void *temp_5_3;
    void *temp_5_4;
    void *temp_5_5;
    void *temp_5_6;
    void *temp_6;
    void *var_5_8;

    pv = m->p[0x68/4];
    if (func_L24_00354948() != 0) {
        return;
    }
    sp00.q = m->q[0x10/16];
    switch (m->b[0x95]) {
    case 0:
        if ((func_L01_004561E0(m) != 0) && (pv->h[0x2D6/2] == 0)) {
            pv->h[0x2D6/2] = (func_00382498(0, 0x28) * 5 + 2) / 6;
        }
        if ((pv->h[0x234/2] == 1) && (func_0038CB00(pv->b + 0x2D6) != 0)) {
            pv->f[0xA0/4] = 0.06981317f;
            func_L01_004450F0(m, 0xD, 2);
            if (m->b[0x43] != 6) {
                func_003C3A10(m, 6, 0, 8);
            }
            if (pv->i[0x2E4/4] != 0) {
                func_L01_004450F0(m, 0x14, 2);
                if (m->b[0x43] != 3) {
                    func_003C3A10(m, 3, 0, 8);
                }
                if (pv->i[0x2E4/4] == 2) {
                    func_L01_004450F0(m, 0x15, -1);
                }
            }
            if (pv->i[0x32C/4] != -1) {
                func_L01_004450F0(m, 8, -1);
                if (m->b[0x43] != 7) {
                    func_003C3A10(m, 7, 0, 5);
                }
            }
        } else if ((pv->i[0x2D8/4] != 0) && (func_0038CB00(pv->b + 0x2D6) != 0) && (pv->i[0x2E4/4] == 0)) {
            m->b[0x95] = 1;
            m->b[0xBE] &= 0xFD;
            pv->i[0x2D8/4] = 0;
            if (pv->i[0x2D0/4] < 0xFA) {
                pv->i[0x2D0/4] = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    case 1:
        if (pv->h[0x234/2] == 1) {
            pv->f[0xA0/4] = 0.06981317f;
            func_L01_004450F0(m, 0xD, 2);
            if (m->b[0x43] != 6) {
                func_003C3A10(m, 6, 0, 8);
            }
        }
        break;
    case 2:
        if ((pv->h[0x234/2] != 1) && (m->b[0x20] != 0x14) && (m->b[0x20] != 0xE) && (m->b[0x20] != 0x10)) {
            if (m->b[0x43] != 7) {
                func_003C3A10(m, 7, 0, 8);
            }
            func_L01_004450F0(m, 9, 1);
            pv->q[0x340/16] = pv->q[0x220/16];
            pv->i[0x2D0/4] = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
        }
        break;
    case 3:
        {
            s32 r;
            pv->c[0x1A9] = 1;
            r = func_L01_00454370(m, pv->b + 0x160);
            if (r & 1) {
                func_L02_003516A8(m);
                func_L01_00315900(m, 0, 0);
                return;
            }
            if (r & 2) {
                if (pv->h[0x234/2] == 1) {
                    if (func_L24_003554A8(m) != 0) {
                        func_L01_004450F0(m, 0xD, 2);
                        if (m->b[0x43] != 6) {
                            func_003C3A10(m, 6, 0, 8);
                        }
                    } else {
                        func_L01_004450F0(m, 0xC, 2);
                        if (m->b[0x43] != 7) {
                            func_003C3A10(m, 7, 0, 8);
                        }
                    }
                } else {
                    if (m->b[0x43] != 7) {
                        func_003C3A10(m, 7, 0, 8);
                    }
                    func_L01_004450F0(m, 9, 1);
                    pv->q[0x340/16] = pv->q[0x220/16];
                    pv->i[0x2D0/4] = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
                }
            }
        }
        break;
    case 4:
        m->f[0x18/4] -= 0.24000001f;
        break;
    }
                switch (m->b[0x20]) {                    /* switch 2 */
                case 1:
                case 26:
                    break;
                case 2:                             /* switch 2 */
                    pv->f[0xA0/4] = 0.61086524f;
                    func_L01_0045BD78(m, D_L24_001DD52C * 0.00040000002f, D_L24_001DD528 * 0.020000001f, D_L24_001DD534 * 0.017453292f * 0.00040000002f, D_L24_001DD530 * 0.017453292f * 0.020000001f);
                    if (func_L01_0045BE38(m, D_L24_0021D600[pv->i[0x2F4/4]]) != 0) {
                        func_L01_004450F0(m, 4, -1);
                        if (m->b[0x43] != 2) {
                            func_003C3A10(m, 2, 0, 0x11);
                        }
                    }
                    break;
                case 4:                             /* switch 2 */
                    if (m->b[0x60] & 2) {
                        temp_4_3 = pv->i[0x2F4/4];
                        if (temp_4_3 != -1) {
                            temp_16 = m->b + 0x10;
                            temp_18 = D_L24_0021D600[temp_4_3];
                            temp_f20 = func_0038CF38(temp_16, (u8 *)temp_18 + 0x10);
                            if (func_0038CF38(temp_16, (u8 *)temp_18 + (*temp_18 * 0x10)) < temp_f20) {
                                func_L01_0045C150(m, D_L24_0021D600[pv->i[0x2F4/4]], 0, *temp_18 - 1);
                            } else {
                                func_L01_0045C150(m, D_L24_0021D600[pv->i[0x2F4/4]], *temp_18 - 1, 0);
                            }
                            func_L01_004450F0(m, 2, -1);
                            if (m->b[0x43] != 4) {
                                func_003C3A10(m, 4, 0, 0x11);
                            }
                        } else {
                            func_L01_004450F0(m, 6, -1);
                            if (m->b[0x43] != 4) {
                                func_003C3A10(m, 4, 0, 0x11);
                            }
                        }
                    }
                    func_L01_0045AA10(m, m->f[0xF8/4]);
                    break;
                case 6:                             /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        func_L01_0045BD78(m, D_L24_001DD52C * 0.00040000002f, D_L24_001DD528 * 0.020000001f, D_L24_001DD534 * 0.017453292f * 0.00040000002f, D_L24_001DD530 * 0.017453292f * 0.020000001f);
                        func_L01_00443B88(&sp10, 4.0f, 6.0f);
                        vec_add_ab(pv->b + 0x300, &sp10, m->b + 0x10);
                    }
                    temp_16_2 = pv->b + 0x300;
                    func_L01_0045A748(m, temp_16_2);
                    if (func_0038CF38(m->b + 0x10, temp_16_2) < 2.0f) {
                        func_L01_004450F0(m, 4, -1);
                        if (m->b[0x43] != 2) {
                            func_003C3A10(m, 2, 0, 0x11);
                        }
                    }
                    break;
                case 9:                             /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        func_L01_0045BD78(m, D_L24_001DD51C * 0.00040000002f, D_L24_001DD518 * 0.020000001f, D_L24_001DD524 * 0.017453292f * 0.00040000002f, D_L24_001DD520 * 0.017453292f * 0.020000001f);
                    }
                    func_L01_0045A748(m, (pv->b + 0x340));
                    if (func_L24_003556A8(m) == 1) {
                        func_L01_004450F0(m, 0x18, -1);
                        if (m->b[0x43] != 3) {
                            func_003C3A10(m, 3, 0, 0xC);
                        }
                    }
                    if ((func_0038CF38(m->b + 0x10, (pv->b + 0x340)) < 6.0f) || (pv->i[0x330/4] >= 0xD)) {
                        func_L01_004450F0(m, 0xA, -1);
                        if (m->b[0x43] != 0xB) {
                            func_003C3A10(m, 0xB, 0, 7);
                        }
                    }
                    break;
                case 10:                             /* switch 2 */
                    if (m->b[0x60] & 2) {
                        func_L01_004450F0(m, 4, -1);
                        if (m->b[0x43] != 1) {
                            func_003C3A10(m, 1, 0, 7);
                        }
                    }
                    break;
                case 8:                             /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        func_L01_0045BD78(m, D_L24_001DD51C * 0.00040000002f, D_L24_001DD518 * 0.020000001f, D_L24_001DD524 * 0.017453292f * 0.00040000002f, D_L24_001DD520 * 0.017453292f * 0.020000001f);
                    }
                    temp_16_3 = (u8 *)&D_L24_001DF600[pv->i[0x32C/4]];
                    temp_18_2 = temp_16_3 + 0x30;
                    if (func_0038CF38((m->b + 0x10), temp_18_2) < 0.5f) {
                        func_L01_0045BD10(m, ((G *)temp_16_3)->f[0x78/4]);
                    } else {
                        func_L01_0045A748(m, temp_18_2);
                    }
                    if ((func_0038CF38((m->b + 0x10), temp_16_3 + 0x30) < 0.5f) && (func_0038DBA0(m->f[0xF8/4], ((G *)temp_16_3)->f[0x78/4]) < 0.17453292f)) {
                        if (m->b[0x43] != 3) {
                            func_003C3A10(m, 3, 0, 8);
                        }
                        func_L01_004450F0(m, 0x18, -1);
                    }
                    break;
                case 12:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        if (m->b[0x43] == 7) {
                            func_L01_0045BD78(m, D_L24_001DD51C * 0.00040000002f, D_L24_001DD518 * 0.020000001f, D_L24_001DD524 * 0.017453292f * 0.00040000002f, D_L24_001DD520 * 0.017453292f * 0.020000001f);
                        } else {
                            func_L01_0045BD78(m, D_L24_001DD52C * 0.00040000002f, D_L24_001DD528 * 0.020000001f, D_L24_001DD534 * 0.017453292f * 0.00040000002f, D_L24_001DD530 * 0.017453292f * 0.020000001f);
                        }
                        func_L01_00459188(m, pv->p[0x230/4], (pv->b + 0x360));
                        pv->f[0x354/4] = (f32) (func_L01_00443A18(D_L24_001DD564, D_L24_001DD568) * 0.017453292f);
                    }
                    if (func_L24_003556A8(m) == 1) {
                        func_L01_004450F0(m, 0x18, -1);
                        if (m->b[0x43] != 3) {
                            func_003C3A10(m, 3, 0, 0xC);
                        }
                    }
                    if ((pv->i[0x330/4] >= 3) && (func_L24_003556A8(m) == 1)) {
                        func_L01_004450F0(m, 0x18, -1);
                        if (m->b[0x43] != 3) {
                            func_003C3A10(m, 3, 0, 4);
                        }
                    }
                    temp_5_2 = pv->p[0x230/4];
                    if (temp_5_2 != pv->i[0x3B0/4]) {
                        func_L01_00459188(m, temp_5_2, (pv->b + 0x360));
                    }
                    func_L01_00458F78(m, (pv->b + 0x360), 0, 0);
                    func_L01_0045A7A8(m, (pv->b + 0x360), pv->f[0x354/4]);
                    if ((func_0038CF38(m->b + 0x10, pv->b + 0x220) < D_L24_001DD53C) && (func_0038DBA0(m->f[0xF8/4], func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < (D_L24_001DD538 * 0.017453292f))) {
                        if (func_00382468(2) != 0) {
                            if (m->b[0x43] != 0xF) {
                                func_003C3A10(m, 0xF, 0, 8);
                            }
                            func_L01_004450F0(m, 0x12, -1);
                        } else {
                            if (m->b[0x43] != 0x10) {
                                func_003C3A10(m, 0x10, 0, 8);
                            }
                            func_L01_004450F0(m, 0x12, -1);
                        }
                    }
                    break;
                case 14:                            /* switch 2 */
                    if (((u32) (m->b[0x42] - 8) < 2U) && (pv->p[0x2DC/4] == 0) && (func_L01_004395E0(m) > 9.0f) && (func_003C2F58(m, 0, &sp10), (func_L01_003FB640(&sp10, 1, m, D_L24_001DD540) != 0))) {
                        if ((D_L24_001E8F58 != 0) && (D_L24_001E8F58 == pv->p[0x2E0/4])) {
                            pv->p[0x2DC/4] = (void *) D_L24_001E8F58;
                            ((G *)D_L24_001E8F58)->i[0x98/4] = 0;
                            temp_4_5 = pv->p[0x2E0/4];
                            if (((G *)temp_4_5)->h[0xAA/2] == 0x1663) {
                                ((G *)temp_4_5)->c[0xBC] = 1;
                            }
                        }
                    }
                    if (pv->p[0x2E0/4] != 0) {
                        func_L01_0045AA10(m, func_0038D160(((G *)(pv->p[0x2E0/4]))->f[0x10/4] - m->f[0x10/4], ((G *)(pv->p[0x2E0/4]))->f[0x14/4] - m->f[0x14/4]));
                    } else {
                        func_L01_0045A9F0(m);
                    }
                    if (func_L01_0044E1B8(m, 18.0f) != 0) {
                        if (pv->p[0x2DC/4] != 0) {
                            func_L01_004450F0(m, 0x10, -1);
                            if (m->b[0x43] != 0xA) {
                                func_003C3A10(m, 0xA, 0, ((s32) func_003824E0(6.0f, 10.0f) * 5 + 2) / 6);
                            }
                        } else if (func_L24_003554A8(m) != 0) {
                            func_L01_004450F0(m, 0xD, -1);
                            if (func_0038CF38(m->b + 0x10, pv->p[0x2E0/4] + 0x10) < 6.0f) {
                                if (m->b[0x43] != 4) {
                                    func_003C3A10(m, 4, 0, 8);
                                }
                            } else if (m->b[0x43] != 6) {
                                func_003C3A10(m, 6, 0, 8);
                            }
                        }
                    }
                    temp_2 = pv->p[0x2E0/4];
                    if ((temp_2 == 0) || (temp_3 = ((G *)temp_2)->b[0x20], (temp_3 == 0xFE)) || (temp_3 == 0xFD)) {
                        if (func_L24_003554A8(m) != 0) {
                            func_L01_004450F0(m, 0xD, -1);
                            if (func_0038CF38(m->b + 0x10, pv->p[0x2E0/4] + 0x10) < 6.0f) {
                                if (m->b[0x43] != 4) {
                                    func_003C3A10(m, 4, 0, 8);
                                }
                            } else if (m->b[0x43] != 6) {
                                func_003C3A10(m, 6, 0, 8);
                            }
                        } else {
                            func_L01_004450F0(m, 0xC, -1);
                            if ((pv->b[0x5F] == 0) && (func_0038CF38(m->b + 0x10, pv->p[0x230/4] + 0x10) < 6.0f)) {
                                if (m->b[0x43] != 4) {
                                    func_003C3A10(m, 4, 0, 8);
                                }
                            } else if (m->b[0x43] != 7) {
                                func_003C3A10(m, 7, 0, 8);
                            }
                        }
                        if (pv->i[0x33C/4] != 0) {
                            func_L01_004450F0(m, 0xB, -1);
                            if (m->b[0x43] != 4) {
                                func_003C3A10(m, 4, 0, 0xC);
                            }
                            pv->i[0x33C/4] = 0;
                        }
                    }
                    if (pv->i[0x2F0/4] != 0) {
                        func_L01_004450F0(m, 0xC, -1);
                        if ((pv->b[0x5F] == 0) && (func_0038CF38(m->b + 0x10, pv->p[0x230/4] + 0x10) < 6.0f)) {
                            if (m->b[0x43] != 4) {
                                func_003C3A10(m, 4, 0, 8);
                            }
                        } else if (m->b[0x43] != 7) {
                            func_003C3A10(m, 7, 0, 8);
                        }
                    }
                    break;
                case 15:                            /* switch 2 */
                    if (func_L24_00351FD8(m) != 0) {
                        if (m->b[0x43] != 0xA) {
                            func_003C3A10(m, 0xA, 0, ((s32) func_003824E0(6.0f, 10.0f) * 5 + 2) / 6);
                        }
                        func_L01_004450F0(m, 0x10, -1);
                    } else {
                        func_L01_004450F0(m, 0x11, -1);
                        if (m->b[0x43] != 5) {
                            func_003C3A10(m, 5, 0, 5);
                        }
                    }
                    break;
                case 17:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        func_L01_0045BD78(m, D_L24_001DD52C * 0.00040000002f, D_L24_001DD528 * 0.020000001f, D_L24_001DD534 * 0.017453292f * 0.00040000002f, D_L24_001DD530 * 0.017453292f * 0.020000001f);
                    }
                    func_L01_0045A7A8(m, pv->b + 0x220, 0.43633232f);
                    if (func_L24_00351FD8(m) != 0) {
                        if (m->b[0x43] != 0xA) {
                            func_003C3A10(m, 0xA, 0, ((s32) func_003824E0(6.0f, 10.0f) * 5 + 2) / 6);
                        }
                        func_L01_004450F0(m, 0x10, -1);
                    }
                    break;
                case 16:                            /* switch 2 */
                    temp_2_2 = pv->p[0x230/4];
                    func_L01_0045BD10(m, func_0038D160(((G *)temp_2_2)->f[0x10/4] - m->f[0x10/4], ((G *)temp_2_2)->f[0x14/4] - m->f[0x14/4]));
                    if ((m->b[0x42] == 0xA) && (func_L01_0044E1B8(m, 16.5f) != 0)) {
                        vec_sub_ab(&sp10, pv->b + 0x220, ((G *)pv->p[0x2DC/4])->b + 0x10);
                        func_0038CF68(&sp10, &sp10, D_L24_001DD55C * 0.020000001f);
                        sp10.f[2] = func_L01_00447878(pv->p[0x2DC/4] + 0x10, pv->b + 0x220, 0, D_L24_001DD55C * 0.020000001f, -(D_L24_001DD560 * 0.00040000002f));
                        temp_6 = pv->p[0x2DC/4];
                        func_L24_0034E250(m, &sp10, temp_6 + 0x10, temp_6 + 0xF0, ((G *)(pv->p[0x2E0/4]))->h[0xAA/2], D_L24_001DD560 * 0.00040000002f, (f32) pv->b[0x45]);
                        func_003C2880(pv->p[0x2DC/4]);
                        pv->p[0x2DC/4] = 0;
                    }
                    if (m->b[0x60] & 2) {
                        if (func_00382468(2) != 0) {
                            if (m->b[0x43] != 0xB) {
                                func_003C3A10(m, 0xB, 0, 8);
                            }
                            func_L01_004450F0(m, 0x13, -1);
                            break;
                        }
                        if (func_L24_003554A8(m) != 0) {
                            func_L01_004450F0(m, 0xD, -1);
                            if (m->b[0x43] != 6) {
                                func_003C3A10(m, 6, 0, 8);
                            }
                            if ((func_0038CF38(m->b + 0x10, pv->p[0x2E0/4] + 0x10) < 6.0f) && (m->b[0x43] != 4)) {
                                func_003C3A10(m, 4, 0, 8);
                            }
                        } else {
                            func_L01_004450F0(m, 0xC, -1);
                            if ((pv->b[0x5F] == 0) && (func_0038CF38(m->b + 0x10, pv->p[0x230/4] + 0x10) < 6.0f)) {
                                if (m->b[0x43] != 4) {
                                    func_003C3A10(m, 4, 0, 8);
                                }
                            } else if (m->b[0x43] != 7) {
                                func_003C3A10(m, 7, 0, 8);
                            }
                            if (pv->i[0x33C/4] != 0) {
                                func_L01_004450F0(m, 0xB, -1);
                                if (m->b[0x43] != 4) {
                                    func_003C3A10(m, 4, 0, 0xC);
                                }
                                pv->i[0x33C/4] = 0;
                            }
                        }
                    }
                    break;
                case 19:                            /* switch 2 */
                    if (m->b[0x60] & 2) {
                        if (func_L24_003554A8(m) != 0) {
                            func_L01_004450F0(m, 0xD, -1);
                            if (m->b[0x43] != 6) {
                                func_003C3A10(m, 6, 0, 8);
                            }
                            if ((func_0038CF38(m->b + 0x10, pv->p[0x2E0/4] + 0x10) < 6.0f) && (m->b[0x43] != 4)) {
                                func_003C3A10(m, 4, 0, 8);
                            }
                        } else {
                            func_L01_004450F0(m, 0xC, -1);
                            if ((pv->b[0x5F] == 0) && (func_0038CF38(m->b + 0x10, pv->p[0x230/4] + 0x10) < 6.0f)) {
                                if (m->b[0x43] != 4) {
                                    func_003C3A10(m, 4, 0, 8);
                                }
                            } else if (m->b[0x43] != 7) {
                                func_003C3A10(m, 7, 0, 8);
                            }
                            if (pv->i[0x33C/4] != 0) {
                                func_L01_004450F0(m, 0xB, -1);
                                if (m->b[0x43] != 4) {
                                    func_003C3A10(m, 4, 0, 0xC);
                                }
                                pv->i[0x33C/4] = 0;
                            }
                        }
                    }
                    break;
                case 13:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        if (m->b[0x43] == 7) {
                            func_L01_0045BD78(m, D_L24_001DD51C * 0.00040000002f, D_L24_001DD518 * 0.020000001f, D_L24_001DD524 * 0.017453292f * 0.00040000002f, D_L24_001DD520 * 0.017453292f * 0.020000001f);
                        } else {
                            func_L01_0045BD78(m, D_L24_001DD52C * 0.00040000002f, D_L24_001DD528 * 0.020000001f, D_L24_001DD534 * 0.017453292f * 0.00040000002f, D_L24_001DD530 * 0.017453292f * 0.020000001f);
                        }
                        if (pv->p[0x2E0/4] != 0) {
                            func_L01_00459188(m, pv->p[0x2E0/4], pv->b + 0x360);
                        }
                    }
                    if (pv->i[0x2F0/4] != 0) {
                        func_L01_004450F0(m, 0xC, -1);
                        if ((pv->b[0x5F] == 0) && (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) < 6.0f)) {
                            if (m->b[0x43] != 4) {
                                func_003C3A10(m, 4, 0, 8);
                            }
                        } else if (m->b[0x43] != 7) {
                            func_003C3A10(m, 7, 0, 8);
                        }
                    } else {
                        G *t = pv->p[0x2E0/4];
                        if ((t == 0) || (t->b[0x20] == 0xFE) || (t->b[0x20] == 0xFD)) {
                            if (func_L24_003554A8(m) != 0) {
                                func_L01_004450F0(m, 0xD, -1);
                                if (m->b[0x43] != 6) {
                                    func_003C3A10(m, 6, 0, 8);
                                }
                                if ((func_0038CF38(m->b + 0x10, ((G *)pv->p[0x2E0/4])->b + 0x10) < 6.0f) && (m->b[0x43] != 4)) {
                                    func_003C3A10(m, 4, 0, 8);
                                }
                            } else {
                                func_L01_004450F0(m, 0xC, -1);
                                if ((pv->b[0x5F] == 0) && (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) < 6.0f)) {
                                    if (m->b[0x43] != 4) {
                                        func_003C3A10(m, 4, 0, 8);
                                    }
                                } else if (m->b[0x43] != 7) {
                                    func_003C3A10(m, 7, 0, 8);
                                }
                                if (pv->i[0x33C/4] != 0) {
                                    func_L01_004450F0(m, 0xB, -1);
                                    if (m->b[0x43] != 4) {
                                        func_003C3A10(m, 4, 0, 0xC);
                                    }
                                    pv->i[0x33C/4] = 0;
                                }
                            }
                        } else {
                            if (t != pv->p[0x3B0/4]) {
                                func_L01_00459188(m, t, pv->b + 0x360);
                            }
                            func_L01_00458F78(m, pv->b + 0x360, 0, 0);
                            func_L01_0045A748(m, pv->b + 0x360);
                            if (((G *)pv->p[0x2E0/4])->h[0xAA/2] == 0x1663) {
                                if ((func_0038CF38(m->b + 0x10, ((G *)pv->p[0x2E0/4])->b + 0x10) < D_L24_001DD554) && (func_0038DBA0(m->f[0xF8/4], func_0038D160(((G *)pv->p[0x2E0/4])->f[0x10/4] - m->f[0x10/4], ((G *)pv->p[0x2E0/4])->f[0x14/4] - m->f[0x14/4])) < (D_L24_001DD550 * 0.017453292f))) {
                                    if (fabs_asm(m->f[0x18/4] - ((G *)pv->p[0x2E0/4])->f[0x18/4]) < D_L24_001DD558) {
                                        if (m->b[0x43] != 8) {
                                            func_003C3A10(m, 8, 0, 8);
                                        }
                                    } else if (m->b[0x43] != 9) {
                                        func_003C3A10(m, 9, 0, 8);
                                    }
                                    func_L01_004450F0(m, 0xE, -1);
                                }
                            } else if ((func_0038CF38(m->b + 0x10, ((G *)pv->p[0x2E0/4])->b + 0x10) < D_L24_001DD554) && (func_0038DBA0(m->f[0xF8/4], func_0038D160(((G *)pv->p[0x2E0/4])->f[0x10/4] - m->f[0x10/4], ((G *)pv->p[0x2E0/4])->f[0x14/4] - m->f[0x14/4])) < (D_L24_001DD550 * 0.017453292f))) {
                                if ((fabs_asm(m->f[0x18/4] - ((G *)pv->p[0x2E0/4])->f[0x18/4]) < D_L24_001DD558) || (((G *)pv->p[0x2E0/4])->h[0xAA/2] == 0x1663)) {
                                    if (m->b[0x43] != 8) {
                                        func_003C3A10(m, 8, 0, 8);
                                    }
                                } else if (m->b[0x43] != 9) {
                                    func_003C3A10(m, 9, 0, 8);
                                }
                                func_L01_004450F0(m, 0xE, -1);
                            } else if (*(u8 *)&D_L24_001DF0C0 == (u8)((s32)m >> 8)) {
                                func_L01_00456230(pv->p[0x2E0/4], 0);
                                func_L24_003554A8(m);
                            }
                            if (func_L24_003556A8(m) == 1) {
                                func_L01_004450F0(m, 0x18, -1);
                                if (m->b[0x43] != 3) {
                                    func_003C3A10(m, 3, 0, 0xC);
                                }
                            }
                        }
                    }
                    break;
                case 18:                            /* switch 2 */
                    temp_2_6 = pv->p[0x230/4];
                    func_L01_0045AA10(m, func_0038D160(((G *)temp_2_6)->f[0x10/4] - m->f[0x10/4], ((G *)temp_2_6)->f[0x14/4] - m->f[0x14/4]));
                    if (m->b[0x60] & 2) {
                        if ((func_0038CF38((m->b + 0x10), pv->b + 0x220) > D_L24_001DD53C) || (func_0038DBA0(m->f[0xF8/4], func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) > (D_L24_001DD538 * 0.017453292f))) {
                            if ((pv->b[0x5F] == 0) && (func_0038CF38((m->b + 0x10), pv->p[0x230/4] + 0x10) < 6.0f)) {
                                if (m->b[0x43] != 4) {
                                    func_003C3A10(m, 4, 0, 8);
                                }
                            } else if (m->b[0x43] != 7) {
                                func_003C3A10(m, 7, 0, 8);
                            }
                            func_L01_004450F0(m, 0xC, -1);
                        } else if (func_00382468(2) != 0) {
                            if (m->b[0x43] != 0xF) {
                                func_003C3A10(m, 0xF, 0, 8);
                            }
                            func_L01_004450F0(m, 0x12, -1);
                        } else {
                            if (m->b[0x43] != 0x10) {
                                func_003C3A10(m, 0x10, 0, 8);
                            }
                            func_L01_004450F0(m, 0x12, -1);
                        }
                    }
                    if ((func_L01_004395E0(m) > 10.0f) && (m->b[0x42] == 0xF)) {
                        func_L01_004468C8(m, 0, D_L24_001DD540, (f32) pv->b[0x44], (pv->b[0x5F] != 0) ? 0x08010001 : 0x08000001, D_L24_001DD544, 0, 1, 0);
                    } else if ((func_L01_004395E0(m) > 10.0f) && (m->b[0x42] == 0x10)) {
                        func_L01_004468C8(m, 1, D_L24_001DD540, (f32) pv->b[0x44], (pv->b[0x5F] != 0) ? 0x08010001 : 0x08000001, D_L24_001DD544, 0, 1, 0);
                    }
                    break;
                case 24:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        sp10.f[0] = func_0038D098(m->f[0xF8/4]) * 7.5f;
                        temp_f0 = func_0038D0B0(m->f[0xF8/4]) * 7.5f;
                        sp10.f[2] = 0.0f;
                        sp10.f[1] = temp_f0;
                        vec_add_ab(&sp10, m->b + 0x10, &sp10);
                        pv->f[0x308/4] = func_003C3D30(&sp10, 0, 0, 0.5f);
                        pv->f[0x30C/4] = (f32) m->f[0x18/4];
                    }
                    if (m->b[0x42] == 3) {
                        f32 t;
                        m->f[0x48/4] = 1.0f;
                        t = func_L01_004395E0(m);
                        if ((t > 11.0f) && (t < 22.0f)) {
                            func_0038CF68(&sp30, m->b + 0xC0, 0.3409091f);
                            vec_add_ba(&sp10, m->b + 0x10, &sp30);
                        }
                        if ((t > 11.0f) && (t < 17.0f)) {
                            func_003C41A0(&sp10.f[2], pv->f[0x308/4] + 1.5f, pv->b + 0x320, 0.016666668f, 0.11904763f, 0.25f);
                        }
                        if (t == 17.0f) {
                            pv->i[0x320/4] = 0;
                        }
                        if ((t > 17.0f) && (t < 22.0f)) {
                            if (fabs_asm(pv->f[0x308/4] - pv->f[0x30C/4]) > 6.0f) {
                                m->f[0x48/4] = 0.35f;
                            } else {
                                m->f[0x48/4] = 0.8f;
                            }
                            func_003C41A0(&sp10.f[2], pv->f[0x308/4], pv->b + 0x320, 0.021428572f, 0.15f, 0.3f);
                        }
                        if ((t > 11.0f) && (t < 22.0f)) {
                            vec_sub_ab(&sp20, &sp10, m->b + 0x10);
                            func_L01_0045AA30(m, &sp20);
                        }
                        if (m->b[0x60] & 2) {
                            pv->f[0xA0/4] = 0.06981317f;
                            func_L01_004450F0(m, 0xD, 2);
                            if (m->b[0x43] != 6) {
                                func_003C3A10(m, 6, 0, 8);
                            }
                        }
                    }
                    break;
                case 20:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        temp_4_6 = m->p[0x24/4];
                        temp_3_3 = m->uh[0x34/2] & 0xFFBE;
                        m->uh[0x34/2] = temp_3_3;
                        m->uh[0x34/2] = (u16) (temp_3_3 | (((G *)temp_4_6)->uh[0x44/2] & 0x1000));
                        m->i[0x98/4] = (s32) ((G *)temp_4_6)->i[0x10/4];
                    }
                    if (m->b[0x42] == 3) {
                        f32 t = func_L01_004395E0(m);
                        temp_16_6 = (u8 *)&D_L24_001DF600[(t < 17.0f) ? pv->i[0x324/4] : pv->i[0x328/4]];
                        if ((t > 11.0f) && (t < 22.0f)) {
                            func_0038CF68(&sp30, m->b + 0xC0, 0.18181819f);
                            vec_add_ba(&sp10, m->b + 0x10, &sp30);
                        } else {
                            m->f[0x48/4] = 1.0f;
                        }
                        if (t > 11.0f) {
                            if (t < 17.0f) {
                                m->f[0x48/4] = 0.5f;
                                func_003C41A0(&sp10.f[2], ((G *)temp_16_6)->f[0x38/4] + 1.5f, pv->b + 0x320, 0.25f, 0.03125f, 0.375f);
                            }
                        }
                        if (t == 17.0f) {
                            pv->i[0x320/4] = 0;
                        }
                        if ((t > 17.0f) && (t < 22.0f)) {
                            func_003C4138(m->b + 0x48, 0.75f, 0.2f);
                            func_003C41A0(&sp10.f[2], ((G *)temp_16_6)->f[0x38/4], pv->b + 0x320, 0.3f, 0.3f, 0.48000002f);
                        }
                        if ((t > 11.0f) && (t < 22.0f)) {
                            vec_sub_ab(&sp20, &sp10, m->b + 0x10);
                            func_L01_0045AA30(m, &sp20);
                        }
                        if (func_L01_0044E1B8(m, 31.0f) != 0) {
                            m->f[0x48/4] = 1.0f;
                            pv->f[0xA0/4] = 0.06981317f;
                            if (m->b[0x43] != 8) {
                                func_003C3A10(m, 8, 0, 8);
                            }
                            func_L01_004450F0(m, 0xE, 2);
                            pv->c[0x1A9] = 1;
                        }
                    }
                    break;
                case 11:                            /* switch 2 */
                    sp10.f[0] = 443.82f;
                    sp10.f[2] = 21.11f;
                    sp10.f[1] = 137.81f;
                    func_L01_0045BD10(m, func_0038D160(443.82f - m->f[0x10/4], 137.81f - m->f[0x14/4]));
                    if (func_0038DBA0(m->f[0xF8/4], func_0038D160(sp10.f[0] - m->f[0x10/4], sp10.f[1] - m->f[0x14/4])) < 0.10471976f) {
                        func_L01_004450F0(m, 0x18, -1);
                        if (m->b[0x43] != 3) {
                            func_003C3A10(m, 3, 0, 0xC);
                        }
                        pv->i[0x33C/4] = 0;
                    }
                    break;
                case 21:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        temp_4_7 = m->p[0x24/4];
                        temp_3_4 = m->uh[0x34/2] & 0xFFBE;
                        m->uh[0x34/2] = temp_3_4;
                        m->uh[0x34/2] = (u16) (temp_3_4 | (((G *)temp_4_7)->uh[0x44/2] & 0x1000));
                        m->i[0x98/4] = (s32) ((G *)temp_4_7)->i[0x10/4];
                    }
                    if (m->b[0x42] == 3) {
                        f32 t = func_L01_004395E0(m);
                        temp_16_7 = (u8 *)&D_L24_001DF600[(t < 17.0f) ? pv->i[0x324/4] : pv->i[0x328/4]];
                        if ((t > 11.0f) && (t < 22.0f)) {
                            func_0038CF68(&sp30, m->b + 0xC0, 0.18181819f);
                            vec_add_ba(&sp10, m->b + 0x10, &sp30);
                        } else {
                            m->f[0x48/4] = 1.0f;
                        }
                        if (t > 11.0f) {
                            if (t <= 17.0f) {
                                m->f[0x48/4] = 0.75f;
                                func_003C41A0(&sp10.f[2], ((G *)temp_16_7)->f[0x38/4] + 1.5f, pv->b + 0x320, 0.25f, 0.013888889f, 0.275f);
                            }
                        }
                        if (t == 17.0f) {
                            pv->i[0x320/4] = 0;
                        }
                        if ((t > 17.0f) && (t < 22.0f)) {
                            func_003C4138(m->b + 0x48, 1.0f, 0.075f);
                            func_003C41A0(&sp10.f[2], ((G *)temp_16_7)->f[0x38/4], pv->b + 0x320, 0.060000002f, 0.90000004f, 0.96000004f);
                        }
                        if ((t > 11.0f) && (t < 22.0f)) {
                            vec_sub_ab(&sp20, &sp10, m->b + 0x10);
                            func_L01_0045AA30(m, &sp20);
                        }
                        if (func_L01_0044E1B8(m, 31.0f) != 0) {
                            m->f[0x48/4] = 1.0f;
                            pv->f[0xA0/4] = 0.06981317f;
                            if (m->b[0x43] != 8) {
                                func_003C3A10(m, 8, 0, 8);
                            }
                            func_L01_004450F0(m, 0xE, 2);
                            pv->c[0x1A9] = 1;
                        }
                    }
                    break;
                case 7:                             /* switch 2 */
                    if (((s32) D_L24_001DF0C0 >= 3) && ((temp_16_8 = D_L24_001DF51C + (pv->i[0x2EC/4] << 8), temp_4_8 = func_00382348(temp_16_8), (temp_16_8 == 0)) || (temp_3_5 = ((G *)temp_16_8)->b[0x20], (temp_3_5 == 0xFE)) || (temp_3_5 == 0xFD) || (*temp_4_8 <= 0.0f)) && (pv->h[0x234/2] == 1)) {
                        func_L01_004450F0(m, 0x14, 2);
                        if (m->b[0x43] != 3) {
                            func_003C3A10(m, 3, 0, 8);
                        }
                    }
                    break;
                }
            vec_sub_ba(&sp10, m->b + 0x10, &sp00);
            if ((func_0038CED8(&sp10) < 0.060000002f) && ((temp_3_6 = m->b[0x20], (temp_3_6 == 0xC)) || (temp_3_6 == 9) || (temp_3_6 == 0xD))) {
                pv->i[0x330/4] = (s32) (pv->i[0x330/4] + 1);
            } else {
                func_0038CAD0(pv->b + 0x330);
            }
            if (((u32) (m->b[0x20] - 0x14) >= 2U) && (func_L01_004513A8(m->b + 0x10, 0, 0) < 0.1f)) {
                temp_3_7 = m->b[0x95];
                if (temp_3_7 != 4) {
                if ((temp_3_7 != 3) && ((func_003D5630() == 0) || (func_003D5630() == 1))) {
                    func_L01_004450F0(m, 0x17, 4);
                    if (m->b[0x43] != 0xE) {
                        func_003C3A10(m, 0xE, 6, 5);
                    }
                    sp20.q = m->q[0x10/16];
                    var_16_2 = 2;
                    func_L01_003016B0(&sp20, 3, 3.25f, 1.025f);
                    do {
                        var_16_2 -= 1;
                        sp30.f[0] = m->f[0x10/4] + func_003824E0(-0.3f, 0.3f);
                        temp_f1 = m->f[0x14/4] + func_003824E0(-0.3f, 0.3f);
                        sp30.f[2] = m->f[0x18/4];
                        sp30.f[1] = temp_f1;
                        func_L01_0046A938(&sp30, m->b + 0x18, -1, func_003824E0(0.5f, 0.75f), 5250.0f);
                    } while (var_16_2 >= 0);
                    var_18 = 0xF;
                    do {
                        var_18 -= 1;
                        temp_f21 = func_00382538();
                        temp_f20_2 = func_003824E0(0, 0.060000002f);
                        sp30.f[0] = func_0038D098(temp_f21) * temp_f20_2;
                        sp30.f[1] = func_0038D0B0(temp_f21) * temp_f20_2;
                        sp30.f[2] = func_003824E0(0.060000002f, 0.16000001f);
                        sp40.f[0] = m->f[0x10/4] + (sp30.f[0] * 8.0f);
                        sp40.f[1] = m->f[0x14/4] + (sp30.f[0] * 8.0f);
                        sp40.f[2] = m->f[0x18/4] - func_003824E0(0, 0.2f);
                        temp_16_9 = func_00382468(2);
                        func_L01_00468A68(&sp40, &sp30, temp_16_9, func_00382498(0x5A, 0x78));
                    } while (var_18 >= 0);
                }
                }
            }
            func_L24_003552F8(m);
}
