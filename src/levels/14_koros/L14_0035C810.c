#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L14_0035C810 */
extern void func_L14_0035C9C0(u8 *, u8 *);
extern int func_L14_0035CA20(int, int *);
extern s32 func_L14_0035CA60(u8 *, u8 *);
extern s32 func_L14_0035CBA0(s32, u8 *);
extern void func_L14_0035CC40(void *, u8 *);
extern void func_L14_0035CD38(void *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_0038CAD0(void *);
__asm__(".extern D_L14_001DD6D0, 4");
__asm__(".extern D_L14_001DD6C0, 4");
extern s32 D_L14_001DD6D0;
extern f32 D_L14_001DD6C0;
void func_L14_0035C810(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        func_L14_0035C9C0(a0, s);
    }
    switch (a0[0x20]) {
    case 1:
        if (func_L14_0035CA20((int)a0, (int *)s)) {
            *(s32 *)s = -1;
            func_L01_004450F0(a0, 2, -1);
            *(s32 *)(s + 0x18) = D_L14_001DD6D0;
        }
        break;
    case 2:
        if (func_0038CAD0(s + 0x18)) {
            func_L01_004450F0(a0, 3, -1);
            *(f32 *)(s + 0x10) = D_L14_001DD6C0;
            func_L14_0035CC40(a0, s);
        }
        break;
    case 3:
        if (func_L14_0035CA60(a0, s)) {
            func_L01_004450F0(a0, 4, -1);
            if (*(s32 *)(s + 0x1C) == -1 || *(s32 *)(s + 0x20) == 0) {
                func_L14_0035CD38(a0, s);
            }
            *(s32 *)(s + 0x18) = *(s32 *)(s + 8);
        }
        break;
    case 4:
        if (*(s32 *)(s + 0x1C) != -1) {
            if (func_L14_0035CBA0((s32)a0, s)) {
                if (*(s32 *)(s + 0x20) != 0) {
                    func_L14_0035CD38(a0, s);
                }
                *(s32 *)(s + 0x1C) = -1;
            }
        }
        if (func_0038CAD0(s + 0x18)) {
            func_L01_004450F0(a0, 5, -1);
            *(s32 *)(s + 0x10) = 0;
        }
        break;
    case 5:
        if (func_L14_0035CA60(a0, s)) {
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L14_0035C810 */

/* localdecomp:start func_L14_0035C9C0 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L14_001DF71C;
__asm__(".extern D_L14_001DF71C, 16");
extern void func_L01_004450F0(u8 *, s32, s32);
void func_L14_0035C9C0(u8 *a0, u8 *a1) {
    s32 i;
    *(u128_t *)(a1 + 0x30) = *(u128_t *)(a0 + 0x10);
    *(s32 *)(a1 + 0x14) = 0;
    *(s32 *)(a1 + 0xC) = 0;
    i = *(s32 *)(a1 + 0x1C);
    if (i != -1) {
        *(f32 *)(a1 + 0x24) = *(f32 *)(D_L14_001DF71C + (i << 8) + 0x18);
        *(s32 *)(a1 + 0x28) = 0;
        *(s32 *)(a1 + 0x2C) = 0;
    }
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L14_0035C9C0 */

/* localdecomp:start func_L14_0035CA20 */
extern char D_001A4C60[];
extern int func_00382380(char *, int, int);

int func_L14_0035CA20(int arg0, int *arg1)
{
    int v = *arg1;
    if (v == -1)
        return 0;
    return func_00382380(D_001A4C60, v, 0) != 0;
}
/* localdecomp:end func_L14_0035CA20 */

INCLUDE_ASM("asm/levels", func_L14_0035CA60);

/* localdecomp:start func_L14_0035CBA0 */
extern u8 *D_L14_001DF71C;
__asm__(".extern D_L14_001DF71C, 16");
__asm__(".extern D_L14_001DD6D8, 4");
__asm__(".extern D_L14_001DD6DC, 4");
__asm__(".extern D_L14_001DD6D4, 4");
__asm__(".extern D_L14_001DD6CC, 4");
extern f32 D_L14_001DD6D8;
extern const f32 D_L14_001DD6DC;
extern f32 D_L14_001DD6D4;
extern const f32 D_L14_001DD6CC;
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
s32 func_L14_0035CBA0(s32 unused, u8 *a1) {
    u8 *o = D_L14_001DF71C + (*(s32 *)(a1 + 0x1C) << 8);
    func_003C41A0((f32 *)(a1 + 0x28), a1 + 0x2C, D_L14_001DD6DC, D_L14_001DD6D8, D_L14_001DD6D8, D_L14_001DD6D4);
    *(f32 *)(o + 0x18) = *(f32 *)(a1 + 0x24) + *(f32 *)(a1 + 0x28);
    if (fabs_asm(D_L14_001DD6DC - *(f32 *)(a1 + 0x28)) < D_L14_001DD6CC) {
        *(f32 *)(o + 0x18) = *(f32 *)(a1 + 0x24) + D_L14_001DD6DC;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L14_0035CBA0 */

/* localdecomp:start func_L14_0035CC40 */
extern u16 *D_L14_0021CCE0[];
extern u8 *D_L14_001DF71C;
__asm__(".extern D_L14_001DF71C, 16");
extern s32 D_L14_001DF758;
extern void func_L14_00355FE0(u8 *e);
extern void func_L14_0035F9B0(u8 *e);

void func_L14_0035CC40(void *unused, u8 *object) {
    u16 *p;
    u8 *e;
    if (*(s32 *)(object + 4) == -1)
        return;
    p = D_L14_0021CCE0[*(s32 *)(object + 4)];
    while ((*(s32 *)(object + 4) & 0xFF) != 0xFF && *(s32 *)(object + 4) <= D_L14_001DF758 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L14_0021CCE0[*(s32 *)(object + 4)])) {
        e = D_L14_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return;
        switch (*(s16 *)(e + 0xAA)) {
        case 0x1699:
            func_L14_00355FE0(e);
            break;
        case 0x16CA:
            func_L14_0035F9B0(e);
            break;
        }
        p++;
    }
}
/* localdecomp:end func_L14_0035CC40 */

/* localdecomp:start func_L14_0035CD38 */
extern u16 *D_L14_0021CCE0[];
extern u8 *D_L14_001DF71C;
__asm__(".extern D_L14_001DF71C, 16");
extern s32 D_L14_001DF758;
extern void func_L14_00356098(u8 *);
extern void func_L14_0035FA00(u8 *);
void func_L14_0035CD38(void *unused, u8 *object) {
    u16 *p;
    u8 *e;
    if (*(s32 *)(object + 4) == -1)
        return;
    p = D_L14_0021CCE0[*(s32 *)(object + 4)];
    while ((*(s32 *)(object + 4) & 0xFF) != 0xFF && *(s32 *)(object + 4) <= D_L14_001DF758 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L14_0021CCE0[*(s32 *)(object + 4)])) {
        e = D_L14_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        switch (*(s16 *)(e + 0xAA)) {
        case 0x1699:
            func_L14_00356098(e);
            break;
        case 0x16CA:
            func_L14_0035FA00(e);
            break;
        }
        p++;
    }
    *(s32 *)(object + 4) = -1;
}
/* localdecomp:end func_L14_0035CD38 */

/* localdecomp:start func_L14_0035CE38 */
void func_L14_0035CF00(u8 *a0);
s32 func_L01_00447490(u8 *a0, s32 a1, s32 a2);
void func_L01_00439880(u8 *a0, u16 *a1, s32 *a2);
void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);

void func_L14_0035CE38(u8 *arg0) {
    u16 tmp;
    s32 tmp2;
    s32 v;

    v = arg0[0x20];
    switch (v) {
    case 0:
        func_L01_00439880(arg0, &tmp, &tmp2);
        *(u16 *)(arg0 + 0x7C) = tmp;
        func_L01_004450F0(arg0, 1, -1);
        break;
    case 1:
        if (func_L01_00447490(arg0, -1, 0) != 0) {
            func_L01_004450F0(arg0, 2, -1);
        }
        break;
    case 2:
        func_L14_0035CF00(arg0);
        break;
    }
    arg0[0xA8] = 0xFF;
}
/* localdecomp:end func_L14_0035CE38 */

/* localdecomp:start func_L14_0035CF00 */
typedef struct {
    vu0_v4 m;
    u8 *obj;
    s32 flags;
    s32 f28;
    f32 f2C;
    s32 f30;
} S_35CF00;
extern u8 D_L14_001D66B0;
extern s32 D_L14_001D67B8;
extern void func_L01_00451FE0(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern void func_L01_00459C50(s32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_L14_0035D088(u8 *, f32, f32);
extern void func_003C2880(void *);
void func_L14_0035CF00(u8 *a0) {
    S_35CF00 blk;
    vu0_v4 v;
    vu0_v4 *pv;
    S_35CF00 *pb;
    func_L01_00451FE0(a0, 0x7FFF, &D_L14_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    if (*(f32 *)(a0 + 0xE8) == 1.0f) {
        pv = &v;
        pb = &blk;
        blk.f2C = 2.0f;
        blk.m = *(vu0_v4 *)(a0 + 0xC0);
        blk.obj = a0;
        blk.f30 = 0;
        func_0038CF68(pv, a0 + 0xE0, 0.5f);
        *pv = *(vu0_v4 *)(a0 + 0x10);
        blk.flags = 0x8000000;
        v.z += 1.1f;
        func_003D4D00(pv, 0x10, a0, pb, 1.4f);
    }
    D_L14_001D67B8 = D_L14_001D67B8 + 1;
    if (D_L14_001D67B8 >= 100) {
        func_L01_00459C50(0x11);
    }
    func_L01_00451E78(a0, 1, 0.0f);
    func_L14_0035D088(a0, -0.080000006f, -0.20000002f);
    func_003C2880(a0);
}
/* localdecomp:end func_L14_0035CF00 */

/* localdecomp:start func_L14_0035D088 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_35D088;
typedef struct {
    u8 pad[0x80];
    f32 x;
    f32 y;
} S_35D088_a;
typedef struct {
    u8 pad[0x140];
    f32 x;
    f32 y;
} S_35D088_b;
typedef struct {
    u8 pad[0x5C];
    u8 *p5C;
} S_35D088_c;
extern S_35D088_a D_001A4BE0;
extern S_35D088_b D_L14_001E1F80;
extern S_35D088_c D_L14_0021F958;
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, f32, f32, u32, s32, s32, s32, f32, s32);
void func_L14_0035D088(u8 *a0, f32 unused_f12, f32 unused_f13) {
    V4_35D088 m;
    V4_35D088 v;
    V4_35D088 p;
    f32 base;
    f32 r;
    f32 ang;
    s32 i;
    u32 col;
    s32 life;
    s32 k;
    u8 *e;
    s32 i2;
    u32 col2;
    s32 life2;
    f32 ang2;
    m = *(V4_35D088 *)(a0 + 0xC0);
    base = func_0038D160(D_001A4BE0.x - D_L14_001E1F80.x, D_001A4BE0.y - D_L14_001E1F80.y);
    for (i = 14; i >= 0; i--) {
        col = 0x625D34;
        r = func_003824E0(0.0050000003539025784f, 0.012000001035630703f);
        ang = func_0038DAB8(base, func_L01_00443A18(0.0f, -6.2831855f));
        v.x = func_0038D098(ang) * r;
        v.y = func_0038D0B0(ang) * r;
        v.z = 0.0f;
        p.x = *(f32 *)(a0 + 0x10) + func_003824E0(-1.0f, 1.0f);
        p.y = *(f32 *)(a0 + 0x14) + func_003824E0(-1.0f, 1.0f);
        p.z = *(f32 *)(a0 + 0x18) + 0.5f;
        if (func_00382468(4) != 0) {
            col = 0x4F5C8DC0;
        }
        life = (func_00382498(40, 60) * 5 + 2) / 6;
        k = func_00382498(-1, -3);
        e = func_L01_004713C8(&p, &v, life, 63000.004f, 336000.0f, col, k, 0x3F, 0, func_003824E0(-0.5f, -3.0f) * 0.00040000002f, 0);
        if (e != 0) {
            e[3] = 0x44;
            e[2] = D_L14_0021F958.p5C[0];
        }
    }
    if (*(f32 *)(a0 + 0xE8) == 1.0f) {
        for (i2 = 39; i2 >= 0; i2--) {
            col2 = 0x625D34;
            p.x = *(f32 *)(a0 + 0x10) + func_L01_00443A18(0.0f, 0.15f);
            p.y = *(f32 *)(a0 + 0x14) + func_L01_00443A18(0.0f, 0.15f);
            p.z = *(f32 *)(a0 + 0x18) + 0.2f;
            ang2 = func_0038DAB8(base, func_L01_00443A18(0.0f, -6.2831855f));
            v.x = func_0038D098(ang2) * 0.12000000476837158f;
            v.y = func_0038D0B0(ang2) * 0.12000000476837158f;
            v.z = 0.0f;
            if (func_00382468(3) != 0) {
                col2 = 0x4C777C;
            }
            life2 = (func_00382498(50, 70) * 5 + 2) / 6;
            k = func_00382498(-2, -4);
            e = func_L01_004713C8(&p, &v, life2, 63000.004f, 168000.0f, col2, k, 0x40, 0, 0.0f, 0);
            if (e != 0) {
                e[2] = D_L14_0021F958.p5C[0];
            }
        }
    }
}
/* localdecomp:end func_L14_0035D088 */
