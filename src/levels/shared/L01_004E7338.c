#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad[9668];
    s32 a;
    s32 pad2;
    s32 b;
} S_004E5540;
typedef struct {
    u8 pad0[9836];
    f32 arr[32];
    s32 f26EC;
    s32 f26F0;
} G_4E5630;
typedef struct S_4E56A8vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} S_4E56A8vec __attribute__((aligned(16)));
typedef struct S_4E56A8c {
    u8 pad0[0x46];
    u8 x46;
} S_4E56A8c;
typedef struct S_4E56A8m {
    u8 pad0[0x10];
    S_4E56A8vec x10;
    u8 pad20[4];
    S_4E56A8c *x24;
} S_4E56A8m;
typedef struct S_4E56A8g {
    u8 pad0[0x80];
    S_4E56A8vec x80;
    u8 pad90[0x2A8];
    f32 x338;
    u8 pad33c[0x2288];
    s32 x25C4;
} S_4E56A8g;
typedef struct S_4E56A8q {
    S_4E56A8vec x0;
    f32 x10;
    f32 x14;
    f32 x18;
} S_4E56A8q;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x64 - 0x21];
    void (*fn64)(void);
} S_4E8698o;
typedef struct {
    u8 pad0[0x1200];
    S_4E8698o *p0;
    S_4E8698o *p4;
    u8 pad8[0x14 - 0x8];
    s32 w14;
    u8 pad18[0x24 - 0x18];
    s32 w24;
    s32 w28;
} S_4E8698e;
typedef struct {
    u8 pad0[9664];
    s32 unk25C0;
    s32 unk25C4;
    s32 pad25C8;
    s32 unk25CC;
    u8 pad25D0[24];
    u8 unk25E8;
    u8 pad25E9[4];
    u8 unk25ED;
    u8 pad25EE;
    u8 unk25EF;
} S_001A4BE0;
typedef struct M004E9888 {
    u8 pad0[16];
    s128 pos;
    u8 pad20[52 - 32];
    u16 h52;
    u8 pad36[64 - 54];
    u8 b64;
    u8 b65;
    u8 b66;
    u8 b67;
    u8 pad44[88 - 68];
    s32 w88;
    s32 w92;
    u8 pad60[156 - 96];
    s32 w156;
} M004E9888;
typedef struct {
    u8 pad0[128];
    s128 q128;
    u8 pad90[3060 - 144];
    M004E9888 *m3060;
    M004E9888 *m3064;
    M004E9888 *m3068;
    u8 padC00[3076 - 3072];
    f32 f3076;
    u8 padC08[6672 - 3080];
    s32 w6672;
    u8 pad1A14[6688 - 6676];
    M004E9888 *m6688;
    M004E9888 *m6692;
    u8 pad1A28[6736 - 6696];
    M004E9888 *m6736;
    u8 pad1A54[6744 - 6740];
    M004E9888 *m6744;
    u8 pad1A5C[9664 - 6748];
    M004E9888 *m9664;
    s32 w9668;
    u8 pad25C8[9700 - 9672];
    u8 b9700;
    u8 pad25E5[10320 - 9701];
    s32 w10320;
    s32 w10324;
    s16 h10328;
} P004E9888;
typedef struct { u8 pad[0xAA]; s16 t; } S4EA;
typedef struct {
    /* 0x0000 */ u8 pad0[64];
    /* 0x0040 */ u8 v64[64];
    /* 0x0080 */ s128 v128;
    /* 0x0090 */ u8 v144[8];
    /* 0x0098 */ f32 f152;
    /* 0x009C */ u8 pad9c[656 - 156];
    /* 0x0290 */ s32 w656;
    /* 0x0294 */ u8 pad294[5172 - 660];
    /* 0x1434 */ s16 h5172;
    /* 0x1436 */ u8 pad1436[8256 - 5174];
    /* 0x2040 */ s128 hist[32];
    /* 0x2240 */ u8 pad2240[8800 - 8768];
    /* 0x2260 */ f32 f8800;
    /* 0x2264 */ f32 f8804;
    /* 0x2268 */ u8 pad2268[9668 - 8808];
    /* 0x25C4 */ s32 w9668;
    /* 0x25C8 */ u8 pad25c8[9716 - 9672];
    /* 0x25F4 */ u8 b9716;
    /* 0x25F5 */ u8 pad25f5[9836 - 9717];
    /* 0x266C */ f32 fhist[32];
    /* 0x26EC */ s32 w9964;
    /* 0x26F0 */ s32 w9968;
    /* 0x26F4 */ s32 w9972;
    /* 0x26F8 */ s32 w9976;
    /* 0x26FC */ u8 pad26fc[10296 - 9980];
    /* 0x2838 */ f32 f10296;
    /* 0x283C */ f32 f10300;
    /* 0x2840 */ f32 f10304;
} func_004EA708_P;
typedef struct { u8 pad[432]; s32 a; s32 b; } S_004EAA60;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 pad0[152];
    u8 f98[264];
    f32 f1A0;
    u8 f1A4[4];
    f32 f1A8;
    u8 pad1AC[5380];
    s32 f16B0;
    u8 pad16B4[3893];
    u8 f25E9;
    u8 pad25EA[10];
    u8 f25F4;
} G_004EAFF8;

