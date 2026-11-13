#include "common.h"

/* localdecomp:start func_L40_003D88A8 */
typedef struct {
    u8 pad0[0x18D];
    s8 f18D;
} S_003D88A8g;

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0x62];
    s32 f98;
    u8 pad9C[0x64];
} S_003D88A8m;

extern S_003D88A8g *D_00241640;
__asm__(".extern D_00241640, 16");
extern u8 *D_L40_0024845C_003D88A8;
__asm__(".extern D_L40_0024845C_003D88A8, 4");
extern u8 *D_L40_0024845C;
__asm__(".extern D_L40_0024845C, 16");
extern s32 D_L40_00242930;
__asm__(".extern D_L40_00242930, 16");
extern s32 D_001A5DF8[];
extern s32 D_001A5E00 __attribute__((section(".data")));

extern void func_003C2880(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_L39_005F2FF8(void *, s32);
extern void func_L39_005F33E0(s32, s32, void *);
extern void func_L39_0061C1E0(void *, s32);
extern s32 func_L39_0066C280(s32, void *, s32, void *, void *);
extern s32 *func_L39_0066C2B8(void);
extern s32 func_00197498(s32);
extern s32 func_L40_0053D8C8(s32, void *, void *, void *);
extern s32 func_L40_0053F7F0(s32);
extern void func_L40_003D9530(u8 *);
extern void func_L40_003D9160(u8 *);
extern void func_L40_003D8E88(void);
extern void func_L40_003EC320(void);
extern void func_L40_003EBEA0(void);
extern void func_L40_003EBCD8(void);

void func_L40_003D88A8(u8 *moby) {
    u8 *pv = *(u8 **)(moby + 0x68);
    S_003D88A8m *m;

    if (*(s32 *)(pv + 0x1A0) == -1 && moby[0x20] == 0) {
        if (D_00241640->f18D == 0) {
            if (*(s32 *)(pv + 0x1D0) != -1) {
                func_003C2880(D_L40_0024845C_003D88A8 + (*(s32 *)(pv + 0x1D0) << 8));
            }
            func_003C2880(moby);
            return;
        }
        func_L39_0061C1E0(moby, -1);
        moby[0x20] = 0x26;
        *(s32 *)(pv + 0x1B0) = 2;
        func_L40_0053D8C8(0x19F6, func_L40_003D9530, func_L40_003D9160, func_L40_003D8E88);
        func_L40_0053D8C8(0x109A, func_L40_003EC320, func_L40_003EBEA0, func_L40_003EBCD8);
        if (*(s32 *)(pv + 0x1D0) != -1) {
            func_L39_0061C1E0(D_L40_0024845C_003D88A8 + (*(s32 *)(pv + 0x1D0) << 8), -1);
        }
        *(u16 *)(moby + 0x34) = (*(u16 *)(moby + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(moby + 0x98) = 0;
        func_L39_005F2FF8(moby, 1);
        return;
    }
    if (*(s32 *)(pv + 0x1B0) == 0) {
        if (D_00241640->f18D == 0) {
            if (*(s32 *)(pv + 0x1D0) != -1) {
                func_003C2880(D_L40_0024845C_003D88A8 + (*(s32 *)(pv + 0x1D0) << 8));
            }
            func_003C2880(moby);
            return;
        }
        func_L39_0061C1E0(moby, -1);
        func_L40_0053D8C8(0x19F6, func_L40_003D9530, func_L40_003D9160, func_L40_003D8E88);
        func_L40_0053D8C8(0x109A, func_L40_003EC320, func_L40_003EBEA0, func_L40_003EBCD8);
        *(s32 *)(pv + 0x1B0) = 1;
        *(f32 *)(moby + 0x18) = func_003C3D30(moby + 0x10, 0, 0, 0.5f);
        *(s32 *)(moby + 0x98) = 0;
        *(u16 *)(moby + 0x34) = (*(u16 *)(moby + 0x34) | 0x41) & 0xEFFF;
        moby[0x30] = 0xFF;
        func_L39_005F2FF8(moby, 1);
        if (*(s32 *)(pv + 0x1D0) != -1) {
            func_L39_0061C1E0(D_L40_0024845C_003D88A8 + (*(s32 *)(pv + 0x1D0) << 8), -1);
            m = (S_003D88A8m *)D_L40_0024845C;
            m[*(s32 *)(pv + 0x1D0)].f34 |= 0x41;
            m[*(s32 *)(pv + 0x1D0)].f34 &= 0xEFFF;
            m[*(s32 *)(pv + 0x1D0)].f98 = 0;
            func_L39_005F2FF8((u8 *)m + (*(s32 *)(pv + 0x1D0) << 8), 1);
        }
    } else if (func_L40_0053F7F0((moby - D_L40_0024845C_003D88A8) >> 8) != 0) {
        if (*(s32 *)(pv + 0x1B0) == 1) {
            if (*(s32 *)(pv + 0x1D8) == 1 && D_001A5E00 >= 3) {
                func_003C2880(moby);
                return;
            }
            {
            u8 *msg = (u8 *)func_L39_0066C2B8();
            u8 *q;
            s32 off;

            if (msg == 0) {
                return;
            }
            off = ((s32 (*)(s32, s32, s32, s32, void *))func_L39_0066C280)(0, func_00197498(2), D_001A5DF8[0] + 0x1F4, 0x19F6, msg);
            q = msg + off;
            *(s32 *)q = (moby - D_L40_0024845C) >> 8;
            q += 4;
            *(s32 *)msg = q - msg;
            }
            *(s32 *)(pv + 0x1B0) = 2;
            func_L40_0053D8C8(0x19F6, func_L40_003D9530, func_L40_003D9160, func_L40_003D8E88);
            func_L40_0053D8C8(0x109A, func_L40_003EC320, func_L40_003EBEA0, func_L40_003EBCD8);
            *(s32 *)(pv + 0x1C0) = 0;
            *(u16 *)(moby + 0x34) &= 0xFFBE;
            *(u16 *)(moby + 0x34) |= *(u16 *)(*(u8 **)(moby + 0x24) + 0x44) & 0x1000;
            *(s32 *)(moby + 0x98) = *(s32 *)(*(u8 **)(moby + 0x24) + 0x10);
        }
    } else if (*(s32 *)(pv + 0x1B0) == 1) {
        if (*(s32 *)(pv + 0x1D8) == 1 && D_001A5E00 >= 3) {
            func_003C2880(moby);
            return;
        }
        func_L40_0053D8C8(0x19F6, func_L40_003D9530, func_L40_003D9160, func_L40_003D8E88);
        func_L40_0053D8C8(0x109A, func_L40_003EC320, func_L40_003EBEA0, func_L40_003EBCD8);
        *(s32 *)(pv + 0x1C0) = 0;
        *(s32 *)(pv + 0x1B0) = 2;
        *(u16 *)(moby + 0x34) &= 0xFFBE;
        *(u16 *)(moby + 0x34) |= *(u16 *)(*(u8 **)(moby + 0x24) + 0x44) & 0x1000;
        *(s32 *)(moby + 0x98) = *(s32 *)(*(u8 **)(moby + 0x24) + 0x10);
    }

    if (moby[0x20] == 0x25) {
        func_L01_00451FE0(moby, 0xF, (u8 *)&D_L40_00242930, 0xFF, 0xB4, 0, 0, 0x23,
                          3.0f, 7.0f, 4.0f, 7.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        ((s32 (*)(s32, s32, u8 *))func_L39_005F33E0)(2, 0, moby);
        func_003C2880(moby);
        if (++*(s32 *)(pv + 0x1C0) >= 0x1A2) {
            *(s32 *)(pv + 0x1C0) = 0;
            moby[0x20] = 0;
            *(s32 *)(pv + 0x1B4) = 0;
            *(s32 *)(pv + 0x1B0) = 1;
            func_0038CB78(pv + 0x1A4, 0, 0x48);
        }
    }
    if (moby[0x20] == 0x27) {
        *(s32 *)(pv + 0x1C0) = 0;
        moby[0x20] = 0;
        *(s32 *)(pv + 0x1B4) = 0;
        *(s32 *)(pv + 0x1B0) = 1;
        func_0038CB78(pv + 0x1A4, 0, 0x48);
        {
        u8 *msg = (u8 *)func_L39_0066C2B8();
        u8 *q;
        s32 off;

        if (msg == 0) {
            return;
        }
        off = ((s32 (*)(s32, s32, s32, s32, void *))func_L39_0066C280)(0, func_00197498(2), D_001A5DF8[0] + 0x1F4, 0x19F6, msg);
        q = msg + off;
        *(s32 *)q = (moby - D_L40_0024845C) >> 8;
        q += 4;
        *(s32 *)msg = q - msg;
        }
        *(s32 *)(pv + 0x1B0) = 2;
        func_L40_0053D8C8(0x19F6, func_L40_003D9530, func_L40_003D9160, func_L40_003D8E88);
        func_L40_0053D8C8(0x109A, func_L40_003EC320, func_L40_003EBEA0, func_L40_003EBCD8);
        *(s32 *)(pv + 0x1C0) = 0;
        *(u16 *)(moby + 0x34) &= 0xFFBE;
        *(u16 *)(moby + 0x34) |= *(u16 *)(*(u8 **)(moby + 0x24) + 0x44) & 0x1000;
        *(s32 *)(moby + 0x98) = *(s32 *)(*(u8 **)(moby + 0x24) + 0x10);
    }
}
/* localdecomp:end func_L40_003D88A8 */

INCLUDE_ASM("asm/levels", func_L40_003D8E88);

/* localdecomp:start func_L40_003D8FB0 */
typedef struct N_003D8FB0 N_003D8FB0;
extern u8 D_1A5CD0[];
extern s32 D_L40_00242930;
__asm__(".extern D_L40_00242930, 16");
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L39_005F33E0(s32, s32, void *);
extern void func_L40_0053F6E0(void *);
extern s32 func_L40_0053DC18(s32 id);
extern void func_L39_005F2FF8(void *, s32);
extern s32 *func_L39_0066C3C8(s32 *n, s32 **head);

void func_L40_003D8FB0(s32 a0, u8 *a1) {
    u8 *r;
    s32 *p;
    s32 *q;

    r = *(u8 **)(a1 + 0x90);
    p = *(s32 **)(r + 0x38);
    while (p != 0) {
        u8 *g = D_1A5CD0;
        q = p + 2;
        if (*(s32 *)(g + 0x128) < q[2]) {
            p = (s32 *)p[0x21];
            continue;
        }
        switch (q[0]) {
        case 1:
            if (q[3] != 0) {
                continue;
            }
            func_L01_004450F0(a1, 2, -1);
            break;
        case 2:
            func_L01_00451FE0(a1, 0xF, (u8 *)&D_L40_00242930, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 7.0f, 4.0f, 7.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
            func_L39_005F33E0(2, 0, a1);
            func_L40_0053F6E0(a1);
            func_L40_0053DC18(a0);
            *(s32 *)(a1 + 0x98) = 0;
            *(u16 *)(a1 + 0x34) = (*(u16 *)(a1 + 0x34) | 0x41) & 0xEFFF;
            func_L39_005F2FF8(a1, 1);
            func_L01_004450F0(a1, 0x25, -1);
            return;
        }
        p = func_L39_0066C3C8(p, (s32 **)(r + 0x38));
    }
}
/* localdecomp:end func_L40_003D8FB0 */

/* localdecomp:start func_L40_003D9160 */
typedef struct { u8 pad[0x88]; s32 a[1]; } S_003D9160;
extern void *D_L40_0035746C[];
extern u8 D_1A5CD0[];
extern s32 func_L40_0053E1A8(u8 *m, s32 team, s32 a2, f32 range, f32 b, f32 c, void *a3);
extern u8 *func_L39_0061D1D8(s32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L40_003EBBE0(void *, s32, s32, s32);
extern s32 *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32, void *, s32, void *, void *);
extern s32 func_L39_0066C1F0(s32);

void func_L40_003D9160(u8 *a0) {
    u8 *r;
    s32 w;
    s32 id;
    u8 *t;
    u8 *e;
    u8 *x;
    s32 *n;
    s32 v;
    f32 buf[4] __attribute__((aligned(16)));

    r = *(u8 **)(a0 + 0x68);
    w = **(s32 **)(a0 + 0x90);
    switch (*(s32 *)(r + 0x1B4)) {
    case 0:
        *(s32 *)(r + 0x1B4) = 1;
        break;
    case 1:
        t = *(u8 **)(r + 0x1A8);
        id = -1;
        if (t == 0 || t[0x31] == 0 || *(s16 *)(*(u8 **)(t + 0x1C) + 0xAA) != 0x109A) {
            id = -1;
            if (++*(s32 *)(r + 0x1D4) >= 9) {
                id = func_L40_0053E1A8(a0, ((S_003D9160 *)D_L40_0035746C[0])->a[*(s32 *)(r + 0x1A0)], 0,
                                       *(f32 *)(r + 0x1C8), -1.0f, 10.0f, 0);
                if (id == -1) {
                    return;
                }
                e = func_L39_0061D1D8(id);
                if (e != 0 && (e[3] & 0xF) == 0 && (x = *(u8 **)(e + 0x2528)) != 0 &&
                    *(s16 *)(*(u8 **)(x + 0x2D0) + 0xAA) == 0x107E) {
                    id = -1;
                }
                if (id == -1) {
                    return;
                }
                *(s32 *)(r + 0x1D4) = 0;
            }
        }
        if (id != -1) {
            func_003C2F58(a0, 0, buf);
            v = func_L40_003EBBE0(buf, *(s32 *)(r + 0x1A0), *(s32 *)(r + 0x1D0), -1);
            *(s32 *)(r + 0x1B8) = 0;
            *(s32 *)(r + 0x1B4) = 2;
            *(s32 *)(r + 0x1AC) = v;
            n = func_L39_0066C2B8();
            if (n != 0) {
                *n = func_L39_0066C280(1, (void *)w, *(s32 *)(D_1A5CD0 + 0x128) + 500, 0, n);
            }
        }
        break;
    case 2:
        if ((*(s32 *)(r + 0x1CC) * 5 + 2) / 6 < ++*(s32 *)(r + 0x1B8)) {
            *(s32 *)(r + 0x1B4) = 1;
            *(s32 *)(r + 0x1A8) = func_L39_0066C1F0(*(s32 *)(r + 0x1AC));
        }
        break;
    }
}
/* localdecomp:end func_L40_003D9160 */

INCLUDE_ASM("asm/levels", func_L40_003D9370);

/* localdecomp:start func_L40_003D9530 */
typedef struct { u8 pad[0x88]; s32 a[1]; } S_003D9530;
extern void *D_L40_0035746C[];
extern void func_L40_003D9370(u8 *, u8 *, s32);
extern void func_L40_0053F6E0(void *);
extern void func_L39_0066C470(s32);
extern void func_L39_005F2FF8(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_00454370(void *, void *);

void func_L40_003D9530(u8 *a0) {
    u8 *r;
    u8 *m;
    s32 v;

    r = *(u8 **)(a0 + 0x68);
    m = *(u8 **)(a0 + 0x90);
    v = *(s32 *)m;
    *(s32 *)(m + 0x18) = ((S_003D9530 *)D_L40_0035746C[0])->a[*(s32 *)(r + 0x1A0)];
    func_L40_003D9370(a0, r, v);
    if (r[0x3E] == 2) {
        func_L40_0053F6E0(a0);
        func_L39_0066C470(v);
        *(s32 *)(a0 + 0x98) = 0;
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F2FF8(a0, 1);
        func_L01_004450F0(a0, 0x25, -1);
    }
    switch (a0[0x20]) {
    case 2:
        if (func_L01_004561B8(a0) != 0 && a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, 8);
        }
        if (a0[0x60] & 2) {
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    case 1:
        if (func_L01_004561B8(a0) != 0 && a0[0x43] != 0) {
            func_003C3A10(a0, 0, 0, 8);
        }
        break;
    case 3:
        if (func_L01_004561B8(a0) != 0 && a0[0x43] != 3) {
            func_003C3A10(a0, 3, 0, 8);
        }
        if (func_L01_00454370(a0, r + 0xE0) & 2) {
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L40_003D9530 */
