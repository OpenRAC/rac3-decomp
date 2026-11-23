#include "common.h"

/* localdecomp:start func_L39_00648C20 */
#include "vu0.h"

typedef struct VT_00648C20 {
    u8 pad0[0x30];
    void (*f30)(u8 *);
} VT_00648C20;

typedef union Buf_00648C20 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_00648C20;

typedef struct Ent_00648C20 {
    u8 pad0[0x18];
    s32 i18;
    u8 pad1C[0x10];
} Ent_00648C20;

/* func_L39_006233A8's result (L39_006233A8.c's Out_006233A8) */
typedef struct Out_00648C20 {
    vu0_v4 v0;
    vu0_v4 v10;
    u8 pad20[4];
    f32 f24;
    s32 f28;
    u8 pad2C[8];
    s32 f34;
    s32 f38;
} Out_00648C20;

typedef struct Tab_00648C20 {
    u8 pad[0xA4];
    u8 flags[0x100];
} Tab_00648C20;

extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;
extern Tab_00648C20 D_001A5810;
extern u8 *D_L39_002637C0[];
__asm__(".extern D_L39_00242930, 16");
extern vu0_v4 D_L39_00242930 __attribute__((section(".sdata")));
extern const f32 D_L39_00245FFC[][4] __attribute__((section(".sdata")));
extern f32 D_L39_00246150[] __attribute__((section(".sdata")));
extern Ent_00648C20 D_L39_0047A8A8[];