typedef union {
    s128 q;
    f32 f[4];
} Vec_004E5300;
typedef struct {
    u8 pad0[516];
    s16 f516;
    u8 pad518[616];
    u8 f1134;
    u8 pad1135[545];
    s32 f1680;
    s32 f1684;
    f32 f1688;
    s32 f1692;
    u8 pad1696[12];
    s32 f1708;
    u8 pad1712[7964];
    s32 f9676;
} Game_004E5300;

INCLUDE_ASM("asm/levels", func_L01_004E7338);

INCLUDE_ASM("asm/levels", func_L01_004E7780);

/* localdecomp:start func_L01_004E7C88 */
extern void func_L01_004ED658(void);
extern u8 D_001A71C4[];

void func_L01_004E7C88(void) {
    if (D_001A71C4[0] == 3) {
        ((void (*)(s32))func_L01_004ED658)(0);
    }
}
/* localdecomp:end func_L01_004E7C88 */

INCLUDE_ASM("asm/levels", func_L01_004E7CB8);

INCLUDE_ASM("asm/levels", func_L01_004E8318);

INCLUDE_ASM("asm/levels", func_L01_004E8BC8);

/* localdecomp:start func_L01_004E8EE0 */

extern u8 D_00142CAE[];
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];

extern s32 func_L01_004E8BC8(s128 *, s32 *, s128 *, s32 *, f32 *, s32 *, s32, s32, s32);

void func_L01_004E8EE0(void) {
    u8 *d;
    u8 *e;
    u8 *q;
    s32 v;
    s128 vec[2];
    s32 w48;
    s32 w52;
    f32 f56;
    s32 w60;
    f32 dz;

    if (D_00142CAE[0] == 0) {
        return;
    }
    d = D_001A4BE0;
    *(s32 *)(d + 1500) = 0;
    if (*(s16 *)(d + 500) != 0) {
        return;
    }
    v = *(s32 *)(d + 9676);
    if (v == 2 || v == 0 || v == 1 || v == 6) {
        goto go;
    }
    if (*(s32 *)(d + 9668) == 1) {
        goto go;
    }
    if ((u32)(*(s32 *)(d + 9668) - 40) < 2) {
        if (*(s32 *)(d + 1504) != 0 || *(s32 *)(d + 1588) != 0) {
            goto go;
        }
    }
    if (v != 4) {
        return;
    }
    if (d[1134] == 0 && *(s16 *)(d + 502) == 0) {
        return;
    }
go:
    q = D_001A4C60;
    vec[1] = *(s128 *)q;
    if (func_L01_004E8BC8(&vec[1], &w48, &vec[0], &w52, &f56, &w60, 0, 0, 0) == 0) {
        return;
    }
    d = q - 0x80;
    if (*(s32 *)(d + 9668) == 40 && *(s32 *)(d + 1588) != 0 && w48 == *(s32 *)(d + 1488)) {
        return;
    }
    e = D_001A4BE0;
    dz = *(f32 *)(e + 136) - ((f32 *)&vec[0])[2];
    if (!(-0.5f < dz)) {
        return;
    }
    if (!(dz < 0.57f) && *(s16 *)(e + 502) == 0) {
        return;
    }
    *(s128 *)(e + 1392) = vec[0];
    *(s32 *)(e + 1488) = w48;
    *(s32 *)(e + 1492) = w52;
    *(f32 *)(e + 1496) = f56;
    *(s32 *)(e + 1524) = w60;
    *(s32 *)(e + 1500) = 1;
}
/* localdecomp:end func_L01_004E8EE0 */

/* localdecomp:start func_L01_004E9090 */
extern void func_L01_005110E8(s32, s32, f32, f32, f32);
void func_L01_004E9090(s32 a0) {
    func_L01_005110E8(a0, 1, 0.3f, 0.0f, 1.34f);
}
/* localdecomp:end func_L01_004E9090 */

/* localdecomp:start func_L01_004E90C8 */
extern s32 func_L01_004E8BC8(s128 *, s32 *, s128 *, s32 *, f32 *, s32 *, s32, s32, s32);
extern void func_L01_004E9090(s32 a0);
extern u8 D_001A4BE0[];



extern s128 D_001A5250;
extern u8 *D_001D52FC;

