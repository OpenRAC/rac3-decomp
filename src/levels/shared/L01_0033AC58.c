#include "common.h"

typedef struct {
    u8 pad0[0x18];
    f32 f18;
} S_33BDC8;
typedef void (*Fn_33CA98)(u8 *);

/* localdecomp:start func_L01_0033AC58 */
__asm__(".extern D_L01_001DCFB8, 4");
extern s32 D_L01_001DCFB8;
s32 *func_L01_0033AC58(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 1) {
        *a2 = 28;
        return &D_L01_001DCFB8;
    }
    return 0;
}
/* localdecomp:end func_L01_0033AC58 */

INCLUDE_ASM("asm/levels", func_L01_0033AC78);

INCLUDE_ASM("asm/levels", func_L01_0033B530);

INCLUDE_ASM("asm/levels", func_L01_0033B7C0);

INCLUDE_ASM("asm/levels", func_L01_0033C030);

/* localdecomp:start func_L01_0033C4B8 */
__asm__(".extern D_L01_001DCFB4, 4");

extern s32 D_001D545C[];
extern s32 D_L01_001DCFB4;
extern void func_L01_00459C50(s32 a0);

void func_L01_0033C4B8(S_33BDC8 *a0) {
    if (D_001D545C[0] == 8) {
        if (a0->f18 < 330.0f) {
            D_L01_001DCFB4++;
        }
        if (D_L01_001DCFB4 >= 46) {
            func_L01_00459C50(12);
        }
    }
}
/* localdecomp:end func_L01_0033C4B8 */

INCLUDE_ASM("asm/levels", func_L01_0033C520);

LINKER_REMNANT("asm/levels", func_L01_0033CBB8);

INCLUDE_ASM("asm/levels", func_L01_0033CBC0);

/* localdecomp:start func_L01_0033D0E8 */
extern void func_L01_004AA7E8(u8 *, s32);
extern void func_L01_00303658(u8 *);

void func_L01_0033D0E8(u8 *p) {
    u8 *q;
    u8 *m;

    *(s32 *)(p + 152) = 0;
    q = *(u8 **)(p + 104);
    *(u16 *)(p + 52) = (*(u16 *)(p + 52) | 0x41) & ~0x1000;
    func_L01_004AA7E8(p, 1);
    p[32] = 6;
    q[248] = 1;
    q[249] = 255;
    m = *(u8 **)(q + 300);
    if (m != 0) {
        if (*(s16 *)(m + 170) == 806) {
            func_L01_00303658(m);
        }
        *(u8 **)(q + 300) = 0;
    }
}
/* localdecomp:end func_L01_0033D0E8 */

LINKER_REMNANT("asm/levels", func_L01_0033D170);

/* localdecomp:start func_L01_0033D178 */
s32 func_L01_0033D178(u8 *obj) {
    return (u32)(obj[32] - 6) < 2;
}
/* localdecomp:end func_L01_0033D178 */

/* localdecomp:start func_L01_0033D188 */

extern Fn_33CA98 *func_L01_0043B548(s32, s32);
extern void func_L01_00303658(u8 *);
extern void func_003C2880(u8 *);

