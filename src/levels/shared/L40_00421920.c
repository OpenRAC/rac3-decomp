#include "common.h"

/* declared by functions of L40_00420998.c, which this file was cut from */
extern s32 func_L39_005F33E0(s32, s32, u8 *);

/* localdecomp:start func_L40_00421920 */
extern u8 *D_L40_0035746C __attribute__((section(".data")));
extern u16 *D_L40_0028EA20[];
extern u8 *D_L40_0024845C;
__asm__(".extern D_L40_0024845C, 16");
extern s32 D_L40_00248498;
extern u8 D_L40_00249FC0[];
extern s32 func_L40_0053DAE8(s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L40_0053F850(void *, void *, s32);
extern s32 func_L40_0053F018(void *);
extern void func_L39_0066C470(s32);
extern void func_L40_00421300(s32, u8 *);
extern void func_L40_00420A38(u8 *, u8 *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
typedef struct { u8 pad[0x88]; s32 a[1]; } S_00421920;
typedef struct { u8 pad[0x310]; u8 *a310[6]; s32 a328[6]; } R_00421920;
typedef s32 u128_00421920 __attribute__((mode(TI)));
typedef union {
    u128_00421920 q;
    f32 f[4];
} V_00421920;

void func_L40_00421920(u8 *m, u8 *r, s32 a2) {
    V_00421920 pos;
    u16 *p;
    u8 *q;
    u8 *c;
    s32 n;
    s32 v;
    f32 old;

    if (m[0x20] == 0) {
        func_L40_0053DAE8(a2, ((S_00421920 *)D_L40_0035746C)->a[*(s32 *)(r + 0x290)]);
        *(u16 *)(r + 0x118) &= 0xFFFC;
        r[0xF0] = 3;
        r[0x128] = 0xFF;
        r[0xF1] = 0xFF;
        r[0xF2] = 0xFF;
        *(f32 *)(r + 0x13C) = 0.0005f;
        *(f32 *)(r + 0x138) = 0.0001f;
        *(f32 *)(r + 0x30) = *(f32 *)(r + 0x2B4);
        r[0x3E] = 1;
        *(s32 *)(r + 0x298) = 0;
        pos.q = *(u128_00421920 *)(m + 0x10);
        pos.f[2] += 1.0f;
        *(f32 *)(m + 0x18) = func_003C3D30(&pos, 0, 0, 0.5f);
        n = 0;
        p = D_L40_0028EA20[*(s32 *)(r + 0x464)];
        while ((*(s32 *)(r + 0x464) & 0xFF) != 0xFF && *(s32 *)(r + 0x464) <= D_L40_00248498 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L40_0028EA20[*(s32 *)(r + 0x464)])) {
            q = D_L40_0024845C + ((*p & 0x7FFF) << 8);
            if (q == 0) {
                break;
            }
            if (n < 6) {
                ((R_00421920 *)r)->a310[n] = q;
                ((R_00421920 *)r)->a328[n] = 0;
                n++;
            }
            c = *(u8 **)(q + 0x24);
            *(u16 *)(q + 0x34) &= 0xFFBE;
            *(u16 *)(q + 0x34) |= *(u16 *)(c + 0x44) & 0x1000;
            *(s32 *)(q + 0x98) = *(s32 *)(c + 0x10);
            p++;
        }
        func_L01_004450F0(m, 1, -1);
    }
    *(u16 *)(m + 0x34) |= 0x1000;
    old = *(f32 *)(r + 0x30);
    v = func_L40_0053F850(m, r + 0xE0, 0);
    if (old != *(f32 *)(r + 0x30)) {
        func_L39_005F33E0(1, 0, m);
    }
    if (v == 4 || *(f32 *)(r + 0x30) < 0.0f) {
        if (func_L40_0053F018(m) != 0 || *(f32 *)(r + 0x30) < 0.0f) {
            func_L39_0066C470(a2);
        }
    }
    func_L40_00421300(a2, m);
    func_L40_00420A38(m, r);
    if (m[0x31] != 0 && func_L01_0040E548(D_L40_00249FC0, m + 0x10) < 256.0f) {
        func_L01_004472C0(m);
        m[0x6F] = 0xF;
    }
}
/* localdecomp:end func_L40_00421920 */

/* localdecomp:start func_L40_00421C08 */
#include "vu0.h"

extern u8 *D_L40_0035746C __attribute__((section(".data")));
extern s32 *D_L40_0028FD80[];
extern u8 D_001FE020[];
extern s32 D_L40_00247690;
__asm__(".extern D_L40_00247690, 4");
extern s32 D_L40_00247704;
__asm__(".extern D_L40_00247704, 4");
extern f32 D_L40_00247700;
__asm__(".extern D_L40_00247700, 4");
extern f32 D_L40_002476FC;
__asm__(".extern D_L40_002476FC, 4");
extern void func_L39_0066C470(s32);
extern void func_L40_0053F6E0(void *);
extern void func_L39_005F2FF8(void *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L40_00421920(u8 *, u8 *, s32);
extern s32 func_L01_004561B8(u8 *);
extern void func_003C2F58(void *, s32, void *);
extern void *func_L40_00421FE0(void *, void *, void *, void *, void *, void *, s32, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_004455E8(void *, void *, f32, f32, f32, f32);
extern f32 func_L39_005B44C8(void);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern s32 func_L39_005F33E0(s32, s32, u8 *);
extern void func_L01_0045A748(void *, void *);
extern s32 func_L01_00454370(void *, void *);

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00421C08;

typedef struct {
    u8 p0[0x88];
    s32 f88[1];
} S2_00421C08;

void func_L40_00421C08(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 *n = *(u8 **)(m + 0x90);
    s32 t = *(s32 *)n;
    u8 *e;
    f32 s, a, z;
    V_00421C08 pos;
    V_00421C08 zero;

    *(s32 *)(n + 0x18) = ((S2_00421C08 *)D_L40_0035746C)->f88[*(s32 *)(v + 0x290)];
    if (v[0x3E] == 2) {
        func_L39_0066C470(t);
        func_L40_0053F6E0(m);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
        func_L39_005F2FF8(m, 1);
        func_L01_004450F0(m, 0x25, -1);
        return;
    }
    func_L40_00421920(m, v, t);
    switch (m[0x20]) {
    case 2:
        if (func_L01_004561B8(m) != 0) {
            func_003C2F58(m, D_L40_00247690, &pos);
            qzero(&zero);
            func_L40_00421FE0(m, &pos, &zero, v + 0x2D0, &zero, m + 0xF0, (D_L40_00247704 * 5 + 2) / 6, 0, 0);
        }
        if (m[0x43] != 2) {
            func_003C3A10(m, 2, 0, 8);
        }
        a = func_0038D160(*(f32 *)(v + 0x2D0) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x2D4) - *(f32 *)(m + 0x14));
        func_L01_004455E8(m, v + 0x458, a, 0.0025132743f, 0.0025132743f, 0.12566371f);
        s = (f32)*(s32 *)(v + 0x460) / 100.0f;
        *(f32 *)(v + 0x2FC) = s / 3.0f;
        *(f32 *)(v + 0x30C) = (s + s) / 3.0f;
        a = func_L39_005B44C8();
        *(f32 *)(v + 0x2F4) = func_0038D0B0(a) * 0.25f * s;
        *(f32 *)(v + 0x2F8) = func_0038D098(a) * 0.25f * s;
        *(f32 *)(v + 0x304) = func_0038D0B0(a) * 0.25f * s;
        *(f32 *)(v + 0x308) = func_0038D098(a) * 0.25f * s;
        if ((*(s32 *)(v + 0x460))++ >= 0x54) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    case 1:
        func_L01_004561B8(m);
        if (*(s32 *)(v + 0x2AC) == -1
            || *(u8 **)((e = D_001FE020 + *(s32 *)(v + 0x2AC) * 0x80) + 0xDC) != m
            || e[0xD0] == 0) {
            *(s32 *)(v + 0x2AC) = func_L39_005F33E0(3, 4, m);
        }
        if (m[0x43] != 1) {
            func_003C3A10(m, 1, 0, 8);
        }
        func_L01_0045A748(m, &((V_00421C08 *)D_L40_0028FD80[*(s32 *)(v + 0x454)])[*(s32 *)(v + 0x450) + 1]);
        s = func_0038D0B0(*(f32 *)(v + 0x348) * 0.017453292f);
        z = *(f32 *)(v + 0x230) + 0.6f + D_L40_002476FC * s;
        *(f32 *)(v + 0x348) += D_L40_00247700;
        if (*(f32 *)(v + 0x348) >= 360.0f) {
            *(f32 *)(v + 0x348) = 0.0f;
        }
        *(f32 *)(m + 0x18) = z;
        *(s32 *)(v + 0x460) = 0;
        break;
    case 3:
        func_L01_004561B8(m);
        if (func_L01_00454370(m, v + 0xE0) & 2) {
            func_L01_004450F0(m, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L40_00421C08 */
