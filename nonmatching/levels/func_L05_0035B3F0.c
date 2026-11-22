/* func_L05_0035B3F0 (PAL): 1265 differences (tools/check.py, level 05, its file's flags; the same at level 10).
 * With the divs_nops row `func_L05_0035B3F0 2 0 0` (retail pads the first of its three div.s, in state 7, with
 * two nops; the row is not committed because the function does not match) check.py gives 519 at levels 05 and 10.
 * Draft by Promises (2026-11-22), written by hand from the assembly: the AI state update of a level 5 enemy, a
 * four-way pre-switch on byte 0x95 and a 14-state switch on byte 0x20 (jump table, state 13 empty), then the
 * stuck-timer tail (distance moved < 0.06 in states 5/6 counts 0x2E4 up, else func_0038CAD0).
 * Same length as retail (1705 words) with the row; an opcode alignment of check.py's output leaves 7 places:
 * - the copy of o+0x10 that state 5's loop passes to func_0038CF38 ($s1 = $s7): retail makes it in the loop's
 *   preheader, this C at the top of the function, so about 495 words in between are one word out of step
 *   (most of the 519); retail also keeps v+0x2F0 in a stack slot at sp+0x80 there, this C in $fp, and its
 *   loop pointer starts at v+0x340 in the preheader (the pointer-local and index forms tried move it);
 * - state 14: retail copies v->3AC into $f2 in the first fabs test's delay slot, and in the second test sets
 *   $a0 (&t.z) in the first branch's delay slot for both calls (this C once per call).
 * Notes: func_0038CB00 and func_0038CAD0 are declared void earlier in the file but this function uses their
 * results, so the draft calls them through a cast (a match would need those declarations changed).
 * func_L01_0046B458 uses the prototype of upstream's other callers (void *, s32, f32, f32, s32, s32, s32,
 * void *, f32, s32): with it the two calls in state 8 schedule as retail's. The $gp globals carry
 * `.extern X, 4` hints; D_L05_001D66B0 is u8[8] with `.extern D_L05_001D66B0, 16`, as in L05_003DB1C0.c,
 * so its address is loaded again for each call as in retail; n and w in state 7 are scoped locals. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_0035B3F0 */
