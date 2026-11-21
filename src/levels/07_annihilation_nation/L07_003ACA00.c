#include "common.h"

/* declared by functions of L07_003A9DB0.c, which this file was cut from */
void func_L07_00334740(void *);
void func_L07_00334800();
extern void func_003C2F58(u8 *a, s32 b, f32 *out);

/* localdecomp:start func_L07_003ACA00 */
void func_L07_00334740(void *);
void func_L07_003ACA90(void *, s32);

void func_L07_003ACA00(u8 *obj) {
    u8 *d = *(u8 **)(obj + 0x68);

    *(s32 *)(d + 0x56C) = 0;
    *(s32 *)(d + 0x188) &= ~0x10;
    func_L07_00334740(obj);
    func_L07_003ACA90(obj, 1);
}
/* localdecomp:end func_L07_003ACA00 */

/* localdecomp:start func_L07_003ACA48 */
void func_L07_00334800();
void func_L07_003ACA90(void *, s32);

void func_L07_003ACA48(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x2C) = (f32) ((*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x24))) + 0x24)) * 0.75f);
    func_L07_00334800();
    func_L07_003ACA90(arg0, 2);
}
/* localdecomp:end func_L07_003ACA48 */

INCLUDE_ASM("asm/levels", func_L07_003ACA90);

INCLUDE_ASM("asm/levels", func_L07_003ACD58);

/* localdecomp:start func_L07_003ACF40 */
typedef struct {
    u8 pad_0[0x25C0];
    void *moby;         /* 0x25C0 */
} S_003ACF40_HERO;

extern S_003ACF40_HERO D_001A4BE0;
extern void *D_001ECC80[];

extern void func_003C2F58(u8 *a, s32 b, f32 *out);
extern s32 func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);

void func_L07_003ACF40(u8 *arg0) {
    u8 *s = *(u8 **)(arg0 + 0x68);
    f32 v[3];
    s32 i;
    s32 j;
    s32 n;

    for (i = 0; i < 2; i++) {
        if ((s[0x567] >> i) & 1) {
            func_003C2F58(arg0, i, v);
            n = func_L01_00446780(arg0, v, 0x10001, 0, 1, 0, 0.5625f, (f32)s[0x44], 1.0f);
            for (j = 0; j < n; j++) {
                if (D_001ECC80[j] == D_001A4BE0.moby) {
                    s[0x566] = 1;
                    break;
                }
            }
        }
    }
}
/* localdecomp:end func_L07_003ACF40 */

/* localdecomp:start func_L07_003AD058 */
void func_L07_003AD058(void *arg0) {
    s32 var_v1;
    void *var_v0;

    var_v1 = 1;
    var_v0 = (*(s32 *)((u8 *)arg0 + 0x68)) + 0x560;
    do {
        *(s8 *)((u8 *)var_v0 + 2) = 0;
        var_v1 -= 1;
        (*(s8 *)var_v0) = 0;
        var_v0 += 1;
    } while (var_v1 >= 0);
}
/* localdecomp:end func_L07_003AD058 */

/* localdecomp:start func_L07_003AD088 */
extern void func_003C2F58(u8 *a, s32 b, f32 *out);

void func_L07_003AD088(void *arg0) {
    u8 *s = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *p = s + 0x562;
    u8 *q = s + 0x560;
    s32 ten = 10;
    s32 i;

    for (i = 0; i < 2; i++) {
        if ((s[0x567] >> i) & 1) {
            u8 *t = q + i;
            u8 *r = s + 0x562;
            if (++p[i - 2] > 10) {
                p[i - 2] = ten;
                p[i] = (p[i] + 1) % ten;
            }
            func_003C2F58(arg0, i, (f32 *)(s + 0x420 + i * 0xA0 + ((r[i] + *t - 1) % ten) * 16));
        }
    }
}
/* localdecomp:end func_L07_003AD088 */

/* localdecomp:start func_L07_003AD180 */
void func_L07_003AD210(void *, void *, s32, s32, s32);

void func_L07_003AD180(void *arg0) {
    u8 *s2 = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *p = s2 + 0x562;
    s32 i;

    for (i = 0; i < 2; i++) {
        if ((s2[0x567] >> i) & 1) {
            func_L07_003AD210(arg0, s2 + 0x420 + i * 0xA0, p[-2], p[0], s2[0x568] + 0x64);
        }
        p++;
    }
}
/* localdecomp:end func_L07_003AD180 */

INCLUDE_ASM("asm/levels", func_L07_003AD210);
