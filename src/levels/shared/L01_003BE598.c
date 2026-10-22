#include "common.h"

typedef struct {
    u8 pad[0x68];
    u8 *w68;
} Moby_003BD218;
typedef int s128_3C1AB8 __attribute__((mode(TI)));
typedef union { s128_3C1AB8 q; f32 f[4]; } V_3C1AB8;
typedef struct {
    u8 pad[0x38];
    f32 f38;
    u8 pad3C[0x180 - 0x3C];
    s128_3C1AB8 v180;
    s128_3C1AB8 v190;
    s128_3C1AB8 v1A0;
    u8 pad1B0[0x1D0 - 0x1B0];
    s32 w1D0;
} P_3C1AB8;
typedef struct {
    u8 pad[0x10];
    s128_3C1AB8 pos;
    u8 pad20[0x68 - 0x20];
    P_3C1AB8 *p68;
} M_3C1AB8;
typedef int s128_3C1EE0 __attribute__((mode(TI)));
typedef struct { u8 pad[0x20]; u8 b20; } M_3C1EE0;
typedef struct {
    u8 pad0;
    u8 unk1;
    u8 pad2[106];
    f32 unk6C;
    u8 pad70[128];
} S_002C5640;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[88];
    s32 a[6];
    s32 b[4];
    s32 c[4];
    u8 pad1[224];
    u8 d[16];
} Obj_003C3C68;
typedef int u128_3C3E90 __attribute__((mode(TI)));
typedef struct { u8 pad[0x25C4]; s32 w25C4; u8 pad25C8[0x283C - 0x25C8]; f32 f283C; } G_3C4008;
typedef struct { u8 pad[0x98]; s32 w98; } P_3C4008;
typedef struct { u8 pad[0x54]; P_3C4008 *p54; u8 pad58[0x100 - 0x58]; u8 b100; } B_3C4008;
typedef struct { u8 pad[0x20]; u8 b20; } M_3C4008;
typedef struct {
    u8 pad0[1724];
    s32 idx;
    s32 arr[1];
} S_3C40F0;
typedef struct {
    u8 p0[0x24];
    s32 id;
    u8 p28[0x698];
    s32 a1728[36];
    s32 a1872[4];
} O_3C41F8;
typedef struct { u8 p0[0x34]; u16 h52; u8 p36[0xCA]; } M_3C41F8;
typedef struct M3C48A8 M3C48A8;
typedef struct {
    u8 pad0[80];
    s32 link;
    u8 pad84[1360 - 84];
    M3C48A8 *child;
} V3C48A8;
struct M3C48A8 {
    u8 pad0[32];
    u8 state;
    u8 pad21[52 - 33];
    u16 flags;
    u8 pad36[104 - 54];
    V3C48A8 *vars;
    u8 pad6C[152 - 108];
    s32 f98;
    u8 pad9C[256 - 156];
};
typedef struct {
    u8 pad0[258];
    u8 active;
    u8 pad103[264 - 259];
    s32 group;
} O3C48A8;

LINKER_REMNANT("asm/levels", func_L01_003BE598);

INCLUDE_ASM("asm/levels", func_L01_003BE5A0);

LINKER_REMNANT("asm/levels", func_L01_003BEA58);

/* localdecomp:start func_L01_003BEA60 */

extern s32 D_L01_001D6740;
extern s16 D_001A4F48[];

s32 func_L01_003BEA60(Moby_003BD218 *m) {
    u8 *p = m->w68;
    if ((p != 0 && *(s32 *)(p + 264) == 2) || D_L01_001D6740 != 0 || D_001A4F48[0] != 0) return 1;
    return 0;
}
/* localdecomp:end func_L01_003BEA60 */

/* localdecomp:start func_L01_003BEAA0 */
extern s32 D_L01_001D673C_003BEAA0;
s32 func_L01_003BEAA0(void) {
    return D_L01_001D673C_003BEAA0;
}
/* localdecomp:end func_L01_003BEAA0 */

