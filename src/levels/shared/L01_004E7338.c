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

typedef struct {
    u8 pad0[0xE78];
    u8 *objects[2];
    u32 padp;
    u32 pending;
    u8 pad1[0x25C0 - 0xE88];
    void *resource;
    u8 pad2[0x25E4 - 0x25C4];
    u8 disabled;
    u8 pad3[4];
    u8 enabled;
    u8 pad4;
    u8 active;
    u8 mode;
} S_004EA638;

typedef struct Cap_004EE068 {
    /* 0x000 */ u8 pad0[0x80];
    /* 0x080 */ S_4E56A8vec v80;
    /* 0x090 */ u8 pad90[0x1B8 - 0x90];
    /* 0x1B8 */ s32 f1B8;
    /* 0x1BC */ u8 pad1BC[0x260 - 0x1BC];
    /* 0x260 */ S_4E56A8vec v260;
    /* 0x270 */ f32 top;
    /* 0x274 */ f32 bottom;
    /* 0x278 */ f32 top_target;
    /* 0x27C */ f32 bottom_target;
    /* 0x280 */ f32 radius_target;
    /* 0x284 */ f32 radius;
    /* 0x288 */ f32 radius_vel;
    /* 0x28C */ u8 pad28C[0x2A7 - 0x28C];
    /* 0x2A7 */ u8 wall_hit;
    /* 0x2A8 */ u8 pad2A8[0x360 - 0x2A8];
    /* 0x360 */ s32 f360;
    /* 0x364 */ u8 pad364[0x46E - 0x364];
    /* 0x46E */ u8 f46E;
    /* 0x46F */ u8 pad46F[0x47C - 0x46F];
    /* 0x47C */ s16 f47C;
    /* 0x47E */ u8 pad47E[0x488 - 0x47E];
    /* 0x488 */ f32 f488;
    /* 0x48C */ u8 pad48C[0x1474 - 0x48C];
    /* 0x1474 */ u8 f1474;
    /* 0x1475 */ u8 pad1475;
    /* 0x1476 */ u8 f1476;
    /* 0x1477 */ u8 pad1477[0x25C4 - 0x1477];
    /* 0x25C4 */ s32 move_state;
    /* 0x25C8 */ s32 pad25C8;
    /* 0x25CC */ s32 control_mode;
    /* 0x25D0 */ s32 pad25D0;
    /* 0x25D4 */ s32 prev_control_mode;
    /* 0x25D8 */ u8 pad25D8[0x25E0 - 0x25D8];
    /* 0x25E0 */ s32 f25E0;
    /* 0x25E4 */ u8 vehicle_mode;
} Cap_004EE068;

typedef struct {
    u8 pad0[0xC18];
    f32 plane;
    f32 depth;
} Interval_004EE7F8;

typedef struct MovementView_004EEEC0 {
    u8 pad0[0x3EF];
    u8 alternate;
    u8 pad1[0x25E9 - 0x3F0];
    u8 special;
    u8 pad2[0x2838 - 0x25EA];
    f32 speed;
} MovementView_004EEEC0;

typedef struct {
    u8 pad0[0x1FC];
    s16 h1FC;
    u8 pad1FE[0xC0C - 0x1FE];
    s32 wC0C;
    u8 padC10[0xE80 - 0xC10];
    u8 *overlayE80;
    u8 padE84[0x25C0 - 0xE84];
    u8 *res25C0;
    u8 pad25C4[0x25CC - 0x25C4];
    s32 w25CC;
    u8 pad25D0[0x25E9 - 0x25D0];
    u8 b25E9;
    u8 pad25EA[0x27FC - 0x25EA];
    void *obj27FC;
    u8 pad2800[0x287C - 0x2800];
    s16 h287C;
} G_004E9D40;

typedef struct {
    u8 pad0[0x18];
    s32 category;
    u8 pad1C[0x24 - 0x1C];
    s32 primary;
    s32 held;
    s32 alternate;
    s32 flags;
    u8 pad34[0xF0 - 0x34];
    /* size 0xF0 */
} Def_004EA7D8;
typedef struct {
    u8 first[0x600];
    u8 second[0x600];
} Buf_004EA7D8;

