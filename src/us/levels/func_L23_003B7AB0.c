#include "common.h"

/* NTSC-U counterpart of func_L23_003B94C8 (src/levels/23_holostar_studios_clank/L23_003B94C8.c) */
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
typedef struct {
    u8 pad0[0x38];
    long x38;
    u8 pad40[0x24];
    void (*update)(void);
} Spawn_3B94C8;

/* localdecomp:start func_L23_003B7AB0 */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern u16 **D_L23_001D6764_003B7AB0;
__asm__(".extern D_L23_001D6764_003B7AB0, 16");
extern E_3B9940 *D_L23_001E009C;
__asm__(".extern D_L23_001E009C, 16");
extern u8 *D_L23_001E0094_3B9940;
__asm__(".extern D_L23_001E0094_3B9940, 4");
extern u8 *D_L23_001E0094;
__asm__(".extern D_L23_001E0094, 16");
extern s16 D_L23_0023A440[];
extern s32 D_L23_001DECC0;
extern s32 D_L23_001DE570;
__asm__(".extern D_L23_001DE570, 4");
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00402498(void *, void *);
extern void func_L23_003B80A8();
extern void func_L01_004367A0(void *, u16 *, s32 *);
extern f32 func_00388A28(f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern Spawn_3B94C8 *func_L01_003F5830(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern void func_L01_002FFEA8(void);
extern void func_L01_0044B598(void *, s32);
extern void func_003BD360(void *);

void func_L23_003B7AB0(Moby_3BA3E8 *self)
{
    Vars_3BA3E8 *v = self->vars;
    u8 *t;
    f32 ang;
    V4 d;
    u16 id;
    s32 count;
    Spawn_3B94C8 *s;

    if (*(u8 *)((u8 *)self + 0x20) == 1) {
        u16 *p;
        E_3B9940 *m;
        u8 *e;

        t = (u8 *)func_L01_00444358(self, -1, 0);
        if (t != 0 && *(f32 *)(t + 0x2C) > 9.0f) {
            func_L01_00441FB8(self, 2, -1);
        }
        p = D_L23_001D6764_003B7AB0[v->id];
        while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764_003B7AB0[v->id])) {
            m = D_L23_001E009C + (*p & 0x7FFF);
            if (m == 0)
                break;
            e = D_L23_001E0094_3B9940 + ((*p & 0x7FFF) << 5);
            if (D_L23_0023A440[e[0x1D]] == 0x1D51) {
                if (fabs_asm(((V4 *)&m->pos)->z - ((V4 *)&self->pos)->z) > 0.01f) {
                    func_L01_00441FB8(self, 2, -1);
                }
                if (((D_L23_001DECC0 >> 3) & 3) == 0) {
                    func_L01_00402498(func_L23_003B80A8, self);
                    e[0x1E] |= 2;
                } else {
                    e[0x1E] &= ~2;
                }
            }
            p++;
        }
    }
    if (*(u8 *)((u8 *)self + 0x20) == 2) {
        u16 *p;
        u8 *e;

        func_L01_004367A0(self, &id, &count);
        while (count > 0) {
            count--;
            ang = func_00388A28(((V4 *)&self->pos)->x - D_001A4BE0.pos.x, ((V4 *)&self->pos)->y - D_001A4BE0.pos.y);
            func_00389380(ang, func_0037E250(-0.5235988f, 0.5235988f));
            d.x = func_00388960(ang) * func_0037E250(0.25f, 0.4166667f);
            d.y = func_00388978(ang) * func_0037E250(0.25f, 0.4166667f);
            d.z = 0.0f;
            d.w = 1.0f;
            s = func_L01_003F5830(self, 2, *(s16 *)((u8 *)self + 0xAA), count, &self->pos, (u8 *)self + 0xF0, &d, 0xFF, 30.0f, 15.0f, 0xB4, 0, 0x80);
            s->update = func_L01_002FFEA8;
            func_L01_0044B598(s, D_L23_001DE570);
            s->x38 = *(long *)((u8 *)D_001A4BE0.hero_moby + 0x38);
        }
        p = D_L23_001D6764_003B7AB0[v->id];
        while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764_003B7AB0[v->id])) {
            e = D_L23_001E0094 + ((*p & 0x7FFF) << 5);
            if (e == 0)
                break;
            if (D_L23_0023A440[e[0x1D]] == 0x1D51) {
                e[0x1E] |= 4;
                break;
            }
            p++;
        }
        func_003BD360(self);
    }
}
/* localdecomp:end func_L23_003B7AB0 */
