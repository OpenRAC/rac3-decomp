#include "common.h"

typedef struct {
    u8 pad0[16];
    s32 unk10;
} C39E3B8;
typedef struct {
    u8 pad0[220];
    s32 unkDC;
} V39E3B8;
typedef struct {
    u8 pad0[36];
    C39E3B8 *unk24;
    u8 pad28[52 - 40];
    u16 unk34;
    u8 pad36[104 - 54];
    V39E3B8 *pVars;
    u8 pad6C[152 - 108];
    s32 unk98;
    u8 pad9C[256 - 156];
} M39E3B8;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} V_003A0200;
typedef struct {
    u8 pad0[0x24];
    f32 f24;
} C_003A0200;
typedef struct {
    u8 pad0[0x36];
    s16 f36;
    u8 pad38[0x100 - 0x38];
} M_003A0200;
typedef struct {
    u8 pad0[0x24];
    C_003A0200 *f24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[0x43 - 0x30];
    u8 f43;
    u8 pad44[0x68 - 0x44];
    V_003A0200 *f68;
} O_003A0200;

/* declared by functions of L02_003A0158.c, which this file was cut from */
extern void func_L02_003A04D0(u8 *o, s32 a);

/* localdecomp:start func_L02_003A04D0 */
#include "vu0.h"
typedef int u128_003A04D0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003A04D0;
typedef struct { u8 pad0[8]; f32 f8; f32 fC; f32 f10; u8 b14; u8 b15; u8 b16; } M_003A04D0;
typedef struct { f32 x, y, z; } P_003A04D0;
typedef struct { f32 u, v; } T_003A04D0;
extern P_003A04D0 D_L02_002A1650[];
extern u32 D_L02_002A18A8[];
extern T_003A04D0 D_L02_002A1970[];
extern void func_0038C750(void);
extern long func_00389598(s32);
extern void func_003A9440(s32, unsigned long);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L02_003A04D0(u8 *o, s32 a) {
    M_003A04D0 *m = *(M_003A04D0 **)(o + 0x68);
    V_003A04D0 base;
    V_003A04D0 off;
    V_003A04D0 v;
    f32 h;
    f32 z;
    f32 r0;
    f32 t;
    f32 r;
    f32 ang;
    f32 zz;
    f32 step;
    f32 dr;
    s32 done;
    s32 n;
    s32 col;
    s32 i;
    s32 k;

    func_0038C750();
    func_003A9440(6, func_00389598(0x17));
    func_003A9440(0x14, 0xFF9000000260);
    func_003A9440(8, 0);
    func_003A9440(0x42, 0x4000000044);
    base = *(V_003A04D0 *)(o + 0x10);
    z = m->f8 - 0.5f;
    if (z < 0.0f) {
        z = 0.0f;
    }
    z *= 3.0f;
    base.z += z;
    done = 0;
    n = 0;
    step = 0.05f;
    h = 0.2f;
    t = -step;
    r0 = 0.9f + m->fC * (0.1f - 0.9f);
    if (a != 0) {
        h *= 0.2f;
    }
    dr = 0.1f - r0;
    do {
        t += step;
        if (m->f8 <= t) {
            t = m->f8;
            done = 1;
        }
        r = r0 + dr * t;
        zz = t * 3.0f;
        ang = func_0038DB48(m->f10 + t * 25.1327419f);
        *(u128_003A04D0 *)&v = 0;
        v.x = func_0038D098(ang) * r;
        v.y = func_0038D0B0(ang) * r;
        v.z = zz;
        off = v;
        k = n + 1;
        vec_add_ab(&v, &base, &off);
        D_L02_002A1650[n + 1].x = v.x;
        D_L02_002A1650[n + 1].y = v.y;
        D_L02_002A1650[n].x = v.x;
        D_L02_002A1650[n].y = v.y;
        D_L02_002A1650[n].z = v.z + h;
        D_L02_002A1650[n + 1].z = v.z - h;
        if (a != 0) {
            col = ((s32)(t / m->f8 * 127.0f) << 24) | 0xFFFFFF;
            D_L02_002A18A8[n + 1] = col;
            D_L02_002A18A8[n] = col;
        } else {
            col = ((s32)(t / m->f8 * 128.0f) << 24) | (m->b16 << 16) | (m->b15 << 8) | m->b14;
            D_L02_002A18A8[k] = col;
            D_L02_002A18A8[n] = col;
        }
        n += 2;
        if (done) {
            break;
        }
    } while (n < 40);
    for (i = 0; i < n; i++) {
        D_L02_002A1970[i].u = i / 2;
        D_L02_002A1970[i].v = !(i & 1) ? 1.0f : 0.0f;
    }
    func_003D3A24(n, D_L02_002A1650, D_L02_002A18A8, D_L02_002A1970, 1);
    *(u128_003A04D0 *)&v = 0;
    v.x = D_L02_002A1650[n - 1].x;
    v.y = D_L02_002A1650[n - 1].y;
    v.z = D_L02_002A1650[n - 1].z + h;
    off = v;
    if (a != 0) {
        func_003D9508(&off, 0x31, 0x7FFFFFFF, 1, 0.3f, 0.08f, 0.7853982f);
    } else {
        func_003D9508(&off, 0x31, (m->b16 << 16) | 0x40000000 | (m->b15 << 8) | m->b14, 1, 0.75f, 0.08f, 0.0f);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L02_003A04D0 */

/* localdecomp:start func_L02_003A0978 */
#include "vu0.h"

typedef int u128_003A0978 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_003A0978;

extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 D_L02_001D66B0;
__asm__(".extern D_L02_001D66B0, 16");
extern u8 *D_L02_0021E23C[];

void func_L02_003A0978(u8 *a0) {
    V4_003A0978 pos;
    V4_003A0978 v10;
    u8 *st;
    u8 *p;
    f32 r0;
    f32 base;
    f32 lin;
    f32 ang;
    f32 zup;
    f32 sz;
    s32 life;
    s32 color;
    s32 b5;
    s32 r;

    st = *(u8 **)(a0 + 0x68);
    r0 = func_003824E0(0.0f, *(f32 *)(st + 8));
    lin = *(f32 *)(st + 0xC) * -0.79999995f + 0.9f;
    base = lin + (0.1f - lin) * r0;
    ang = func_00382538();
    zup = *(f32 *)(st + 8) - 0.5f;
    if (zup < 0.0f) {
        zup = 0.0f;
    }
    *(u128_003A0978 *)&v10 = 0;
    zup *= 3.0f;
    zup += r0 * 3.0f;
    v10.x = base * func_0038D0B0(ang);
    v10.y = base * func_0038D098(ang);
    v10.z = zup;
    *(u128_003A0978 *)&pos = *(u128_003A0978 *)&v10;
    vec_add_ab(&pos, a0 + 0x10, &pos);
    life = func_00382498(-10, 10) + 30;
    sz = func_003824E0(-0.1f, 0.1f) + 0.3f;
    color = st[0x16] << 16 | st[0x15] << 8 | st[0x14];
    b5 = 0;
    r = func_00382468(2);
    p = func_L01_0046FB40(&pos, &D_L02_001D66B0, life, color, r ? -1 : 1, 0x40, 0x20,
                          sz * 210000.0f, sz * 210000.0f, 0.0016000001f, 0);
    if (p != 0) {
        b5 = p[8] + 0x20;
        p[2] = *D_L02_0021E23C[0];
    }
    r = func_00382468(2);
    p = func_L01_0046FB40(&pos, &D_L02_001D66B0, life, 0xF7F7F7, r ? -1 : 1, 0x30, 0x30,
                          sz * 0.4f * 210000.0f, sz * 0.4f * 210000.0f, 0.0016000001f, 0);
    if (p != 0) {
        p[2] = *D_L02_0021E23C[0];
        p[8] = b5;
    }
}
/* localdecomp:end func_L02_003A0978 */

/* localdecomp:start func_L02_003A0C18 */
#include "vu0.h"
typedef int u128_003A0C18 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003A0C18;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[0x14 - 0x8];
    u8 b14;
    u8 b15;
    u8 b16;
    u8 pad17;
    u8 b18;
} M_003A0C18;
typedef struct { u8 pad0[0x10]; V_003A0C18 pos; u8 pad20[0xE0]; } E_003A0C18;
typedef struct { u8 pad0[0x68]; M_003A0C18 *x68; } O_003A0C18;

extern u8 D_L02_0021E0D8[];
extern u8 *D_L02_001DE99C_003A0C18;
__asm__(".extern D_L02_001DE99C_003A0C18, 16");
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

static __inline__ E_003A0C18 *moby_003A0C18(s32 idx) {
    return (E_003A0C18 *)(D_L02_001DE99C_003A0C18 + (idx << 8));
}

void func_L02_003A0C18(O_003A0C18 *o) {
    M_003A0C18 *m = o->x68;
    E_003A0C18 *e;
    V_003A0C18 v0;
    V_003A0C18 v10;
    f32 ang;
    f32 a;
    f32 b;
    s32 i;
    s32 c1;
    s32 col;
    s32 keep;
    u8 *tb;
    s32 d1;
    u8 *p;

    e = m->b18 != 0 ? moby_003A0C18(m->x4) : moby_003A0C18(m->x0);
    ang = 0.0f;
    tb = D_L02_0021E0D8;
    for (i = 0; i < 40; i++) {
        *(u128_003A0C18 *)&v10 = 0;
        keep = 0;
        v10.x = func_0038D0B0(ang) * 0.4f;
        v10.y = func_0038D098(ang) * 0.4f;
        v10.z = 1.75f;
        *(u128_003A0C18 *)&v0 = *(u128_003A0C18 *)&v10;
        vec_add_ba(&v10, &e->pos, &v0);
        v0.z = 0.0f;
        func_0038CF68(&v0, &v0, (func_003824E0(-1.0f, 1.0f) + 10.0f) * (1.2f / 60.0f));
        c1 = func_00382498(0xF, 0x19);
        a = func_003824E0(-0.1f, 0.1f) + 0.5f;
        b = func_003824E0(-4.0f, 4.0f) + 15.0f;
        col = (m->b16 << 16) | (m->b15 << 8) | m->b14;
        d1 = func_00382468(2);
        b = b * (0.4f / 1000.0f);
        p = func_L01_0046FB40(&v10, &v0, c1, col, d1 != 0 ? -1 : 1, 0x40, 0x20, a * 210000.0f,
                              a * 210000.0f, b, 0);
        if (p != 0) {
            keep = p[8] + 0x20;
            p[2] = **(u8 **)(tb + 0x164);
        }
        p = func_L01_0046FB40(&v10, &v0, c1, 0xF7F7F7, func_00382468(2) != 0 ? -1 : 1, 0x30, 0x30,
                              a * 0.4f * 210000.0f, a * 0.4f * 210000.0f, b, 0);
        if (p != 0) {
            p[2] = **(u8 **)(tb + 0x164);
            p[8] = keep;
        }
        ang = func_0038DAB8(ang, 0.15707964f);
    }
}
/* localdecomp:end func_L02_003A0C18 */