typedef struct {
    u8 pad0[0xE78];
    s32 slots[2];
    s32 padE80;
    s32 cancel;
    u8 padE88[0x1180 - 0xE88];
    s32 idleTimer;
    u8 pad1184[0x15A0 - 0x1184];
    f32 stick;
    u8 pad15A4[0x25C0 - 0x15A4];
    s32 moby;
    s32 pad25C4;
    s32 pad25C8;
    s32 controlMode;
    u8 pad25D0[0x25E9 - 0x25D0];
    u8 active;
    u8 pad25EA;
    u8 flags;
    u8 dual;
    u8 pad25ED[0x2830 - 0x25ED];
    s32 animation;
    s32 item;
    u8 pad2838[0x2874 - 0x2838];
    s16 suppressed;
} Anim_004EA7D8;
typedef struct {
    u8 pad0[8];
    f32 weight;
    u8 pad0C[0x38 - 0xC];
    u8 *first;
    u8 *second;
} Slot_004EA7D8;

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

/* localdecomp:start func_L01_004E9238 */
extern u8 D_001A4BE0[];

s32 func_L01_004E9238(arg0)
s32 arg0;
{
    u8 *p = (arg0 * 0x50) + D_001A4BE0;

    if (*(s32 *)(p + 0x1224) == 2) {
        return *(s32 *)(p + 0x1228);
    }
    return -1;
}
/* localdecomp:end func_L01_004E9238 */

/* localdecomp:start func_L01_004E9270 */
extern s32 func_L01_004E9238();

int func_L01_004E9270(void)
{
    return func_L01_004E9238() == 30;
}
/* localdecomp:end func_L01_004E9270 */

/* localdecomp:start func_L01_004E9298 */
extern s32 func_L01_004E9238();

int func_L01_004E9298(void)
{
    return func_L01_004E9238() == 23;
}
/* localdecomp:end func_L01_004E9298 */

/* localdecomp:start func_L01_004E92C0 */
extern s32 func_L01_004E9238();

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

/* localdecomp:start func_L01_004E9370 */
extern f32 D_001A57F8[];

s32 func_L01_004E9370(s32 kind, f32 *out)
{
    *out = 0.0f;
    switch (kind) {
    case 50:
        *out = -0.95993108f;
        return 1;
    case 44: case 45: case 66: case 67:
    case 72: case 80: case 84: case 85:
        return 1;
    case 28: case 29: case 31:
        if (D_001A57F8[0] > 25.0f) {
            *out = -1.30899691f;
        }
        return 1;
    default:
        return 0;
    }
}
/* localdecomp:end func_L01_004E9370 */

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

/* localdecomp:start func_L01_004E9BB0 */
s32 func_L01_004E9BB0(s32 value) {
    switch (value) {
    case 1: return 0x60;
    case 2: return 0x5E;
    case 3: return 0x5C;
    default: return 0;
    }
}
/* localdecomp:end func_L01_004E9BB0 */

/* localdecomp:start func_L01_004E9C08 */
extern u8 D_001A4BE0[];
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L01_00439D70(M004E9888 *, s32 *);
extern void func_L01_00439E10(u8 *, u8 *);
extern f32 func_L01_004396C0(u8 *);
typedef struct { u8 *m; s32 keep; f32 target; f32 out; } E_4E9C08;
void func_L01_004E9C08(E_4E9C08 *arr, s32 n) {
    s32 i = 0;
    u8 *h;
    E_4E9C08 *e;
    if (n > i) {
        h = hero;
        e = arr;
        do {
            u8 *m = e->m;
            if (m != 0 && *(s32 *)(m + 0x34) != 0) {
                if (func_003C4138((f32 *)(m + 8), 0.0f, 0.120000005f) == 0.0f) {
                    moby_anim_layer_free(*(M004E9888 **)(h + 0x25C0), (s32 *)e);
                }
            }
            if (e->m != 0) {
                if (*(s32 *)(m + 0x34) == 0) {
                    func_003C4138((f32 *)(m + 8), e->target, 0.3f);
                }
                moby_anim_layer_update(*(u8 **)(h + 0x25C0), m);
                e->out = func_L01_004396C0(m);
                if (e->keep == 0 && (*(u8 *)(m + 5) & 2)) {
                    *(s32 *)(m + 0x34) = 1;
                    *(s32 *)(m + 0x28) = 0;
                }
            }
            i++;
            e++;
        } while (i < n);
    }
}
/* localdecomp:end func_L01_004E9C08 */