void func_L01_004E90C8(void) {
    Vec_004E5300 a;
    Vec_004E5300 b;
    s32 i48;
    s32 i52;
    f32 f56;
    s32 i60;
    f32 k;
    f32 d;
    s32 m;
    Game_004E5300 *g;
    s128 *pv;

    (*(Game_004E5300 *)&D_001A4BE0).f1692 = 0;
    if ((*(Game_004E5300 *)&D_001A4BE0).f516 != 0) {
        return;
    }
    ((void (*)(Vec_004E5300 *))func_L01_004E9090)(&a);
    m = (*(Game_004E5300 *)&D_001A4BE0).f9676;
    if ((m == 4 && (*(Game_004E5300 *)&D_001A4BE0).f1134 == 0) || m == 2 || m == 15) {
        if (((s32 (*)(Vec_004E5300 *, s32 *, Vec_004E5300 *, s32 *, f32 *, s32 *, s32, s32, s32))func_L01_004E8BC8)(&a, &i48, &b, &i52, &f56, &i60, 0, 0, 1) == 0) {
            return;
        }
        d = a.f[2] - b.f[2];
        k = -0.7f;
        if (*(s32 *)(D_001D52FC + 420) & 0x80) {
            k = -1.2f;
        }
        if (k < d && d < 0.4f) {
            pv = &D_001A5250;
            *pv = b.q;
            g = (Game_004E5300 *)((u8 *)pv - 1648);
            g->f1680 = i48;
            g->f1684 = i52;
            g->f1688 = f56;
            g->f1708 = i60;
            g->f1692 = 1;
        }
    }
}
/* localdecomp:end func_L01_004E90C8 */

/* localdecomp:start func_L01_004E9200 */
extern u8 D_001A4BE0[];

s32 func_L01_004E9200(s32 arg0) {
    void *temp_a0;

    temp_a0 = (arg0 * 0x50) + D_001A4BE0;
    if ((*(s32 *)((u8 *)temp_a0 + 0x1224)) == 2) {
        return (*(s32 *)((u8 *)temp_a0 + 0x1200));
    }
    return 0;
}
/* localdecomp:end func_L01_004E9200 */

INCLUDE_ASM("asm/levels", func_L01_004E9238);

/* localdecomp:start func_L01_004E9270 */
extern int func_L01_004E9238(void);

int func_L01_004E9270(void)
{
    return func_L01_004E9238() == 30;
}
/* localdecomp:end func_L01_004E9270 */

/* localdecomp:start func_L01_004E9298 */
extern int func_L01_004E9238(void);

int func_L01_004E9298(void)
{
    return func_L01_004E9238() == 23;
}
/* localdecomp:end func_L01_004E9298 */

/* localdecomp:start func_L01_004E92C0 */
extern s32 func_L01_004E9238(void);

