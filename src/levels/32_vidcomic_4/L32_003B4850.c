#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L32_003B41E8.c, which this file was cut from */
extern void func_L32_003B4850(u8 *, u8 *);

/* localdecomp:start func_L32_003B4850 */
extern f32 D_L32_001DED9C;
__asm__(".extern D_L32_001DED9C, 4");
extern s32 D_L32_001DED1C;
__asm__(".extern D_L32_001DED1C, 4");
extern s32 D_L32_001DED20;
__asm__(".extern D_L32_001DED20, 4");
extern s32 D_L32_001DED50;
__asm__(".extern D_L32_001DED50, 4");
extern f32 D_L32_001DEDC0;
__asm__(".extern D_L32_001DEDC0, 4");
extern f32 D_L32_001DEDC4;
__asm__(".extern D_L32_001DEDC4, 4");
extern f32 D_L32_001DEDB4;
__asm__(".extern D_L32_001DEDB4, 4");
extern f32 D_L32_001DEDB0;
__asm__(".extern D_L32_001DEDB0, 4");
extern f32 D_L32_001DEDAC;
__asm__(".extern D_L32_001DEDAC, 4");
extern f32 D_L32_001DEDA8;
__asm__(".extern D_L32_001DEDA8, 4");
extern f32 D_L32_001DEDA4;
__asm__(".extern D_L32_001DEDA4, 4");
extern f32 D_L32_001DEDA0;
__asm__(".extern D_L32_001DEDA0, 4");
extern void func_L30_0034C958(vu0_v4 *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_0038DB48(f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L02_003BA9F8(void *, void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);

typedef struct {
    u8 *moby;
    s32 tex;
    s16 life;
    u16 flags;
    s16 pad_c;
    u16 color;
    f32 vx;
    f32 vz;
    f32 size0;
    f32 size1;
} P_003B4850;

typedef struct {
    s32 pad_0;
    u32 rgba;
    u8 alpha;
    u8 pad_9;
    s16 age;
    f32 size;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} S_003B4850;

void func_L32_003B4850(u8 *a0, u8 *a1) {
    S_003B4850 *s = (S_003B4850 *)a0;
    P_003B4850 *p = (P_003B4850 *)a1;
    u8 *moby;
    u8 *vars;
    s32 x;
    s32 tex;
    f32 ang;
    f32 rad;
    f32 t;
    f32 a;
    u16 c;
    vu0_v4 dir;
    vu0_v4 v;
    vu0_v4 r0;
    vu0_v4 r1;

    if (p == 0)
        return;
    moby = p->moby;
    vars = *(u8 **)(moby + 0x68);
    x = p->tex;
    if (p->flags & 1) {
        if (moby == 0 || vars == 0 || x == 0)
            return;
        *(u128_t *)&s->x = *(u128_t *)(moby + 0x10);
        func_L30_0034C958((vu0_v4 *)&s->x, D_L32_001DED9C);
        tex = *(s32 *)(vars + 0x40) ? D_L32_001DED1C : D_L32_001DED20;
        s->rgba = func_0038DBD8(D_L32_001DED50, tex, func_003824E0(0.0f, 1.0f));
        ang = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        rad = func_003824E0(D_L32_001DEDC4, D_L32_001DEDC0);
        func_0038CF68(&dir, vars + 0x20, 1.0f);
        v.x = func_0038D098(ang) * rad;
        v.z = func_0038D0B0(ang) * rad;
        v.y = 0.0f;
        func_L02_003BA9F8(&v, &dir, &r0, &r1);
        func_0038CE20(&r0, &r0, 1.0f - D_L32_001DEDB4);
        func_0038CE20(&r1, &r1, D_L32_001DEDB4 + 1.0f);
        vec_add_ab(&v, &r0, &r1);
        p->vx = v.x;
        p->vz = v.z;
        p->size0 = func_003824E0(D_L32_001DEDB0, D_L32_001DEDAC);
        p->size1 = func_003824E0(D_L32_001DEDA8, D_L32_001DEDA4);
    }
    t = func_L03_0034B440(1, 0, 0, (f32)s->age, (f32)p->life, 1.0f);
    a = (1.0f - t) * 128.0f;
    s->x += p->vx;
    s->z += p->vz;
    s->rgba = (s->rgba & 0xFFFFFF) | ((s32)a << 24);
    s->size = func_003C4088(p->size0, p->size1, t);
    c = p->color;
    s->alpha = func_003C4088((f32)(c & 0xFF), (f32)(c & 0xFF) + D_L32_001DEDA0 * (f32)p->life * (f32)(c >> 8) * 0.00390625f, t);
}
/* localdecomp:end func_L32_003B4850 */
