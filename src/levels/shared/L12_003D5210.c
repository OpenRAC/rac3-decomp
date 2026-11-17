#include "common.h"

typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; void *w68; } M_3D5548;
typedef struct {
    void (*fn0)(void *);
} Iface;
typedef struct {
    char pad0[0x30];
    int timer;
    char pad34[0x3E - 0x34];
    unsigned char b62;
    char pad3F[0x40 - 0x3F];
    float f64;
} Vars;
typedef struct {
    char pad0[0x30];
    unsigned char b48;
    char pad31[0x32 - 0x31];
    short h50;
} Obj;

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L12_003D4B18.c, which this file was cut from */
extern f32 func_0038CEA8(void *);

/* localdecomp:start func_L12_003D5210 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003D5210;
__asm__(".extern D_L12_001DEF6C, 4");
extern f32 D_L12_001DEF6C;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_004669B0(void *, s32, void *, u32, s32, f32, f32, f32, f32);
extern void func_L01_004668A0(void *, void *, s32, s32, s32, f32);

void func_L12_003D5210(u8 *m, void *dir, V4_003D5210 *at) {
    V4_003D5210 pos;
    V4_003D5210 vel;
    V4_003D5210 p;
    V4_003D5210 d;
    s32 r;
    u32 color;
    f32 speed;
    f32 s;

    pos = *at;
    p = *(V4_003D5210 *)(m + 0x10);
    func_0038CE20(&p, m + 0xC0, -1.2f);
    vec_add_ab(&p, &p, m + 0x10);
    speed = func_0038CEA8(dir) * D_L12_001DEF6C;
    func_0038CE20(&vel, m + 0xC0, speed);
    r = func_00382498(0x20, 0x40);
    color = 0x7F000000 | ((r + 8) << 16) | (r << 8) | r;
    func_L01_004669B0(&p, func_00382498(0, 2) - 1, &vel, color, 0, 0.25f, 0.8f, 1.01f, func_003824E0(0.75f, 1.0f) * 210000.0f);
    vec_sub_ba(&d, m + 0x10, &pos);
    func_0038CE20(&d, &d, 0.5f);
    vec_add_ab(&p, &p, &d);
    r = func_00382498(0x40, 0x80);
    color = 0x40000000 | (r << 16) | (r << 8) | r;
    s = func_003824E0(1.25f, 1.75f) * 210000.0f;
    func_L01_004668A0(&p, &vel, color, 0x101010, (func_00382498(0x19, 0x1E) * 5 + 2) / 6, s);
}
/* localdecomp:end func_L12_003D5210 */

INCLUDE_ASM("asm/levels", func_L12_003D5418);

INCLUDE_ASM("asm/levels", func_L12_003D5570);