s32 func_L01_004E92C0(void) {
    s32 v = func_L01_004E9238();

    if (v == 13 || v == 28 || v == 29 || v == 14) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_004E92C0 */

/* localdecomp:start func_L01_004E9308 */
extern u8 D_001A4BE0[];

int func_L01_004E9308(void)
{
    S_004E5540 *p = &(*(S_004E5540 *)&D_001A4BE0);
    if ((u32)(p->b - 17) < 2 || p->a == 108 || p->a == 132 || p->a == 120 || p->a == 119) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_004E9308 */

/* localdecomp:start func_L01_004E9358 */
s32 func_L01_004E9358(u8 *a0, s32 a1) {
    if (a1 == 255) a1 = a0[169];
    return a1;
}
/* localdecomp:end func_L01_004E9358 */

INCLUDE_ASM("asm/levels", func_L01_004E9370);

/* localdecomp:start func_L01_004E93F8 */
extern u8 D_001A4BE0[];
f32 func_L01_004E93F8(s32 a0) {
    s32 n;
    s32 m;
    n = a0 < 32 ? a0 : 31;
    m = (*(G_4E5630 *)&D_001A4BE0).f26F0;
    if (m < n) {
        n = m;
    }
    return (*(G_4E5630 *)&D_001A4BE0).arr[((*(G_4E5630 *)&D_001A4BE0).f26EC - n + 31) % 32];
}
/* localdecomp:end func_L01_004E93F8 */

/* localdecomp:start func_L01_004E9450 */
extern void func_L01_00456C20_004E9450();
 
void func_L01_004E9450(void) {
    func_L01_00456C20_004E9450();
}
/* localdecomp:end func_L01_004E9450 */

/* localdecomp:start func_L01_004E9470 */
extern u8 D_001A4C60[];
extern S_4E56A8q D_L01_001E2A40;
extern f32 func_0038CF00(S_4E56A8vec *a, S_4E56A8vec *b);
extern f32 func_0038CF38(S_4E56A8vec *a, S_4E56A8vec *b);
extern f32 func_0038D160(f32 a, f32 b);
extern f32 func_0038DBA0(f32 a, f32 b);
extern s32 func_003C4B50(S_4E56A8m *m);
f32 func_L01_004E9470(S_4E56A8m *m, s32 *out, f32 a, f32 b, f32 c, f32 d) {
    S_4E56A8g *g;
    S_4E56A8vec p;
    f32 dist;
    f32 yaw;
    f32 lim;
    f32 pitch;
    f32 t;
    f32 res;

    *out = 0;
    p = (*(S_4E56A8vec *)&D_001A4C60);
    g = (S_4E56A8g *)((u8 *)&(*(S_4E56A8vec *)&D_001A4C60) - 0x80);
    if (g->x25C4 == 20) {
        p.z = g->x338;
    }
    dist = func_0038CF00(&p, &m->x10);
    if (b < dist) {
        *out = 1;
    }
    yaw = func_0038DBA0(func_0038D160(m->x10.x - p.x, m->x10.y - p.y), a);
    lim = yaw;
    pitch = func_0038DBA0(func_0038D160(func_0038CF38(&p, &m->x10), m->x10.z - p.z), 0.0f);
    if (g->x25C4 == 1 || g->x25C4 == 29) {
        t = func_0038DBA0(func_0038D160(m->x10.x - D_L01_001E2A40.x0.x, m->x10.y - D_L01_001E2A40.x0.y), D_L01_001E2A40.x18);
        pitch = func_0038DBA0(func_0038D160(func_0038CF38(&D_L01_001E2A40.x0, &m->x10), m->x10.z - D_L01_001E2A40.x0.z), -D_L01_001E2A40.x14);
        lim = pitch;
        yaw = t + pitch;
        if (pitch < t) {
            lim = t;
        }
    }
    if (0.0f < c && c < lim) {
        *out = 1;
    }
    if (0.0f < d && d < pitch) {
        *out = 1;
    }
    res = dist + yaw * dist;
    if (func_003C4B50(m) != 0) {
        res += b * 0.8f;
    } else if (m != 0 && m->x24 != 0 && m->x24->x46 == 22) {
        res += b * 0.8f;
    }
    return res;
}
/* localdecomp:end func_L01_004E9470 */

INCLUDE_ASM("asm/levels", func_L01_004E96E8);

INCLUDE_ASM("asm/levels", func_L01_004E9980);

INCLUDE_ASM("asm/levels", func_L01_004E9BB0);

INCLUDE_ASM("asm/levels", func_L01_004E9C08);

LINKER_REMNANT("asm/levels", func_L01_004E9D38);

INCLUDE_ASM("asm/levels", func_L01_004E9D40);

INCLUDE_ASM("asm/levels", func_L01_004E9FB0);

INCLUDE_ASM("asm/levels", func_L01_004EA638);

INCLUDE_ASM("asm/levels", func_L01_004EA7D8);

/* localdecomp:start func_L01_004EAA80 */
extern u8 D_001A4BE0[];
extern s32 func_L01_004DFDB0(s32);
extern void func_L01_0050FB40(s32, s32, f32);

void func_L01_004EAA80(void)
{
    u8 *g = D_001A4BE0;
    u8 *h;

    if (g[9705] == 0) {
        return;
    }
    if (*(s32 *)(g + 3704) != 0) {
        *(s32 *)(g + 3716) = 1;
    } else if (*(s32 *)(g + 9668) == 0 && (*(u8 **)(g + 9664))[67] == *(s32 *)(g + 10288)) {
        func_L01_0050FB40(func_L01_004DFDB0(0), 0, -2.0f);
    }
    h = D_001A4BE0;
    h[9705] = 0;
    h[9707] = 0;
}
/* localdecomp:end func_L01_004EAA80 */

INCLUDE_ASM("asm/levels", func_L01_004EAB10);

/* localdecomp:start func_L01_004EAEE8 */
extern s32 func_L01_004E9FB0();
extern void func_L01_004EAB10();
extern void func_L01_004E9D40();
void func_L01_004EAEE8(void) {
    func_L01_004E9FB0();
    func_L01_004EAB10();
    func_L01_004E9D40();
}
/* localdecomp:end func_L01_004EAEE8 */

INCLUDE_ASM("asm/levels", func_L01_004EAF18);

/* localdecomp:start func_L01_004EB918 */
f32 func_L01_004EB918(f32 a[][4], f32 b[][4]) {
    s32 i, j;
    f32 sum = 0.0f;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            sum += __builtin_fabsf(a[i][j] - b[i][j]);
        }
    }
    return sum;
}
/* localdecomp:end func_L01_004EB918 */

INCLUDE_ASM("asm/levels", func_L01_004EB978);

INCLUDE_ASM("asm/levels", func_L01_004EBDA8);

/* localdecomp:start func_L01_004EC468 */


extern u8 D_001A4BE0[];
extern void func_003C2880(S_4E8698o *a0);

