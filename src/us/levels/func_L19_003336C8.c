#include "common.h"

/* NTSC-U counterpart of func_L19_003340A0 (src/levels/shared/L19_00331380.c): 0.02 -> 0.0166667 */
typedef struct { u8 pad[0x330]; s32 ids[8]; } Grp_003345D0;

typedef struct {
    u8 pad[0x330];
    s32 ids[8];
} Obj_003347B0;

typedef struct {
    u8 pad[0x330];
    s32 ids[8];
} GroupState_00334958;

typedef struct {
    u8 pad[0x330];
    s32 ids[8];
} Obj_00334B10;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) t1v;
typedef t1v t0v;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00332360;
typedef struct {
    u8 pad0[0x350];
    s32 w350;
    u8 pad354[4];
    u8 *p358;
    u8 pad35C[4];
    s32 w360;
} St_00332360;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0xF];
    unsigned long d30;
    u8 pad38[0x30];
    St_00332360 *p68;
    u8 pad6C[0x29];
    u8 b95;
    u8 pad96[2];
    s32 w98;
    u8 pad9C[0xE];
    s16 hAA;
} Obj_00332360;
typedef struct {
    u8 pad0[0x25C0];
    s32 w25C0;
    u8 pad25C4[0x286C - 0x25C4];
    s32 w286C;
} Hero_00332360;

#include "vu0.h"
typedef struct {
    u8 pad0[0x10];
    u8 b10;
} An_00331380;
typedef struct {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x44 - 0x14];
    u16 h44;
    u8 pad46[0x48 - 0x46];
    An_00331380 *a48;
    u8 pad4C[0x50 - 0x4C];
    An_00331380 *a50;
    An_00331380 *a54;
} Cl_00331380;
typedef struct M_00331380 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[3];
    Cl_00331380 *cls;
    u8 pad28[0x34 - 0x28];
    u16 h34;
    u8 pad36[0x42 - 0x36];
    u8 b42;
    u8 b43;
    u8 pad44[0x60 - 0x44];
    u8 b60;
    u8 pad61[0x68 - 0x61];
    void *pv;
    u8 pad6C[0x95 - 0x6C];
    u8 b95;
    u16 h96;
    s32 w98;
    u8 pad9C[0xAA - 0x9C];
    s16 hAA;
    u8 padAC[0xC0 - 0xAC];
    f32 mtx[12];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} M_00331380;
typedef struct {
    u8 pad0[0x80];
    u8 b80[0x140 - 0x80];
    f32 f140;
    f32 f144;
    u8 pad148[0x164 - 0x148];
    f32 f164;
    u8 pad168[0x170 - 0x168];
    f32 f170;
    f32 f174;
    u8 pad178[0x1C0 - 0x178];
    s32 w1C0;
    u8 pad1C4[0x1C8 - 0x1C4];
    s32 w1C8;
    u8 pad1CC[0x1D4 - 0x1CC];
    s32 w1D4;
    u8 pad1D8[0x1E0 - 0x1D8];
    vu0_v4 v1E0;
    u8 pad1F0[0x218 - 0x1F0];
    s32 w218;
    u8 pad21C[0x354 - 0x21C];
    M_00331380 *p354;
    M_00331380 *p358;
    u8 pad35C[0x364 - 0x35C];
    f32 f364;
    u8 pad368[0x36C - 0x368];
    u8 t36C[4];
    s32 w370;
    s32 w374;
    s32 w378;
    s32 w37C;
    u8 pad380[0x384 - 0x380];
    f32 f384;
    f32 f388;
    u8 b38C[0x3A0 - 0x38C];
    f32 f3A0;
    u8 pad3A4[0x3C0 - 0x3A4];
    vu0_v4 v3C0;
} P_00331380;
extern Hero_00332360 D_1A4BE0;
extern u8 D_1A4C60[];
extern s32 D_L19_001DF240_003336C8;
extern f32 func_00388978(f32);
extern f32 func_00389380(f32, f32);
#define HERO_00331380 ((u8 *)&D_1A4BE0)
extern Hero_00332360 D_1A4BE0;
#include "vu0.h"
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[2];
    u8 b38;
    u8 pad39[0x140 - 0x39];
    f32 f140;
    f32 f144;
    f32 f148;
    f32 f14C;
    f32 f150;
    u8 pad154[0x16C - 0x154];
    f32 f16C;
    f32 f170;
    f32 f174;
    u8 pad178[0x188 - 0x178];
    u8 *p188;
    u8 *p18C;
    u8 pad190[0x230 - 0x190];
    u8 a230[0x80];
    u8 a2B0[0xA0];
    s32 w350;
    u8 pad354[4];
    s32 w358[14];
    u8 pad390[0x10];
    s32 w3A0;
    f32 f3A4;
    s32 w3A8;
    u8 pad3AC[4];
    s32 w3B0;
    s32 w3B4;
    u8 pad3B8[4];
    f32 f3BC;
    vu0_v4 v3C0;
    vu0_v4 v3D0;
} S_00333160;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[4];
    u8 *p24;
    u8 pad28[0xC];
    u16 h34;
    u8 pad36[0xD];
    u8 b43;
    u8 pad44[0x24];
    S_00333160 *s;
    u8 pad6C[0x12];
    u8 b7E;
    u8 pad7F[0x2B];
    s16 hAA;
    u8 padAC[0x14];
    vu0_v4 vC0;
} A_00333160;
typedef int u128_t __attribute__((mode(TI)));
extern u16 *D_L19_0021C260_003336C8[];
extern u8 *D_L19_001DF71C_003336C8;
extern s32 D_L19_001DF758_003336C8 __attribute__((section(".sdata")));
#include "vu0.h"
typedef struct {
    u8 pad0[0x12];
    s16 count;
    u8 pad14[0xC];
    s32 *ids;
    u8 pad24[0xC];
} E_003337D8;
typedef struct {
    s32 count;
    u8 pad4[0x1C];
    E_003337D8 e[1];
} T_003337D8;
#include "vu0.h"
extern void func_L19_003336C8(void *a);

