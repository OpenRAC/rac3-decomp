#include "common.h"

typedef struct {
    char pad0[0x10];
    u8 count;
} Anim;
typedef struct {
    char pad0[0x48];
    Anim *anims[1];
} Class;
typedef struct {
    char pad0[0x24];
    Class *cls;
    char pad28[0x40 - 0x28];
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    s32 unk44;
    char pad48[0x58 - 0x48];
    s32 unk58;
    s32 unk5C;
} Moby;
typedef struct {
    char data[0x600];
} Buf;
typedef struct {
    u8 pad0[0xC20];
    s32 xC20;
    s32 xC24;
    s32 xC28;
} D_001A4BE0_t;
typedef struct {
    u8 pad0[0x20];
    u8 b32;
    u8 pad21[0x34 - 0x21];
    u16 h52;
    u8 pad36[0xAA - 0x36];
    s16 h170;
} M_50C8E8;
typedef struct {
    M_50C8E8 *p[3];
    u8 padC[0x28 - 0xC];
    s32 w40;
    u8 pad2C[0x50 - 0x2C];
} E_50C8E8;
typedef struct {
    u8 pad0[0xBF8];
    M_50C8E8 *p3064;
    u8 padBFC[0x1200 - 0xBFC];
    E_50C8E8 e[1];
    u8 pad1250[0x12FC - 0x1250];
    M_50C8E8 *p4860;
    u8 pad1300[0x1A24 - 0x1300];
    M_50C8E8 *p6692;
    u8 pad1A28[0x25E4 - 0x1A28];
    u8 b9700;
} G_50C8E8;
typedef struct {
    u8 pad0[0x44];
    s16 h68;
    u8 pad46[0x1A0 - 0x46];
    M_50C8E8 *arr[1];
} H_50C8E8;
typedef struct {
    u8 pad0[0x20];
    s16 h32;
} K_50C8E8;
typedef struct {
    f32 m[16];
} M_0050D430;
typedef struct {
    f32 v[4];
} V_0050D430;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_50D4D8;
typedef struct {
    u8 pad0[64];
    Vec4_50D4D8 m;
    u8 pad50[9636];
    u8 b25F4;
} G_50D4D8;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 m0[64];
    u8 m40[9716 - 64];
    u8 mode;
} S_50D530;
typedef struct {
    f32 m0[4][4];
    f32 m1[4][4];
    u8 pad[0x25F4 - 0x80];
    u8 mode;
} Cam50D5B0;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_00511618;
typedef struct {
    u8 m0[64];
    u8 m40[9716 - 64];
    u8 mode;
} S_50D870;
typedef struct {
    u8 pad[138];
    u16 h8A;
    u8 pad2[240 - 140];
} S_50D8F8;
typedef struct {
    u8 pad0[0x8A];
    u16 h8A;
    u8 pad8C[0xF0 - 0x8C];
} S_50DA08;
typedef struct {
    u8 arr[0x40];
} S_50DA08a;
typedef struct {
    s32 arr[0x40];
} S_50DA08b;
typedef struct {
    u8 pad0[52];
    s32 x34;
} G_0050F828;

typedef struct {
    u8 pad0[0x78];
    s32 color78;
} Node_005124D8;
typedef struct {
    u8 pad0[0x1340];
    Node_005124D8 *p1340;
    Node_005124D8 *p1344;
    Node_005124D8 *p1348;
    u8 pad134C[0x1390 - 0x134C];
    Node_005124D8 *p1390;
    u8 pad1394[0x2890 - 0x1394];
    f32 f2890;
    f32 f2894;
    f32 f2898;
    f32 f289C;
} Glob_005124D8;

typedef struct Manip_00512A30 {
    u8 pad0;
    u8 initialized;
    u8 pad2[0x1E];
    f32 scale[3];
    u8 pad2C[0x14];
} Manip_00512A30;

extern s32 D_L01_001D6694;