void func_L01_004EC468(s32 idx, s32 a1) {
    S_4E8698e *t;
    S_4E8698e *e;
    S_4E8698o *o;

    t = (S_4E8698e *)(D_001A4BE0 + idx * 80);
    t->w14 = a1;
    if (t->w24 != 3) {
        o = t->p0;
        t->w24 = 3;
        if (o != 0 && o->b20 != 254 && o->b20 != 253 && o->fn64 != 0) {
            o->fn64();
        }
    }
    e = (S_4E8698e *)(D_001A4BE0 + idx * 80);
    e->w24 = 0;
    e->w28 = 0;
    if (e->p0 != 0) {
        func_003C2880(e->p0);
        e->p0 = 0;
    }
    if (e->p4 != 0 && idx != 3) {
        func_003C2880(e->p4);
        e->p4 = 0;
    }
}
/* localdecomp:end func_L01_004EC468 */

INCLUDE_ASM("asm/levels", func_L01_004EC540);

/* localdecomp:start func_L01_004EC598 */
extern u8 D_001A4BE0[];
extern s32 func_L01_00511A98(void);
s32 func_L01_004EC598(void) {
    u8 *p;
    u32 v;
    if (func_L01_00511A98() != 0) {
        return 0;
    }
    p = D_001A4BE0;
    if (p[9700] != 0) {
        return 0;
    }
    v = *(u32 *)(p + 9676);
    if (v < 3 || v == 4) {
        if (*(s16 *)(p + 872) != 0) {
            return 0;
        }
        return p[5238] == 0;
    }
    return 0;
}
/* localdecomp:end func_L01_004EC598 */

INCLUDE_ASM("asm/levels", func_L01_004EC600);

INCLUDE_ASM("asm/levels", func_L01_004ED188);

/* localdecomp:start func_L01_004ED328 */
extern u8 D_001A4BE0[];

extern s32 func_L01_004E9308(void);
extern void func_L01_004EAF18(void);
extern void func_L01_004EBDA8(s32);
extern void func_L01_005124D8(void);
extern void func_L01_004E3650(void);
extern void func_L01_004ED188(void);

void func_L01_004ED328(void) {
    if (func_L01_004E9308() != 0 || ((S_001A4BE0 *)&D_001A4BE0)[0].unk25C4 == 176) {
        ((S_001A4BE0 *)&D_001A4BE0)[0].unk25E8 = 1;
        ((S_001A4BE0 *)&D_001A4BE0)[0].unk25ED = 1;
    }
    if (func_L01_004E9308() != 0 || ((S_001A4BE0 *)&D_001A4BE0)[0].unk25C4 == 49 || ((S_001A4BE0 *)&D_001A4BE0)[0].unk25CC == 3 ||
        ((S_001A4BE0 *)&D_001A4BE0)[0].unk25C4 == 18 || ((S_001A4BE0 *)&D_001A4BE0)[0].unk25C4 == 135 ||
        ((S_001A4BE0 *)&D_001A4BE0)[0].unk25C4 == 176) {
        ((S_001A4BE0 *)&D_001A4BE0)[0].unk25EF = 1;
    } else {
        ((S_001A4BE0 *)&D_001A4BE0)[0].unk25EF = 0;
    }
    func_L01_004EAF18();
    func_L01_004EBDA8(((S_001A4BE0 *)&D_001A4BE0)[0].unk25C0);
    func_L01_005124D8();
    func_L01_004E3650();
    func_L01_004ED188();
}
/* localdecomp:end func_L01_004ED328 */

INCLUDE_ASM("asm/levels", func_L01_004ED3F8);

INCLUDE_ASM("asm/levels", func_L01_004ED5F8);

/* localdecomp:start func_L01_004ED658 */
extern void func_003C2880(S_4E8698o *a0);
extern u8 D_001A4BE0[];



extern s32 D_L01_001D6694;
extern u8 func_00393BE8[];
extern u8 func_00393C40[];
extern u8 func_00394620[];
extern u8 D_L01_00252880[];
extern u8 D_L01_00252E80[8];
extern void func_L01_00439D70(M004E9888 *, s32 *);
extern void func_L01_004E04E8(void);
extern void func_00393348(s32, s32, void *, void *, void *, s32, s32);
extern void func_L01_0041C828(s32);
extern void func_L01_004E1560(void);
extern void func_L01_0050FED0(void);
extern s32 func_L01_004DFCC8(M004E9888 *, s32, s32, void *);
extern void func_L01_005003D0(s32, s32);

