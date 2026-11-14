#include "common.h"

typedef struct N_65FDA0 { u32 w0; s32 w4; s32 w8; u8 p0[0x49]; u8 b55; u8 p1x; struct N_65FDA0 *next; } N_65FDA0;
typedef struct N_65FE10 { u8 pad[0x58]; struct N_65FE10 *next; } N_65FE10;
typedef void (*Fn_6600D8)(void *, void *);
typedef struct {
    u32 pad0 : 4;
    u32 cap : 6;
    u32 pad1 : 22;
} S_6601C8;

/* localdecomp:start func_L39_00663950 */
#include "vu0.h"
extern s32 D_001D5A1C_sda;
extern u8 D_L39_004997E0[];
extern void func_L39_005BA418(void *, void *);
extern void func_0038D308(f32 *, f32 *);
extern void func_0038CF68(void *, void *, f32);

void func_L39_00663950(u8 *o) {
    u8 *a = *(u8 **)(o + 0x2558);
    u8 *q = *(u8 **)(a + 0xC44);
    u8 *t = 0;
    s32 x1, x2, x3;
    f32 s, s2;

    if (q != 0 && (a[0xC42] == 0 || D_001D5A1C_sda - *(s32 *)(a + 0xC3C) >= *(s8 *)(a + 0xC41))) {
        t = q;
    }
    if (t == 0) {
        return;
    }
    {
        u8 idx = (*(u8 **)(o + 0x2558))[0xC31];
        if ((*(u32 *)(t + 0x14) & 0xC000000) != 0x4000000) {
            func_L39_005BA418(o + 0x23B0, (s32 *)t + idx);
        }
    }
    *(s32 *)(o + 0x23BC) = 0;
    func_0038D308((f32 *)(o + 0x23C0), (f32 *)(o + 0x23B0));
    if (*(u32 *)(o + 0x1310) < 2) {
        s = 2.0f;
        s2 = -3.0f;
    } else {
        {
            u32 buf[4];
            u8 *p = o + 0x19E4;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 i;

            if (*p == 0) {
                x1 = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                x1 = buf[1];
            }
        }
        if ((x1 ^ 4) == 0) {
            goto chk;
        }
        {
            u32 buf[4];
            u8 *p = o + 0x19E4;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 i;

            if (*p == 0) {
                x2 = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                x2 = buf[1];
            }
        }
        if ((x2 ^ 0x15) == 0) {
chk:
            if (*(s32 *)(o + 0x1310) == 2) {
                goto small;
            }
        }
        if (o[0x24FD] != 0) {
small:
            s = 0.6f;
        } else {
            s = 1.15f;
        }
        {
            u32 buf[4];
            u8 *p = o + 0x19E6;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 i;

            if (*p == 0) {
                x3 = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (i = 0; i < 40; i += 5) {
                    *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                x3 = buf[1];
            }
        }
        if ((x3 ^ 3) == 0) {
            s = 1.75f;
        }
        s2 = 0.0f;
    }
    func_0038CF68(o + 0x23A0, o + 0x40, s);
    vec_add_ab(o + 0x23A0, o + 0x23A0, o + 0xA0);
    if (s2 != 0.0f) {
        vu0_v4 v;
        func_0038CF68(&v, o + 0x23C0, s2);
        vec_add_ab(o + 0x23A0, o + 0x23A0, &v);
    }
    *(vu0_q *)(*(u8 **)(o + 0x2530) + 0x10) = *(vu0_q *)(o + 0x23B0);
    *(vu0_q *)(*(u8 **)(o + 0x2530)) = *(vu0_q *)(o + 0x23A0);
}
/* localdecomp:end func_L39_00663950 */

/* localdecomp:start func_L39_00663C80 */
#include "vu0.h"

typedef union Buf_00663C80 {
    u8 b[8];
    u32 w[2];
} Buf_00663C80;

extern u8 D_L39_004997E0[];
extern void func_L39_00648C20(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);

void func_L39_00663C80(u8 *g) {
    Buf_00663C80 buf;
    u8 *q;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;
    u32 a;
    f32 len;

    func_L39_00648C20(g);
    vec_add_ab(g + 0x120, g + 0x120, g + 0x4D90);
    q = g + 0x19E6;
    qzero(g + 0x4D90);
    if (*q == 0) {
        b = 0;
    } else {
        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
    }
    if ((b ^ 14) == 0) {
        len = func_0038CEA8(g + 0x120);
        if (func_0038CE68(g + 0x15A0, g + 0x120) < len * len * -0.6f) {
            func_0038CE20(g + 0x15A0, g + 0x15A0, 0.5f);
        }
    }
}
/* localdecomp:end func_L39_00663C80 */

/* localdecomp:start func_L39_00663DA8 */
typedef struct VT_00663DA8 {
    u8 pad0[0x28];
    void (*f28)(void *);
    u8 pad2C[8];
    void (*f34)(void *, s32, s32, s32, s32);
} VT_00663DA8;

typedef struct Cam_00663DA8 {
    u8 pad0[0x44];
    f32 f44;
} Cam_00663DA8;

typedef struct Lnk_00663DA8 {
    u8 pad0[4];
    Cam_00663DA8 *p4;
} Lnk_00663DA8;

typedef union Buf_00663DA8 {
    u8 b[16];
    u32 w[4];
    f32 f[2];
} Buf_00663DA8;

extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8;
extern void func_003C4A40(void *, void *);
extern void func_L39_00665568(u8 *);
extern void func_L39_00663950(u8 *);
extern void func_L39_00622450(u8 *);
extern void func_L39_00622990(u8 *);
extern void func_L39_00622C28(u8 *);
extern void func_L39_006233A8(u8 *, void *, void *, void *);
extern void func_L39_00629FE0(u8 *, s32);
extern void func_L39_00656F28(u8 *);
extern void func_L39_0063EE68_00663DA8(u8 *);
extern void func_L39_0063A230(u8 *);
extern void func_L39_006390D0(u8 *);
extern s32 func_L39_00639D90(void *);
extern void func_L39_006217C0(u8 *);
extern void func_L39_0063C468(u8 *);
extern void func_L39_0063C840(u8 *);
extern void func_L39_0063EE70_00663DA8(u8 *);
extern void func_L39_0063EC20(u8 *);
extern void func_L39_0063EC78(u8 *);
extern void func_L35_003A53C0(s32);
extern void func_L39_0063AE10(u8 *);
extern void func_L39_0062B838(u8 *, s32);
extern void func_L39_0063EE78(u8 *);
extern void func_L39_00621388(u8 *);
extern void func_L39_00621600(u8 *);
extern void func_L39_00631E90(u8 *);
extern void func_L39_0063A540(u8 *);
extern void func_L39_00644D08(u8 *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_004436F4(void *);
extern void func_L39_0063F0C8(u8 *);
extern void func_L39_0063B0A8(u8 *);
extern s32 func_L39_00636F30(u8 *, s32, s32);
extern void func_L39_00664760(u8 *);

static __inline__ u32 Dec_00663DA8(u8 *q) {
    Buf_00663DA8 buf;
    u32 r;
    s32 n;
    s32 m;
    s32 k;
    s32 i;
    u8 *d;

    if (*q == 0) {
        r = 0;
    } else {
        n = *q;
        m = n + 1;
        k = ((s32)q - n) & 7;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
        }
        buf.w[0] ^= (u32)q;
        buf.w[1] ^= buf.w[0];
        r = buf.w[1];
    }
    return r;
}

static __inline__ s32 IsState_00663DA8(u8 *o, u32 st) {
    u8 r;

    if (*(u8 **)(o + 0x2530) != 0) {
        r = 0;
        if ((*(u8 **)(o + 0x2530))[0x27B] != 0 && (Dec_00663DA8(o + 0x19E4) ^ st) == 0) {
            r |= 1;
        }
    } else {
        r = 0;
    }
    return r;
}

static __inline__ void Prep_00663DA8(u8 *q) {
    s32 t;
    if (*q == 0) {
        *q = ++D_L39_004997E0[0];
    } else {
        t = *q;
        *q = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

static __inline__ void SetF_00663DA8(u8 *q, f32 v) {
    u8 *hk = q;
    Buf_00663DA8 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    Prep_00663DA8(q);
    key = ((u32 *)D_L39_004997E0)[((u32)hk * D_L39_0024B9C8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.f[1] = v;
    buf.w[1] ^= key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        D_L39_004997E0[m + ((k + i) & 7) * 255] = *d++;
    }
}

void func_L39_00663DA8(u8 *o) {
    u8 *q;
    s32 flag;

    if (o[0x24FC] != 0) {
        if (o[0x24FA] & 0x40) {
            (*(VT_00663DA8 **)(o + 0x14))->f34(o, 0x8E, 1, 0, 1);
            o[0x24FC] = 0;
        } else {
            s8 b = *(s8 *)(o + 0x24F9);

            if (b & 0xF0) {
                if (*(s32 *)(o + 0x24D0) == 4 || *(s8 *)(o + 0x2502) == (b >> 4) - 1) {
                    f32 *e;
                    u8 found;

                    found = IsState_00663DA8(o, 0x31);
                    e = (f32 *)(o + 0x24EC);
                    if (!found) {
                        func_003C4A40(*(void **)(o + 0x2524), o + 0x2504);
                        (*(VT_00663DA8 **)(o + 0x14))->f34(o, 0x16, 1, 0, 1);
                    }
                    {
                        vu0_v4 v;

                        v.x = e[0];
                        v.y = e[1];
                        v.z = e[2];
                        v.w = 0.0f;
                        vec_add_ba(o + 0x120, o + 0x120, &v);
                        vec_add_ab(o + 0x140, o + 0x140, &v);
                    }
                    *(s8 *)(o + 0x2502) = -1;
                    o[0x24FC] = 0;
                }
            } else if (o[0x24FA] & 0x20) {
                o[0x24FC] = 0;
            } else {
                f32 *e;
                u8 found;

                found = IsState_00663DA8(o, 0x31);
                e = (f32 *)(o + 0x24EC);
                if (!found) {
                    (*(VT_00663DA8 **)(o + 0x14))->f34(o, 0x16, 1, 0, 1);
                }
                {
                    vu0_v4 v;

                    v.x = e[0];
                    v.y = e[1];
                    v.z = e[2];
                    v.w = 0.0f;
                    vec_add_ba(o + 0x120, o + 0x120, &v);
                    vec_add_ab(o + 0x140, o + 0x140, &v);
                }
                o[0x24FC] = 0;
            }
        }
    }
    *(s16 *)(o + 0x19E2) = 0;
    *(s16 *)(o + 0x19E0) = 0;
    func_L39_00665568(o);
    func_L39_00663950(o);
    func_L39_00622450(o);
    (*(VT_00663DA8 **)(o + 0x14))->f28(o);
    func_L39_00622990(o);
    if (*(f32 *)(o + 0xA0) < 2.0f || 1021.0f < *(f32 *)(o + 0xA0) ||
        *(f32 *)(o + 0xA4) < 2.0f || 1021.0f < *(f32 *)(o + 0xA4) ||
        *(f32 *)(o + 0xA8) < 2.0f || 1021.0f < *(f32 *)(o + 0xA8)) {
        if (*(s32 *)(o + 0x234C) >= 2) {
            *(s32 *)(o + 0x234C) -= 1;
            *(s32 *)(o + 0x2348) = (*(s32 *)(o + 0x2348) + 31) % 32;
        }
        *(vu0_q *)(o + 0xA0) = *(vu0_q *)(o + 0x1DC0 + *(s32 *)(o + 0x2348) * 16);
    }
    func_L39_00622C28(o);
    flag = 0;
    func_L39_006233A8(o, o + 0xA0, o + 0xB0, o + 0x1540);
    if (*(f32 *)(o + 0x2A8) == 0.0f || *(s16 *)(o + 0x370) != -1 || 10.0f < *(f32 *)(o + 0x2AC)) {
        flag = 1;
    }
    if (*(s32 *)(o + 0x478) == 0xB || flag) {
        func_L39_00629FE0(o, flag);
        if (flag && (o[0x1A0E] == 0 || *(s32 *)(o + 0x251C) != 0) && o[0x1A0B] == 0 && o[0x15EE] != 0) {
            o[0x1A13] = 1;
        }
    }
    func_L39_00656F28(o);
    func_L39_0063EE68_00663DA8(o);
    func_L39_0063A230(o);
    if (*(u8 **)(o + 0x2524) != 0 && (*(u8 **)(o + 0x2524))[0x31] != 0 && *(s32 *)(o + 0x2544) == (D_001D5A1C_sda & 7)) {
        func_L39_006390D0(o);
    } else if (*(s32 *)(o + 0x4A0) != 0) {
        *(f32 *)(o + 0xACC) = 0.01f;
        *(f32 *)(o + 0xB7C) = 0.01f;
    }
    if (o[0x1A08] != 0 || func_L39_00639D90(o) != 0 || (Dec_00663DA8(o + 0x19E4) ^ 1) == 0 ||
        (Dec_00663DA8(o + 0x19E4) ^ 0x1D) == 0 || *(s32 *)(o + 0x2544) == (D_001D5A1C_sda & 7)) {
        func_L39_006217C0(o);
    }
    if (*(u8 **)(o + 0x2524) != 0 && ((*(u8 **)(o + 0x2524))[0x31] != 0 || *(s32 *)(o + 0x1078) != 0)) {
        func_L39_0063C468(o);
        func_L39_0063C840(o);
    }
    func_L39_0063EE70_00663DA8(o);
    if (*(u8 **)(o + 0x2524) != 0 && ((*(u8 **)(o + 0x2524))[0x31] != 0 || *(s32 *)(o + 0x1078) != 0)) {
        func_L39_0063EC20(o);
    } else {
        func_L39_0063EC78(o);
    }
    func_L35_003A53C0((s32)o);
    func_L39_0063AE10(o);
    func_L39_0062B838(o, 0);
    func_L39_0063EE78(o);
    if (o[0x1A0A] != 0) {
        func_L39_00621388(o);
    } else {
        func_L39_00621600(o);
    }
    if (*(u8 **)(o + 0x2524) != 0 && (*(u8 **)(o + 0x2524))[0x31] != 0) {
        func_L39_00631E90(o);
    }
    func_L39_0063A540(o);
    func_L39_00644D08(o);
    if (*(s16 *)(o + 0x2504) != 0) {
        func_L01_0044ABD0(*(void **)(o + 0x2524), o + 0x2504);
    }
    if (*(u8 **)(o + 0x2524) != 0 && (*(u8 **)(o + 0x2524))[0x31] != 0) {
        func_L01_004436F4(*(void **)(o + 0x2524));
    }
    if (*(u8 **)(o + 0x2524) != 0 && (*(u8 **)(o + 0x2524))[0x31] != 0) {
        func_L39_0063F0C8(o);
    }
    if (func_L39_00639D90(o) != 0) {
        *(s32 *)(o + 0x2450) = 0x20;
    }
    func_L39_0063B0A8(o);
    q = *(u8 **)(o + 0x2528);
    if (q != 0 && (*(u8 **)(q + 0x2D8) == o || *(u8 **)(q + 0x2DC) == o)) {
        *(vu0_q *)(o + 0xA0) = *(vu0_q *)(*(u8 **)(q + 0x2D0) + 0x10);
    }
    if ((Dec_00663DA8(o + 0x19E4) ^ 0x90) != 0 && func_L39_00636F30(o, 0x90, 10) == 0) {
        Lnk_00663DA8 *l = *(Lnk_00663DA8 **)(o + 0x2558);
        if (l != 0 && l->p4 != 0) {
            SetF_00663DA8(o + 0x2476, l->p4->f44);
        }
    }
    func_L39_00664760(o);
}
/* localdecomp:end func_L39_00663DA8 */

INCLUDE_ASM("asm/levels", func_L39_00664760);

INCLUDE_ASM("asm/levels", func_L39_00665568);