/* localdecomp:start func_L01_00511038 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vector_00511038;
extern D_001A4BE0_t D_001A4BE0;
void func_L01_00511038(char *target, s32 add_position, f32 magnitude, f32 angle, f32 height) {
 extern f32 func_0038D098(f32);
 extern f32 func_0038D0B0(f32);
 extern void func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
 f32 *out = (f32 *)target;
 out[0] = func_0038D098(angle) * magnitude;
 out[1] = func_0038D0B0(angle) * magnitude;
 out[2] = height;
 func_0038D028((V_0050D430 *)out, (V_0050D430 *)out, (M_0050D430 *)&D_001A4BE0);
 if (add_position) {
  __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
          : "+m"(*(Vector_00511038 *)out)
          : "m"(*(Vector_00511038 *)((u8 *)&D_001A4BE0 + 0x80))
          : "vf1", "vf2");
 }
}
/* localdecomp:end func_L01_00511038 */

/* localdecomp:start func_L01_005110E8 */
#include "vu0.h"
extern D_001A4BE0_t D_001A4BE0;
void func_L01_005110E8(V_0050D430 *out, int translate, float x, float y, float z) {
    extern void func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
    M_0050D430 *matrix = (M_0050D430 *)&D_001A4BE0;
    qzero(out);
    out->v[0] = x;
    out->v[1] = y;
    out->v[2] = z;
    func_0038D028(out, out, matrix);
    if (translate) {
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*out) : "m"(*(V_0050D430 *)((u8 *)matrix+0x80)), "m"(*out) : "vf1", "vf2");
    }
}
/* localdecomp:end func_L01_005110E8 */

/* localdecomp:start func_L01_00511158 */
extern void func_L01_00510F08(f32);
void func_L01_00511158(f32 x) {
    func_L01_00510F08(-x);
}
/* localdecomp:end func_L01_00511158 */

/* localdecomp:start func_L01_00511178 */
void func_L01_00511178(Vec4 *out, Vec4 *in, f32 scale) {
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038D328(M_0050D430 *, u8 *);
    extern void func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
    M_0050D430 mat;
    Vec4 delta;
    u8 *base=(u8 *)&D_001A4BE0;
    switch(base[0x25F4]) {
        case 0:
            out->q=in->q;
            out->f[0]+=func_0038D098(*(f32 *)(*(u8 **)(base+0x25C0)+0xF8))*scale;
            out->f[1]+=func_0038D0B0(*(f32 *)(*(u8 **)(base+0x25C0)+0xF8))*scale;
            break;
        case 1:
        case 2:
            delta.f[0]=func_0038D098(0.0f)*scale;
            delta.f[1]=func_0038D0B0(0.0f)*scale;
            delta.f[2]=0.0f;
            func_0038D328(&mat, *(u8 **)(base+0x25C0)+0xF0);
            func_0038D028((V_0050D430 *)&delta,(V_0050D430 *)&delta,&mat);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*out) : "m"(*in), "m"(delta) : "vf1", "vf2");
            break;
    }
}
/* localdecomp:end func_L01_00511178 */

/* localdecomp:start func_L01_00511280 */
#include "vu0.h"
void func_L01_00511280(Vec4 *out,Vec4 *in,f32 height) {
    extern void func_0038D328(M_0050D430 *,u8 *);
    extern void func_0038D028(V_0050D430 *,V_0050D430 *,M_0050D430 *);
    M_0050D430 mat;
    Vec4 delta;
    u8 *base=(u8 *)&D_001A4BE0;
    s32 mode=base[0x25F4];
    switch(mode) {
    case 0:
        out->q=in->q;
        out->f[2]+=height;
        break;
    case 1:
    case 2:
        qzero(&delta);
        delta.f[2]=height;
        func_0038D328(&mat,*(u8 **)(base+0x25C0)+0xF0);
        func_0038D028((V_0050D430 *)&delta,(V_0050D430 *)&delta,&mat);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
             : "=m"(*out) : "m"(*in),"m"(delta) : "vf1","vf2");
        break;
    }
}
/* localdecomp:end func_L01_00511280 */

/* localdecomp:start func_L01_00511320 */
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);

static __inline__ void sub_00511320(Vec4 *d, Vec4 *a, Vec4 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}

