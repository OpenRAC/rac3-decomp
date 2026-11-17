#include "common.h"

/* declared by functions of L30_0034EDE0.c, which this file was cut from */
typedef struct { u8 pad[0x10]; u8 x10[0x9A]; s16 xAA; } M_34EDE0;
typedef struct { u8 pad[0x10]; u8 x10[0x10]; } O_34EDE0;

/* localdecomp:start func_L30_0034EFB8 */
#include "vu0.h"

typedef struct {
    vu0_v4 v;
    u8 *o;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 i20;
} S_0034EFB8;
typedef struct {
    u8 pad[0x18];
    u8 *x18;
} G_0034EFB8;
typedef struct {
    f32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    u8 pad14[8];
    f32 x1C;
} V_0034EFB8;
__asm__(".extern D_L30_001DD5EC, 4");
__asm__(".extern D_L30_001DD5F8, 4");
__asm__(".extern D_L30_001DD5FC, 4");
__asm__(".extern D_L30_001DD604, 4");
__asm__(".extern D_L30_001DD610, 4");
extern s32 D_L30_001DD5EC;
extern f32 D_L30_001DD5F8;
extern f32 D_L30_001DD5FC;
extern f32 D_L30_001DD604;
extern f32 D_L30_001DD610;
typedef struct {
    u8 pad[0x25C0];
    u8 *p25C0;
} H_0034EFB8;
extern H_0034EFB8 D_001A4BE0;
extern G_0034EFB8 D_L30_001E9000;
extern vu0_v4 D_L30_001E9020_0034EFB8;
extern void func_L30_0034CC28(void *, u8 *, void *, s32, s32, f32);
extern void func_L30_0034F2D8(u8 *, M_34EDE0 *);
extern f32 func_0038DB00(f32, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern s32 func_L30_003445B8(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);

void func_L30_0034EFB8(u8 *a0) {
    S_0034EFB8 st;
    vu0_v4 d;
    vu0_v4 a;
    vu0_v4 b;
    V_0034EFB8 *s = *(V_0034EFB8 **)(a0 + 0x68);
    M_34EDE0 *m;
    u8 *g;

    func_L30_0034CC28(&st, D_001A4BE0.p25C0, s, 0, 0, (f32)D_L30_001DD5EC);
    if (s->x10 <= 0) {
        m = func_L30_0034EDE0((O_34EDE0 *)a0);
        if (m != 0) {
            func_L30_0034F2D8(a0, m);
        }
    }
    vec_add_ab(a0 + 0x10, a0 + 0x10, s);
    s->x1C = func_0038DB00(s->x1C, s->x0 / D_L30_001DD610);
    if (func_L01_003FB640(a0 + 0x10, 0, D_001A4BE0.p25C0, D_L30_001DD610) != 0) {
        g = D_L30_001E9000.x18;
        if (g != 0 && func_L30_003445B8(g) == 0 && *(s16 *)(D_L30_001E9000.x18 + 0xAA) != 0x1B1C) {
            func_L01_004450F0(a0, 1, -1);
            return;
        }
        s->x10++;
        func_003A52A0(0, 0, a0);
        vec_sub_ba(&d, &D_L30_001E9020_0034EFB8, a0 + 0x10);
        func_0038CF68(&d, &d, 1.0f);
        if (func_0038CE68(s, &d) > 0.0f) {
            func_L02_003BA9F8(s, &d, &a, &b);
            func_0038CE20(&a, &a, -D_L30_001DD5FC);
            func_0038CE20(&b, &b, D_L30_001DD604);
            vec_add_ab(s, &a, &b);
        }
    } else {
        s->x8 -= D_L30_001DD5F8;
    }
}
/* localdecomp:end func_L30_0034EFB8 */
