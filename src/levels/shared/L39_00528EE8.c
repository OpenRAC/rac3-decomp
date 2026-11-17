#include "common.h"

/* declared by functions of L39_00528D28.c, which this file was cut from */
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_L39_005B4410(f32, f32);

INCLUDE_ASM("asm/levels", func_L39_00528EE8);

/* localdecomp:start func_L39_00529130 */
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
__asm__(".extern D_L39_0024CE1C, 16");
__asm__(".extern D_L39_0024112C, 16");
extern u8 *D_L39_0024CE1C;
extern s32 D_L39_0024112C;
extern G_00529130 D_L39_0025F740;
__asm__(".extern D_001D5A10_sda, 4");
__asm__(".extern D_L39_0024AA78, 4");
__asm__(".extern D_L39_0024AA7C, 4");
__asm__(".extern D_L39_0024AA80, 4");
extern s32 *D_001D5A10_sda;
extern f32 D_L39_0024AA78;
extern f32 D_L39_0024AA7C;
extern f32 D_L39_0024AA80;
extern void func_L18_00323B20(u8 *);
extern void func_L01_00404A10(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_L18_00457C10(f32, f32, f32, f32, f32, f32 *);
extern f32 func_0038CED8(void *);
extern f32 func_0038CEA8(void *);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L39_00528EE8(O_00529130 *, void *);
extern void func_0038CFB8(void *, void *, f32);
extern void func_L39_005FFDF8(s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L39_005FFE78(void);
extern void func_L01_0040E790(f32 *, f32 *, f32 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_00528BF0(T_00529130 *, void *, void *, f32, f32);
extern void func_003C2880(void *);
extern s32 func_0038CAD0(void *);

void func_L39_00529130(O_00529130 *o) {
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
    o->x2C += (o->x24->x24 - o->x2C) * 0.0600000024f;
    m->x38 += (1.2f - m->x38) * 0.120000005f * 1.44f;
    func_L01_00404A10(func_L18_00323B20, o);
    vec_sub_ba(&v, &m->x10, &o->x10);
    o->xF8 = func_L18_00457C10(o->xF8, func_0038D160(v.x, v.y),
                               D_L39_0024AA7C, D_L39_0024AA78, D_L39_0024AA80, &m->x3C);
    o->xF4 = func_L18_00457C10(o->xF4, -func_0038D160(func_0038CED8(&v), v.z),
                               D_L39_0024AA7C, D_L39_0024AA78, D_L39_0024AA80, &m->x40);
    vec_sub_ab(&v, &m->x10, &m->x20);
    if (func_0038CEA8(&v) < 6.0f) {
        m->x44 *= func_0038CEA8(&v) / 6.0f;
    } else {
        m->x44 += 0.120000005f;
    }
    func_00382760(&ray[1], m->x38, o->xF8, -o->xF4);
    if (o->x31 != 0 && (*D_001D5A10_sda < 3 || (D_L39_0024112C & 1))) {
        func_L39_00528EE8(o, &ray[1]);
    }
    pos = &o->x10;
    ray[0] = o->x10;
    vec_add_ab(&m->x20, &m->x20, &ray[1]);
    o->x10 = m->x20;
    if (((f32 *)&o->x10)[0] < 0.0f || ((f32 *)&o->x10)[1] < 0.0f || ((f32 *)&o->x10)[2] < 0.0f) {
        func_003C2880(o);
        return;
    }
    s.x10 = o;
    s.x14 = 0x1030001;
    s.x1C = m->x5C;
    s.x20 = 1;
    s.x0 = ray[1];
    func_0038CFB8(&s, &s, 1.0f);
    ((f32 *)&s.x0)[2] = 1.0f;
    ((f32 *)&s.x0)[3] = 5627.9248f;
    s.x18 = 3;
    s.x19 = 3;
    s.x1A = o->xAA;
    s.x28 = m->x60;
    a = -1;
    tgt = m->x30;
    if (D_L39_0024CE1C != 0) {
        a = *(s32 *)(D_L39_0024CE1C + 0x2548);
    }
    func_L39_005FFDF8(a);
    hit = func_003D3CB0(ray, pos, 0, tgt, (s32)&s);
    func_L39_005FFE78();
    if (hit != 0) {
        t = D_L39_0025F740.x18;
        if ((t != 0 && t != m->x30 && t->xAA != 0x15A5) || D_L39_0025F740.x1C > 0) {
            src = &D_L39_0025F740.x20;
            o->x10 = *src;
            func_00382760(&ray[1], m->x38, o->xF8, -o->xF4);
            pw = &w;
            func_L01_0040E790((f32 *)pw, (f32 *)&ray[1], (f32 *)&D_L39_0025F740.x40);
            func_0038CF68(pw, pw, 0.0400000028f);
            k = 1.5f;
            t2 = D_L39_0025F740.x18;
            if (t2 != 0 && t2 != m->x30 && t2->xAA != 0x15A5) {
                k = 2.5f;
            }
            func_L39_00528BF0(m->x30, pw, pos, k, m->x5C);
            func_003C2880(o);
            return;
        }
    }
    if (func_0038CAD0(m->x34) != 0) {
        func_003C2880(o);
    }
}
/* localdecomp:end func_L39_00529130 */
