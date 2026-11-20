#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
    u8 pad8[8];
    void (*f10)(u8 *);
} Tbl_003A5118;
typedef struct {
    u8 pad0[576];
    s32 f240;
    u8 pad244[284];
    s32 ids[10];
    u8 pad388[32];
    s32 f3A8;
} Vars_003A5118;
typedef struct {
    u8 pad0[104];
    Vars_003A5118 *vars;
} Obj_003A5118;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    u8 p10[0x30];
    s32 x40;
    s32 x44;
    s32 x48;
    s32 x4C;
    u8 p50[0x18];
    s32 x68;
    s32 x6C;
    u8 p70[0x64];
    s32 xD4;
} S_3A68C0;
typedef struct {
    u8 p0[0xB2];
    u16 xB2;
} O_3A68C0;
typedef struct {
    u8 p0[0x464];
    u8 x464[1];
} T_3A68C0;
typedef struct {
    u8 pad0[150];
    u16 timer;
} Obj003A7510;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128_3A7C18 __attribute__((mode(TI)));
typedef struct {
    s128_3A7C18 q0;
    u8 *parent;
    f32 f14;
    int f18;
    f32 f1C;
    f32 f20;
} V_3A7C18;
typedef int u128_003A9A80 __attribute__((mode(TI)));
typedef struct {
    u8 pad[0x64];
    u8 *w64;
} Moby_003A9A80;
typedef struct {
    u8 pad[0x30];
    u8 b30;
    u8 pad2[3];
    u16 h34;
    u8 pad3[0x98 - 0x36];
    int x98;
} S_3A9AC0m;
typedef struct {
    int x0;
    int x4;
    u8 pad[0x10];
} S_3A9AC0a;
typedef struct {
    int x0;
    int x4;
    u8 pad[0x28];
} S_3A9AC0b;
typedef struct {
    u8 pad[0x24];
    int n;
    S_3A9AC0b *p;
    u8 pad2[4];
} S_3A9AC0c;
typedef struct {
    u8 pad[8];
    int n8;
    S_3A9AC0a *pC;
    u8 pad2[0x34 - 0x10];
    int n34;
    S_3A9AC0c *p38;
} S_3A9AC0d;
typedef struct {
    u8 pad[0xD0];
    u8 bD0;
    u8 pad2[0xDC - 0xD1];
    S_3A9AC0m *mDC;
} S_3A9AC0e;
typedef struct {
    u8 pad[0x64];
    S_3A9AC0m *m;
    S_3A9AC0d *d;
    u8 pad2[0xBA0 - 0x6C];
    u8 xBA0[0xC48 - 0xBA0];
    int xC48;
    u8 pad3[0xD1C - 0xC4C];
    int xD1C;
} S_3A9AC0o;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_003AB448;

typedef struct {
    u8 pad0[0x60];
    s32 group;
} G_003AADB8;

INCLUDE_ASM("asm/levels", func_L01_003A4970);

/* localdecomp:start func_L01_003A62F8 */
#define B(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define H(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define W(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define L(p, o) (*(unsigned long *)((u8 *)(p) + (o)))

