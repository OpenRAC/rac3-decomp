#include "common.h"

typedef struct {
    u8 *obj;
    s32 col;
    s32 pad8;
    f32 t;
    u8 pad10[16];
} Ent_003153D8;
typedef struct {
    f32 v[4][4];
    u8 pad40[0x10];
    f32 w[4][2];
    unsigned long d70;
    u8 pad78[8];
    unsigned long d80;
} Obj317488;
typedef struct {
    u8 pad0[56];
    s32 w56;
    s32 w60;
} S_00142660;
typedef struct {
    u8 pad[8];
    s32 x8;
} S_142660;
typedef struct { u8 pad[20]; s32 id; u8 pad2[8]; } E_31ABE0;
typedef int u128_t __attribute__((mode(TI)));

typedef struct { u8 pad[0x1C]; s32 active; u8 pad20[0x10]; } E_L01_00272540_00318408;
typedef struct { u8 pad[0x44]; s32 active; u8 pad48[8]; } E_L01_00272780_00318408;
typedef struct { u8 pad0[0x25C0]; s32 x25C0; u8 pad25C4[0x2850 - 0x25C4]; s32 x2850; } G_00318408;

INCLUDE_ASM("asm/levels", func_L01_00314158);

INCLUDE_ASM("asm/levels", func_L01_00314620);

INCLUDE_ASM("asm/levels", func_L01_00314C90);

