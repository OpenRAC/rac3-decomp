#include "common.h"

/* NTSC-U counterpart of func_L39_00529130 (src/levels/shared/L39_00528EE8.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_00528C08 */
#include "vu0.h"
typedef struct { u8 pad0[0xAA]; s16 xAA; } T_00529130;
typedef struct { u8 pad0[0x24]; f32 x24; } U_00529130;
typedef struct {
    u8 pad0[0x10]; u128_t x10; u128_t x20; T_00529130 *x30; u8 x34[4]; f32 x38; f32 x3C; f32 x40; f32 x44;
    u8 pad48[0x5C - 0x48]; f32 x5C; s32 x60;
} M_00529130;
typedef struct {
    u8 pad0[0x10]; u128_t x10; u8 pad20[4]; U_00529130 *x24; u8 pad28[4]; f32 x2C; u8 pad30; u8 x31; u8 pad32[0x68 - 0x32];
    M_00529130 *x68; u8 pad6C[0xAA - 0x6C]; u16 xAA; u8 padAC[0xF4 - 0xAC]; f32 xF4; f32 xF8;
} O_00529130;
typedef struct {
    u128_t x0; void *x10; s32 x14; u8 x18; u8 x19; u16 x1A; f32 x1C; s32 x20; u8 pad24[4]; s32 x28; u8 pad2C[4];
} S_00529130;
typedef struct { u8 pad0[0x18]; T_00529130 *x18; s32 x1C; u128_t x20; u8 pad30[0x10]; u128_t x40; } G_00529130;
__asm__(".extern D_L39_0024CF1C, 16");
__asm__(".extern D_L39_002412AC, 16");
extern u8 *D_L39_0024CF1C;
extern s32 D_L39_002412AC;
extern G_00529130 D_L39_0025F840;
__asm__(".extern D_001D5A10_sda_00528C08, 4");
__asm__(".extern D_L39_0024AB88, 4");
__asm__(".extern D_L39_0024AB8C, 4");
__asm__(".extern D_L39_0024AB90, 4");
extern s32 *D_001D5A10_sda_00528C08;
extern f32 D_L39_0024AB88;
extern f32 D_L39_0024AB8C;
extern f32 D_L39_0024AB90;
extern void func_L18_00323498(u8 *);
extern void func_L01_004026A0(void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_L18_00454598(f32, f32, f32, f32, f32, f32 *);
extern f32 func_003887A0(void *);
extern f32 func_00388770(void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L39_005289D0(O_00529130 *, void *);
extern void func_00388880(void *, void *, f32);
extern void func_L39_005FD658(s32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L39_005FD6D8(void);
extern void func_L01_0040C260(f32 *, f32 *, f32 *);
extern void func_00388830(void *, void *, f32);
extern void func_L39_005286D8(T_00529130 *, void *, void *, f32, f32);
extern void func_003BD360(void *);
extern s32 func_00388398(void *);

void func_L39_00528C08(O_00529130 *o) {
    M_00529130 *m;
    u128_t ray[2];
    vu0_v4 v;
    S_00529130 s;
    vu0_v4 w;
    s32 hit;
    s32 a;
    T_00529130 *t;
    T_00529130 *tgt;
    T_00529130 *t2;
    u128_t *src;
    vu0_v4 *pw;
    u128_t *pos;
    f32 k;

    if (o == 0 || (m = o->x68) == 0) {
        return;
    }
    o->x2C += (o->x24->x24 - o->x2C) * 0.05f;
    m->x38 += (1.0f - m->x38) * 0.1f;
    func_L01_004026A0(func_L18_00323498, o);
    vec_sub_ba(&v, &m->x10, &o->x10);
    o->xF8 = func_L18_00454598(o->xF8, func_00388A28(v.x, v.y),
                               D_L39_0024AB8C, D_L39_0024AB88, D_L39_0024AB90, &m->x3C);
    o->xF4 = func_L18_00454598(o->xF4, -func_00388A28(func_003887A0(&v), v.z),
                               D_L39_0024AB8C, D_L39_0024AB88, D_L39_0024AB90, &m->x40);
    vec_sub_ab(&v, &m->x10, &m->x20);
    if (func_00388770(&v) < 6.0f) {
        m->x44 *= func_00388770(&v) / 6.0f;
    } else {
        m->x44 += 0.1f;
    }
    func_0037E4B8(&ray[1], m->x38, o->xF8, -o->xF4);
    if (o->x31 != 0 && (*D_001D5A10_sda_00528C08 < 3 || (D_L39_002412AC & 1))) {
        func_L39_005289D0(o, &ray[1]);
    }
    pos = &o->x10;
    ray[0] = o->x10;
    vec_add_ab(&m->x20, &m->x20, &ray[1]);
    o->x10 = m->x20;
    if (((f32 *)&o->x10)[0] < 0.0f || ((f32 *)&o->x10)[1] < 0.0f || ((f32 *)&o->x10)[2] < 0.0f) {
        func_003BD360(o);
        return;
    }
    s.x10 = o;
    s.x14 = 0x1030001;
    s.x1C = m->x5C;
    s.x20 = 1;
    s.x0 = ray[1];
    func_00388880(&s, &s, 1.0f);
    ((f32 *)&s.x0)[2] = 1.0f;
    ((f32 *)&s.x0)[3] = 5627.9248f;
    s.x18 = 3;
    s.x19 = 3;
    s.x1A = o->xAA;
    s.x28 = m->x60;
    a = -1;
    tgt = m->x30;
    if (D_L39_0024CF1C != 0) {
        a = *(s32 *)(D_L39_0024CF1C + 0x2548);
    }
    func_L39_005FD658(a);
    hit = func_003CE740(ray, pos, 0, tgt, (s32)&s);
    func_L39_005FD6D8();
    if (hit != 0) {
        t = D_L39_0025F840.x18;
        if ((t != 0 && t != m->x30 && t->xAA != 0x15A5) || D_L39_0025F840.x1C > 0) {
            src = &D_L39_0025F840.x20;
            o->x10 = *src;
            func_0037E4B8(&ray[1], m->x38, o->xF8, -o->xF4);
            pw = &w;
            func_L01_0040C260((f32 *)pw, (f32 *)&ray[1], (f32 *)&D_L39_0025F840.x40);
            func_00388830(pw, pw, 0.0333333351f);
            k = 1.5f;
            t2 = D_L39_0025F840.x18;
            if (t2 != 0 && t2 != m->x30 && t2->xAA != 0x15A5) {
                k = 2.5f;
            }
            func_L39_005286D8(m->x30, pw, pos, k, m->x5C);
            func_003BD360(o);
            return;
        }
    }
    if (func_00388398(m->x34) != 0) {
        func_003BD360(o);
    }
}
/* localdecomp:end func_L39_00528C08 */