void func_L01_00511320(Vec4 *out, Vec4 *in) {
    Vec4 axis;
    u8 *base = (u8 *)&D_001A4BE0;

    switch (base[0x25F4]) {
    case 0:
        out->q = in->q;
        out->f[2] = 0.0f;
        break;
    case 1:
        func_0038CF68(&axis, base + 0x2C0, 1.0f);
        func_0038CE20(&axis, &axis, func_0038CE68(&axis, in));
        sub_00511320(out, in, &axis);
        break;
    case 2:
        func_0038CE20(&axis, base + 0x2E0, func_0038CE68(base + 0x2E0, in));
        sub_00511320(out, in, &axis);
        break;
    }
}
/* localdecomp:end func_L01_00511320 */

/* localdecomp:start func_L01_00511408 */
extern D_001A4BE0_t D_001A4BE0;
extern f32 func_0038CED8(V_0050D430 *);
extern void func_0038D328(M_0050D430 *, u8 *);
extern void func_0038D5B0(M_0050D430 *, M_0050D430 *);
extern void func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
f32 func_L01_00511408(V_0050D430 *a0) {
    u8 *g = ((u8 *)&(*(G_50C8E8 *)&D_001A4BE0));
    M_0050D430 m0, m1;
    V_0050D430 v;
    switch (g[9716]) {
    case 0:
        return func_0038CED8(a0);
    case 1:
    case 2:
        func_0038D328(&m0, *(u8 **)(g + 9664) + 240);
        func_0038D5B0(&m1, &m0);
        func_0038D028(&v, a0, &m1);
        return func_0038CED8(&v);
    }
    return 0.0f;
}
/* localdecomp:end func_L01_00511408 */

/* localdecomp:start func_L01_005114B0 */
extern D_001A4BE0_t D_001A4BE0;
extern void func_0038D000(Vec4_50D4D8 *, f32 *, Vec4_50D4D8 *);
f32 func_L01_005114B0(f32 *a0) {
    Vec4_50D4D8 t;
    switch ((*(G_50D4D8 *)&D_001A4BE0).b25F4) {
    case 0:
        return a0[2];
    case 1:
    case 2:
        func_0038D000(&t, a0, &(*(G_50D4D8 *)&D_001A4BE0).m);
        return t.v[2];
    }
    return 0.0f;
}
/* localdecomp:end func_L01_005114B0 */

/* localdecomp:start func_L01_00511508 */
extern void func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
extern D_001A4BE0_t D_001A4BE0;



void func_L01_00511508(Vec4 *out, Vec4 *in, f32 z) {
    S_50D530 *s = &(*(S_50D530 *)&D_001A4BE0);
    s32 m = s->mode;

    if (m == 0) {
        out->q = in->q;
        out->f[2] = z;
        return;
    }
    if (m < 0) {
        return;
    }
    if (m < 3) {
        ((void (*)(Vec4 *, Vec4 *, void *))func_0038D028)(out, in, s->m40);
        out->f[2] = z;
        ((void (*)(Vec4 *, Vec4 *, void *))func_0038D028)(out, out, s->m0);
    }
}
/* localdecomp:end func_L01_00511508 */

/* localdecomp:start func_L01_00511588 */
extern void func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
extern D_001A4BE0_t D_001A4BE0;

extern void func_0038CFB8(f32 *, f32 *, f32);

void func_L01_00511588(f32 *dst, f32 *src, f32 scale) {
    switch ((*(Cam50D5B0 *)&D_001A4BE0).mode) {
    case 0:
        func_0038CFB8(dst, src, scale);
        break;
    case 1:
    case 2:
        ((void (*)(f32 *, f32 *, void *))func_0038D028)(dst, src, (*(Cam50D5B0 *)&D_001A4BE0).m1);
        func_0038CFB8(dst, dst, scale);
        ((void (*)(f32 *, f32 *, void *))func_0038D028)(dst, dst, (*(Cam50D5B0 *)&D_001A4BE0).m0);
        break;
    }
}
/* localdecomp:end func_L01_00511588 */

/* localdecomp:start func_L01_00511618 */
extern void func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
extern D_001A4BE0_t D_001A4BE0;