void func_L01_0033D188(u8 *m, s32 flag) {
    u8 *v = *(u8 **)(m + 104);
    Fn_33CA98 *t;
    u8 *o;

    if (*(s32 *)(v + 176) != 0) {
        t = func_L01_0043B548(6625, 108);
        o = *(u8 **)(v + 300);
        if (o != 0) {
            if (flag == 0) {
                if (*(s16 *)(o + 170) == 806) {
                    func_L01_00303658(o);
                }
            } else if (*(s32 *)(v + 176) == -2) {
                *(u8 **)(o + 184) = o;
            }
        }
        *(u8 **)(v + 300) = 0;
        *(f32 *)(v + 224) = 1.0f;
        *(s32 *)(v + 208) = 0;
        *(s32 *)(v + 212) = 0;
        *(s32 *)(v + 220) = 0;
        *(s32 *)(v + 228) = 0;
        v[249] = 0;
        v[250] = 0;
        *(s32 *)(v + 288) = 0;
        *(s32 *)(v + 292) = 0;
        *(s32 *)(v + 304) = 0;
        t[0](m);
        if (flag != 0 && *(s32 *)(v + 176) != -2) {
            t[1](m);
        }
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L01_0033D188 */

/* localdecomp:start func_L01_0033D290 */
void func_L01_0033D290(void) {

}
/* localdecomp:end func_L01_0033D290 */

/* localdecomp:start func_L01_0033D298 */
extern void func_L01_0033D188_0033D298(u8 *m, s32 flag);
extern void func_L01_0033D298(void *p);
extern void func_L01_0033D298(void *);

 
void func_L01_0033D298(void *p) {
    ((void (*)(void *, s32))func_L01_0033D188_0033D298)(p, 0);
}
/* localdecomp:end func_L01_0033D298 */

/* localdecomp:start func_L01_0033D2B8 */
extern float D_L01_001DCFD8;
float func_00382538(void);
float func_0038DAB8(float, float);
void func_0038D750(void *, int, float);
void func_L01_0043A430(void *, int, void *);
void func_L01_0033D2B8(unsigned char *a) {
    unsigned char *s = *(unsigned char **)(a + 0x68);
    float f;
    switch (a[0x20]) {
    case 0:
        a[0x20] = 1;
        a[0x63] = 0x20;
        *(float *)(s + 0x40) = func_00382538();
        func_L01_0043A430(a, 1, s);
        break;
    case 1:
        f = D_L01_001DCFD8 * 0.01745329238474369f * 0.020000001415610313f;
        *(float *)(a + 0xF8) = func_0038DAB8(*(float *)(a + 0xF8), f);
        *(float *)(s + 0x40) = func_0038DAB8(*(float *)(s + 0x40), f * -2.0f);
        func_0038D750(s + 0x10, 2, *(float *)(s + 0x40));
        break;
    }
}
/* localdecomp:end func_L01_0033D2B8 */

/* localdecomp:start func_L01_0033D390 */
void func_L01_0033D390(void) {

}
/* localdecomp:end func_L01_0033D390 */

INCLUDE_ASM("asm/levels", func_L01_0033D398);

/* localdecomp:start func_L01_0033D780 */
extern f32 D_L01_001DD010;
__asm__(".extern D_L01_001DD010, 4");
extern u8 D_L01_001E18B0;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_L01_0033DED0(void *);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L01_0033D780(void *a0) {
    f32 t;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    s32 c0;
    s32 c1;
    s32 c2;
    D_L01_001DD010 = func_0038DAB8(D_L01_001DD010, 0.15f);
    t = func_0038D098(D_L01_001DD010);
    f20 = (t + 1.0f) * 0.5f;
    f23 = f20 * 0.0625f + 0.0625f;
    f22 = f20 * 0.19999999f + 0.15f;
    f21 = f20 * 0.125f + 0.125f;
    c0 = func_0038DBD8(f20, 0x2F007F00, 0x3F007F00);
    c1 = func_0038DBD8(f20, 0x2F7F7F7F, 0x5F7F7F7F);
    c2 = func_0038DBD8(f20, 0x10003F00, 0x10003F00);
    func_L01_0033DED0(a0);
    func_003D9508(&D_L01_001E18B0, 0x31, c0, 1, f21, 0.125f, 0.0f);
    func_003D9508(&D_L01_001E18B0, 0x31, c1, 1, f23, 0.124f, 0.0f);
    func_003D9508(&D_L01_001E18B0, 0xB, c2, 1, f22, 0.123f, 0.0f);
}
/* localdecomp:end func_L01_0033D780 */

INCLUDE_ASM("asm/levels", func_L01_0033D940);

INCLUDE_ASM("asm/levels", func_L01_0033DBE8);

INCLUDE_ASM("asm/levels", func_L01_0033DED0);