/* localdecomp:start func_L01_003BEAA8 */
s32 func_L01_003BEAA8(u32 a) {
    s32 r = 0;
    if (a < 2 || a == 11 || a == 13 || a == 14) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_003BEAA8 */

INCLUDE_ASM("asm/levels", func_L01_003BEAE0);

INCLUDE_ASM("asm/levels", func_L01_003C1978);

INCLUDE_ASM("asm/levels", func_L01_003C27E0);

INCLUDE_ASM("asm/levels", func_L01_003C2E10);

INCLUDE_ASM("asm/levels", func_L01_003C2E48);

INCLUDE_ASM("asm/levels", func_L01_003C2E88);

/* localdecomp:start func_L01_003C3320 */
extern s32 D_L01_001EAA18[];
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, M_3C1AB8 *, s32);
void func_L01_003C3320(M_3C1AB8 *m) {
    V_3C1AB8 a;
    V_3C1AB8 b;
    P_3C1AB8 *p;
    a.q = m->pos;
    p = m->p68;
    a.f[2] += 0.1f;
    b.q = p->v190;
    a.f[2] += p->f38;
    b.f[2] += p->f38;
    if (3600.0f <= func_L01_0040E548(&a, &b)) {
        return;
    }
    if (func_003D3CB0(&a, &b, 16, m, 0) != 0) {
        if (D_L01_001EAA18[0] == 0) {
            return;
        }
        if (D_L01_001EAA18[0] != p->w1D0) {
            return;
        }
    }
    p->v180 = p->v190;
    p->v1A0 = p->v190;
}
/* localdecomp:end func_L01_003C3320 */

LINKER_REMNANT("asm/levels", func_L01_003C3408);

INCLUDE_ASM("asm/levels", func_L01_003C3410);

INCLUDE_ASM("asm/levels", func_L01_003C35A0);

/* localdecomp:start func_L01_003C3748 */
extern void func_003C2F58(M_3C1EE0 *, s32, s128_3C1EE0 *);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
void func_L01_003C3748(M_3C1EE0 *m) {
    s128_3C1EE0 v;
    u32 col;
    if (m == 0) {
        return;
    }
    if (m->b20 == 254) {
        return;
    }
    if (m->b20 == 253) {
        return;
    }
    col = (m->b20 == 5) ? 0x40202080 : 0x40802020;
    func_003C2F58(m, 2, &v);
    func_003D9508(&v, 11, col, 1, 0.1f, 0.08f, 0.0f);
    func_003C2F58(m, 3, &v);
    func_003D9508(&v, 11, col, 1, 0.1f, 0.08f, 0.0f);
}
/* localdecomp:end func_L01_003C3748 */

INCLUDE_ASM("asm/levels", func_L01_003C3830);

INCLUDE_ASM("asm/levels", func_L01_003C3898);

INCLUDE_ASM("asm/levels", func_L01_003C38D0);

/* localdecomp:start func_L01_003C39A8 */

extern u8 D_001425C0[];
extern S_002C5640 D_L01_002C5600[];