void func_L01_00511618(Vec4_00511618 *out, Vec4_00511618 *in, f32 scale)
{
    u8 *g = ((u8 *)&D_001A4BE0);

    switch (g[9716]) {
    case 0:
        *out = *in;
        out->v[2] *= scale;
        break;
    case 1:
    case 2:
        ((void (*)(Vec4_00511618 *, Vec4_00511618 *, void *))func_0038D028)(out, in, g + 64);
        out->v[2] *= scale;
        ((void (*)(Vec4_00511618 *, Vec4_00511618 *, void *))func_0038D028)(out, out, g);
        break;
    }
}
/* localdecomp:end func_L01_00511618 */

/* localdecomp:start func_L01_005116A8 */
extern void func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
extern D_001A4BE0_t D_001A4BE0;

void func_L01_005116A8(f32 *v, f32 *out, f32 s) {
    u8 *p = ((u8 *)&D_001A4BE0);

    switch (p[9716]) {
    case 0:
        v[0] = v[0] * s;
        v[1] = v[1] * s;
        break;
    case 1:
    case 2:
        ((void (*)(f32 *, f32 *, void *))func_0038D028)(v, out, p + 64);
        v[0] = v[0] * s;
        v[1] = v[1] * s;
        ((void (*)(f32 *, f32 *, void *))func_0038D028)(v, v, p);
        break;
    }
}
/* localdecomp:end func_L01_005116A8 */

/* localdecomp:start func_L01_00511748 */
extern D_001A4BE0_t D_001A4BE0;
extern f32 func_L01_005114B0(f32 *a0);

/* hero_ticks_to_apex: the height of the top of his arc from pos and vel, and the whole ticks until it */
f32 func_L01_00511748(f32 gravity, f32 *pos, f32 *vel, s32 *ticks) {
    s32 n;
    s32 rise;
    f32 apex;

    /* the hero's gravity mode, as func_L01_005114B0 reads it */
    switch ((*(G_50D4D8 *)&D_001A4BE0).b25F4) {
    case 0:
        /* n ticks of speed vel.z, losing gravity a tick: the drop is gravity * n(n+1)/2 */
        n = vel[2] / gravity;
        apex = pos[2] + vel[2] * (f32)n - (f32)((n * n + n) >> 1) * gravity;
        if (ticks != 0) {
            *ticks = n;
        }
        return apex;
    case 1:
    case 2:
        rise = func_L01_005114B0(vel) / gravity;
        if (ticks != 0) {
            *ticks = rise;
        }
        return pos[2] + vel[2] * 0.5f;
    }
    return 0.0f;
}
/* localdecomp:end func_L01_00511748 */

/* localdecomp:start func_L01_00511848 */
extern f32 func_0038CED8(V_0050D430 *);
extern void func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
extern D_001A4BE0_t D_001A4BE0;


extern f32 func_0038D160(f32, f32);

f32 func_L01_00511848(Vec4 *in)
{
    S_50D870 *s = &(*(S_50D870 *)&D_001A4BE0);
    s32 m = s->mode;
    Vec4 v;

    if (m == 0) {
        return func_0038D160(in->f[2], ((f32 (*)(Vec4 *))func_0038CED8)(in));
    }
    if (m < 0) {
        return 0.0f;
    }
    if (m >= 3) {
        return 0.0f;
    }
    v.q = in->q;
    ((void (*)(Vec4 *, Vec4 *, void *))func_0038D028)(&v, &v, s->m40);
    return func_0038D160(v.f[2], ((f32 (*)(Vec4 *))func_0038CED8)(&v));
}
/* localdecomp:end func_L01_00511848 */

/* localdecomp:start func_L01_005118D0 */

extern s32 D_001A5E08[];
extern u8 D_001425C0[];
extern S_50D8F8 D_L01_002C5600[];
extern s32 D_001427F0[];

s32 func_L01_005118D0(s32 i, s32 n) {
    if (i == -1) {
        i = D_001A5E08[0];
    }
    if ((D_001425C0[i] + D_L01_002C5600)->h8A == 0) {
        return 1;
    }
    if (D_001427F0[i] < n) {
        return 0;
    }
    D_001427F0[i] -= n;
    return 1;
}
/* localdecomp:end func_L01_005118D0 */

/* localdecomp:start func_L01_00511950 */
s32 func_L01_00511950(s32 arg0) {
    return arg0;
}
/* localdecomp:end func_L01_00511950 */

