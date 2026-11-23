#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3B9B00;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3B9B00 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3B9B00;
typedef struct { u8 b[256]; } C_3B9B00;
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3B9D08;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3B9D08 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3B9D08;
typedef struct { u8 b[256]; } C_3B9D08;
typedef struct {
    u8 pad0[28];
    f32 f28;
    u8 pad1[104];
    f32 f136;
    u8 pad2[28];
    s32 i168;
    u8 pad3[4];
    u8 v176[16];
} V_003B9F08;
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 b33;
    u8 pad1[15];
    u8 b49;
    u8 pad2[2];
    u16 h52;
    u8 pad3[50];
    V_003B9F08 *vars;
    u8 pad4[62];
    s16 oclass;
    u8 pad5[84];
} M_003B9F08;
typedef struct {
    u8 pad0[28];
    f32 f28;
    u8 pad1[104];
    f32 f136;
    u8 pad2[28];
    s32 i168;
    u8 pad3[4];
    u8 v176[16];
} V_003BA0F8;
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 b33;
    u8 pad1[15];
    u8 b49;
    u8 pad2[2];
    u16 h52;
    u8 pad3[50];
    V_003BA0F8 *vars;
    u8 pad4[62];
    s16 oclass;
    u8 pad5[84];
} M_003BA0F8;
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3BA2E8;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3BA2E8 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3BA2E8;
typedef struct { u8 b[256]; } C_3BA2E8;
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3BA4F0;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3BA4F0 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3BA4F0;
typedef struct { u8 b[256]; } C_3BA4F0;
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3BA6D0;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3BA6D0 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3BA6D0;
typedef struct { u8 b[256]; } C_3BA6D0;
typedef struct {
    u8 pad0[28];
    f32 phase;
    u8 pad20[136 - 32];
    f32 size;
    u8 pad8C[168 - 140];
    s32 range;
    u8 padAC[4];
    u8 trail0[32];
    u8 trail1[32];
} Vars_003BA8B0;
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 group;
    u8 pad22[49 - 34];
    u8 visible;
    u8 pad32[2];
    u16 flags;
    u8 pad36[104 - 54];
    Vars_003BA8B0 *vars;
    u8 pad6C[170 - 108];
    s16 oclass;
    u8 padAC[84];
} Moby_003BA8B0;
typedef struct {
    u8 pad[0x1C];
    f32 f1C;
    u8 pad2[0x88 - 0x20];
    f32 f88;
    u8 pad3[0xA8 - 0x8C];
    int xA8;
    u8 pad4[0xB0 - 0xAC];
    u8 xB0[4];
} S_3BAAD8v;
typedef struct {
    u8 pad[0x20];
    u8 b20;
    u8 b21;
    u8 pad2[0x31 - 0x22];
    u8 b31;
    u8 pad3[0x34 - 0x32];
    u16 h34;
    u8 pad4[0x68 - 0x36];
    S_3BAAD8v *v;
    u8 pad5[0xAA - 0x6C];
    s16 hAA;
} S_3BAAD8m;

typedef struct {
    u8 pad[0x24];
    f32 f24;
} P_003B8B50;
typedef struct {
    u8 pad[0xC];
    s32 iC;
    u8 pad2[0xAC - 0x10];
    s16 hAC;
} V_003B8B50;
typedef struct {
    u8 pad[0x20];
    u8 b20;
    u8 b21;
    u8 pad2[0x24 - 0x22];
    P_003B8B50 *p24;
    u8 pad3[0x2C - 0x28];
    f32 f2C;
    u8 pad4[0x34 - 0x30];
    u16 h34;
    u8 pad5[0x68 - 0x36];
    V_003B8B50 *v;
    u8 pad6[0xAA - 0x6C];
    s16 hAA;
} M_003B8B50;

typedef struct {
    u8 pad0[0x84];
    s16 h84;
    u8 pad86[0x9C - 0x86];
    s32 i9C;
} V_003BB258;
typedef struct {
    u8 pad0[0x68];
    V_003BB258 *vars;
    u8 pad6C[0x78 - 0x6C];
    s32 i78;
    u8 pad7C[0xAA - 0x7C];
    s16 hAA;
} M_003BB258;