static inline u32 Dec_00648C20(u8 *q) {
    Buf_00648C20 buf;
    u8 *d;
    s32 n;
    s32 k;
    s32 m;
    s32 i;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

static inline s32 DecEq_00648C20(u8 *q, u32 v) {
    return Dec_00648C20(q) == v;
}

static inline s32 DecGt_00648C20(u8 *q, s32 v) {
    return (s32)Dec_00648C20(q) > v;
}

static inline void Prep_00648C20(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static inline void Set16_00648C20(u8 *q, s16 v) {
    u8 *hk = q;
    Buf_00648C20 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00648C20(q);
    buf.h[2] = v;
    key = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    buf.w[0] = (u32)q ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

static inline void Set32_00648C20(u8 *q, u32 v) {
    u8 *hk = q;
    Buf_00648C20 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00648C20(q);
    key = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = v;
    buf.w[1] ^= key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

extern s32 func_L01_003F1F20(s32, s32);
extern s32 func_003D4D00(void *, s32, f32, void *, void *);
extern void func_0038CE20(f32 *, f32 *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CED8(f32 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040E728(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_00446A70(u8 *, u8 *, s32, void *, void *, f32);
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_L01_004482A0(f32 *, f32 *, f32, f32, f32, f32);
extern f32 func_L01_004485E0(s32, f32, f32);
extern void func_L01_00448690(void *, s32, f32, f32);
extern f32 func_L01_00448728(f32 *, f32, f32 *, f32, f32, f32, s32);
extern s32 func_L39_005B8928(u8 *);
extern void func_003C4BB0(f32 *, f32);
extern void func_L39_005F3488(s32, s32, s32, s32);
extern s32 func_L39_006233A8(u8 *, vu0_v4 *, void *, Out_00648C20 *);
extern void func_L39_0062D0C8(u8 *, f32);
extern void func_L39_0062D190(u8 *, f32);
extern void func_L39_0062EF58(u8 *);
extern void func_L39_0062FCF0(u8 *, f32, f32, f32);
extern void func_L39_006314E0(u8 *, s32);
extern void func_L39_00632298(void *, void *, void *, f32);
extern void func_L39_00632558(void *, void *, void *, f32);
extern f32 func_L39_006325D8(u8 *, void *);
extern f32 func_L39_00632678(u8 *, void *);
extern void func_L39_00632A20(u8 *, void *, void *, f32);
extern s32 func_L39_00632C48(u8 *, f32);
extern void func_L39_00632C80(u8 *, void *, void *, f32);
extern void func_L39_00632D78(u8 *, s32, f32);
extern void func_L39_00633160(u8 *);
extern void func_L39_006331D0(u8 *, f32, f32, f32);
extern void func_L39_00633308(u8 *, s32, f32, f32, f32);
extern void func_L39_00633620(u8 *, f32, f32);
extern void func_L39_00633670(u8 *, f32);
extern void func_L39_00633748(u8 *);
extern void func_L39_00633980(u8 *, f32, f32, f32);
extern f32 func_L39_00633C78(u8 *, void *, s32);
extern void func_L39_00633CF8(u8 *);
extern void func_L39_00634E18(u8 *, f32, f32);
extern void func_L39_00634E38(u8 *, f32, f32);
extern void func_L39_00634E48(u8 *, f32, f32);
extern void func_L31_004F3CA0_00648C20(u8 *, f32, f32);
extern void func_L39_00637EC8(void *, void *, void *, s32, s32, s32, s32);
extern void func_L39_006384C0(u8 *, f32, f32, f32);
extern void func_L39_0063A058(u8 *, s32, s32, s32);
extern void func_L39_0063BA40(u8 *);
extern void func_L39_00647730(void *, void *);
extern void func_L39_0064AA70(u8 *);
extern void func_L39_0064BC28(u8 *);
extern void func_L39_0064C7E0(u8 *);
extern void func_L39_0064D4A8(u8 *);
extern void func_L39_0064DCF0(u8 *);
extern void func_L39_0064E3B0(u8 *);
extern void func_L39_0064E8F8(u8 *);

void func_L39_00648C20(void *arg) {
    u8 *o = arg;
    u8 *q;
    u32 a;
    u32 qb;
    u32 x;
    u8 ok;

    q = *(u8 **)(o + 0x2524);
    a = Dec_00648C20(o + 0x19E5);
    qb = q[0x43];
    switch (Dec_00648C20(o + 0x19E4)) {
    case 0x90: {
        x = Dec_00648C20(o + 0x19E7);
        if ((x ^ 0x7E) == 0) {
            func_L39_0064E8F8(o);
            break;
        }
        Set16_00648C20(o + 0x313, 2);
        x = Dec_00648C20(o + 0x19E7);
        if ((x ^ 0x76) == 0) {
            ((VT_00648C20 *)*(void **)(o + 0x14))->f30(o);
            break;
        }
        x = Dec_00648C20(o + 0x19E7);
        if ((x ^ 0x7A) == 0) {
            ((VT_00648C20 *)*(void **)(o + 0x14))->f30(o);
            break;
        }
    }
    case 0: case 1: case 3: case 4: case 0x1C: case 0x1D: case 0x1E: case 0x39:
    case 0x6F: case 0x71: case 0x7F:
        func_L39_0064AA70(o);
        break;
    case 0x7E:
        func_L39_0064E8F8(o);
        break;
    case 2: case 0x72:
        func_L39_0064BC28(o);
        break;
    case 7: case 9: case 0xA: case 0xB: case 0xC: case 0xD: case 0xE: case 0xF:
    case 0x10: case 0x11: case 0x12: case 0x1B: case 0x38: case 0x68: case 0x70: case 0x83:
        func_L39_0064C7E0(o);
        break;
    case 0x13:
        func_L39_0064E3B0(o);
        break;
    case 0x22:
        if (D_001A5810.flags[*(s32 *)(o + 0x2544)] != 0
            || ((ok = DecEq_00648C20(o + 0x19E4, 1) || DecEq_00648C20(o + 0x19E4, 0x1D) || o[0x24FE] != 0 || o[0x2500] != 0)
                && (o[0x1A0A] != 0 || o[0x1A14] == 0))) {
            *(vu0_v4 *)(o + 0xFC0) = *(vu0_v4 *)(o + 0x11A0);
            *(f32 *)(o + 0xFD0) = *(f32 *)(o + 0x11E0);
        } else if (*(s16 *)(o + 0x3E4) != 0) {
            *(vu0_v4 *)(o + 0xFC0) = *(vu0_v4 *)(o + 0x23C0);
            *(f32 *)(o + 0xFD0) = *(f32 *)(o + 0x23B8);
        }
        func_L39_00633308(o, 0, 0.053280003f, 0.1872f, 0.2443461f);
        break;
    case 0x7D: {
        vu0_v4 vloc;
        vu0_v4 vloc2;
        f32 f21;
        f32 roll;
        s32 lim;
        s32 n;
        s32 i;
        {
            func_L39_0063A058(o, 4, *(s32 *)(o + 0x2524), 0xD);
            func_L01_003F1F20(0x16, *(s32 *)(o + 0x2534));
            func_L39_00632D78(o, 0, 1.0f);
            *(f32 *)(o + 0xFB0) = 0.23000002f;
            func_L39_00632C80(o, &vloc, o + 0x1580, 0.24480002f);
            f21 = *(f32 *)(o + 0x2468) * 0.024434611f * vloc.x;
            if (*(s32 *)(o + 0x2F0) < 0x32) {
                *(f32 *)(o + 0xFB0) = 0.6f;
            }
            lim = 0x2A;
            if (*(s32 *)(o + 0x2F0) < lim) {
                f21 = f21 * ((f32)*(s32 *)(o + 0x2F0) / (f32)lim);
            }
            if (0.2f < *(f32 *)(o + 0x2468)) {
                func_L39_006331D0(o, 0.0f, 0.0f, f21);
            }
            func_L39_00633620(o, 0.040000003f, 0.006f);
            func_L39_00633670(o, 99999.0f);
            func_L01_004482A0((f32 *)(o + 0xA8), (f32 *)(o + 0x1590), *(f32 *)(o + 0x2A8) + 0.17f, 0.057600003f, 0.43200004f, 0.15f);
            func_0038CE20((f32 *)&vloc2, (f32 *)(o + 0x140), 3.0f);
            vec_add_ab(&vloc2, &vloc2, o + 0xE0);
            n = func_003D4D00(&vloc2, 0, 0.57f, *(void **)(o + 0x2524), 0);
            if (n != 0) {
                vu0_v4 vloc3;
                func_0038CE20((f32 *)&vloc3, (f32 *)(o + 0x140), 7.0f);
                for (i = 0; i < n; i++) {
                    if (func_L39_005B8928(D_L39_002637C0[i]) != 0
                        || *(s16 *)(D_L39_002637C0[i] + 0xAA) == 0x1080
                        || *(s16 *)(D_L39_002637C0[i] + 0xAA) == 0x10AA
                        || *(s16 *)(D_L39_002637C0[i] + 0xAA) == 0x10AD
                        || *(s16 *)(D_L39_002637C0[i] + 0xAA) == 0x10AE) {
                        func_L01_00446A70(D_L39_002637C0[i], *(u8 **)(o + 0x2524), 0x10000, o + 0xA0, &vloc3, 1.0f);
                    }
                }
            }
            if (*(s32 *)(o + 0x1310) == 1) {
                *(s32 *)(o + 0x35C) = 2;
            }
            func_L39_00634E18(o, 0.024480002f, 0.43200004f);
            func_L39_00634E38(o, 0.036000002f, 0.43200004f);
            func_L39_00634E48(o, 0.0432f, 0.38880002f);
            roll = f21 * 27.0f;
            if (1.7f < roll) {
                roll = 1.7f;
            } else if (roll < -1.7f) {
                roll = -1.7f;
            }
            *(f32 *)(o + 0x7C0) = -roll;
            *(f32 *)(o + 0x9D8) = roll * 0.5f;
            *(f32 *)(o + 0x928) = roll * 0.5f;
            break;
        }
    }
    case 0x78:
        *(f32 *)(o + 0xFD0) = *(f32 *)(o + 0x2BC);
        *(f32 *)(o + 0xFB0) = 0.11000001f;
        func_L39_0062D190(o, 0.010000001f);
        func_L39_00632A20(o, o + 0x120, o + 0x160, 0.0072000003f);
        break;
    case 6: case 0x2C: {
        f32 fa;
        x = Dec_00648C20(o + 0x19E4);
        if ((x ^ 0x2C) == 0) {
            vu0_v4 vloc;
            {
                fa = 0.0f;
                if (4.0f < *(f32 *)(o + 0x2AC)) {
                    fa = 0.43633232f;
                }
                vloc = *(vu0_v4 *)(o + 0xB0);
                func_L01_00448728(&vloc.y, fa, (f32 *)(o + 0xC4), 0.028800001f, 0.43200004f, 0.05235988f, 0);
                func_L01_00448728(&vloc.x, 0.0f, (f32 *)(o + 0xC0), 0.028800001f, 0.43200004f, 0.05235988f, 0);
                func_L39_00633980(o, *(f32 *)(o + 0xC0), *(f32 *)(o + 0xC4), 0.0f);
                if (1.0f < *(f32 *)(o + 0x2AC)) {
                    Set32_00648C20(o + 0x19E5, 1);
                }
            }
        }
        func_L39_00633160(o);
        if (*(s16 *)(o + 0x320) == 0) {
            func_L39_0062EF58(o);
        }
        func_L39_00633CF8(o);
        func_L31_004F3CA0_00648C20(o, 0.7f, 0.0f);
        func_L39_00632A20(o, o + 0x120, o + 0x120, *(f32 *)(o + 0x15C0));
        if (func_L39_00632678(o, o + 0x120) < -1.0000001f) {
            func_L39_00632558(o, o + 0x120, o + 0x120, -1.0000001f);
        }
        break;
    }
    case 0x76:
        x = Dec_00648C20(o + 0x19E5);
        if ((x ^ 8) != 0) {
            u8 *v;
            f32 fa;
            fa = 0.0034906587f;
            o[0x1A0C] = 1;
            func_003C4138((f32 *)(o + 0x15C8), *(f32 *)(o + 0x15D0), fa);
            v = o + 0x120;
            func_003C4138((f32 *)(o + 0x15CC), *(f32 *)(o + 0x15D4), fa);
            func_L39_00633980(o, *(f32 *)(o + 0x15C8), *(f32 *)(o + 0x15CC), 0.0f);
            func_L01_0040E728(v, v, func_0038CED8((f32 *)v) * 0.88f);
            func_L39_00632A20(o, v, v, *(f32 *)(o + 0x15C0));
            if (func_L39_00632678(o, v) < -1.0000001f) {
                func_L39_00632558(o, v, v, -1.0000001f);
            }
        }
        break;
    case 0x16: {
        f32 f20;
        f32 d;
        f20 = func_L39_006325D8(o, o + 0x120);
        d = 0.0016000001f;
        if (*(s16 *)(o + 0x2DE) == 0 && *(s32 *)(o + 0x2F0) >= 9) {
            d = 0.004f;
        }
        f20 -= d;
        if (f20 < 0.0f) {
            f20 = 0.0f;
        }
        if (o[0x377] != 0) {
            func_L39_006384C0(o, 3.7f, 0.0f, 0.35f);
        }
        func_L39_00632298(o, o + 0x120, o + 0x120, f20);
        func_L39_00632A20(o, o + 0x120, o + 0x120, 0.004f);
        break;
    }
    case 0x8E:
        qzero(o + 0x120);
        break;
    case 0x64: {
        vu0_v4 vloc;
        vu0_v4 vloc2;
        f32 f20;
        s32 n;
        s32 i;
        {
            vec_sub_ab(&vloc, o + 0x13C0, o + 0xA0);
            *(f32 *)(o + 0xFD0) = func_0038D160(vloc.x, vloc.y);
            f20 = func_0038CED8((f32 *)&vloc);
            if (0.2f < f20) {
                *(f32 *)(o + 0x2468) = 1.0f;
                *(f32 *)(o + 0xFD0) = func_0038D160(vloc.x, vloc.y);
                *(f32 *)(o + 0xFB0) = f20;
                *(f32 *)(o + 0xFB0) = (f20 < D_L39_00245FFC[0][2] ? D_L39_00245FFC[0][1] : D_L39_00245FFC[1][1]) * 0.020000001f;
            } else {
                *(f32 *)(o + 0x2468) = 1.0f;
                *(f32 *)(o + 0xFD0) = *(f32 *)(o + 0x13CC);
                *(s32 *)(o + 0xFB0) = 0;
            }
            func_L39_00633308(o, 0, 0.0432f, 0.43200004f, 0.15707964f);
            func_L39_00633CF8(o);
            func_L39_00633620(o, 0.014800001f, 0.012f);
            func_L39_00633670(o, 99999.0f);
            func_L39_006314E0(o, 0);
            if (*(s16 *)(o + 0x2DE) != 0) {
                func_L39_00632A20(o, o + 0x120, o + 0x140, 0.010000001f);
                func_L39_00633748(o);
            } else {
                func_L39_00632A20(o, o + 0x120, o + 0x120, 0.0216f);
            }
            vloc2 = *(vu0_v4 *)(o + 0xE0);
            n = func_003D4D00(&vloc2, 0, *(f32 *)(o + 0x1F4) + 0.2f, *(void **)(o + 0x2524), 0);
            for (i = 0; i < n; i++) {
                u8 *p = D_L39_002637C0[i];
                if (p != 0 && *(s16 *)(p + 0xAA) == 0xCB) {
                    func_L01_00446A70(p, *(u8 **)(o + 0x2524), 0x10000, o + 0xE0, &D_L39_00242930, 100.0f);
                }
            }
            break;
        }
    }
    case 0x65: {
        vu0_v4 vloc;
        u8 *v;
        {
            vec_sub_ab(&vloc, o + 0x13C0, o + 0xA0);
            if (func_0038CE68(&vloc, o + 0x190) < 0.0f) {
                qzero(o + 0x190);
            }
            v = o + 0x120;
            qzero(v);
            func_L39_0062D0C8(o, 0.0108f);
            func_L39_006314E0(o, 0);
            if (*(s16 *)(o + 0x2DE) != 0) {
                func_L39_00632A20(o, v, o + 0x140, 0.010000001f);
                func_L39_00633748(o);
            } else {
                func_L39_00632A20(o, v, v, 0.0216f);
            }
            break;
        }
    }
    case 0x66: {
        vu0_v4 vloc;
        vu0_v4 vloc2;
        s32 i;
        {
            qzero(o + 0x120);
            if (*(s32 *)(o + 0x13D4) == 0) {
                break;
            }
            if (*(s32 *)(o + 0x13D8) > 0) {
                if (*(s32 *)(o + 0x2F0) == 1) {
                    func_L39_00647730(o, *(u8 **)(o + 0x2524) + 0x10);
                    func_L39_005F3488(0, 0, *(s32 *)(o + 0x2524), 0x10C3);
                }
                func_003C4138((f32 *)(o + 0xF0), 0.0f, 0.16000001f);
                func_003C4138((f32 *)(o + 0xF4), 0.0f, 0.16000001f);
                func_003C4138((f32 *)(o + 0xF8), 2.0f, 0.16000001f);
                *(s16 *)(o + 0x2488) = 1;
                *(s32 *)(o + 0x13D8) = *(s32 *)(o + 0x13D8) - 1;
            }
            if (*(s32 *)(o + 0x13D4) == 0) {
                break;
            }
            if (*(s32 *)(o + 0x13D8) != 0) {
                break;
            }
            *(f32 *)(o + 0xF0) = -0.32000002f;
            *(f32 *)(o + 0xF4) = -0.32000002f;
            vec_sub_ba(&vloc, o + 0x13C0, *(u8 **)(o + 0x2524) + 0x10);
            vloc.z = 0.0f;
            func_0038CF68(&vloc2, &vloc, 0.3f);
            vec_add_ab(&vloc, &vloc, *(u8 **)(o + 0x13DC) + 0x10);
            vloc.z = vloc.z + 0.2f;
            if (func_003D4D00(&vloc, 1, 0.5f, *(void **)(o + 0x13DC), 0) != 0) {
                for (i = 0; i < 8; i++) {
                    vec_add_ab(&vloc, &vloc, &vloc2);
                    if (func_003D4D00(&vloc, 1, 0.5f, *(void **)(o + 0x13DC), 0) == 0) {
                        break;
                    }
                }
            }
            *(s32 *)(o + 0x13D4) = 0;
            func_L39_00637EC8(o, &vloc, *(u8 **)(o + 0x13DC) + 0xF0, 0, 1, 1, 0);
            func_L39_00647730(o, &vloc);
            func_L39_005F3488(1, 0, *(s32 *)(o + 0x2524), 0x10C3);
            Set16_00648C20(o + 0x311, 0x4B);
            break;
        }
    }
    case 0x2B:
        func_L39_0064D4A8(o);
        break;
    case 0x14:
        func_L39_0064DCF0(o);
        break;
    case 0x15: case 0x85: {
        s32 hit;
        u32 z;
        s32 flag;
        f32 f20;
        f32 f1;
        *(s32 *)(o + 0xFB0) = 0;
        if (*(s32 *)(o + 0x61C) != 0
            || *(f32 *)(o + 0x628) < (f32)D_L39_0047A8A8[*(s16 *)(o + 0x107C)].i18) {
            o[0x469] = 2;
        }
        hit = 0;
        if ((DecEq_00648C20(o + 0x19E7, 1) && DecGt_00648C20(o + 0x19E9, 0x11)) || o[0x24FE] != 0) {
            hit = 1;
        }
        if (hit == 0) {
            if (*(s32 *)(o + 0x1068) != 0 || *(s32 *)(o + 0x1064) != 0) {
                flag = 0;
                if (o[0x1A06] != 0) {
                    f20 = func_L39_00633C78(o, o + 0x1040, 0);
                    f1 = func_L39_00633C78(o, o + 0x1040, 1);
                } else {
                    f20 = func_0038DB00(*(f32 *)(o + 0x106C), *(f32 *)(o + 0xB8));
                    f1 = func_L01_004485E0(1, *(f32 *)(o + 0x106C), *(f32 *)(o + 0xB8));
                }
                if (f1 < 4.363323f) {
                    flag = 1;
                }
                if (0.0f < f20) {
                    *(f32 *)(o + 0x610) = 1.0f / (f1 + 1.0f);
                }
                *(f32 *)(o + 0xFD0) = *(f32 *)(o + 0x106C);
                *(vu0_v4 *)(o + 0xFC0) = *(vu0_v4 *)(o + 0x1040);
                if (flag != 0) {
                    func_L39_00633308(o, 1, 0.08208001f, 0.28800002f, 0.3385939f);
                } else {
                    func_L39_00633308(o, 0, 0.08208001f, 0.28800002f, 0.3385939f);
                }
            } else {
                s32 g = 1;
                z = Dec_00648C20(o + 0x19E4);
                if ((z ^ 0x85) == 0 && *(s32 *)(o + 0x2F0) >= 10) {
                    g = 0;
                } else if (*(s32 *)(o + 0x61C) == 0 && 6.0f < *(f32 *)(o + 0x628)) {
                    g = 0;
                }
                if (g != 0) {
                    z = Dec_00648C20(o + 0x19E4);
                    if ((z ^ 0x15) == 0) {
                        func_L39_0062FCF0(o, 14.0f, 0.5235988f, 0.7853982f);
                    }
                }
            }
        }
        if ((*(s32 *)(o + 0x61C) == 0 || o[0x24FE] != 0) && (*(u8 **)(o + 0x2524))[0x43] == 0x1A) {
            f32 fz = 33.0f;
            if (o[0x24FE] != 0) {
                fz = 32.0f;
            }
            if (func_L39_00632C48(o, fz) != 0) {
                z = Dec_00648C20(o + 0x19E4);
                if ((z ^ 0x15) == 0) {
                    func_L39_0063BA40(o);
                }
            }
        }
        func_L39_00633620(o, 0.014800001f, 0.0112000005f);
        func_L39_00633670(o, 99999.0f);
        if (*(s16 *)(o + 0x2DE) != 0) {
            func_L39_00632A20(o, o + 0x120, o + 0x160, 0.010000001f);
        } else {
            func_L39_00632A20(o, o + 0x120, o + 0x120, 0.0216f);
        }
        break;
    }
    case 0x17: case 0x18:
        vec_sub_ba(o + 0xFC0, o + 0x1550, o + 0x1540);
        *(f32 *)(o + 0xFD0) = func_0038D160(*(f32 *)(o + 0xFC0), *(f32 *)(o + 0xFC4));
        func_L39_00633308(o, 0, 0.057600003f, 0.28800002f, 0.12566371f);
        if (o[0x1A06] != 2) {
            func_L01_00448690(o + 0xB4, 0, 0.0f, 0.09424779f);
        }
        vec_sub_ab(o + 0x120, o + 0x1540, o + 0xA0);
        func_003C4BB0((f32 *)(o + 0x120), 0.080000006f);
        func_003C4138((f32 *)(o + 0x1570), *(f32 *)(o + 0xA8), 0.060000002f);
        break;
    case 0x19: case 0x1A: {
        vu0_v4 side;
        vu0_v4 pos;
        vu0_v4 dir;
        Out_00648C20 hit;
        {
            vec_sub_ba(o + 0xFC0, o + 0x1550, o + 0x1540);
            *(f32 *)(o + 0xFD0) = func_0038D160(*(f32 *)(o + 0xFC0), *(f32 *)(o + 0xFC4));
            func_L39_00633308(o, 0, 0.028800001f, 0.28800002f, 0.09424779f);
            vec_sub_ab(&dir, o + 0x1550, o + 0x1540);
            qzero(o + 0x120);
            x = Dec_00648C20(o + 0x19E4);
            if ((x ^ 0x19) == 0) {
                func_0038CE90(&side, o + 0x250, &dir);
            } else {
                func_0038CE90(&side, &dir, o + 0x250);
            }
            func_0038CF68(&side, &side, 0.2f);
            vec_add_ba(&pos, o + 0xA0, &side);
            if (func_L39_006233A8(o, (vu0_v4 *)(o + 0xA0), o + 0xB0, 0) == 0) {
                break;
            }
            if (func_L39_006233A8(o, &pos, o + 0xB0, &hit) == 0) {
                break;
            }
            vec_sub_ba(o + 0x120, &hit.v0, o + 0xA0);
            func_0038CF68(o + 0x120, o + 0x120, D_L39_00246150[(s32)*(f32 *)(o + 0x628)] * 0.5f);
            break;
        }
    }
    case 0x79: {
        f32 f20 = 0.0f;
        func_003C4138((f32 *)(o + 0xFB4), f20, 0.0096f);
        *(f32 *)(o + 0x120) = func_0038D098(*(f32 *)(o + 0x1070)) * *(f32 *)(o + 0xFB4);
        *(f32 *)(o + 0x124) = func_0038D0B0(*(f32 *)(o + 0x1070)) * *(f32 *)(o + 0xFB4);
        if (0.0f < *(f32 *)(o + 0x2AC)) {
            *(f32 *)(o + 0x128) = *(f32 *)(o + 0x158) - 0.010000001f;
        } else {
            *(f32 *)(o + 0x128) = f20;
        }
        *(f32 *)(o + 0xFD0) = func_0038DAB8(*(f32 *)(o + 0x1070), 3.1415927f);
        func_L39_00633308(o, 0, 0.072000004f, 0.28800002f, 0.3385939f);
        break;
    }
    case 0x7A:
        qzero(o + 0x120);
        *(f32 *)(o + 0x128) = -0.020000001f;
        break;
    case 0x37:
        if ((*(u8 **)(o + 0x2524))[0x43] == 0x33) {
            func_L39_00633308(o, 0, 0.19728f, 0.36f, 0.2443461f);
        } else {
            func_L39_00633308(o, 0, 1.44f, 0.14400001f, 0.4886922f);
        }
        break;
    case 0x62: case 0x63:
        qzero(o + 0x120);
        break;
    }
    x = Dec_00648C20(o + 0x19E5);
    if (a != x) {
        *(s32 *)(o + 0x2F8) = 0;
    }
    if (qb != q[0x43]) {
        *(s32 *)(o + 0x2FC) = 0;
    }
}
/* localdecomp:end func_L39_00648C20 */