/* localdecomp:start func_L01_00511958 */
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern S_50D8F8 D_L01_002C5600[];

s32 func_L01_00511958(s32 a0, s32 a1) {
    s32 idx = func_L01_00511950(a0);
    s32 *slot = &D_001427F0[idx];
    S_50D8F8 *e;
    s32 v = *slot + a1;

    *slot = v;
    e = &D_L01_002C5600[D_001425C0[idx]];
    if (e->h8A != 0) {
        s32 overflow = v - e->h8A;
        if (overflow <= 0) {
            return 0;
        }
        *slot = e->h8A;
        return overflow;
    }
    return 0;
}
/* localdecomp:end func_L01_00511958 */

/* localdecomp:start func_L01_005119E0 */
extern s32 D_001427F0[];
extern S_50D8F8 D_L01_002C5600[];
extern u8 D_001425C0[];



extern s32 D_001A5E08[];

s32 func_L01_005119E0(s32 i) {
    if (i == -1) {
        i = D_001A5E08[0];
    }
    if (((*(S_50DA08a *)&D_001425C0).arr[i] + ((S_50DA08 *)&D_L01_002C5600))->h8A == 0) {
        return 1;
    }
    return (*(S_50DA08b *)&D_001427F0).arr[i];
}
/* localdecomp:end func_L01_005119E0 */

/* localdecomp:start func_L01_00511A40 */
extern D_001A4BE0_t D_001A4BE0;
extern void func_L01_005003D0(s32, s32);

void func_L01_00511A40(u128_t *src, s32 a1, f32 f) {
    u128_t *dst = (u128_t *)((char *)&D_001A4BE0 + 0x1B40);
    char *c = (char *)dst - 0x1B40;

    *dst = *src;
    *(f32 *)(c + 0x1B4C) = f;
    *(s32 *)(c + 0x1B50) = a1;
    if ((u32)(*(s32 *)(c + 0x25C4) - 0x66) >= 4) {
        func_L01_005003D0(0x66, 2);
    }
}
/* localdecomp:end func_L01_00511A40 */

LINKER_REMNANT("asm/levels", func_L01_00511A90);

/* localdecomp:start func_L01_00511A98 */
extern int D_001A71A4[];
s32 func_L01_00511A98(void)
{
    s32 state = D_001A71A4[0];
    if (state == 104) goto two;
    if (state > 104) goto right;
    if (state < 102) goto zero;
    goto one;
right:
    if (state != 105) goto zero;
    return 1;
two:
    return 2;
one:
    return 1;
zero:
    return 0;
}
/* localdecomp:end func_L01_00511A98 */

/* localdecomp:start func_L01_00511AE8 */
extern D_001A4BE0_t D_001A4BE0;
extern void func_L01_005003D0(s32, s32);

void func_L01_00511AE8(void) {
    u8 *p = ((u8 *)&D_001A4BE0);

    if (*(f32 *)(p + 0x170) < 0.054000005f) {
        func_L01_005003D0(0, 1);
    } else if (*(s32 *)(p + 0x25C4) == 0x69) {
        func_L01_005003D0(0, 1);
    } else {
        func_L01_005003D0(3, 1);
    }
}
/* localdecomp:end func_L01_00511AE8 */

INCLUDE_ASM("asm/levels", func_L01_00511B50);

/* localdecomp:start func_L01_00512490 */
extern D_001A4BE0_t D_001A4BE0;
extern s32 func_L01_00477190(s32 a0, u8 *a1, u8 *a2, f32 f);
void func_L01_00512490(void) {
    u8 *p = ((u8 *)&D_001A4BE0);
    if (func_L01_00477190(*(s16 *)(p + 10374), p + 128, p + 128, *(f32 *)(p + 644))) {
        *(s16 *)(p + 534) = 4;
    }
}
/* localdecomp:end func_L01_00512490 */

