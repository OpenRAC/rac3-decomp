#include "common.h"

/* NTSC-U version of func_00385A98 (boot_elf): 0.02 -> 0.0166667; 0.02 -> 0.0166667; 0.02 -> 0.0166667 */
#include "common.h"


extern void func_U_0038DF00(s32, s32, f32);



typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_37E0F0;
typedef int Q_37E0F0 __attribute__((mode(TI)));
extern s32 func_13D3E0(void);
typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; u16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E568;
typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; s16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E630;
void func_U_0038D050(void *, void *, s32);
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_U_00222500[];
extern void func_U_0038DDE0(f32, f32);
extern f32 func_U_0038DE28(f32, f32);
s32 func_U_00381CB0(void *, s32, s32, s32);
typedef struct { s32 a, b, c, d, e; } S_37D000;
typedef int u128_37EB68 __attribute__((mode(TI)));
typedef struct { u8 p0[0x2B8]; f32 f2B8; u8 p2BC[0xC]; f32 f2C8; u8 p2CC[0x58]; s32 f324; u8 p328[0x138]; } E_37EB68;
typedef struct { u8 p0[0xC]; s32 fC; u8 p10[0x24 - 0x10]; s32 f24; } T_37EE80;
typedef struct { u8 p0[0x1C]; T_37EE80 *f1C; } R_37EE80;
typedef struct { u8 p0[0x5D0]; s32 f5D0; u8 p5D4[0x5E0 - 0x5D4]; s32 f5E0; u8 p5E4[0x690 - 0x5E4]; s32 f690; u8 p694[0x6A0 - 0x694]; s32 f6A0; u8 p6A4[0x25CC - 0x6A4]; s32 f25CC; } A_37EE80;
typedef struct { u8 p0[0x24C]; s32 f24C; u8 p250[0x460 - 0x250]; } E_37EE80;
typedef struct { u8 p0[0x10]; s32 f10; u8 p14[0xC]; } G2_37EE80;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_37F228;
typedef int Q_37F228 __attribute__((mode(TI)));
extern void func_U_0038D290(s32 a, s32 b, f32 x);
typedef int u128_37F420 __attribute__((mode(TI)));
extern void func_U_0038D290(s32 a, s32 b, f32 x);
typedef int u128_37F4F8 __attribute__((mode(TI)));
typedef struct { u8 p0[2]; u8 b2; u8 b3; u8 p4[0x50 - 4]; u128_37F4F8 q50; u128_37F4F8 q60; u8 p70[0xC0 - 0x70]; u128_37F4F8 qC0; u128_37F4F8 qD0; u8 pE0[0x460 - 0xE0]; } E_37F4F8;
typedef int u128_t __attribute__((mode(TI)));
typedef int Q_3801C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3801C0;
typedef union { V_3801C0 v; u128_t q; f32 f[4]; } U_3801C0;
typedef struct { u8 p0[0x86]; s16 h86; } P_3801C0;
typedef struct {
    f32 f0, f4, f8, fC;
    f32 f10[4];
    U_3801C0 u20;
    u128_t q30;
    u128_t q40;
    U_3801C0 u50;
    U_3801C0 u60;
    V_3801C0 v70;
    V_3801C0 v80;
    u128_t q90;
    f32 fA0, fA4, fA8;
    f32 fAC[5];
    u8 pC0[0x30];
} B_3801C0;
typedef struct {
    u8 p0[0x40];
    U_3801C0 u40;
    u8 p50[8];
    f32 f58;
    u8 p5C[0x24];
    V_3801C0 v80;
    u8 p90[0x6C];
    s32 iFC;
    s32 i100;
    u8 p104[0x460 - 0x150 - 0x104];
} A_3801C0;
typedef struct {
    u8 p0[0x50];
    P_3801C0 *f50;
    u8 p54[0xC];
    B_3801C0 b;
    A_3801C0 a;
} E_3801C0;
typedef struct { f32 x, y, z, w; } V_3804A0;
typedef union { u128_t q; V_3804A0 v; } Q_3804A0;
typedef struct { Q_3804A0 q0; u8 pad10[0x40]; u8 *f50; u8 pad54[0x3FC]; s32 f450; u8 pad454[0xC]; } E_3804A0;
typedef struct { u8 p0[8]; f32 f8; u8 pC[0x460 - 0xC]; } E_00380600;
typedef struct { u8 p0[0x40]; f32 f40, f44; u8 p48[0x100 - 0x48]; s32 f100, f104; u8 p108[0x118 - 0x108]; f32 f118; u8 p11C[0x12E - 0x11C]; u8 b12E, b12F, b130, b131, b132; } R_00380600;
typedef struct { u8 p0[0xC0]; s32 fC0; } Q_00380600;
typedef struct { u8 pad[0xC8]; f32 fC8; f32 fCC; u8 fD0[0x460 - 0xD0]; } S_3807F0;
extern f32 func_U_003C43B8(f32 *, f32, f32);
typedef struct { u8 pad[0xD4]; f32 fD4; f32 fD8; f32 fDC; u8 fE0[0x460 - 0xE0]; } S_3808E0;
extern f32 func_U_003C43B8(f32 *, f32, f32);
typedef struct { u128_t q0; u128_t q1; u8 pad[0x360]; f32 f380[4]; f32 f390[4]; f32 f3a0[4]; f32 f3b0[4]; f32 f3c0[4]; f32 f3d0[4]; u128_t q3e0; u8 pad2[0x70]; } E_003809F0;
typedef struct { u8 p0[0x10]; u8 pos[0x10]; u8 b20; } O_380D48;
typedef struct {
    O_380D48 *obj; s32 state; f32 f8; s32 pC;
    s16 h10[16]; s16 h30[16]; s32 c50[16]; f32 f90[16]; f32 fD0[16];
} S_380D48;
extern f32 func_U_0038D228(void *, void *);
extern void func_U_00386460(f32 *, void *);
extern long func_U_00389920(s32);
typedef struct {
    u8 p0[0x10]; f32 f10; s32 f14; s32 f18; f32 f1C; u8 p20[6]; s16 h26; f32 f28; s32 f2C;
    u8 p30[8]; f32 f38; f32 f3C;
} S_3810C0;
extern void func_U_0038C000(f32, f32, f32, f32, f32, s32, s32, long, s32, s32, s32, s32, f32, f32);
extern long func_U_00389920(s32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3813E0;
typedef int Q_3813E0 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x1430];
    s32 f1430;
    u8 p1434[0x2C];
    u8 *f1460;
    f32 f1464;
    f32 f1468;
} S_3813E0;
typedef struct { f32 f0; s16 h4; u8 p6[0xA]; f32 f10; } P_3813E0;
extern S_3813E0 D_001A4BE0;
extern f32 D_U_001D57C8, D_U_001D57CC, D_U_001D57D0, D_U_001D57D4, D_U_001D5804, D_U_001D5808, D_U_001D5830, D_U_001D5834;
extern s32 D_U_001D57D8, D_U_001D57E8;
extern f32 D_U_001D57F8;
extern s32 D_U_001D580C, D_U_001D5810, D_U_001D5814, D_U_001D5818, D_U_001D581C, D_U_001D5820, D_U_001D5824, D_U_001D5828, D_U_001D582C;
extern s32 D_001D4BD0_00385A98, D_001D4BD4_00385A98;
extern P_3813E0 *func_U_00382748(u8 *);
extern void func_U_00386460(f32 *, void *);
extern f32 func_U_0038D228(void *, void *);
extern f32 func_U_0038D488(f32, f32);
extern void func_U_0038C000(f32, f32, f32, f32, f32, s32, s32, long, s32, s32, s32, s32, f32, f32);
extern void func_U_0038C828(s32, s32, s32, s32, s32 *, s32 *, s32, s32, f32, f32);
extern long func_U_00389920(s32);
/* localdecomp:start func_U_00385A70 */
__asm__(".extern D_U_001D57C8, 4");
__asm__(".extern D_U_001D57CC, 4");
__asm__(".extern D_U_001D57D0, 4");
__asm__(".extern D_U_001D57D4, 4");
__asm__(".extern D_U_001D57D8, 4");
__asm__(".extern D_U_001D57E8, 4");
__asm__(".extern D_U_001D57F8, 4");
__asm__(".extern D_U_001D5804, 4");
__asm__(".extern D_U_001D5808, 4");
__asm__(".extern D_U_001D580C, 4");
__asm__(".extern D_U_001D5810, 4");
__asm__(".extern D_U_001D5814, 4");
__asm__(".extern D_U_001D5818, 4");
__asm__(".extern D_U_001D581C, 4");
__asm__(".extern D_U_001D5820, 4");
__asm__(".extern D_U_001D5824, 4");
__asm__(".extern D_U_001D5828, 4");
__asm__(".extern D_U_001D582C, 4");
__asm__(".extern D_U_001D5830, 4");
__asm__(".extern D_U_001D5834, 4");
void func_U_00385A70(void) {
    f32 scr[4];
    f32 pos[2];
    V4_3813E0 v;
    s32 rgb4[4];
    s32 clr2[4];
    u8 *obj;
    P_3813E0 *info;
    f32 total, part, zoom, size;
    s32 i;
    if (D_001A4BE0.f1430 == 0 && D_001A4BE0.f1464 == 0.0f) return;
    if (D_001A4BE0.f1430 != (s32)D_001A4BE0.f1460) {
        func_U_003C43B8(&D_001A4BE0.f1464, 0.0f, D_U_001D57D4 * 0.0166666675f);
        if (D_001A4BE0.f1464 <= 0.0f) D_001A4BE0.f1460 = (u8 *)D_001A4BE0.f1430;
    } else if (D_001A4BE0.f1430 != 0 && D_001A4BE0.f1464 < 1.0f) {
        func_U_003C43B8(&D_001A4BE0.f1464, 1.0f, D_U_001D57D4 * 0.0166666675f);
        D_001A4BE0.f1468 = ((f32 (*)(f32, f32))func_U_0038DDE0)(D_001A4BE0.f1468, D_U_001D5808 * 0.017453292f * 0.0166666675f);
    }
    D_001A4BE0.f1468 = ((f32 (*)(f32, f32))func_U_0038DDE0)(D_001A4BE0.f1468, D_U_001D5808 * 0.017453292f * 0.0166666675f);
    obj = D_001A4BE0.f1460;
    if (obj == 0) return;
    if (D_001A4BE0.f1464 == 0.0f) return;
    part = 0.0f;
    info = func_U_00382748(obj);
    total = part;
    if (info != 0) {
        Q_3813E0 qa, qb;
        func_U_0038D290((s32)&v, (s32)(obj + 0xE0), info->f10);
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(V4_3813E0 *)(obj + 0x10)));
        __asm__("vadd.xyz %0, %0, %1" : "+j"(qa) : "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(v) : "j"(qa));
        total = (f32)info->h4;
        part = info->f0;
    } else {
        v = *(V4_3813E0 *)(obj + 0x10);
    }
    zoom = 0.75f;
    func_U_00386460(scr, &v);
    pos[0] = (scr[0] - (f32)D_001D4BD0_00385A98) * 0.0625f;
    pos[1] = (scr[1] - (f32)D_001D4BD4_00385A98) * 0.0625f;
    if (info != 0) zoom = info->f10;
    if (zoom > 2.0f) zoom = 2.0f;
    size = func_U_0038D488(func_U_0038D228(D_U_00222500, obj + 0x10), zoom) * D_U_001D57C8;
    if (size > D_U_001D57CC) size = D_U_001D57CC;
    else if (size < D_U_001D57D0) size = D_U_001D57D0;
    for (i = 0; i < 3; i++) {
        f32 ang, sc;
        long tex;
        s32 rgba;
        switch (i) {
        case 0: ang = D_001A4BE0.f1468; break;
        case 1: ang = -D_001A4BE0.f1468; break;
        case 2: default: ang = D_U_001D5804 * 0.017453292f; break;
        }
        tex = func_U_00389920(i + 0x33);
        rgba = ((s32 (*)(s32, s32, f32))func_U_0038DF00)((&D_U_001D57E8)[i], (&D_U_001D57D8)[i], D_001A4BE0.f1464);
        sc = (((&D_U_001D57F8)[i] - 1.0f) * (1.0f - D_001A4BE0.f1464) + 1.0f) * size;
        func_U_0038C000(pos[0], pos[1], sc, sc, ang, 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_U_0038C000(pos[0], pos[1], sc, sc, ((f32 (*)(f32, f32))func_U_0038DDE0)(ang, 1.5707964f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_U_0038C000(pos[0], pos[1], sc, sc, ((f32 (*)(f32, f32))func_U_0038DDE0)(ang, 3.1415927f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
        func_U_0038C000(pos[0], pos[1], sc, sc, func_U_0038DE28(ang, 1.5707964f), 0x40, 0x40, tex, 0xFFFFF3, rgba, 0, 0, 0.0f, 0.0f);
    }
    if (total != 0.0f) {
        long x, y;
        f32 half;
        f32 half2;
        s32 rgba;
        clr2[0] = D_U_001D5810;
        clr2[1] = D_U_001D5814;
        clr2[2] = D_U_001D5818;
        clr2[3] = D_U_001D581C;
        rgba = ((s32 (*)(s32, s32, f32))func_U_0038DF00)(D_U_001D5828 & 0xFFFFFF, D_U_001D5828, D_001A4BE0.f1464);
        rgb4[3] = rgba;
        rgb4[2] = rgba;
        rgb4[1] = rgba;
        rgb4[0] = rgba;
        x = (s32)scr[0];
        y = (s32)scr[1];
        half = D_U_001D5834 * func_U_0038D488(D_U_001D5830, total);
        func_U_0038C828(x, y, (s32)(size * (f32)D_U_001D5820), (s32)(size * (f32)D_U_001D5824), rgb4, clr2, D_U_001D580C, 0x10, half, -half);
        rgba = ((s32 (*)(s32, s32, f32))func_U_0038DF00)(D_U_001D582C & 0xFFFFFF, D_U_001D582C, D_001A4BE0.f1464);
        rgb4[3] = rgba;
        rgb4[2] = rgba;
        rgb4[1] = rgba;
        rgb4[0] = rgba;
        half2 = half - (half + half) * (part / total);
        func_U_0038C828(x, y, (s32)(size * (f32)D_U_001D5820), (s32)(size * (f32)D_U_001D5824), rgb4, clr2, D_U_001D580C, 0x10, half, half2);
    }
}
/* localdecomp:end func_U_00385A70 */