void func_L01_004ED658(void) {
    M004E9888 *m;

    if ((*(P004E9888 *)&D_001A4BE0).b9700 == 1) {
        (*(P004E9888 *)&D_001A4BE0).w10324 = (*(P004E9888 *)&D_001A4BE0).w10320;
        (*(P004E9888 *)&D_001A4BE0).w10320 = (*(P004E9888 *)&D_001A4BE0).h10328;
        if ((*(P004E9888 *)&D_001A4BE0).m6688) {
            ((void (*)(M004E9888 *))func_003C2880)((*(P004E9888 *)&D_001A4BE0).m6688);
            (*(P004E9888 *)&D_001A4BE0).m6688 = 0;
        }
        if ((*(P004E9888 *)&D_001A4BE0).m6692) {
            ((void (*)(M004E9888 *))func_003C2880)((*(P004E9888 *)&D_001A4BE0).m6692);
            (*(P004E9888 *)&D_001A4BE0).m6692 = 0;
        }
        if ((*(P004E9888 *)&D_001A4BE0).m6736) {
            ((void (*)(M004E9888 *))func_003C2880)((*(P004E9888 *)&D_001A4BE0).m6736);
            (*(P004E9888 *)&D_001A4BE0).m6736 = 0;
        }
        if ((*(P004E9888 *)&D_001A4BE0).m6744) {
            ((void (*)(M004E9888 *))func_003C2880)((*(P004E9888 *)&D_001A4BE0).m6744);
            (*(P004E9888 *)&D_001A4BE0).m6744 = 0;
        }
        if ((*(P004E9888 *)&D_001A4BE0).w6672) {
            func_L01_00439D70((*(P004E9888 *)&D_001A4BE0).m9664, &(*(P004E9888 *)&D_001A4BE0).w6672);
        }
    }
    func_L01_004E04E8();
    (*(P004E9888 *)&D_001A4BE0).b9700 = 0;
    func_00393348(35, 0, func_00393BE8, func_00393C40, func_00394620, 0, 0);
    func_L01_0041C828(3);
    if ((*(P004E9888 *)&D_001A4BE0).m3060) {
        (*(P004E9888 *)&D_001A4BE0).m3060->h52 &= 0xFFF9;
    }
    (*(P004E9888 *)&D_001A4BE0).m3060 = 0;
    if ((*(P004E9888 *)&D_001A4BE0).m3068) {
        ((void (*)(M004E9888 *))func_003C2880)((*(P004E9888 *)&D_001A4BE0).m3068);
        (*(P004E9888 *)&D_001A4BE0).m3068 = 0;
    }
    func_L01_004E1560();
    (*(P004E9888 *)&D_001A4BE0).m9664 = (*(P004E9888 *)&D_001A4BE0).m3064;
    (*(P004E9888 *)&D_001A4BE0).m3064->pos = (*(P004E9888 *)&D_001A4BE0).q128;
    (*(P004E9888 *)&D_001A4BE0).m9664->w156 = 0;
    (*(P004E9888 *)&D_001A4BE0).f3076 = 1.0f;
    func_L01_0050FED0();
    m = (*(P004E9888 *)&D_001A4BE0).m9664;
    if (m->b66 != 255) {
        (*(P004E9888 *)&D_001A4BE0).m9664->w88 = func_L01_004DFCC8(m, m->b66, m->b64, D_L01_00252880);
    }
    m = (*(P004E9888 *)&D_001A4BE0).m9664;
    (*(P004E9888 *)&D_001A4BE0).m9664->w92 = func_L01_004DFCC8(m, m->b67, m->b65, D_L01_00252E80);
    if ((*(P004E9888 *)&D_001A4BE0).w9668 != 101 || (D_L01_001D6694 != 2 && D_L01_001D6694 != 6)) {
        func_L01_005003D0(0, 1);
    }
}
/* localdecomp:end func_L01_004ED658 */

/* localdecomp:start func_L01_004ED838 */
extern void func_L01_005116A8(s32, s32);
extern void func_L01_00511618(s32, s32, f32);
extern void func_L01_00511588(s32, s32);
extern void func_L01_00511508(s32, s32, f32);
void func_L01_004ED838(s32 a0, s32 a1, f32 f12, f32 f13) {
    if (a1 != 0) {
        func_L01_005116A8(a0, a0);
        func_L01_00511618(a0, a0, f13);
    } else {
        func_L01_00511588(a0, a0);
        func_L01_00511508(a0, a0, f13);
    }
}
/* localdecomp:end func_L01_004ED838 */

INCLUDE_ASM("asm/levels", func_L01_004ED8A8);

INCLUDE_ASM("asm/levels", func_L01_004EDE10);

/* localdecomp:start func_L01_004EDFA8 */
s32 func_L01_004EDFA8(S4EA *p) {
    if (p == 0) return 0;
    return p->t == 0x47;
}
/* localdecomp:end func_L01_004EDFA8 */

INCLUDE_ASM("asm/levels", func_L01_004EDFC8);

INCLUDE_ASM("asm/levels", func_L01_004EE068);

INCLUDE_ASM("asm/levels", func_L01_004EE388);

INCLUDE_ASM("asm/levels", func_L01_004EE400);

/* localdecomp:start func_L01_004EE4E0 */
extern u8 D_001A4BE0[];