extern s32 func_L01_003A65F0(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_003A6BB0(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_003A6990(void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32);
extern u8 D_L01_001E2A40[];
extern s32 D_001D545C;
extern s32 D_L01_001DFB40;

s32 func_L01_003A62F8(u8 *m) {
    u8 *v = *(u8 **)(m + 104);

    if (B(m, 32) == 0) {
        if (func_L01_003A65F0(m) != 0) {
            return 1;
        }
    }
    if (B(m, 49) != 0) {
        if (func_L01_0040E548(D_L01_001E2A40, m + 16) < 576.0f) {
            func_L01_004472C0(m);
            B(m, 111) = 22;
        }
    }
    if (B(v, 62) != 2) {
        if (func_L01_00452FB0(m, v + 352, 0, 0, 0) != 0) {
            func_003A52A0(3, 0, m);
            func_L01_003A6BB0(m);
        }
        func_L01_00452860(m, v + 48, 0);
        if (B(v, 94) == 0) {
            goto rest;
        }
        func_003A52A0(3, 0, m);
    }
    func_L01_003A6990(m);
    return 1;
rest:
    if ((L(m, 48) & 0x104100000000L) != 0x4100000000L || W(m, 152) != 0) {
        if (0.0f < F(v, 48)) {
            if (B(v, 95) != 0) {
                func_L01_00456BD0(m, 5);
            } else if (D_001D545C != 9 || (u8)(B(m, 149) - 3) < 2) {
                func_L01_00456BD0(m, 3);
            }
        }
    }
    if ((H(m, 178) + 8) % 8 != D_L01_001DFB40 % 8) {
        return 0;
    }
    if (B(v, 95) != 0) {
        if (B(m, 149) == 0) {
            func_L01_00456C98(m, W(v, 720), 0, 0, 0, 0, 3, 0, F(v, 724), 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(m, W(v, 728), 0, 0, 0, 0, 3, 0, F(v, 732), 10.0f, 1.0f, 0, 0);
        }
    } else {
        if (B(m, 149) == 0) {
            func_L01_00456C98(m, W(v, 720), 0, 0, 0, 0, 1, W(v, 960) != 0, F(v, 724), 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(m, W(v, 728), 0, 0, 0, 0, 1, W(v, 960) != 0, F(v, 732), 10.0f, 1.0f, 0, 0);
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003A62F8 */

/* localdecomp:start func_L01_003A65F0 */
typedef int Q_003A65F0 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 f34;
    u8 pad36[0x2];
    u8 f38;
    u8 f39;
    u8 pad3A[0x4];
    u8 f3E;
    u8 f3F;
    f32 f40;
    u8 pad44[0x14];
    u8 f58;
    u8 pad59[0x1];
    u8 f5A;
    u8 pad5B[0x3];
    u8 f5E;
    u8 f5F;
    u8 pad60[0x10];
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 pad84[0x18];
    f32 f9C;
    f32 fA0;
    u8 padA4[0x4];
    s32 fA8;
    u8 padAC[0xC4];
    u8 f170;
    u8 f171;
    u8 f172;
    u8 pad173[0x1D];
    f32 f190;
    f32 f194;
    u8 pad198[0x4];
    f32 f19C;
    u8 pad1A0[0x8];
    u8 f1A8;
    u8 pad1A9[0x2E];
    u8 f1D7;
    u8 f1D8;
    u8 f1D9;
    u8 f1DA;
    u8 f1DB;
    u8 pad1DC[0x64];
    s32 f240;
    u8 pad244[0xA];
    u8 f24E;
    u8 f24F;
    u8 pad250[0x90];
    s32 f2E0;
    s16 f2E4;
    u8 pad2E6[0x2];
    s32 f2E8;
    f32 f2EC;
    u8 pad2F0[0x10];
    s32 f300;
    u8 pad304[0x4];
    s32 f308;
    s32 f30C;
    s32 f310;
    u8 pad314[0x8];
    s32 f31C;
    Q_003A65F0 f320;
    u8 pad330[0x28];
    s32 f358;
    u8 pad35C[0x2C];
    s32 f388;
    u8 pad38C[0x1C];
    s32 f3A8;
    f32 f3AC;
} Vars_003A65F0;
s32 func_L01_003A65F0(void *arg) {
    extern f32 func_00382538(void);
    extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
    extern Tbl_003A5118 *func_L01_0043B548(s32, s32);
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L01_003A6F80(Obj_003A5118 *);
    extern void func_L01_004450F0(S_3A9AC0m *, int, int);
    u8 *m = arg;
    Vars_003A65F0 *v = *(Vars_003A65F0 **)(m + 0x68);
    Tbl_003A5118 *t;
    *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
    v->f320 = *(Q_003A65F0 *)(m + 0x10);
    v->f3AC = *(f32 *)(m + 0xF8);
    v->f2EC = func_00382538();
    v->f170 = 0x11;
    v->f19C = 0.15f;
    v->f1D7 = 1;
    v->f1DA = 0;
    v->f1A8 = 4;
    v->f171 = 4;
    v->f172 = 4;
    v->fA8 |= 4;
    v->f190 = 0.5f;
    v->f194 = 0.5f;
    v->f1D8 = 2;
    v->f1D9 = 2;
    v->f1DB = 255;
    v->f70 = 1.1f;
    v->f74 = 0.05f;
    v->f78 = 0.5f;
    v->f7C = 1.0f;
    v->f80 = 0.7853981852531433f;
    v->fA0 = 0.3490658402442932f;
    v->f9C = 0.003920000046491623f;
    func_L01_0045BD78(m, 0.002400000113993883f, 0.1600000113248825f, 0.010053097270429134f, 0.25132742524147034f);
    v->f58 = 20;
    v->f5A = 14;
    if (v->f34 == 0) {
        v->f34 = 4;
        v->f30 = 4.0f;
    }
    v->f40 = 0.75f;
    v->f38 = 1;
    v->f3E = 1;
    v->f39 = 0;
    v->f3F = 0;
    v->f31C = 0;
    v->f358 = -1;
    v->f388 = 0;
    v->f5E = 0;
    v->f5F = 0;
    v->f2E0 = 0;
    v->f2E4 = 0;
    v->f2E8 = 0;
    v->f308 = 0;
    v->f30C = 0;
    if (v->f240 > 0) {
        t = func_L01_0043B548(0x19E1, 0x6C);
        v->f240 = -1;
        if (m[0x43]) func_003C3A10(m, 0, 0, 0);
        v->f24E = 15;
        v->f24F = 5;
        t->f0(m);
    } else if (v->f3A8) {
        func_L01_003A6F80((Obj_003A5118 *)m);
    } else {
        func_L01_004450F0((S_3A9AC0m *)m, 2, 0);
        if (m[0x43]) func_003C3A10(m, 0, 0, 0);
        if (v->f310) func_L01_004450F0((S_3A9AC0m *)m, 1, -1);
        if (v->f300 != -1) func_L01_004450F0((S_3A9AC0m *)m, 3, -1);
    }
    return 0;
}
/* localdecomp:end func_L01_003A65F0 */

/* localdecomp:start func_L01_003A6898 */
extern u8 *D_L01_001E001C;
extern Tbl_003A5118 *func_L01_0043B548(s32, s32);
extern void func_L01_003A6F80(Obj_003A5118 *);
extern void func_003C2880(Obj_003A5118 *);
void func_L01_003A6898(Obj_003A5118 *o, s32 flag) {
    Vars_003A5118 *v;
    Tbl_003A5118 *t;
    s32 i;
    v = o->vars;
    if (v->f240 != 0) {
        t = func_L01_0043B548(6625, 108);
        for (i = 0; i < 10; i++) {
            if (v->ids[i] != -1) {
                t->f10(D_L01_001E001C + v->ids[i] * 256);
                v->ids[i] = -1;
            }
        }
        t->f0(o);
        if (flag != 0) {
            t->f4(o);
        }
    } else if (v->f3A8 != 0) {
        func_L01_003A6F80(o);
    } else {
        func_003C2880(o);
    }
}
/* localdecomp:end func_L01_003A6898 */

LINKER_REMNANT("asm/levels", func_L01_003A6988);

/* localdecomp:start func_L01_003A6990 */
extern s32 D_001D545C;
extern s32 D_L01_001D67B4;
extern s32 D_L01_001D67C0;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
void func_L01_003A6990(void *obj) {
    extern void func_L01_00459C50(s32);
    extern void func_L01_00452310(void *, f32, f32, s32, f32, void *, s32, s32, f32, f32, s32, f32, f32, s32, s32);
    extern void func_L01_004443E8(void *, s32, s32);
    u8 *v = *(u8 **)((u8 *)obj + 0x68);
    if (D_001D545C == 12 && *(u8 **)(v + 0x48) != 0 && v[0x47] == 9) {
        if (++D_L01_001D67B4 >= 20) func_L01_00459C50(15);
    } else if (D_001D545C == 18 && *(u8 **)(v + 0x48) != 0 && *(s16 *)(*(u8 **)(v + 0x48) + 0xAA) == 0x185E) {
        if (++D_L01_001D67C0 >= 20) func_L01_00459C50(21);
    }
    if (v[0x5E] == 0) {
        func_L01_00452310(obj, -1.0f, 3.0f, 0x3FFF, 6.0f, D_L01_001D66B0, 2, 20, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0);
    }
    func_L01_004443E8(obj, 0, 3);
}
/* localdecomp:end func_L01_003A6990 */

/* localdecomp:start func_L01_003A6AC0 */
extern f32 D_L01_001DE2EC;
__asm__(".extern D_L01_001DE2EC, 4");
extern f32 D_L01_001DE2F0;
__asm__(".extern D_L01_001DE2F0, 4");
extern f32 D_L01_001DE2F4;
__asm__(".extern D_L01_001DE2F4, 4");
extern f32 D_L01_001DE2F8;
__asm__(".extern D_L01_001DE2F8, 4");
extern f32 D_L01_001DE2FC;
__asm__(".extern D_L01_001DE2FC, 4");
void func_L01_003A6AC0(u8 *obj) {
    extern s32 func_0038CAD0(s32 *);
    extern void func_0038CB00(s32 *);
    extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
    extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
    extern void func_L01_0044EBA0(void *, void *, void *, f32, f32, f32);
    u8 *v = *(u8 **)(obj + 0x68);
    func_0038CAD0((s32 *)(v + 0x2E0));
    func_0038CB00((s32 *)(v + 0x2E4));
    if (*(u16 *)(obj + 0x96) < 0xFFFF) ++*(u16 *)(obj + 0x96);
    func_L01_00451DF8(obj, v + 0x250, 4, 1, 2.5f);
    func_L01_0044EAE0(obj, v + 0x2EC, v + 0x2F0, D_L01_001DE2EC, D_L01_001DE2F0 * 0.017453292f * 0.020000001415610313f, -1.0f);
    func_L01_0044EBA0(obj, v + 0x2F4, v + 0x2F8, D_L01_001DE2FC * 0.017453292f, D_L01_001DE2F4 * 0.017453292f * 0.020000001415610313f, D_L01_001DE2F8 * 0.017453292f * 0.020000001415610313f);
}
/* localdecomp:end func_L01_003A6AC0 */

/* localdecomp:start func_L01_003A6BB0 */
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001E0058;

void func_L01_003A6BB0(void *obj) {
    u8 *a0 = obj;
    u16 *p;
    u8 *m;

    if (a0[0x21] == 0xFF) {
        return;
    }
    p = D_L01_0021DE20[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L01_001E0058 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L01_0021DE20[a0[0x21]])) {
        m = D_L01_001E001C + ((*p & 0x7FFF) << 8);
        if (m == 0) {
            return;
        }
        if (*(s16 *)(m + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            *(s32 *)(*(u8 **)(m + 0x68) + 0x2E8) = 1;
        }
        p++;
    }
}
/* localdecomp:end func_L01_003A6BB0 */




/* localdecomp:start func_L14_0035F870 */
__asm__(".extern D_L14_001DF71C, 16");
extern u8 *D_L14_001DF71C;
__asm__(".extern D_L14_001DF758, 4");
extern s32 D_L14_001DF758;
extern u16 *D_L14_0021CCE0[];

void func_L14_0035F870(u8 *a0) {
    u16 *p;
    u8 *e;

    if (a0[0x21] == 0xFF) {
        return;
    }
    p = D_L14_0021CCE0[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L14_001DF758 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L14_0021CCE0[a0[0x21]])) {
        e = D_L14_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            break;
        }
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            *(s32 *)(*(u8 **)(e + 0x68) + 0x2E0) = 1;
        }
        p++;
    }
}
/* localdecomp:end func_L14_0035F870 */

/* localdecomp:start func_L02_0034C938 */
__asm__(".extern D_L02_001DE99C, 16");
extern u8 *D_L02_001DE99C;
__asm__(".extern D_L02_001DE9D8, 4");
extern s32 D_L02_001DE9D8;
extern u16 *D_L02_0021B460[];

void func_L02_0034C938(u8 *a0) {
    u16 *p;
    u8 *e;

    if (a0[0x21] == 0xFF) {
        return;
    }
    p = D_L02_0021B460[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L02_001DE9D8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L02_0021B460[a0[0x21]])) {
        e = D_L02_001DE99C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            break;
        }
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            *(s32 *)(*(u8 **)(e + 0x68) + 0x2D8) = 1;
        }
        p++;
    }
}
/* localdecomp:end func_L02_0034C938 */

