#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003C4F88 */
extern u8 D_001A30B0[];
extern s32 D_L05_001D673C;
extern u8 *D_L05_001DF7CC;
extern u8 *D_L05_001DFC80;
extern u8 D_L05_001D66B0[8];
extern s32 func_L05_003C6080(u8 *);
extern void func_L05_003C66F0(u8 *);
extern void func_L05_003C67C0(u8 *);
extern void func_L05_003C69D8(u8 *);
extern void func_L05_00323AC0(u8 *, void *, void *, f32, f32);
extern void func_003C2880(u8 *);
extern s32 func_L01_004561E0(u8 *);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_00382498(s32, s32);
extern s32 func_0038CB00(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_00454370(u8 *, u8 *);
extern void func_L01_00409598(u8 *, u8 *, u8 *, s32, s32, s32, s32, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0045BDE8(u8 *, s32);
extern void func_L01_0045BD10(u8 *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0045CED0(u8 *, void *);
extern void func_L01_0045A748(u8 *, void *);
extern void func_L01_0045CF00(u8 *, void *, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0043A800(u8 *, s32, void *);
extern s32 func_L01_0044E1B8(u8 *, f32);
extern void func_003C2F58(u8 *, s32, void *);
extern u8 *func_L01_0046B458(void *, s32, s32, s32, s32, void *, f32, f32, f32, s32);
void func_L05_003C4F88(u8 *a0) {
    u8 *s;
    struct { vu0_v4 v90, va0, vb0, vc0, vd0; } L;
    s32 f;
    s32 i;
    s32 id;
    u8 *snd;
    f32 d;
    f32 d1;
    f32 f20;
    f32 f21;
    s = *(u8 **)(a0 + 0x68);
    if (func_L05_003C6080(a0)) {
        func_003C2880(a0);
        return;
    }
    switch (a0[0x95]) {
    case 0:
        if (func_L01_004561E0(a0)) {
            *(s16 *)(s + 0x2F6) = (func_00382498(0, 0x1E) * 5 + 2) / 6;
        }
        if (*(s16 *)(s + 0x234) == 1 && func_0038CB00(s + 0x2F6)) {
            func_L01_004450F0(a0, 5, 2);
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 8);
            }
            if (*(s32 *)(s + 0x408) != -1) {
                u8 *e = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30;
                if (*(s16 *)(e + 0x32) != 0) {
                    if (a0[0x43] != 1) {
                        func_003C3A10(a0, 1, 0, 8);
                    }
                    func_L01_004450F0(a0, 6, -1);
                }
            }
            if (*(s32 *)(s + 0x2FC) != -1) {
                func_L01_004450F0(a0, 4, -1);
            }
        } else if (*(s32 *)(s + 0x2F8) != 0 && func_0038CB00(s + 0x2F6)) {
            func_L01_004450F0(a0, 5, 2);
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 8);
            }
            if (*(s32 *)(s + 0x408) != -1) {
                u8 *e = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30;
                if (*(s16 *)(e + 0x32) != 0) {
                    if (a0[0x43] != 1) {
                        func_003C3A10(a0, 1, 0, 8);
                    }
                    func_L01_004450F0(a0, 6, -1);
                }
            }
            if (*(s32 *)(s + 0x2FC) != -1) {
                func_L01_004450F0(a0, 4, -1);
            }
            *(s32 *)(s + 0x2F8) = 0;
            if (*(s32 *)(s + 0x2F0) < 0xFA) {
                *(s32 *)(s + 0x2F0) = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    case 1:
        if (*(s16 *)(s + 0x234) == 1) {
            func_L01_004450F0(a0, 5, 2);
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 8);
            }
            if (*(s32 *)(s + 0x408) != -1) {
                u8 *e = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30;
                if (*(s16 *)(e + 0x32) != 0) {
                    if (a0[0x43] != 1) {
                        func_003C3A10(a0, 1, 0, 8);
                    }
                    func_L01_004450F0(a0, 6, -1);
                }
            }
            if (*(s32 *)(s + 0x2FC) != -1) {
                func_L01_004450F0(a0, 4, -1);
            }
        } else if (*(s32 *)(s + 0x2F0) == 0) {
            func_L01_004450F0(a0, 1, 0);
        }
        break;
    case 2:
        if (func_L01_004561E0(a0)) {
            if (*(s32 *)(s + 0x424) != 0) {
                func_L01_00409598(a0, a0 + 0x10, a0 + 0xF0, 0, 2, 3, 0x25, 0x25, 0xFF8040, 0x8F1010);
                *(s32 *)(s + 0x424) = 0;
            }
        }
        if (*(s16 *)(s + 0x234) != 1 && func_L01_004561E0(a0) == 0) {
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 8);
            }
            func_L01_004450F0(a0, 3, 1);
            *(s32 *)(s + 0x2F0) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
        }
        break;
    case 3:
        if (func_L01_004561E0(a0)) {
            *(s32 *)(s + 0x2FC) = -1;
        }
        f = func_L01_00454370(a0, s + 0x160);
        if ((f & 1) || *(f32 *)(s + 0x30) <= 0.0f) {
            func_L05_003C66F0(a0);
            func_0038CF68(&L.va0, a0 + 0xE0, 3.0f);
            vec_add_ba(&L.v90, a0 + 0x10, &L.va0);
            func_L01_003303B8(&L.v90, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 0, 1.0f, 0.0f, 0.0f, 2.0f, 0, 1, 0, 1, 0, 1,
                              0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF,
                              0x280000FF, 0x3064FF, 0);
            func_003A52A0(5, 0, a0);
            id = *(s32 *)(s + 0x420);
            if (id != -1) {
                snd = D_001A30B0 + id * 0x80;
                if (*(u8 **)(snd + 0xDC) == a0 && snd[0xD0] != 0) {
                    func_003A4F28(id);
                }
            }
            *(s32 *)(s + 0x420) = -1;
            func_003C2880(a0);
            return;
        }
        if (f & 2) {
            if (*(s16 *)(s + 0x234) == 1) {
                func_L01_004450F0(a0, 5, 2);
                if (*(s32 *)(s + 0x408) != -1) {
                    u8 *e = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30;
                    if (*(s16 *)(e + 0x32) != 0) {
                        if (a0[0x43] != 1) {
                            func_003C3A10(a0, 1, 0, 8);
                        }
                        func_L01_004450F0(a0, 6, -1);
                    }
                }
            } else {
                func_L01_004450F0(a0, 3, 1);
                *(s32 *)(s + 0x2F0) = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    }
    switch (a0[0x20]) {
    case 4:
        if (func_L01_004561B8(a0)) {
            s32 g = D_L05_001D673C;
            *(s32 *)(s + 0xA8) |= 0x400;
            if (g != 0) {
                *(s32 *)(s + 0xA8) |= 0x10;
            }
            func_L01_0045BD78(a0, *(f32 *)(s + 0x404) * 2.5f * 0.00040000002f, *(f32 *)(s + 0x404) * 0.020000001f,
                              0.010053097f, 0.25132743f);
        }
        if (func_L01_0045BDE8(a0, *(s32 *)(s + 0x2FC))) {
            s32 g = D_L05_001D673C;
            *(s32 *)(s + 0x2FC) = -1;
            *(s32 *)(s + 0xA8) &= ~0x400;
            if (g != 0) {
                *(s32 *)(s + 0xA8) &= ~0x10;
            }
            qzero(s + 0x110);
            func_L01_004450F0(a0, 5, -1);
            if (*(s32 *)(s + 0x408) != -1) {
                u8 *e = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30;
                if (*(s16 *)(e + 0x32) != 0) {
                    if (a0[0x43] != 1) {
                        func_003C3A10(a0, 1, 0, 8);
                    }
                    func_L01_004450F0(a0, 6, -1);
                }
            }
        } else {
            func_L01_0045BD10(a0, func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14)));
        }
        break;
    case 5:
        if (*(s16 *)(s + 0x428) == 0) {
            if (D_L05_001D673C != 0) {
                func_L01_0045CED0(a0, s + 0x220);
            } else {
                func_L01_0045A748(a0, s + 0x220);
            }
        }
        if (func_0038CF38(a0 + 0x10, s + 0x220) < 25.0f || *(s16 *)(s + 0x428) != 0) {
            func_L01_004450F0(a0, 7, -1);
            if (a0[0x43] != 3) {
                func_003C3A10(a0, 3, 0, 8);
            }
        }
        break;
    case 7:
        if (*(s16 *)(s + 0x428) != 0) {
            func_L05_003C69D8(a0);
        } else if (D_L05_001D673C != 0) {
            vec_sub_ab(&L.v90, s + 0x220, a0 + 0x10);
            func_L01_0045CF00(a0, a0 + 0x10, &L.v90);
        } else {
            func_L01_0045BD10(a0, func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14)));
        }
        if (a0[0x60] & 2) {
            if (a0[0x43] != 4) {
                func_003C3A10(a0, 4, 0, 8);
            }
            func_L01_004450F0(a0, 8, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(a0)) {
            if (*(s32 *)(s + 0x408) != -1) {
                u8 *e = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30;
                if (*(s16 *)(e + 0x32) != 0) { u8 *e2;
                    *(vu0_q *)(s + 0x410) =
                        *(vu0_q *)(D_L05_001DFC80 + (**(s32 **)(D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30 + 0x40) << 7) + 0x30);
                    for (i = 0; i < *(s16 *)((e2 = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30) + 0x32); i++) {
                        u8 *w = D_L05_001DFC80 +
                                (*(s32 *)(*(u8 **)(D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30 + 0x40) + i * 4) << 7);
                        f20 = func_0038CF38(w + 0x30, s + 0x220);
                        if ((func_0038CF38(s + 0x410, s + 0x220) < f20 || func_0038CF38(a0 + 0x10, s + 0x410) < 2.0f) &&
                            2.0f < func_0038CF38(a0 + 0x10, w + 0x30)) {
                            *(vu0_q *)(s + 0x410) = *(vu0_q *)(w + 0x30);
                        }
                    }
                }
            }
        }
        if (D_L05_001D673C != 0) {
            if (func_0038CF00(a0 + 0x10, s + 0x410) < 3.0f) {
                if (D_L05_001D673C == 0) {
                    func_L01_0045BD10(a0, func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                        *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14)));
                    if (!(func_0038DBA0(*(f32 *)(a0 + 0xF8), func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                                           *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14))) < 0.27925268f)) {
                        break;
                    }
                } else {
                    vec_sub_ab(&L.v90, s + 0x220, a0 + 0x10);
                    func_L01_0045CF00(a0, a0 + 0x10, &L.v90);
                    func_L01_004450F0(a0, 7, -1);
                    if (a0[0x43] != 3) {
                        func_003C3A10(a0, 3, 0, 8);
                    }
                    break;
                }
                func_L01_004450F0(a0, 7, -1);

                if (a0[0x43] != 3) {
                    func_003C3A10(a0, 3, 0, 8);
                }
            } else if (D_L05_001D673C != 0) {
                func_L01_0045CED0(a0, s + 0x410);
            } else {
                func_L01_0045A748(a0, s + 0x410);
                func_L01_0045BD10(a0, func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                    *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14)));
            }
        } else {
            if (func_0038CF38(a0 + 0x10, s + 0x410) < 1.0f) {
                if (D_L05_001D673C != 0) {
                    vec_sub_ab(&L.v90, s + 0x220, a0 + 0x10);
                    func_L01_0045CF00(a0, a0 + 0x10, &L.v90);
                    func_L01_004450F0(a0, 7, -1);
                    if (a0[0x43] != 3) {
                        func_003C3A10(a0, 3, 0, 8);
                    }
                    break;
                } else {

                    func_L01_0045BD10(a0, func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                        *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14)));
                    if (!(func_0038DBA0(*(f32 *)(a0 + 0xF8), func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                                           *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14))) < 0.27925268f)) {
                        break;
                    }
                }
                func_L01_004450F0(a0, 7, -1);
                if (a0[0x43] != 3) {
                    func_003C3A10(a0, 3, 0, 8);
                }
            } else if (D_L05_001D673C != 0) {
                func_L01_0045CED0(a0, s + 0x410);
            } else {
                func_L01_0045A748(a0, s + 0x410);
                func_L01_0045BD10(a0, func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                    *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14)));
            }
        }
        break;
    case 8:
        if (D_L05_001D673C == 0) {
            func_L01_0040EE50(&L.vb0, a0 + 0xC0);
            vec_sub_ab(&L.v90, s + 0x220, a0 + 0x10);
            func_0038D000(&L.v90, &L.v90, &L.vb0);
            func_L01_0043A800(a0, 0, &L.va0);
            *(f32 *)(s + 0x364) = -func_0038D160(func_0038CF38(&L.va0, &L.v90), L.v90.z - L.va0.z);
            func_L01_0043A800(a0, 1, &L.va0);
            *(f32 *)(s + 0x3E4) = -func_0038D160(func_0038CF38(&L.va0, &L.v90), L.v90.z - L.va0.z);
        }
        if (*(s16 *)(s + 0x428) != 0) {
            func_L05_003C69D8(a0);
        } else {
            func_L01_0045BD10(a0, func_0038D160(*(f32 *)(s + 0x220) - *(f32 *)(a0 + 0x10),
                                                *(f32 *)(s + 0x224) - *(f32 *)(a0 + 0x14)));
        }
        if (D_L05_001D673C != 0) {
            vec_sub_ab(&L.v90, s + 0x220, a0 + 0x10);
            func_L01_0045CF00(a0, a0 + 0x10, &L.v90);
        }
        if (*(u16 *)(a0 + 0x96) >= 0xC9) {
            func_L01_004450F0(a0, 9, -1);
            if (a0[0x43] != 5) {
                func_003C3A10(a0, 5, 0, 8);
            }
        }
        if ((func_L01_0044E1B8(a0, 2.0f) || func_L01_0044E1B8(a0, 6.0f) || func_L01_0044E1B8(a0, 10.0f) ||
             func_L01_0044E1B8(a0, 14.0f) || func_L01_0044E1B8(a0, 18.0f) || func_L01_0044E1B8(a0, 22.0f) ||
             func_L01_0044E1B8(a0, 26.0f)) &&
            a0[0x42] == 4) {
            func_003C2F58(a0, 2, &L.v90);
            f21 = 1.0f;
            f20 = 0.0f;
            vec_sub_ab(&L.va0, s + 0x220, &L.v90);
            func_L05_00323AC0(a0, &L.v90, &L.va0, (f32)s[0x44], *(f32 *)(s + 0x40C));
            func_0038CF68(&L.vb0, &L.va0, f21);
            vec_add_ab(&L.vb0, &L.vb0, &L.v90);
            func_L01_0046B458(&L.vb0, 2, 0x7F1040FF, 0, 2, D_L05_001D66B0, 3.0f, 10.0f, f20, 0);
            func_L01_0046B458(&L.vb0, 2, 0x5F5F5F5F, 0, 2, D_L05_001D66B0, f21, 7.0f, f20, 0);
        }
        if ((func_L01_0044E1B8(a0, 4.0f) || func_L01_0044E1B8(a0, 8.0f) || func_L01_0044E1B8(a0, 12.0f) ||
             func_L01_0044E1B8(a0, 16.0f) || func_L01_0044E1B8(a0, 20.0f) || func_L01_0044E1B8(a0, 24.0f) ||
             func_L01_0044E1B8(a0, 28.0f)) &&
            a0[0x42] == 4) {
            func_003C2F58(a0, 3, &L.v90);
            f21 = 1.0f;
            f20 = 0.0f;
            vec_sub_ab(&L.va0, s + 0x220, &L.v90);
            func_L05_00323AC0(a0, &L.v90, &L.va0, (f32)s[0x44], *(f32 *)(s + 0x40C));
            func_0038CF68(&L.vb0, &L.va0, f21);
            vec_add_ab(&L.vb0, &L.vb0, &L.v90);
            func_L01_0046B458(&L.vb0, 2, 0x7F1040FF, 0, 2, D_L05_001D66B0, 3.0f, 10.0f, f20, 0);
            func_L01_0046B458(&L.vb0, 2, 0x5F5F5F5F, 0, 2, D_L05_001D66B0, f21, 7.0f, f20, 0);
        }
        break;
    case 9:
        if (a0[0x60] & 2) {
            *(s16 *)(s + 0x42A) = 0;
            func_L01_004450F0(a0, 5, -1);
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 8);
            }
            if (*(s32 *)(s + 0x408) != -1) {
                u8 *e = D_L05_001DF7CC + *(s32 *)(s + 0x408) * 0x30;
                if (*(s16 *)(e + 0x32) != 0) {
                    if (a0[0x43] != 1) {
                        func_003C3A10(a0, 1, 0, 8);
                    }
                    func_L01_004450F0(a0, 6, -1);
                }
            }
        }
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
    func_L05_003C67C0(a0);
}
/* localdecomp:end func_L05_003C4F88 */

