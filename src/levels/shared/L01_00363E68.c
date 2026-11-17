#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00363E68);

INCLUDE_ASM("asm/levels", func_L01_00364180);

INCLUDE_ASM("asm/levels", func_L01_003649E8);

INCLUDE_ASM("asm/levels", func_L01_00364C20);

/* localdecomp:start func_L01_00365E28 */
typedef int s128_365E28 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_365E28;
typedef struct { f32 x, y, z; } V3_365E28;
typedef struct { f32 u, v; } Uv_365E28;
extern V3_365E28 D_L01_0028F1B0[];
extern s32 D_L01_0028F3A8[];
extern Uv_365E28 D_L01_0028F450[];
extern s32 func_003A9440(s32 a, unsigned long b);
extern s32 func_00389598(s32 a);
extern void func_0038C750(void);
extern f32 func_0038DB48(f32 a);
extern f32 func_0038D098(f32 a);
extern void func_00382760(V4_365E28 *v, f32 a, f32 b, f32 c);
extern void func_0038D028(void *a, void *b, void *c);
extern void func_003D3A24(s32 n, void *a, void *b, void *c, s32 d);

/* suck_arc_strip_draw: one Suck Cannon vortex arc: a strip of 21 pairs of points on a ball, drawn
   in an effect texture; the pair's two points sit at the two latitudes */
void func_L01_00365E28(s128_365E28 *matrix, f32 span, f32 from_lat, f32 to_lat, s32 texture, f32 unused_f, s32 colour, s32 added) {
    V4_365E28 v;
    V4_365E28 w;
    f32 step, lon, u, rad, twenty;
    s32 i, k;

    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x513F1);
    func_003A9440(6, func_00389598(texture));
    if (added != 0) {
        func_003A9440(0x42, 0x8000000048UL);
    } else {
        func_003A9440(0x42, 0x8000000041UL);
    }
    rad = 0.0174532924f;
    func_0038C750();
    twenty = 20.0f;
    step = span * rad / twenty;
    for (i = 0; i < 42; i += 2) {
        k = i / 2;
        lon = func_0038DB48((f32)k * step);
        func_0038D098(lon);
        u = (f32)k / twenty;
        D_L01_0028F3A8[i] = colour;
        D_L01_0028F3A8[i + 1] = colour;
        D_L01_0028F450[i].u = u;
        D_L01_0028F450[i].v = 0.0f;
        D_L01_0028F450[i + 1].u = u;
        D_L01_0028F450[i + 1].v = 1.0f;
        func_00382760(&v, 1.0f, lon, from_lat * rad);
        v.w = 1.0f;
        func_0038D028(&w, &v, matrix);
        D_L01_0028F1B0[i].x = w.x;
        D_L01_0028F1B0[i].y = w.y;
        D_L01_0028F1B0[i].z = w.z;
        func_00382760(&v, 1.0f, lon, to_lat * rad);
        v.w = 1.0f;
        func_0038D028(&w, &v, matrix);
        D_L01_0028F1B0[i + 1].x = w.x;
        D_L01_0028F1B0[i + 1].y = w.y;
        D_L01_0028F1B0[i + 1].z = w.z;
    }
    func_003D3A24(0x2A, D_L01_0028F1B0, D_L01_0028F3A8, D_L01_0028F450, 1);
}
/* localdecomp:end func_L01_00365E28 */

/* localdecomp:start func_L01_003660B0 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;

extern void func_0038D328(s128 *, S_38C110v *);
extern void func_0038D640(s128 *, void *, s128 *);
extern void func_0038CE20(s128 *, s128 *, f32);
extern void func_L01_00365E28(s128 *, f32, f32, f32, s32, f32, s32, s32);

void func_L01_003660B0(S_38C110v *a0, void *a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16, f32 f17) {
    S_38C110v v;
    s128 m1[4];
    s128 m2[4];

    v.x = 0.0f;
    v.y = 0.0f;
    v.z = f12;
    v.w = 1.0f;
    func_0038D328(m1, &v);
    func_0038D640(m2, a1, m1);
    func_0038CE20(&m2[0], &m2[0], f13);
    func_0038CE20(&m2[1], &m2[1], f13);
    func_0038CE20(&m2[2], &m2[2], f13);
    *(S_38C110v *)&m2[3] = *a0;
    func_L01_00365E28(m2, f17, f14, f15, a2, f16, a3, 1);
}
/* localdecomp:end func_L01_003660B0 */

/* localdecomp:start func_L01_003661D8 */
extern s16 D_L01_001E1B10;
extern void func_L01_00364180();
extern void func_L01_00404808(void *, void *);
void func_L01_003661D8(void *a0) {
    s32 i;
    if (D_L01_001E1B10 > 0) {
        for (i = 0; i < 10; i++) {
            if ((&D_L01_001E1B10)[i] > 64) {
                (&D_L01_001E1B10)[i] = 64;
            }
            (&D_L01_001E1B10)[i] -= 8;
        }
        func_L01_00404808(func_L01_00364180, a0);
    }
}
/* localdecomp:end func_L01_003661D8 */