/* localdecomp:start func_L01_003A6C68 */
void func_L01_003A6C68(u8 *arg0, u8 *arg1) {
    extern void func_003C3A10(void *, s32, s32, s32);
    u8 *src = *(u8 **)(arg1 + 0x68);
    u8 *dst = *(u8 **)(arg0 + 0x68);
    s32 i;
    s32 *p;
    s32 empty;
    *(s32 *)(dst + 0x2D0) = *(s32 *)(src + 0);
    if (*(f32 *)(src + 4) > 0.0f) *(f32 *)(dst + 0x2D4) = *(f32 *)(src + 4);
    *(s32 *)(dst + 0x2D8) = *(s32 *)(src + 8);
    if (*(f32 *)(src + 0xC) > 0.0f) *(f32 *)(dst + 0x2DC) = *(f32 *)(src + 0xC);
    *(s32 *)(dst + 0x2FC) = *(s32 *)(src + 0x10);
    *(s32 *)(dst + 0x300) = *(s32 *)(src + 0x14);
    *(s32 *)(dst + 0x304) = *(s32 *)(src + 0x18);
    *(s32 *)(dst + 0x310) = *(s32 *)(src + 0x1C);
    *(s32 *)(dst + 0x314) = *(s32 *)(src + 0x20);
    *(s32 *)(dst + 0x344) = *(s32 *)(src + 0x30);
    *(s32 *)(dst + 0x348) = *(s32 *)(src + 0x34);
    *(s32 *)(dst + 0x34C) = *(s32 *)(src + 0x38);
    *(s32 *)(dst + 0x350) = *(s32 *)(src + 0x40);
    *(s32 *)(dst + 0x354) = *(s32 *)(src + 0x44);
    *(s32 *)(dst + 0x35C) = *(s32 *)(src + 0x48);
    *(s32 *)(dst + 0x3A0) = *(s32 *)(src + 0x68);
    *(s32 *)(dst + 0x3C0) = *(s32 *)(src + 0x88);
    *(s32 *)(dst + 0x318) = -1;
    p = (s32 *)(dst + 0x384);
    empty = -1;
    i = 9;
    do {
        *p = empty;
        i--;
        p--;
    } while (i >= 0);
    if (arg0[0x43] != 0) func_003C3A10(arg0, 0, 0, 0);
}
/* localdecomp:end func_L01_003A6C68 */

/* localdecomp:start func_L01_003A6D78 */
f32 func_L01_003A6D78(void) {
    return 2.0f;
}
/* localdecomp:end func_L01_003A6D78 */

/* localdecomp:start func_L01_003A6D88 */
extern void func_L01_003A6898_003A6D88(Obj_003A5118 *o, s32 flag);
extern void func_L01_003A6D88(void *p);
extern void func_L01_003A6D88(void *);

 
void func_L01_003A6D88(void *p) {
    ((void (*)(void *, s32))func_L01_003A6898_003A6D88)(p, 0);
}
/* localdecomp:end func_L01_003A6D88 */

