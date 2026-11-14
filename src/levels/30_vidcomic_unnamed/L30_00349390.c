#include "common.h"
#include "vu0.h"

typedef struct { u8 pad0[0x20]; u8 b20; u8 pad21[0x43 - 0x21]; u8 b43; u8 pad44[0x68 - 0x44]; void *p68; } Obj_0034BC90;
typedef struct { u8 pad0[0x50]; f32 f50; s16 h54; u8 pad56[0x210 - 0x56]; f32 f210; s32 w214; s32 w218; u8 pad21c[0x220 - 0x21c]; f32 f220; } P_0034BC90;

INCLUDE_ASM("asm/levels", func_L30_00349390);

/* localdecomp:start func_L30_00349470 */
extern void func_L30_00349630(void *, void *, float *);
extern void func_0038CF68(void *, void *, f32);
extern f32 D_L30_001DD2F0;
__asm__(".extern D_L30_001DD2F0, 4");

void func_L30_00349470(u8 *a0, void *a1) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];
    f32 k;

    func_L30_00349630(a0, 0, v);
    vec_sub_ab(w, a1, v);
    func_0038CF68(w, w, 1.0f);
    k = D_L30_001DD2F0;
    *(f32 *)(p + 0x68) = w[0] * k;
    *(f32 *)(p + 0x64) = w[2] * (-k);
}
/* localdecomp:end func_L30_00349470 */

INCLUDE_ASM("asm/levels", func_L30_003494F0);

INCLUDE_ASM("asm/levels", func_L30_00349550);

INCLUDE_ASM("asm/levels", func_L30_00349630);

INCLUDE_ASM("asm/levels", func_L30_003496D8);

INCLUDE_ASM("asm/levels", func_L30_003497B0);