/* localdecomp:start func_L19_003336C8 */
typedef struct { s32 a, b; } Col_003340A0;
typedef struct { u8 pad[0x78]; s32 f78; } O_003340A0;
extern f32 D_L19_001DCC68;
__asm__(".extern D_L19_001DCC68, 4");
extern f32 D_L19_001DCC6C;
__asm__(".extern D_L19_001DCC6C, 4");
extern f32 D_L19_001DCC70_003336C8;
__asm__(".extern D_L19_001DCC70_003336C8, 4");
extern f32 D_L19_001DCC74;
__asm__(".extern D_L19_001DCC74, 4");
extern s32 D_L19_001DCC28_003336C8[2];
__asm__(".extern D_L19_001DCC28_003336C8, 8");
extern s32 D_L19_001DCC30_003336C8[2];
__asm__(".extern D_L19_001DCC30_003336C8, 8");
extern s32 D_L19_001DCC38_003336C8[2];
__asm__(".extern D_L19_001DCC38_003336C8, 8");
extern s32 D_L19_001DCC40[2];
__asm__(".extern D_L19_001DCC40, 8");
extern s32 D_L19_001DCC50_003336C8[2];
__asm__(".extern D_L19_001DCC50_003336C8, 8");
extern s32 D_L19_001DCC58[2];
__asm__(".extern D_L19_001DCC58, 8");
extern s32 D_L19_001DCC60_003336C8[2];
__asm__(".extern D_L19_001DCC60_003336C8, 8");
extern s32 D_L19_001DF240_003336C8;
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_00402498(void *, void *);
extern void func_L19_003339D0(u8 *);

void func_L19_003336C8(void *a) {
    u8 *a0 = a;
    u8 *p = *(u8 **)(a0 + 0x68);
    Col_003340A0 c;
    f32 w;
    u16 *q;
    u8 *e;

    if (a0[0x31] == 0) {
        return;
    }
    switch (a0[0x95]) {
    case 1:
    case 7:
        c.a = D_L19_001DCC30_003336C8[0];
        c.b = D_L19_001DCC30_003336C8[1];
        w = D_L19_001DCC70_003336C8 * 0.017453292f * 0.0166666675f;
        break;
    case 8:
        c.a = D_L19_001DCC38_003336C8[0];
        c.b = D_L19_001DCC38_003336C8[1];
        w = D_L19_001DCC74 * 0.017453292f * 0.0166666675f;
        break;
    case 2:
        c.a = D_L19_001DCC38_003336C8[0];
        c.b = D_L19_001DCC38_003336C8[1];
        w = D_L19_001DCC6C * 0.017453292f * 0.0166666675f;
        break;
    case 3:
        c.a = D_L19_001DCC50_003336C8[0];
        c.b = D_L19_001DCC50_003336C8[1];
        w = D_L19_001DCC6C * 0.017453292f * 0.0166666675f;
        break;
    case 4:
        c.a = D_L19_001DCC60_003336C8[0];
        c.b = D_L19_001DCC60_003336C8[1];
        w = D_L19_001DCC6C * 0.017453292f * 0.0166666675f;
        break;
    case 5:
        c.a = D_L19_001DCC58[0];
        c.b = D_L19_001DCC58[1];
        w = D_L19_001DCC6C * 0.017453292f * 0.0166666675f;
        break;
    case 6:
        c.a = D_L19_001DCC40[0];
        c.b = D_L19_001DCC40[1];
        w = D_L19_001DCC6C * 0.017453292f * 0.0166666675f;
        break;
    case 0:
    default:
        c.a = D_L19_001DCC28_003336C8[0];
        c.b = D_L19_001DCC28_003336C8[1];
        w = D_L19_001DCC68 * 0.017453292f * 0.0166666675f;
        break;
    }
    *(f32 *)(p + 0x35C) = func_00389380(*(f32 *)(p + 0x35C), w);
    ((O_003340A0 *)a0)->f78 = func_003894A0(c.a, c.b, func_00388978(*(f32 *)(p + 0x35C)) * 0.5f + 0.5f);
    if (*(s32 *)(p + 0x368) != D_L19_001DF240_003336C8) {
        for (q = D_L19_0021C260_003336C8[a0[0x21]];
             a0[0x21] != 0xFF && a0[0x21] <= D_L19_001DF758_003336C8 && q != 0 &&
             ((s16)q[-1] >= 0 || q == D_L19_0021C260_003336C8[a0[0x21]]);
             q++) {
            e = D_L19_001DF71C_003336C8 + ((*q & 0x7FFF) << 8);
            if (e == 0)
                break;
            *(s32 *)(*(u8 **)(e + 0x68) + 0x368) = D_L19_001DF240_003336C8;
        }
        func_L01_00402498(func_L19_003339D0, a0);
    }
}
/* localdecomp:end func_L19_003336C8 */
