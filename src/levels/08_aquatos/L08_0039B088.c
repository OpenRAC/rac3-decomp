#include "common.h"
#include "vu0.h"

typedef int s128_0039AA50 __attribute__((mode(TI)));

/* localdecomp:start func_L08_0039B088 */
extern s32 D_001D6694;
extern s32 D_001D545C;
extern u8 *D_L08_001DF21C;
extern s32 D_L08_001F1FC0[];
extern s32 D_001A71A0[];
extern u8 D_001A4BE0[];

extern s32 func_L08_0039C028(u8 *);
extern void func_L01_004AA7E8(u8 *, s32);
extern s32 func_L01_004561E0(u8 *);
extern s32 func_L01_004561B8(u8 *);
extern s16 func_00382498(s32, s32);
extern s32 func_L01_00456250();
extern s32 func_0038CB00(void *);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L08_0039C480(u8 *);
extern void func_L08_0039CB60(u8 *);
extern void func_L08_0039CF78(u8 *);
extern void func_L08_0039C760(void *);
extern void func_L08_0039C930(u8 *);
extern void func_003C2880(u8 *);
extern f32 func_003C3D30(f32, void *, s32, s32);
extern void func_003C41A0(void *, f32, f32, f32, f32, void *);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_0045BD78(f32, f32, f32, f32, u8 *);
extern void func_0038CF68(f32, void *, void *);
extern void func_L01_0045D218(u8 *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_L01_0045A898(f32, u8 *, void *);
extern void func_L01_00448890(void *, f32, f32, f32, f32, void *, s32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_L01_004395E0(u8 *);
extern s32 func_L01_0044E1B8(f32, u8 *);
extern void func_L01_0045AA30(u8 *, void *);
extern void func_L01_0045A748(u8 *, void *);
extern void func_L01_004468C8(u8 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L08_0042CC70(f32, u8 *, void *, s32, s32, s32);
extern s32 func_L08_0042CDA8(u8 *, void *);
extern s32 func_L01_00454370(u8 *, void *);

/* Field access through a struct member, as the original's structs give: gcc 2.95's alias
 * analysis (MEM_IN_STRUCT_P against a fixed scalar) lets the scheduler move global loads
 * above these stores, as retail does. */
#define U8(p, o) (((struct { u8 _p[o]; u8 v; } *)(p))->v)
#define U16(p, o) (((struct { u8 _p[o]; u16 v; } *)(p))->v)
#define S16(p, o) (((struct { u8 _p[o]; s16 v; } *)(p))->v)
#define S64(p, o) (((struct { u8 _p[o]; long v; } *)(p))->v)
#define S32(p, o) (((struct { u8 _p[o]; s32 v; } *)(p))->v)
#define F32(p, o) (((struct { u8 _p[o]; f32 v; } *)(p))->v)

static inline void restore_flags(u8 *a) {
    u8 *m = *(u8 **)(a + 0x24);
    U16(a, 0x34) &= ~0x41;
    U16(a, 0x34) |= U16(m, 0x44) & 0x1000;
    S32(a, 0x98) = S32(m, 0x10);
}

void func_L08_0039B088(u8 *a) {
    vu0_v4 v;
    vu0_v4 d;
    vu0_v4 s;
    vu0_v4 dir;
    u8 *st = *(u8 **)(a + 0x68);
    u8 *m;
    s32 t;
    s32 ok;
    f32 ang, r, f;
    u8 *rot;
    u8 *rot3;
    f32 *pz;

    if (func_L08_0039C028(a) != 0) goto kill;

    if (D_001D6694 == 2) {
        if ((U8(a, 0x34) ^ 1) & 1) {
            S32(a, 0x98) = 0;
            U16(a, 0x34) = (U16(a, 0x34) | 0x41) & ~0x1000;
            func_L01_004AA7E8(a, 1);
            S32(st, 0x328) = 1;
        }
        return;
    }

    if (S32(st, 0x328) != 0) {
        restore_flags(a);
        S32(st, 0x328) = 0;
    }

    switch (U8(a, 0x95)) {
    case 0:
        if (func_L01_004561E0(a) != 0 && S16(st, 0x2D6) == 0) {
            S16(st, 0x2D6) = (func_00382498(0, 100) * 5 + 2) / 6;
        }
        if (D_001D545C != 8) {
            ok = 1;
        } else if (S32(st, 0x300) == -1) {
            ok = 1;
        } else {
            ok = func_L01_00456250(D_L08_001DF21C + (S32(st, 0x300) << 8)) != 0;
        }
        if (S32(st, 0x314) != 0) {
            S32(a, 0x98) = 0;
            U16(a, 0x34) = (U16(a, 0x34) | 0x41) & ~0x1000;
            func_L01_004AA7E8(a, 1);
        }
        if (S16(st, 0x234) == 1 && func_0038CB00(st + 0x2D6) != 0 && ok) {
            if (U8(a, 0x43) != 0) {
                func_003C3A10(a, 0, 0, 8);
            }
            func_L01_004450F0(a, 5, 2);
            if (S32(st, 0x314) != 0) {
                restore_flags(a);
                if (U8(a, 0x43) != 9) {
                    func_003C3A10(a, 9, 1, 2);
                }
                F32(st, 0x324) = F32(a, 0xF8);
                func_L01_004450F0(a, 3, -1);
            }
        } else if (S32(st, 0x2D8) != 0 && func_0038CB00(st + 0x2D6) != 0) {
            func_L01_004450F0(a, 4, 1);
            S32(st, 0x2D8) = 0;
            if (S32(st, 0x2D0) < 250) {
                S32(st, 0x2D0) = (func_00382498(480, 600) * 5 + 2) / 6;
            }
        }
        break;
    case 4:
        if (S32(st, 0x300) != -1) {
            m = D_L08_001DF21C + (S32(st, 0x300) << 8);
            if (S32(st, 0x304) == 0) {
                if (m == 0 || U8(m, 0x20) == 0xFE || U8(m, 0x20) == 0xFD) {
                    restore_flags(a);
                    if (U8(a, 0x43) != 0) {
                        func_003C3A10(a, 0, 0, 8);
                    }
                    func_L01_004450F0(a, 5, 2);
                }
            } else if (S32(st, 0x304) == 1 && func_L01_00456250(m) != 0) {
                restore_flags(a);
                if (U8(a, 0x43) != 0) {
                    func_003C3A10(a, 0, 0, 8);
                }
                func_L01_004450F0(a, 5, 2);
            }
        } else if (S32(st, 0x308) != -1) {
            u8 *o = D_L08_001DF21C + (S32(st, 0x308) << 8);
            if (o == 0 || U8(o, 0x20) == 0xFE || U8(o, 0x20) == 0xFD) {
                restore_flags(a);
                if (U8(a, 0x43) != 0) {
                    func_003C3A10(a, 0, 0, 8);
                }
                func_L01_004450F0(a, 5, 2);
            }
        }
        break;
    case 1:
        if (S16(st, 0x234) == 1) {
            if (U8(a, 0x43) != 0) {
                func_003C3A10(a, 0, 0, 8);
            }
            func_L01_004450F0(a, 5, 2);
        } else if (S32(st, 0x2D0) == 0) {
            func_L01_004450F0(a, 1, 0);
        }
        break;
    case 2:
        if (S16(st, 0x234) != 1 && func_L01_004561E0(a) == 0) {
            func_L01_004450F0(a, 1, 0);
            if (U8(a, 0x43) != 3) {
                func_003C3A10(a, 3, 0, 8);
            }
            S32(st, 0x2D0) = (func_00382498(580, 600) * 5 + 2) / 6;
        }
        break;
    case 3:
        t = func_L01_00454370(a, st + 0x160);
        if ((t & 1) || F32(st, 0x30) <= 0.0f) {
            func_L08_0039C480(a);
            func_L08_0039CB60(a);
            S32(a, 0x98) = 0;
            U16(a, 0x34) |= 0x41;
            func_L01_004450F0(a, 10, 5);
            return;
        }
        if ((t & 2) || func_L01_004395E0(a) > 17.0f) {
            if (S16(st, 0x234) == 1) {
                if (U8(a, 0x43) != 0) {
                    func_003C3A10(a, 0, 0, 6);
                }
                func_L01_004450F0(a, 5, 2);
            } else {
                func_L01_004450F0(a, 4, 1);
                S32(st, 0x2D0) = (func_00382498(580, 600) * 5 + 2) / 6;
            }
        }
        break;
    }

    switch (U8(a, 0x20)) {
    case 1:
        if ((U8(a, 0x60) & 2) && S64(st, 0x310) == 0) {
            if (U8(a, 0x43) != 0) {
                func_003C3A10(a, 0, 0, 8);
            }
            func_L01_004450F0(a, 2, -1);
        }
        break;
    case 10:
        func_L08_0039CF78(a);
        if (U16(a, 0x96) < 34) break;
    kill:
        func_003C2880(a);
        return;
    case 2:
        if (func_L01_004561B8(a) != 0) {
            ang = func_00382538();
            r = func_003824E0(4.0f, 8.0f);
            qzero(st + 0x2F0);
            F32(st, 0x2F0) = func_0038D098(ang) * r;
            F32(st, 0x2F4) = func_0038D0B0(ang) * r;
            vec_add_ab(st + 0x2F0, st + 0x2F0, st + 0x2E0);
            S16(st, 0x2D4) = func_00382498(300, 530);
            if (D_001D545C == 0x1C) {
                S32(st, 0xA8) |= 4;
                F32(st, 0x7C) = F32(st, 0x78) = 0.7f;
                U16(a, 0x34) |= 0x100;
                F32(st, 0x80) = 12.566371f;
                S32(st, 0xA8) |= 1;
            }
            func_L01_0045BD78(0.0064000003f, 0.080000006f, 0.010053097f, 0.25132743f, a);
        }
        if (D_001D545C == 0x1C) {
            func_0038CF68(3.0f, &d, a + 0xC0);
            vec_add_ba(&v, a + 0x10, &d);
            func_L01_0045D218(a, &v);
            if (func_0038DBA0(F32(a, 0xF8), func_0038D160(F32(st, 0x2F0) - F32(a, 0x10), F32(st, 0x2F4) - F32(a, 0x14))) > 0.17453292f) {
                func_0038D890(a + 0xC0, a + 0xC0, a + 0xE0, 0.09075713f);
                func_0038D890(a + 0xD0, a + 0xD0, a + 0xE0, 0.09075713f);
                F32(a, 0xF8) = func_0038D160(F32(a, 0xC0), F32(a, 0xC4));
            }
        } else {
            u8 *rot2;
            func_L01_0045A898(F32(a, 0xF8), a, st + 0x2F0);
            rot2 = a + 0xF8;
            func_L01_00448890(rot2, func_0038D160(F32(st, 0x2F0) - F32(a, 0x10), F32(st, 0x2F4) - F32(a, 0x14)), 0.0050265486f, 0.0050265486f, 0.12566371f, st + 0x2DC, 0);
        }
        if (func_0038CF38(a + 0x10, st + 0x2F0) < 0.75f) {
            ang = func_00382538();
            r = func_003824E0(2.0f, 6.0f);
            qzero(st + 0x2F0);
            F32(st, 0x2F0) = func_0038D098(ang) * r;
            F32(st, 0x2F4) = func_0038D0B0(ang) * r;
            vec_add_ab(st + 0x2F0, st + 0x2F0, st + 0x2E0);
        }
        if (func_0038CB00(st + 0x2D4) != 0) {
            if (U8(a, 0x43) != 4) {
                func_003C3A10(a, 4, 0, 8);
            }
            func_L01_004450F0(a, 1, -1);
        }
        func_L08_0039C930(a);
        break;
    case 3:
        rot = a + 0xF8;
        func_L01_00448890(rot, func_0038D160(F32(st, 0x220) - F32(a, 0x10), F32(st, 0x224) - F32(a, 0x14)), 0.004886922f, 0.0018849557f, 0.06981318f, st + 0x2DC, 0);
        if (func_L01_004561B8(a) != 0) {
            S32(st, 0x314) = 0;
            F32(st, 0x2E8) = F32(a, 0x18);
            F32(st, 0x2F8) = F32(a, 0x18);
        }
        if (U8(a, 0x42) == 9) {
            f = func_L01_004395E0(a);
            if (f > 8.0f && f < 19.0f) {
                dir.x = func_0038D098(F32(st, 0x324));
                dir.y = func_0038D0B0(F32(st, 0x324));
                dir.z = 0.0f;
                func_0038CF68(0.13636364f, &s, &dir);
                vec_add_ba(&v, a + 0x10, &s);
            }
            if (f > 8.0f && f < 14.0f) {
                func_003C41A0(&v.z, F32(st, 0x2F8) + 1.5f + 1.0f, 0.75f, 1.5f, 0.1875f, st + 0x318);
            }
            if (f == 14.0f) {
                S32(st, 0x318) = 0;
            }
            if (f > 14.0f && f < 19.0f) {
                F32(a, 0x48) = 0.7f;
                pz = &v.z;
                func_003C41A0(pz, func_003C3D30(0.5f, a + 0x10, 0, 0), 0.14999999f, 1.8f, 0.089999996f, st + 0x318);
            }
            if (f > 8.0f && f < 19.0f) {
                vec_sub_ab(&d, &v, a + 0x10);
                func_L01_0045AA30(a, &d);
            }
        }
        if (U8(a, 0x60) & 2) {
            F32(a, 0x48) = 1.0f;
            func_L01_004450F0(a, 5, -1);
            if (U8(a, 0x43) != 0) {
                func_003C3A10(a, 0, 0, 5);
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(a) != 0) {
            if (D_001D545C == 0x1C) {
                S32(st, 0xA8) |= 4;
                F32(st, 0x7C) = F32(st, 0x78) = 0.7f;
                U16(a, 0x34) |= 0x100;
                F32(st, 0x80) = 12.566371f;
                S32(st, 0xA8) |= 1;
            }
            func_L01_0045BD78(0.0064000003f, 0.080000006f, 0.010053097f, 0.25132743f, a);
        }
        if (D_001D545C == 0x1C) {
            func_L01_0045D218(a, st + 0x220);
            F32(a, 0xF8) = func_0038D160(F32(a, 0xC0), F32(a, 0xC4));
        } else {
            func_L01_0045A748(a, st + 0x220);
        }
        if (func_0038CF38(a + 0x10, st + 0x220) < 1.5f
            && func_0038DBA0(F32(a, 0xF8), func_0038D160(F32(st, 0x220) - F32(a, 0x10), F32(st, 0x224) - F32(a, 0x14))) < 0.43633232f) {
            if (U8(a, 0x43) != 1) {
                func_003C3A10(a, 1, 0, 8);
            }
            func_L01_004450F0(a, 6, -1);
        }
        func_L08_0039C930(a);
        break;
    case 6:
        if (func_L01_004561B8(a) != 0) {
            if (D_001D545C == 0x1C) {
                S32(st, 0xA8) |= 4;
                F32(st, 0x7C) = F32(st, 0x78) = 0.7f;
                U16(a, 0x34) |= 0x100;
                F32(st, 0x80) = 12.566371f;
                S32(st, 0xA8) |= 1;
            }
            func_L01_0045BD78(0.051200002f, 0.56000006f, 0.010053097f, 0.25132743f, a);
        }
        if (U8(a, 0x42) == 1 && func_L01_0044E1B8(30.0f, a) != 0) {
            func_L01_004450F0(a, 7, -1);
            if (U8(a, 0x43) != 7) {
                func_003C3A10(a, 7, 0, 5);
            }
        }
        if (func_L01_004395E0(a) > 11.0f && func_L01_004395E0(a) < 18.0f && U8(a, 0x42) == 1) {
            func_L01_004468C8(a, 0, S32(st, 0x230) == D_001A71A0[0] ? 1 : 0x10001, 0, 1, 0, 0.75f, (f32)U8(st, 0x45), 1.5f);
        }
        break;
    case 7:
        if (U8(a, 0x60) & 2) {
            func_L01_004450F0(a, 5, -1);
            if (U8(a, 0x43) != 0) {
                func_003C3A10(a, 0, 0, 8);
            }
        }
        break;
    }
    func_L08_0039C760(a);
}
/* localdecomp:end func_L08_0039B088 */

/* localdecomp:start func_L08_0039C028 */
typedef int q_0039C028 __attribute__((mode(TI)));
extern s32 func_L08_0039C220(void *);
extern void func_L08_0039C480(void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_003A6BB0(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L08_0039C028(void *arg) {
    u8 *a = arg;
    u8 *v = *(u8 **)(a + 0x68);
    u8 *m;

    if (a[0x20] == 0 && func_L08_0039C220(a)) {
        return 1;
    }
    if (v[0x3E] == 2) {
        func_L08_0039C480(a);
        return 1;
    }
    m = (u8 *)func_L01_00447490(a, 0x10000, 0);
    if (m != 0) {
        *(q_0039C028 *)(v + 0x330) = *(q_0039C028 *)(m + 0x10);
    }
    if (func_L01_00452FB0(a, v + 0x160, 0, 0, 0)) {
        func_L01_003A6BB0(a);
    }
    func_L01_00452860(a, v + 0x30, 0);
    if (v[0x5E] != 0) {
        func_L08_0039C480(a);
        return 1;
    }
    if (v[0x5F] != 0) {
        func_L01_00456BD0(a, 5);
        if (a[0x95] == 0) {
            func_L01_00456C98(a, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        if (a[0x95] == 2) {
            func_L01_00456BD0(a, 3);
        }
        if (a[0x95] == 0) {
            func_L01_00456C98(a, *(s32 *)(v + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(a, *(s32 *)(v + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(v + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L08_0039C028 */

/* localdecomp:start func_L08_0039C220 */
#include "vu0.h"
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 p20[0x14]; u16 h34; u8 p36[0xD]; u8 b43; u8 p44[0x24]; u8 *p68;
    u8 p6C[0x2C]; s32 w98;
} M_0039C220;
typedef struct {
    u8 p0[0x30]; f32 f30; s16 h34; u8 p36[3]; u8 b39; u8 p3A[4]; u8 b3E; u8 b3F; f32 f40;
    u8 p44[0x14]; u8 b58; u8 p59; u8 b5A; u8 p5B[0x15]; f32 f70; f32 f74; f32 f78; f32 f7C; f32 f80;
    u8 p84[0x18]; f32 f9C; f32 fA0; u8 pA4[0xCC]; u8 b170; u8 p171[0x1F];
    f32 f190; f32 f194; u8 p198[4]; f32 f19C; u8 p1A0[8]; u8 b1A8;
    u8 p1A9[0x2E]; u8 b1D7; u8 b1D8; u8 b1D9; u8 b1DA; u8 b1DB; u8 p1DC[0x34]; f32 f210;
    u8 p214[0xCC]; vu0_v4 v2E0; u8 p2F0[0x10]; s32 w300; u8 p304[4]; s32 w308; u8 p30C[8];
    s32 w314; u8 p318[4]; f32 f31C;
} P_0039C220;
extern s32 D_001D545C;
extern f32 func_00382538(void);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);

s32 func_L08_0039C220(void *arg) {
    M_0039C220 *m = arg;
    P_0039C220 *p = (P_0039C220 *)m->p68;
    f32 h;
    f32 z;

    p->v2E0 = m->pos;
    p->f31C = func_00382538();
    p->b170 = 8;
    p->b1A8 = 3;
    p->f19C = 0.15f;
    p->f190 = 0.5f;
    p->b1DB = 0xFF;
    p->f194 = 0.5f;
    p->b1D7 = 1;
    p->b1D8 = 0;
    p->b1D9 = 0;
    p->b1DA = 0;
    p->f210 = 1.0f;
    p->f70 = 0.5f;
    p->f74 = 0.25f;
    p->f78 = 1.0f;
    p->f7C = 1.25f;
    p->f80 = 1.6580628f;
    p->fA0 = 0.34906584f;
    p->f9C = 0.00392f;
    func_L01_0045BD78(m, 0.0064000003f, 0.080000006f, 0.010053097f, 0.25132743f);
    p->b58 = 0x14;
    p->b5A = 0xE;
    if (p->h34 == 0) {
        p->h34 = 1;
        p->f30 = 1.0f;
    }
    p->f40 = 1.0f;
    p->b39 = 1;
    p->b3E = 1;
    p->b3F = 0;
    func_L01_004450F0(m, 1, 0);
    if (m->b43 != 3) func_003C3A10(m, 3, 0, 0);
    if ((p->w300 != -1 || p->w308 != -1) && D_001D545C != 8) {
        func_L01_004450F0(m, 9, 4);
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
    }
    if (p->w314 != 0) {
        h = func_003C3D30(&m->pos, 0, 0, 0.5f);
        z = m->pos.z;
        if (z - h > 3.0f) h = z;
        m->pos.z = h - 1.0f;
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
    }
    return 0;
}
/* localdecomp:end func_L08_0039C220 */

/* localdecomp:start func_L08_0039C480 */
/* PAL port of the NTSC-U match src/us/levels/func_L08_0039AA50.c */
#include "vu0.h"

extern s32 D_001D545C;
extern f32 D_L08_001DA8B8;
extern u8 D_1426E0[];
extern f32 D_L08_002F0F30[];
extern s32 func_003A52A0(s32, s32, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);
extern void func_L01_0044A7D0(void *);
extern s32 func_L01_0041A4F0(void);
extern void func_L08_0039E658(void *);
extern void func_003C3938(void *, s32, s32);
extern void func_L01_004443E8(void *, s32, s32);

void func_L08_0039C480(u8 *self) {
    vu0_v4 vec;
    u8 *s3;
    u8 *s0;
    u8 *obj;
    f32 f;
    f32 g;
    s32 i;

    s3 = *(u8 **)(self + 0x68);
    func_003A52A0(0, 0, self);
    func_003A52A0(1, 0, self);
    for (i = 0; i < 2; i++) {
        obj = func_003C24B0(0x1968, 0x260);
        if (obj != 0) {
            *(s128_0039AA50 *)(obj + 0xF0) = *(s128_0039AA50 *)(self + 0xF0);
            func_L01_00456160(obj, self);
            *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x20;
            func_L01_0044A7D0(obj);
            obj[0xB0] = self[0xB0];
            s0 = *(u8 **)(obj + 0x68);
            *(s32 *)(s0 + 0x180) = *(s32 *)(s3 + 0x2C0);
            *(s32 *)(s0 + 0x188) = *(s32 *)(s3 + 0x2C8);
            *(f32 *)(s0 + 0x18C) = *(f32 *)(s3 + 0x2CC);
            *(f32 *)(s0 + 0x184) = *(f32 *)(s3 + 0x2C4);
            *(u8 **)(s0 + 0x1C) = s0 + 0x70;
            *(u8 **)(s0 + 0xC) = s0 + 0x160;
            *(u8 **)(s0 + 0x0) = s0 + 0x30;
            *(s16 *)(s0 + 0x36) = 25;
            f = (f32)s0[0x44];
            if (func_L01_0041A4F0() != 0) {
                if (D_001D545C != 7 || D_1426E0[0x7B] == 0) {
                    g = f * D_L08_002F0F30[D_001D545C];
                } else {
                    g = f * D_L08_001DA8B8;
                }
            } else {
                g = f;
            }
            s0[0x44] = (s32)g;
            f = (f32)s0[0x45];
            if (func_L01_0041A4F0() != 0) {
                if (D_001D545C != 7 || D_1426E0[0x7B] == 0) {
                    g = f * D_L08_002F0F30[D_001D545C];
                } else {
                    g = f * D_L08_001DA8B8;
                }
            } else {
                g = f;
            }
            s0[0x45] = (s32)g;
            func_L08_0039E658(obj);
            *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + 0.5f;
            func_L01_004450F0(obj, 2, 1);
            *(s128_0039AA50 *)(s0 + 0x1E0) = *(s128_0039AA50 *)(s3 + 0x330);
            func_003C3938(obj, 6, 0);
            *(s32 *)(s0 + 0x1DC) = i;
            *(s32 *)(s0 + 0x190) = 500;
            if (i == 0) {
                if (D_001D545C == 0x1C) {
                    func_0038CF68(1.0f, &vec, self + 0xD0);
                } else {
                    func_0038CF68(0.57f, &vec, self + 0xD0);
                }
            } else {
                if (D_001D545C == 0x1C) {
                    func_0038CF68(-1.0f, &vec, self + 0xD0);
                } else {
                    func_0038CF68(-0.57f, &vec, self + 0xD0);
                }
            }
            vec_add_ab(obj + 0x10, &vec, self + 0x10);
            *(s16 *)(obj + 0xB6) = 0x14;
        }
    }
    func_L01_004443E8(self, 0, 3);
}
/* localdecomp:end func_L08_0039C480 */

/* localdecomp:start func_L08_0039C760 */
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L05_0035E050(void);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00451DF8(void *, f32, void *, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_0038CAD0(void *);
extern u8 D_L08_001E1D40[];
__asm__(".extern D_L08_001E1D40, 16");

void func_L08_0039C760(void *arg0) {
    u8 *v17;
    f32 f;
    f32 r;
    u16 t;

    v17 = *(u8 **)((u8 *)arg0 + 0x68);
    func_0038CAD0(v17 + 0x2D0);
    t = *(u16 *)((u8 *)arg0 + 0x96);
    if (t <= 0xFFFE) {
        *(u16 *)((u8 *)arg0 + 0x96) = t + 1;
    }
    if (*(u8 *)((u8 *)arg0 + 0x31) != 0) {
        func_L01_00404808((void *) func_L05_0035E050, arg0);
    }
    func_L01_00451DF8(arg0, 2.5f, v17 + 0x240, 1, 1);
    if (*(u8 *)((u8 *)arg0 + 0x31) != 0) {
        f = func_L01_0040E548(D_L08_001E1D40, (u8 *)arg0 + 0x10);
        if (f < 576.0f) {
            func_L01_004472C0(arg0);
            *(u8 *)((u8 *)arg0 + 0x6F) = 0x16;
        }
    }
    r = func_0038DAB8(*(f32 *)(v17 + 0x31C), 0.15358898f);
    *(f32 *)(v17 + 0x31C) = r;
    r = func_0038D0B0(r);
    *(s32 *)((u8 *)arg0 + 0x78) = func_0038DBD8((r + 1.0f) * 0.5f, 0x8000A0A0, 0x80005050);
}
/* localdecomp:end func_L08_0039C760 */