/* localdecomp:start func_L01_005124D8 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_00451DB8(Node_005124D8 *, f32 *, s32, s32, f32);

void func_L01_005124D8(void)
{
    Node_005124D8 *node;

    node = ((Glob_005124D8 *)&D_001A4BE0)->p1340;
    if (node != 0) {
        if (D_L01_001D6694 == 2)
            ((Glob_005124D8 *)&D_001A4BE0)->f2890 = func_0038DAB8(((Glob_005124D8 *)&D_001A4BE0)->f2890, 0.0244346114f);
        else
            ((Glob_005124D8 *)&D_001A4BE0)->f2890 = func_0038DAB8(((Glob_005124D8 *)&D_001A4BE0)->f2890, 0.0418879057f);
        node->color78 = func_0038DBD8(0xd2d2d2, 0x285050,
                                      func_0038D0B0(((Glob_005124D8 *)&D_001A4BE0)->f2890) * 0.5f + 0.5f);
    }
    node = ((Glob_005124D8 *)&D_001A4BE0)->p1344;
    if (node != 0) {
        if (D_L01_001D6694 != 2) {
            f32 limit;
            s32 which;

            limit = func_0038DAB8(((Glob_005124D8 *)&D_001A4BE0)->f2894, 0.0593411946f);
            ((Glob_005124D8 *)&D_001A4BE0)->f2894 = limit;
            which = 0x1ee628;
            if (limit > 0.0f && limit < 1.9198622f) {
                which = 0x1e1ed2;
            }
            node->color78 = func_0038DBD8(node->color78, which, 0.07f);
        } else {
            ((Glob_005124D8 *)&D_001A4BE0)->f2894 = func_0038DAB8(((Glob_005124D8 *)&D_001A4BE0)->f2894, 0.0314159265f);
            node->color78 = func_0038DBD8(0x1e1ed2, 0x1e1e50,
                                          func_0038D0B0(((Glob_005124D8 *)&D_001A4BE0)->f2894) * 0.5f + 0.5f);
        }
    }
    if (((Glob_005124D8 *)&D_001A4BE0)->p1348 != 0) {
        if (D_L01_001D6694 == 2)
            func_L01_00451DB8(((Glob_005124D8 *)&D_001A4BE0)->p1348, &((Glob_005124D8 *)&D_001A4BE0)->f2898, 0xdcdcdc, 0x323232, 0.0314159265f);
        else
            func_L01_00451DB8(((Glob_005124D8 *)&D_001A4BE0)->p1348, &((Glob_005124D8 *)&D_001A4BE0)->f2898, 0xdcdcdc, 0x323232, 0.0488692228f);
    }
    node = ((Glob_005124D8 *)&D_001A4BE0)->p1390;
    if (node != 0) {
        f32 a;
        s32 which;

        a = func_0038DAB8(((Glob_005124D8 *)&D_001A4BE0)->f289C, 0.0593411946f);
        ((Glob_005124D8 *)&D_001A4BE0)->f289C = a;
        which = 0x5a5a5a;
        if (a > 0.0f && a < 1.2217305f) {
            which = 0xaac8aa;
        }
        node->color78 = func_0038DBD8(node->color78, which, 0.15f);
    }
}
/* localdecomp:end func_L01_005124D8 */

/* localdecomp:start func_L01_00512750 */
extern H_50C8E8 D_L01_001E6D80;
extern D_001A4BE0_t D_001A4BE0;
extern s32 D_L01_001D6694;
extern void func_L01_004EAF18(void);
extern void func_L01_004E52E0(s32);
extern void func_L01_004EBDA8(s32);
extern void func_L01_005124D8(void);

#define MOBY_FLAGS(p) (*(u16 *)((u8 *)(p) + 52))

