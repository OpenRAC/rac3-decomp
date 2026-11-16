#include "common.h"

/* NTSC-U counterpart of func_L23_003BB150 (src/levels/23_holostar_studios_clank/L23_003B94C8.c) */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { u8 pad0[0x20]; u8 a20[0x10]; u128_t pos; } E_3B9940;
typedef struct {
    s32 id;
    f32 x4;
    s32 x8;
    f32 xC;
    u8 pad10[0x10];
    u8 x20[0x10];
} Vars_3BA3E8;
typedef struct {
    u8 pad0[0x10];
    u128_t pos;
    u8 pad20[0xC];
    f32 scale;
    u8 pad30[4];
    u16 x34;
    u8 pad36[0x32];
    Vars_3BA3E8 *vars;
    u8 pad6C[0x54];
    V4 m[3];
} Moby_3BA3E8;
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern u16 **D_L23_001D6764_003B9678;
extern E_3B9940 *D_L23_001E009C;
extern u8 *D_L23_001E0094_3B9940;
extern u8 *D_L23_001E0094;
extern s16 D_L23_0023A440[];
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00402498(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_003BD360(void *);
extern u16 **D_L23_001D6764_003B9678;
extern E_3B9940 *D_L23_001E009C;
extern u8 *D_L23_001E0094_3B9940;
extern s16 D_L23_0023A440[];
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern u16 **D_L23_001D6764_003B9678;
extern u8 *D_L23_001E0094;
extern s16 D_L23_0023A440[];
extern u16 **D_L23_001D6764_003B9678;
extern u8 *D_L23_001E0094;
extern s16 D_L23_0023A440[];

/* localdecomp:start func_L23_003B9678 */
/* MATCH (file flags as is: L23_003B94C8.c) */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern u16 **D_L23_001D6764_003B9678;
__asm__(".extern D_L23_001D6764_003B9678, 16");
extern E_3B9940 *D_L23_001E009C;
__asm__(".extern D_L23_001E009C, 16");
extern u8 *D_L23_001E0094_3B9940;
__asm__(".extern D_L23_001E0094_3B9940, 4");
extern u8 *D_L23_001E0094;
__asm__(".extern D_L23_001E0094, 16");
extern s16 D_L23_0023A440[];
extern V4 D_L23_001DE5A0[2] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE5A0, 4");
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00402498(void *, void *);
extern void func_L23_003B9C20(u8 *m);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_0044ED60(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                          f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                          s32 h, s32 k);
extern void func_003888C8(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_003BD360(void *);

void func_L23_003B9678(Moby_3BA3E8 *self)
{
    Vars_3BA3E8 *v = self->vars;
    u8 *t;
    u16 *p;
    u16 *p2;
    E_3B9940 *m;
    u8 *e;
    f32 ang;
    V4 d;
    V4 r;
    V4 o;
    s32 i;

    if (*(u8 *)((u8 *)self + 0x20) == 1) {
        t = (u8 *)func_L01_00444358(self, -1, 0);
        if (t != 0 && *(f32 *)(t + 0x2C) > 9.0f) {
            func_L01_00441FB8(self, 2, -1);
        }
        p = D_L23_001D6764_003B9678[v->id];
        while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764_003B9678[v->id])) {
            m = D_L23_001E009C + (*p & 0x7FFF);
            if (m == 0)
                break;
            if (D_L23_0023A440[(D_L23_001E0094_3B9940 + ((*p & 0x7FFF) << 5))[0x1D]] == 0x1CF8 &&
                fabs_asm(((V4 *)&m->pos)->z - ((V4 *)&self->pos)->z) > 0.01f) {
                func_L01_00441FB8(self, 2, -1);
            }
            p++;
        }
        func_L01_00402498(func_L23_003B9C20, self);
    }
    if (*(u8 *)((u8 *)self + 0x20) == 2) {
        ang = func_00388A28(((V4 *)&self->pos)->x - D_001A4BE0.pos.x, ((V4 *)&self->pos)->y - D_001A4BE0.pos.y);
        d.x = func_00388960(ang) * 0.25f;
        d.y = func_00388978(ang) * 0.25f;
        d.z = 0.0f;
        d.w = 1.0f;
        func_L01_0044ED60(self, 0xFF, &d, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        p2 = D_L23_001D6764_003B9678[v->id];
        while (p2 != 0 && ((s16)p2[-1] >= 0 || p2 == D_L23_001D6764_003B9678[v->id])) {
            e = D_L23_001E0094 + ((*p2 & 0x7FFF) << 5);
            if (e == 0)
                break;
            if (D_L23_0023A440[e[0x1D]] == 0x1CF8) {
                e[0x1E] |= 4;
                break;
            }
            p2++;
        }
        for (i = 0; i < 2; i++) {
            qzero(&r);
            func_003888C8(&o, &D_L23_001DE5A0[i], self->m);
            func_003886E8(&o, &o, v->x4);
            func_L02_003E0520(self, &o, 5.0f, &r, 0x28, 0, 0, 0.3333333432674408f, 2.0f, 10.0f, 1.0f);
        }
        func_0039FE80(0, 0, self);
        func_003BD360(self);
    }
}
/* localdecomp:end func_L23_003B9678 */