/* localdecomp:start func_L01_003A6DA8 */
__asm__(".extern D_L01_001E0058, 4");
typedef struct {
    u8 p0[0x318];
    s32 f318;
    u8 p31C[0x44];
    s32 arr[10];
} P_003A6DA8;
void func_L01_003A6DA8(u8 *obj, u8 *parent, s32 group) {
    P_003A6DA8 *v = *(P_003A6DA8 **)(obj + 0x68);
    v->f318 = parent != 0 ? (parent - D_L01_001E001C) >> 8 : -1;
    if (group != 255) {
        u16 *p;
        u8 *m;
        s32 i;
        p = D_L01_0021DE20[group];
        i = 0;
        while (((u16)group & 0xFF) != 0xFF && group <= D_L01_001E0058 && p != 0 &&
               ((s16)p[-1] >= 0 || p == D_L01_0021DE20[group])) {
            m = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (m == 0) return;
            v->arr[i] = (m - D_L01_001E001C) >> 8;
            i++;
            *(u16 *)(m + 0x34) |= 2;
            p++;
        }
    } else {
        s32 j;
        s32 *a = &v->arr[9];
        for (j = 0; j < 10; j++) {
            *a-- = -1;
        }
    }
}
/* localdecomp:end func_L01_003A6DA8 */

/* localdecomp:start func_L01_003A6EB0 */
#include "vu0.h"
void func_L01_003A6EB0(S_3A9AC0m *obj) {
    extern void func_003C3A10(void *, s32, s32, s32);
    extern void func_L01_004450F0(S_3A9AC0m *, int, int);
    u8 *m = (u8 *)obj;
    u8 *v = *(u8 **)(m + 0x68);
    u8 *model;
    s32 value;
    v[0x5E] = 0;
    v[0x60] = 0;
    v[0x5F] = 0;
    qzero(m + 0xF0);
    model = *(u8 **)(m + 0x24);
    *(f32 *)(m + 0x2C) = *(f32 *)(model + 0x24);
    *(u128_t *)(m + 0x10) = *(u128_t *)(v + 0x320);
    *(f32 *)(m + 0xF8) = *(f32 *)(v + 0x3AC);
    *(u16 *)(m + 0x34) &= 0xFFBE;
    *(u16 *)(m + 0x34) |= *(u16 *)(model + 0x44) & 0x1000;
    value = *(s32 *)(model + 0x10);
    *(u16 *)(m + 0x34) &= 0xFFFD;
    *(s32 *)(m + 0x98) = value;
    if (m[0x43] != 2) func_003C3A10(obj, 2, 0, 8);
    func_L01_004450F0(obj, 6, 3);
    if (*(s32 *)(v + 0x2FC) != -1) func_L01_004450F0(obj, 8, -1);
}
/* localdecomp:end func_L01_003A6EB0 */

/* localdecomp:start func_L01_003A6F80 */
void func_L01_003A6F80(Obj_003A5118 *obj) {
    extern f32 *func_00382348(u8 *);
    extern u8 *func_L01_00448FF0(void *);
    extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32);
    extern void func_L01_004AA7E8(S_3A9AC0m *, int);
    extern s32 func_L01_004AA710(void *, s32);
    extern void func_003A4F28(int);
    extern void func_L01_004450F0(S_3A9AC0m *, int, int);
    u8 *o = (u8 *)obj;
    f32 *hp;
    u8 *v;
    s32 i = 0;
    o[0x7F] = 0;
    hp = func_00382348(o);
    *hp = (f32)*(s16 *)((u8 *)hp + 4);
    v = func_L01_00448FF0(o);
    *(s16 *)(v + 0x38) = 0;
    v[7] = 0;
    v[9] = 0;
    v[8] = 0;
    ((s32 (*)(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32))func_L01_00456C98)(o, -1, 0, 0, 0, 0, 3, 0, 0.0f, 0.0f, 1.0f, 0, 0);
    o[0xA8] = 255;
    ((S_3A9AC0m *)o)->h34 |= 0x43;
    ((S_3A9AC0m *)o)->h34 &= 0xEFFF;
    ((S_3A9AC0m *)o)->x98 = 0;
    func_L01_004AA7E8((S_3A9AC0m *)o, 1);
    do {
        if (func_L01_004AA710(o, i) != 0) func_003A4F28(i);
        i++;
    } while (i < 52);
    func_L01_004450F0((S_3A9AC0m *)o, 16, 6);
}
/* localdecomp:end func_L01_003A6F80 */

/* localdecomp:start func_L01_003A7080 */
long func_L01_003A7080(u8 *p) {
    long result = 0;
    if (p[0x95] == 6) {
        s32 active = p[0x20] == 16;
        result = active;
    }
    return result;
}
/* localdecomp:end func_L01_003A7080 */

INCLUDE_ASM("asm/levels", func_L01_003A70A8);

INCLUDE_ASM("asm/levels", func_L01_003A78E8);

/* localdecomp:start func_L01_003A7B38 */
typedef struct {
    u8 pad_0[0x10];
    u8 muzzle_a[0x10];         /* 0x10: the muzzle when the flag is set */
    u8 muzzle_b[0x10];         /* 0x20: the muzzle otherwise */
    u8 pad_30[0x54 - 0x30];
    s32 timer;                 /* 0x54: the draw waits while it runs */
} N60Vars_3A7B38;
typedef struct {
    u8 pad_0[0x68];
    N60Vars_3A7B38 *vars;
} N60Moby_3A7B38;

extern s32 D_L01_001DE360;
__asm__(".extern D_L01_001DE360, 4");
extern s32 func_0038CAD0(s32 *);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32 a, f32 b);
extern void func_003D9508(void *p, s32 a, s32 b, s32 c, f32 d, f32 e, f32 f);

/* n60_muzzle_draw: the N60's muzzle for the frame of a shot: additive billboards of textures 49
   (twice, random rolls) and 11 (pushed 0.08 toward the camera), then a star of 65 at a roll of
   30-60 degrees */