LINKER_REMNANT("asm/levels", func_L01_004E9D38);

/* localdecomp:start func_L01_004E9D40 */
__asm__(".extern D_L01_001DBDA8, 4");
extern s32 D_L01_001DBDA8;
extern u8 D_001A4BE0[];
extern u8 D_L01_00253480[];
extern u8 *func_00382348(void *);
extern s32 func_L01_004E9BB0(s32);
extern s32 func_L01_004DFD60(void);
extern u8 *func_L01_00439CB8(void *, s32, s32, s32);
extern void func_L01_00439D70(M004E9888 *, s32 *);
extern void func_L01_0043A250(u8 *, u8 *, s32, s32, s32, s32);
extern void func_L01_00439E10(u8 *, u8 *);
extern f32 func_003C4138(f32 *, f32, f32);

void func_L01_004E9D40(void)
{
    s32 enabled = 0;
    s32 id = 0;
    s32 mode;
    f32 opacity = 1.0f;
    u8 *data;
    u8 *overlay;

    if ((*(G_004E9D40 *)&D_001A4BE0).obj27FC) {
        data = func_00382348((*(G_004E9D40 *)&D_001A4BE0).obj27FC);
        if (data) {
            enabled = 1;
            id = 0x60;
            if (data[0x2C]) {
                id = func_L01_004E9BB0(data[0x2C]);
                if ((*(G_004E9D40 *)&D_001A4BE0).w25CC == 1) {
                    opacity = 0.7f;
                }
            }
        }
    }
    if ((*(G_004E9D40 *)&D_001A4BE0).h1FC) {
        enabled = 1;
        id = func_L01_004E9BB0((*(G_004E9D40 *)&D_001A4BE0).h287C);
    }
    if (func_L01_004DFD60()) {
        s32 anim = (*(G_004E9D40 *)&D_001A4BE0).res25C0[0x43];
        enabled = 1;
        if (anim == 0x4A || anim == 0x66 || anim == 0x4E) {
            if (!(*(G_004E9D40 *)&D_001A4BE0).wC0C) {
                enabled = 0;
            }
        }
        opacity = 0.8f;
        id = 0x62;
    }
    mode = func_L01_004E9238(0);
    if (mode == 0x2F || mode == 0x10 || mode == 0x11 || mode == 0x47 || mode == 0x77) {
        if ((*(G_004E9D40 *)&D_001A4BE0).b25E9) {
            enabled = 1;
            opacity = 0.8f;
            id = 0x5D;
        }
    }
    if (enabled) {
        if (!(*(G_004E9D40 *)&D_001A4BE0).overlayE80) {
            (*(G_004E9D40 *)&D_001A4BE0).overlayE80 = func_L01_00439CB8((*(G_004E9D40 *)&D_001A4BE0).res25C0, 0x18, D_L01_001DBDA8, 0x840);
            *(s32 *)((*(G_004E9D40 *)&D_001A4BE0).overlayE80 + 8) = 0;
        }
    } else {
        if (!(*(G_004E9D40 *)&D_001A4BE0).overlayE80) {
            return;
        }
        if (func_003C4138((f32 *)((*(G_004E9D40 *)&D_001A4BE0).overlayE80 + 8), 0.0f, 0.060000002f) == 0.0f) {
            func_L01_00439D70((M004E9888 *)(*(G_004E9D40 *)&D_001A4BE0).res25C0, (s32 *)&(*(G_004E9D40 *)&D_001A4BE0).overlayE80);
        }
    }
    overlay = (*(G_004E9D40 *)&D_001A4BE0).overlayE80;
    if (!overlay) {
        return;
    }
    if (!enabled) {
        return;
    }
    func_003C4138((f32 *)(overlay + 8), opacity, 0.060000002f);
    *(u8 **)((*(G_004E9D40 *)&D_001A4BE0).overlayE80 + 0x38) = D_L01_00253480;
    *(u8 **)((*(G_004E9D40 *)&D_001A4BE0).overlayE80 + 0x3C) = D_L01_00253480 + 0x600;
    if ((*(G_004E9D40 *)&D_001A4BE0).overlayE80[0x23] != id) {
        func_L01_0043A250((*(G_004E9D40 *)&D_001A4BE0).res25C0, (*(G_004E9D40 *)&D_001A4BE0).overlayE80, id, 0, 10, 1);
    }
    func_L01_00439E10((*(G_004E9D40 *)&D_001A4BE0).res25C0, (*(G_004E9D40 *)&D_001A4BE0).overlayE80);
}
/* localdecomp:end func_L01_004E9D40 */

