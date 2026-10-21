#include "common.h"

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

INCLUDE_ASM("asm/levels", func_L01_0040C7A0);

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

INCLUDE_ASM("asm/levels", func_L01_0040CA60);

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