void func_L01_003A7B38(N60Moby_3A7B38 *gun) {
    N60Vars_3A7B38 *vars = gun->vars;
    if (func_0038CAD0(&vars->timer))
        return;
    if (D_L01_001DE360) {
        func_003D9508(vars->muzzle_a, 0x31, 0x3F204090, 1, 0.6f, 0.0f, func_00382538());
        func_003D9508(vars->muzzle_a, 0x31, 0x3F204090, 1, 0.6f, 0.0f, func_00382538());
        func_003D9508(vars->muzzle_a, 0xB, 0x3F204090, 1, 0.6f, 0.0799999982118f, 0.0f);
        func_003D9508(vars->muzzle_a, 0x41, 0x3F909090, 1, 0.75f, 0.0f,
                      func_003824E0(30.0f, 60.0f) * 0.01745329238474369f);
    } else {
        func_003D9508(vars->muzzle_b, 0x31, 0x3F204090, 1, 0.6f, 0.0f, func_00382538());
        func_003D9508(vars->muzzle_b, 0x31, 0x3F204090, 1, 0.6f, 0.0f, func_00382538());
        func_003D9508(vars->muzzle_b, 0xB, 0x3F204090, 1, 0.6f, 0.0799999982118f, 0.0f);
        func_003D9508(vars->muzzle_b, 0x41, 0x3F909090, 1, 0.75f, 0.0f,
                      func_003824E0(30.0f, 60.0f) * 0.01745329238474369f);
    }
}
/* localdecomp:end func_L01_003A7B38 */

LINKER_REMNANT("asm/levels", func_L01_003A7D50);

/* localdecomp:start func_L01_003A7D70 */
extern void func_L01_003A7DC0(u8 *, u8 *);
extern void func_L01_003A8288(u8 *, u8 *);

void func_L01_003A7D70(u8 *obj) {
    u8 *d = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 0:
        func_L01_003A7DC0(obj, d);
        break;
    case 1:
        func_L01_003A8288(obj, d);
        break;
    }
}
/* localdecomp:end func_L01_003A7D70 */

INCLUDE_ASM("asm/levels", func_L01_003A7DC0);

/* localdecomp:start func_L01_003A8048 */
extern s32 func_L01_00456250(void *);
extern s32 func_0038CAD0(s32 *);
extern void func_L01_004AADE8(s32, s32, void *, s32);
extern u8 *D_L01_001E001C;
extern s32 D_001D545C;
extern s32 D_L01_001DE370;
extern T_3A68C0 D_L01_00237800;
extern u8 D_001BBE90[];

s32 func_L01_003A8048(O_3A68C0 *o, S_3A68C0 *p) {
    s32 ok = 1;
    if (p->x0 != -1) {
        if (!func_L01_00456250(D_L01_001E001C + (p->x0 << 8))) ok = 0;
    }
    if (p->x4 != -1) {
        if (!func_L01_00456250(D_L01_001E001C + (p->x4 << 8))) ok = 0;
    }
    if (p->xD4) {
        u16 h = o->xB2;
        s32 b;
        if (D_L01_00237800.x464[(s16)h] || (b = D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)], (h & 1) ? (b >> 4) & 7 : b & 7)) ok = 1;
    }
    if (p->x68 != ok) {
        if (p->x6C == 0) p->x6C = D_L01_001DE370;
        if (func_0038CAD0(&p->x6C)) {
            s32 a, f;
            p->x68 = ok;
            if (p->xC && ok) {
                p->x0 = -1;
                p->x4 = -1;
            }
            if (ok) {
                a = p->x40;
                if (a < 0) goto done;
                f = p->x48;
            } else {
                a = p->x44;
                if (a < 0) goto done;
                f = p->x4C;
            }
            if (f == 0) func_L01_004AADE8(a, 0, D_L01_001E001C + (p->x8 << 8), 0);
        }
    } else {
        p->x6C = 0;
    }
done:
    if (p->xD4 && ok) {
        u16 h = o->xB2;
        if (h & 1) {
            u8 *q = &D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)];
            if (((*q >> 4) & 7) != 7) *q += 16;
        } else {
            u8 *q = &D_001BBE90[((s16)h >> 1) + (D_001D545C << 10)];
            if ((*q & 7) != 7) *q += 1;
        }
    }
    return p->x68;
}
/* localdecomp:end func_L01_003A8048 */

INCLUDE_ASM("asm/levels", func_L01_003A8288);

INCLUDE_ASM("asm/levels", func_L01_003A8850);

/* localdecomp:start func_L01_003A8C98 */
extern void func_003C2880(Obj_003A5118 *);

extern void func_L01_003A8850(Obj003A7510 *);
extern void func_L01_00404808(void (*)(Obj003A7510 *), Obj003A7510 *);

void func_L01_003A8C98(Obj003A7510 *obj) {
    obj->timer++;
    func_L01_00404808(func_L01_003A8850, obj);
    if (obj->timer >= 7) {
        ((void (*)(Obj003A7510 *))func_003C2880)(obj);
    }
}
/* localdecomp:end func_L01_003A8C98 */

/* localdecomp:start func_L01_003A8CF0 */

extern u8 D_001A4EC0[];
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(u8 *, Vec4 *, f32);
extern void func_0038CE90(u8 *, u8 *, u8 *);

u8 *func_L01_003A8CF0(u8 *parent, Vec4 *a1, Vec4 *a2, f32 scale)
{
    Vec4 pos;
    Vec4 rot;
    u8 *m;
    Vec4 *rp = &rot;

    pos = *a1;
    rot = *a2;
    m = func_003C24B0(6387, 128);
    if (m != 0) {
        m[48] = 255;
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        m[32] = 0;
        *(u8 **)(m + 184) = parent;
        *(u128_t *)(m + 16) = pos.q;
        *(u16 *)(m + 52) |= 0x100;
        *(f32 *)(*(u8 **)(m + 104) + 16) = scale;
        *(f32 *)(m + 28) = scale;
        if (rp->f[0] != 0.0f || rp->f[1] != 0.0f || rp->f[2] != 0.0f) {
            func_0038CF68(m + 192, rp, 1.0f);
            func_0038CE90(m + 208, m + 192, D_001A4EC0);
            func_0038CF68(m + 208, (Vec4 *)(m + 208), 1.0f);
            func_0038CE90(m + 224, m + 208, m + 192);
        } else {
            *(u128_t *)(m + 192) = *(u128_t *)(parent + 192);
            *(u128_t *)(m + 208) = *(u128_t *)(parent + 208);
            *(u128_t *)(m + 224) = *(u128_t *)(parent + 224);
        }
    }
    return m;
}
/* localdecomp:end func_L01_003A8CF0 */

INCLUDE_ASM("asm/levels", func_L01_003A8E50);

/* localdecomp:start func_L01_003A93A0 */


extern u8 *func_003C24B0(int, int);
extern f32 func_00382538(void);
extern void func_0038D308(void *, void *);