extern u8 *D_L05_001EA6D8[];
extern u8 *D_L05_001DFC80;
extern u8 *D_L05_0021ED80[];
extern u8 D_L05_001D66B0[8];
__asm__(".extern D_L05_001D66B0, 16");
extern f32 D_L05_001DD720;
__asm__(".extern D_L05_001DD720, 4");
extern f32 D_L05_001DD724;
__asm__(".extern D_L05_001DD724, 4");
extern f32 D_L05_001DD728;
__asm__(".extern D_L05_001DD728, 4");
extern f32 D_L05_001DD72C;
__asm__(".extern D_L05_001DD72C, 4");
extern f32 D_L05_001DD730;
__asm__(".extern D_L05_001DD730, 4");
extern f32 D_L05_001DD734;
__asm__(".extern D_L05_001DD734, 4");
extern f32 D_L05_001DD738;
__asm__(".extern D_L05_001DD738, 4");
extern f32 D_L05_001DD73C;
__asm__(".extern D_L05_001DD73C, 4");
extern s32 D_L05_001DD744;
__asm__(".extern D_L05_001DD744, 4");
extern s32 D_L05_001DD748;
__asm__(".extern D_L05_001DD748, 4");
extern f32 D_L05_001DD7A0;
__asm__(".extern D_L05_001DD7A0, 4");
extern s32 func_L05_0035CE98(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_L05_0035E820(void *);
extern s32 func_L01_00454370(void *, void *);
extern void func_L05_0035D300(void *);
extern void func_L01_00315900(void *, s32, s32);
extern void func_003C2880(u8 *);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_004561B8(void *);
extern f32 func_L01_004395E0(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0045BD10(void *, f32);
extern void func_003C41A0(void *, void *, f32, f32, f32, f32);
extern void func_L01_0045AA30(void *, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0045BE38(void *, void *);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L05_0035E148(void *, f32);
extern void func_L05_0035E5A8(void *);
extern void func_L01_0045A748(void *, void *);
extern s32 func_L05_0035E6C8(void *);
extern s32 func_L05_0035E640(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_L01_0045AA10(void *, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_L05_00362E38(void *, void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern void func_003C2F58(s32, s32, void *);
extern s32 func_00382468(s32);
extern f32 func_L01_00447878(void *, void *, s32, f32, f32);
extern u8 *func_L05_0032B880(void *, void *, void *, f32);
extern void func_L01_004468C8(void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L05_0035D388(void *);
extern void func_0038CAD0(void *);
extern void func_0038CB00(void *);

void func_L05_0035B3F0(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    vu0_v4 p;
    vu0_v4 t;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 m[4];
    f32 fr;
    s32 r;
    s32 i;
    u8 *e;
    u8 *pos;
    u8 **pp;

    if (func_L05_0035CE98(o) != 0) {
        return;
    }
    p = *(vu0_v4 *)(o + 0x10);
    pos = o + 0x10;
    switch (o[0x95]) {
    case 0:
        if (*(s16 *)(v + 0x234) == 1) {
            if (o[0x43] != 4) {
                func_003C3A10(o, 4, 0, 8);
            }
            func_L01_004450F0(o, 6, 2);
            if (*(s32 *)(v + 0x3C0) != -1) {
                func_L05_0035E820(o);
                func_L01_004450F0(o, 0xC, -1);
            }
        } else if (*(s32 *)(v + 0x2D8) != 0) {
            if (((s32 (*)(void *))func_0038CB00)(v + 0x2D6) != 0) {
                func_L01_004450F0(o, 4, 1);
            }
        }
        break;
    case 1:
        if (*(s16 *)(v + 0x234) == 1) {
            func_L01_004450F0(o, 8, 2);
        } else if (*(s32 *)(v + 0x2D0) == 0) {
            func_L01_004450F0(o, 1, 0);
        }
        break;
    case 2:
        if (*(s16 *)(v + 0x234) != 1) {
            func_L01_004450F0(o, 4, 1);
        }
        break;
    case 3:
        r = func_L01_00454370(o, v + 0x160);
        if (r & 1) {
            func_L05_0035D300(o);
            func_L01_00315900(o, 0, 0);
            func_003C2880(o);
            return;
        }
        if (r & 2) {
            if (*(s16 *)(v + 0x234) == 1) {
                func_L01_004450F0(o, 8, 2);
                if (func_0038CF38(pos, *(u8 **)(v + 0x230) + 0x10) < 2.0f) {
                    if (o[0x43] != 9) {
                        func_003C3A10(o, 9, 5, 2);
                    }
                    func_L01_004450F0(o, 0xB, -1);
                }
            } else {
                func_L01_004450F0(o, 4, 1);
                *(s32 *)(v + 0x2D0) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    }

    switch (o[0x20]) {
    case 1:
        if (func_L01_004561B8(o) != 0 && o[0x43] != 0) {
            func_003C3A10(o, 0, 0, 8);
        }
        break;
    case 4:
        if (func_L01_004561B8(o) != 0) {
            if (o[0x43] != 0) {
                func_003C3A10(o, 0, 0, 8);
            }
            *(s32 *)(v + 0x2D8) = 0;
            if (*(s32 *)(v + 0x2D0) < 250) {
                *(s32 *)(v + 0x2D0) = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    case 14:
        if (func_L01_004561B8(o) != 0) {
            *(f32 *)(v + 0x3B8) = *(f32 *)(o + 0x18);
        }
        if (o[0x42] == 2) {
            f32 fr = func_L01_004395E0(o);
            if (7.0f < fr && fr < 19.0f) {
                func_0038CF68(&b, o + 0xC0, 0.125f);
                vec_add_ba(&t, o + 0x10, &b);
                func_L01_0045BD10(o, func_0038D160(*(f32 *)(v + 0x220) - *(f32 *)(o + 0x10),
                                                   *(f32 *)(v + 0x224) - *(f32 *)(o + 0x14)));
            }
            if (7.0f < fr && fr < 13.0f) {
                f32 c = *(f32 *)(v + 0x3AC);
                f32 d = *(f32 *)(v + 0x3B8);
                if (c < d && 1.0f < fabs_asm(c - d)) {
                    func_003C41A0(&t.z, v + 0x3A8, c + 3.0f + 1.0f, 0.05f, 0.23809525f, 0.5f);
                } else {
                    func_003C41A0(&t.z, v + 0x3A8, c + 3.0f, 0.05f, 0.23809525f, 0.5f);
                }
            }
            if (fr == 13.0f) {
                *(s32 *)(v + 0x3A8) = 0;
            }
            if (13.0f < fr && fr < 19.0f) {
                f32 c = *(f32 *)(v + 0x3AC);
                f32 d = *(f32 *)(v + 0x3B8);
                if (c < d && 1.0f < fabs_asm(c - d)) {
                    func_003C41A0(&t.z, v + 0x3A8, c, 0.071428575f, 0.25f, 0.6f);
                } else {
                    func_003C41A0(&t.z, v + 0x3A8, c, 0.05f, 0.25f, 0.5f);
                }
            }
            if (7.0f < fr && fr < 19.0f) {
                vec_sub_ab(&a, &t, o + 0x10);
                func_L01_0045AA30(o, &a);
            }
            if (o[0x60] & 2) {
                if (o[0x43] != 4) {
                    func_003C3A10(o, 4, 0, 8);
                }
                func_L01_004450F0(o, 6, 2);
            }
        }
        break;
    case 2:
        func_L01_0045BD78(o, 0.0042000003f, 0.060000002f, 0.010053097f, 0.25132743f);
        if (func_L01_0045BE38(o, D_L05_0021ED80[*(s32 *)(v + 0x3A0)]) != 0) {
            func_L01_004450F0(o, 3, -1);
            if (o[0x43] != 1) {
                func_003C3A10(o, 1, 0, 0x11);
            }
        }
        break;
    case 3:
        if (o[0x60] & 2) {
            u8 *path = D_L05_0021ED80[*(s32 *)(v + 0x3A0)];
            fr = func_0038CF38(pos, path + 0x10);
            if (func_0038CF38(pos, path + *(s32 *)path * 16) < fr) {
                func_L01_0045C150(o, D_L05_0021ED80[*(s32 *)(v + 0x3A0)], 0, *(s32 *)path - 1);
            } else {
                func_L01_0045C150(o, D_L05_0021ED80[*(s32 *)(v + 0x3A0)], *(s32 *)path - 1, 0);
            }
            func_L01_004450F0(o, 2, -1);
            if (o[0x43] != 3) {
                func_003C3A10(o, 3, 0, 0x11);
            }
        }
        break;
    case 5:
        pp = (u8 **)(v + 0x340);
        if (func_L01_004561B8(o) != 0) {
            func_L01_0045BD78(o, 0.0096f, 0.15f, 0.010053097f, 0.25132743f);
            *(vu0_v4 *)(v + 0x390) = *(vu0_v4 *)(pp[0] + 0x10);
            for (i = 0; i < *(s32 *)(v + 0x380); i++) {
                fr = func_0038CF38(o + 0x10, pp[i] + 0x10);
                if (fr < func_0038CF38(o + 0x10, v + 0x390)) {
                    *(vu0_v4 *)(v + 0x390) = *(vu0_v4 *)(pp[i] + 0x10);
                }
            }
            *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(v + 0x300) = *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(v + 0x390);
            func_L05_0035E148(o, 4.0f);
        }
        func_L05_0035E5A8(o);
        t = *(vu0_v4 *)(v + 0x390);
        if (1.0f < func_0038CF38(v + 0x310, &t)) {
            *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(v + 0x390);
            func_L05_0035E148(o, 4.0f);
            *(s32 *)(v + 0x2E4) = 0;
        }
        *(vu0_v4 *)(v + 0x300) = *(vu0_v4 *)(v + 0x390);
        if (*(s32 *)(v + 0x2E4) >= 5 || func_0038CF38(pos, v + 0x2F0) <= *(f32 *)(v + 0xA4)) {
            *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(v + 0x390);
            func_L05_0035E148(o, 4.0f);
            *(s32 *)(v + 0x2E4) = 0;
        }
        func_L01_0045A748(o, v + 0x2F0);
        if (func_0038CF38(pos, v + 0x390) <= *(f32 *)(v + 0xA4)) {
            if (*(s16 *)(v + 0x3D2) != 0) {
                *(s32 *)(v + 0x384) = 1;
                if (o[0x43] != 5) {
                    func_003C3A10(o, 5, 0, 8);
                }
                func_L01_004450F0(o, 7, -1);
            } else {
                *(s32 *)(v + 0x384) = 1;
                if (o[0x43] != 8) {
                    func_003C3A10(o, 8, 0, 8);
                }
                func_L01_004450F0(o, 9, -1);
            }
        }
        break;
    case 6:
        if (func_L01_004561B8(o) != 0) {
            *(s32 *)(v + 0x384) = 0;
            func_L01_0045BD78(o, 0.0096f, 0.15f, 0.010053097f, 0.25132743f);
            *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(v + 0x300) = *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(v + 0x220);
            func_L05_0035E148(o, 15.0f);
        }
        func_L05_0035E5A8(o);
        t = *(vu0_v4 *)(v + 0x220);
        if (1.0f < func_0038CF38(v + 0x310, &t)) {
            *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(v + 0x220);
            func_L05_0035E148(o, 15.0f);
            *(s32 *)(v + 0x2E4) = 0;
        }
        *(vu0_v4 *)(v + 0x300) = *(vu0_v4 *)(v + 0x220);
        if (*(s32 *)(v + 0x2E4) >= 3) {
            r = func_L05_0035E6C8(o);
            if (r == 1) {
                func_L01_004450F0(o, 0xE, -1);
                if (o[0x43] != 2) {
                    func_003C3A10(o, 2, 0, 4);
                }
            } else if (r != 2) {
                *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(v + 0x220);
                func_L05_0035E148(o, 15.0f);
                *(s32 *)(v + 0x2E4) = 0;
            }
        }
        func_L01_0045A748(o, v + 0x2F0);
        if (func_0038CF38(pos, *(u8 **)(v + 0x230) + 0x10) < 8.0f && func_L05_0035E640(o) != 0 &&
            *(s16 *)(v + 0x3D0) == 0) {
            if (o[0x43] != 5) {
                func_003C3A10(o, 5, 0, 8);
            }
            func_L01_004450F0(o, 7, -1);
            a = *(vu0_v4 *)(o + 0x10);
            b = *(vu0_v4 *)(v + 0x220);
            a.z += *(f32 *)(v + 0x78);
            if (func_003D3CB0(&a, &b, 0, o, 0) != 0 && *(u8 **)(v + 0x230) != D_L05_001EA6D8[0] &&
                *(s16 *)(v + 0x3D2) == 0) {
                if (o[0x43] != 8) {
                    func_003C3A10(o, 8, 0, 8);
                }
                func_L01_004450F0(o, 9, -1);
            }
        }
        if (func_0038CF38(pos, *(u8 **)(v + 0x230) + 0x10) < 2.0f) {
            if (o[0x43] != 9) {
                func_003C3A10(o, 9, 0, 8);
            }
            func_L01_004450F0(o, 0xB, -1);
        }
        break;
    case 12:
        e = D_L05_001DFC80 + ((s32 *)(v + 0x3C0))[*(s32 *)(v + 0x3D4)] * 0x80;
        if (func_L01_004561B8(o) != 0) {
            *(s32 *)(v + 0x384) = 0;
            func_L01_0045BD78(o, 0.0096f, 0.15f, 0.010053097f, 0.25132743f);
            *(vu0_v4 *)(v + 0x300) = *(vu0_v4 *)(e + 0x30);
            *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(e + 0x30);
            *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(e + 0x30);
            func_L05_0035E148(o, 15.0f);
        }
        func_L05_0035E5A8(o);
        t = *(vu0_v4 *)(v + 0x220);
        if (1.0f < func_0038CF38(v + 0x310, &t)) {
            *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(e + 0x30);
            *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(e + 0x30);
            func_L05_0035E148(o, 15.0f);
            *(s32 *)(v + 0x2E4) = 0;
        }
        *(vu0_v4 *)(v + 0x300) = *(vu0_v4 *)(e + 0x30);
        if (*(s32 *)(v + 0x2E4) >= 3) {
            r = func_L05_0035E6C8(o);
            if (r == 1) {
                func_L01_004450F0(o, 0xE, -1);
                if (o[0x43] != 2) {
                    func_003C3A10(o, 2, 0, 4);
                }
            } else if (r != 2) {
                *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(e + 0x30);
                *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(e + 0x30);
                func_L05_0035E148(o, 15.0f);
                *(s32 *)(v + 0x2E4) = 0;
            }
        }
        func_L01_0045A748(o, v + 0x2F0);
        if (func_0038CF38(pos, e + 0x30) < 0.5f) {
            if (o[0x43] != 5) {
                func_003C3A10(o, 5, 0, 8);
            }
            func_L01_004450F0(o, 7, -1);
            a = *(vu0_v4 *)(o + 0x10);
            b = *(vu0_v4 *)(v + 0x220);
            a.z += *(f32 *)(v + 0x78);
            if (func_003D3CB0(&a, &b, 0, o, 0) != 0 && *(u8 **)(v + 0x230) != D_L05_001EA6D8[0] &&
                *(s16 *)(v + 0x3D2) == 0) {
                if (o[0x43] != 8) {
                    func_003C3A10(o, 8, 0, 8);
                }
                func_L01_004450F0(o, 9, -1);
            }
        }
        if (func_0038CF38(pos, *(u8 **)(v + 0x230) + 0x10) < 2.0f) {
            if (o[0x43] != 9) {
                func_003C3A10(o, 9, 0, 8);
            }
            func_L01_004450F0(o, 0xB, -1);
        }
        break;
    case 7:
        if (func_L01_004561B8(o) != 0) {
            f32 n;
            f32 w;
            func_L01_00443B88(v + 0x330, -D_L05_001DD734, D_L05_001DD734);
            n = (D_L05_001DD728 + D_L05_001DD72C) * 5.0f + 2.0f;
            w = D_L05_001DD730;
            *(f32 *)(v + 0x338) = -D_L05_001DD738;
            *(s32 *)(v + 0x2E0) = n / 6.0f;
            *(f32 *)(o + 0x48) = w;
        }
        func_L01_0045AA10(o, func_0038D160(*(f32 *)(*(u8 **)(v + 0x230) + 0x10) - *(f32 *)(o + 0x10),
                                           *(f32 *)(*(u8 **)(v + 0x230) + 0x14) - *(f32 *)(o + 0x14)));
        if (func_0038CF38(pos, *(u8 **)(v + 0x230) + 0x10) < 3.0f) {
            if (o[0x43] != 9) {
                func_003C3A10(o, 9, 0, 8);
            }
            func_L01_004450F0(o, 0xB, -1);
        }
        if (*(s32 *)(v + 0x3DC) == *(s32 *)(v + 0x230)) {
            fr = (D_L05_001DD72C * 5.0f + 2.0f) / 6.0f;
            if (fr < (f32)*(s32 *)(v + 0x2E0)) {
                *(s32 *)(v + 0x2E0) = fr;
            }
        }
        if (((s32 (*)(void *))func_0038CAD0)(v + 0x2E0) != 0) {
            if (o[0x43] != 6) {
                func_003C3A10(o, 6, 0, 3);
            }
            func_L01_004450F0(o, 8, -1);
        }
        break;
    case 8:
        if (func_L01_0044E1B8(o, 2.5f) != 0) {
            f32 k;
            func_003C2EC0(o, 0, m);
            func_0038D028(&t, &D_L05_001DD7A0, m);
            vec_add_ba(&t, &m[3], &t);
            vec_sub_ba(&a, v + 0x220, &t);
            func_L05_00362E38(o, &t, &a, (f32)v[0x44]);
            k = func_003824E0(8.0f, 10.0f);
            func_L01_0046B458(&t, 0x19, k * 0.3f, k, 0xAF40DF20, 0, 10, D_L05_001D66B0, 0.0f, 0);
            func_L01_0046B458(&t, 0x19, k * 0.04f, k * 0.4f, 0x20FFFFFF, 1, -10, D_L05_001D66B0, 0.0f, 0);
        }
        if (o[0x60] & 2) {
            func_003C2F58((s32)o, 6, &t);
            if (func_003D3CB0(&t, v + 0x220, 0, o, 0) != 0 && *(u8 **)(v + 0x230) != D_L05_001EA6D8[0] &&
                *(s16 *)(v + 0x3D2) == 0) {
                if (o[0x43] != 8) {
                    func_003C3A10(o, 8, 0, 8);
                }
                func_L01_004450F0(o, 9, -1);
            } else if (func_0038CF38(pos, *(u8 **)(v + 0x230) + 0x10) < 13.0f && func_L05_0035E640(o) != 0) {
                if (o[0x43] != 5) {
                    func_003C3A10(o, 5, 0, 8);
                }
                func_L01_004450F0(o, 7, -1);
                a = *(vu0_v4 *)(o + 0x10);
                b = *(vu0_v4 *)(v + 0x220);
                a.z += *(f32 *)(v + 0x78);
                if (func_003D3CB0(&a, &b, 0, o, 0) != 0 && *(u8 **)(v + 0x230) != D_L05_001EA6D8[0] &&
                    *(s32 *)(v + 0x340) != 0) {
                    if (o[0x43] != 4) {
                        func_003C3A10(o, 4, 0, 8);
                    }
                    func_L01_004450F0(o, 5, -1);
                }
            } else if (*(s32 *)(v + 0x3C0) == -1) {
                if (o[0x43] != 4) {
                    func_003C3A10(o, 4, 0, 8);
                }
                func_L01_004450F0(o, 6, -1);
            }
            if (*(s32 *)(v + 0x3C0) != -1) {
                if (func_0038CF38(pos, v + 0x220) < 13.0f) {
                    func_L05_0035E820(o);
                    if (o[0x43] != 4) {
                        func_003C3A10(o, 4, 0, 8);
                    }
                    func_L01_004450F0(o, 0xC, -1);
                } else {
                    func_L01_004450F0(o, 7, -1);
                    if (o[0x43] != 5) {
                        func_003C3A10(o, 5, 0, 8);
                    }
                }
            }
            if (func_00382468(3) != 0 || *(s16 *)(v + 0x3D2) != 0) {
                if (o[0x43] != 7) {
                    func_003C3A10(o, 7, 0, 5);
                }
                *(s32 *)(v + 0x2D0) = func_00382468(200) + 200;
                func_L01_004450F0(o, 0xA, -1);
            }
            if (func_0038CF38(pos, *(u8 **)(v + 0x230) + 0x10) < 2.0f) {
                if (o[0x43] != 9) {
                    func_003C3A10(o, 9, 0, 8);
                }
                func_L01_004450F0(o, 0xB, -1);
            }
        }
        break;
    case 11: {
        f32 fr;
        if (func_L01_004561B8(o) != 0) {
            func_L01_0045BD78(o, D_L05_001DD724 * 0.00040000002f, D_L05_001DD720 * 0.020000001f, 0.010053097f,
                              0.25132743f);
        }
        if (o[0x60] & 2) {
            func_L01_004450F0(o, 6, -1);
            if (o[0x43] != 4) {
                func_003C3A10(o, 4, 0, 8);
            }
        }
        fr = func_L01_004395E0(o);
        if (fr < (f32)D_L05_001DD744) {
            func_L01_0045AA10(o, func_0038D160(*(f32 *)(v + 0x220) - *(f32 *)(o + 0x10),
                                               *(f32 *)(v + 0x224) - *(f32 *)(o + 0x14)));
        } else if (fr < (f32)D_L05_001DD748) {
            t = *(vu0_v4 *)(o + 0xC0);
            vec_add_ba(&t, &t, o + 0x10);
            func_L01_0045A748(o, &t);
        }
        if (16.0f < fr && fr < 22.0f) {
            func_L01_004468C8(o, 7, v[0x5F] ? 0x10001 : 1, 0, 1, 0, 0.6f, (f32)v[0x45], D_L05_001DD73C);
        }
        break;
    }
    case 9:
        func_L01_0045AA10(o, func_0038D160(*(f32 *)(*(u8 **)(v + 0x230) + 0x10) - *(f32 *)(o + 0x10),
                                           *(f32 *)(*(u8 **)(v + 0x230) + 0x14) - *(f32 *)(o + 0x14)));
        if (func_L01_0044E1B8(o, 16.0f) != 0) {
            u8 *q;
            func_003C2F58((s32)o, 5, &t);
            func_0038CF68(&a, o + 0xC0, func_0038CF38(pos, *(u8 **)(v + 0x230) + 0x10) / 1.3f * 0.020000001f);
            a.z = func_L01_00447878(&t, v + 0x220, 0,
                                    func_0038CF38(pos, *(u8 **)(v + 0x230) + 0x10) * 0.020000001f, -0.0044f);
            q = func_L05_0032B880(&t, &a, o, (f32)v[0x46]);
            *(f32 *)(q + 0x2C) = *(f32 *)(q + 0x2C) * 1.5f;
        }
        if (o[0x60] & 2) {
            func_L01_004450F0(o, 7, -1);
            if (o[0x43] != 5) {
                func_003C3A10(o, 5, 0, 8);
            }
        }
        break;
    case 10:
        if (o[0x42] == 0 || func_L01_0044E1B8(o, 35.0f) != 0) {
            if (*(s16 *)(v + 0x3D2) == 0 || *(s32 *)(v + 0x2D0) < *(u16 *)(o + 0x96)) {
                func_003C2F58((s32)o, 6, &t);
                if (func_003D3CB0(&t, v + 0x220, 0, o, 0) != 0 && *(u8 **)(v + 0x230) != D_L05_001EA6D8[0]) {
                    if (func_0038CF38(pos, v + 0x220) < 13.0f && *(s16 *)(v + 0x3D2) != 0) {
                        if (o[0x43] != 8) {
                            func_003C3A10(o, 8, 0, 5);
                        }
                        func_L01_004450F0(o, 9, -1);
                    } else if (*(s32 *)(v + 0x3C0) != -1) {
                        func_L05_0035E820(o);
                        if (o[0x43] != 4) {
                            func_003C3A10(o, 4, 0, 8);
                        }
                        func_L01_004450F0(o, 0xC, -1);
                    }
                } else if ((*(s16 *)(v + 0x3D2) != 0 ||
                            func_0038CF38(pos, *(u8 **)(v + 0x230) + 0x10) < 8.0f) &&
                           func_L05_0035E640(o) != 0 && *(s16 *)(v + 0x3D0) == 0) {
                    if (o[0x43] != 5) {
                        func_003C3A10(o, 5, 0, 8);
                    }
                    func_L01_004450F0(o, 7, -1);
                    a = *(vu0_v4 *)(o + 0x10);
                    b = *(vu0_v4 *)(v + 0x220);
                    a.z += *(f32 *)(v + 0x78);
                    if (func_003D3CB0(&a, &b, 0, o, 0) != 0 && *(u8 **)(v + 0x230) != D_L05_001EA6D8[0] &&
                        *(s32 *)(v + 0x340) != 0) {
                        if (o[0x43] != 4) {
                            func_003C3A10(o, 4, 0, 8);
                        }
                        func_L01_004450F0(o, 5, -1);
                    }
                } else if (*(s32 *)(v + 0x3C0) == -1) {
                    if (o[0x43] != 4) {
                        func_003C3A10(o, 4, 0, 8);
                    }
                    func_L01_004450F0(o, 6, -1);
                }
            }
            if (o[0x20] == 10 && o[0x42] == 7 && o[0x43] != 0) {
                func_003C3A10(o, 0, 0, 8);
            }
        }
        break;
    }

    vec_sub_ba(&t, o + 0x10, &p);
    if (func_0038CED8(&t) < 0.060000002f && (u8)(o[0x20] - 5) < 2) {
        (*(s32 *)(v + 0x2E4))++;
    } else {
        func_0038CAD0(v + 0x2E4);
    }
    func_L05_0035D388(o);
}
/* localdecomp:end func_L05_0035B3F0 */
