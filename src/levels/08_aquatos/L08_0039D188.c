#include "common.h"
#include "vu0.h"

typedef int u128_0039CB58 __attribute__((mode(TI)));

/* localdecomp:start func_L08_0039D188 */
extern s32 D_001D6694;
extern s32 D_001D545C;
extern u8 *D_L08_001DF21C;
extern s32 D_L08_001F1FC0[];
extern s32 D_001A71A0[];
extern u8 D_001A4BE0[];

extern s32 func_L08_0039E430(u8 *);
extern void func_L01_004AA7E8(u8 *, s32);
extern s32 func_L01_004561E0(u8 *);
extern s32 func_L01_004561B8(u8 *);
extern s16 func_00382498(s32, s32);
extern s32 func_L01_00456250();
extern s32 func_0038CB00(void *);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L08_0039E8C8(u8 *);
extern void func_L08_0039EFB0(u8 *);
extern void func_L08_0039F3C8(u8 *);
extern void func_L08_0039EBC0(u8 *);
extern void func_L08_0039ED70(u8 *);
extern void func_003C2880(u8 *);
extern f32 func_003C3D30(void *, f32, s32, s32);
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

/* Field access through a struct member, as the original's structs give: gcc 2.95's alias
 * analysis (MEM_IN_STRUCT_P against a fixed scalar) lets the scheduler move global loads
 * above these stores, as retail does. */
#define U8(p, o) (((struct { u8 _p[o]; u8 v; } *)(p))->v)
#define U16(p, o) (((struct { u8 _p[o]; u16 v; } *)(p))->v)
#define S16(p, o) (((struct { u8 _p[o]; s16 v; } *)(p))->v)
#define S32(p, o) (((struct { u8 _p[o]; s32 v; } *)(p))->v)
#define F32(p, o) (((struct { u8 _p[o]; f32 v; } *)(p))->v)

static inline void restore_flags(u8 *a) {
    u8 *m = *(u8 **)(a + 0x24);
    U16(a, 0x34) &= ~0x41;
    U16(a, 0x34) |= U16(m, 0x44) & 0x1000;
    S32(a, 0x98) = S32(m, 0x10);
}