u8 *func_L01_003A93A0(u8 *parent, s128_3A7C18 *a, s128_3A7C18 *pos, int n, f32 f) {
    u8 *m = func_003C24B0(6390, 128);
    V_3A7C18 *pv;

    if (m != 0) {
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        m[0x20] = 0;
        pv = *(V_3A7C18 **)(m + 0x68);
        *(long *)(m + 0x38) = *(long *)(parent + 0x38);
        *(s128_3A7C18 *)(m + 0x10) = *pos;
        pv->q0 = *a;
        pv->f14 = f;
        pv->parent = parent;
        pv->f20 = func_00382538();
        *(u16 *)(m + 0x34) |= 0x208;
        *(f32 *)((u8 *)pv + 0xC) = (f32)n;
        *(s128_3A7C18 *)(m + 0xF0) = *(s128_3A7C18 *)(parent + 0xF0);
        func_0038D308(m + 0xC0, m + 0xF0);
        m[0x23] = 0x80;
        *(u16 *)(m + 0x34) |= 0x100;
        pv->f18 = 0;
    }
    return m;
}
/* localdecomp:end func_L01_003A93A0 */

INCLUDE_ASM("asm/levels", func_L01_003A94A8);

/* localdecomp:start func_L01_003A9928 */
void func_L01_003A9928(u8 *obj) {
    *(u16 *)(obj + 52) |= 2;
}
/* localdecomp:end func_L01_003A9928 */

/* localdecomp:start func_L01_003A9938 */
void func_L01_003A9938(void *arg0) {
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 2);
}
/* localdecomp:end func_L01_003A9938 */

/* localdecomp:start func_L01_003A9948 */
void func_L01_003A9948(void *arg0) {
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 2);
}
/* localdecomp:end func_L01_003A9948 */

/* localdecomp:start func_L01_003A9958 */
void func_L01_003A9958(void *arg0) {
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 2);
}
/* localdecomp:end func_L01_003A9958 */

/* localdecomp:start func_L01_003A9968 */
void func_L01_003A9968(void *arg0) {
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 2);
}
/* localdecomp:end func_L01_003A9968 */

INCLUDE_ASM("asm/levels", func_L01_003A9978);

/* localdecomp:start func_L01_003AA018 */
#include "vu0.h"
u8 *func_L01_003AA018(u8 *parent, u128_t *a, u128_t *position, s32 count, f32 factor) {
    extern u8 *func_003C24B0(s32, s32);
    u8 *m = func_003C24B0(6457, 128);
    u8 *v;
    f32 tenth;
    if (m != 0) {
        m[0x30] = 255;
        *(s16 *)(m + 0x32) = 255;
        m[0x31] = 1;
        m[0x20] = 0;
        v = *(u8 **)(m + 0x68);
        tenth = 0.1f;
        *(long *)(m + 0x38) = *(long *)(parent + 0x38);
        *(u128_t *)(m + 0x10) = *position;
        *(u128_t *)(v + 0x00) = *a;
        *(u128_t *)(v + 0x10) = *position;
        *(u128_t *)(v + 0x20) = *position;
        *(f32 *)(v + 0x1C) = 1.0f;
        *(f32 *)(v + 0x2C) = tenth;
        *(s16 *)(m + 0x96) = 0;
        *(s32 *)(m + 0x48) = 0;
        *(f32 *)(v + 0x0C) = (f32)count;
        *(u8 **)(m + 0xB8) = parent;
        *(f32 *)(v + 0x30) = factor;
        m[0x23] = 128;
        qzero(m + 0xF0);
        *(u16 *)(m + 0x34) |= 0x100;
    }
    return m;
}
/* localdecomp:end func_L01_003AA018 */

INCLUDE_ASM("asm/levels", func_L01_003AA120);

/* localdecomp:start func_L01_003AA618 */
extern u8 D_L01_001DE498[8];
__asm__(".extern D_L01_001DE498, 8");
extern u8 D_L01_001DE478[8];
__asm__(".extern D_L01_001DE478, 8");

u8 *func_L01_003AA618(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 0:
        *a2 = 4;
        return D_L01_001DE498;
    case 1:
        *a2 = 0x1C;
        return D_L01_001DE478;
    }
    return 0;
}
/* localdecomp:end func_L01_003AA618 */

INCLUDE_ASM("asm/levels", func_L01_003AA658);

/* localdecomp:start func_L01_003AABB0 */
#include "vu0.h"
typedef struct { s32 id; u8 pad[0x3C]; } Item_003AABB0;
typedef struct {
    s32 health;
    u8 pad4[12];
    s32 count;
    Item_003AABB0 *items;
    u8 pad18[0x50];
    s32 mode;
} Config_003AABB0;
typedef Config_003AABB0 *(*Get_003AABB0)(void);
void func_L01_003AABB0(u8 *parent, G_003AADB8 *o, u8 *moby)
{
    extern Get_003AABB0 *func_L01_0043B568(s32, s32, s32);
    extern void func_L01_004450F0(S_3A9AC0m *, int, int);
    extern void func_L01_003AB208(u8 *, Moby_003A9A80 *);
    extern void func_L01_0043A800(u8 *, s32, Vec4 *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C3938(u8 *, s32, s32);
    extern void func_003C7C38(void *);
    Vec4 v;
    Get_003AABB0 *table;
    Config_003AABB0 *cfg;
    u8 *state;
    u8 *cls;
    Item_003AABB0 *item;
    s32 i;
    u16 health;
    table = func_L01_0043B568(*(s16 *)(moby + 0xAA), 3, 8);
    *(u8 **)((u8 *)o + 0x64) = moby;
    *(Get_003AABB0 **)((u8 *)o + 0xC48) = table;
    cfg = (*table)();
    *(Config_003AABB0 **)((u8 *)o + 0x68) = cfg;
    cls = *(u8 **)(moby + 0x24);
    state = *(u8 **)(moby + 0x68);
    *(u16 *)(moby + 0x34) &= 0xFFBC;
    *(u16 *)(moby + 0x34) |= *(u16 *)(cls + 0x44) & 0x1000;
    *(s32 *)(moby + 0x98) = *(s32 *)(cls + 0x10);
    if (*(u16 *)(parent + 0x34) & 0x80)
        *(u16 *)(moby + 0x34) |= 0x80;
    else
        *(u16 *)(moby + 0x34) &= 0xFF7F;
    (*(u8 **)(moby + 0x24))[0x46] = 5;
    moby[0x30] = parent[0x30];
    *(u16 *)(moby + 0x32) = *(u16 *)(parent + 0x32);
    moby[0x31] = 1;
    func_L01_004450F0((S_3A9AC0m *)moby, 2, -1);
    *(f32 *)(state + 0x30) = cfg->health;
    health = cfg->health;
    state[0x3E] = 1;
    state[0xE6] = 1;
    state[0xE7] = 1;
    state[0x39] = 0;
    state[0x64] = 0;
    state[0x3F] = 0;
    state[0x8A] = 0;
    *(u16 *)(state + 0xA8) = 0;
    state[0x80] = 255;
    state[0xB8] = 255;
    state[0x81] = 255;
    state[0x38] = 2;
    *(f32 *)(state + 0x40) = -0.1f;
    state[0x58] = 30;
    state[0x5A] = 120;
    *(u16 *)(state + 0x34) = health;
    func_L01_003AB208(parent, (Moby_003A9A80 *)o);
    qzero((u8 *)o + 0xD90);
    item = cfg->items;
    for (i = 0; i < cfg->count; i++, item++) {
        func_L01_0043A800(*(u8 **)((u8 *)o + 0x64), item->id, &v);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(Vec4 *)((u8 *)o + 0xD90)) : "m"(*(Vec4 *)((u8 *)o + 0xD90)), "m"(v) : "vf1", "vf2");
    }
    func_0038CE20((u8 *)o + 0xD90, (u8 *)o + 0xD90, 1.0f / cfg->count);
    func_003C3938(*(u8 **)((u8 *)o + 0x64), cfg->mode, 0);
    func_003C7C38(moby);
}
/* localdecomp:end func_L01_003AABB0 */