/* localdecomp:start func_L30_00349968 */
s32 func_L30_00349968(u8 *a0, u32 a1, s32 a2) {
    u8 *p = *(u8 **)(a0 + 0x68);

    if (a1 >= 5) {
        return 0;
    }
    if (a1 == 0 && *(s32 *)(p + 0xD0) > 0) {
        if (a2 != 0 && *(s32 *)(p + 0xCC) != 4 && *(s32 *)(p + 0xCC) != 5 && *(s32 *)(p + 0xCC) != 6) {
            return 0;
        }
        return 1;
    }
    if (a1 == 1 && *(s32 *)(p + 0x110) > 0) {
        return 1;
    }
    if (a1 == 2 && *(s32 *)(p + 0x120) > 0) {
        return 1;
    }
    if (a1 == 3 && *(s32 *)(p + 0xF0) > 0) {
        return 1;
    }
    if (a1 == 4 && *(s32 *)(p + 0x100) > 0) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L30_00349968 */

/* localdecomp:start func_L30_00349A20 */
extern f32 D_L30_001DD278[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD278, 8");
extern f32 D_L30_001DD288[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD288, 8");
extern f32 D_L30_001DD298[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD298, 8");
extern s32 D_L30_001DD1F0[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD1F0, 8");
extern f32 func_003824E0(f32, f32);

void func_L30_00349A20(u8 *a0, s32 a1) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 *tbl;
    s32 n;
    s32 i;
    f32 r;

    i = 0;
    if (a0[0x20] == 3) {
        tbl = D_L30_001DD278;
    } else if (a0[0x20] == 4) {
        tbl = D_L30_001DD288;
    } else if (a0[0x20] == 5) {
        tbl = D_L30_001DD298;
    } else {
        return;
    }
    n = D_L30_001DD1F0[a0[0x20] - 3];
    r = func_003824E0(0.0f, 1.0f);
    while (tbl[i] < r) {
        r -= tbl[i];
        i++;
    }
    i++;
    if (a1 == 3) {
        *(s32 *)(q + 0xEC) = i;
        *(s32 *)(q + 0xF0) = n;
        *(s32 *)(q + 0xE8) = 0;
    } else {
        *(s32 *)(q + 0xFC) = i;
        *(s32 *)(q + 0x100) = n;
        *(s32 *)(q + 0xF8) = 0;
    }
}
/* localdecomp:end func_L30_00349A20 */

INCLUDE_ASM("asm/levels", func_L30_00349B28);

INCLUDE_ASM("asm/levels", func_L30_00349CA8);

INCLUDE_ASM("asm/levels", func_L30_00349EE8);

/* localdecomp:start func_L30_0034A058 */
extern u8 D_L30_001D66B0;
extern void func_L30_00349630(void *, void *, float *);
extern void func_L30_00342C80(float *, u8 *, float, float);
void func_L30_0034A058(void *a, s32 unused, void *c) {
    float v[4];
    func_L30_00349630(a, c, v);
    v[2] += 0.5f;
    func_L30_00342C80(v, &D_L30_001D66B0, 0.5f, 1.0f);
}
/* localdecomp:end func_L30_0034A058 */

/* localdecomp:start func_L30_0034A0A8 */
__asm__(".extern D_L30_001DF728, 16");
extern u8 *D_L30_001DF728;
__asm__(".extern D_L30_001DEAB0, 4");
extern s32 D_L30_001DEAB0;

void func_L30_0034A0A8(s32 unused, s32 flag) {
    u8 *p = D_L30_001DF728;
    u8 *obj = 0;

    if (p != 0) {
        do {
            if (*(s16 *)(p + 0xAA) == 0x1B55) {
                obj = *(u8 **)(p + 0x68);
            }
            p = *(u8 **)(p + 0x28);
        } while (p != 0);
    }
    if (obj != 0) {
        if (flag != 0) {
            *(f32 *)(obj + 0x10C) = 1.0f;
        } else {
            *(s32 *)(obj + 0x10C) = 0;
        }
    }
    D_L30_001DEAB0 = flag ^ 1;
}
/* localdecomp:end func_L30_0034A0A8 */

LINKER_REMNANT("asm/levels", func_L30_0034A100);

INCLUDE_ASM("asm/levels", func_L30_0034A108);

INCLUDE_ASM("asm/levels", func_L30_0034A968);

INCLUDE_ASM("asm/levels", func_L30_0034AA20);

/* localdecomp:start func_L30_0034ABF8 */
extern u8 *func_L01_00447490(u8 *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 D_L30_001DF0D8;

void func_L30_0034ABF8(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *p;
    u8 *q;
    s32 n;

    D_L30_001DF0D8 = 0.0f;
    p = func_L01_00447490(a0, 0x10000, 0);
    a0[0xA8] = 0xFF;
    if (*(s32 *)(st + 0x24) != 0) {
        return;
    }
    if (p == 0) {
        return;
    }
    q = *(u8 **)(p + 0x20);
    if (q != 0) {
        if (*(s16 *)(q + 0xAA) == 0x9DE) {
            return;
        }
    }
    n = *(f32 *)(p + 0x2C);
    a0[0xA8] = 0xFF;
    *(s32 *)(st + 0x20) -= n;
    D_L30_001DF0D8 = 1.0f;
    if (*(s32 *)(st + 0x20) > 0) {
        func_L01_004450F0(a0, 7, -1);
    } else {
        func_L01_004450F0(a0, 8, -1);
    }
}
/* localdecomp:end func_L30_0034ABF8 */

/* localdecomp:start func_L30_0034ACC8 */
__asm__(".extern D_L30_001DF728, 16");
extern u8 *D_L30_001DF728;
__asm__(".extern D_L30_001DEAB0, 4");
extern s32 D_L30_001DEAB0;

void func_L30_0034ACC8(s32 unused, s32 flag) {
    u8 *v = D_L30_001DF728;
    u8 *f = 0;

    if (v != 0) {
        do {
            if (*(s16 *)(v + 0xAA) == 0x1B55) {
                f = *(u8 **)(v + 0x68);
            }
            v = *(u8 **)(v + 0x28);
        } while (v != 0);
    }
    if (f != 0) {
        if (flag != 0) {
            *(f32 *)(f + 0xEC) = 1.0f;
        } else {
            *(s32 *)(f + 0xEC) = 0;
        }
    }
    D_L30_001DEAB0 = flag ^ 1;
}
/* localdecomp:end func_L30_0034ACC8 */

INCLUDE_ASM("asm/levels", func_L30_0034AD28);

INCLUDE_ASM("asm/levels", func_L30_0034B2F0);

/* localdecomp:start func_L30_0034B4A0 */
extern s32 func_L01_0045BD10(u8 *, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
__asm__(".extern D_001DD434, 4");
extern f32 D_001DD434;

void func_L30_0034B4A0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 x, s;
    u8 *q;

    if (*(f32 *)(p + 0x30) < *(f32 *)(a0 + 0x10)) {
        func_L01_0045BD10(a0, 3.1415927f);
    } else {
        func_L01_0045BD10(a0, 0.0f);
    }
    q = a0 + 0xD0;
    x = *(f32 *)(a0 + 0xF8);
    s = func_0038D0B0(x);
    func_0038CF68(q, q, D_001DD434 + (1.0f - D_001DD434) * __builtin_fabsf(s));
}
/* localdecomp:end func_L30_0034B4A0 */

INCLUDE_ASM("asm/levels", func_L30_0034B538);

/* localdecomp:start func_L30_0034B688 */
extern void func_L01_004450F0(void *, s32, s32);
__asm__(".extern D_L30_001DD440, 4");
__asm__(".extern D_L30_001DD444, 4");
__asm__(".extern D_L30_001DD448, 4");
extern f32 D_L30_001DD440;
extern f32 D_L30_001DD444;
extern f32 D_L30_001DD448;

typedef struct { u8 pad0[0x60]; f32 f60; u8 pad64[0xA4 - 0x64]; f32 fA4; f32 fA8; f32 fAC; } S_0034B688;

void func_L30_0034B688(u8 *a0) {
    S_0034B688 *p = *(S_0034B688 **)(a0 + 0x68);

    p->f60 = 0.75f;
    p->fA4 = D_L30_001DD440 * 0.017453292f * (0.024f * (1.0f / 60.0f));
    p->fA8 = D_L30_001DD444 * 0.017453292f * (0.024f * (1.0f / 60.0f));
    p->fAC = D_L30_001DD448 * 0.017453292f * (1.2f * (1.0f / 60.0f));
    *(u16 *)(a0 + 0x34) |= 0x100;
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L30_0034B688 */

INCLUDE_ASM("asm/levels", func_L30_0034B720);

/* localdecomp:start func_L30_0034B980 */
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_L01_0044E850(f32, f32, void *, void *, s32);
__asm__(".extern D_L30_001DD460, 4");
extern f32 D_L30_001DD460;
__asm__(".extern D_L30_001DD45C, 4");
extern f32 D_L30_001DD45C;

s32 func_L30_0034B980(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 f20;
    s32 ret = 1;
    f32 r2;

    f20 = *(f32 *)(p + 0x210) + *(f32 *)(a0 + 0xF4);
    if (func_0038D0B0(f20) < D_L30_001DD460) {
        r2 = func_0038D098(f20);
        f20 = (r2 < 0.0f) ? 3.1415927f : 0.0f;
        ret = 0;
    }
    if (func_0038D098(f20) < 0.0f) {
        *(f32 *)(p + 0x1F8) = -D_L30_001DD45C;
        *(f32 *)(p + 0x1F0) = f20 - 3.1415927f;
    } else {
        *(f32 *)(p + 0x1F8) = D_L30_001DD45C;
        *(f32 *)(p + 0x1F0) = -f20;
    }
    func_L01_0044E850(0.0432000011f, 0.432000041f, a0, p + 0x190, 1);
    return ret;
}
/* localdecomp:end func_L30_0034B980 */

INCLUDE_ASM("asm/levels", func_L30_0034BA88);

/* localdecomp:start func_L30_0034BBC0 */
extern u8 *func_L01_00447490(u8 *, s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern void func_003C4A40(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L30_0034BBC0(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *p = func_L01_00447490(a0, 0x10000, 0);
    f32 f;

    func_L01_0044ABD0(a0, st + 0x180);
    if (p == 0) {
        return;
    }
    a0[0xA8] = 0xFF;
    f = *(f32 *)(p + 0x2C);
    if (0.0f < f) {
        if (a0[0x20] == 4) {
            return;
        }
        *(f32 *)(st + 0x50) = *(f32 *)(st + 0x50) - f;
        if (*(f32 *)(st + 0x50) <= 0.0f) {
            func_L01_004450F0(a0, 4, -1);
        } else {
            st[0x187] = 0xFF;
            func_003C4A40(a0, st + 0x180);
        }
    }
}
/* localdecomp:end func_L30_0034BBC0 */

/* localdecomp:start func_L30_0034BC90 */
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L30_0034BC90(void *a0, f32 a3, s32 a1, s32 a2) {
    Obj_0034BC90 *o = (Obj_0034BC90 *)a0;
    P_0034BC90 *p = (P_0034BC90 *)o->p68;
    p->f50 = (f32)p->h54;
    p->f220 = p->f210 = a3;
    p->w214 = a1;
    p->w218 = a2;
    if (o->b43 != 2) func_003C3A10(a0, 2, 0, 0);
    if ((u32)(p->w214 - 1) < 0x42 && o->b20) func_L01_004450F0(a0, p->w214, -1);
}
/* localdecomp:end func_L30_0034BC90 */

INCLUDE_ASM("asm/levels", func_L30_0034BD28);