void func_L08_0039D188(u8 *a) {
    vu0_v4 v;
    vu0_v4 d;
    vu0_v4 s;
    vu0_v4 dir;
    u8 *st = *(u8 **)(a + 0x68);
    u8 *m;
    s32 t;
    s32 ok;
    f32 ang, r, f, g, q;
    u8 *rot;
    u8 *rot3;
    f32 *pz;
    u8 *h;

    if (func_L08_0039E430(a) != 0) goto kill;

    if (D_001D6694 == 2) {
        if ((U8(a, 0x34) ^ 1) & 1) {
            S32(a, 0x98) = 0;
            U16(a, 0x34) = (U16(a, 0x34) | 0x41) & ~0x1000;
            func_L01_004AA7E8(a, 1);
            S32(st, 0x250) = 1;
        }
        return;
    }

    if (S32(st, 0x250) != 0) {
        restore_flags(a);
        S32(st, 0x250) = 0;
    }

    switch (U8(a, 0x95)) {
    case 0:
        if (func_L01_004561E0(a) != 0 && S16(st, 0x196) == 0) {
            S16(st, 0x196) = (func_00382498(0, 100) * 5 + 2) / 6;
        }
        if (S32(st, 0x1C4) == 1) {
            S32(a, 0x98) = 0;
            U16(a, 0x34) = (U16(a, 0x34) | 0x41) & ~0x1000;
            func_L01_004AA7E8(a, 1);
        }
        if (S16(st, 0x174) == 1 && U8(a, 0x20) != 1 && U8(a, 0x20) != 2 && func_0038CB00(st + 0x196) != 0) {
            if (U8(a, 0x43) != 0) {
                func_003C3A10(a, 0, 0, 8);
            }
            func_L01_004450F0(a, 7, 2);
            if (S32(st, 0x1C4) == 1) {
                restore_flags(a);
                if (U8(a, 0x43) != 5) {
                    func_003C3A10(a, 5, 2, 2);
                }
                F32(st, 0x1D8) = F32(a, 0xF8);
                func_L01_004450F0(a, 6, -1);
            }
        } else if (S32(st, 0x198) != 0) {
            func_L01_004450F0(a, 5, 1);
            S32(st, 0x198) = 0;
            if (S32(st, 0x190) < 250) {
                S32(st, 0x190) = (func_00382498(480, 600) * 5 + 2) / 6;
            }
        }
        break;
    case 4:
        if (S32(st, 0x1C0) != -1) {
            m = D_L08_001DF21C + (S32(st, 0x1C0) << 8);
            if (S32(st, 0x1C4) == 0) {
                if (m == 0 || U8(m, 0x20) == 0xFE || U8(m, 0x20) == 0xFD) {
                    restore_flags(a);
                    if (U8(a, 0x43) != 2) {
                        func_003C3A10(a, 2, 0, 8);
                    }
                    func_L01_004450F0(a, 1, 2);
                }
            } else if (S32(st, 0x1C4) == 1 && func_L01_00456250(m) != 0) {
                restore_flags(a);
                if (U8(a, 0x43) != 2) {
                    func_003C3A10(a, 2, 0, 8);
                }
                func_L01_004450F0(a, 1, 2);
            }
        } else if (S32(st, 0x1C8) != -1) {
            u8 *o = D_L08_001DF21C + (S32(st, 0x1C8) << 8);
            if (o == 0 || U8(o, 0x20) == 0xFE || U8(o, 0x20) == 0xFD) {
                restore_flags(a);
                if (U8(a, 0x43) != 2) {
                    func_003C3A10(a, 2, 0, 8);
                }
                func_L01_004450F0(a, 1, 2);
            }
        }
        break;
    case 1:
        if (S16(st, 0x174) == 1 && U8(a, 0x20) != 1 && U8(a, 0x20) != 2) {
            if (U8(a, 0x43) != 0) {
                func_003C3A10(a, 0, 0, 8);
            }
            func_L01_004450F0(a, 7, 2);
        } else if (S32(st, 0x190) == 0) {
            func_L01_004450F0(a, 3, 0);
        }
        break;
    case 2:
        if (S16(st, 0x174) != 1 && func_L01_004561E0(a) == 0) {
            func_L01_004450F0(a, 4, 0);
            if (U8(a, 0x43) != 0) {
                func_003C3A10(a, 0, 0, 0);
            }
            S32(st, 0x190) = (func_00382498(580, 600) * 5 + 2) / 6;
        }
        break;
    case 3:
        if (F32(st, 0x30) <= 0.0f) {
            func_L08_0039E8C8(a);
            func_L08_0039EFB0(a);
            S32(a, 0x98) = 0;
            U16(a, 0x34) |= 0x41;
            func_L01_004450F0(a, 11, 5);
            return;
        }
        if (U8(a, 0x43) != 0) {
            func_003C3A10(a, 0, 0, 8);
        }
        func_L01_004450F0(a, 7, 2);
        break;
    }

    switch (U8(a, 0x20)) {
    case 1:
        if (func_L01_004561B8(a) != 0) {
            if (U8(a, 0x43) != 2) {
                func_003C3A10(a, 2, 2, 2);
            }
            S16(st, 0x36) = 0x21;
                if (D_001D545C == 0x1C) {
                    S32(st, 0xA8) |= 4;
                    F32(st, 0x7C) = F32(st, 0x78) = 0.7f;
                    U16(a, 0x34) |= 0x100;
                    F32(st, 0x80) = 12.566371f;
                    S32(st, 0xA8) |= 1;
                }
        }
        if (D_L08_001F1FC0[0] != 1) {
            func_003C41A0(a + 0x18, func_003C3D30(a + 0x10, 0.5f, 0, 0), 0.00392f, 0.00392f, 0.16000001f, st + 0x19C);
        }
        if (U8(a, 0x60) & 2) {
            func_L01_004450F0(a, 3, -1);
            if (U8(a, 0x43) != 1) {
                func_003C3A10(a, 1, 0, 8);
            }
        }
    case 3:
        if ((D_L08_001F1FC0[0] != 0 || S32(st, 0x1C4) == 0) && (U8(a, 0x60) & 2)) {
            if (U8(a, 0x43) != 0) {
                func_003C3A10(a, 0, 0, 8);
            }
            func_L01_004450F0(a, 4, -1);
        }
        break;
    case 11:
        func_L08_0039F3C8(a);
        if (U16(a, 0x96) < 26) break;
        goto kill;
    case 4:
        if (func_L01_004561B8(a) != 0) {
            if (D_001D545C == 0x1C) {
                S32(st, 0xA8) |= 4;
                F32(st, 0x7C) = F32(st, 0x78) = 0.7f;
                U16(a, 0x34) |= 0x100;
                F32(st, 0x80) = 12.566371f;
                S32(st, 0xA8) |= 1;
            }
            ang = func_00382538();
            r = func_003824E0(4.0f, 8.0f);
            qzero(st + 0x1B0);
            F32(st, 0x1B0) = func_0038D098(ang) * r;
            F32(st, 0x1B4) = func_0038D0B0(ang) * r;
            vec_add_ab(st + 0x1B0, st + 0x1B0, st + 0x1A0);
            S16(st, 0x194) = func_00382498(300, 530);
            func_L01_0045BD78(0.0032000002f, 0.040000003f, 0.010053097f, 0.25132743f, a);
        }
        if (D_001D545C == 0x1C) {
            func_0038CF68(3.0f, &d, a + 0xC0);
            vec_add_ba(&v, a + 0x10, &d);
            func_L01_0045D218(a, &v);
            if (func_0038DBA0(F32(a, 0xF8), func_0038D160(F32(st, 0x1B0) - F32(a, 0x10), F32(st, 0x1B4) - F32(a, 0x14))) > 0.17453292f) {
                func_0038D890(a + 0xC0, a + 0xC0, a + 0xE0, 0.09075713f);
                func_0038D890(a + 0xD0, a + 0xD0, a + 0xE0, 0.09075713f);
                F32(a, 0xF8) = func_0038D160(F32(a, 0xC0), F32(a, 0xC4));
            }
        } else {
            u8 *rot2;
            func_L01_0045A898(F32(a, 0xF8), a, st + 0x1B0);
            rot2 = a + 0xF8;
            func_L01_00448890(rot2, func_0038D160(F32(st, 0x1B0) - F32(a, 0x10), F32(st, 0x1B4) - F32(a, 0x14)), 0.0050265486f, 0.0050265486f, 0.12566371f, st + 0x19C, 0);
        }
        if (func_0038CF38(a + 0x10, st + 0x1B0) < 0.75f) {
            ang = func_00382538();
            r = func_003824E0(2.0f, 6.0f);
            qzero(st + 0x1B0);
            F32(st, 0x1B0) = func_0038D098(ang) * r;
            F32(st, 0x1B4) = func_0038D0B0(ang) * r;
            vec_add_ab(st + 0x1B0, st + 0x1B0, st + 0x1A0);
        }
        if (func_0038CB00(st + 0x194) != 0) {
            if (U8(a, 0x43) != 1) {
                func_003C3A10(a, 1, 0, 8);
            }
            func_L01_004450F0(a, 3, -1);
        }
        func_L08_0039ED70(a);
        break;
    case 6:
        rot = a + 0xF8;
        func_L01_00448890(rot, func_0038D160(F32(st, 0x160) - F32(a, 0x10), F32(st, 0x164) - F32(a, 0x14)), 0.004886922f, 0.0018849557f, 0.06981318f, st + 0x19C, 0);
        if (func_L01_004561B8(a) != 0) {
            S32(st, 0x1C4) = 0;
            func_L08_0039EFB0(a);
            F32(st, 0x1A8) = F32(a, 0x18);
            F32(st, 0x1B8) = F32(a, 0x18);
        }
        f = func_L01_004395E0(a);
        if (U8(a, 0x42) == 5) {
            F32(a, 0x48) = 0.7f;
            if (f > 6.0f && f < 18.0f) {
                dir.x = func_0038D098(F32(st, 0x1D8));
                dir.y = func_0038D0B0(F32(st, 0x1D8));
                dir.z = 0.0f;
                func_0038CF68(0.125f, &s, &dir);
                vec_add_ba(&v, a + 0x10, &s);
            }
            if (f > 6.0f && f < 14.0f) {
                func_003C41A0(&v.z, F32(st, 0x1B8) + 1.5f + 1.0f, 0.5625f, 1.125f, 0.140625f, st + 0x1D4);
            }
            if (f == 14.0f) {
                S32(st, 0x1D4) = 0;
            }
            if (f > 14.0f && f < 18.0f) {
                F32(a, 0x48) = 0.7f;
                pz = &v.z;
                func_003C41A0(pz, func_003C3D30(a + 0x10, 0.5f, 0, 0), 0.1875f, 2.25f, 0.1125f, st + 0x1D4);
            }
            if (f > 6.0f && f < 18.0f) {
                vec_sub_ab(&d, &v, a + 0x10);
                func_L01_0045AA30(a, &d);
            }
        }
        if (f > 21.0f) {
            F32(a, 0x48) = 1.0f;
            func_L01_004450F0(a, 7, -1);
            if (U8(a, 0x43) != 0) {
                func_003C3A10(a, 0, 0, 6);
            }
        }
        break;
    case 7:
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
            func_L01_0045D218(a, st + 0x160);
            F32(a, 0xF8) = func_0038D160(F32(a, 0xC0), F32(a, 0xC4));
        } else {
            func_L01_0045A748(a, st + 0x160);
        }
        if (func_0038CF38(a + 0x10, st + 0x160) < 1.5f
            && func_0038DBA0(F32(a, 0xF8), func_0038D160(F32(st, 0x160) - F32(a, 0x10), F32(st, 0x164) - F32(a, 0x14))) < 0.43633232f) {
            if (U8(a, 0x43) != 4) {
                func_003C3A10(a, 4, 0, 8);
            }
            func_L01_004450F0(a, 8, -1);
        }
        func_L08_0039ED70(a);
        break;
    case 8:
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
        if (U8(a, 0x42) == 4 && func_L01_0044E1B8(30.0f, a) != 0) {
            func_L01_004450F0(a, 9, -1);
            if (U8(a, 0x43) != 3) {
                func_003C3A10(a, 3, 1, 5);
            }
        }
        if (func_L01_004395E0(a) > 11.0f && func_L01_004395E0(a) < 18.0f && U8(a, 0x42) == 4) {
            func_L01_004468C8(a, 0, S32(st, 0x170) == D_001A71A0[0] ? 1 : 0x10001, 0, 1, 0, 0.75f, (f32)U8(st, 0x45), 1.5f);
        }
        break;
    case 2: {
        if (func_L01_004561B8(a) != 0) {
            F32(st, 0x200) = func_003824E0(0.012f, 0.016800001f);
            U8(st, 0x22D) = 3;
            S32(st, 0x210) = 0x2CC;
            F32(st, 0x218) = 0.7f;
            F32(st, 0x208) = 0.10000001f;
            F32(st, 0x20C) = 0.14000002f;
            S32(st, 0x214) = 12;
            F32(st, 0x244) = F32(st, 0x240) = -1.0f;
            h = D_001A4BE0;
            q = func_0038D160(F32(a, 0x10) - F32(h, 0x80), F32(a, 0x14) - F32(h, 0x84));
            if (S32(st, 0x1DC) != 0) {
                g = func_0038DAB8(q, 0.17453292f);
            } else {
                g = func_0038DAB8(q, -0.17453292f);
            }
            f = g;
            func_L08_0042CC70(f, a, st + 0x1F0, 6, 2, 0);
        }
        rot3 = a + 0xF8;
        func_L01_00448890(rot3, func_0038D160(F32(st, 0x160) - F32(a, 0x10), F32(st, 0x164) - F32(a, 0x14)), 0.0053756144f, 0.0018849557f, 0.09424779f, st + 0x19C, 0);
        if (func_L08_0042CDA8(a, st + 0x1F0) & 1) {
            func_L01_004450F0(a, 1, 1);
        }
        if (F32(a, 0x10) < 2.0f || F32(a, 0x10) > 1021.0f || F32(a, 0x14) < 2.0f || F32(a, 0x14) > 1021.0f
            || F32(a, 0x18) < 2.0f || F32(a, 0x18) > 1021.0f) {
        kill:
            func_003C2880(a);
            return;
        }
        break;
    }
    case 9:
        if (U8(a, 0x60) & 2) {
            func_L01_004450F0(a, 7, -1);
            if (U8(a, 0x43) != 0) {
                func_003C3A10(a, 0, 0, 8);
            }
        }
        break;
    }
    func_L08_0039EBC0(a);
}
/* localdecomp:end func_L08_0039D188 */