/* localdecomp:start func_L01_003AADB8 */
extern u16 *D_L01_0021DE20[];
extern s32 D_L01_001E0058;
extern void func_L01_003AABB0(u8 *a0, G_003AADB8 *a1, u8 *a2);

void func_L01_003AADB8(u8 *a0, G_003AADB8 *a1) {
    u16 *p;
    u8 *e;

    for (p = D_L01_0021DE20[a1->group];
         (a1->group & 0xFF) != 0xFF && a1->group <= D_L01_001E0058 && p != 0 &&
         ((s16)p[-1] >= 0 || p == D_L01_0021DE20[a1->group]);
         p++) {
        e = D_L01_001E001C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            break;
        }
        if (e[0x20] == 1) {
            func_L01_003AABB0(a0, a1, e);
            break;
        }
    }
}
/* localdecomp:end func_L01_003AADB8 */

INCLUDE_ASM("asm/levels", func_L01_003AAE80);

/* localdecomp:start func_L01_003AB208 */


extern void func_0038D308(void *, void *);

void func_L01_003AB208(u8 *src, Moby_003A9A80 *m) {
    *(u128_003A9A80 *)(m->w64 + 16) = *(u128_003A9A80 *)(src + 16);
    *(u128_003A9A80 *)(m->w64 + 240) = *(u128_003A9A80 *)(src + 240);
    func_0038D308(m->w64 + 192, src + 240);
}
/* localdecomp:end func_L01_003AB208 */

/* localdecomp:start func_L01_003AB248 */

extern u8 D_001A30B0[];
extern void func_003A4F28(int);
extern void func_L01_0044EA78(S_3A9AC0m *, void *);
extern void func_L01_004AA7E8(S_3A9AC0m *, int);
extern void func_L01_004450F0(S_3A9AC0m *, int, int);

void func_L01_003AB248(int unused, S_3A9AC0o *o, int flag) {
    S_3A9AC0d *d = o->d;
    S_3A9AC0a *a;
    S_3A9AC0b *b;
    S_3A9AC0c *c;
    int i, j;
    int k = o->xD1C;

    if (k != -1) {
        S_3A9AC0e *e = (S_3A9AC0e *)(D_001A30B0 + k * 128);
        if (e->mDC == o->m && e->bD0 != 0) {
            func_003A4F28(k);
        }
    }
    o->xD1C = -1;
    func_L01_0044EA78(o->m, o->xBA0);
    if (d->n8 != 0) {
        a = d->pC;
        for (i = 0; i < d->n8; i++) {
            func_L01_0044EA78(o->m, (u8 *)o + (a->x4 * 128 + 160));
            a++;
        }
    }
    if (d->n34 != 0) {
        c = d->p38;
        for (j = 0; j < d->n34; j++) {
            if (c->n != 0) {
                b = c->p;
                for (i = 0; i < c->n; i++) {
                    func_L01_0044EA78(o->m, (u8 *)o + (b->x4 * 128 + 160));
                    b++;
                }
            }
            c++;
        }
    }
    o->m->h34 |= 0x41;
    o->m->h34 &= 0xEFFF;
    o->m->x98 = 0;
    func_L01_004AA7E8(o->m, 1);
    if (flag) {
        func_L01_004450F0(o->m, 1, -1);
        o->m->h34 |= 2;
    } else {
        o->m->b30 = 255;
        func_L01_004450F0(o->m, 3, -1);
    }
    o->d = 0;
    o->m = 0;
    o->xC48 = 0;
}
/* localdecomp:end func_L01_003AB248 */

/* localdecomp:start func_L01_003AB448 */

void func_L01_003AB448(u8 *obj, Vec4_003AB448 a, Vec4_003AB448 b) {
    *(Vec4_003AB448 *)(obj + 128) = a;
    *(Vec4_003AB448 *)(obj + 144) = b;
}
/* localdecomp:end func_L01_003AB448 */

/* localdecomp:start func_L01_003AB470 */
extern u8 D_001A4C60[];
extern u8 *D_L01_001E001C;
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern f32 *func_00382348(u8 *);

s32 func_L01_003AB470(s32 a0, u8 *p) {
    u8 *o;
    f32 *v;

    if (*(s32 *)(p + 0xC20) != -1 && func_00382380(D_001A4C60, *(s32 *)(p + 0xC20), 0) != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0xC24) != -1 && func_L01_00456500(D_001A4C60, *(s32 *)(p + 0xC24)) != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0xD28) != -1 && func_L01_00445AD0(*(s32 *)(p + 0xD28), -1, 0) <= *(s16 *)(p + 0xD2C)) {
        return 1;
    }
    if (*(s32 *)(p + 0xD24) != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0xC28) != -1) {
        o = D_L01_001E001C + (*(s32 *)(p + 0xC28) << 8);
        if (o == 0 || o[0x20] == 254) {
            return 1;
        }
        if (o[0x20] == 253) {
            return 1;
        }
        v = func_00382348(o);
        if (v != 0 && *v <= 0.0f) {
            return 1;
        }
    }
    if (*(s32 *)(p + 0xC2C) != -1 && func_L01_00445AD0(*(s32 *)(p + 0xC2C), -1, 1) == 0) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003AB470 */

