#include "common.h"
#include "vu0.h"

extern u8 D_L05_001E2700[];
extern void func_0038CB00(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00404808(void *, u8 *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(u8 *);
extern void func_L01_00451DF8(void *a, void *b, s32 c, s32 d, f32 e);

/* localdecomp:start func_L05_0035B308 */
extern void func_003C2F58(s32, s32, void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003C5458(void *, s32, f32, f32);
__asm__(".extern D_L05_001DD6F0, 8");
extern u8 D_L05_001DD6F0[8];
__asm__(".extern D_L05_001DD710, 8");
extern s32 D_L05_001DD710[2];
__asm__(".extern D_L05_001DD6E0, 8");
extern f32 D_L05_001DD6E0[2];
__asm__(".extern D_L05_001DD6D8, 8");
extern f32 D_L05_001DD6D8[2];

void func_L05_0035B308(u8 *arg0)
{
    u8 *v;
    s32 i;
    vu0_v4 p;
    u8 m[0x40];
    vu0_v4 d;

    v = *(u8 **)(arg0 + 0x68);
    for (i = 0; i < 2; i++) {
        func_003C2F58(*(s32 *)(v + 0x3EC), 2, &p);
        func_003C2EC0(*(void **)(v + 0x3EC), 2, m);
        func_0038D028(&d, D_L05_001DD6F0 + i * 0x10, m);
        vec_add_ab(&p, &p, &d);
        func_003C5458(&p, D_L05_001DD710[i], D_L05_001DD6E0[i], D_L05_001DD6D8[i]);
    }
}
/* localdecomp:end func_L05_0035B308 */

/* localdecomp:start func_L05_0035B3F0 */
extern u8 *D_L05_001EA6D8[];
extern u8 *D_L05_001DFC80_0035B3F0;
extern u8 *D_L05_0021ED80_0035B3F0[];
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
extern s32 func_L05_0035CE98(u8 *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_L05_0035E820(void *);
extern s32 func_L01_00454370_0035B3F0(void *, void *);
extern void func_L05_0035D300(u8 *);
extern void func_L01_00315900(void *, s32, s32);
extern void func_003C2880(u8 *);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_004561B8_0035B3F0(void *);
extern f32 func_L01_004395E0_0035B3F0(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0045BD10_0035B3F0(void *, f32);
extern void func_003C41A0(void *, void *, f32, f32, f32, f32);
extern void func_L01_0045AA30(void *, void *);
extern void func_L01_0045BD78_0035B3F0(void *, f32, f32, f32, f32);
extern s32 func_L01_0045BE38(void *, void *);
extern void func_L01_0045C150_0035B3F0(void *, void *, s32, s32);
extern void func_L05_0035E148(void *, f32);
extern void func_L05_0035E5A8(void *);
extern void func_L01_0045A748_0035B3F0(void *, void *);
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
extern void func_L05_0035D388(u8 *);
extern void func_0038CAD0(void *);
extern s32 func_0038CAD0_0035B3F0(void *);
extern s32 func_0038CB00_0035B3F0(void *);

typedef struct {
    u8 pad0[0x340];
    u8 *pts[16]; /* 0x340: the points state 5 picks the nearest of; their count is at 0x380 */
    u8 pad380[0x40];
    s32 ids[5]; /* 0x3C0: indexed by the s32 at 0x3D4 in state 12 */
} V_35B3F0;

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

    if (func_L05_0035CE98(o) != 0) {
        return;
    }
    pos = o + 0x10;
    p = *(vu0_v4 *)pos;
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
            if (func_0038CB00_0035B3F0(v + 0x2D6) != 0) {
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
        r = func_L01_00454370_0035B3F0(o, v + 0x160);
        if (r & 1) {
            func_L05_0035D300(o);
            func_L01_00315900(o, 0, 0);
            func_003C2880(o);
            return;
        }
        if (r & 2) {
            if (*(s16 *)(v + 0x234) == 1) {
                func_L01_004450F0(o, 8, 2);
                if (func_0038CF38(o + 0x10, *(u8 **)(v + 0x230) + 0x10) < 2.0f) {
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
        if (func_L01_004561B8_0035B3F0(o) != 0 && o[0x43] != 0) {
            func_003C3A10(o, 0, 0, 8);
        }
        break;
    case 4:
        if (func_L01_004561B8_0035B3F0(o) != 0) {
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
        if (func_L01_004561B8_0035B3F0(o) != 0) {
            *(f32 *)(v + 0x3B8) = *(f32 *)(o + 0x18);
        }
        if (o[0x42] == 2) {
            f32 fr = func_L01_004395E0_0035B3F0(o);
            if (7.0f < fr && fr < 19.0f) {
                func_0038CF68(&b, o + 0xC0, 0.125f);
                vec_add_ba(&t, o + 0x10, &b);
                func_L01_0045BD10_0035B3F0(o, func_0038D160(*(f32 *)(v + 0x220) - *(f32 *)(o + 0x10),
                                                   *(f32 *)(v + 0x224) - *(f32 *)(o + 0x14)));
            }
            if (7.0f < fr && fr < 13.0f) {
                if (*(f32 *)(v + 0x3AC) < *(f32 *)(v + 0x3B8) &&
                    1.0f < fabs_asm(*(f32 *)(v + 0x3AC) - *(f32 *)(v + 0x3B8))) {
                    func_003C41A0(&t.z, v + 0x3A8, *(f32 *)(v + 0x3AC) + 3.0f + 1.0f, 0.05f, 0.23809525f, 0.5f);
                } else {
                    func_003C41A0(&t.z, v + 0x3A8, *(f32 *)(v + 0x3AC) + 3.0f, 0.05f, 0.23809525f, 0.5f);
                }
            }
            if (fr == 13.0f) {
                *(s32 *)(v + 0x3A8) = 0;
            }
            if (13.0f < fr && fr < 19.0f) {
                if (*(f32 *)(v + 0x3AC) < *(f32 *)(v + 0x3B8) &&
                    1.0f < fabs_asm(*(f32 *)(v + 0x3AC) - *(f32 *)(v + 0x3B8))) {
                    func_003C41A0(&t.z, v + 0x3A8, *(f32 *)(v + 0x3AC), 0.071428575f, 0.25f, 0.6f);
                } else {
                    func_003C41A0(&t.z, v + 0x3A8, *(f32 *)(v + 0x3AC), 0.05f, 0.25f, 0.5f);
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
        func_L01_0045BD78_0035B3F0(o, 0.0042000003f, 0.060000002f, 0.010053097f, 0.25132743f);
        if (func_L01_0045BE38(o, D_L05_0021ED80_0035B3F0[*(s32 *)(v + 0x3A0)]) != 0) {
            func_L01_004450F0(o, 3, -1);
            if (o[0x43] != 1) {
                func_003C3A10(o, 1, 0, 0x11);
            }
        }
        break;
    case 3:
        if (o[0x60] & 2) {
            u8 *path = D_L05_0021ED80_0035B3F0[*(s32 *)(v + 0x3A0)];
            fr = func_0038CF38(o + 0x10, path + 0x10);
            if (func_0038CF38(o + 0x10, path + *(s32 *)path * 16) < fr) {
                func_L01_0045C150_0035B3F0(o, D_L05_0021ED80_0035B3F0[*(s32 *)(v + 0x3A0)], 0, *(s32 *)path - 1);
            } else {
                func_L01_0045C150_0035B3F0(o, D_L05_0021ED80_0035B3F0[*(s32 *)(v + 0x3A0)], *(s32 *)path - 1, 0);
            }
            func_L01_004450F0(o, 2, -1);
            if (o[0x43] != 3) {
                func_003C3A10(o, 3, 0, 0x11);
            }
        }
        break;
    case 5:
        if (func_L01_004561B8_0035B3F0(o) != 0) {
            func_L01_0045BD78_0035B3F0(o, 0.0096f, 0.15f, 0.010053097f, 0.25132743f);
            *(vu0_v4 *)(v + 0x390) = *(vu0_v4 *)(((V_35B3F0 *)v)->pts[0] + 0x10);
            for (i = 0; i < *(s32 *)(v + 0x380); i++) {
                fr = func_0038CF38(o + 0x10, ((V_35B3F0 *)v)->pts[i] + 0x10);
                if (fr < func_0038CF38(o + 0x10, v + 0x390)) {
                    *(vu0_v4 *)(v + 0x390) = *(vu0_v4 *)(((V_35B3F0 *)v)->pts[i] + 0x10);
                }
            }
            *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(v + 0x300) = *(vu0_v4 *)(v + 0x390);
            func_L05_0035E148(o, 4.0f);
        }
        func_L05_0035E5A8(o);
        t = *(vu0_v4 *)(v + 0x390);
        if (1.0f < func_0038CF38(v + 0x310, &t)) {
            *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(v + 0x390);
            func_L05_0035E148(o, 4.0f);
            *(s32 *)(v + 0x2E4) = 0;
        }
        *(vu0_v4 *)(v + 0x300) = *(vu0_v4 *)(v + 0x390);
        if (*(s32 *)(v + 0x2E4) >= 5 || func_0038CF38(o + 0x10, v + 0x2F0) <= *(f32 *)(v + 0xA4)) {
            *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(v + 0x390);
            func_L05_0035E148(o, 4.0f);
            *(s32 *)(v + 0x2E4) = 0;
        }
        func_L01_0045A748_0035B3F0(o, v + 0x2F0);
        if (func_0038CF38(o + 0x10, v + 0x390) <= *(f32 *)(v + 0xA4)) {
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
        if (func_L01_004561B8_0035B3F0(o) != 0) {
            *(s32 *)(v + 0x384) = 0;
            func_L01_0045BD78_0035B3F0(o, 0.0096f, 0.15f, 0.010053097f, 0.25132743f);
            *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(v + 0x300) = *(vu0_v4 *)(v + 0x220);
            func_L05_0035E148(o, 15.0f);
        }
        func_L05_0035E5A8(o);
        t = *(vu0_v4 *)(v + 0x220);
        if (1.0f < func_0038CF38(v + 0x310, &t)) {
            *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(v + 0x220);
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
                *(vu0_v4 *)(v + 0x310) = *(vu0_v4 *)(v + 0x2F0) = *(vu0_v4 *)(v + 0x220);
                func_L05_0035E148(o, 15.0f);
                *(s32 *)(v + 0x2E4) = 0;
            }
        }
        func_L01_0045A748_0035B3F0(o, v + 0x2F0);
        if (func_0038CF38(o + 0x10, *(u8 **)(v + 0x230) + 0x10) < 8.0f && func_L05_0035E640(o) != 0 &&
            *(s16 *)(v + 0x3D0) == 0) {
            if (o[0x43] != 5) {
                func_003C3A10(o, 5, 0, 8);
            }
            func_L01_004450F0(o, 7, -1);
            a = *(vu0_v4 *)(o + 0x10);
            b = *(vu0_v4 *)(v + 0x220);
            a.z += *(f32 *)(v + 0x78);
            if (func_003D3CB0(&a, &b, 0, o, 0) != 0 && D_L05_001EA6D8[0] != *(u8 **)(v + 0x230) &&
                *(s16 *)(v + 0x3D2) == 0) {
                if (o[0x43] != 8) {
                    func_003C3A10(o, 8, 0, 8);
                }
                func_L01_004450F0(o, 9, -1);
            }
        }
        if (func_0038CF38(o + 0x10, *(u8 **)(v + 0x230) + 0x10) < 2.0f) {
            if (o[0x43] != 9) {
                func_003C3A10(o, 9, 0, 8);
            }
            func_L01_004450F0(o, 0xB, -1);
        }
        break;
    case 12:
        e = D_L05_001DFC80_0035B3F0 + ((V_35B3F0 *)v)->ids[*(s32 *)(v + 0x3D4)] * 0x80;
        if (func_L01_004561B8_0035B3F0(o) != 0) {
            *(s32 *)(v + 0x384) = 0;
            func_L01_0045BD78_0035B3F0(o, 0.0096f, 0.15f, 0.010053097f, 0.25132743f);
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
        func_L01_0045A748_0035B3F0(o, v + 0x2F0);
        if (func_0038CF38(o + 0x10, e + 0x30) < 0.5f) {
            if (o[0x43] != 5) {
                func_003C3A10(o, 5, 0, 8);
            }
            func_L01_004450F0(o, 7, -1);
            a = *(vu0_v4 *)(o + 0x10);
            b = *(vu0_v4 *)(v + 0x220);
            a.z += *(f32 *)(v + 0x78);
            if (func_003D3CB0(&a, &b, 0, o, 0) != 0 && D_L05_001EA6D8[0] != *(u8 **)(v + 0x230) &&
                *(s16 *)(v + 0x3D2) == 0) {
                if (o[0x43] != 8) {
                    func_003C3A10(o, 8, 0, 8);
                }
                func_L01_004450F0(o, 9, -1);
            }
        }
        if (func_0038CF38(o + 0x10, *(u8 **)(v + 0x230) + 0x10) < 2.0f) {
            if (o[0x43] != 9) {
                func_003C3A10(o, 9, 0, 8);
            }
            func_L01_004450F0(o, 0xB, -1);
        }
        break;
    case 7:
        if (func_L01_004561B8_0035B3F0(o) != 0) {
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
        if (func_0038CF38(o + 0x10, *(u8 **)(v + 0x230) + 0x10) < 3.0f) {
            if (o[0x43] != 9) {
                func_003C3A10(o, 9, 0, 8);
            }
            func_L01_004450F0(o, 0xB, -1);
        }
        if (*(s32 *)(v + 0x3DC) == *(s32 *)(v + 0x230)) {
            f32 q = (D_L05_001DD72C * 5.0f + 2.0f) / 6.0f;
            if (q < (f32)*(s32 *)(v + 0x2E0)) {
                *(s32 *)(v + 0x2E0) = q;
            }
        }
        if (func_0038CAD0_0035B3F0(v + 0x2E0) != 0) {
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
            if (func_003D3CB0(&t, v + 0x220, 0, o, 0) != 0 && D_L05_001EA6D8[0] != *(u8 **)(v + 0x230) &&
                *(s16 *)(v + 0x3D2) == 0) {
                if (o[0x43] != 8) {
                    func_003C3A10(o, 8, 0, 8);
                }
                func_L01_004450F0(o, 9, -1);
            } else if (func_0038CF38(o + 0x10, *(u8 **)(v + 0x230) + 0x10) < 13.0f && func_L05_0035E640(o) != 0) {
                if (o[0x43] != 5) {
                    func_003C3A10(o, 5, 0, 8);
                }
                func_L01_004450F0(o, 7, -1);
                a = *(vu0_v4 *)(o + 0x10);
                b = *(vu0_v4 *)(v + 0x220);
                a.z += *(f32 *)(v + 0x78);
                if (func_003D3CB0(&a, &b, 0, o, 0) != 0 && D_L05_001EA6D8[0] != *(u8 **)(v + 0x230) &&
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
                if (func_0038CF38(o + 0x10, v + 0x220) < 13.0f) {
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
            if (func_0038CF38(o + 0x10, *(u8 **)(v + 0x230) + 0x10) < 2.0f) {
                if (o[0x43] != 9) {
                    func_003C3A10(o, 9, 0, 8);
                }
                func_L01_004450F0(o, 0xB, -1);
            }
        }
        break;
    case 11: {
        f32 fr;
        if (func_L01_004561B8_0035B3F0(o) != 0) {
            func_L01_0045BD78_0035B3F0(o, D_L05_001DD724 * 0.00040000002f, D_L05_001DD720 * 0.020000001f, 0.010053097f,
                              0.25132743f);
        }
        if (o[0x60] & 2) {
            func_L01_004450F0(o, 6, -1);
            if (o[0x43] != 4) {
                func_003C3A10(o, 4, 0, 8);
            }
        }
        fr = func_L01_004395E0_0035B3F0(o);
        if (fr < (f32)D_L05_001DD744) {
            func_L01_0045AA10(o, func_0038D160(*(f32 *)(v + 0x220) - *(f32 *)(o + 0x10),
                                               *(f32 *)(v + 0x224) - *(f32 *)(o + 0x14)));
        } else if (fr < (f32)D_L05_001DD748) {
            t = *(vu0_v4 *)(o + 0xC0);
            vec_add_ba(&t, &t, o + 0x10);
            func_L01_0045A748_0035B3F0(o, &t);
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
            func_0038CF68(&a, o + 0xC0, func_0038CF38(o + 0x10, *(u8 **)(v + 0x230) + 0x10) / 1.3f * 0.020000001f);
            a.z = func_L01_00447878(&t, v + 0x220, 0,
                                    func_0038CF38(o + 0x10, *(u8 **)(v + 0x230) + 0x10) * 0.020000001f, -0.0044f);
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
                if (func_003D3CB0(&t, v + 0x220, 0, o, 0) != 0 && D_L05_001EA6D8[0] != *(u8 **)(v + 0x230)) {
                    if (func_0038CF38(o + 0x10, v + 0x220) < 13.0f && *(s16 *)(v + 0x3D2) != 0) {
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
                            func_0038CF38(o + 0x10, *(u8 **)(v + 0x230) + 0x10) < 8.0f) &&
                           func_L05_0035E640(o) != 0 && *(s16 *)(v + 0x3D0) == 0) {
                    if (o[0x43] != 5) {
                        func_003C3A10(o, 5, 0, 8);
                    }
                    func_L01_004450F0(o, 7, -1);
                    a = *(vu0_v4 *)(o + 0x10);
                    b = *(vu0_v4 *)(v + 0x220);
                    a.z += *(f32 *)(v + 0x78);
                    if (func_003D3CB0(&a, &b, 0, o, 0) != 0 && D_L05_001EA6D8[0] != *(u8 **)(v + 0x230) &&
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

/* localdecomp:start func_L05_0035CE98 */
extern s32 func_L05_0035D078(u8 *);
extern void func_L05_0035D300(u8 *);
extern void func_003C2880(u8 *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_003A6BB0(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, f32, void *, s32, s32, s32, s32, s32, f32, f32, s32, s32);

s32 func_L05_0035CE98(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        if (func_L05_0035D078(a0) != 0) return 1;
    }
    if (p[0x5E] != 0) {
        func_L05_0035D300(a0);
        func_003C2880(a0);
        return 1;
    }
    if (p[0x3E] == 2) {
        func_L05_0035D300(a0);
        return 1;
    }
    if (func_L01_00452FB0(a0, p + 0x160, 0, 0, 0) != 0) func_L01_003A6BB0(a0);
    func_L01_00452860(a0, p + 0x30, 0);
    if (p[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C0), *(f32 *)(p + 0x2C4), 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C8), *(f32 *)(p + 0x2CC), 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        }
    } else {
        func_L01_00456BD0(a0, 3);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C0), *(f32 *)(p + 0x2C4), 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2C8), *(f32 *)(p + 0x2CC), 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
        }
    }
    return 0;
}
/* localdecomp:end func_L05_0035CE98 */

/* localdecomp:start func_L05_0035D078 */
typedef int Q_35D078 __attribute__((mode(TI)));
typedef struct {
 u8 pad000[0x30];
 float f030;
 s16 f034;
 u8 pad036[0x3];
 u8 f039;
 u8 pad03a[0x4];
 u8 f03e;
 u8 f03f;
 float f040;
 u8 pad044[0x14];
 u8 f058;
 u8 pad059[0x1];
 u8 f05a;
 u8 pad05b[0x15];
 float f070;
 float f074;
 float f078;
 float f07c;
 float f080;
 u8 pad084[0x18];
 float f09c;
 float f0a0;
 u8 pad0a4[0xcc];
 u8 f170;
 u8 f171;
 u8 f172;
 u8 pad173[0x3];
 u8 f176;
 u8 pad177[0x5];
 float f17c;
 float f180;
 float f184;
 float f188;
 float f18c;
 float f190;
 float f194;
 s16 f198;
 u8 pad19a[0x2];
 float f19c;
 u8 pad1a0[0x8];
 u8 f1a8;
 u8 f1a9;
 u8 pad1aa[0xe];
 float f1b8;
 float f1bc;
 u8 pad1c0[0xc];
 u8 f1cc;
 u8 f1cd;
 u8 f1ce;
 u8 f1cf;
 u8 pad1d0[0x2];
 u8 f1d2;
 u8 f1d3;
 u8 pad1d4[0x3];
 u8 f1d7;
 u8 f1d8;
 u8 f1d9;
 u8 f1da;
 u8 f1db;
 u8 pad1dc[0x1c4];
 s32 f3a0;
 u8 pad3a4[0xc];
 Q_35D078 f3b0;
} Data_35D078;
extern float D_L05_001DD7B0;
__asm__(".extern D_L05_001DD7B0, 4");
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
s32 func_L05_0035D078(u8 *m) {
 float half_time=0.5f;
 float long_time=0.4000000059604645f;
 float short_time=0.20000000298023224f;
 Data_35D078 *d=*(Data_35D078 **)(m+0x68);
 d->f170=13;
 d->f171=10;
 d->f172=11;
 d->f1a8=3;
 d->f176=12;
 d->f17c=0.32000002f;
 d->f180=0.120000005f;
 d->f184=0.0088f;
 d->f190=half_time;
 d->f188=0.014800001f;
 d->f19c=long_time;
 d->f18c=0.016f;
 d->f1cc=6;
 d->f1cd=12;
 d->f194=half_time;
 d->f1ce=6;
 d->f1d2=8;
 d->f1d3=15;
 d->f1cf=12;
 d->f1da=2;
 d->f1d7=0;
 d->f1db=17;
 d->f198=0;
 d->f1d8=3;
 d->f1bc=long_time;
 d->f1a9=1;
 d->f070=0.699999988079071f;
 d->f1b8=short_time;
 d->f1d9=3;
 d->f074=short_time;
 d->f078=0.75f;

 d->f07c=1.0f;
 d->f080=1.483529806137085f;
 d->f0a0=0.3490658402442932f;
 d->f09c=0.00392f;
 func_L01_0045BD78(m,0.0096f,0.15f,0.010053097f,0.25132743f);
 d->f058=20; d->f05a=14;
 d->f3b0=*(Q_35D078 *)(m+0x10);
 if(d->f034==0) { d->f034=8; d->f030=8.0f; }
 d->f039=1; d->f03e=1; d->f03f=0; d->f040=1.0f;
 *(float *)(m+0x2c)*=D_L05_001DD7B0;
 func_L01_004450F0(m,1,0);
 if(m[0x43]) func_003C3A10(m,0,0,0);
 if(d->f3a0!=-1) {
  func_L01_004450F0(m,2,-1);
  if(m[0x43]!=3) func_003C3A10(m,3,0,0);
 }
 return 0;
}
/* localdecomp:end func_L05_0035D078 */

/* localdecomp:start func_L05_0035D300 */
extern u8 D_001A30B0[];
extern void func_003A4F28(s32);
extern void func_L01_004443E8(u8 *, s32, s32);
extern void func_003C2880(u8 *);

void func_L05_0035D300(u8 *arg0)
{
    u8 *v;
    s32 i;
    u8 *e;

    v = *(u8 **)(arg0 + 104);
    i = *(s32 *)(v + 748);
    if (i != -1) {
        e = D_001A30B0 + (i << 7);
        if (*(u8 **)(e + 220) == arg0 && e[208] != 0) {
            func_003A4F28(i);
        }
    }
    *(s32 *)(v + 748) = -1;
    func_L01_004443E8(arg0, 0, 3);
    func_003C2880(arg0);
}
/* localdecomp:end func_L05_0035D300 */

/* localdecomp:start func_L05_0035D388 */
extern u8 D_001A30B0[];
extern void func_L05_0035D560(s32);
extern void func_L05_0035D590(u8 *);

void func_L05_0035D388(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 h;
    u8 *e;

    func_0038CAD0(v + 0x2D0);
    func_0038CB00(v + 0x2D4);
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        (*(u16 *)(a0 + 0x96))++;
    }
    func_L01_00451DF8(a0, v + 0x240, 6, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L05_001E2700, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
    }
    h = *(s32 *)(v + 0x2EC);
    if (h == -1 || (e = D_001A30B0 + (h << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
        *(s32 *)(v + 0x2EC) = func_003A52A0(1, 4, a0);
    }
    func_L01_00404808(func_L05_0035D560, a0);
    func_L01_00404808(func_L05_0035D590, a0);
}
/* localdecomp:end func_L05_0035D388 */