INCLUDE_ASM("asm/levels", func_L08_0039E430);

/* localdecomp:start func_L08_0039E658 */
/* PAL port of the NTSC-U match src/us/levels/func_L08_0039CB58.c */
#include "vu0.h"

extern void func_0038D308(void *, void *);
extern f32 func_00382538(void);
extern f32 func_003C3D30(void *, f32, s32, s32);

s32 func_L08_0039E658(u8 *self) {
    u8 *t;
    f32 f;
    f32 g;
    f32 h;
    u8 *pos;

    t = *(u8 **)(self + 0x68);
    pos = self + 0x10;
    *(u128_0039CB58 *)(t + 0x1A0) = *(u128_0039CB58 *)pos;
    if (*(s16 *)(self + 0xB2) == 0) {
        *(s32 *)(t + 0x1C0) = -1;
        *(s32 *)(t + 0x1C8) = -1;
    }
    *(s32 *)(self + 0xF0) = 0;
    *(s32 *)(self + 0xF4) = 0;
    func_0038D308(self + 0xC0, self + 0xF0);
    f = func_00382538();
    *(f32 *)(t + 0x70) = 0.5f;
    *(f32 *)(t + 0x1D0) = f;
    *(f32 *)(t + 0x74) = 0.25f;
    *(f32 *)(t + 0x78) = 1.25f;
    *(f32 *)(t + 0x7C) = 1.5f;
    *(f32 *)(t + 0x80) = 1.57079637f;
    *(f32 *)(t + 0xA0) = 0.34906584f;
    *(f32 *)(t + 0x9C) = 0.00392f;
    func_L01_0045BD78(0.0064000003f, 0.080000006f, 0.010053097f, 0.25132743f, self);
    t[0x58] = 0x14;
    t[0x5A] = 0xE;
    if (*(s16 *)(t + 0x34) == 0) {
        *(s16 *)(t + 0x34) = 1;
        *(f32 *)(t + 0x30) = 1.0f;
    }
    if (t[0x44] == 0) {
        t[0x44] = 5;
        t[0x45] = 5;
        t[0x46] = 5;
    }
    *(f32 *)(t + 0x40) = 0.5f;
    t[0x3F] = 0;
    t[0x39] = 1;
    t[0x64] = 1;
    t[0x3E] = 1;
    func_L01_004450F0(self, 3, 0);
    if (self[0x43] != 1) {
        func_003C3A10(self, 1, 0, 0);
    }
    if (*(s32 *)(t + 0x1C0) != -1 || *(s32 *)(t + 0x1C8) != -1) {
        func_L01_004450F0(self, 0xA, 4);
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(self + 0x98) = 0;
        func_L01_004AA7E8(self, 1);
    } else if (*(s32 *)(t + 0x1C4) == 1) {
        g = func_003C3D30(pos, 0.5f, 0, 0);
        h = *(f32 *)(self + 0x18);
        if (3.0f < h - g) {
            g = h;
        }
        *(f32 *)(self + 0x18) = g - 1.0f;
        *(s32 *)(self + 0x98) = 0;
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(self, 1);
    }
    return 0;
}
/* localdecomp:end func_L08_0039E658 */

INCLUDE_ASM("asm/levels", func_L08_0039E8C8);

INCLUDE_ASM("asm/levels", func_L08_0039EBC0);
