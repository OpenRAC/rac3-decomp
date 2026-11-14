/* func_L06_0034A7A8: an enemy moby's per-frame update (Starship Phoenix under attack, also level 10 at
   00349A68): a switch on its mode (m+0x95: 0-3) and a 40-way switch on its state (m+0x20, cases 1-40)
   through jtbl_002BD000; the VU0 vector work through include/vu0.h's helpers. Written from retail
   with an m2c draft (Opus, 2026-11-08), then reworked (Opus, 2026-11-08, second pass).
   Near miss: 5042 instructions, the same as retail; 5019 lines (99.5 percent) and 5037 opcodes
   (99.9 percent) equal at level 06 (kit cd.py); the stock checker reports 33 diff.
   Needs on src/levels/shared/L06_0034A2B8.c: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as", include/vu0.h (with vec_copy), and the .extern size hints for
   the $gp scalars D_L06_001DD290/001DD298 (D_L06_001DEE80 has none: Ps2EeAs gives it lui+lw, and
   $gp only in the one delay slot retail has it in).
   What mattered (second pass, 94.4 -> 99.5 percent):
   - fe_func_003C41A0 is (p, f32, p, f32, f32, f32): with arguments evaluated in order, the float
     (often a call) comes before the second pointer, as retail computes pv+0x8E0 after the call;
     func_L01_004468C8 is s32 (m, s32, f32, f32, s32, f32, s32, s32, s32);
   - D_L06_001DEA4C points to a 0x30-byte header then 0x30-byte records (count at +2, list at
     +0x10): base + n*0x30 in retail's operand order; D_L06_001DEE80 is an array of 0x80-byte
     records with a vector at +0x30; D_L06_001E8458 is .data (%hi/%lo everywhere);
   - no m2c address temps: m+0x10, pv+0x220, pv+0x980 written at each use (CSE and the helpers'
     parameters give retail's callee-saved copies); cases 33 and 34 keep &sp90, &spB0, m+0x10 in
     pointer locals (retail's s2/s1/s0 across the calls), which also keeps them from being
     cross-jumped together, so no do { } while (0) is needed;
   - state 30 and 18's lqc2/sqc2 copies of m+0x10 are vec_copy (plain u128 copies give lq/sq);
   - state 22: the first 0x980 store through a plain pointer (retail reloads D_L06_001DEA4C after
     it), the loop bound re-read from pv->i[0x974/4]; switch 3 (state 23) is an if chain;
     "(x - 2 + n) % n" for the ring index; case 1/2 labels (the table starts at 1); case 5's list
     offsets in bytes; stores in retail's order in states 39 and 40.
   Left (33 rows, allocation and scheduling):
   - state 30: vf1/vf2 swapped in vec_sub_ba + vec_copy (retail: m+0x10 in vf1, the copy in vf1
     after the vsub);
   - state 22: the first record test allocates 0x30/D_L06_001DEA4C/the sum in v1/a2/v0 against
     retail's v0/v1/v1;
   - state 18: retail interleaves the two vec_copy of m+0x10 with the first vec_sub's loads (copy,
     load a, copy, load b); putting the second copy after the vsub in C spills a VU register
     (frame +0x10);
   - level 10's place differs in more rows (77; not looked at).
   Tried without effect (Opus, 2026-11-13): state 30 with a vsub whose result is tied to the
   loaded-second source ("+j", both load orders), the copy before the sub (spills a VU register,
   frame +0x10), a pointer local for m+0x10; state 22 with an E30 pointer local (1241 diff), the
   record reached as (E30 *)(base + 0x30) + n, base[0].e[n] and base->e + n (33-41 diff). */