extern void func_L01_004C7D98(u8 *, u8 *);
extern u8 *func_L01_00392908(u8 *, u8 *);
extern void func_003A52A0(s32, s32, u8 *);
extern s32 func_L01_003BEAA0_003C39A8(void);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00446780(u8 *, u8 *, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_003C38D0(u8 *);

void func_L01_003C39A8(u8 *arg0) {
    u8 buf[16];
    u8 *v;
    u8 x;
    s32 t;

    x = D_L01_002C5600[D_001425C0[87]].unk1;
    t = x < 4;
    if (!t) {
        func_L01_004C7D98(arg0 + 16, buf);
        v = func_L01_00392908(arg0 + 16, buf);
        if (v != 0) {
            *(s32 *)(v + 184) = *(s32 *)(arg0 + 184);
        }
    } else if (x == 0 || !t) {
        func_003A52A0(0, 0, arg0);
        func_L01_003303B8(arg0 + 16, 0, 20, 20, 20, 20, 0, 2, 0.5f, 0.0f, 0.0f, 2.0f,
                      func_L01_003BEAA0_003C39A8() == 0, 1, 0, 0, 1, 1, 0x1010000, 0, 0x388EF7, 25591, 0x407FFF, 8447, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L01_00446780(arg0, arg0 + 16, 0x1010000, 0, 1, 0, 2.0f, D_L01_002C5600[D_001425C0[87]].unk6C, 0.0f);
    }
    if (func_L01_004CB2D8() != 0) {
        func_L01_003303B8(arg0 + 16, 0, 3, 3, 3, 6, 3, 0, 0.5f, 0.0f, 0.0f, 2.0f,
                      0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 25591, 0x407FFF, 8447, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
    func_L01_003C38D0(arg0);
}
/* localdecomp:end func_L01_003C39A8 */

INCLUDE_ASM("asm/levels", func_L01_003C3C50);

/* localdecomp:start func_L01_003C3CE8 */
extern s32 D_L01_002BB3E0[];
s32 *func_L01_003C3CE8(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 104;
        return D_L01_002BB3E0;
    }
    return 0;
}
/* localdecomp:end func_L01_003C3CE8 */

INCLUDE_ASM("asm/levels", func_L01_003C3D08);

INCLUDE_ASM("asm/levels", func_L01_003C4C40);

/* localdecomp:start func_L01_003C5110 */

extern void func_003C7C38(u8 *a0);

void func_L01_003C5110(void *a0, u8 *a1) {
    s32 i;
    u8 **pp = (u8 **)(a1 + 64);
    for (i = 4; i >= 0; i--) {
        u8 *m = *pp++;
        if (m != 0) {
            u8 *v = *(u8 **)(m + 104);
            func_003C7C38(m);
            *(u128_t *)(v + 112) = *(u128_t *)(m + 16);
            *(u128_t *)(v + 128) = *(u128_t *)(m + 240);
        }
    }
}
/* localdecomp:end func_L01_003C5110 */

INCLUDE_ASM("asm/levels", func_L01_003C5188);

/* localdecomp:start func_L01_003C5220 */

extern void func_0038D308(u8 *, u8 *);
extern void func_L01_0044F450(u8 *, u8 *);
extern void func_L01_003C5188(u8 *, u8 *);

void func_L01_003C5220(u8 *a0, u8 *a1) {
    func_0038D308(a0 + 192, a0 + 240);
    func_L01_0044F450(a0, a1 + 368);
    *(u128_t *)(a1 + 272) = *(u128_t *)(a0 + 16);
    *(u128_t *)(a1 + 288) = *(u128_t *)(a0 + 240);
    *(f32 *)(a1 + 248) = *(f32 *)(a1 + 1652);
    *(f32 *)(a1 + 252) = *(f32 *)(a1 + 1704);
    func_L01_003C5188(a0, a1);
}
/* localdecomp:end func_L01_003C5220 */

INCLUDE_ASM("asm/levels", func_L01_003C5290);

/* localdecomp:start func_L01_003C54E8 */
extern void func_L01_003C5CA8(void *self, u8 *obj);

extern void func_L01_0044F8D8(void *, s32);
extern void func_003CD250(s32);

void func_L01_003C54E8(void *self, Obj_003C3C68 *o) {
    s32 i;

    func_L01_0044F8D8(o->d, 0);
    ((void (*)(void *, Obj_003C3C68 *))func_L01_003C5CA8)(self, o);
    for (i = 0; i < 6; i++) {
        if (o->a[i] != 0) {
            func_003CD250(o->a[i]);
            o->a[i] = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (o->b[i] != 0) {
            func_003CD250(o->b[i]);
            o->b[i] = 0;
        }
        if (o->c[i] != 0) {
            func_003CD250(o->c[i]);
            o->c[i] = 0;
        }
    }
}
/* localdecomp:end func_L01_003C54E8 */

INCLUDE_ASM("asm/levels", func_L01_003C55B8);

/* localdecomp:start func_L01_003C55F8 */
extern s32 D_L01_001DEE54;
s32 func_L01_003C55F8(void) {
    return D_L01_001DEE54;
}
/* localdecomp:end func_L01_003C55F8 */

/* localdecomp:start func_L01_003C5600 */
u8 func_L01_003C5600(u8 *a) {
    return *(*(u8 **)(a + 0x68) + 0x103);
}
/* localdecomp:end func_L01_003C5600 */

/* localdecomp:start func_L01_003C5610 */
extern void func_L01_003C6F68(void *, s32);
void func_L01_003C5610(void *p) {
    func_L01_003C6F68(p, *(s32 *)((u8 *)p + 0x68));
}
/* localdecomp:end func_L01_003C5610 */

/* localdecomp:start func_L01_003C5630 */
extern void func_L01_003C6EF0(void *, s32);
void func_L01_003C5630(void *p) {
    func_L01_003C6EF0(p, *(s32 *)((u8 *)p + 0x68));
}
/* localdecomp:end func_L01_003C5630 */

/* localdecomp:start func_L01_003C5650 */
extern void func_L01_00456230(u8 *o, s32 a);

void func_L01_003C5650(u8 *a) {
    u8 *p = *(u8 **)(a + 104);
    func_L01_00456230(a, 1);
    p[259] = 1;
}
/* localdecomp:end func_L01_003C5650 */

/* localdecomp:start func_L01_003C5688 */
void func_L01_003C5688(u8 *obj) {
    (*(u8 **)(obj + 104))[259] = 1;
}
/* localdecomp:end func_L01_003C5688 */

INCLUDE_ASM("asm/levels", func_L01_003C5698);

/* localdecomp:start func_L01_003C5710 */

void func_L01_003C5710(u8 *a0, u128_3C3E90 *a1, u128_3C3E90 *a2) {
    *(u128_3C3E90 *)(a0 + 0x00) = *a1;
    *(u128_3C3E90 *)(a0 + 0x10) = *a2;
}
/* localdecomp:end func_L01_003C5710 */

/* localdecomp:start func_L01_003C5728 */
extern void func_L01_003C5110(void *a0, u8 *a1);

extern void func_L01_003C5710(u8 *, u128_t *, u128_t *);
extern void func_0038D308(u8 *, u8 *);
extern void func_L01_0044F450(u8 *, u8 *);

void func_L01_003C5728(u8 *m, u8 *b, u128_t *pos, u128_t *dir) {
    func_L01_003C5710(b, pos, dir);
    *(u128_t *)(m + 16) = *pos;
    *(u128_t *)(m + 240) = *dir;
    func_0038D308(m + 192, m + 240);
    func_L01_0044F450(m, b + 368);
    ((void (*)(u8 *, u8 *))func_L01_003C5110)(m, b);
}
/* localdecomp:end func_L01_003C5728 */

/* localdecomp:start func_L01_003C57B0 */
extern void func_L01_003C5728(u8 *m, u8 *b, u128_t *pos, u128_t *dir);
extern char *D_L01_001E0100;
void func_L01_003C57B0(void *a, void *b, int i) {
    char *p = D_L01_001E0100 + i * 128;
    ((void (*)(void *, void *, char *, char *))func_L01_003C5728)(a, b, p + 48, p + 112);
}
/* localdecomp:end func_L01_003C57B0 */

/* localdecomp:start func_L01_003C57E0 */
extern u8 D_001A4BE0[];
extern s32 func_00382380(u8 *, s32, s32);
extern void func_L01_00456230(u8 *o, s32 a);

void func_L01_003C57E0(u8 *a0, u8 *a1) {
    u8 *p = D_001A4BE0;
    s32 v = *(s32 *)(p + 9668);
    if (v == 116 || v == 49 || v == 101) {
        return;
    }
    if (*(s32 *)(p + 860) == *(s32 *)(a1 + 72) ||
        (*(s32 *)(a1 + 204) != -1 && func_00382380(p + 128, *(s32 *)(a1 + 204), 0) != 0)) {
        func_L01_00456230(a0, 1);
        a1[259] = 1;
    } else {
        func_L01_00456230(a0, 0);
    }
}
/* localdecomp:end func_L01_003C57E0 */

/* localdecomp:start func_L01_003C5888 */
extern u8 D_001A4BE0[];
extern s32 func_L01_00511A98(void);
extern void func_L01_00511AE8(void);
extern s32 func_L01_003C6860(M_3C4008 *);
extern s32 func_L01_00456250(M_3C4008 *);
void func_L01_003C5888(M_3C4008 *m, B_3C4008 *b) {
    if (b->b100 == 0) {
        return;
    }
    if (func_L01_00511A98() != 0) {
        if (b->b100 == 2) {
            return;
        }
        if ((*(G_3C4008 *)&D_001A4BE0).w25C4 == 105) {
            return;
        }
        if (m->b20 == 5 && func_L01_003C6860(m) != 0) {
            if (b->p54 == 0) {
                return;
            }
            if (b->p54->w98 == 0) {
                return;
            }
        }
        if (func_L01_00456250(m) != 0) {
            return;
        }
        if (!(0.9f < (*(G_3C4008 *)&D_001A4BE0).f283C)) {
            return;
        }
        func_L01_00511AE8();
        b->b100 = 0;
    } else {
        b->b100 = 0;
    }
}
/* localdecomp:end func_L01_003C5888 */

/* localdecomp:start func_L01_003C5970 */
extern struct U_3C41F8 D_L01_001E001C __attribute__((section(".sdata")));
extern s32 D_L01_001F3F40[];
extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
extern void func_L01_0042B068(s32, s32);
extern void func_L01_003C5290(u8 *, u8 *);


void func_L01_003C5970(u8 *m, u8 *v) {
    s32 e = ((S_3C40F0 *)v)->arr[((S_3C40F0 *)v)->idx];
    u16 *list;
    u8 *o;

    if (e != -1 && e != D_L01_001F3F40[0]) {
        func_L01_0042B068(e, 0);
    }
    func_L01_003C5290(m, v);
    list = D_L01_0021DE20[*(s32 *)(v + 36)];
    while ((*(s32 *)(v + 36) & 0xFF) != 255 && *(s32 *)(v + 36) <= D_L01_001E0058 && list != 0 &&
           ((s16)list[-1] >= 0 || list == D_L01_0021DE20[*(s32 *)(v + 36)])) {
        o = (*(u8 * *)&D_L01_001E001C) + ((*list & 0x7FFF) << 8);
        if (o == 0) {
            break;
        }
        list++;
        *(u16 *)(o + 52) &= 0xFF7F;
    }
}
/* localdecomp:end func_L01_003C5970 */

/* localdecomp:start func_L01_003C5A78 */
extern void func_L01_003C5290(u8 *, u8 *);

extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
extern struct U_3C41F8 D_L01_001E001C __attribute__((section(".sdata")));
extern s32 D_L01_001F3F40[];
extern void func_L01_0042B068(s32 a, s32 b);

void func_L01_003C5A78(void *a, O_3C41F8 *o, s32 i) {
    u16 *p;
    M_3C41F8 *e;
    s32 s = o->a1872[i];

    if (s == -1) {
        s32 t = o->a1728[i];
        if (t != s && t != D_L01_001F3F40[0]) {
            func_L01_0042B068(t, 0);
        }
    } else if (s != D_L01_001F3F40[0]) {
        func_L01_0042B068(s, 0);
    }
    ((void (*)(void *a, O_3C41F8 *o))func_L01_003C5290)(a, o);
    for (p = D_L01_0021DE20[o->id];
         (o->id & 0xFF) != 0xFF && o->id <= D_L01_001E0058 && p != 0 &&
         ((s16)p[-1] >= 0 || p == D_L01_0021DE20[o->id]);
         p++) {
        e = *(M_3C41F8 **)&D_L01_001E001C + (p[0] & 0x7FFF);
        if (e == 0) {
            break;
        }
        e->h52 &= 0xFF7F;
    }
}
/* localdecomp:end func_L01_003C5A78 */

/* localdecomp:start func_L01_003C5BA8 */
extern s32 func_00382380(u8 *, s32, s32);
extern s32 D_001D545C;
extern u8 D_001BBC40[][16];
extern u8 D_001A4C60[];


s32 func_L01_003C5BA8(s32 unused, u8 *obj) {
    s32 i;
    s32 *p = (s32 *)(obj + 1856);
    for (i = 0; i < 4; i++, p++) {
        s32 a = p[-4];
        s32 b;
        if (a == -1) {
            continue;
        }
        b = p[0];
        if (b != -1 && !(D_001BBC40[D_001D545C][b] & 0x80)) {
            continue;
        }
        if (((s32 (*)(void *a, s32 b, s32 c))func_00382380)(D_001A4C60, a, 0) != 0) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_003C5BA8 */

/* localdecomp:start func_L01_003C5C60 */
extern void func_L01_003F5E88(u8 *);
void func_L01_003C5C60(s32 a0, u8 *a1) {
    u8 *s = *(u8 **)(a1 + 84);
    if (s != 0 && *(s32 *)(s + 152) == 0) {
        func_L01_003F5E88(s);
        *(s32 *)(s + 152) = *(s32 *)(*(u8 **)(s + 36) + 16);
    }
}
/* localdecomp:end func_L01_003C5C60 */

/* localdecomp:start func_L01_003C5CA8 */
extern void func_L01_003F5EE0(u8 *);

void func_L01_003C5CA8(void *self, u8 *obj) {
    u8 *s = *(u8 **)(obj + 84);
    if (s != 0 && *(s32 *)(s + 152) != 0) {
        func_L01_003F5EE0(s);
        *(s32 *)(s + 152) = 0;
    }
}
/* localdecomp:end func_L01_003C5CA8 */

INCLUDE_ASM("asm/levels", func_L01_003C5CE8);

INCLUDE_ASM("asm/levels", func_L01_003C5DF0);

/* localdecomp:start func_L01_003C5EC0 */
void func_L01_003C5DF0(s32, s32, s32);
void func_L01_003EB5E0(s32, s32);
extern s32 D_L01_001DF95C;

void func_L01_003C5EC0(s32 arg0, s32 arg1) {
    func_L01_003EB5E0(0, 3);
    func_L01_003C5DF0(arg0, arg1, 0);
    D_L01_001DF95C = 0;
}
/* localdecomp:end func_L01_003C5EC0 */

INCLUDE_ASM("asm/levels", func_L01_003C5F10);

/* localdecomp:start func_L01_003C6128 */
extern struct U_3C41F8 D_L01_001E001C __attribute__((section(".sdata")));
extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
extern void func_L01_004AA7E8(M3C48A8 *m, s32 a1);
void func_L01_003C6128(void *a0, O3C48A8 *obj) {
    s16 *p;
    M3C48A8 *m;
    M3C48A8 *o;
    M3C48A8 *c;
    s32 g;

    p = ((s16 * *)&D_L01_0021DE20)[obj->group];
    while (g = obj->group, (g & 0xFF) != 255 && g <= D_L01_001E0058 && p != 0 &&
             (p[-1] >= 0 || p == ((s16 * *)&D_L01_0021DE20)[g])) {
        m = &(*(M3C48A8 * *)&D_L01_001E001C)[*p & 0x7FFF];
        if (m == 0) {
            break;
        }
        if (m->state == 254) {
            goto next;
        }
        if (m->state == 253) {
            goto next;
        }
        if (m->flags & 2) {
            goto next;
        }
        if (m->vars->link == -1) {
            goto next;
        }
        o = &(*(M3C48A8 * *)&D_L01_001E001C)[m->vars->link];
        c = o->vars->child;
        m->flags |= 2;
        o->f98 = 0;
        o->flags = (o->flags | 0x43) & ~0x1000;
        func_L01_004AA7E8(o, 1);
        if (c != 0) {
            c->f98 = 0;
            c->flags = (c->flags | 0x41) & ~0x1000;
            func_L01_004AA7E8(c, 1);
        }
next:
        p++;
    }
    obj->active = 0;
}
/* localdecomp:end func_L01_003C6128 */

INCLUDE_ASM("asm/levels", func_L01_003C6288);

INCLUDE_ASM("asm/levels", func_L01_003C6318);

INCLUDE_ASM("asm/levels", func_L01_003C6350);

INCLUDE_ASM("asm/levels", func_L01_003C6390);

INCLUDE_ASM("asm/levels", func_L01_003C63E0);