INCLUDE_ASM("asm/levels", func_L01_00366240);

LINKER_REMNANT("asm/levels", func_L01_003663F0);

INCLUDE_ASM("asm/levels", func_L01_00366400);

INCLUDE_ASM("asm/levels", func_L01_00366BE0);

INCLUDE_ASM("asm/levels", func_L01_00366CD0);

/* localdecomp:start func_L01_00366DE0 */
extern s32 D_001A71A4[];
extern s32 D_L01_001E1C60;
extern f32 D_L01_001E1C64;

void func_L01_00366DE0(void) {
    s32 temp_v0;
    s32 temp_v0_2;

    if (D_001A71A4[0] == 1) {
        temp_v0 = D_L01_001E1C60 + 1;
        D_L01_001E1C60 = temp_v0;
        if (temp_v0 >= 0x22) {
            D_L01_001E1C60 = 0x21;
        }
    } else {
        temp_v0_2 = D_L01_001E1C60 - 1;
        D_L01_001E1C60 = temp_v0_2;
        if (temp_v0_2 < 0) {
            D_L01_001E1C60 = 0;
        }
    }
    D_L01_001E1C64 = (f32) D_L01_001E1C60 / 33.0f;
}
/* localdecomp:end func_L01_00366DE0 */

/* localdecomp:start func_L01_00366E48 */
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_0043A430(s32, s32, void *);
void func_L01_00366E48(s32 a, s32 *b, s32 *c, void *buf, s32 e) {
    *b = 0;
    *c = 0;
    func_0038CB78(buf, 0, 64);
    func_L01_0043A430(a, e, buf);
}
/* localdecomp:end func_L01_00366E48 */

/* localdecomp:start func_L01_00366EA8 */
void func_L01_00366EA8(f32 *a, f32 *b, f32 *c, s32 index, s32 active) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    if (active) {
        *a += 0.05400000512599945f;
        if (*a > 1.0f) *a = 1.0f;
    } else {
        if (*a < 0.1f) {
            *a += 0.012f;
            if (*a > 0.1f) *a = 0.1f;
        } else {
            *a -= 0.007200000341981649f;
            if (*a < 0.1f) *a = 0.1f;
        }
    }
    *b = func_0038DAB8(*b, *a * 0.37699115f);
    c[index + 4] = func_0038D0B0(*b * 0.5f);
    c[7] = func_0038D098(*b * 0.5f);
}
/* localdecomp:end func_L01_00366EA8 */

/* localdecomp:start func_L01_00366FC8 */
typedef struct {
    u8 pad[0x1200];
    u8 *p1200;
    u8 pad2[0x24];
    s32 mode1228;
} State_00366240;

extern State_00366240 D_001A4BE0;