INCLUDE_ASM("asm/levels", func_L01_004E9FB0);

/* localdecomp:start func_L01_004EA638 */
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern Def_004EA7D8 D_L01_002C5600[];
extern Buf_004EA7D8 D_L01_00255880[];
__asm__(".extern D_L01_001DBD48, 8");
__asm__(".extern D_L01_001DBDA0, 8");
extern s32 D_L01_001DBD48[2];
extern s32 D_L01_001DBDA0[2];
extern s32 func_L01_004E9238();
extern u8 *func_L01_00439CB8(void *, s32, s32, s32);
extern void func_L01_0043A1E8(void *, u8 *, s32, s32, s32, s32);

void func_L01_004EA638(s32 arg0, s32 arg1) {
    s32 id, i;

    if (((S_004EA638 *)D_001A4BE0)->disabled || !((S_004EA638 *)D_001A4BE0)->enabled ||
        !((S_004EA638 *)D_001A4BE0)->active || arg0 || !arg1)
        return;

    id = ((Def_004EA7D8 *)((u8 *)D_L01_002C5600 + D_001425C0[func_L01_004E9238(0)] * 0xF0))->held;
    if (id == -1)
        return;

    for (i = 0; i < 2; i++) {
        u8 *object;

        if (((S_004EA638 *)D_001A4BE0)->objects[i])
            continue;
        if (i == 1 && ((S_004EA638 *)D_001A4BE0)->mode != 2)
            break;

        object = func_L01_00439CB8(((S_004EA638 *)D_001A4BE0)->resource, D_L01_001DBD48[i], D_L01_001DBDA0[i], 0x3C0);
        ((S_004EA638 *)D_001A4BE0)->objects[i] = object;
        if (object) {
            ((S_004EA638 *)D_001A4BE0)->pending = 0;
            *(s32 *)(object + 8) = 0;
            *(u8 **)(object + 0x38) = D_L01_00255880[i].first;
            *(u8 **)(object + 0x3C) = D_L01_00255880[i].second;
            func_L01_0043A1E8(((S_004EA638 *)D_001A4BE0)->resource, object, id, 0, 12, 1);
            *(f32 *)(object + 0x28) = 1.0f;
        }
    }
}
/* localdecomp:end func_L01_004EA638 */

/* localdecomp:start func_L01_004EA7D8 */
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern Def_004EA7D8 D_L01_002C5600[];
extern u8 D_001439F4[];
__asm__(".extern D_L01_001DBD48, 8");
__asm__(".extern D_L01_001DBDA0, 8");
extern s32 D_L01_001DBD48[2];
extern s32 D_L01_001DBDA0[2];
extern Buf_004EA7D8 D_L01_00255880[];

extern void func_L01_004E67C0(void);
extern s32 func_00382498();
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_L01_00439D70(M004E9888 *, s32 *);
extern u8 *func_L01_00439CB8(void *, s32, s32, s32);
extern void func_L01_0043A1E8(void *, u8 *, s32, s32, s32, s32);