/* localdecomp:start func_L01_003BC530 */
extern void (**func_L01_0043B568(s32, s32, s32))(void *, void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern u8 D_L01_001E2A40[];
extern u8 D_L01_002BB070[];

void func_L01_003BC530(u8 *a0) {
    void (**p)(void *, void *);
    s32 h;

    switch (a0[0x20]) {
    case 0:
        p = func_L01_0043B568(0x194C, 0, 4);
        if (p != 0) {
            (*p)(a0, D_L01_002BB070);
        }
        goto call;
    case 1:
        goto body;
    case 2:
        if (a0[0x31] != 0) {
            if (func_L01_0040E548(D_L01_001E2A40, a0 + 0x10) < 1024.0f) {
                func_L01_004472C0(a0);
                a0[0x6F] = 0x1E;
            }
        }
        break;
    case 3:
        h = *(u16 *)(a0 + 0x96) + 1;
        *(u16 *)(a0 + 0x96) = h;
        if ((u16)h < 0x1F5) {
            break;
        }
    call:
        func_L01_004450F0(a0, 1, -1);
    body:
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(a0 + 0x98) = 0;
        func_L01_004AA7E8(a0, 1);
        *(u16 *)(a0 + 0x34) |= 2;
        break;
    }
}
/* localdecomp:end func_L01_003BC530 */

/* localdecomp:start func_L01_003BC658 */
u8 *func_L01_003BC658(void) {
    return D_L01_002BB070;
}
/* localdecomp:end func_L01_003BC658 */

/* localdecomp:start func_L01_003BC668 */
extern u8 D_L01_001D66B0[8];
extern u8 *func_L01_0045B958(void *);
extern void func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2, f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern s32 func_003A52A0(s32, s32, void *);

void func_L01_003BC668(u8 *a0) {
    vu0_q loc;
    vu0_q *lp;
    u8 *p;

    lp = &loc;
    loc = *(vu0_q *)D_L01_001D66B0;
    p = func_L01_0045B958(a0);
    if (p != 0) {
        loc = *(vu0_q *)(p + 0xA0);
    }
    func_L01_003303B8(a0 + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 2.5f, 0.0f, 0.0f, 2.0f, 1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_L01_00452310(a0, 0x1FFF, lp, 1, 0x14, -1.0f, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
    func_003A52A0(3, 0, a0);
}
/* localdecomp:end func_L01_003BC668 */

/* localdecomp:start func_L01_003BC7D0 */
extern void func_003C2880(void *);
extern s32 func_L01_003BC920(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_00404A10_003BC7D0(void *, void *);
extern void func_L01_003BC978(u8 *);
extern f32 D_L01_001DE9AC;
__asm__(".extern D_L01_001DE9AC, 4");
extern f32 D_L01_001DE9B4;
__asm__(".extern D_L01_001DE9B4, 4");
extern f32 D_L01_001DE9C4;
__asm__(".extern D_L01_001DE9C4, 4");
extern f32 D_L01_001DE9C8;
__asm__(".extern D_L01_001DE9C8, 4");

void func_L01_003BC7D0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    f32 t;
    f32 g;

    if (*(s32 *)(v + 0x14) != 0) {
        g = D_L01_001DE9AC;
        *(f32 *)(v + 0x10) = *(f32 *)(v + 0x10) - g;
        if (*(f32 *)(v + 0x10) < g) {
            func_003C2880(a0);
            return;
        }
    } else if (*(f32 *)(v + 0x10) < 1.0f) {
        t = *(f32 *)(v + 0x10) + D_L01_001DE9AC;
        *(f32 *)(v + 0x10) = t;
        if (1.0f < t) {
            *(f32 *)(v + 0x10) = 1.0f;
        }
    }
    if (func_L01_003BC920(a0, v) != 0) {
        *(f32 *)(v + 0x18) = *(f32 *)(v + 0x18) + ((1.0f - *(f32 *)(v + 0x18)) * D_L01_001DE9C4 + D_L01_001DE9C8);
    } else {
        *(f32 *)(v + 0x18) = *(f32 *)(v + 0x18) - (*(f32 *)(v + 0x18) * D_L01_001DE9C4 + D_L01_001DE9C8);
    }
    if (*(f32 *)(v + 0x18) > 1.0f) {
        *(f32 *)(v + 0x18) = 1.0f;
    } else if (*(f32 *)(v + 0x18) < 0.0f) {
        *(f32 *)(v + 0x18) = 0.0f;
    }
    *(f32 *)(a0 + 0xF0) = func_0038DAB8(*(f32 *)(a0 + 0xF0), D_L01_001DE9B4);
    func_L01_00404A10_003BC7D0(func_L01_003BC978, a0);
}
/* localdecomp:end func_L01_003BC7D0 */

/* localdecomp:start func_L01_003BC920 */
extern f32 func_0038CF00(void *, void *);
extern s32 func_0038DC20(void *, f32);
extern u8 D_L01_001E29C0[];
extern f32 D_L01_001DE9B8;
__asm__(".extern D_L01_001DE9B8, 4");
extern f32 D_L01_001DE9BC;
__asm__(".extern D_L01_001DE9BC, 4");
extern f32 D_L01_001DE9C0;
__asm__(".extern D_L01_001DE9C0, 4");

s32 func_L01_003BC920(void *a0, void *a1) {
    f32 t = func_0038CF00(a1, D_L01_001E29C0);
    f32 g = D_L01_001DE9C0;
    *(f32 *)((u8 *)a1 + 0xC) = D_L01_001DE9B8 + t * D_L01_001DE9BC;
    return func_0038DC20(a1, g) == 1;
}
/* localdecomp:end func_L01_003BC920 */

/* localdecomp:start func_L01_003BC978 */
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(f32, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038C750(void);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern u8 D_L01_001E29E0_003BC978[];
__asm__(".extern D_L01_001DE990, 8");
extern u8 D_L01_001DE990;
__asm__(".extern D_L01_001DE9E0, 8");
extern u8 D_L01_001DE9E0;
extern u8 D_L01_002BB0F0[];
extern u8 D_L01_002BB170[];
extern u8 D_L01_002BB260[];
extern f32 D_L01_002A2D70[];
extern s32 D_L01_001E2178;
__asm__(".extern D_L01_001E2178, 64");
extern u8 D_L01_001E2880_003BC978[];
extern u8 D_001A4BE0[];
__asm__(".extern D_L01_001DE980, 4");
extern f32 D_L01_001DE980;
__asm__(".extern D_L01_001DE984, 4");
extern f32 D_L01_001DE984;
__asm__(".extern D_L01_001DE9A0, 4");
extern f32 D_L01_001DE9A0;
__asm__(".extern D_L01_001DE9A4, 4");
extern f32 D_L01_001DE9A4;
__asm__(".extern D_L01_001DE9A8, 4");
extern f32 D_L01_001DE9A8;
__asm__(".extern D_L01_001DE9CC, 4");
extern f32 D_L01_001DE9CC;
__asm__(".extern D_L01_001DE9D0, 4");
extern f32 D_L01_001DE9D0;
__asm__(".extern D_L01_001DE9D4, 4");
extern s32 D_L01_001DE9D4;

void func_L01_003BC978(u8 *a) {
    f32 p0[4];
    f32 p10[4];
    f32 p20[4];
    f32 p30[4];
    f32 p40[4];
    f32 p50[4];
    f32 p60[4];
    f32 p70[4];
    f32 p80[4];
    u8 *v;
    f32 f20;
    f32 t;
    f32 u;
    f32 r;
    f32 g;
    f32 q;
    s32 i;
    u8 *pb;
    s32 n1;
    s32 n2;
    u8 *src1;
    u8 *src2;
    u8 *dst1;
    u8 *dst2;
    f32 *o;
    s32 *w;
    s32 k;
    f32 x0;
    f32 x1;
    f32 x2;
    u8 *s;

    v = *(u8 **)(a + 0x68);
    pb = D_L01_001E2880_003BC978;
    func_0038D000(p20, &D_L01_001DE990, D_L01_001E29E0_003BC978);
    func_0038CF68(D_L01_001DE9A0, p0, p20);
    vec_add_ab(p0, p0, (D_L01_001E29E0_003BC978 - 0x20));
    vec_sub_ba(p20, v, (D_L01_001E29E0_003BC978 - 0x20));
    func_0038CF68(D_L01_001DE9A0, p10, p20);
    vec_add_ab(p10, p10, (D_L01_001E29E0_003BC978 - 0x20));
    vec_sub_ba(p20, p10, p0);
    func_0038CE20(p30, p20, *(f32 *)(v + 0x18));
    vec_add_ba(p30, p30, p0);
    vec_sub_ba(p20, p30, (D_L01_001E29E0_003BC978 - 0x20));
    func_0038CF68(D_L01_001DE9A0, p30, p20);
    vec_add_ab(p30, p30, (D_L01_001E29E0_003BC978 - 0x20));
    t = *(f32 *)(v + 0x10);
    u = *(f32 *)(v + 0x18);
    q = t * D_L01_001DE9A4;
    f20 = t * D_L01_001DE9A8;
    f20 -= q;
    f20 *= u;
    f20 += q;
    *(f32 *)(a + 0x2C) = *(f32 *)(*(u8 **)(a + 0x24) + 0x24) * f20;
    vec_sub_ba(p20, v, D_001A4BE0 + 0x80);
    *(f32 *)(a + 0xF8) = func_0038D160(p20[0], p20[1]);
    r = func_0038DBA0(*(f32 *)(a + 0xF8), *(f32 *)(D_L01_001E29E0_003BC978 - 8));
    r -= 1.5707964f;
    r *= 0.63661975f;
    r *= D_L01_001DE9CC;
    *(f32 *)(a + 0xF4) = (D_L01_001DE9D0 - r) * *(f32 *)(v + 0x18) + r;
    func_0038D308(a + 0xC0, a + 0xF0);
    func_0038CE20(p20, a + 0xC0, (*(f32 *)(v + 0x18) * 0.5f + 0.5f) * f20 * D_L01_001DE980);
    vec_sub_ab(p30, p30, p20);
    func_0038D328(p50, a + 0xF0);
    func_0038CE20(p50, p50, D_L01_001DE980 * f20);
    func_0038CE20(p60, p60, D_L01_001DE984 * f20);
    func_0038CE20(p70, p70, D_L01_001DE984 * f20);
    *(vu0_q *)p80 = *(vu0_q *)p30;
    p80[3] = 1.0f;
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x5360B);
    func_003A9440(6, func_00389598(D_L01_001DE9D4));
    func_003A9440(0x42, 0x8000000044UL);
    func_0038C750();
    w = &D_L01_001E2178 + 15;
    k = 0x411465B7;
    for (i = 15; i >= 0; i--) {
        *w = k;
        w--;
    }
    if (func_0038DBA0(*(f32 *)(a + 0xF8), *(f32 *)(pb + 0x158)) < 1.5707964f) {
        dst1 = &D_L01_001DE9E0;
        src1 = D_L01_002BB0F0;
        n1 = 8;
        src2 = D_L01_002BB170;
        n2 = 15;
        dst2 = D_L01_002BB260;
    } else {
        dst2 = &D_L01_001DE9E0;
        src1 = D_L01_002BB170;
        n1 = 15;
        dst1 = D_L01_002BB260;
        n2 = 8;
        src2 = D_L01_002BB0F0;
    }
    for (i = 0; i < n1; i++) {
        func_0038D028(p40, src1 + i * 0x10, p50);
        x0 = p40[0];
        x1 = p40[1];
        x2 = p40[2];
        D_L01_002A2D70[i * 3] = x0;
        D_L01_002A2D70[i * 3 + 1] = x1;
        D_L01_002A2D70[i * 3 + 2] = x2;
    }
    func_003D3A24(n1, D_L01_002A2D70, &D_L01_001E2178, dst1, 1);
    for (i = 0; i < n2; i++) {
        func_0038D028(p40, src2 + i * 0x10, p50);
        x0 = p40[0];
        x1 = p40[1];
        x2 = p40[2];
        D_L01_002A2D70[i * 3] = x0;
        D_L01_002A2D70[i * 3 + 1] = x1;
        D_L01_002A2D70[i * 3 + 2] = x2;
    }
    func_003D3A24(n2, D_L01_002A2D70, &D_L01_001E2178, dst2, 1);
}
/* localdecomp:end func_L01_003BC978 */
