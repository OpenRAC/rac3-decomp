#include "common.h"

/* declared by functions of L33_003BD2E8.c, which this file was cut from */
extern void func_L33_003BD978(u8 *);
extern void func_L33_003BDA58(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L01_004561B8(void);
extern s32 func_0038CAD0(u8 *);

/* localdecomp:start func_L33_003BD978 */
__asm__(".extern D_L33_001DF16C, 4");
__asm__(".extern D_L33_001DF170, 4");
__asm__(".extern D_L33_001DF15C, 4");
typedef struct {
    u8 p0[0x10];
    f32 x, y, z;
    u8 p1c[0x23 - 0x1C];
    u8 alpha;
    u8 *cls;
    u8 p28[4];
    f32 scale;
    u8 p30[4];
    u16 flags;
    u8 p36[0x48 - 0x36];
    s32 f48;
    u8 p4c[0x68 - 0x4C];
    s32 *v;
} M_003BD978;
extern f32 D_L33_001DF16C;
extern f32 D_L33_001DF170;
extern f32 D_L33_001DF15C;
extern s32 func_L01_004561B8(void);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038CAD0(u8 *);
extern void func_003C2880(void *);

void func_L33_003BD978(u8 *a0) {
    M_003BD978 *m = (M_003BD978 *)a0;
    s32 *v = m->v;
    f32 t, r;
    if (((s32 (*)(u8 *))func_L01_004561B8)(a0)) {
        m->f48 = 0;
        m->flags |= 8;
    }
    t = 1.0f;
    r = func_L03_0034B440(1, 0, 0, (f32)v[5], (f32)v[4], t);
    m->alpha = (s32)((t - r) * 128.0f);
    m->scale = func_003C4088(D_L33_001DF16C, D_L33_001DF170, r) * *(f32 *)(m->cls + 0x24);
    m->y += D_L33_001DF15C;
    if (func_0038CAD0((u8 *)(v + 5))) {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L33_003BD978 */

/* localdecomp:start func_L33_003BDA58 */
__asm__(".extern D_L33_001DF180, 4");
__asm__(".extern D_L33_001DF164_3BDA58, 4");
__asm__(".extern D_L33_001DF168, 4");
__asm__(".extern D_L33_001DF158, 4");
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003BDA58;
extern s32 D_L33_001DF6C0;
extern s32 D_L33_001DF180;
extern s32 D_L33_001DF164_3BDA58;
extern f32 D_L33_001DF168;
extern f32 D_L33_001DF158;
extern u8 D_001A4BE0[];
extern u8 *func_L33_003BD6C8(u8 *);
extern void func_L30_0034CF28(void *, void *, s32, f32, f32);
extern f32 func_L30_0034CE78(void *);
extern f32 func_0038CF00(void *, void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L30_004CF4B0(s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L33_003BDA58(u8 *a0) {
    s32 *v;
    V_003BDA58 pos;
    V_003BDA58 *hp;
    u8 *h;
    s32 r;
    r = D_L33_001DF6C0 % D_L33_001DF180;
    v = *(s32 **)(a0 + 0x68);
    *(s32 *)(a0 + 0x48) = 0;
    if (r == 0) {
        ((void (*)(void))func_L33_003BD6C8)();
    }
    func_L30_0034CF28(a0 + 0x10, v + 2, D_L33_001DF164_3BDA58, D_L33_001DF168, 0.0f);
    hp = (V_003BDA58 *)(D_001A4BE0 + 0x80);
    h = D_001A4BE0;
    pos = *hp;
    pos.z += func_L30_0034CE78(*(void **)(h + 0x25C0));
    if ((func_0038CF00(&pos, a0 + 0x10) < D_L33_001DF158 && *(s32 *)(h + 0x360) != 0)
        || (v[0] != -1 && func_00382380(hp, v[0], 0))) {
        func_L30_004CF4B0(0x74, 1);
        {
            u8 *g = D_001A4BE0;
            *(s16 *)(g + 0x1DC) = 0;
            *(u16 *)(*(u8 **)(g + 0x25C0) + 0x34) |= 8;
        }
        func_L01_004450F0(a0, 2, -1);
    }
}
/* localdecomp:end func_L33_003BDA58 */
