#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern int func_003C4D58(unsigned char *);
extern void func_003C4C18(f32 *v, f32 r);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C4B40 */
s32 func_003C4B40(s32 arg0) {
    return (u32)(arg0 - 500) < 41;
}
/* localdecomp:end func_003C4B40 */

/* localdecomp:start func_003C4B50 */
extern s32 func_003C4B40_003C4B50(s16);
extern u32 D_001DA49C[];
extern u32 D_001DA4A4[];
s32 func_003C4B50(u32 arg0) {
    if (arg0 == 0) return 0;
    if (arg0 < D_001DA49C[0]) return 0;
    if (D_001DA4A4[0] >= arg0) {
        return func_003C4B40_003C4B50(*(s16 *)((u8 *)arg0 + 0xAA)) != 0;
    }
    return 0;
}
/* localdecomp:end func_003C4B50 */

LINKER_REMNANT("asm/remnants", func_003C4BA0);

/* localdecomp:start func_003C4BB0 */
extern f32 func_0038CEA8(s32 a);
extern void func_0038CF68(s32 a, s32 b, f32 x);
void func_003C4BB0(s32 a, f32 x) {
    if (x < func_0038CEA8(a)) func_0038CF68(a, a, x);
}
/* localdecomp:end func_003C4BB0 */

LINKER_REMNANT("asm/remnants", func_003C4C00);

/* localdecomp:start func_003C4C18 */
extern f32 func_003824E0(f32, f32);
void func_003C4C18(f32 *v, f32 r) {
    v[0] += func_003824E0(-r, r);
    v[1] += func_003824E0(-r, r);
    v[2] += func_003824E0(-r, r);
}
/* localdecomp:end func_003C4C18 */

LINKER_REMNANT("asm/remnants", func_003C4C98);

/* localdecomp:start func_003C4CE8 */
#include "vu0.h"
extern void func_0038CF68(s32 a, s32 b, f32 x);
void func_003C4CE8(void *a, f32 f) {
    f32 r;
    ((void (*)(void *, f32))func_0038CF68)(a, f);
    r = 1.0f - f * f;
    r = sqrt_asm(r);
    *(f32*)((u8*)a + 0xC) = r;
}
/* localdecomp:end func_003C4CE8 */

LINKER_REMNANT("asm/remnants", func_003C4D38);

/* localdecomp:start func_003C4D58 */
int func_003C4D58(unsigned char *object) {
    unsigned char *link;
    int flags;

    if (object != 0)
        goto check_flags;
failure:
    return 0;
check_flags:
    flags = *(unsigned short *)(object + 0x34) & 0x20;
    if (flags == 0)
        goto failure;
    link = *(unsigned char **)(object + 0x68);
    if (link == 0)
        goto failure;
    return *(int *)(link + 8);
}
/* localdecomp:end func_003C4D58 */

LINKER_REMNANT("asm/remnants", func_003C4D90);

/* localdecomp:start func_003C4DA8 */
typedef int u128_3BF838 __attribute__((mode(TI)));
typedef struct { u128_3BF838 r[4]; } M_3BF838;
extern void func_0038D328();
extern void func_0038D5B0();
extern void func_0038D640();
extern void func_003C48A8();
void func_003C4DA8(u8 *p, u128_3BF838 *a1, u128_3BF838 *a2, void *a3) {
    M_3BF838 m0, m1, m2, m3;
    func_0038D328(&m0, a2);
    func_0038D5B0(&m1, &m0);
    func_0038D328(&m2, a3);
    func_0038D640(&m3, &m1, &m2);
    func_003C48A8(&m3, p);
    if (*(s32 *)(p + 0x3C) & 2) {
        *(u128_3BF838 *)(p + 0x20) = *a2;
    }
    *(u128_3BF838 *)(p + 0x10) = *a1;
}
/* localdecomp:end func_003C4DA8 */

LINKER_REMNANT("asm/remnants", func_003C4E68);

extern s32 func_0038D058(f32 *);
/* localdecomp:start func_003C4E80 */
/* func_003C4E80 log: from the US draft; inline asm abs.s replaced by vu0.h fabs_asm */
#include "vu0.h"
extern s32 func_0038D058(f32 *);
void func_003C4E80(void *a, void *b) {
    f32 *v = (f32 *)a;
    f32 t[4];
    f32 x, y, z, ax, ay, az, m, s;
    s32 n;
    x = v[0];
    y = v[1];
    z = v[2];
    ax = fabs_asm(x);
    ay = fabs_asm(y);
    az = fabs_asm(z);
    if (ay < ax) ay = ax;
    m = ay;
    m = (az < m) ? m : az;
    n = (s32)(m * 10000.0f / 63.0f);
    if (n >= 256) n = 255;
    if (n <= 0) n = 1;
    t[3] = n;
    s = 1.0f / (t[3] * 0.0001f);
    t[0] = x * s + 127.0f;
    t[1] = y * s + 127.0f;
    t[2] = z * s + 127.0f;
    *(s32 *)b = func_0038D058(t);
}
/* localdecomp:end func_003C4E80 */

LINKER_REMNANT("asm/remnants", func_003C4F88);

/* localdecomp:start func_003C5060 */
typedef struct { u8 pad[0x40]; } M_3BFAF8;
void func_0038D5B0(M_3BFAF8 *, void *);
void func_0038D000(void *, void *, M_3BFAF8 *);
void func_003C5060(u8 *a, void *b, void *c, M_3BFAF8 *d) {
M_3BFAF8 m; if (d == 0) { func_0038D5B0(&m, a + 0xC0); func_0038D000(b, c, &m); } else { func_0038D000(b, c, d); }
}
/* localdecomp:end func_003C5060 */

LINKER_REMNANT("asm/remnants", func_003C50C8);

/* localdecomp:start func_003C50E8 */
f32 func_003C50E8(s32 a, s32 b, s32 c) {
    f32 v[4];
    func_003C5060(a, v, b, c);
    return v[2];
}
/* localdecomp:end func_003C50E8 */

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFBA8;
typedef int Q_3BFBA8 __attribute__((mode(TI)));
extern f32 D_001D5C00;
extern void func_0038CE20(f32 *, void *, f32);
/* localdecomp:start func_003C5110 */
/* the same code as boot_elf's func_003C54C8 */
void func_003C5110(void *a, f32 *out, s32 f) {
    Q_3BFBA8 p, q, r;
    __asm__("lqc2 %0, %1" : "=j"(p) : "m"(D_001D5C00));
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(V4_3BFBA8 *)a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(p), "j"(q));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_3BFBA8 *)out) : "j"(r));
    out[2] = 0;
    ((void (*)(void *, f32))func_0038CF68)(out, 1.0f);
    if (f == 0) {
        func_0038CE20(out, out, -1.0f);
    }
}
/* localdecomp:end func_003C5110 */