void func_L01_00512750(s32 arg) {
    u8 *p;
    u8 *g;
    u8 *m;
    s32 i;
    u8 *h;

    if (D_L01_001D6694 != 2 && D_L01_001D6694 != 6) {
        return;
    }
    g = ((u8 *)&D_001A4BE0);
    if (*(u8 **)(g + 4768) == 0) {
        func_L01_004EAF18();
    }
    m = ((u8 *)&D_L01_001E6D80);
    for (i = 0; i < *(s16 *)(m + 68); i++) {
        p = ((u8 **)(m + 416))[i];
        if (p != 0 && (*(s16 *)(p + 170) == 1290 || *(s16 *)(p + 170) == 3412)) {
            MOBY_FLAGS(p) |= 0x800;
        }
    }
    func_L01_004E52E0(arg);
    func_L01_004EBDA8(arg);
    func_L01_005124D8();
    h = ((u8 *)&D_001A4BE0);
    if (*(u8 **)(h + 4768) != 0) MOBY_FLAGS(*(u8 **)(h + 4768)) &= ~1;
    if (*(u8 **)(h + 4688) != 0) MOBY_FLAGS(*(u8 **)(h + 4688)) &= ~1;
    if (*(u8 **)(h + 4692) != 0) MOBY_FLAGS(*(u8 **)(h + 4692)) &= ~1;
    if (*(u8 **)(h + 4928) != 0) MOBY_FLAGS(*(u8 **)(h + 4928)) &= ~1;
    if (*(u8 **)(h + 4932) != 0) MOBY_FLAGS(*(u8 **)(h + 4932)) &= ~1;
    if (*(u8 **)(h + 4936) != 0) MOBY_FLAGS(*(u8 **)(h + 4936)) &= ~1;
    if (*(u8 **)(h + 5008) != 0) MOBY_FLAGS(*(u8 **)(h + 5008)) &= ~1;
}
/* localdecomp:end func_L01_00512750 */

/* localdecomp:start func_L01_005128D8 */
extern D_001A4BE0_t D_001A4BE0;

extern u8 *func_003C24B0(s32 a0, s32 a1);
extern void func_L01_004E52E0(s32 a0);
extern void func_L01_004EBDA8(s32 a0);

void func_L01_005128D8(s32 arg0) {
    u8 *g = ((u8 *)&D_001A4BE0);
    u8 *g2;
    u8 *m;
    u8 *p;

    *(s32 *)(g + 4808) = 23;
    if (*(s32 *)(g + 4768) == 0) {
        m = func_003C24B0(1290, 128);
        if (m != 0) {
            *(s16 *)(m + 50) = 32;
            m[49] = 1;
            *(unsigned long *)(m + 56) = 0x20202000000000L;
            *(u16 *)(m + 52) |= 2;
            *(s32 *)(m + 100) = 0;
            p = *(u8 **)(m + 36);
            if (p != 0 && p[6] != 0) {
                m[99] = 16;
            }
            *(u16 *)(m + 52) |= 0x800;
            g2 = ((u8 *)&D_001A4BE0);
            *(u8 **)(g2 + 4768) = m;
            *(s32 *)(g2 + 4804) = 2;
        }
    }
    func_L01_004E52E0(arg0);
    func_L01_004EBDA8(arg0);
}
/* localdecomp:end func_L01_005128D8 */

/* localdecomp:start func_L01_005129A8 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L01_005129A8(char *arg) {
    u8 *obj = (u8 *)arg;
    u8 *g = ((u8 *)&D_001A4BE0);
    f32 x;
    f32 t;
    s32 r;
    u8 *q;

    x = func_0038DAB8(*(f32 *)(g + 0x2810), 0.073303834f);
    *(f32 *)(g + 0x2810) = x;
    t = func_0038D0B0(x) * 0.5f + 0.5f;
    r = func_0038DBD8(0x808C8C8C, 0x80464646, t);
    *(s32 *)(obj + 0x78) = r;
    q = *(u8 **)(g + 0x12A0);
    if (q != 0) {
        *(s32 *)(q + 0x78) = r;
    }
}
/* localdecomp:end func_L01_005129A8 */

/* localdecomp:start func_L01_00512A30 */
extern u8 D_001D5472;
extern u8 D_001D5470;
extern s32 D_001A5E30[];
__asm__(".extern D_L01_001DBD38, 4");
__asm__(".extern D_L01_001DBD3C, 4");
extern f32 D_L01_001DBD38;
extern f32 D_L01_001DBD3C;
extern s32 D_L01_001E13E0;
extern u8 D_L01_001E13E1;
extern f32 D_L01_001E1400;
extern f32 D_L01_001E1404;
extern f32 D_L01_001E1408;
extern Manip_00512A30 D_L01_00251400[];

extern void func_L01_0043A430(char *, s32, void *);
extern void func_L01_005128D8(s32);
extern void func_L01_005129A8(char *);
extern void func_L01_00512750(s32);

