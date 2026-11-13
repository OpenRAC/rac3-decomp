#include "common.h"

typedef struct S_004E56D0 {
    u8 pad0[0x1B04];
    s32 x1B04;
    u8 pad1[0x1B24 - 0x1B08];
    u8 *x1B24;
    u8 pad2[0x25C0 - 0x1B28];
    u8 *x25C0;
} S_004E56D0;

typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;

extern S_004E6988 D_001A4BE0;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_L30_004CF4B0(s32, s32);

typedef struct {
    u8 pad0[0x43];
    u8 b43;
} P_004E6D08;
typedef struct {
    u8 pad0[0xC08];
    s32 w_C08;
    u8 pad1[0x1AC0 - 0xC0C];
    s32 w_1AC0;
    u8 pad2[0x25C0 - 0x1AC4];
    P_004E6D08 *p_25C0;
    s32 w_25C4;
    u8 pad3[0x25CC - 0x25C8];
    s32 w_25CC;
    u8 pad4[0x25E9 - 0x25D0];
    u8 b_25E9;
    u8 pad5[0x25EB - 0x25EA];
    u8 b_25EB;
} S_004E6D08;

/* declared by functions of L30_004E5158.c, which this file was cut from */
extern void func_L30_004E71F0(s32);
extern void func_003C2880(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_004F4E70(s32, s32);
extern void func_L30_004E6AD0(s32);
typedef struct {
    u8 pad0[0x40];
    f32 f40;
    f32 f44;
} S2_004E5DD8;
extern S2_004E5DD8 D_L30_001E9000;

/* localdecomp:start func_L30_004E6AD0 */
typedef struct S_004E6AD0 {
    u8 pad0[0x1B04];
    s32 x1B04;
    u8 pad1[0x1B10 - 0x1B08];
    void *x1B10;
    u8 pad2[0x1B24 - 0x1B14];
    u8 *x1B24;
    u8 pad3[0x25C0 - 0x1B28];
    u8 *x25C0;
    s32 x25C4;
    u8 pad4[0x25E9 - 0x25C8];
    u8 x25E9;
    u8 pad5;
    u8 x25EB;
} S_004E6AD0;

typedef struct V_004E6AD0 {
    f32 v[4];
} V_004E6AD0;

extern f32 func_L30_004E6988(void);
extern void func_L30_004E6A48(V_004E6AD0 *, f32);
extern void func_L30_004B7BC8(s32, s32, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_004AAC98(s32, s32, u8 *, s32);
extern void func_L30_00350DB0(V_004E6AD0 *, f32);
extern void func_L30_0034F1A8(V_004E6AD0 *, f32);
extern void func_L30_00347348(V_004E6AD0 *, f32);
extern void *func_L30_00351CB0(void *);

void func_L30_004E6AD0(s32 a0) {
    V_004E6AD0 v;
    f32 f;
    u8 *obj;

    ((S_004E6AD0 *)&D_001A4BE0)->x25E9 = 1;
    ((S_004E6AD0 *)&D_001A4BE0)->x25EB = a0;
    f = func_L30_004E6988();
    func_L30_004E6A48(&v, f);
    if (((S_004E6AD0 *)&D_001A4BE0)->x25C4 == 0x9A) {
        func_L01_0050FB40(((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4 ? 0x3F : 0xF, 0, 3.0f);
    } else if (((S_004E6AD0 *)&D_001A4BE0)->x25C4 == 0xA3) {
        s32 a;

        a = ((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4 ? 0x17 : 0x19;

        if (((S_004E6AD0 *)&D_001A4BE0)->x25C0[0x43] != 0x10) {
            s32 off = ((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4;
            if (((S_004E6AD0 *)&D_001A4BE0)->x25C0[0x43] % 3 == 2) {
                off = 2;
                if (((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4) {
                    off = 0;
                }
            }
            if (((S_004E6AD0 *)&D_001A4BE0)->x25C0[0x43] % 3 == 0) {
                off = 1;
                if (((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4) {
                    off = 2;
                }
            }
            a = ((S_004E6AD0 *)&D_001A4BE0)->x25C0[0x43] + off;
        }
        func_L01_0050FB40(a, 0, 3.0f);
    } else if (((S_004E6AD0 *)&D_001A4BE0)->x1B04 != 4) {
        func_L30_004B7BC8(1, 0x3E, 0, 0);
    }
    obj = ((S_004E6AD0 *)&D_001A4BE0)->x1B24;
    if (obj != 0 && !((*(u8 **)(obj + 0x24))[0xC] < 2) && obj[0x43] != 1) {
        func_003C3A10(obj, 1, 0, 4);
    }
    switch (((S_004E6AD0 *)&D_001A4BE0)->x1B04) {
    case 0:
        break;
    case 2:
        func_003A52A0(0x1F, 0, ((S_004E6AD0 *)&D_001A4BE0)->x25C0);
        func_L30_00350DB0(&v, f);
        break;
    case 3:
        func_L01_004AAC98(0, 0, ((S_004E6AD0 *)&D_001A4BE0)->x1B24, 0x1C7D);
        func_L30_0034F1A8(&v, f);
        break;
    case 4:
        if (((S_004E6AD0 *)&D_001A4BE0)->x1B10 == 0) {
            ((S_004E6AD0 *)&D_001A4BE0)->x1B10 = func_L30_00351CB0(((S_004E6AD0 *)&D_001A4BE0)->x25C0);
        }
        break;
    case 1:
    case 5:
        func_003A52A0(0, 0, ((S_004E6AD0 *)&D_001A4BE0)->x25C0);
        func_L30_00347348(&v, f);
        break;
    }
}
/* localdecomp:end func_L30_004E6AD0 */

LINKER_REMNANT("asm/levels", func_L30_004E6D00);

/* localdecomp:start func_L30_004E6D08 */
void func_L30_004E6D08(void) {
    if (((*(S_004E6D08 *)&D_001A4BE0).w_C08 & 2) != 0 && (*(S_004E6D08 *)&D_001A4BE0).b_25EB == 0) {
        s32 t = (*(S_004E6D08 *)&D_001A4BE0).p_25C0->b43;
        if (t == 19 || t == 22 || t == 25 || t == 28 || t == 31) {
            func_L01_0050FB40((*(S_004E6D08 *)&D_001A4BE0).p_25C0->b43 - 2, 0, 3.0f);
        }
        (*(S_004E6D08 *)&D_001A4BE0).b_25E9 = 0;
    }
    if ((*(S_004E6D08 *)&D_001A4BE0).w_25CC != 0) {
        if ((*(S_004E6D08 *)&D_001A4BE0).w_1AC0 == 0) {
            (*(S_004E6D08 *)&D_001A4BE0).b_25E9 = 0;
        }
    }
}
/* localdecomp:end func_L30_004E6D08 */

/* localdecomp:start func_L30_004E6DC8 */
s32 func_L30_004E6DC8(s32 a0) {
    u8 *b = (u8 *)&D_001A4BE0;
    s32 on;
    if (*(u8 **)(b + 0x1B24) != 0) {
        on = 1;
    } else {
        on = 0;
    }
    switch (a0) {
    case 0x2C:
        if (on) {
            return 0x30;
        }
        break;
    case 7:
        if (on) {
            return 0x2F;
        }
        break;
    case 1:
        if (on) {
            return *(s32 *)(b + 0x1B10) == 0 ? 0x31 : 0x3F;
        }
        break;
    }
    return a0;
}
/* localdecomp:end func_L30_004E6DC8 */

/* localdecomp:start func_L30_004E6E50 */
void func_L30_004E6E50(void) {
    u8 *b = (u8 *)&D_001A4BE0;
    u8 *q = *(u8 **)(b + 0x25C0);
    s32 a1 = 0xE;
    s32 f = 2;
    s32 v;

    if (q[0x43] == 0x3A) {
        a1 = 0xB;
        f = 4;
    }
    func_L01_0050FB40(0x3A, a1, (f32)f);
    v = *(s32 *)(b + 0x25CC);
    *(s16 *)(b + 0x1B3C) = 1;
    *(s16 *)(b + 0xBDC) = 0;
    if (v != 2) {
        func_L30_004CF4B0(0x9C, 0);
    }
    *(s16 *)(b + 0x1E0) = 0x11;
}
/* localdecomp:end func_L30_004E6E50 */

/* localdecomp:start func_L30_004E6ED8 */
typedef int Q_004E6ED8 __attribute__((mode(TI)));

typedef struct V_004E6ED8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_004E6ED8;

typedef struct S_004E6ED8 {
    u8 pad0[0xC08];
    s32 xC08;
    s32 xC0C;
    u8 pad1[0xC18 - 0xC10];
    f32 xC18;
    u8 pad2[0x1AE4 - 0xC1C];
    f32 x1AE4;
    u8 pad3[0x1B3C - 0x1AE8];
    s16 x1B3C;
    u8 pad4[0x25C0 - 0x1B3E];
    u8 *x25C0;
    u8 pad5[0x25CC - 0x25C4];
    s32 x25CC;
} S_004E6ED8;

extern f32 D_L30_001DBFD4;
__asm__(".extern D_L30_001DBFD4, 4");
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_004EE7F8(f32);
extern s32 func_L01_004F4E70(s32, s32);
extern void func_L30_0034CB68(void *, void *, s32, s32, s32, s32, f32, f32);
extern s32 func_L30_004E6DC8(s32);

void func_L30_004E6ED8(void) {
    V_004E6ED8 v;

    if (((S_004E6ED8 *)&D_001A4BE0)->x1B3C == 0) {
        return;
    }
    *(Q_004E6ED8 *)&v = 0;
    v.x = 1.0f;
    v.w = 1.0f;
    if (*(u16 *)(((S_004E6ED8 *)&D_001A4BE0)->x25C0 + 0x34) & 0x8000) {
        func_0038CE20(&v, &v, -1.0f);
    }
    if (func_L01_004EE7F8(D_L30_001DBFD4) != 0) {
        func_L01_004F4E70(7, 0);
    }
    if (((S_004E6ED8 *)&D_001A4BE0)->xC0C == 0 && 11.0f < ((S_004E6ED8 *)&D_001A4BE0)->xC18
        && ((S_004E6ED8 *)&D_001A4BE0)->xC18 < 19.0f) {
        func_L30_0034CB68(((S_004E6ED8 *)&D_001A4BE0)->x25C0, &v, 0, 0, 0, 0, ((S_004E6ED8 *)&D_001A4BE0)->x1AE4, 0.75f);
    }
    if (((S_004E6ED8 *)&D_001A4BE0)->x25CC == 2 && ((S_004E6ED8 *)&D_001A4BE0)->x25C0[0x43] == 0x3A
        && 27.5f <= ((S_004E6ED8 *)&D_001A4BE0)->xC18 && ((S_004E6ED8 *)&D_001A4BE0)->xC0C == 0) {
        func_L01_0050FB40(0x2D, 0, 6.0f);
    }
    if (((S_004E6ED8 *)&D_001A4BE0)->x25CC == 0 && ((S_004E6ED8 *)&D_001A4BE0)->x25C0[0x43] == 0x3A
        && (((S_004E6ED8 *)&D_001A4BE0)->xC08 & 2)) {
        func_L01_0050FB40(func_L30_004E6DC8(1), 0, 4.0f);
    }
    if (((S_004E6ED8 *)&D_001A4BE0)->x25C0[0x43] != 0x3A) {
        ((S_004E6ED8 *)&D_001A4BE0)->x1B3C = 0;
    }
}
/* localdecomp:end func_L30_004E6ED8 */

/* localdecomp:start func_L30_004E70A8 */
typedef struct {
    u8 pad0[0x18];
    u8 *x18;
} S_004E70A8;
typedef struct {
    u8 pad0[0x1DC];
    s16 h1DC;
    u8 pad1[0x25C0 - 0x1DE];
    u8 *p25C0;
} H_004E70A8;

extern u8 *D_L30_001ED080[];
extern s32 func_L30_004E5370(void);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_00446978(void *, void *);

s32 func_L30_004E70A8(u8 *a0, u8 *a1, s32 a2, s32 n) {
    f32 tmp[4] __attribute__((aligned(16)));
    s32 hit = 0;
    s32 i;
    u8 *m;

    for (i = 0; i < n; i++) {
        if (n >= 2) {
            m = D_L30_001ED080[i];
        } else {
            m = ((S_004E70A8 *)&D_L30_001E9000)->x18;
        }
        if (m == ((H_004E70A8 *)&D_001A4BE0)->p25C0) {
            __asm__ __volatile__(
                "lqc2 $vf2, 0x10(%1)\n"
                "lqc2 $vf1, 0x10(%2)\n"
                "vsub.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, 0(%0)\n"
                : : "r"(tmp), "r"(m), "r"(a0) : "memory");
            if (!func_L30_004E5370() || func_0038CE68(((H_004E70A8 *)&D_001A4BE0)->p25C0 + 0xC0, tmp) < 0.0f
                || (*(s32 *)(a1 + 0x14) & 0x20000)) {
                func_L01_00446978(m, a1);
                if (((H_004E70A8 *)&D_001A4BE0)->h1DC == 0) {
                    hit = 1;
                }
            }
        } else if (m != 0) {
            func_L01_00446978(m, a1);
        }
    }
    return hit;
}
/* localdecomp:end func_L30_004E70A8 */

/* localdecomp:start func_L30_004E71F0 */
typedef int Q_004E71F0 __attribute__((mode(TI)));

typedef struct E_004E71F0 {
    s32 x0;
    u8 pad[0xC];
} E_004E71F0;

typedef struct S_004E71F0 {
    u8 pad0[0x80];
    Q_004E71F0 x80;
    Q_004E71F0 x90;
    u8 pad1[0x1AB0 - 0xA0];
    E_004E71F0 x1AB0[3];
    u8 pad2[0x1AFC - 0x1AE0];
    s32 x1AFC;
    u8 pad3[0x25C0 - 0x1B00];
    u8 *x25C0;
} S_004E71F0;

typedef struct G_004E71F0 {
    u8 pad[0x77];
    u8 x77;
} G_004E71F0;

extern G_004E71F0 D_00142660_004E71F0;
__asm__(".extern D_00142660_004E71F0, 16");
extern void func_003C2880(void *);
extern s32 func_L01_0044E7D8(void *);
extern void func_L01_0044E820(void *, s32);

void func_L30_004E71F0(s32 a0) {
    u8 s[2];
    u8 r[2];
    u8 *o;
    s32 i;
    s32 cls = a0 != 0 ? 0x1EF9 : 0x1363;

    s[0] = ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x42];
    s[1] = ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x43];
    r[0] = ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x40];
    r[1] = ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x41];
    if (a0 != 0) {
        D_00142660_004E71F0.x77 |= 0x80;
    } else {
        D_00142660_004E71F0.x77 &= 0x7F;
    }
    o = func_003C24B0(cls, 0x80);
    if (o == 0) {
        return;
    }
    *(s16 *)(o + 0x32) = 0xFF;
    *(Q_004E71F0 *)(o + 0x10) = ((Q_004E71F0 *)((u8 *)&D_001A4BE0 + 0x80))[0];
    *(Q_004E71F0 *)(o + 0xF0) = ((Q_004E71F0 *)((u8 *)&D_001A4BE0 + 0x80))[1];
    *(long *)(o + 0x38) = *(long *)(((S_004E71F0 *)&D_001A4BE0)->x25C0 + 0x38);
    func_003C2880(((S_004E71F0 *)&D_001A4BE0)->x25C0);
    ((S_004E71F0 *)&D_001A4BE0)->x25C0 = o;
    *(s32 *)(o + 0x64) = 0;
    *(u16 *)(((S_004E71F0 *)&D_001A4BE0)->x25C0 + 0x34) |= 2;
    *(f32 *)(((S_004E71F0 *)&D_001A4BE0)->x25C0 + 0x2C) *= 0.83f;
    if (*(s16 *)(((S_004E71F0 *)&D_001A4BE0)->x25C0 + 0xAA) == 0x1EF9) {
        ((S_004E71F0 *)&D_001A4BE0)->x1AFC = func_L01_0044E7D8(((S_004E71F0 *)&D_001A4BE0)->x25C0);
        func_L01_0044E820(((S_004E71F0 *)&D_001A4BE0)->x25C0, 0x606060);
    } else {
        func_L01_0044E820(((S_004E71F0 *)&D_001A4BE0)->x25C0, ((S_004E71F0 *)&D_001A4BE0)->x1AFC);
    }
    ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x42] = s[0];
    ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x43] = s[1];
    ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x40] = r[0];
    ((S_004E71F0 *)&D_001A4BE0)->x25C0[0x41] = r[1];
    for (i = 2; i >= 0; i--) {
        ((S_004E71F0 *)&D_001A4BE0)->x1AB0[i].x0 = 0;
    }
}
/* localdecomp:end func_L30_004E71F0 */