/* localdecomp:start func_L01_003AB598 */
typedef struct { u8 p0[0x34]; s16 h34; u8 p36[0x44 - 0x36]; u8 b44; } S_003AB598;
typedef struct { s32 w0; u8 p4[0x14]; f32 f18; } O_003AB598;
void func_L01_003AB598(u8 *a0, O_003AB598 *a1) {
    S_003AB598 *s = *(S_003AB598 **)(a0 + 0x68);
    if (s->h34 >= 2) {
        a1->w0 = s->h34;
    }
    if (s->b44 != 0) {
        a1->f18 = (f32)s->b44;
    }
}
/* localdecomp:end func_L01_003AB598 */

/* localdecomp:start func_L01_003AB5D0 */
extern f32 D_L01_001DE440 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE440, 4");
extern f32 D_L01_001DE3AC __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE3AC, 4");
extern f32 D_L01_001DE3A8 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE3A8, 4");
extern f32 D_L01_001DE3B8 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE3B8, 4");
extern f32 D_L01_001DE3BC __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE3BC, 4");
extern f32 D_L01_001DE3C0 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE3C0, 4");
extern f32 D_L01_001DE3B0 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE3B0, 4");
extern f32 D_L01_001DE3B4 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE3B4, 4");
typedef struct { u8 pad0[0xC44]; f32 strength; u8 padC48[0xD00-0xC48]; f32 a, b, c; } State_003AB5D0;
void func_L01_003AB5D0(u8 *object, State_003AB5D0 *state, f32 *x, f32 *y, f32 *z) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    f32 radians;
    f32 timestep;
    if (object[0x20] == 2) {
        *x = 0;
        *y = 0;
        *z = 0;
    } else if (state->strength < 1.0f) {
        state->strength += D_L01_001DE440;
        if (state->strength > 1.0f)
            state->strength = 1.0f;
    }
    radians = 0.01745329238474369f;
    timestep = 0.020000001415610313f;
    state->a = func_0038DAB8(state->a, D_L01_001DE3AC * radians * timestep);
    *x = func_0038D0B0(state->a) * D_L01_001DE3A8 * state->strength;
    { f32 sb = func_0038D0B0(state->b);
      f32 sc = func_0038D0B0(state->c);
      *y = D_L01_001DE3B8 * sb * sc * 1.5f * state->strength; }
    { f32 sb = func_0038D0B0(state->b);
      f32 cc = func_0038D098(state->c);
      *z = D_L01_001DE3B8 * sb * cc * state->strength; }
    state->b = func_0038DAB8(state->b, D_L01_001DE3BC * radians * timestep);
    state->c = func_0038DAB8(state->c, D_L01_001DE3C0 * radians * timestep);
    *z += func_0038D0B0(state->a + D_L01_001DE3B0) * D_L01_001DE3B4 * state->strength;
}
/* localdecomp:end func_L01_003AB5D0 */

INCLUDE_ASM("asm/levels", func_L01_003AB790);

/* localdecomp:start func_L01_003ABD10 */
f32 func_L01_003ABD10(u8 *object, u8 *state, f32 value) {
    extern f32 func_L01_00477ED0(s32, s32, f32, f32, f32);
    if (object[0x20] == 5 && *(s32 *)(state + 0xC54) != 0) return value;
    return func_L01_00477ED0(*(s32 *)(state + 0xD10), 1, *(f32 *)(state + 0xD6C), *(f32 *)(state + 0xD14), value);
}
/* localdecomp:end func_L01_003ABD10 */

/* localdecomp:start func_L01_003ABD60 */
typedef struct {
    s32 count;
    u8 pad4[12];
    Vec4_003AB448 pts[1];
} Path_003ABD60;
f32 func_L01_003ABD60(u8 *object, Path_003ABD60 *path, s32 *index, f32 position, f32 distance) {
    f32 step;
    f32 ratio;
    f32 remaining = 1.0f;
    while (0.0f < remaining) {
        if (position < 0.0f) {
            *index = -1;
            step = (distance / *(f32 *)(object + 0xD6C)) * remaining;
            if (position + step >= 0.0f) {
                *index = 0;
                ratio = (0.0f - position) / step;
                remaining -= ratio * remaining;
                position = 0.0f;
            } else {
                position += step;
                remaining = 0.0f;
            }
        } else {
            s32 seg = (s32)position;
            f32 offset;
            *index = seg;
            step = (distance / path->pts[seg].v[3]) * remaining;
            offset = position + step - (f32)seg;
            if (offset >= 1.0f && seg < path->count - 1) {
                ratio = (step - (offset - 1.0f)) / step;
                position += step * ratio;
                remaining -= ratio * remaining;
                *index = (s32)position;
            } else {
                position += step;
                remaining = 0.0f;
            }
        }
    }
    return position;
}
/* localdecomp:end func_L01_003ABD60 */

/* localdecomp:start func_L01_003ABE88 */
typedef struct { s32 count; u8 pad[12]; Vec4_003AB448 a[1]; Vec4_003AB448 b[1]; } Points_003ABE88;
static __inline__ void copy_003ABE88(Vec4_003AB448 *dst, Vec4_003AB448 *src) {
    *(u128_t *)dst = *(u128_t *)src;
}
void func_L01_003ABE88(u8 *object, Points_003ABE88 *points, s32 index, void *out) {
    extern void func_0038CDF8(void *, void *, void *);
    Vec4_003AB448 a;
    Vec4_003AB448 b;
    s32 n = points->count;
    if (index >= n) {
        copy_003ABE88(&a, &(*(Vec4_003AB448 *)(object + 0xD70)));
        copy_003ABE88(&b, &(*(Vec4_003AB448 *)(object + 0xD80)));
    } else if (index == n - 2) {
        copy_003ABE88(&a, &(((Points_003ABE88 *)((index << 4) + (s32)points))->a[0]));
        copy_003ABE88(&b, &(((Points_003ABE88 *)((index << 4) + (s32)points))->b[0]));
    } else if (index == n - 1) {
        b = *(Vec4_003AB448 *)(object + 0xD70);
        a = ((Points_003ABE88 *)((index << 4) + (s32)points))->a[0];
    } else {
        if (index < 0) {
            a = *(Vec4_003AB448 *)(object + 0xD60);
        } else {
            a = ((Points_003ABE88 *)((index << 4) + (s32)points))->a[0];
        }
        b = ((Points_003ABE88 *)((index << 4) + (s32)points))->b[0];
    }
    func_0038CDF8(out, &a, &b);
}
/* localdecomp:end func_L01_003ABE88 */

INCLUDE_ASM("asm/levels", func_L01_003ABF48);

INCLUDE_ASM("asm/levels", func_L01_003AC000);