void func_L01_00512A30(char *object, int spawn)
{
    Manip_00512A30 *record;
    int i;

    if (D_001D5472)
        D_L01_001DBD38 = 1.57f;
    else
        D_L01_001DBD38 = 0.875f;
    if (D_001D5470)
        D_L01_001DBD3C = 1.8f;
    else
        D_L01_001DBD3C = 1.0f;
    if (D_L01_001E13E1 == 0) {
        func_L01_0043A430(object, 24, &D_L01_001E13E0);
        if (*(short *)(object + 0xAA) == 0xF6B) {
            D_L01_001E1400 = 0.92f;
            (&D_L01_001E1400)[1] = 0.92f;
            D_L01_001E1408 = 0.92f;
        } else {
            D_L01_001E1408 = D_L01_001DBD38;
            D_L01_001E1400 = D_L01_001DBD38 * 0.97f;
            D_L01_001E1404 = D_L01_001DBD38 * 0.97f;
        }
    }
    if (*(short *)(object + 0xAA) == 0xF6B)
        return;
    if (spawn) {
        func_L01_005128D8((s32)object);
        return;
    }
    if (D_001A5E30[0]) {
        record = D_L01_00251400;
        for (i = 0; i < 2; i++, record++) {
            if (record->initialized == 0) {
                func_L01_0043A430(object, i + 22, record);
                record->scale[0] = 0.01f;
                record->scale[1] = 0.01f;
                record->scale[2] = 0.01f;
            }
        }
    }
    func_L01_005129A8(object);
    func_L01_00512750((s32)object);
}
/* localdecomp:end func_L01_00512A30 */

/* localdecomp:start func_L01_00512BE0 */

extern void func_L01_004E52E0(s32);
extern void func_0038D590(void *, void *);
extern void func_003C7DD8(void *);
extern void func_L01_004E5520(void *, void *, s32, s32, s32);
extern u8 D_001A5940[];
extern u8 D_L01_00251680[];
extern u8 D_L01_00251880[];
extern u8 D_L01_00251980[];
extern u8 D_L01_001DBD60[];
extern u8 D_L01_001DBD70[];
extern u8 D_L01_001DBD88[];

void func_L01_00512BE0(s32 arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    u8 *tbl;

    func_L01_004E52E0(arg0);
    tbl = D_001A5940;
    *(u128_t *)(arg1 + 16) = *(u128_t *)tbl;
    func_0038D590(arg1 + 192, tbl - 48);
    func_003C7DD8(arg1);
    func_L01_004E5520(D_L01_001DBD60, D_L01_00251680, *(s32 *)(arg1 + 36), 0, arg0);
    *(u8 **)(arg1 + 88) = D_L01_00251680;
    *(s32 *)(arg1 + 68) = 0;
    *(u8 **)(arg1 + 92) = D_L01_00251680;
    *(s32 *)(arg1 + 64) = 0;
    if (arg2 != 0) {
        *(u128_t *)(arg2 + 16) = *(u128_t *)(tbl - 128);
        func_0038D590(arg2 + 192, tbl - 176);
        func_003C7DD8(arg2);
        func_L01_004E5520(D_L01_001DBD70, D_L01_00251880, *(s32 *)(arg2 + 36), 0, arg0);
        *(u8 **)(arg2 + 88) = D_L01_00251880;
        *(s32 *)(arg2 + 68) = 0;
        *(u8 **)(arg2 + 92) = D_L01_00251880;
        *(s32 *)(arg2 + 64) = 0;
    }
    if (arg3 != 0) {
        *(u128_t *)(arg3 + 16) = *(u128_t *)(tbl - 64);
        func_0038D590(arg3 + 192, tbl - 112);
        func_003C7DD8(arg3);
        func_L01_004E5520(D_L01_001DBD88, D_L01_00251980, *(s32 *)(arg3 + 36), 0, arg0);
        *(u8 **)(arg3 + 88) = D_L01_00251980;
        *(s32 *)(arg3 + 68) = 0;
        *(u8 **)(arg3 + 92) = D_L01_00251980;
        *(s32 *)(arg3 + 64) = 0;
    }
}
/* localdecomp:end func_L01_00512BE0 */