extern u8 D_001A6EC0[];
extern u8 D_001A6014[];
extern u8 *D_001D52FC;
extern s32 func_L01_00513EF0(void);
extern void func_0038CB00(void *a0);
extern u8 func_L01_00510E40(void);
extern f32 func_L01_004EE780(void);
extern f32 func_0038CED8(void *a0);
extern f32 func_0038D160(f32 a, f32 b);
extern void **func_L01_0043B568(s32 a0, s32 a1, s32 a2);
extern void func_L01_004F5E98(void);
extern void func_0038D328(void *a0, void *a1);
extern void func_0038D2A0(void *a0);
extern void func_0038D5B0(void *a0, void *a1);
extern void func_L01_004EE068(s32 a0);
extern void func_L01_004FE668(void);
extern void func_L01_004FE920(void);

void func_L01_004EE4E0(void) {
    void **prof;
    s32 pad;
    u8 *pl;
    func_004EA708_P *q;
    s32 t;

    *(s128 *)D_001A6EC0 = *(s128 *)(D_001A6EC0 - 8800);
    if ((*(u32 *)(D_001D52FC + 416) & 3) && func_L01_00513EF0() == 0) {
        q = (func_004EA708_P *)(D_001A6EC0 - 8928);
        if (q->h5172 <= 0) {
            q->h5172 = 1;
        }
    } else {
        func_0038CB00(D_001A6014);
    }
    if ((*(func_004EA708_P *)&D_001A4BE0).w9668 == 16) {
        (*(func_004EA708_P *)&D_001A4BE0).h5172 = 0;
    }
    (*(func_004EA708_P *)&D_001A4BE0).b9716 = func_L01_00510E40();
    (*(func_004EA708_P *)&D_001A4BE0).w656 = 0;
    (*(func_004EA708_P *)&D_001A4BE0).f8800 = *(f32 *)(D_001D52FC + 264);
    (*(func_004EA708_P *)&D_001A4BE0).f8804 = -*(f32 *)(D_001D52FC + 268);
    (*(func_004EA708_P *)&D_001A4BE0).f10300 = func_L01_004EE780();
    if (func_0038CED8(&(*(func_004EA708_P *)&D_001A4BE0).f8800) < 0.25f) {
        pl = D_001D52FC;
        t = ((*(s32 *)(pl + 432) >> 13) & 1) - ((*(s32 *)(pl + 432) >> 15) & 1);
        (*(func_004EA708_P *)&D_001A4BE0).f8800 = (f32)t;
        t = (*(s32 *)(pl + 432) >> 14) & 1;
        (*(func_004EA708_P *)&D_001A4BE0).f8804 = (f32)((*(s32 *)(pl + 432) & 0x1000) ? 1 - t : -t);
    }
    (*(func_004EA708_P *)&D_001A4BE0).f10296 = func_L01_004EE780();
    (*(func_004EA708_P *)&D_001A4BE0).f10304 = func_0038D160((*(func_004EA708_P *)&D_001A4BE0).f8800, (*(func_004EA708_P *)&D_001A4BE0).f8804);
    prof = func_L01_0043B568(7791, 0, 12);
    if (prof != 0) {
        ((void (*)(void))prof[1])();
    }
    func_L01_004F5E98();
    (*(func_004EA708_P *)&D_001A4BE0).fhist[(*(func_004EA708_P *)&D_001A4BE0).w9964] = (*(func_004EA708_P *)&D_001A4BE0).f152;
    (*(func_004EA708_P *)&D_001A4BE0).w9964 = ((*(func_004EA708_P *)&D_001A4BE0).w9964 + 1) % 32;
    if (++(*(func_004EA708_P *)&D_001A4BE0).w9968 > 32) {
        (*(func_004EA708_P *)&D_001A4BE0).w9968 = 32;
    }
    (*(func_004EA708_P *)&D_001A4BE0).hist[(*(func_004EA708_P *)&D_001A4BE0).w9972] = (*(func_004EA708_P *)&D_001A4BE0).v128;
    (*(func_004EA708_P *)&D_001A4BE0).w9972 = ((*(func_004EA708_P *)&D_001A4BE0).w9972 + 1) % 32;
    if (++(*(func_004EA708_P *)&D_001A4BE0).w9976 > 32) {
        (*(func_004EA708_P *)&D_001A4BE0).w9976 = 32;
    }
    func_0038D328(&(*(func_004EA708_P *)&D_001A4BE0), (*(func_004EA708_P *)&D_001A4BE0).v144);
    func_0038D2A0((*(func_004EA708_P *)&D_001A4BE0).v64);
    func_0038D5B0((*(func_004EA708_P *)&D_001A4BE0).v64, &(*(func_004EA708_P *)&D_001A4BE0));
    func_L01_004EE068(0);
    func_L01_004FE668();
    func_L01_004FE920();
    if (prof != 0) {
        ((void (*)(void))prof[2])();
    }
}
/* localdecomp:end func_L01_004EE4E0 */