s32 func_L01_00366FC8(void) {
    State_00366240 *s = &D_001A4BE0;
    if (s->mode1228 != 18 || s->p1200 == 0 || s->p1200[32] == 1 || s->p1200[32] == 5) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_00366FC8 */

/* localdecomp:start func_L01_00367018 */
extern s128 D_L01_001E1C30[1] __attribute__((section(".sdata")));
extern f32 D_L01_001E1C28;
s32 func_L01_00367018(s128 *out, f32 *value) {
    extern s32 func_L01_00366FC8(void);
    if (!func_L01_00366FC8()) return 0;
    *out = D_L01_001E1C30[0];
    *value = D_L01_001E1C28;
    return 1;
}
/* localdecomp:end func_L01_00367018 */

LINKER_REMNANT("asm/levels", func_L01_00367078);

INCLUDE_ASM("asm/levels", func_L01_00367080);

INCLUDE_ASM("asm/levels", func_L01_00367260);

/* localdecomp:start func_L01_00367430 */
extern s32 D_L01_001E1C24;
extern s32 D_L01_001E1CD4;
extern s32 D_L01_001DFB40;
extern f32 D_L01_001E1C20;
extern s32 D_L01_001E1CD0;
extern s32 D_001D545C;
extern f32 D_L01_002B3870[];
void func_L01_00367430(s32 a, f32 amount) {
    if (amount <= 0.0f && a != D_L01_001E1C24) return;
    if (amount < D_L01_001E1C20 && D_L01_001E1CD4 == D_L01_001DFB40) return;
    D_L01_001E1C24 = a;
    D_L01_001E1CD0 = 8;
    D_L01_001E1CD4 = D_L01_001DFB40;
    D_L01_001E1C20 = amount;
    if (amount > 2.0f) {
        if (D_001D545C == 16) D_L01_002B3870[5] = 0.08f;
        else D_L01_002B3870[5] = (amount - 2.0f) * 0.05f + 0.08f;
        if (D_L01_002B3870[5] > 1.0f) D_L01_002B3870[5] = 1.0f;
        D_L01_002B3870[6] = 0.08f / D_L01_002B3870[5];
        D_L01_002B3870[7] = 0.55f;
    } else {
        D_L01_002B3870[5] = 0.08f;
        D_L01_002B3870[7] = 0.0f;
    }
}
/* localdecomp:end func_L01_00367430 */

LINKER_REMNANT("asm/levels", func_L01_00367580);

INCLUDE_ASM("asm/levels", func_L01_00367590);

/* localdecomp:start func_L01_00367658 */
extern f32 D_L01_001E1C70;

s32 func_L01_00367658(void) {
    s32 var_v0;

    var_v0 = 0;
    if (!(D_L01_001E1C70 < 1.0f)) {
        var_v0 = 1;
    }
    return var_v0;
}
/* localdecomp:end func_L01_00367658 */

INCLUDE_ASM("asm/levels", func_L01_00367688);

INCLUDE_ASM("asm/levels", func_L01_00367780);

INCLUDE_ASM("asm/levels", func_L01_00367EE0);

INCLUDE_ASM("asm/levels", func_L01_00368478);

INCLUDE_ASM("asm/levels", func_L01_003687C8);

INCLUDE_ASM("asm/levels", func_L01_00368B30);

LINKER_REMNANT("asm/levels", func_L01_003691D0);

/* localdecomp:start func_L01_003691D8 */
typedef struct { u8 pad0[0x24]; f32 scale; } Class_003691D8;
typedef struct {
 u8 pad0[0x10]; s128 pos; u8 state; u8 pad21[3]; Class_003691D8 *cls;
 u8 pad28[4]; f32 scale; u8 pad30[4]; u16 flags;
 u8 pad36[0x62]; s32 data; u8 pad9C[0x24]; s128 rot[3]; f32 angles[4];
} Moby_003691D8;
extern s128 D_L01_001E2A40[];
void func_L01_003691D8(Moby_003691D8 *m) {
 extern void func_L01_003693F8(void *);
 extern s32 func_0038DC20(void *,f32);
 extern f32 func_0038DAB8(f32,f32);
 extern void func_0038D308(void *,void *);
 extern void func_L01_00404A10_003691D8(void *,void *);
 extern f32 func_L01_0040E548(void *,void *);
 extern void func_L01_004AA7E8(void *,s32);
 extern void func_L01_003303B8(void *,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
 S_38C110v v;
 if(m->flags & 0x80) return;
 switch(m->state) {
 case 3: break;
 case 1:
  *(s128 *)&v=m->pos;
  v.w=m->scale/m->cls->scale/1.5f*1.4f;
  if(func_0038DC20(&v,40.0f)==-1) return;
  m->angles[2]=func_0038DAB8(m->angles[2],0.03141593f);
  func_0038D308(m->rot,m->angles);
  func_L01_00404A10_003691D8(func_L01_003693F8,m);
  break;
 case 2:
  if(func_L01_0040E548(D_L01_001E2A40,&m->pos)<1600.0f) {
   func_L01_003303B8(&m->pos,0,25,20,20,20,0,0,0.2f,0.0f,0.0f,2.0f,
    1,1,1,0,0,1,0,0,0xF78E38,0xF76300,0xFF7F40,0xFF2000,0xFF8F00,0xFF6430,0x7FFFA060,0x28FF0000,0xFF6430,0);
  }
  m->data=0;
  m->state=3;
  m->flags=(m->flags|0x41)&0xEFFF;
  func_L01_004AA7E8(m,1);
  break;
 }
}
/* localdecomp:end func_L01_003691D8 */

LINKER_REMNANT("asm/levels", func_L01_003693E8);

INCLUDE_ASM("asm/levels", func_L01_003693F8);

INCLUDE_ASM("asm/levels", func_L01_00369700);

INCLUDE_ASM("asm/levels", func_L01_00369C48);

/* localdecomp:start func_L01_00369D80 */
typedef struct {
    u8 pad[0x1C];
    s32 f1C;
} S_00369D80_1C;

typedef struct {
    u8 pad[0x68];
    S_00369D80_1C *f68;
    u8 pad2[0x4C];
    s32 fB8;
} S_00369D80;

extern s32 func_00382498(s32, s32);
extern void *func_L01_003E0058(void *, void *, s32);

void func_L01_00369D80(S_00369D80 *a0, void *a1, void *a2) {
    S_00369D80_1C *p;
    void *r;
    s32 x;

    p = a0->f68;
    x = func_00382498(15, 45);
    p->f1C = (x * 5 + 2) / 6;
    func_0038CE20(a2, a2, 0.2f);
    r = func_L01_003E0058(a1, a2, 0);
    if (r != 0) {
        ((S_00369D80 *)r)->fB8 = a0->fB8;
    }
}
/* localdecomp:end func_L01_00369D80 */

INCLUDE_ASM("asm/levels", func_L01_00369E28);

INCLUDE_ASM("asm/levels", func_L01_0036AA60);

INCLUDE_ASM("asm/levels", func_L01_0036AB88);

INCLUDE_ASM("asm/levels", func_L01_0036B078);

INCLUDE_ASM("asm/levels", func_L01_0036B440);
