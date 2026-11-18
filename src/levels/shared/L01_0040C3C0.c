#include "common.h"
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} V40A3D0;
typedef struct {
    u8 pad0[48];
    V40A3D0 out;
    V40A3D0 pad40;
    V40A3D0 ang;
    V40A3D0 pad60;
    V40A3D0 tgt;
    V40A3D0 pad80;
    V40A3D0 scale;
} S40A3D0;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    s32 n;
    f32 f4;
    u8 pad8[16];
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    u8 data[1];
} P_0040A478;

INCLUDE_ASM("asm/levels", func_L01_0040C3C0);

/* localdecomp:start func_L01_0040C7A0 */
/* m2c3 */
s32 func_L01_00443B88(s32, f32, f32);               /* extern */

void func_L01_0040C7A0(s32 arg0, void *arg1) {
    func_L01_00443B88(arg0 + 0x50, -3.1415927f, 3.1415927f);
    func_L01_00443B88(arg0 + 0x60, -3.1415927f, 3.1415927f);
    func_L01_00443B88(arg0 + 0x70, (*(f32 *)((u8 *)(arg1) + 8)) * 0.017453292f * 0.020000001f, (*(f32 *)((u8 *)(arg1) + 0xC)) * 0.017453292f * 0.020000001f);
    func_L01_00443B88(arg0 + 0x80, (*(f32 *)((u8 *)(arg1) + 8)) * 0.017453292f * 0.020000001f, (*(f32 *)((u8 *)(arg1) + 0xC)) * 0.017453292f * 0.020000001f);
    func_L01_00443B88(arg0 + 0x90, (*(f32 *)((u8 *)(arg1) + 0x10)), (*(f32 *)((u8 *)(arg1) + 0x14)));
    func_L01_00443B88(arg0 + 0xA0, (*(f32 *)((u8 *)(arg1) + 0x10)), (*(f32 *)((u8 *)(arg1) + 0x14)));
}
/* localdecomp:end func_L01_0040C7A0 */

/* localdecomp:start func_L01_0040C8A0 */


extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L01_0040C8A0(S40A3D0 *s) {
    s32 i;

    for (i = 1; i >= 0; i--) {
        s->ang.x = func_0038DAB8(s->ang.x, s->tgt.x);
        s->ang.y = func_0038DAB8(s->ang.y, s->tgt.y);
        s->ang.z = func_0038DAB8(s->ang.z, s->tgt.z);
        s->out.x = func_0038D098(s->ang.x) * s->scale.x;
        s->out.y = func_0038D0B0(s->ang.y) * s->scale.y;
        s->out.z = -func_0038D0B0(s->ang.z) * s->scale.z;
        s = (S40A3D0 *)((u8 *)s + 16);
    }
}
/* localdecomp:end func_L01_0040C8A0 */

/* localdecomp:start func_L01_0040C948 */


extern void func_L01_0040CA60(void *, s32, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0040CC30(void *, s32, s32 *, s32 *, void *, f32, f32, f32);

void func_L01_0040C948(s32 *a0, P_0040A478 *a1)
{
    s128 buf[a1->n];
    s32 a[4];
    s32 b[4];
    f32 f20;
    f32 f22;
    f32 f21;

    func_L01_0040CA60(buf, a1->n, a0, a1->f18);
    f20 = func_003824E0(a1->f2C, a1->f30);
    f22 = func_003824E0(a1->f1C, a1->f20);
    f21 = func_003824E0(a1->f24, a1->f28);
    a[0] = func_0038DBD8(0, a0[8], f20);
    a[1] = func_0038DBD8(0, a0[9], f20);
    b[0] = func_0038DBD8(0, a0[10], f20);
    b[1] = func_0038DBD8(0, a0[11], f20);
    func_L01_0040CC30(buf, a1->n, a, b, a1->data, f22, f21, a1->f4);
}
/* localdecomp:end func_L01_0040C948 */

/* localdecomp:start func_L01_0040CA60 */
typedef int u128_40CA60 __attribute__((mode(TI)));
typedef union {
    u128_40CA60 q;
    f32 f[4];
} Vec4_40CA60;
extern void func_L01_0040D220(Vec4_40CA60 *, Vec4_40CA60 *, Vec4_40CA60 *, Vec4_40CA60 *, Vec4_40CA60 *, f32);
extern void func_0038CF68(Vec4_40CA60 *, Vec4_40CA60 *, f32);

void func_L01_0040CA60(void *a0, s32 n, void *a2, f32 s) {
    Vec4_40CA60 *buf = a0;
    Vec4_40CA60 *p = a2;
    Vec4_40CA60 t0, t1, tmp;
    f32 inv;
    s32 i;
    t0 = p[3];
    vec_add_ba(&t0, &t0, &p[0]);
    t1 = p[4];
    vec_add_ba(&t1, &t1, &p[1]);
    inv = 1.0f / (f32)(n - 2);
    for (i = 0; i < n - 1; i++) {
        func_L01_0040D220(&buf[i], &p[0], &p[1], &t0, &t1, (f32)i * inv);
        if (i > 0 && i < n - 2) {
            tmp.f[3] = 0.0f;
            tmp.f[0] = func_003824E0(-1.0f, 1.0f);
            tmp.f[1] = func_003824E0(-1.0f, 1.0f);
            tmp.f[2] = func_003824E0(-1.0f, 1.0f);
            func_0038CF68(&tmp, &tmp, s);
            vec_add_ba(&buf[i], &buf[i], &tmp);
        }
    }
    vec_sub_ab(&tmp, &buf[n - 2], &buf[n - 3]);
    vec_add_ab(&buf[n - 1], &buf[n - 2], &tmp);
}
/* localdecomp:end func_L01_0040CA60 */

INCLUDE_ASM("asm/levels", func_L01_0040CC30);

/* localdecomp:start func_L01_0040D198 */
void func_L01_0040D198(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0040D198 */

INCLUDE_ASM("asm/levels", func_L01_0040D220);
