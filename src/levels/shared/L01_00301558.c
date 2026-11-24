#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

/* declared by functions of L01_003002A8.c, which this file was cut from */
extern u8 *func_003C24B0(s32, s32);
extern f32 func_00382538(void);
extern void func_003C7C38(u8 *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_003C2880(u8 *);

/* localdecomp:start func_L01_00301558 */

extern s32 D_L01_001D673C_00301558;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0044A7D0(u8 *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern f32 func_00382538(void);
extern void func_003C5180(u8 *, Vec4 *, s32);
extern void func_L01_004515D8(u8 *, Vec4 *, Vec4 *);
extern void func_003C48A8(u8 *, u8 *);
extern void func_003C7C38(u8 *);

u8 *func_L01_00301558(Vec4 *pos, Vec4 *dir, u8 type, f32 scale, f32 f13) {
    Vec4 v;
    Vec4 mt[3];
    u8 *m;
    u8 *pv;

    m = func_003C24B0(775, 128);
    if (m != 0) {
        pv = *(u8 **)(m + 104);
        func_L01_0044A7D0(m);
        func_L01_0043B9E8(m, 40, 40, 70);
        m[48] = 255;
        *(s16 *)(m + 50) = 64;
        *(f32 *)(m + 44) *= scale;
        *(f32 *)pv = f13;
        pv[4] = type;
        *(u128_t *)(m + 16) = pos->q;
        *(f32 *)(m + 248) = func_00382538();
        if (dir->f[0] != 0.0f && dir->f[1] != 0.0f && dir->f[2] != 0.0f) {
            *(u128_t *)(m + 240) = dir->q;
        } else if (D_L01_001D673C_00301558 != 0) {
            func_003C5180(m + 16, &v, 0);
            func_L01_004515D8(m + 192, &v, mt);
            func_003C48A8(m + 192, m + 240);
        }
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L01_00301558 */

/* localdecomp:start func_L01_003016B0 */
extern u8 *func_L01_00301558(Vec4 *pos, Vec4 *dir, u8 type, f32 scale, f32 f13);
extern u8 D_L01_001D66B0[];

void func_L01_003016B0(s32 a0, u8 a1) {
    ((void (*)(s32 a0, u8 *a1, u8 a2))func_L01_00301558)(a0, D_L01_001D66B0, a1);
}
/* localdecomp:end func_L01_003016B0 */

/* localdecomp:start func_L01_003016D8 */
extern s32 D_L01_001D673C[];
extern void func_003C2880(u8 *);

void func_L01_003016D8(u8 *obj) {
    s32 d;
    u8 *a;
    u8 *p;
    Vec4 v;
    Vec4 mt[3];
    f32 f;
    s32 c;

    d = D_L01_001D673C[0];
    a = *(u8 **)(obj + 0x68);
    f = *(f32 *)(obj + 0x2C) * *(f32 *)a;
    *(f32 *)(obj + 0x2C) = f;
    if (d != 0) {
        p = obj + 0xC0;
        func_003C5180(obj + 0x10, &v, 0);
        func_L01_004515D8(p, &v, &mt[0]);
        func_003C48A8(p, obj + 0xF0);
    }
    c = obj[0x23] - a[4];
    obj[0x23] = c;
    if (!(a[4] < (u8)c)) {
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L01_003016D8 */

/* localdecomp:start func_L01_00301788 */
s32 func_L01_00301788(u8 *obj) {
    return obj[32] == 1;
}
/* localdecomp:end func_L01_00301788 */