/* localdecomp:start func_L05_003C6080 */
extern u8 D_001A30B0[];
extern s32 D_001D545C;
extern s32 func_L05_003C63A8_003C6080(void);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L05_003C66F0_003C6080(u8 *a0);
extern s32 func_L01_00452FB0_003C6080(void *, void *, s32, s32, s32);
extern void func_L05_003C6920_003C6080(void *);
extern void func_L01_00455E18_003C6080(void *, void *, void *);
extern s32 func_L01_00452860_003C6080(void *, void *, s32);
extern void func_L01_00456BD0_003C6080(void *, s32);
extern void func_L01_00456C98_003C6080(void *, s32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, f32);

s32 func_L05_003C6080(u8 *o) {
    u8 *t;
    u8 *e;
    s32 id;

    t = *(u8 **)(o + 0x68);
    if (o[0x20] == 0) {
        if (func_L05_003C63A8_003C6080() != 0) {
            return 1;
        }
    }
    id = *(s32 *)(t + 0x420);
    if (id == -1 || (e = D_001A30B0 + id * 0x80, *(u8 **)(e + 0xDC) != o) || e[0xD0] == 0) {
        *(s32 *)(t + 0x420) = func_003A52A0(3, 4, o);
    }
    if (t[0x3E] == 2) {
        func_L05_003C66F0_003C6080(o);
        return 1;
    }
    if (o[0xBC] != 0) {
        o[0xBC] = o[0xBC] - 1;
    }
    if (o[0x20] == 4 && D_001D545C == 0xB) {
        if (func_L01_00452FB0_003C6080(o, t + 0x160, 0, 0, 1) != 0) {
            if (o[0xBC] == 0) {
                func_003A52A0(4, 0, o);
                o[0xBC] = 0x19;
            }
            *(s16 *)(t + 0x42A) = 1;
            func_L05_003C6920_003C6080(o);
        }
    } else {
        if (func_L01_00452FB0_003C6080(o, t + 0x160, 0, 0, 0) != 0) {
            if (o[0xBC] == 0) {
                func_003A52A0(4, 0, o);
                o[0xBC] = 0x19;
            }
            *(s16 *)(t + 0x42A) = 1;
            func_L05_003C6920_003C6080(o);
        }
    }
    func_L01_00455E18_003C6080(o, t + 0x240, t + 0x30);
    func_L01_00452860_003C6080(o, t + 0x30, 0);
    if (t[0x5E] != 0) {
        func_L05_003C66F0_003C6080(o);
        return 1;
    }
    if (t[0x5F] != 0) {
        func_L01_00456BD0_003C6080(o, 5);
        if (o[0x95] == 0) {
            func_L01_00456C98_003C6080(o, *(s32 *)(t + 0x2E0), *(f32 *)(t + 0x2E4), 10.0f, 0, 0, 0, 0, 3, 0, 0, 0, 1.0f);
        } else {
            func_L01_00456C98_003C6080(o, *(s32 *)(t + 0x2E8), *(f32 *)(t + 0x2EC), 10.0f, 0, 0, 0, 0, 3, 0, 0, 0, 1.0f);
        }
    } else {
        func_L01_00456BD0_003C6080(o, 3);
        if (*(s16 *)(t + 0x42A) != 0) {
            func_L01_00456C98_003C6080(o, -1, 256.0f, 256.0f, 0, 0, 0, 0, 1, 0, 0, 0, 1.0f);
        } else if (o[0x95] == 0) {
            func_L01_00456C98_003C6080(o, *(s32 *)(t + 0x2E0), *(f32 *)(t + 0x2E4), 10.0f, 0, 0, 0, 0, 1, 0, 0, 0, 1.0f);
        } else {
            func_L01_00456C98_003C6080(o, *(s32 *)(t + 0x2E8), *(f32 *)(t + 0x2EC), 10.0f, 0, 0, 0, 0, 1, 0, 0, 0, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L05_003C6080 */

/* localdecomp:start func_L05_003C63A8 */
struct V_3C42B0;
typedef struct {
    u8 pad0[0x68];
    struct V_3C42B0 *v68;
    u8 pad6C[0x10];
    s16 h7C;
} O_3C42B0;
typedef struct V_3C42B0 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0x3];
    u8 b39;
    u8 pad3A[0x4];
    u8 b3E;
    u8 b3F;
    f32 f40;
    u8 pad44[0x14];
    u8 b58;
    u8 pad59[0x1];
    u8 b5A;
    u8 pad5B[0x9];
    u8 b64;
    u8 pad65[0xB];
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 pad84[0x18];
    union { f32 f; s32 i; } u9C;
    f32 fA0;
    u8 padA4[0x4];
    s32 wA8;
    u8 padAC[0xC4];
    u8 b170;
    u8 pad171[0x1F];
    f32 f190;
    f32 f194;
    u8 pad198[0x4];
    f32 f19C;
    u8 pad1A0[0x8];
    u8 b1A8;
    u8 pad1A9[0x2E];
    u8 b1D7;
    u8 b1D8;
    u8 b1D9;
    u8 b1DA;
    u8 b1DB;
    u8 pad1DC[0x244];
    s32 w420;
    s32 w424;
    s16 h428;
} V_3C42B0;
extern s32 D_L05_001D673C;
extern s32 D_L05_001DF6C0;
extern s32 D_L05_001D67BC;
extern vu0_v4 D_L05_001EA6E0;
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

s32 func_L05_003C63A8(u8 *o) {
    V_3C42B0 *v = ((O_3C42B0 *)o)->v68;
    vu0_v4 m[4];
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 m2[4];

    ((O_3C42B0 *)o)->h7C = 0x7F;
    if (D_L05_001D673C != 0) {
        *(s16 *)(o + 0x32) = 0xFF;
        *(u16 *)(o + 0x34) |= 0x100;
        func_003C5180(o + 0x10, m, 0);
        func_L01_004515D8(o + 0xC0, &m[0], &m[1]);
        func_0038CF68(&a, o + 0xE0, 0.5f);
        func_0038CF68(&b, o + 0xE0, -4.0f);
        vec_add_ba(&a, &a, o + 0x10);
        vec_add_ba(&b, &b, o + 0x10);
        if (func_003D3CB0(&a, &b, 2, o, 0) != 0) {
            *(vu0_v4 *)(o + 0x10) = D_L05_001EA6E0;
            func_003C5180(o + 0x10, m2, 0);
            func_L01_004515D8(o + 0xC0, &m2[0], &m2[1]);
        }
        v->h428 = 0;
    }
    v->b170 = 0xA;
    v->b1A8 = 3;
    v->b1D7 = 1;
    v->b1DB = 0xFF;
    v->b1D8 = 0;
    v->b1D9 = 0;
    v->b1DA = 0;
    v->f19C = 0.15f;
    v->f70 = 0.7f;
    v->f78 = v->f74 = v->f194 = v->f190 = 0.5f;
    v->f7C = 1.0f;
    v->f80 = 0.7853982f;
    v->fA0 = 0.34906584f;
    v->u9C.f = 0.00392f;
    if (D_L05_001D673C != 0) {
        v->u9C.i = 0;
    }
    v->wA8 |= 4;
    if (D_L05_001D673C == 0) {
        v->wA8 |= 0x14;
    }
    func_L01_0045BD78(o, 0.012f, 0.20000002f, 0.010053097f, 0.25132743f);
    v->b58 = 0x14;
    v->b5A = 0xE;
    if (v->h34 == 0) {
        v->h34 = 0x64;
        v->f30 = 100.0f;
    }
    v->b39 = 1;
    v->b3E = 1;
    v->b3F = 0;
    v->b64 = 0;
    v->w420 = -1;
    v->f40 = 2.0f;
    func_L01_004450F0(o, 1, 0);
    if (o[0x43] != 0) {
        func_003C3A10(o, 0, 0, 0);
    }
    if (v->w424 != 0) {
        *(s32 *)(o + 0x98) = 0;
        *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(o, 1);
    }
    if (v->h428 != 0) {
        v->wA8 |= 4;
        *(u16 *)(o + 0x34) |= 0x100;
        v->f80 = 12.566371f;
        v->wA8 |= 1;
    }
    if (D_L05_001DF6C0 == 0) {
        D_L05_001D67BC = 0;
    }
    return 0;
}
/* localdecomp:end func_L05_003C63A8 */

/* localdecomp:start func_L05_003C66F0 */
extern void func_L01_004443E8(void *, s32, s32);
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                              f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_L01_00459C50(s32);
extern s32 D_001D545C;
extern s32 D_L05_001D67BC;
extern u8 D_L05_001D66B0[8];

void func_L05_003C66F0(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    if (D_001D545C == 0x11 && (pv[0x60] != 0 || pv[0x47] == 0x87)) {
        D_L05_001D67BC = D_L05_001D67BC + 1;
        if (D_L05_001D67BC >= 0x28) {
            func_L01_00459C50(0x13);
        }
    }
    func_L01_004443E8(a0, 0, 3);
    func_L01_00452310(a0, 0x3FFF, D_L05_001D66B0, 1, 0x28, -1.0f, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0);
}
/* localdecomp:end func_L05_003C66F0 */

/* localdecomp:start func_L05_003C67C0 */
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern u8 D_L05_001E2700[];

void func_L05_003C67C0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    f32 a;
    f32 b;
    func_0038CAD0(v + 0x2F0);
    func_0038CB00(v + 0x2F4);
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        (*(u16 *)(a0 + 0x96))++;
    }
    func_L01_00451DF8(a0, v + 0x260, 4, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L05_001E2700, a0 + 0x10) < 1024.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x1E;
        }
    }
    a = 0.0432000011f;
    *(f32 *)(v + 0x42C) = func_0038DAB8(*(f32 *)(v + 0x42C), 0.069813177f);
    b = 0.432000041f;
    *(s32 *)(a0 + 0x78) = func_0038DBD8(0x80A0A0A0, 0x60101010, (func_0038D0B0(*(f32 *)(v + 0x42C)) + 1.0f) * 0.5f);
    func_L01_0044E850(a0, v + 0x300, 0, a, b);
    func_L01_0044E850(a0, v + 0x380, 1, a, b);
}
/* localdecomp:end func_L05_003C67C0 */