void func_L01_004EA7D8(s32 item)
{
    s32 duration, primary, held, blendDuration, i;
    Slot_004EA7D8 *slot;
    Def_004EA7D8 *def;

    if (item == -1)
        item = func_L01_004E9238(0);
    if (item == -1 || item == 0)
        return;
    ((Anim_004EA7D8 *)D_001A4BE0)->item = item;
    def = &D_L01_002C5600[D_001425C0[item]];
    primary = def->primary;
    held = def->held;
    if (((Anim_004EA7D8 *)D_001A4BE0)->controlMode == 12)
        held = def->alternate;
    ((Anim_004EA7D8 *)D_001A4BE0)->active = 1;
    { s32 flags = def->flags; ((Anim_004EA7D8 *)D_001A4BE0)->flags = flags; }
    duration = -1;
    if (D_L01_002C5600[D_001425C0[item]].category == 0)
        duration = 9;
    else if (primary == 0x31 || item == 0x12 || item == 0x27)
        duration = 2;
    else if (item == 0x2F)
        duration = 4;
    blendDuration = duration;
    if (blendDuration < 0)
        blendDuration = 9;
    func_L01_004E67C0();
    { s32 t = func_00382498(75, 100); ((Anim_004EA7D8 *)D_001A4BE0)->idleTimer = t; }
    if (((Anim_004EA7D8 *)D_001A4BE0)->controlMode == 0 && ((Anim_004EA7D8 *)D_001A4BE0)->suppressed == 0) {
        if (D_001439F4[0] != 1 || __builtin_fabsf(((Anim_004EA7D8 *)D_001A4BE0)->stick) < 0.17453292f) {
            ((Anim_004EA7D8 *)D_001A4BE0)->animation = primary;
            func_L01_0050FB40(primary, 0, (f32)duration);
            return;
        }
    }
    if (held == -1)
        return;
    for (i = 0; i < 2 && (i != 1 || ((Anim_004EA7D8 *)D_001A4BE0)->dual == 2); i++) {
        if (((Anim_004EA7D8 *)D_001A4BE0)->slots[i])
            func_L01_00439D70((M004E9888 *)((Anim_004EA7D8 *)D_001A4BE0)->moby, &((Anim_004EA7D8 *)D_001A4BE0)->slots[i]);
        slot = (Slot_004EA7D8 *)func_L01_00439CB8((void *)((Anim_004EA7D8 *)D_001A4BE0)->moby, D_L01_001DBD48[i], D_L01_001DBDA0[i], 0x3C0);
        ((Anim_004EA7D8 *)D_001A4BE0)->slots[i] = (s32)slot;
        if (slot) {
            ((Anim_004EA7D8 *)D_001A4BE0)->animation = held;
            ((Anim_004EA7D8 *)D_001A4BE0)->cancel = 0;
            slot->weight = 1.0f;
            slot->first = D_L01_00255880[i].first;
            slot->second = D_L01_00255880[i].second;
            func_L01_0043A1E8((void *)((Anim_004EA7D8 *)D_001A4BE0)->moby, (u8 *)slot, ((Anim_004EA7D8 *)D_001A4BE0)->animation, 0, blendDuration, 1);
        }
    }
}
/* localdecomp:end func_L01_004EA7D8 */

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

/* localdecomp:start func_L01_004EC540 */
extern u8 D_001A4BE0[];
void func_L01_004EC540(s32 a0) {
    u8 *p;
    switch (a0) {
    case 0x13:
    case 0x27:
    case 0x3F:
    case 0x97:
        p = D_001A4BE0;
        *(s16 *)(p + 0x287C) = 3;
        *(s16 *)(p + 0x1FC) = 0x3A;
        break;
    }
}
/* localdecomp:end func_L01_004EC540 */

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