/* localdecomp:start func_L01_00315350 */
#include "vu0.h"
typedef union { vu0_q q; f32 f[4]; } V_00315350;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
void func_L01_00315350(u8 *m) {
    extern f32 func_003C3D30(u8 *, s32, s32, f32);
    extern s32 func_003C2B88(u8 *, s32);
    extern void func_00382580(f32 *, f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
    extern void func_L01_00475770(f32 *, u8 *, s32, u8, f32, f32);
    V_00315350 a, b, c;
    f32 light = func_003C3D30(m + 0x10, 0, 0, 0.5f);
    s32 count = func_003C2B88(m, 0);
    s32 pass, left;
    f32 size;
    V_00315350 *scratch;
    for (pass = 0; pass < 5; pass++) {
        if (count != 0) {
            scratch = (V_00315350 *)0x70000000; /* EE scratchpad results. */
            for (left = 0; left < count; left++, scratch += 2) {
                if (scratch[1].f[3] == 0.0f) {
                    a.q = scratch[0].q;
                    a.f[3] = 1.0f;
                    func_00382580(b.f, 0.0f, scratch[0].f[3]);
                    vec_add_ab(&a, &a, &b);
                    size = func_003824E0(0.7f, 1.0f) * scratch[0].f[3];
                    func_L01_00475770(a.f, D_L01_001D66B0, 125, (u8)func_00382468(2), size, light);
                } else {
                    a.q = scratch[0].q;
                    b.q = scratch[1].q;
                    a.f[3] = 1.0f;
                    b.f[3] = 1.0f;
                    func_0038CDF8(c.f, a.f, b.f, func_003824E0(0.0f, 1.0f));
                    c.f[0] += func_003824E0(-scratch[0].f[3] * 0.4f, scratch[0].f[3] * 0.4f);
                    c.f[1] += func_003824E0(-scratch[0].f[3] * 0.4f, scratch[0].f[3] * 0.4f);
                    c.f[2] += func_003824E0(-scratch[0].f[3] * 0.4f, scratch[0].f[3] * 0.4f);
                    size = func_003824E0(0.7f, 1.0f) * scratch[0].f[3];
                    func_L01_00475770(c.f, D_L01_001D66B0, 125, (u8)func_00382468(2), size, light);
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00315350 */

/* localdecomp:start func_L01_003155A8 */
#include "vu0.h"
typedef struct { vu0_v4 a,b; } Scratch_003155A8;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
void func_L01_003155A8(u8 *m) {
    extern f32 func_003C3D30(void *, s32, s32, f32);
    extern s32 func_003C2B88(void *, s32);
    extern void func_00382580(void *, f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern void func_L01_00475F28(void *, void *, s32, u8, f32, f32);
    vu0_v4 a,b,c;
    f32 f=func_003C3D30(m+0x10,0,0,0.5f);
    s32 count=func_003C2B88(m,0);
    s32 i,n;
    Scratch_003155A8 *p;
    for(i=0;i<5;i++) {
        if(count) {
            p=(Scratch_003155A8 *)0x70000000;
            for(n=0;n<count;n++,p++) {
                f32 size;
                if(p->b.w==0.0f) {
                    *(vu0_q *)&a=*(vu0_q *)&p->a;
                    a.w=1.0f;
                    func_00382580(&b,0.0f,p->a.w);
                    vec_add_ab(&a,&a,&b);
                    size=func_003824E0(0.7f,1.0f)*p->a.w;
                    func_L01_00475F28(&a,D_L01_001D66B0,125,(u8)func_00382468(2),size,f);
                } else {
                    *(vu0_q *)&a=*(vu0_q *)&p->a;
                    *(vu0_q *)&b=*(vu0_q *)&p->b;
                    a.w=1.0f;
                    b.w=1.0f;
                    func_0038CDF8(&c,&a,&b,func_003824E0(0.0f,1.0f));
                    c.x+=func_003824E0(-p->a.w*0.4f,p->a.w*0.4f);
                    c.y+=func_003824E0(-p->a.w*0.4f,p->a.w*0.4f);
                    c.z+=func_003824E0(-p->a.w*0.4f,p->a.w*0.4f);
                    size=func_003824E0(0.7f,1.0f)*p->a.w;
                    func_L01_00475F28(&c,D_L01_001D66B0,125,(u8)func_00382468(2),size,f);
                }
            }
        }
    }
}
/* localdecomp:end func_L01_003155A8 */

/* localdecomp:start func_L01_00315800 */

extern Ent_003153D8 D_L01_00271B40[];
extern u8 **func_L01_00448FB8(u8 *);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);

void func_L01_00315800(s32 i, s32 a1) {
    s32 a;
    u8 **v;
    s32 c;
    s32 g;
    s32 b;

    a = (s32)(D_L01_00271B40[i].t * 96.0f);
    D_L01_00271B40[i].obj[35] = a;
    v = func_L01_00448FB8(D_L01_00271B40[i].obj);
    if (v != 0 && *v != 0) {
        (*v)[35] = a;
    }
    c = func_0038DBD8(a1, D_L01_00271B40[i].col, D_L01_00271B40[i].t);
    b = (c >> 16) & 0xFF;
    g = (c >> 8) & 0xFF;
    func_L01_0043B9E8(D_L01_00271B40[i].obj, c & 0xFF, g, b);
}
/* localdecomp:end func_L01_00315800 */

/* localdecomp:start func_L01_003158D0 */
extern Ent_003153D8 D_L01_00271B40[];
extern s32 D_L01_001E1740;
extern void func_0038CBA0(void *, s32);

void func_L01_003158D0(void) {
    func_0038CBA0(((u8 *)&D_L01_00271B40), 2048);
    D_L01_001E1740 = 0;
}
/* localdecomp:end func_L01_003158D0 */

/* localdecomp:start func_L01_00315900 */
extern u8 *D_L01_001E173C;
extern s32 D_L01_001E1740;
extern u8 *func_003C24B0(s32, s32);
extern void func_003C2880(u8 *);
extern void func_003C6FB0(u8 *, s32 *, s32 *, s32 *);

void func_L01_00315900(u8 *a0, s32 a1, void (*a2)(u8 *)) {
    u8 *p = D_L01_001E173C;
    s32 x;
    s32 y;
    s32 z;
    s32 n;
    s32 count;

    if (p == 0 || *(s16 *)(p + 0xAA) != 0xC41 || p[0x20] == 0xFE || p[0x20] == 0xFD) {
        u8 *q = func_003C24B0(0xC41, 0x80);
        D_L01_001E173C = q;
        if (q != 0) {
            q[0x30] = 0xFF;
        } else {
            func_003C2880(a0);
        }
    }
    count = D_L01_001E1740;
    *(u16 *)(a0 + 0x34) |= 2;
    *(s32 *)(a0 + 0x98) = 0;
    *(s32 *)(a0 + 0x48) = 0;
    *(s32 *)(a0 + 0x44) = 0;
    if (count < 0x40) {
        func_003C6FB0(a0, &x, &y, &z);
        n = D_L01_001E1740;
        D_L01_00271B40[n].obj = a0;
        D_L01_00271B40[n].col =(z << 16) | (y << 8) | x;
        D_L01_00271B40[n].pad8 = a1;
        D_L01_00271B40[n].t = 1.0f;
        *(void (**)(u8 *))D_L01_00271B40[n].pad10 = a2;
        D_L01_001E1740 = n + 1;
    } else if (a2 != 0) {
        a2(a0);
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L01_00315900 */

INCLUDE_ASM("asm/levels", func_L01_00315A60);

INCLUDE_ASM("asm/levels", func_L01_003163D0);

/* localdecomp:start func_L01_00316DA0 */
#include "vu0.h"
extern void func_0038CE20(f32 *, f32 *, f32);

void func_L01_00316DA0(vu0_v4 *a0, vu0_v4 *a1, vu0_v4 *a2, f32 t) {
    vu0_v4 d;

    if (t == 0.0f) {
        *(vu0_q *)a0 = *(vu0_q *)a1;
    } else if (t == 1.0f) {
        *(vu0_q *)a0 = *(vu0_q *)a2;
    } else {
        vec_sub_ba(&d, a2, a1);
        func_0038CE20((f32 *)&d, (f32 *)&d, t);
        vec_add_ab(a0, a1, &d);
    }
}
/* localdecomp:end func_L01_00316DA0 */

/* localdecomp:start func_L01_00316E38 */
#include "vu0.h"
void func_L01_00316E38(vu0_v4 *out, vu0_v4 *p, vu0_v4 *q, vu0_v4 *r, vu0_v4 *s, f32 t) {
    f32 t2,t3,a,b,c;
    if(t==0.0f) { *(vu0_q *)out=*(vu0_q *)p; return; }
    if(t==1.0f) { *(vu0_q *)out=*(vu0_q *)q; return; }
    t2=t*t;
    t3=t2*t;
    a=(s->x-q->x)-(r->x-p->x);
    b=(r->x-p->x)-a;
    c=q->x-r->x;
    out->x=a*t3+b*t2+c*t+p->x;
    a=(s->y-q->y)-(r->y-p->y);
    b=(r->y-p->y)-a;
    c=q->y-r->y;
    out->y=a*t3+b*t2+c*t+p->y;
    a=(s->z-q->z)-(r->z-p->z);
    b=(r->z-p->z)-a;
    c=q->z-r->z;
    out->z=a*t3+b*t2+c*t+p->z;
    out->w=0.0f;
}
/* localdecomp:end func_L01_00316E38 */

/* localdecomp:start func_L01_00316F50 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L01_00316F50(s32 a0, f32 *e, s32 n)
{
    s32 i;
    f32 *p;

    for (i = 0; i < n; i++) {
        p = &e[i * 32];
        p[0] = func_0038DAB8(p[0], p[3]);
        p[1] = func_0038DAB8(p[1], p[4]);
        p[2] = func_0038DAB8(p[2], p[5]);
        p[9] = func_0038DAB8(p[9], p[12]);
        p[10] = func_0038DAB8(p[10], p[13]);
        p[11] = func_0038DAB8(p[11], p[14]);
        p[20] = func_0038D098(p[0]) * p[6];
        p[21] = func_0038D0B0(p[1]) * p[7];
        p[22] = -func_0038D0B0(p[2]) * p[8];
        p[24] = func_0038D098(p[9]) * p[15];
        p[25] = func_0038D0B0(p[10]) * p[16];
        p[26] = -func_0038D0B0(p[11]) * p[17];
    }
}
/* localdecomp:end func_L01_00316F50 */

INCLUDE_ASM("asm/levels", func_L01_00317070);

LINKER_REMNANT("asm/levels", func_L01_00317230);

/* localdecomp:start func_L01_00317238 */
#include "vu0.h"
void func_L01_00317238(u8 *object, vu0_v4 *center, f32 *out, f32 scale) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    /* Retail reserves 0xD0 bytes for this scratch buffer, using its first two vectors. */
    vu0_v4 points[13];
    vu0_v4 a, b;
    vu0_v4 *p = points;
    s32 i;
    f32 angle = 0.0f;
    for (i = 1; i >= 0; i--) {
        angle = func_0038DAB8(angle, 0.5711987018585205f);
        p->w = 0.0f;
        p->y = func_0038D098(angle) * scale;
        p->x = 0.0f;
        p->z = -func_0038D0B0(angle) * scale;
        func_0038D000(p, p, object + 0xC0);
        vec_add_ab(p, p, center);
        p++;
    }
    vec_sub_ba(&a, &points[0], center);
    vec_sub_ba(&b, &points[1], center);
    func_0038CE90(out, (f32 *)&a, (f32 *)&b);
    func_0038CF68(out, out, 1.0f);
}
/* localdecomp:end func_L01_00317238 */

/* localdecomp:start func_L01_00317370 */
void func_L01_00317370(vu0_v4 *p, s32 i) {
    vu0_v4 d;

    vec_sub_ab(&d, &p[i - 2], &p[i - 3]);
    vec_add_ab(&p[i - 1], &p[i - 2], &d);
}
/* localdecomp:end func_L01_00317370 */

/* localdecomp:start func_L01_003173B0 */
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(s32, s32, s32, s32, f32, f32, f32);

void func_L01_003173B0(s32 unused, s32 target, u32 color, s32 n, f32 scale) {
    f32 size;
    color |= func_00382498(n >> 1, n) << 24;
    size = func_003824E0(scale * 0.75f, scale);
    size = size + size;
    func_003D9508(target, 44, color, 1, size, 0.08f, func_00382538());
}
/* localdecomp:end func_L01_003173B0 */

INCLUDE_ASM("asm/levels", func_L01_00317440);

/* localdecomp:start func_L01_003178B8 */

void func_L01_003178B8(Obj317488 *o) {
    o->d80 = 0xFF9000000260;
    o->d70 = 0;
    o->w[0][0] = 0;
    o->w[1][0] = 0;
    o->w[2][0] = 1.0f;
    o->w[3][0] = 1.0f;
    o->w[0][1] = 0;
    o->w[1][1] = 1.0f;
    o->w[2][1] = 0;
    o->w[3][1] = 1.0f;
    o->v[0][2] = -2.0f;
    o->v[1][2] = 2.0f;
    o->v[2][2] = -2.0f;
    o->v[3][2] = 2.0f;
    o->v[0][1] = -2.0f;
    o->v[1][1] = -2.0f;
    o->v[2][1] = 2.0f;
    o->v[3][1] = 2.0f;
    o->v[0][0] = 0;
    o->v[1][0] = 0;
    o->v[2][0] = 0;
    o->v[3][0] = 0;
    o->v[0][3] = 1.0f;
    o->v[1][3] = 1.0f;
    o->v[2][3] = 1.0f;
    o->v[3][3] = 1.0f;
}
/* localdecomp:end func_L01_003178B8 */

/* localdecomp:start func_L01_00317948 */
typedef struct {
    u8 pad0[0x30];
    vu0_v4 v30;
} R_00317948;

extern void func_003CA4A0(u8 *, s32, s32 *, void *);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_0038D000(void *, void *, void *);

void func_L01_00317948(u8 *obj, s32 a1, f32 *out, void *offs) {
    R_00317948 r;
    s32 a = a1;
    f32 s = *(f32 *)(obj + 0x2C) * 0.0009765625f;

    func_003CA4A0(obj, 1, &a, &r);
    func_0038CE20(out, &r.v30.x, s);
    vec_add_ba(out, out, offs);
    func_0038D000(out, out, obj + 0xC0);
    vec_add_ba(out, out, obj + 0x10);
}
/* localdecomp:end func_L01_00317948 */

/* localdecomp:start func_L01_003179F0 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
extern vu0_v4 D_001A4C90;
extern s32 D_L01_001D673C;
extern f32 D_L01_001DC7C4,D_L01_001DC7C8,D_L01_001DC7CC,D_L01_001DC7D0,D_L01_001DC7D4,D_L01_001DC7D8;
__asm__(".extern D_L01_001DC7C4, 4");
__asm__(".extern D_L01_001DC7C8, 4");
__asm__(".extern D_L01_001DC7CC, 4");
__asm__(".extern D_L01_001DC7D0, 4");
__asm__(".extern D_L01_001DC7D4, 4");
__asm__(".extern D_L01_001DC7D8, 4");
void func_L01_003179F0(vu0_v4 *position, s32 count, f32 scale) {
    extern void func_0038CF68(f32 *,f32 *,f32);
    extern f32 func_0038CE68(void *,void *);
    extern void func_0038CE20(f32 *,f32 *,f32);
    extern f32 func_003824E0(f32,f32);
    extern s32 func_00382468(s32);
    extern void func_0038D890(void *,void *,void *,f32);
    extern u8 *func_L01_0046B458(void *,s32,f32,f32,u32,s32,s32,void *,f32,s32);
    vu0_v4 velocity, direction, axis, temp;
    f32 size, angle, brightness;
    s32 sign;
    s32 i;
    u8 *particle;
    vec_sub_ab(&direction,&D_L01_001E29C0,position);
    if (!D_L01_001D673C) {
        direction.z=0;
        axis.x=0;
        axis.y=0;
        axis.z=1;
        axis.w=1;
    } else {
        vec_sub_ab(&temp,position,&D_001A4C90);
        func_0038CF68((f32 *)&axis,(f32 *)&temp,1.0f);
        func_0038CE20((f32 *)&temp,(f32 *)&axis,func_0038CE68(&axis,&direction));
        vec_sub_ab(&direction,&direction,&temp);
    }
    for (i=0;i<count;i++) {
        size=func_003824E0(D_L01_001DC7D4,D_L01_001DC7D8);
        sign=func_00382468(2);
        if (!sign) sign--;
        angle=func_003824E0(-1.0471976f,1.0471976f);
        func_0038D890(&velocity,&direction,&axis,angle);
        func_0038CF68((f32 *)&velocity,(f32 *)&velocity,func_003824E0(D_L01_001DC7C4,D_L01_001DC7C8)*0.020000001415610313f);
        velocity.z=func_003824E0(D_L01_001DC7CC,D_L01_001DC7D0)*0.020000001415610313f;
        qzero(&velocity);
        brightness=scale*1.44f;
        particle=func_L01_0046B458(position,50,size*0.1f,size,0x7F7F2020,0,sign,&velocity,brightness,1);
        if(particle) particle[9]=116;
        particle=func_L01_0046B458(position,50,size*0.07f,size*0.7f,0x7FFF4040,1,-sign,&velocity,brightness,1);
        if(particle) particle[9]=116;
    }
}
/* localdecomp:end func_L01_003179F0 */

/* localdecomp:start func_L01_00317C48 */

extern u8 D_001A4C60[];
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern s32 D_L01_001EFC80[][3];
extern s32 D_L01_001EFD40[][3];
extern S_00142660 D_00142660;
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00400430(s32);

void func_L01_00317C48(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 104);
    u8 *q;
    s32 r;
    s32 sh;
    u8 v;

    if (a0[32] == 0) {
        a0[48] = 255;
        a0[32]++;
    }
    if (func_00382380(D_001A4C60, p[1], 0) == 0) {
        return;
    }
    D_001A4C60[9591] = a0[176];
    if (p[2] != 0) {
        return;
    }
    if ((D_001BBC40[a0[176] + D_001D545C * 16] >> (a0[177] * 2)) & 3) {
        return;
    }
    p[2] = 1;
    r = func_L01_00400430(a0[176]);
    q = &D_001BBC40[(a0[176] & 15) + D_001D545C * 16];
    sh = (a0[177] & 3) * 2;
    v = *q;
    if ((v >> sh) & 3) {
        return;
    }
    *q = (v & ~(3 << sh)) | (r << sh);
    D_00142660.w56 += D_L01_001EFC80[a0[176] & 15][a0[177] & 3];
    D_00142660.w60 += D_L01_001EFD40[a0[176] & 15][a0[177] & 3];
}
/* localdecomp:end func_L01_00317C48 */

INCLUDE_ASM("asm/levels", func_L01_00317DF0);

/* localdecomp:start func_L01_00318408 */
__asm__(".extern D_L01_001DC7DC, 4");

extern G_00318408 D_001A4BE0;
extern s32 D_L01_001DC7DC;
extern E_L01_00272540_00318408 D_L01_00272540[];
extern E_L01_00272780_00318408 D_L01_00272780[];
extern s32 func_L01_00318818(void);
extern u8 *func_003C24B0(s32, s32);
extern s32 func_L01_00424CB0(s32, f32, f32, f32, f32, f32);

void func_L01_00318408(void) {
    u8 *object;
    u8 *state;
    s32 flag;
    s32 a;
    s32 t;
    s32 i;

    flag = 0;
    if (func_L01_00318818() == 0) {
        s32 x = ((S_142660 *)&D_00142660)->x8;
        a = x + 1;
        flag = 1;
        D_001A4BE0.x2850 += (s32)((f32)a * 0.33333334f);
        if (a < D_001A4BE0.x2850)
            D_001A4BE0.x2850 = a;
    } else {
        D_001A4BE0.x2850 = ((S_142660 *)&D_00142660)->x8 + 1;
    }
    if (D_L01_001DC7DC)
        return;
    object = func_003C24B0(0xCE7, 0x80);
    if (!object)
        return;
    state = *(u8 **)(object + 0x68);
    object[0x30] = 0xFF;
    *(u16 *)(object + 0x32) = 0xFF;
    *(s32 *)(state + 0x18) = flag;
    object[0x20] = 0;
    for (i = 11; i >= 0; i--)
        D_L01_00272540[i].active = 0;
    for (i = 63; i >= 0; i--)
        D_L01_00272780[i].active = 0;
    *(s32 *)(state + 0x10) = func_L01_00424CB0(D_001A4BE0.x25C0 + 0x10, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    *(u8 **)(state + 8) = func_003C24B0(0xCEB, 0x80);
    *(u8 **)(state + 12) = func_003C24B0(0xCEC, 0x80);
    if (*(u8 **)(state + 8)) {
        **(s32 **)(*(u8 **)(state + 8) + 0x68) = 0;
        (*(u8 **)(state + 8))[0x30] = 0xFF;
        *(s16 *)(*(u8 **)(state + 8) + 0x32) = 0xFF;
    }
    if (*(u8 **)(state + 12)) {
        **(s32 **)(*(u8 **)(state + 12) + 0x68) = 0;
        (*(u8 **)(state + 12))[0x30] = 0xFF;
        *(s16 *)(*(u8 **)(state + 12) + 0x32) = 0xFF;
    }
    D_L01_001DC7DC = (s32)object;
}
/* localdecomp:end func_L01_00318408 */

/* localdecomp:start func_L01_003185E8 */
extern s32 D_L01_001DC7DC;

void func_L01_003185E8(void) { D_L01_001DC7DC = 0; }
/* localdecomp:end func_L01_003185E8 */

/* localdecomp:start func_L01_003185F0 */
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern vu0_v4 D_L01_00273FA0[];
extern u8 D_001A4CC0[];

void func_L01_003185F0(void) {
    s32 i;
    f32 speed;
    f32 yaw;
    f32 tilt;
    vu0_v4 *p = D_L01_00273FA0;

    for (i = 24; i >= 0; i--) {
        speed = func_003824E0(0.01f, 7.0f);
        yaw = func_00382538();
        tilt = func_003824E0(0.0f, 3.1415927f);
        func_00382760(p, speed, yaw, tilt);
        vec_add_ab(p, p, D_001A4CC0);
        p++;
    }
}
/* localdecomp:end func_L01_003185F0 */

INCLUDE_ASM("asm/levels", func_L01_003186A8);

/* localdecomp:start func_L01_00318818 */
extern S_00142660 D_00142660;

extern s32 D_L01_002AC240[];

s32 func_L01_00318818(void) {
    S_142660 *g = &(*(S_142660 *)&D_00142660);
    s32 *t;
    s32 r = 0;
    s32 i = 0;

    for (t = D_L01_002AC240; i < 19; i++, t++) {
        if (g->x8 < *t) break;
        if (g->x8 == *t) {
            r = 1;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_L01_00318818 */

/* localdecomp:start func_L01_00318878 */
#include "vu0.h"
extern G_00318408 D_001A4BE0;
extern E_L01_00272540_00318408 D_L01_00272540[];
void func_L01_00318878(s32 owner) {
    extern f32 func_00382538(void);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    extern void func_0038CF68(f32 *, f32 *, f32);
    vu0_v4 offset, position, end;
    E_L01_00272540_00318408 *p;
    p = D_L01_00272540;
    do {
        if (p->active == 0) {
            p->active = owner;
            *(f32 *)((u8 *)p + 0x10) = func_00382538();
            *(f32 *)((u8 *)p + 0x14) = func_L01_00443A18(1200.0f, 1400.0f) * 0.017453292f * 0.020000001415610313f;
            *(s32 *)((u8 *)p + 0x18) = 31;
            *(f32 *)((u8 *)p + 0x20) = func_003824E0(0.3f, 0.4f);
            func_L01_004C7D98((void *)(D_001A4BE0.x25C0 + 0x10), &offset);
            *(vu0_q *)&position = *(vu0_q *)(D_001A4BE0.x25C0 + 0x10);
            vec_add_ab(&end, &position, &offset);
            func_0038CE90((f32 *)&position, (f32 *)&position, (f32 *)&end);
            func_0038CF68((f32 *)p, (f32 *)&position, *(f32 *)((u8 *)p + 0x20));
            break;
        }
        p++;
    } while ((s32)p < (s32)(D_L01_00272540 + 12));
}
/* localdecomp:end func_L01_00318878 */

INCLUDE_ASM("asm/levels", func_L01_003189B0);

INCLUDE_ASM("asm/levels", func_L01_00318AF8);

INCLUDE_ASM("asm/levels", func_L01_00318C30);

INCLUDE_ASM("asm/levels", func_L01_00318D80);

INCLUDE_ASM("asm/levels", func_L01_00318E68);

/* localdecomp:start func_L01_00318FB8 */
void func_L01_00318FB8(u8 *p)
{
    *(unsigned long *)(p + 128) = 0xFF9000000260;
    *(unsigned long *)(p + 112) = 0;
    *(f32 *)(p + 80) = 0.0f;
    *(f32 *)(p + 84) = 0.0f;
    *(f32 *)(p + 88) = 1.0f;
    *(f32 *)(p + 92) = 0.0f;
    *(f32 *)(p + 96) = 0.0f;
    *(f32 *)(p + 100) = 1.0f;
    *(f32 *)(p + 104) = 1.0f;
    *(f32 *)(p + 108) = 1.0f;
    *(f32 *)(p + 8) = -1.0f;
    *(f32 *)(p + 24) = 1.0f;
    *(f32 *)(p + 40) = -1.0f;
    *(f32 *)(p + 56) = 1.0f;
    *(f32 *)(p + 4) = -1.0f;
    *(f32 *)(p + 36) = 1.0f;
    *(f32 *)(p + 52) = 1.0f;
    *(f32 *)(p + 0) = 0.0f;
    *(f32 *)(p + 16) = 0.0f;
    *(f32 *)(p + 32) = 0.0f;
    *(f32 *)(p + 48) = 0.0f;
    *(f32 *)(p + 12) = 1.0f;
    *(f32 *)(p + 28) = 1.0f;
    *(f32 *)(p + 20) = -1.0f;
    *(f32 *)(p + 44) = 1.0f;
    *(f32 *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_00318FB8 */

/* localdecomp:start func_L01_00319040 */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L01_00319040(f32 *m, f32 s) {
    func_0038CE20(m, m, s);
    func_0038CE20(m + 4, m + 4, s);
    func_0038CE20(m + 8, m + 8, s);
    func_0038CE20(m + 12, m + 12, s);
}
/* localdecomp:end func_L01_00319040 */

INCLUDE_ASM("asm/levels", func_L01_003190A8);

INCLUDE_ASM("asm/levels", func_L01_00319258);

/* localdecomp:start func_L01_00319480 */
#include "vu0.h"
typedef struct {
    vu0_v4 first, second, origin, current, end;
    f32 phase[3], rate[3], scale[3];
    f32 phase2[3], rate2[3], scale2[3];
    s32 delay;
    void *owner;
    s32 timer, duration, finished, pad;
} Arc_00319480;
extern u8 D_L01_00273B80[0x420];
static __inline__ Arc_00319480 *entry_00319480(u32 base, s32 index) {
    return (Arc_00319480 *)(index * sizeof(Arc_00319480) + base);
}
void func_L01_00319480(void *owner) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern s32 func_0038CAD0(void *);
    s32 i;
    Arc_00319480 *e;
    vu0_v4 delta;
    for (i = 0; i < 6; i++) {
        e = entry_00319480((u32)D_L01_00273B80, i);
        if (e->owner != owner) continue;
        vec_sub_ba(&delta, &e->end, &e->origin);
        *(vu0_q *)&e->origin = *(vu0_q *)D_001A4CC0;
        vec_add_ba(&e->end, &e->origin, &delta);
        if (e->timer) {
            e->phase[0] = func_0038DAB8(e->phase[0], e->rate[0] * 100.0f);
            e->phase[1] = func_0038DAB8(e->phase[1], e->rate[1] * 100.0f);
            e->phase[2] = func_0038DAB8(e->phase[2], e->rate[2] * 100.0f);
            e->phase2[0] = func_0038DAB8(e->phase2[0], e->rate2[0] * 100.0f);
            e->phase2[1] = func_0038DAB8(e->phase2[1], e->rate2[1] * 100.0f);
            e->phase2[2] = func_0038DAB8(e->phase2[2], e->rate2[2] * 100.0f);
        } else {
            e->phase[0] = func_0038DAB8(e->phase[0], e->rate[0] * 50.0f);
            e->phase[1] = func_0038DAB8(e->phase[1], e->rate[1] * 50.0f);
            e->phase[2] = func_0038DAB8(e->phase[2], e->rate[2] * 50.0f);
            e->phase2[0] = func_0038DAB8(e->phase2[0], e->rate2[0] * 50.0f);
            e->phase2[1] = func_0038DAB8(e->phase2[1], e->rate2[1] * 50.0f);
            e->phase2[2] = func_0038DAB8(e->phase2[2], e->rate2[2] * 50.0f);
        }
        e->first.x = func_0038D098(e->phase[0]) * e->scale[0];
        e->first.y = func_0038D0B0(e->phase[1]) * e->scale[1];
        e->first.z = -func_0038D0B0(e->phase[2]) * e->scale[2];
        e->second.x = func_0038D098(e->phase2[0]) * e->scale2[0];
        e->second.y = func_0038D0B0(e->phase2[1]) * e->scale2[1];
        e->second.z = -func_0038D0B0(e->phase2[2]) * e->scale2[2];
        func_0038CDF8(&e->current, &e->origin, &e->end, 1.0f - (f32)e->timer / (f32)e->duration);
        if (func_0038CAD0(&e->timer)) {
            if (!e->finished) e->finished = 1;
            if (func_0038CAD0(&e->delay)) e->owner = 0;
        }
    }
}
/* localdecomp:end func_L01_00319480 */

INCLUDE_ASM("asm/levels", func_L01_00319718);

INCLUDE_ASM("asm/levels", func_L01_00319880);

/* localdecomp:start func_L01_00319A48 */
void func_L01_00319A48(vu0_v4 *base, s32 i) {
    vu0_v4 tmp;
    vec_sub_ab(&tmp, &base[i - 2], &base[i - 3]);
    vec_add_ab(&base[i - 1], &base[i - 2], &tmp);
}
/* localdecomp:end func_L01_00319A48 */

INCLUDE_ASM("asm/levels", func_L01_00319A88);

INCLUDE_ASM("asm/levels", func_L01_00319F00);

/* localdecomp:start func_L01_0031A518 */
void func_L01_0031A518(u128_t *v, s32 *w, u128_t *dv, s32 *dw, s32 *n) {
    if (*n < 70) {
        dv[*n] = *v;
        dw[*n] = *w;
        (*n)++;
    }
}
/* localdecomp:end func_L01_0031A518 */

INCLUDE_ASM("asm/levels", func_L01_0031A560);

/* localdecomp:start func_L01_0031A7D8 */
extern u8 func_L01_0031A820[];
extern void func_L01_00404A10_0031A7D8(void *a0, u8 *a1);
void func_L01_0031A7D8(u8 *a0) {
    if (a0[32] == 0) {
        a0[32] = 1;
        *(f32 *)(a0 + 192) = 1.0f;
        *(f32 *)(a0 + 212) = 1.0f;
        *(f32 *)(a0 + 232) = 1.0f;
    }
    func_L01_00404A10_0031A7D8(func_L01_0031A820, a0);
}
/* localdecomp:end func_L01_0031A7D8 */

INCLUDE_ASM("asm/levels", func_L01_0031A820);

/* localdecomp:start func_L01_0031AAA8 */
extern u8 func_L01_0031AAF0[];
extern void func_L01_00404A10_0031AAA8(void *a0, u8 *a1);
void func_L01_0031AAA8(u8 *a0) {
    if (a0[32] == 0) {
        a0[32] = 1;
        *(f32 *)(a0 + 192) = 1.0f;
        *(f32 *)(a0 + 212) = 1.0f;
        *(f32 *)(a0 + 232) = 1.0f;
    }
    func_L01_00404A10_0031AAA8(func_L01_0031AAF0, a0);
}
/* localdecomp:end func_L01_0031AAA8 */

INCLUDE_ASM("asm/levels", func_L01_0031AAF0);

INCLUDE_ASM("asm/levels", func_L01_0031AD78);

/* localdecomp:start func_L01_0031AFB8 */
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);

void func_L01_0031AFB8(u8 *s) {
    u8 *m;
    u8 *q;

    func_L01_0043B9E8(*(u8 **)(s + 20), s[4], s[5], s[6]);
    m = *(u8 **)(s + 20);
    if (*(u16 *)(m + 52) & 0x20) {
        q = *(u8 **)(*(u8 **)(m + 104) + 16);
        if (q != 0 && *(s16 *)q != 0) {
            q[4] = s[4];
            q[5] = *(s32 *)(s + 4) >> 8;
            q[6] = *(s32 *)(s + 4) >> 16;
        }
    }
}
/* localdecomp:end func_L01_0031AFB8 */

/* localdecomp:start func_L01_0031B038 */
extern E_31ABE0 D_L01_00274580[];
s32 func_L01_0031B038(s32 a0) {
    s32 r = -1;
    s32 i;
    for (i = 0; i < 30; i++) {
        if (D_L01_00274580[i].id == a0) {
            r = i;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_L01_0031B038 */

INCLUDE_ASM("asm/levels", func_L01_0031B090);

/* localdecomp:start func_L01_0031B358 */
__asm__(".extern D_L01_001DC7F8, 4");
extern s32 D_L01_001DC7F8;
extern u8 *func_003C24B0(s32, s32);

u8 *func_L01_0031B358(void)
{
    u8 *p = func_003C24B0(0xD04, 0x80);

    if (p != 0) {
        s32 v = 0xFF;

        D_L01_001DC7F8 = (s32)p;
        p[0x20] = 1;
        *(u16 *)(p + 0x32) = v;
        p[0x30] = v;
    }
    return p;
}
/* localdecomp:end func_L01_0031B358 */

/* localdecomp:start func_L01_0031B3A0 */
typedef struct {
    f32 per_second; /* damage a second */
    s32 seconds;    /* how long it lasts */
    u8 pad8[8];
} AcidRow_0031B3A0;

__asm__(".extern D_L01_001DC7F8, 4");
__asm__(".extern D_L01_001DC800, 8");
__asm__(".extern D_L01_001DC810, 8");
__asm__(".extern D_L01_001DC818, 8");
extern s32 D_L01_001DC7F8;
extern u8 D_L01_001DC800[8];
extern u8 D_L01_001DC810[8];
extern u8 D_L01_001DC818[8];
extern E_31ABE0 D_L01_00274580[];
/* the per-item tables: bank 0, then bank 1 (the gun at V3 or V4) */
extern AcidRow_0031B3A0 D_L01_00274940[][204];
extern u8 *D_L01_001E1778;
extern u8 *D_L01_001E177C;
extern u8 *D_L01_001E1780;
extern s16 D_L01_001E1784;
extern s32 D_L01_001E1788;
extern f32 D_L01_001E178C;
extern u8 *func_L01_0031B358(void);

/* acid_mod_tables_init: at the level start, empties the acid slots and fills the acid mod's
   per-item tables (damage per second, seconds) in two banks; only the Plasma Coil (0x10,
   0xA0), Lava Gun (0x11, 0xA1) and Bouncer (0x13, 0xA6) have numbers. */
void func_L01_0031B3A0(void)
{
    s32 i;

    /* the 30 slots: none has a target */
    for (i = 0; i < 30; i++) {
        D_L01_00274580[i].id = 0;
    }
    D_L01_001DC7F8 = 0;
    /* its moby (class 0xD04), which D_L01_001DC7F8 keeps; called with a 0 it ignores */
    ((u8 *(*)(s32))func_L01_0031B358)(0);
    /* the acid's look (0x1E1778-0x1E178C): three tables, a count of 3, 30 (the slot count
       the loop leaves in i) and 0.96 */
    D_L01_001E1784 = 3;
    D_L01_001E1788 = i;
    D_L01_001E178C = 0.96f;
    D_L01_001E1778 = D_L01_001DC800;
    D_L01_001E177C = D_L01_001DC810;
    D_L01_001E1780 = D_L01_001DC818;
    for (i = 0; i < 204; i++) {
        D_L01_00274940[0][i].per_second = 0;
        D_L01_00274940[0][i].seconds = 0;
        D_L01_00274940[1][i].per_second = 0;
        D_L01_00274940[1][i].seconds = 0;
    }
    /* bank 0: the Lava Gun (0x11, 0xA1), Bouncer (0x13, 0xA6) and Plasma Coil (0x10, 0xA0),
       each 2 a second for 4 s */
    D_L01_00274940[0][0x11].per_second = 2.0f;
    D_L01_00274940[0][0x11].seconds = 4;
    D_L01_00274940[0][0xA1].per_second = 2.0f;
    D_L01_00274940[0][0xA1].seconds = 4;
    D_L01_00274940[0][0x13].per_second = 2.0f;
    D_L01_00274940[0][0x13].seconds = 4;
    D_L01_00274940[0][0xA6].per_second = 2.0f;
    D_L01_00274940[0][0xA6].seconds = 4;
    D_L01_00274940[0][0x10].per_second = 2.0f;
    D_L01_00274940[0][0x10].seconds = 4;
    D_L01_00274940[0][0xA0].per_second = 2.0f;
    D_L01_00274940[0][0xA0].seconds = 4;
    /* bank 1: the Lava Gun and Bouncer 3 a second for 6 s, the Plasma Coil 5 for 4 s */
    D_L01_00274940[1][0x11].per_second = 3.0f;
    D_L01_00274940[1][0x11].seconds = 6;
    D_L01_00274940[1][0xA1].per_second = 3.0f;
    D_L01_00274940[1][0xA1].seconds = 6;
    D_L01_00274940[1][0x13].per_second = 3.0f;
    D_L01_00274940[1][0x13].seconds = 6;
    D_L01_00274940[1][0xA6].per_second = 3.0f;
    D_L01_00274940[1][0xA6].seconds = 6;
    D_L01_00274940[1][0x10].per_second = 5.0f;
    D_L01_00274940[1][0x10].seconds = 4;
    D_L01_00274940[1][0xA0].per_second = 5.0f;
    D_L01_00274940[1][0xA0].seconds = 4;
}
/* localdecomp:end func_L01_0031B3A0 */

INCLUDE_ASM("asm/levels", func_L01_0031B4F8);

/* localdecomp:start func_L01_0031B810 */
#include "vu0.h"
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern u8 *D_L01_001EAA18[];
typedef struct { u8 pad0[0x18]; u8 *object; u8 pad1C[4]; vu0_v4 position; } Hit_0031B810;
extern Hit_0031B810 D_L01_001EAA00;
void func_L01_0031B810(u8 *obj) {
    extern f32 func_00382538(void);
    extern void func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern f32 func_0038CF38(void *, void *);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_004CB320(void);
    extern void func_L01_004CB358(void);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern void func_L01_0031BC78(u8 *);
    extern void func_L01_00404A10_0031B810(void (*)(u8 *), u8 *);
    extern s32 func_L01_00456250(void *);
    extern void func_L01_0031C100(void *, s32);
    extern void func_L01_00456230(void *, s32);
    extern void func_003C2880(u8 *);
    vu0_v4 old, velocity;
    u8 info[0x30];
    vu0_v4 back, acceleration;
    u8 *state = *(u8 **)(obj + 0x68);
    f32 power = *(f32 *)(state + 0x3C);
    vu0_v4 *point;
    s32 hit;
    s32 rotation;
    u8 *owner;
    *(f32 *)(state + 0x38) += 1.0f;
    if (*(f32 *)(state + 0x38) > 2.0f) old = *(vu0_v4 *)(state + 0x10);
    else old = *(vu0_v4 *)state;
    rotation = (s32)func_00382538();
    func_L01_0046A610(state + 0x10, D_L01_001D66B0, 3, 96, 0x406080, rotation, 168000.0f, 200.0f, 0.95f, 0.0f, 0.0f);
    if (*(f32 *)(state + 0x38) < 50.0f) {
        *(f32 *)(state + 0x34) += *(f32 *)(state + 0x44);
        func_0038CF68((f32 *)(state + 0x10), (f32 *)(state + 0x20), *(f32 *)(state + 0x34));
        func_0038CF68((f32 *)&velocity, (f32 *)(state + 0x20), 0.08000000566244125f);
        func_L01_00446760(info, obj, 0x10001, &velocity, power);
        *(u16 *)(info + 0x1A) = *(u16 *)(obj + 0xAA);
        vec_add_ba(state + 0x10, state, state + 0x10);
        func_0038CF68((f32 *)&back, (f32 *)(state + 0x20), -*(f32 *)(state + 0x44));
        vec_add_ab(&back, &back, state + 0x10);
        owner = *(u8 **)(obj + 0xB8);
        func_L01_004CB320();
        hit = func_003D3CB0(state + 0x10, &old, 16, owner, info);
        if (hit) {
            u8 *contact = D_L01_001EAA18[0];
            if (contact && *(s16 *)(contact + 0xAA) == 0x186D && contact[0x20] != 2 && contact[0x20] != 5) contact[0x20] = 4;
        }
        func_L01_004CB358();
        if (hit) {
            Hit_0031B810 *collision = &D_L01_001EAA00;
            if (collision->object == *(void **)(obj + 0xB8)) goto first_continue;
            {
                point = &collision->position;
                *(vu0_q *)(state + 0x10) = *(vu0_q *)point;
                if (!func_L01_00456250(obj)) {
                    func_L01_0031C100(point, 20);
                    func_L01_00456230(obj, 1);
                }
                func_003C2880(obj);
                return;
            }
        }
    first_continue:
        func_L01_00404A10_0031B810(func_L01_0031BC78, obj);
    } else if (*(f32 *)(state + 0x38) >= 50.0f && *(f32 *)(state + 0x38) < 180.0f) {
        if (*(f32 *)(state + 0x44) < func_0038CF38(state, state + 0x10)) {
            *(f32 *)(state + 0x34) += *(f32 *)(state + 0x44);
            func_0038CF68((f32 *)(state + 0x10), (f32 *)(state + 0x20), *(f32 *)(state + 0x34));
            func_0038CF68((f32 *)&velocity, (f32 *)(state + 0x20), 0.08000000566244125f);
            func_L01_00446760(info, obj, 0x10001, &velocity, power);
            *(u16 *)(info + 0x1A) = *(u16 *)(obj + 0xAA);
            vec_add_ba(state + 0x10, state, state + 0x10);
            func_0038CF68((f32 *)&back, (f32 *)(state + 0x20), -*(f32 *)(state + 0x44));
            vec_add_ab(&back, &back, state + 0x10);
            func_L01_004CB320();
            hit = func_003D3CB0(state + 0x10, &old, 16, obj, info);
            if (hit) {
                u8 *contact = D_L01_001EAA18[0];
                if (contact && *(s16 *)(contact + 0xAA) == 0x186D && contact[0x20] != 2 && contact[0x20] != 5) contact[0x20] = 4;
            }
            func_L01_004CB358();
            {
                u8 *other;
                if (hit) {
                    Hit_0031B810 *collision = &D_L01_001EAA00;
                    other = collision->object;
                    if (other != *(u8 **)(obj + 0xB8) && (other == 0 || *(s16 *)(other + 0xAA) != 0x1625)) {
                        point = &collision->position;
                        *(vu0_q *)(state + 0x10) = *(vu0_q *)point;
                        {
                            if (!func_L01_00456250(obj)) {
                                func_L01_0031C100(point, 20);
                                func_L01_00456230(obj, 1);
                            }
                            func_003C2880(obj);
                            return;
                        }
                    }
                }
            }
            func_0038CF68((f32 *)&acceleration, (f32 *)(state + 0x20), *(f32 *)(state + 0x44));
            vec_add_ab(state, state, &acceleration);
            func_L01_00404A10_0031B810(func_L01_0031BC78, obj);
        }
    } else {
        func_L01_0031C100(state + 0x10, 20);
        func_003C2880(obj);
    }
    return;
}
/* localdecomp:end func_L01_0031B810 */

LINKER_REMNANT("asm/levels", func_L01_0031BC68);

/* localdecomp:start func_L01_0031BC78 */

extern void func_L01_0031BCA0(u8 *, u128_t *);

void func_L01_0031BC78(u8 *obj) {
    u128_t v;
    v = **(u128_t **)(obj + 104);
    func_L01_0031BCA0(obj, &v);
}
/* localdecomp:end func_L01_0031BC78 */

INCLUDE_ASM("asm/levels", func_L01_0031BCA0);

/* localdecomp:start func_L01_0031C100 */
void func_L01_0031C100(void *arg0, s32 arg1) {
    extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32,
        f32, f32, f32, f32,
        s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    func_L01_003303B8(arg0, 0, 5, 5, 5, 5, 10, 0,
        0.3f, 0.0f, 0.0f, 0.0f,
        0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7,
        0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
}
/* localdecomp:end func_L01_0031C100 */