/* localdecomp:start func_L01_004EE780 */
extern u8 D_001A4BE0[];
extern f32 func_0038CEA8(void *);
f32 func_L01_004EE780(void) {
    u8 *p = D_001A4BE0;
    f32 a = __builtin_fabsf(*(f32 *)(p + 8800));
    f32 b = __builtin_fabsf(*(f32 *)(p + 8804));
    f32 m;
    f32 r;

    if (b < a) m = a; else m = b;
    r = (m + func_0038CEA8(p + 8800)) * 0.5f;
    if (1.0f < r) r = 1.0f;
    return r;
}
/* localdecomp:end func_L01_004EE780 */

INCLUDE_ASM("asm/levels", func_L01_004EE7F8);

/* localdecomp:start func_L01_004EE838 */
extern u8 D_001A4BE0[];
void func_L01_004EE838(void) {
    (*(S_004EAA60 *)&D_001A4BE0).a = 0;
    (*(S_004EAA60 *)&D_001A4BE0).b = 0;
}
/* localdecomp:end func_L01_004EE838 */

INCLUDE_ASM("asm/levels", func_L01_004EE850);

INCLUDE_ASM("asm/levels", func_L01_004EEBA8);

/* localdecomp:start func_L01_004EEC98 */
extern void func_0038D328(void *a0, void *a1);

extern Vec4 D_001A4C70[4];
extern void func_0038D640(Vec4 *, Vec4 *, Vec4 *);
extern void func_003C48A8(Vec4 *, Vec4 *);

void func_L01_004EEC98(f32 x, f32 y, f32 z) {
    Vec4 v;
    Vec4 m1[4];
    Vec4 m2[4];

    v.f[0] = x;
    v.f[1] = y;
    v.f[2] = z;
    ((void (*)(Vec4 *, Vec4 *))func_0038D328)(m1, &v);
    ((void (*)(Vec4 *, Vec4 *))func_0038D328)(m2, D_001A4C70);
    func_0038D640(m2, m2, m1);
    func_003C48A8(m2, D_001A4C70);
}
/* localdecomp:end func_L01_004EEC98 */

/* localdecomp:start func_L01_004EED18 */

extern u8 D_001A4D70[];

extern void func_0038D028(Vec4 *out, void *a, void *b);
extern f32 func_0038D160(f32 x, f32 y);
extern f32 func_L01_00448728(f32 *out, void *a, void *b, f32 f0, f32 f1, f32 f2, f32 f3);
extern void func_L01_004EEC98(f32 a, f32 b, f32 c);

void func_L01_004EED18(void *arg, f32 a, f32 b, f32 c) {
    Vec4 v;
    f32 out;
    f32 angle;
    u8 *base = D_001A4D70;
    f32 zero = 0.0f;
    func_0038D028(&v, base, base - 336);
    angle = func_0038D160(v.f[0], v.f[1]);
    out = zero;
    *(f32 *)(base + 24) = func_L01_00448728(&out, base + 20, arg, angle, a, b, c);
    func_L01_004EEC98(zero, zero, out);
}
/* localdecomp:end func_L01_004EED18 */

/* localdecomp:start func_L01_004EEDD0 */
extern f32 func_L01_00448728(f32 *out, void *a, void *b, f32 f0, f32 f1, f32 f2, f32 f3);
extern void func_L01_004EED18(void *arg, f32 a, f32 b, f32 c);
extern u8 D_001A4BE0[];
extern s32 func_L01_004606E8(s32, s32, s32, s32);


void func_L01_004EEDD0(f32 x, f32 y, f32 z, s32 a) {
    G_004EAFF8 *g;
    G_004EAFF8 *h;
    h = &(*(G_004EAFF8 *)&D_001A4BE0);
    if (h->f16B0 == 1) {
        if (h->f25E9 != 0 || func_L01_004606E8(40, 2, 0, 0) != 0) {
            x *= 3.0f;
            z *= 3.0f;
        }
    }
    g = &(*(G_004EAFF8 *)&D_001A4BE0);
    if (g->f25F4 != 0) {
        ((void (*)(f32, f32, f32, s32))func_L01_004EED18)(x, y, z, a);
    } else {
        g->f1A8 = ((f32 (*)(void *, void *, f32, f32, f32, f32, s32))func_L01_00448728)(g->f98, g->f1A4, g->f1A0, x, y, z, a);
    }
}
/* localdecomp:end func_L01_004EEDD0 */

LINKER_REMNANT("asm/levels", func_L01_004EEEB8);

INCLUDE_ASM("asm/levels", func_L01_004EEEC0);

INCLUDE_ASM("asm/levels", func_L01_004EF128);

INCLUDE_ASM("asm/levels", func_L01_004EF178);

/* localdecomp:start func_L01_004EF238 */
extern char D_001A4CD0[];
extern void func_0038CF68(void *, s32, float);
void func_L01_004EF238(s32 a0) {
    char *p = D_001A4CD0;
    func_0038CF68(p, a0, *(float *)(p + 196));
}
/* localdecomp:end func_L01_004EF238 */

INCLUDE_ASM("asm/levels", func_L01_004EF268);