/* localdecomp:start func_L01_004ED188 */
extern u8 D_001A4BE0[];
extern s32 D_L01_001DF948;
extern void func_L01_004EC600(s32);
extern void func_L01_004EC468(s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L01_004ED188(void)
{
    int i;

    for (i = 0; i < 7; i++) {
        u8 *base = D_001A4BE0;
        u8 *slot = base + i * 80;
        u8 *entry = *(u8 **)(slot + 0x1200);
        void (*callback)(u8 *);

        if (entry != 0) {
            switch (*(int *)(slot + 0x1224)) {
            case 2:
                ++*(int *)(slot + 0x1220);
                func_L01_004EC600(i);
                if ((entry[0x60] & 2) && entry[0x43] == 0
                    && (*(u8 **)(entry + 0x24))[0xC] >= 2)
                    func_003C3A10(entry, 1, 0, 2);
                break;
            case 3:
                ++slot[0x121B];
                if ((entry[0x60] & 2) || i == 1 || i == 0)
                    func_L01_004EC468(i, D_L01_001DF948 + 2);
                break;
            }
            {
                u8 *block = D_001A4BE0;

                if (*(int *)(block + 0x16B0) == 2 && i == 0
                    && *(int *)(block + 0x1228) != 9)
                    continue;
            }
            if (entry != 0 && entry[0x20] != 254 && entry[0x20] != 253 && i != 6) {
                callback = *(void (**)(u8 *))(entry + 0x64);
                if (callback != 0)
                    callback(entry);
            }
        } else {
            func_L01_004EC600(i);
        }
    }
}
/* localdecomp:end func_L01_004ED188 */

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

/* localdecomp:start func_L01_004EDFC8 */
extern u8 D_001A4BE0[];
extern u8 D_L01_001E2DC0[];
extern f32 D_L01_001E2A58[];
extern f32 func_L01_004F4E20(void *, s32);
extern f32 func_0038DBA0(f32 a, f32 b);
extern u8 *D_001D52FC;

s32 func_L01_004EDFC8(f32 a) {
    f32 f;

    if ((*(u32 *)(D_001D52FC + 416) & 3) != 0 ||
        ((*(G_004EAFF8 *)&D_001A4BE0).f16B0 != 0 && (*(func_004EA708_P *)&D_001A4BE0).h5172 != 0)) {
        if ((*(func_004EA708_P *)&D_001A4BE0).b9716 != 0) {
            f = func_L01_004F4E20(D_L01_001E2DC0, 0);
            __asm__("abs.s %0, %1" : "=f"(f) : "f"(f));
        } else {
            f = func_0038DBA0((*(func_004EA708_P *)&D_001A4BE0).f152, D_L01_001E2A58[0]);
        }
        if (f < a) {
            return 0;
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_004EDFC8 */

/* localdecomp:start func_L01_004EE068 */
extern u8 D_001A4BE0[];
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_L01_004482A0(f32 *, f32 *, f32, f32, f32, f32);

void func_L01_004EE068(s32 a0) {
    switch ((*(Cap_004EE068 *)&D_001A4BE0).vehicle_mode) {
    case 0:
        (*(Cap_004EE068 *)&D_001A4BE0).top_target = 0.8f;
        (*(Cap_004EE068 *)&D_001A4BE0).bottom_target = 0.7f;
        (*(Cap_004EE068 *)&D_001A4BE0).radius_target = 0.45f;
        break;
    case 1:
        (*(Cap_004EE068 *)&D_001A4BE0).top_target = 0.55f;
        (*(Cap_004EE068 *)&D_001A4BE0).bottom_target = 0.45f;
        (*(Cap_004EE068 *)&D_001A4BE0).radius_target = 0.25f;
        break;
    case 3:
        (*(Cap_004EE068 *)&D_001A4BE0).top_target = 0.8f;
        (*(Cap_004EE068 *)&D_001A4BE0).bottom_target = 0.6f;
        (*(Cap_004EE068 *)&D_001A4BE0).radius_target = 0.45f;
        break;
    }
    if ((*(Cap_004EE068 *)&D_001A4BE0).control_mode == 4) {
        if ((*(Cap_004EE068 *)&D_001A4BE0).f47C < (*(Cap_004EE068 *)&D_001A4BE0).f1B8 &&
            !(*(Cap_004EE068 *)&D_001A4BE0).f46E)
            (*(Cap_004EE068 *)&D_001A4BE0).bottom_target = (*(Cap_004EE068 *)&D_001A4BE0).f488;
    } else if ((*(Cap_004EE068 *)&D_001A4BE0).move_state == 6) {
        (*(Cap_004EE068 *)&D_001A4BE0).bottom_target = 0.5f;
    } else if ((*(Cap_004EE068 *)&D_001A4BE0).move_state == 4) {
        (*(Cap_004EE068 *)&D_001A4BE0).top_target = 0.3500000238418579f;
    } else if ((u32)((*(Cap_004EE068 *)&D_001A4BE0).control_mode - 17) < 2) {
        (*(Cap_004EE068 *)&D_001A4BE0).top_target = 0.0f;
        (*(Cap_004EE068 *)&D_001A4BE0).bottom_target = 0.0f;
    } else if ((*(Cap_004EE068 *)&D_001A4BE0).f1474 && (*(Cap_004EE068 *)&D_001A4BE0).f360) {
        (*(Cap_004EE068 *)&D_001A4BE0).top_target = 0.8f;
        (*(Cap_004EE068 *)&D_001A4BE0).bottom_target = 0.9f;
    } else if ((*(Cap_004EE068 *)&D_001A4BE0).move_state == 129) {
        (*(Cap_004EE068 *)&D_001A4BE0).radius_target = 0.8f;
    } else if ((*(Cap_004EE068 *)&D_001A4BE0).move_state == 80) {
        (*(Cap_004EE068 *)&D_001A4BE0).radius_target = 0.5f;
    }
    if (a0 != 0) {
        (*(Cap_004EE068 *)&D_001A4BE0).top = (*(Cap_004EE068 *)&D_001A4BE0).top_target;
        (*(Cap_004EE068 *)&D_001A4BE0).bottom = (*(Cap_004EE068 *)&D_001A4BE0).bottom_target;
        (*(Cap_004EE068 *)&D_001A4BE0).radius = (*(Cap_004EE068 *)&D_001A4BE0).radius_target;
    }
    if (!(*(Cap_004EE068 *)&D_001A4BE0).wall_hit ||
        (*(Cap_004EE068 *)&D_001A4BE0).prev_control_mode == 18 ||
        (*(Cap_004EE068 *)&D_001A4BE0).f25E0 == 18 ||
        ((*(Cap_004EE068 *)&D_001A4BE0).vehicle_mode == 0 && (*(Cap_004EE068 *)&D_001A4BE0).bottom < 0.53f) ||
        (*(Cap_004EE068 *)&D_001A4BE0).control_mode == 17 ||
        (*(Cap_004EE068 *)&D_001A4BE0).f1476 ||
        func_0038CF38(&(*(Cap_004EE068 *)&D_001A4BE0).v260, &(*(Cap_004EE068 *)&D_001A4BE0).v80) >
            (*(Cap_004EE068 *)&D_001A4BE0).radius * 0.5f) {
        func_003C4138(&(*(Cap_004EE068 *)&D_001A4BE0).top, (*(Cap_004EE068 *)&D_001A4BE0).top_target, 0.024f);
        func_003C4138(&(*(Cap_004EE068 *)&D_001A4BE0).bottom, (*(Cap_004EE068 *)&D_001A4BE0).bottom_target, 0.024f);
        func_L01_004482A0(&(*(Cap_004EE068 *)&D_001A4BE0).radius, &(*(Cap_004EE068 *)&D_001A4BE0).radius_vel,
                          (*(Cap_004EE068 *)&D_001A4BE0).radius_target, 0.0288000014f, 0.43200004f, 0.08000000566f);
    }
}
/* localdecomp:end func_L01_004EE068 */

/* localdecomp:start func_L01_004EE388 */
extern u8 D_001A4BE0[];
extern void func_L01_004EEDD0(f32 gain, f32 damping, f32 cap, s32 a);
void hero_strafe_turn(void) {
    u8 *h = hero;
    *(f32 *)(h + 0x1A0) = D_L01_001E2A40.x18;
    *(s128 *)(h + 0x190) = *(s128 *)((u8 *)&D_L01_001E2A40 + 0x380);
    *(f32 *)(h + 0x1A4) = *(f32 *)(h + 0x143C);
    hero_turn_towards(0.060480002f, 0.36f, 0.38397247f, 0);
    *(f32 *)(h + 0x143C) = *(f32 *)(h + 0x1A4);
}
/* localdecomp:end func_L01_004EE388 */

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

/* localdecomp:start func_L01_004EE7F8 */
int func_L01_004EE7F8(f32 value)
{
    Interval_004EE7F8 *root = (Interval_004EE7F8 *)D_001A4BE0;
    if (value < root->plane) {
        if (root->plane - value <= root->depth)
            return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_004EE7F8 */

/* localdecomp:start func_L01_004EE838 */
extern u8 D_001A4BE0[];
void func_L01_004EE838(void) {
    (*(S_004EAA60 *)&D_001A4BE0).a = 0;
    (*(S_004EAA60 *)&D_001A4BE0).b = 0;
}
/* localdecomp:end func_L01_004EE838 */

INCLUDE_ASM("asm/levels", func_L01_004EE850);

/* localdecomp:start func_L01_004EEBA8 */
extern u8 D_001A4BE0[];
extern s32 D_001D545C;
extern f32 D_L01_001DBE18;
extern void func_L01_004EE850(f32 max_speed, s32 mode);
void hero_walk_target(void) {
    u8 *h;
    hero_stick_move(1.0f, 0);
    h = hero;
    if (0.0f < *(f32 *)(h + 0x1B0)) {
        *(f32 *)(h + 0x1B0) = D_L01_001DBE18 * 0.020000001f * *(f32 *)(h + 0x2838);
    }
    if (level_current == 0x15 && *(u8 *)(h + 0x1479) != 0) {
        *(f32 *)(h + 0x1B0) *= 0.85f;
    }
    h = hero;
    if (*(s32 *)(h + 0x25C4) == 0x75) {
        *(f32 *)(h + 0x1B0) *= 0.8f;
        if (*(f32 *)(h + 0x1B0) < 0.050000004f) {
            *(f32 *)(h + 0x1B0) = 0.050000004f;
        }
    }
}
/* localdecomp:end func_L01_004EEBA8 */

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

/* localdecomp:start func_L01_004EEEC0 */
extern u8 D_001A4BE0[];
extern void func_L01_004EEDD0(f32 x, f32 y, f32 z, s32 a);

void func_L01_004EEEC0(void)
{
    float speed = ((MovementView_004EEEC0 *)D_001A4BE0)->speed;
    float first;
    float second;
    float third;
    if (speed == 1.0f) {
        first = 0.0316800028f;
    } else {
        first = speed * 0.0288000014f;
        if (first > 0.0316800028f)
            first = 0.0316800028f;
        if (first < 0.0144000007f)
            first = 0.0144000007f;
    }
    if (((MovementView_004EEEC0 *)D_001A4BE0)->speed == 1.0f) {
        third = 0.111701079f;
    } else {
        third = speed * 0.0767944903f;
        if (third > 0.111701079f)
            third = 0.111701079f;
        if (third < 0.038397245f)
            third = 0.038397245f;
    }
    second = 0.388800025f;
    if (((MovementView_004EEEC0 *)D_001A4BE0)->alternate) {
        first = 0.050400004f;
        third = 0.233874128f;
    }
    switch (func_L01_004E9238(0)) {
    case 16:
    case 17:
    case 39:
    case 47:
        if (((MovementView_004EEEC0 *)D_001A4BE0)->special && !((MovementView_004EEEC0 *)D_001A4BE0)->alternate) {
            if (speed > 0.95f) {
                first = 0.0244800021f;
                second = 0.259200007f;
                third = 0.174532936f;
            } else {
                first = speed * 0.01296f;
                second = 0.216000021f;
                third = speed * 0.094247788f;
            }
        }
        break;
    default:
        break;
    }
    func_L01_004EEDD0(first, second, third, 0);
}
/* localdecomp:end func_L01_004EEEC0 */

/* localdecomp:start func_L01_004EF128 */
extern u8 D_001A4BE0[];
extern f32 func_003C4138(f32 *, f32, f32);
void hero_approach_speed(f32 accel, f32 decel) {
    u8 *h = hero;
    if (*(f32 *)(h + 0x1B4) < *(f32 *)(h + 0x1B0)) {
        func_003C4138((f32 *)(h + 0x1B4), *(f32 *)(h + 0x1B0), accel);
    } else {
        func_003C4138((f32 *)(h + 0x1B4), *(f32 *)(h + 0x1B0), decel);
    }
}
/* localdecomp:end func_L01_004EF128 */

/* localdecomp:start func_L01_004EF178 */
extern u8 D_001A4BE0[];
extern char D_001A4CD0[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_00382760(void *, f32, f32, f32);
void hero_velocity_along(f32 yaw) {
    u8 *h = hero;
    Vec4 out;
    f32 ang = *(f32 *)(h + 0x98);
    f32 speed;
    if (yaw <= 3.1415927f) {
        ang = yaw;
    }
    speed = *(f32 *)(h + 0x1B4);
    if (*(u8 *)(h + 0x25F4)) {
        Vec4 v;
        f32 z = 0.0f;
        v.f[0] = func_0038D098(z) * speed;
        v.f[1] = func_0038D0B0(z) * speed;
        v.f[2] = z;
        func_0038D028(&v, &v, h);
        out.q = v.q;
    } else {
        func_00382760(&out, speed, ang, *(f32 *)(h + 0x344));
    }
    *(u128_t *)D_001A4CD0 = out.q;
}
/* localdecomp:end func_L01_004EF178 */

/* localdecomp:start func_L01_004EF238 */
extern char D_001A4CD0[];
extern void func_0038CF68(void *, s32, float);
void func_L01_004EF238(s32 a0) {
    char *p = D_001A4CD0;
    func_0038CF68(p, a0, *(float *)(p + 196));
}
/* localdecomp:end func_L01_004EF238 */

INCLUDE_ASM("asm/levels", func_L01_004EF268);
