#include "common.h"

/* localdecomp:start func_L39_00574F20 */
#include "vu0.h"

typedef struct {
    u32 x : 10;
    u32 y : 10;
    u32 z : 10;
} Dims_00574F20;

typedef struct {
    Dims_00574F20 d;
    u8 *data;
    u8 pad8[8];
} Grid_00574F20;

typedef struct {
    u8 pad0[0x18];
    u8 f18;
    u8 pad19[7];
} Ent_00574F20;

extern u8 D_L39_0024DE00[];
extern Ent_00574F20 *D_L39_0024BB6C_00574F20;
extern Grid_00574F20 *D_L39_0024BC8C;
extern u8 D_001FE020[];
extern vu0_v4 D_L39_0024B7B0 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B7B0, 4");
extern f32 D_L39_0024B7A0;
__asm__(".extern D_L39_0024B7A0, 4");
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L39_005F35D8(s32, s32, void *, s32);
extern s32 func_L39_005F3760(u32, s32);
extern f32 func_L01_003EFA80(f32, f32, f32);
extern f32 func_L01_003EFAA0(f32 *, f32, f32);

void func_L39_00574F20(u8 *self) {
    vu0_v4 d;
    vu0_v4 r;
    f32 s[4];
    vu0_v4 t;
    s32 *sub;
    Grid_00574F20 *g;
    s32 flags;
    u8 *slot;
    s32 x, y, z;
    s32 x1, y1, z1;
    f32 fx, fy, fz;
    f32 a, b;
    s32 v;

    sub = *(s32 **)(self + 8);
    vec_sub_ab(&d, D_L39_0024DE00, self + 0x40);
    d.w = 0.0f;
    func_0038D000(&r, &d, self + 0x50);
    flags = 0x19;
    if (fabs_asm(r.x) <= 1.0f && fabs_asm(r.y) <= 1.0f && fabs_asm(r.z) <= 1.0f) {
        if (D_L39_0024BB6C_00574F20[sub[1]].f18) flags = 0x1D;
        slot = D_001FE020 + (sub[5] << 7);
        if (*(u8 **)(slot + 0x100) != self || slot[0xD0] == 0) {
            sub[5] = func_L39_005F35D8(sub[1], flags, self, 0x400);
        }
        g = &D_L39_0024BC8C[sub[6]];
        func_0038CE20(&t, &r, 0.5f);
        vec_add_ab(&t, &t, &D_L39_0024B7B0);
        func_0038CE20(&r, &t, (f32)g->d.x);
        fz = r.z;
        z = fz;
        fy = r.y;
        y = fy;
        fx = r.x;
        x = fx;
        fx -= (f32)x;
        fy -= (f32)y;
        fz -= (f32)z;
        {
            s32 px = x;
            s32 py = y;
            s32 pz = z;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[0] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        x1 = x + 1;
        {
            s32 px = x1;
            s32 py = y;
            s32 pz = z;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[1] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        y1 = y + 1;
        {
            s32 px = x;
            s32 py = y1;
            s32 pz = z;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[2] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        {
            s32 px = x1;
            s32 py = y1;
            s32 pz = z;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[3] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        a = func_L01_003EFAA0(s, fx, fy);
        z1 = z + 1;
        {
            s32 px = x;
            s32 py = y;
            s32 pz = z1;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[0] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        {
            s32 px = x1;
            s32 py = y;
            s32 pz = z1;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[1] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        {
            s32 px = x;
            s32 py = y1;
            s32 pz = z1;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[2] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        {
            s32 px = x1;
            s32 py = y1;
            s32 pz = z1;
            if (px == g->d.x) px--;
            if (py == g->d.y) py--;
            if (pz == g->d.z) pz--;
            s[3] = g->data[px + py * g->d.x + pz * g->d.x * g->d.y];
        }
        b = func_L01_003EFAA0(s, fx, fy);
        v = (s32)(func_L01_003EFA80(a, b, fz) * D_L39_0024B7A0);
        func_L39_005F3760(sub[5], v > 0x400 ? 0x400 : v);
    }
}
/* localdecomp:end func_L39_00574F20 */

/* localdecomp:start func_L39_00575528 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x18];
    u8 f18;
    u8 pad19[7];
} Ent_00575528;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00575528;
extern u8 D_L39_0024DE00[];
extern Ent_00575528 *D_L39_0024BB6C;
extern u8 D_001FE020[];
extern void func_0038D000(void *, void *, void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L39_005F35D8(s32, s32, void *, s32);
extern s32 func_L39_005B4398(s32);
extern void func_L39_005F3088(s32);

void func_L39_00575528(u8 *self) {
    s32 *sub = *(s32 **)(self + 8);
    V4_00575528 d;
    V4_00575528 l;
    s32 flags = 0x19;
    u8 *slot;

    vec_sub_ab(&d, D_L39_0024DE00, self + 0x40);
    d.w = 0.0f;
    func_0038D000(&l, &d, self + 0x50);
    if (fabs_asm(l.x) <= 1.0f && fabs_asm(l.y) <= 1.0f && fabs_asm(l.z) <= 1.0f) {
        if (D_L39_0024BB6C[sub[0]].f18) flags |= 4;
        slot = D_001FE020 + (sub[4] << 7);
        if (*(u8 **)(slot + 0x100) != self || !slot[0xD0]) {
            if (func_0038CAD0(sub + 3)) {
                sub[4] = func_L39_005F35D8(sub[0], flags, self, 0x400);
                if (sub[2] > 0) {
                    sub[3] = (s32)((sub[1] + func_L39_005B4398(sub[2] - sub[1])) * 50.0f);
                }
            } else {
                sub[4] = -1;
            }
        } else {
            *(s32 *)(slot + 0x118) = flags;
        }
    } else {
        s32 index = sub[4];
        if (index != -1) {
            u8 *slot2 = D_001FE020 + (index << 7);
            if (*(u8 **)(slot2 + 0x100) == self && slot2[0xD0]) func_L39_005F3088(index);
        }
        sub[4] = -1;
    }
}
/* localdecomp:end func_L39_00575528 */

INCLUDE_ASM("asm/levels", func_L39_005756C0);