typedef int u128_t __attribute__((mode(TI)));
typedef union Mo_ { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; long d[0x20]; u128_t q[0x10]; } Mo;
typedef union Pv_ { u8 b[0x1000]; s8 c[0x1000]; s16 h[0x800]; u16 uh[0x800]; s32 i[0x400]; u32 u[0x400]; f32 f[0x400]; void *p[0x400]; long d[0x200]; u128_t q[0x100]; } Pv;
typedef union G_ { u8 b[0x4000]; s8 c[0x4000]; s16 h[0x2000]; u16 uh[0x2000]; s32 i[0x1000]; u32 u[0x1000]; f32 f[0x1000]; void *p[0x1000]; long d[0x800]; u128_t q[0x400]; } G;
typedef union { f32 f[4]; s32 i[4]; s8 c[16]; u8 b[16]; s16 h[8]; u16 uh[8]; u128_t q; } __attribute__((aligned(16))) U16;
extern char D_001A4BE0[];
typedef struct { u8 pad0[2]; s16 cnt; u8 pad4[0xC]; s32 *list; u8 pad14[0x1C]; } E30;
typedef struct { u8 hdr[0x30]; E30 e[1]; } H30;
extern H30 *D_L06_001DEA4C;
typedef struct { u8 pad0[0x30]; u128_t pos; u8 pad40[0x40]; } E80;
extern E80 *D_L06_001DEE80;
extern s32 D_L06_001E8458 __attribute__((section(".data")));
extern u128_t D_L06_001E8460;
extern void *D_L06_0021CB00[];
extern s32 D_L06_001DD298;
extern f32 D_L06_001DD290;
__asm__(".extern D_L06_001DD298, 4");
__asm__(".extern D_L06_001DD290, 4");
extern void func_L06_0034FDA8(void *);
extern s32 fe_func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 fe_func_0038CB00(void *);
extern f32 fe_func_0038CF38(void *, void *);
extern void fe_func_0038CF68(void *, void *, f32);
extern f32 fe_func_0038D098(f32);
extern f32 fe_func_0038D0B0(f32);
extern f32 fe_func_0038D160(f32, f32);
extern f32 fe_func_0038DAB8(f32, f32);
extern f32 fe_func_0038DBA0(f32, f32);
extern void fe_func_003C2880(void *);
extern f32 func_L01_004395E0(void *);
extern void fe_func_003C2F58(void *, s32, void *);
extern s32 fe_func_00382468(s32);
extern s32 fe_func_00382498(s32, s32);
extern f32 fe_func_003824E0(f32, f32);
extern f32 fe_func_00382538(void);
extern void fe_func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern void func_L01_00445BE0(s32, s32);
extern f32 fe_func_003C3D30(void *, s32, s32, f32);
extern void func_L01_00446760(void *, void *, s32, f32, void *);
extern f32 fe_func_003C4138(void *, f32, f32);
extern void fe_func_003C41A0(void *, f32, void *, f32, f32, f32);
extern s32 func_L01_0044C108(void *);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004561E0(void *);
extern void func_L01_00459188(void *, void *, void *);
extern void func_L01_0045A748(void *, void *);
extern s32 func_L01_0045AA30(void *, void *);
extern s32 func_L01_0045BD10(void *, f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0045BDE8(void *, s32);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L01_0045D218(void *, void *);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L06_0034A6C8(void *);
extern s32 func_L06_0034F670(void *);
extern s32 func_L06_0034FCC8(void *, s32);
extern void func_L06_003584D0(void *, void *, void *, void *, s32, s32, f32);
extern s32 func_L01_004468C8(void *, s32, f32, f32, s32, f32, s32, s32, s32);
extern s32 func_L06_0042B660(void *, void *, f32);
extern void func_L01_0044C280(void *, void *, void *, s32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_L01_00458F78(void *, void *, s32, s32);
#include "vu0.h"

void func_L06_0034A7A8(Mo *m) {
    U16 sp90;
    U16 spA0;
    U16 spB0;
    U16 spC0;
    U16 spD0;
    U16 spE0;
    U16 spF0;
    U16 sp100;
    U16 sp110;
    U16 sp120;
    U16 sp130;
    U16 sp140;
    f32 temp_f0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_12;
    f32 temp_f0_13;
    f32 temp_f0_14;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f14_3;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f21;
    f32 var_f0;
    f32 var_f22;
    s32 *temp_s1;
    s32 temp_a0_10;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_a0_7;
    s32 temp_a0_8;
    s32 temp_a0_9;
    s32 temp_a1;
    s32 temp_a1_4;
    s32 temp_a1_5;
    s32 temp_a3;
    s32 temp_s0_2;
    s32 temp_s0_6;
    s32 temp_s2;
    s32 temp_s7;
    s32 temp_v0;
    s32 temp_v0_10;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a1;
    s32 var_a1_10;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a1_4;
    s32 var_a1_5;
    s32 var_a1_6;
    s32 var_a1_7;
    s32 var_a1_8;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_condition_bit;
    s32 var_condition_bit_2;
    s32 var_condition_bit_3;
    s32 var_condition_bit_4;
    s32 var_condition_bit_5;
    s32 var_condition_bit_6;
    s32 var_condition_bit_7;
    s32 var_condition_bit_8;
    s32 var_condition_bit_9;
    s32 var_s2;
    u8 temp_a0;
    u8 temp_v0_2;
    u8 temp_v1;
    u8 temp_v1_3;
    u8 temp_v1_4;
    u8 temp_v1_5;
    u8 temp_v1_7;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_s0;
    void *temp_s0_10;
    void *temp_s0_11;
    void *temp_s0_12;
    void *temp_s0_13;
    void *temp_s0_14;
    void *temp_s0_3;
    void *temp_s0_4;
    void *temp_s0_5;
    void *temp_s0_7;
    void *temp_s0_8;
    void *temp_s0_9;
    void *temp_s1_2;
    void *temp_s1_3;
    void *temp_s1_4;
    void *temp_s1_5;
    void *temp_s1_6;
    void *temp_s1_7;
    void *temp_s3;
    void *temp_s4;
    Pv *pv;
    void *temp_s7_2;
    void *temp_v0_7;
    void *temp_v0_8;
    void *temp_v0_9;
    void *temp_v1_6;
    void *var_a0_2;
    void *var_a0_3;
    void *var_a1_9;
    void *var_s0;
    void *var_s1;

    pv = m->p[0x68/4];
    if (func_L01_0044C108((u8 *)m + 0x10) == 0) {
        return;
    }
    if ((pv->i[0x958/4] != 0) && (m->b[0x20] == 0x25)) {
        return;
    }
    if ((func_L06_0034F670(m) != 0) || (pv->d[0x908/8] != 0)) {
        fe_func_003C2880(m);
        return;
    }
    if ((pv->f[0x30/4] > 0.0f) && (((G *)D_001A4BE0)->i[0x2850/4] <= 0) && (m->b[0x60] & 2) && (m->b[0x95] != 4)) {
        if (m->b[0x43] != 0x12) {
            fe_func_003C3A10(m, 0x12, 0, 8);
        }
        func_L01_004450F0(m, 0x18, 4);
        if (((G *)D_001A4BE0)->p[0x2808/4] == m) {
            if (m->b[0x43] != 2) {
                fe_func_003C3A10(m, 2, 0, 8);
            }
            func_L01_004450F0(m, 0x19, -1);
        }
    }
    if ((pv->b[0x176] == 0xFF) && (pv->f[0x30/4] <= 0.0f)) {
        if ((m->b[0x21] != 0xFF) && (m->b[0xBC] == 0)) {
            func_L01_00445BE0(m->b[0x21], 0);
            m->b[0xBC] = 0;
        }
        func_L06_0034FCC8(m, 0);
        func_L01_003303B8((u8 *)m + 0x10, 0, 0xA, 0xA, 0xA, 0xA, 0xF, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                          0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        fe_func_003C2880(m);
        return;
    }
    temp_s7 = (pv->b[0x5F] != 0) ? 0x10001 : 1;
    switch (m->b[0x95]) {
    case 0:
        if ((pv->i[0x948/4] != -1) && (func_L01_00445AD0(pv->i[0x948/4], -1, 1) != 0)) {
            break;
        }
        if ((pv->h[0x234/2] == 1) && (fe_func_0038CB00(pv->b + 0x8D6) != 0)) {
            func_L01_004450F0(m, 0xB, 2);
            if (m->b[0x43] != 0xB) {
                fe_func_003C3A10(m, 0xB, 0, (s32)(((fe_func_003824E0(6.0f, 12.0f) * 5.0f) + 2.0f) / 6.0f));
            }
            if ((pv->i[0x930/4] != 0) && (pv->i[0x944/4] == -1)) {
                func_L01_004450F0(m, 0xA, 2);
                if (m->b[0x43] != 0xE) {
                    fe_func_003C3A10(m, 0xE, 0, 8);
                }
            }
            if (pv->i[0x908/4] != 0) {
                s32 r = func_L06_0034A6C8(m);
                if (r == 1) {
                    if (m->b[0x43] != 4) {
                        fe_func_003C3A10(m, 4, 0, 8);
                    }
                    func_L01_004450F0(m, 0x1D, 2);
                    pv->i[0x908/4] = 2;
                } else if (r == 2) {
                    if (m->b[0x43] != 3) {
                        fe_func_003C3A10(m, 3, 0, 8);
                    }
                    func_L01_004450F0(m, 0x1E, 2);
                    pv->i[0x908/4] = 1;
                }
            }
            if (pv->i[0x95C/4] != -1) {
                func_L01_004450F0(m, 0x11, 2);
                if (m->b[0x43] != 7) {
                    fe_func_003C3A10(m, 7, 0, 8);
                }
            }
            {
            s32 n = pv->i[0x974/4];
            if ((n != -1) && (D_L06_001DEA4C->e[n].cnt != 0)) {
                func_L01_004450F0(m, 0xB, 2);
                if (m->b[0x43] != 0xB) {
                    fe_func_003C3A10(m, 0xB, 0, (s32)(((fe_func_003824E0(6.0f, 12.0f) * 5.0f) + 2.0f) / 6.0f));
                }
            }
            }
            if (pv->i[0x90C/4] != 0) {
                if (m->b[0x43] != 5) {
                    fe_func_003C3A10(m, 5, 0, 8);
                }
                func_L01_004450F0(m, 0x1F, 2);
            }
            if (pv->i[0x94C/4] != 0) {
                if (m->b[0x43] != 5) {
                    fe_func_003C3A10(m, 5, 0, 8);
                }
                func_L01_004450F0(m, 0x20, 2);
            }
        } else if ((pv->i[0x8D8/4] != 0) && (fe_func_0038CB00(pv->b + 0x8D6) != 0)) {
            if (m->b[0x20] == 2) {
                if (m->b[0x43] != 5) {
                    fe_func_003C3A10(m, 5, 0, 8);
                }
                func_L01_004450F0(m, 0x20, 2);
            } else {
                func_L01_004450F0(m, 8, 1);
            }
            pv->i[0x8D8/4] = 0;
            if (pv->i[0x8D0/4] < 0xFA) {
                pv->i[0x8D0/4] = (fe_func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    case 1:
        if (pv->h[0x234/2] == 1) {
            func_L01_004450F0(m, 0xB, 2);
            if (m->b[0x43] != 0xB) {
                fe_func_003C3A10(m, 0xB, 0, 8);
            }
            if (m->b[0x20] == 2) {
                if (m->b[0x43] != 5) {
                    fe_func_003C3A10(m, 5, 0, 8);
                }
                func_L01_004450F0(m, 0x20, 2);
            }
        }
        break;
    case 2:
        if ((pv->h[0x234/2] != 1) && (func_L01_004561E0(m) == 0) && (m->b[0x20] != 0x20)) {
            if (m->b[0x43] != 0x11) {
                fe_func_003C3A10(m, 0x11, 0, 8);
            }
            func_L01_004450F0(m, 8, 1);
            pv->i[0x8D0/4] = (fe_func_00382498(0x244, 0x258) * 5 + 2) / 6;
        }
        break;
    case 3:
        {
        s32 r = func_L01_00454370(m, pv->b + 0x160);
        if (r & 1) {
            if ((m->b[0x21] != 0xFF) && (m->b[0xBC] == 0)) {
                func_L01_00445BE0(m->b[0x21], 0);
                m->b[0xBC] = 0;
            }
            func_L06_0034FCC8(m, 0);
            func_L01_003303B8((u8 *)m + 0x10, 0, 0xA, 0xA, 0xA, 0xA, 0xF, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            fe_func_003C2880(m);
            return;
        }
        if (r & 2) {
            if (pv->h[0x234/2] == 1) {
                if (pv->i[0x95C/4] != -1) {
                    func_L01_004450F0(m, 0x11, 2);
                    if (m->b[0x43] != 7) {
                        fe_func_003C3A10(m, 7, 0, 7);
                    }
                } else {
                    func_L01_004450F0(m, 0xE, 2);
                    if (m->b[0x43] != 6) {
                        fe_func_003C3A10(m, 6, 0, 7);
                    }
                }
            } else {
                if (m->b[0x43] != 0x11) {
                    fe_func_003C3A10(m, 0x11, 0, 8);
                }
                func_L01_004450F0(m, 8, 1);
                pv->i[0x8D0/4] = (fe_func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        if ((pv->b[0x176] == 0xFF) && (pv->f[0x30/4] <= 0.0f)) {
            if ((m->b[0x21] != 0xFF) && (m->b[0xBC] == 0)) {
                func_L01_00445BE0(m->b[0x21], 0);
                m->b[0xBC] = 0;
            }
            func_L06_0034FCC8(m, 0);
            func_L01_003303B8((u8 *)m + 0x10, 0, 0xA, 0xA, 0xA, 0xA, 0xF, 0, 1.0f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            fe_func_003C2880(m);
            return;
        }
        }
        break;
    }
    switch (m->b[0x20]) {
                        case 1:
                        case 2:
                            break;
                        case 3:                     /* switch 2 */
                            if (m->b[0x60] & 2) {
                                if (m->b[0x43] != 9) {
                                    fe_func_003C3A10(m, 9, 0, 0);
                                }
                                func_L01_004450F0(m, 4, -1);
                            }
                            break;
                        case 4:                     /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                func_L01_0045BD78(m, 0.0032000002f, 0.040000003f, 0.010053097f, 0.25132743f);
                                temp_f20 = fe_func_00382538();
                                temp_f21 = fe_func_003824E0(7.0f, 8.0f);
                                qzero(pv->b + 0x960);
                                pv->f[0x960/4] = fe_func_0038D098(temp_f20) * temp_f21;
                                pv->f[0x964/4] = fe_func_0038D0B0(temp_f20) * temp_f21;
                                vec_add_ab(pv->b + 0x960, pv->b + 0x910, pv->b + 0x960);
                            }
                            fe_func_0038CF68(&sp90, (u8 *)m + 0xC0, 3.0f);
                            vec_add_ab(&sp90, &sp90, m->b + 0x10);
                            func_L01_0045A748(m, &sp90);
                            func_L01_0045BD10(m, fe_func_0038D160(pv->f[0x960/4] - m->f[0x10/4], pv->f[0x964/4] - m->f[0x14/4]));
                            if (fe_func_0038CF38((u8 *)m + 0x10, (u8 *)pv + 0x960) < 0.5f) {
                                func_L01_004450F0(m, 7, -1);
                                if (m->b[0x43] != 1) {
                                    fe_func_003C3A10(m, 1, 1, 0xA);
                                }
                            }
                            break;
                        case 5:                     /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                temp_s0 = (u8 *)m + 0x10;
                                func_L01_0045BD78(m, 0.0032000002f, 0.040000003f, 0.0050265486f, 0.25132743f);
                                temp_s1 = D_L06_0021CB00[pv->i[0x950/4]];
                                temp_f20_2 = fe_func_0038CF38(temp_s0, (u8 *)temp_s1 + 0x10);
                                if (fe_func_0038CF38(temp_s0, (u8 *)temp_s1 + (*temp_s1 * 0x10)) < temp_f20_2) {
                                    func_L01_0045C150(m, temp_s1, 0, *temp_s1 - 1);
                                } else {
                                    func_L01_0045C150(m, temp_s1, *temp_s1 - 1, 0);
                                }
                            }
                            if (func_L01_0045BDE8(m, pv->i[0x950/4]) != 0) {
                                func_L01_004450F0(m, 7, -1);
                                if (m->b[0x43] != 1) {
                                    fe_func_003C3A10(m, 1, 6, 3);
                                }
                            }
                            break;
                        case 6:                     /* switch 2 */
                            func_L01_004561B8(m);
                            if ((func_L01_0044E1B8(m, 8.0f) != 0) && (m->b[0x42] == 0xA)) {
                                if (m->b[0x43] != 1) {
                                    fe_func_003C3A10(m, 1, 6, 3);
                                }
                                func_L01_004450F0(m, 7, -1);
                                break;
                            }
                            break;
                        case 7:                     /* switch 2 */
                            if ((func_L01_0044E1B8(m, 61.0f) != 0) && (m->b[0x42] == 1)) {
                                if (m->b[0x43] != 6) {
                                    fe_func_003C3A10(m, 6, 0, 0xA);
                                }
                                func_L01_004450F0(m, 4, -1);
                                if (pv->i[0x950/4] != -1) {
                                    func_L01_004450F0(m, 5, -1);
                                    if (m->b[0x43] != 6) {
                                        fe_func_003C3A10(m, 6, 0, 0xA);
                                    }
                                }
                            }
                            break;
                        case 8:                     /* switch 2 */
                            if (m->b[0x60] & 2) {
                                if (m->b[0x43] != 6) {
                                    fe_func_003C3A10(m, 6, 0, 5);
                                }
                                func_L01_004450F0(m, 4, -1);
                                break;
                            }
                            break;
                        case 36:                    /* switch 2 */
                            if (m->b[0x42] == 0x1B) {
                                temp_f0 = func_L01_004395E0(m);
                                if ((temp_f0 > 8.0f) && (temp_f0 < 24.0f)) {
                                    f32 d = fe_func_0038CF38((u8 *)m + 0x10, (u8 *)pv + 0x220);
                                    fe_func_0038CF68(&spB0, (u8 *)m + 0xC0, (d - 1.25f) * 0.0625f);
                                    vec_add_ba(&sp90, m->b + 0x10, &spB0);
                                    if (temp_f0 < 20.0f) {
                                        func_L01_0045BD10(m, fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]));
                                    }
                                }
                                if (temp_f0 > 16.0f) {
                                    fe_func_003C2F58(m, 0, &spB0);
                                    fe_func_003C2F58(m, 1, &spC0);
                                    temp_a1 = D_L06_001DD298;
                                    temp_s0_2 = ((pv->i[0x8DC/4] - 2 + temp_a1) % temp_a1) * 0x10;
                                    vec_sub_ab(&spD0, pv->b + 0x2C0 + pv->i[0x8DC/4] * 0x10, pv->b + 0x2C0 + temp_s0_2);
                                    fe_func_0038CF68(&spD0, &spD0, 1.1f);
                                    spD0.f[2] = 1.0f;
                                    spD0.f[3] = 5627.925f;
                                    func_L01_00446760(&spE0, m, temp_s7, (f32) pv->b[0x44], &spD0);
                                    spF0.c[9] = 1;
                                    spF0.uh[5] = m->uh[0xAA/2];
                                    spF0.c[8] = 0;
                                    fe_func_003D3CB0(&spB0, &spC0, 9, m, &spE0);
                                    fe_func_003D3CB0(&spB0, pv->b + 0x2C0 + temp_s0_2, 9, m, &spE0);
                                }
                                if ((temp_f0 > 8.0f) && (temp_f0 < 16.0f)) {
                                    fe_func_003C41A0(&sp90.f[2], fe_func_003C3D30((u8 *)m + 0x10, 0, 0, 0.5f) + 3.5f, (u8 *)pv + 0x8E0, 1.09375f, 0.175f, 0.74375004f);
                                }
                                if (temp_f0 == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((temp_f0 > 16.0f) && (temp_f0 < 24.0f)) {
                                    fe_func_003C41A0(&sp90.f[2], fe_func_003C3D30((u8 *)m + 0x10, 0, 0, 0.5f), (u8 *)pv + 0x8E0, 0.036458332f, 0.21875f, 0.65625f);
                                }
                                if ((temp_f0 > 8.0f) && (temp_f0 < 24.0f)) {
                                    vec_sub_ab(&spA0, &sp90, m->b + 0x10);
                                    func_L01_0045AA30(m, &spA0);
                                }
                                if ((func_L01_0044E1B8(m, 28.0f) != 0) && (((G *)D_001A4BE0)->i[0x2850/4] > 0)) {
                                    if ((m->b[0x21] != 0xFF) && (pv->b[0x5F] == 0)) {
                                        func_L01_00445BE0((s32) m->b[0x21], 0);
                                        m->b[0xBC] = 0U;
                                    }
                                    if (fe_func_00382468(2) != 0) {
                                        if (m->b[0x43] != 4) {
                                            fe_func_003C3A10(m, 4, 0, 6);
                                        }
                                        func_L01_004450F0(m, 0x1B, -1);
                                    } else {
                                        if (m->b[0x43] != 3) {
                                            fe_func_003C3A10(m, 3, 0, 6);
                                        }
                                        func_L01_004450F0(m, 0x1C, -1);
                                    }
                                    break;
                                }
                            }
                            break;
                        case 26:                    /* switch 2 */
                            if (m->b[0x42] == 5) {
                                f32 t = func_L01_004395E0(m);
                                if ((t > 8.0f) && (t < 24.0f)) {
                                    fe_func_0038CF68(&spB0, m->b + 0xC0, -0.09375f);
                                    vec_add_ba(&sp90, m->b + 0x10, &spB0);
                                    func_L01_0045BD10(m, fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]));
                                }
                                if ((t > 8.0f) && (t < 16.0f)) {
                                    fe_func_003C41A0(&sp90.f[2], fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f) + D_L06_001DD290, pv->b + 0x8E0, (D_L06_001DD290 * 0.125f) / 1.05f, (D_L06_001DD290 * 0.125f) / 2.1f, D_L06_001DD290 * 0.125f);
                                }
                                if (t == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((t > 16.0f) && (t < 24.0f)) {
                                    f32 h = 0.5f;
                                    fe_func_003C41A0(&sp90.f[2], fe_func_003C3D30(m->b + 0x10, 0, 0, h), pv->b + 0x8E0, (D_L06_001DD290 * 0.125f) / 12.0f, (D_L06_001DD290 * 0.125f) * h, D_L06_001DD290 * 0.125f);
                                }
                                if ((t > 8.0f) && (t < 24.0f)) {
                                    vec_sub_ab(&spA0, &sp90, m->b + 0x10);
                                    func_L01_0045AA30(m, &spA0);
                                }
                                if (func_L01_0044E1B8(m, 34.0f) != 0) {
                                    if (m->b[0x43] != 0x1B) {
                                        fe_func_003C3A10(m, 0x1B, 6, 4);
                                    }
                                    func_L01_004450F0(m, 0x24, -1);
                                }
                            }
                            break;
                        case 27:                    /* switch 2 */
                            if (m->b[0x42] == 4) {
                                f32 t = func_L01_004395E0(m);
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    fe_func_0038CF68(&spB0, m->b + 0xD0, 0.1125f);
                                    vec_add_ba(&sp90, m->b + 0x10, &spB0);
                                    func_L01_0045BD10(m, fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]));
                                }
                                if ((t > 7.0f) && (t < 16.0f)) {
                                    fe_func_003C41A0(&sp90.f[2], fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f) + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if (t == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((t > 16.0f) && (t < 23.0f)) {
                                    fe_func_003C41A0(&sp90.f[2], fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f), pv->b + 0x8E0, 0.023809524f, 0.14285715f, 0.2857143f);
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    vec_sub_ab(&spA0, &sp90, m->b + 0x10);
                                    func_L01_0045AA30(m, &spA0);
                                }
                                if (func_L01_0044E1B8(m, 36.0f) != 0) {
                                    if (m->b[0x43] != 0x10) {
                                        fe_func_003C3A10(m, 0x10, 0, 6);
                                    }
                                    func_L01_004450F0(m, 0x17, -1);
                                    if ((fe_func_0038CF38(m->b + 0x10, pv->b + 0x220) <= 4.2f) && (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                        if (m->b[0x43] != 0xF) {
                                            fe_func_003C3A10(m, 0xF, 0xA, 5);
                                        }
                                        func_L01_004450F0(m, 0x12, -1);
                                    }
                                }
                            }
                            break;
                        case 28:                    /* switch 2 */
                            if (m->b[0x42] == 3) {
                                f32 t = func_L01_004395E0(m);
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    fe_func_0038CF68(&spB0, m->b + 0xD0, -0.1125f);
                                    vec_add_ba(&sp90, m->b + 0x10, &spB0);
                                    func_L01_0045BD10(m, fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]));
                                }
                                if ((t > 7.0f) && (t < 16.0f)) {
                                    fe_func_003C41A0(&sp90.f[2], fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f) + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if (t == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((t > 16.0f) && (t < 23.0f)) {
                                    fe_func_003C41A0(&sp90.f[2], fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f), pv->b + 0x8E0, 0.023809524f, 0.14285715f, 0.2857143f);
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    vec_sub_ab(&spA0, &sp90, m->b + 0x10);
                                    func_L01_0045AA30(m, &spA0);
                                }
                                if (func_L01_0044E1B8(m, 36.0f) != 0) {
                                    if (m->b[0x43] != 0x10) {
                                        fe_func_003C3A10(m, 0x10, 0, 6);
                                    }
                                    func_L01_004450F0(m, 0x17, -1);
                                    if ((fe_func_0038CF38(m->b + 0x10, pv->b + 0x220) <= 4.2f) && (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                        if (m->b[0x43] != 0xF) {
                                            fe_func_003C3A10(m, 0xF, 0xA, 5);
                                        }
                                        func_L01_004450F0(m, 0x12, -1);
                                    }
                                }
                            }
                            break;
                        case 31:                    /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                pv->f[0x92C/4] = (f32) m->f[0xF8/4];
                                pv->f[0x918/4] = (f32) m->f[0x18/4];
                            }
                            if (m->b[0x42] == 5) {
                                sp90.q = m->q[0x10/16];
                                spA0.q = m->q[0x10/16];
                                spA0.f[2] -= 1.0f;
                                sp90.f[2] += 15.0f;
                                if (fe_func_003D3CB0(&spA0, &sp90, 0, m, 0) != 0) {
                                    sp90.q = D_L06_001E8460;
                                }
                                temp_f0_5 = func_L01_004395E0(m);
                                if ((temp_f0_5 > 8.0f) && (temp_f0_5 < 24.0f)) {
                                    spB0.q = m->q[0x10/16];
                                }
                                if ((temp_f0_5 > 8.0f) && (temp_f0_5 < 16.0f)) {
                                    temp_f0_6 = D_L06_001DD290 * 0.125f;
                                    fe_func_003C41A0(&spB0.f[2], sp90.f[2], (u8 *)pv + 0x8E0, temp_f0_6 / 1.05f, temp_f0_6 / 2.1f, temp_f0_6 * 1.3f);
                                }
                                if (temp_f0_5 == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                    m->f[0xF8/4] = fe_func_0038DAB8(m->f[0xF8/4], 3.1415927f);
                                }
                                if ((temp_f0_5 > 16.0f) && (temp_f0_5 < 24.0f)) {
                                    temp_f0_7 = D_L06_001DD290 * 0.125f;
                                    fe_func_003C41A0(&spB0.f[2], sp90.f[2], (u8 *)pv + 0x8E0, temp_f0_7 / 1.05f, temp_f0_7 / 2.1f, temp_f0_7 * 1.3f);
                                }
                                if (temp_f0_5 > 8.0f) {
                                    if (temp_f0_5 < 24.0f) {
                                        fe_func_003C4138((u8 *)m + 0xF4, 3.1415927f, 0.16755162f);
                                    }
                                }
                                if ((temp_f0_5 > 24.0f) && (pv->i[0x930/4] == 0)) {
                                    pv->i[0x8E8/4] = (s32) (pv->i[0x8E8/4] + 1);
                                }
                                if ((temp_f0_5 > 8.0f) && (temp_f0_5 < 24.0f)) {
                                    vec_sub_ba(&spC0, &spB0, m->b + 0x10);
                                    vec_add_ab(m->b + 0x10, m->b + 0x10, &spC0);
                                }
                                if (func_L01_0044E1B8(m, 35.0f) != 0) {
                                    if (m->b[0x43] != 8) {
                                        fe_func_003C3A10(m, 8, 3, 6);
                                    }
                                    func_L01_004450F0(m, 0x26, -1);
                                    if ((pv->i[0x94C/4] != 0) && (pv->h[0x234/2] != 1)) {
                                        func_L01_004450F0(m, 2, 0);
                                        if (m->b[0x43] != 0) {
                                            fe_func_003C3A10(m, 0, 0, 8);
                                        }
                                    }
                                }
                            }
                            break;
                        case 32:                    /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                pv->f[0x92C/4] = (f32) m->f[0xF8/4];
                                pv->f[0x918/4] = (f32) m->f[0x18/4];
                            }
                            if (m->b[0x42] == 5) {
                                var_f22 = D_L06_001DD290;
                                                                if (fabs_asm(pv->f[0x918/4] - fe_func_003C3D30(((u8 *)m + 0x10), 0, 0, 0.1f)) > 16.0f) {
                                    var_f22 = 6.0f;
                                }
                                sp90.q = m->q[0x10/16];
                                spA0.q = m->q[0x10/16];
                                spA0.f[2] += 1.0f;
                                sp90.f[2] -= 5.0f;
                                if (fe_func_003D3CB0(&spA0, &sp90, 2, m, 0) != 0) {
                                    sp90.q = D_L06_001E8460;
                                }
                                temp_f0_8 = func_L01_004395E0(m);
                                if ((temp_f0_8 > 8.0f) && (temp_f0_8 < 24.0f)) {
                                    spB0.q = m->q[0x10/16];
                                }
                                if ((temp_f0_8 > 8.0f) && (temp_f0_8 < 16.0f)) {
                                    temp_f0_9 = var_f22 * 0.125f;
                                    fe_func_003C41A0(&spB0.f[2], sp90.f[2], (u8 *)pv + 0x8E0, temp_f0_9 / 1.05f, temp_f0_9 / 2.1f, temp_f0_9 * 1.4f);
                                }
                                if (temp_f0_8 == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                    m->f[0xF8/4] = fe_func_0038DAB8(m->f[0xF8/4], 3.1415927f);
                                }
                                if ((temp_f0_8 > 16.0f) && (temp_f0_8 < 24.0f)) {
                                    func_L01_0045BD10(m, fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]));
                                    temp_f0_10 = var_f22 * 0.125f;
                                    fe_func_003C41A0(&spB0.f[2], sp90.f[2], (u8 *)pv + 0x8E0, temp_f0_10 / 1.05f, temp_f0_10 / 2.1f, temp_f0_10 * 1.4f);
                                }
                                if (temp_f0_8 > 8.0f) {
                                    if (temp_f0_8 < 24.0f) {
                                        fe_func_003C4138((u8 *)m + 0xF4, 0.0f, 0.16755162f);
                                    }
                                }
                                if ((temp_f0_8 > 24.0f) && (pv->i[0x930/4] == 0)) {
                                    pv->i[0x8E8/4] = (s32) (pv->i[0x8E8/4] + 1);
                                }
                                if ((temp_f0_8 > 8.0f) && (temp_f0_8 < 24.0f)) {
                                    vec_sub_ab(&spC0, &spB0, m->b + 0x10);
                                    func_L01_0045AA30(m, &spC0);
                                }
                                if (func_L01_0044E1B8(m, 35.0f) != 0) {
                                    if (m->b[0x43] != 0xF) {
                                        fe_func_003C3A10(m, 0xF, 0xA, 7);
                                    }
                                    func_L01_004450F0(m, 0x12, -1);
                                    if (fe_func_0038CF38(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) > 3.0f) {
                                        if (m->b[0x43] != 0x1B) {
                                            fe_func_003C3A10(m, 0x1B, 6, 4);
                                        }
                                        func_L01_004450F0(m, 0x24, -1);
                                    }
                                    if (fe_func_0038CF38(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) > 6.0f) {
                                        func_L01_004450F0(m, 0xB, 2);
                                        if (m->b[0x43] != 0xB) {
                                            fe_func_003C3A10(m, 0xB, 0, 8);
                                        }
                                    }
                                }
                            }
                            break;
                        case 29:                    /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                pv->q[0x920/16] = m->q[0xD0/16];
                            }
                            if (m->b[0x42] == 4) {
                                f32 t = func_L01_004395E0(m);
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    f32 k = 0.1125f;
                                    spA0.q = m->q[0x10/16];
                                    fe_func_0038CF68(&spB0, pv->b + 0x920, 3.0f);
                                    vec_add_ba(&spB0, m->b + 0x10, &spB0);
                                    if (fe_func_003D3CB0(m->b + 0x10, &spB0, 0, m, 0) != 0) {
                                        spB0.q = D_L06_001E8460;
                                    } else {
                                        spB0.q = m->q[0x10/16];
                                    }
                                    func_L06_0042B660(&spA0, &spB0, k + k);
                                }
                                if ((t > 7.0f) && (t < 16.0f)) {
                                    fe_func_003C41A0(&spA0.f[2], pv->f[0x918/4] + 2.0f + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if (t == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((t > 16.0f) && (t < 23.0f)) {
                                    fe_func_003C41A0(&spA0.f[2], pv->f[0x918/4] + 2.0f + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    fe_func_003C4138(m->b + 0xF0, 1.5707964f, 0.08377581f);
                                }
                                if ((t > 23.0f) && (pv->i[0x930/4] == 0)) {
                                    pv->i[0x8E8/4]++;
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    vec_sub_ba(&sp90, &spA0, m->b + 0x10);
                                    vec_add_ab(m->b + 0x10, m->b + 0x10, &sp90);
                                }
                                if (func_L01_0044E1B8(m, 35.0f) != 0) {
                                    if (m->b[0x43] != 8) {
                                        fe_func_003C3A10(m, 8, 3, 6);
                                    }
                                    func_L01_004450F0(m, 0x26, -1);
                                }
                            }
                            break;
                        case 33:                    /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                pv->q[0x920/16] = m->q[0xE0/16];
                            }
                            if (m->b[0x42] == 4) {
                                f32 t = func_L01_004395E0(m);
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    U16 *a = &sp90;
                                    U16 *b = &spB0;
                                    u8 *p = m->b + 0x10;
                                    a->q = *(u128_t *)p;
                                    fe_func_0038CF68(b, pv->b + 0x920, 3.0f);
                                    vec_add_ba(b, p, b);
                                    if (fe_func_003D3CB0(p, b, 0, m, 0) != 0) {
                                        b->q = D_L06_001E8460;
                                    }
                                    func_L06_0042B660(a, b, 0.225f);
                                }
                                if ((t > 7.0f) && (t < 16.0f)) {
                                    fe_func_003C41A0(&sp90.f[2], pv->f[0x918/4] + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if (t == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((t > 16.0f) && (t < 23.0f)) {
                                    fe_func_003C41A0(&sp90.f[2], pv->f[0x918/4], pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    fe_func_003C4138(m->b + 0xF0, 0.0f, 0.08377581f);
                                }
                                if ((t > 23.0f) && (pv->i[0x930/4] == 0)) {
                                    pv->i[0x8E8/4]++;
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    vec_sub_ab(&spA0, &sp90, m->b + 0x10);
                                    func_L01_0045AA30(m, &spA0);
                                }
                                if (func_L01_0044E1B8(m, 35.0f) != 0) {
                                    func_L01_004450F0(m, 0xB, 2);
                                    if (m->b[0x43] != 0xB) {
                                        fe_func_003C3A10(m, 0xB, 0, 8);
                                    }
                                    if (pv->i[0x930/4] != 0) {
                                        func_L01_004450F0(m, 0xA, -1);
                                        if (m->b[0x43] != 0xE) {
                                            fe_func_003C3A10(m, 0xE, 0, 8);
                                        }
                                    }
                                }
                            }
                            break;
                        case 30:                    /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                pv->q[0x920/16] = m->q[0xD0/16];
                            }
                            if (m->b[0x42] == 3) {
                                f32 t = func_L01_004395E0(m);
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    f32 k = 0.1125f;
                                    sp90.q = m->q[0x10/16];
                                    fe_func_0038CF68(&spB0, pv->b + 0x920, -3.0f);
                                    vec_add_ba(&spB0, m->b + 0x10, &spB0);
                                    if (fe_func_003D3CB0(m->b + 0x10, &spB0, 0, m, 0) != 0) {
                                        spB0.q = D_L06_001E8460;
                                    } else {
                                        spB0.q = m->q[0x10/16];
                                    }
                                    func_L06_0042B660(&sp90, &spB0, k + k);
                                }
                                if ((t > 7.0f) && (t < 16.0f)) {
                                    fe_func_003C41A0(&sp90.f[2], pv->f[0x918/4] + 2.0f + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if (t == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((t > 16.0f) && (t < 23.0f)) {
                                    fe_func_003C41A0(&sp90.f[2], pv->f[0x918/4] + 2.0f + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    fe_func_003C4138(m->b + 0xF0, -1.5707964f, 0.08377581f);
                                }
                                if ((t > 23.0f) && (pv->i[0x930/4] == 0)) {
                                    pv->i[0x8E8/4]++;
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    vec_sub_ba(&spA0, &sp90, m->b + 0x10);
                                    vec_copy(&sp120, m->b + 0x10);
                                    vec_add_ab(m->b + 0x10, &spA0, &sp120);
                                }
                                if (func_L01_0044E1B8(m, 35.0f) != 0) {
                                    if (m->b[0x43] != 8) {
                                        fe_func_003C3A10(m, 8, 3, 6);
                                    }
                                    func_L01_004450F0(m, 0x26, -1);
                                }
                            }
                            break;
                        case 34:                    /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                pv->q[0x920/16] = m->q[0xE0/16];
                            }
                            if (m->b[0x42] == 3) {
                                f32 t = func_L01_004395E0(m);
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    U16 *a = &sp90;
                                    U16 *b = &spB0;
                                    u8 *p = m->b + 0x10;
                                    a->q = *(u128_t *)p;
                                    fe_func_0038CF68(b, pv->b + 0x920, 3.0f);
                                    vec_add_ba(b, p, b);
                                    if (fe_func_003D3CB0(p, b, 0, m, 0) != 0) {
                                        b->q = D_L06_001E8460;
                                    }
                                    func_L06_0042B660(a, b, 0.225f);
                                }
                                if ((t > 7.0f) && (t < 16.0f)) {
                                    fe_func_003C41A0(&sp90.f[2], pv->f[0x918/4] + 2.0f, pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if (t == 16.0f) {
                                    pv->i[0x8E0/4] = 0;
                                }
                                if ((t > 16.0f) && (t < 23.0f)) {
                                    fe_func_003C41A0(&sp90.f[2], pv->f[0x918/4], pv->b + 0x8E0, 0.22222222f, 0.22222222f, 0.22222222f);
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    fe_func_003C4138(m->b + 0xF0, 0.0f, 0.08377581f);
                                }
                                if ((t > 23.0f) && (pv->i[0x930/4] == 0)) {
                                    pv->i[0x8E8/4]++;
                                }
                                if ((t > 7.0f) && (t < 23.0f)) {
                                    vec_sub_ab(&spA0, &sp90, m->b + 0x10);
                                    func_L01_0045AA30(m, &spA0);
                                }
                                if (func_L01_0044E1B8(m, 35.0f) != 0) {
                                    func_L01_004450F0(m, 0xB, 2);
                                    if (m->b[0x43] != 0xB) {
                                        fe_func_003C3A10(m, 0xB, 0, 8);
                                    }
                                    if (pv->i[0x930/4] != 0) {
                                        func_L01_004450F0(m, 0xA, -1);
                                        if (m->b[0x43] != 0xE) {
                                            fe_func_003C3A10(m, 0xE, 0, 8);
                                        }
                                    }
                                }
                            }
                            break;
                        case 38:                    /* switch 2 */
                            if (m->b[0x60] & 2) {
                                if (m->b[0x43] != 9) {
                                    fe_func_003C3A10(m, 9, 0, 5);
                                }
                                func_L01_004450F0(m, 0x27, -1);
                                break;
                            }
                            break;
                        case 39:                    /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                func_L01_0045BD78(m, 0.0048f, 0.080000006f, 0.010053097f, 0.25132743f);
                                pv->i[0xA8/4] = (s32) (pv->i[0xA8/4] | 4);
                                pv->f[0x78/4] = 0.7f;
                                pv->f[0x7C/4] = 0.7f;
                                m->uh[0x34/2] = (u16) (m->uh[0x34/2] | 0x100);
                                pv->f[0x80/4] = 12.566371f;
                                pv->i[0xA8/4] = (s32) (pv->i[0xA8/4] | 1);
                            }
                            fe_func_0038CF68(&sp90, (u8 *)m + 0xC0, 7.0f);
                            vec_add_ba(&sp90, m->b + 0x10, &sp90);
                            func_L01_0045D218(m, (u8 *)pv + 0x220);
                            if ((fe_func_0038CF38(m->b + 0x10, pv->b + 0x220) < 13.0f) && (pv->i[0x90C/4] == 0)) {
                                if (m->b[0x43] != 0xA) {
                                    fe_func_003C3A10(m, 0xA, 2, 2);
                                }
                                func_L01_004450F0(m, 0x28, -1);
                            }
                            if (pv->i[0x90C/4] != 0) {
                                if (fe_func_0038CF38(m->b + 0x10, pv->b + 0x220) < 2.5f) {
                                    if (m->b[0x43] != 0xA) {
                                        fe_func_003C3A10(m, 0xA, 2, 2);
                                    }
                                    func_L01_004450F0(m, 0x28, -1);
                                    break;
                                }
                            }
                            break;
                        case 40:                    /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                m->uh[0x34/2] = (u16) (m->uh[0x34/2] & 0xFEFF);
                                pv->f[0x74/4] = 0.5f;
                                pv->f[0x70/4] = 0.7f;
                                pv->f[0x78/4] = 0.5f;
                                pv->f[0x7C/4] = 1.0f;
                                pv->f[0x80/4] = 0.7853982f;
                                pv->f[0xA0/4] = 0.34906584f;
                                pv->f[0x9C/4] = 0.00392f;
                                pv->i[0xA8/4] &= ~4;
                                pv->i[0xA8/4] &= ~1;
                            }
                            if ((func_L01_0044E1B8(m, 8.0f) != 0) && (m->b[0x42] == 0xA)) {
                                if (m->b[0x43] != 0) {
                                    fe_func_003C3A10(m, 0, 0, 8);
                                }
                                func_L01_004450F0(m, 0x23, -1);
                                if (pv->i[0x90C/4] != 0) {
                                    sp90.q = m->q[0x10/16];
                                    spA0.q = m->q[0x10/16];
                                    spA0.f[2] += 1.0f;
                                    sp90.f[2] -= 5.0f;
                                    if (fe_func_003D3CB0(&spA0, &sp90, 0, m, 0) != 0) {
                                        if (D_L06_001E8458 == 0) {
                                            func_L01_004450F0(m, 0x20, -1);
                                            if (m->b[0x43] != 5) {
                                                fe_func_003C3A10(m, 5, 5, 3);
                                            }
                                        }
                                    } else {
                                        func_L01_004450F0(m, 0x20, -1);
                                        if (m->b[0x43] != 5) {
                                            fe_func_003C3A10(m, 5, 5, 3);
                                        }
                                    }
                                }
                                temp_a0_4 = pv->i[0x908/4];
                                if (temp_a0_4 == 1) {
                                    func_L01_004450F0(m, 0x21, -1);
                                    if (m->b[0x43] != 4) {
                                        fe_func_003C3A10(m, 4, 0, 5);
                                    }
                                } else if (temp_a0_4 == 2) {
                                    func_L01_004450F0(m, 0x22, -1);
                                    if (m->b[0x43] != 3) {
                                        fe_func_003C3A10(m, 3, 0, 5);
                                    }
                                }
                            }
                            break;
                        case 35:                    /* switch 2 */
                            sp90.q = m->q[0x10/16];
                            spA0.q = m->q[0x10/16];
                            spA0.f[2] += 1.0f;
                            sp90.f[2] -= 5.0f;
                            if (fe_func_003D3CB0(&spA0, &sp90, 0, m, 0) != 0) {
                                if (D_L06_001E8458 == 0) {
                                    func_L01_004450F0(m, 0x20, -1);
                                    if (m->b[0x43] != 5) {
                                        fe_func_003C3A10(m, 5, 5, 3);
                                    }
                                }
                            } else {
                                func_L01_004450F0(m, 0x20, -1);
                                if (m->b[0x43] != 5) {
                                    fe_func_003C3A10(m, 5, 5, 3);
                                }
                            }
                            break;
                        case 10:                    /* switch 2 */
                            if ((func_L01_004395E0(m) > 12.0f) && (m->b[0x42] == 0xE)) {
                                pv->i[0x8E8/4] = (s32) (pv->i[0x8E8/4] + 1);
                            }
                            if ((func_L01_0044E1B8(m, 25.0f) != 0) && (m->b[0x42] == 0xE)) {
                                pv->i[0x8E8/4] = (s32) (pv->i[0x8E8/4] + 1);
                                func_L01_004450F0(m, 0xB, -1);
                                if (m->b[0x43] != 0xB) {
                                    fe_func_003C3A10(m, 0xB, 0, 5);
                                }
                            }
                            break;
                        case 11:                    /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                func_L01_0045BD78(m, 0.0072000003f, 0.16000001f, 0.010053097f, 0.25132743f);
                                pv->f[0xA4/4] = 2.5f;
                            }
                            if (m->b[0x60] & 2) {
                                func_L01_004450F0(m, 0xC, -1);
                                if (m->b[0x43] != 0xC) {
                                    temp_s0_6 = fe_func_00382468(3);
                                    fe_func_003C3A10(m, 0xC, temp_s0_6, (s32) ((fe_func_00382468(4) * 5) + 2) / 6);
                                }
                                temp_v1_2 = pv->i[0x944/4];
                                if (temp_v1_2 != -1) {
                                    func_L01_004450F0(m, 0x10, -1);
                                    break;
                                }
                                temp_a0_5 = pv->i[0x974/4];
                                if ((temp_a0_5 != temp_v1_2) && (D_L06_001DEA4C->e[temp_a0_5].cnt != 0)) {
                                    func_L01_004450F0(m, 0x16, -1);
                                    break;
                                }
                            }
                            break;
                        case 12:                    /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                if ((m->b[0x21] != 0xFF) && (pv->b[0x5F] == 0)) {
                                    func_L01_00445BE0(m->b[0x21], 1);
                                    m->b[0xBC] = 0;
                                }
                                func_L01_00459188(m, pv->p[0x230/4], pv->b + 0x9A0);
                            }
                            func_L01_00458F78(m, pv->b + 0x9A0, 0, 0);
                            func_L01_0045A748(m, pv->b + 0x9A0);
                            if (pv->p[0x230/4] != pv->p[0x9F0/4]) {
                                func_L01_00459188(m, pv->p[0x230/4], pv->b + 0x9A0);
                            }
                            if (fe_func_0038CF38(pv->b + 0x9A0, pv->b + 0x220) < 1.0f) {
                                pv->f[0xA4/4] = 2.5f;
                            } else {
                                pv->f[0xA4/4] = 0.5f;
                            }
                            if (((fe_func_0038CF38(m->b + 0x10, pv->b + 0x220) < 3.5f) && (func_L01_0044E1B8(m, 14.0f) != 0)) || (m->b[0xBC] != 0)) {
                                pv->f[0xA4/4] = 1.5f;
                                func_L01_004450F0(m, 0xD, -1);
                                if (m->b[0x43] != 0xD) {
                                    fe_func_003C3A10(m, 0xD, 0, 4);
                                }
                            }
                            break;
                        case 13:                    /* switch 2 */
                            if (pv->i[0x930/4] == 0) {
                                pv->i[0x8E8/4] = (s32) (pv->i[0x8E8/4] + 1);
                            }
                            if ((func_L01_0044E1B8(m, 3.0f) != 0) && (m->b[0x42] == 0xD)) {
                                if (m->b[0x43] != 0x1C) {
                                    fe_func_003C3A10(m, 0x1C, 0, 5);
                                }
                                func_L01_004450F0(m, 0x14, -1);
                                if ((pv->i[0x930/4] != 0) && (pv->i[0x8E8/4] == 0)) {
                                    func_L01_004450F0(m, 0xA, 2);
                                    if (m->b[0x43] != 0xE) {
                                        fe_func_003C3A10(m, 0xE, 0, 8);
                                    }
                                }
                                if (m->b[0xBC] != 0) {
                                    if (m->b[0x43] != 0) {
                                        fe_func_003C3A10(m, 0, 0, 7);
                                    }
                                    func_L01_004450F0(m, 9, -1);
                                }
                                temp_a0_6 = pv->i[0x974/4];
                                if ((temp_a0_6 != -1) && (D_L06_001DEA4C->e[temp_a0_6].cnt != 0)) {
                                    func_L01_004450F0(m, 0x15, -1);
                                    if (m->b[0x43] != 0x14) {
                                        fe_func_003C3A10(m, 0x14, 0, 0xC);
                                    }
                                }
                            }
                            break;
                        case 9:                     /* switch 2 */
                            if (m->b[0xBC] == 0) {
                                func_L01_004450F0(m, 0xB, -1);
                                if (m->b[0x43] != 0xB) {
                                    fe_func_003C3A10(m, 0xB, 0, 5);
                                }
                            }
                            if (m->b[0x42] == 0) {
                                if (fe_func_00382468(3) == 0) {
                                    if (m->b[0x43] != 0x10) {
                                        fe_func_003C3A10(m, 0x10, 0, 7);
                                    }
                                } else if (fe_func_00382468(2) != 0) {
                                    if (m->b[0x43] != 0x11) {
                                        fe_func_003C3A10(m, 0x11, 0, 7);
                                    }
                                } else if (m->b[0x43] != 0xE) {
                                    fe_func_003C3A10(m, 0xE, 0, 8);
                                }
                            }
                            if ((m->b[0x42] == 0xE) && (m->b[0x60] & 2)) {
                                if (fe_func_00382468(2) == 0) {
                                    if (m->b[0x43] != 0x10) {
                                        fe_func_003C3A10(m, 0x10, 0, 7);
                                    }
                                } else if (m->b[0x43] != 0x11) {
                                    fe_func_003C3A10(m, 0x11, 0, 7);
                                }
                            }
                            if ((m->b[0x42] == 0x10) && (m->b[0x60] & 2)) {
                                if (fe_func_00382468(2) == 0) {
                                    if (m->b[0x43] != 0xE) {
                                        fe_func_003C3A10(m, 0xE, 0, 7);
                                    }
                                } else if (m->b[0x43] != 0x11) {
                                    fe_func_003C3A10(m, 0x11, 0, 7);
                                }
                            }
                            if ((m->b[0x42] == 0x11) && (m->b[0x60] & 2)) {
                                fe_func_00382468(2);
                                if (m->b[0x43] != 0x10) {
                                    fe_func_003C3A10(m, 0x10, 0, 7);
                                }
                            }
                            break;
                        case 14:                    /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                func_L01_0045BD78(m, 0.0032000002f, 0.040000003f, 0.010053097f, 0.25132743f);
                                pv->f[0xA4/4] = 2.5f;
                            }
                            func_L01_0045A748(m, (u8 *)pv + 0x220);
                            if (fe_func_0038CF38(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) <= 2.5f) {
                                if (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f) {
                                    if (m->b[0x43] != 0x1C) {
                                        fe_func_003C3A10(m, 0x1C, 4, 5);
                                    }
                                    func_L01_004450F0(m, 0x14, -1);
                                }
                            }
                            if ((fe_func_0038CF38(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) > 6.0f) || ((u16) m->uh[0x96/2] >= 0xFBU)) {
                                func_L01_004450F0(m, 0xB, 2);
                                if (m->b[0x43] != 0xB) {
                                    fe_func_003C3A10(m, 0xB, 0, 8);
                                }
                            }
                            if (m->b[0xBC] != 0) {
                                func_L01_004450F0(m, 9, -1);
                                if (m->b[0x43] != 0) {
                                    fe_func_003C3A10(m, 0, 0, 8);
                                }
                            }
                            break;
                        case 16:                    /* switch 2 */
                            if (pv->i[0x970/4] != 0) {
                                if (func_L01_004561B8(m) != 0) {
                                    if (m->b[0x43] != 6) {
                                        fe_func_003C3A10(m, 6, 0, 7);
                                    }
                                    func_L01_0045BD78(m, 0.0032000002f, 0.040000003f, 0.010053097f, 0.25132743f);
                                    pv->f[0xA4/4] = 2.5f;
                                }
                                if (func_L01_0045BDE8(m, pv->i[0x944/4]) == 0) {
                                    break;
                                }
                                if (pv->i[0x930/4] == 0) {
                                    pv->i[0x944/4] = -1;
                                    func_L01_004450F0(m, 0xE, -1);
                                    if (m->b[0x43] != 6) {
                                        fe_func_003C3A10(m, 6, 0, 7);
                                    }
                                }
                                if (pv->i[0x930/4] != 0) {
                                    pv->i[0x944/4] = -1;
                                    func_L01_004450F0(m, 0xA, 2);
                                    if (m->b[0x43] != 0xE) {
                                        fe_func_003C3A10(m, 0xE, 0, 8);
                                    }
                                }
                                if (fe_func_0038CF38(m->b + 0x10, pv->b + 0x220) < 3.5f) {
                                    pv->i[0x944/4] = -1;
                                    pv->f[0xA4/4] = 1.5f;
                                    if (m->b[0x43] != 0x1C) {
                                        fe_func_003C3A10(m, 0x1C, 0, 5);
                                    }
                                    func_L01_004450F0(m, 0x14, -1);
                                    break;
                                }
                                {
                                s32 n = pv->i[0x974/4];
                                if ((n != -1) && (D_L06_001DEA4C->e[n].cnt != 0)) {
                                    func_L01_004450F0(m, 0x16, -1);
                                }
                                }
                            } else {
                                if (func_L01_0045BDE8(m, pv->i[0x944/4]) != 0) {
                                    if (pv->i[0x930/4] == 0) {
                                        pv->i[0x944/4] = -1;
                                        func_L01_004450F0(m, 0xC, -1);
                                    }
                                    if ((pv->i[0x930/4] != 0) && (func_L01_0044E1B8(m, 14.0f) != 0)) {
                                        pv->i[0x944/4] = -1;
                                        func_L01_004450F0(m, 0xD, -1);
                                        if (m->b[0x43] != 0xD) {
                                            fe_func_003C3A10(m, 0xD, 0, 4);
                                        }
                                    }
                                    {
                                    s32 n = pv->i[0x974/4];
                                    if ((n != -1) && (D_L06_001DEA4C->e[n].cnt != 0)) {
                                        func_L01_004450F0(m, 0x16, -1);
                                    }
                                    }
                                }
                                if ((fe_func_0038CF38(m->b + 0x10, pv->b + 0x220) < 3.5f) && (func_L01_0044E1B8(m, 14.0f) != 0)) {
                                    pv->i[0x944/4] = -1;
                                    pv->f[0xA4/4] = 1.5f;
                                    func_L01_004450F0(m, 0xD, -1);
                                    if (m->b[0x43] != 0xD) {
                                        fe_func_003C3A10(m, 0xD, 0, 4);
                                    }
                                }
                            }
                            break;
                        case 15:                    /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                func_L01_0045BD78(m, 0.0048f, 0.080000006f, 0.010053097f, 0.25132743f);
                                pv->f[0xA4/4] = 2.5f;
                                func_L01_00459188(m, pv->p[0x230/4], ((u8 *)pv + 0x9A0));
                            }
                            func_L01_00458F78(m, ((u8 *)pv + 0x9A0), 0, 0);
                            func_L01_0045A748(m, ((u8 *)pv + 0x9A0));
                            temp_a1_3 = pv->p[0x230/4];
                            if (temp_a1_3 != pv->i[0x9F0/4]) {
                                func_L01_00459188(m, temp_a1_3, ((u8 *)pv + 0x9A0));
                            }
                            temp_s1_3 = (u8 *)pv + 0x220;
                            if ((fe_func_0038CF38(((u8 *)m + 0x10), temp_s1_3) <= 2.5f) && (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                if (m->b[0x43] != 0xF) {
                                    fe_func_003C3A10(m, 0xF, 0, 5);
                                }
                                func_L01_004450F0(m, 0x12, -1);
                            }
                            if (fe_func_0038CF38(((u8 *)m + 0x10), temp_s1_3) > 8.0f) {
                                func_L01_004450F0(m, 0xB, 2);
                                if (m->b[0x43] != 0xB) {
                                    fe_func_003C3A10(m, 0xB, 0, 8);
                                }
                            }
                            if (m->b[0xBC] != 0) {
                                func_L01_004450F0(m, 9, -1);
                                if (m->b[0x43] != 0) {
                                    fe_func_003C3A10(m, 0, 0, 8);
                                }
                            }
                            break;
                        case 17:                    /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                func_L01_0045BD78(m, 0.0048f, 0.080000006f, 0.010053097f, 0.25132743f);
                            }
                            temp_s0_10 = (u8 *)&D_L06_001DEE80[pv->i[0x95C/4]].pos;
                            var_a1_9 = temp_s0_10;
                            if (fe_func_0038CF38((u8 *)m + 0x10, temp_s0_10) <= 1.0f) {
                                if (!(fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                    temp_v0_8 = pv->p[0x230/4];
                                    func_L01_0045BD10(m, fe_func_0038D160(((G *)(temp_v0_8))->f[0x10/4] - m->f[0x10/4], ((G *)(temp_v0_8))->f[0x14/4] - m->f[0x14/4]));
                                } else {
                                    func_L01_004450F0(m, 0x15, -1);
                                    if (m->b[0x43] != 0x14) {
                                        fe_func_003C3A10(m, 0x14, 0, 0xC);
                                    }
                                }
                            } else {
                                func_L01_0045A748(m, var_a1_9);
                            }
                            break;
                        case 22:                    /* switch 2 */
                            if (func_L01_004561B8(m) != 0) {
                                s32 n;
                                func_L01_0045BD78(m, 0.0072000003f, 0.16000001f, 0.010053097f, 0.25132743f);
                                n = pv->i[0x974/4];
                                if ((n != -1) && (D_L06_001DEA4C->e[n].cnt != 0)) {
                                    s32 k;
                                    *(u128_t *)(pv->b + 0x980) = *(u128_t *)((u8 *)D_L06_001DEE80 + (*D_L06_001DEA4C->e[n].list << 7) + 0x30);
                                    for (k = 0; k < D_L06_001DEA4C->e[pv->i[0x974/4]].cnt; k++) {
                                        E80 *e = &D_L06_001DEE80[D_L06_001DEA4C->e[pv->i[0x974/4]].list[k]];
                                        f32 d = fe_func_0038CF38(&e->pos, pv->b + 0x220);
                                        if (((fe_func_0038CF38(pv->b + 0x980, pv->b + 0x220) < d) || (fe_func_0038CF38(m->b + 0x10, pv->b + 0x980) < 2.0f)) && (fe_func_0038CF38(m->b + 0x10, &e->pos) > 2.0f)) {
                                            pv->q[0x980/16] = e->pos;
                                        }
                                    }
                                }
                                pv->f[0xA4/4] = 0.5f;
                            }
                            if (fe_func_0038CF38(m->b + 0x10, pv->b + 0x980) < 1.0f) {
                                func_L01_0045BD10(m, fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]));
                                if (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.27925268f) {
                                    func_L01_004450F0(m, 0xD, -1);
                                    if (m->b[0x43] != 0xD) {
                                        fe_func_003C3A10(m, 0xD, 0, 4);
                                    }
                                }
                            } else {
                                func_L01_0045A748(m, pv->b + 0x980);
                            }
                            break;
                        case 18:                    /* switch 2 */
                            fe_func_003C2F58(m, 0, &sp90);
                            fe_func_003C2F58(m, 1, &spA0);
                            temp_a1_5 = D_L06_001DD298;
                            temp_s2 = ((pv->i[0x8DC/4] - 2 + temp_a1_5) % temp_a1_5) * 0x10;
                            vec_sub_ab(&spB0, pv->b + 0x2C0 + pv->i[0x8DC/4] * 0x10, pv->b + 0x2C0 + temp_s2);
                            fe_func_0038CF68(&spB0, &spB0, 2.5f);
                            spB0.f[2] = 1.0f;
                            spB0.f[3] = 5627.925f;
                            func_L01_00446760(&spC0, m, temp_s7, (f32) pv->b[0x44], &spB0);
                            spD0.c[9] = 1;
                            spD0.uh[5] = m->uh[0xAA/2];
                            spD0.c[8] = 0;
                            fe_func_003D3CB0(&sp90, &spA0, 9, m, &spC0);
                            vec_copy(&sp140, m->b + 0x10);
                            vec_copy(&sp130, m->b + 0x10);
                            vec_sub_ab(&sp110, pv->b + 0x2C0 + temp_s2, &sp140);
                            vec_sub_ba(&spF0, &spA0, &sp130);
                            func_L01_0044C280(&sp100, &sp110, &spF0, 0, 0.2f);
                            vec_add_ab(&sp100, &sp100, m->b + 0x10);
                            fe_func_003D3CB0(&sp90, &sp100, 9, m, &spC0);
                            func_L01_0044C280(&sp100, &sp110, &spF0, 0, 0.4f);
                            vec_add_ab(&sp100, &sp100, m->b + 0x10);
                            fe_func_003D3CB0(&sp90, &sp100, 9, m, &spC0);
                            func_L01_0044C280(&sp100, &sp110, &spF0, 0, 0.6f);
                            vec_add_ab(&sp100, &sp100, m->b + 0x10);
                            fe_func_003D3CB0(&sp90, &sp100, 9, m, &spC0);
                            func_L01_0044C280(&sp100, &sp110, &spF0, 0, 0.8f);
                            vec_add_ab(&sp100, &sp100, m->b + 0x10);
                            fe_func_003D3CB0(&sp90, &sp100, 9, m, &spC0);
                            fe_func_003D3CB0(&sp90, pv->b + (temp_s2 + 0x2C0), 9, m, &spC0);
                            if ((func_L01_0044E1B8(m, 30.0f) != 0) && (m->b[0x42] == 0xF) && (((G *)D_001A4BE0)->i[0x2850/4] > 0)) {
                                if (fe_func_00382468(4) == 0) {
                                    if (fe_func_00382468(2) != 0) {
                                        if (m->b[0x43] != 0x11) {
                                            fe_func_003C3A10(m, 0x11, 0xD, 7);
                                        }
                                    } else if (m->b[0x43] != 0x10) {
                                        fe_func_003C3A10(m, 0x10, 0xA, 8);
                                    }
                                    func_L01_004450F0(m, 0x17, -1);
                                    if (((G *)D_001A4BE0)->p[0x2808/4] == m) {
                                        if (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.61086524f) {
                                            func_L01_004450F0(m, 0x15, -1);
                                            if (m->b[0x43] != 0x14) {
                                                fe_func_003C3A10(m, 0x14, 0, 0xC);
                                            }
                                        }
                                    }
                                }
                                if (((G *)D_001A4BE0)->p[0x2808/4] != m) {
                                    if ((fe_func_0038CF38(m->b + 0x10, (u8 *)pv + 0x220) <= 2.5f) && (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                        if (m->b[0x43] != 0x13) {
                                            fe_func_003C3A10(m, 0x13, 0xA, 5);
                                        }
                                        func_L01_004450F0(m, 0x13, -1);
                                        break;
                                    }
                                }
                            } else if (m->b[0x60] & 2) {
                                if ((fe_func_0038CF38((u8 *)m + 0x10, (u8 *)pv + 0x220) <= 2.5f) && (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                    if (m->b[0x43] != 0x13) {
                                        fe_func_003C3A10(m, 0x13, 8, 7);
                                    }
                                    func_L01_004450F0(m, 0x13, -1);
                                    break;
                                }
                                if (m->b[0x43] != 6) {
                                    fe_func_003C3A10(m, 6, 0, 8);
                                }
                                func_L01_004450F0(m, 0xE, -1);
                                if (fe_func_00382468(5) == 0) {
                                    if (m->b[0x43] != 0x1B) {
                                        fe_func_003C3A10(m, 0x1B, 6, 4);
                                    }
                                    func_L01_004450F0(m, 0x24, -1);
                                }
                                if ((((G *)D_001A4BE0)->p[0x2808/4] == m) && (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.61086524f)) {
                                    func_L01_004450F0(m, 0x15, -1);
                                    if (m->b[0x43] != 0x14) {
                                        fe_func_003C3A10(m, 0x14, 0, 0xC);
                                    }
                                }
                            }
                            break;
                        case 20:                    /* switch 2 */
                            if ((func_L01_0044E1B8(m, 30.0f) != 0) && (m->b[0x42] == 0x1C) && (((G *)D_001A4BE0)->i[0x2850/4] > 0)) {
                                if ((((G *)D_001A4BE0)->p[0x2808/4] != m) && (fe_func_0038CF38((u8 *)m + 0x10, (u8 *)pv + 0x220) <= 2.5f) && (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                    func_L01_004450F0(m, 0x13, -1);
                                    if (m->b[0x43] != 0x13) {
                                        fe_func_003C3A10(m, 0x13, 8, 5);
                                    }
                                } else {
                                    if (m->b[0x43] != 0x1B) {
                                        fe_func_003C3A10(m, 0x1B, 0, 0xC);
                                    }
                                    func_L01_004450F0(m, 0x24, -1);
                                }
                            }
                            if ((func_L01_004395E0(m) > 12.0f) && (m->b[0x42] == 0x1C)) {
                                func_L01_004468C8(m, 8, 0.25f, (f32) pv->b[0x45], temp_s7, 2.5f, 0, 1, 0);
                                func_L01_004468C8(m, 9, 0.45f, (f32) pv->b[0x45], temp_s7, 2.5f, 0, 1, 0);
                                func_L01_004468C8(m, 7, 0.75f, (f32) pv->b[0x45], temp_s7, 2.5f, 0, 1, 0);
                            }
                            break;
                        case 19:                    /* switch 2 */
                            if (m->b[0x42] != m->b[0x43]) {
                                temp_v0_9 = pv->p[0x230/4];
                                func_L01_0045BD10(m, fe_func_0038D160(((G *)(temp_v0_9))->f[0x10/4] - m->f[0x10/4], ((G *)(temp_v0_9))->f[0x14/4] - m->f[0x14/4]));
                            }
                            if (func_L01_004395E0(m) < 20.0f) {
                                func_L01_004468C8(m, 4, 0.3f, (f32) pv->b[0x46], temp_s7, 2.0f, 0, 1, 0);
                            }
                            if ((func_L01_0044E1B8(m, 25.0f) != 0) && (m->b[0x42] == 0x13) && (((G *)D_001A4BE0)->i[0x2850/4] > 0)) {
                                if (((G *)D_001A4BE0)->p[0x2808/4] != m) {
                                    func_L01_004450F0(m, 0x1A, -1);
                                    if (m->b[0x43] != 5) {
                                        fe_func_003C3A10(m, 5, 5, 3);
                                    }
                                    break;
                                }
                                if (m->b[0x43] != 0x1B) {
                                    fe_func_003C3A10(m, 0x1B, 0, 0xC);
                                }
                                func_L01_004450F0(m, 0x24, -1);
                                break;
                            }
                            break;
                        case 21:                    /* switch 2 */
                            if ((func_L01_0044E1B8(m, 15.5f) != 0) && (m->b[0x42] == 0x14)) {
                                fe_func_003C2F58(m, 4, &spA0);
                                vec_sub_ab(&sp90, pv->b + 0x220, &spA0);
                                fe_func_0038CF68(&sp90, &sp90, 0.50000006f);
                                if (pv->b[0x5F] != 0) {
                                    fe_func_0038CF68(&sp90, &sp90, 1.0000001f);
                                }
                                func_L06_003584D0(m, &sp90, &spA0, (u8 *)m + 0xF0, 1, 0, (f32) pv->b[0x46]);
                            }
                            if (func_L01_0044E1B8(m, 26.0f) != 0) {
                                if (m->b[0x42] == 0x14) {
                                    temp_s1_5 = (u8 *)pv + 0x220;
                                    if (fe_func_0038CF38(((u8 *)m + 0x10), temp_s1_5) > 6.0f) {
                                        func_L01_004450F0(m, 0xB, 2);
                                        if (m->b[0x43] != 0xB) {
                                            fe_func_003C3A10(m, 0xB, 0, 5);
                                        }
                                    } else {
                                        if (m->b[0x43] != 6) {
                                            fe_func_003C3A10(m, 6, 0, 8);
                                        }
                                        func_L01_004450F0(m, 0xE, -1);
                                    }
                                    if (fe_func_0038CF38(((u8 *)m + 0x10), temp_s1_5) < 8.0f) {
                                        if (m->b[0x43] != 0x1B) {
                                            fe_func_003C3A10(m, 0x1B, 0, 0xC);
                                        }
                                        func_L01_004450F0(m, 0x24, -1);
                                    }
                                    if (pv->i[0x95C/4] != -1) {
                                        func_L01_004450F0(m, 0x11, -1);
                                        if (m->b[0x43] != 7) {
                                            fe_func_003C3A10(m, 7, 0, 5);
                                        }
                                    }
                                    temp_a0_10 = pv->i[0x974/4];
                                    if ((temp_a0_10 != -1) && (D_L06_001DEA4C->e[temp_a0_10].cnt != 0)) {
                                        func_L01_004450F0(m, 0xB, 2);
                                        if (m->b[0x43] != 0xB) {
                                            fe_func_003C3A10(m, 0xB, 0, (s32) (((fe_func_003824E0(6.0f, 12.0f) * 5.0f) + 2.0f) / 6.0f));
                                        }
                                    }
                                }
                            }
                            break;
                        case 23:                    /* switch 2 */
                            temp_v1_7 = m->b[0x42];
                            if (temp_v1_7 == 0x10) {
                                if (m->b[0x60] & 2) {
                                    if (m->b[0x43] != 6) {
                                        fe_func_003C3A10(m, 6, 0, 7);
                                    }
                                    func_L01_004450F0(m, 0xE, -1);
                                    if ((fe_func_0038CF38(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) <= 2.5f) && (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                        if (m->b[0x43] != 0x13) {
                                            fe_func_003C3A10(m, 0x13, 8, 7);
                                        }
                                        func_L01_004450F0(m, 0x13, -1);
                                    }
                                    if (fe_func_0038CF38(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) > 6.0f) {
                                        if (m->b[0x43] != 7) {
                                            fe_func_003C3A10(m, 7, 0, 7);
                                        }
                                        func_L01_004450F0(m, 0xF, -1);
                                        break;
                                    }
                                }
                            } else if (temp_v1_7 == 0x11) {
                                if (func_L01_0044E1B8(m, 38.0f) != 0) {
                                    if (m->b[0x43] != 6) {
                                        fe_func_003C3A10(m, 6, 0, 7);
                                    }
                                    func_L01_004450F0(m, 0xE, -1);
                                    if ((fe_func_0038CF38(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) <= 2.5f) && (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                        if (m->b[0x43] != 0xF) {
                                            fe_func_003C3A10(m, 0xF, 0xA, 5);
                                        }
                                        func_L01_004450F0(m, 0x12, -1);
                                    }
                                    if (fe_func_0038CF38(((u8 *)m + 0x10), ((u8 *)pv + 0x220)) > 6.0f) {
                                        if (m->b[0x43] != 7) {
                                            fe_func_003C3A10(m, 7, 0, 7);
                                        }
                                        func_L01_004450F0(m, 0xF, -1);
                                        break;
                                    }
                                }
                            } else {
                                if (m->b[0x60] & 2) {
                                    if (m->b[0x43] != 6) {
                                        fe_func_003C3A10(m, 6, 0, 7);
                                    }
                                    func_L01_004450F0(m, 0xE, -1);
                                    if ((fe_func_0038CF38((u8 *)m + 0x10, (u8 *)pv + 0x220) <= 2.5f) && (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.43633232f)) {
                                        if (m->b[0x43] != 0xF) {
                                            fe_func_003C3A10(m, 0xF, 0xA, 5);
                                        }
                                        func_L01_004450F0(m, 0x12, -1);
                                        break;
                                    }
                                }
                            }
                            break;
                        case 24:                    /* switch 2 */
                            if ((func_L01_0044E1B8(m, 27.0f) != 0) && (m->b[0x42] == 0x12)) {
                                pv->i[0x8E8/4] = 0;
                                if (m->b[0x43] != 0) {
                                    fe_func_003C3A10(m, 0, 0, 7);
                                }
                                func_L01_004450F0(m, 0x19, -1);
                                break;
                            }
                            break;
                        case 25:                    /* switch 2 */
                            func_L01_0045BD10(m, fe_func_0038D160(((G *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((G *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
                            break;
    }
    func_L06_0034FDA8(m);
}