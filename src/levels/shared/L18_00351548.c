#include "common.h"
#include "vu0.h"

typedef int Quad_3543C8 __attribute__((mode(TI)));
typedef struct Obj_3543C8 {
    u8 pad0[0x10];
    Quad_3543C8 pos;
    u8 pad20[4];
    u8 *def;
    u8 pad28[0xC];
    u16 flags;
    u8 pad36[0x32];
    u8 *vars;
    u8 pad6C[0x2A];
    u16 timer;
    s32 w98;
    u8 pad9C[0xC];
    u8 alpha;
    u8 padA9[0x13];
    u8 state;
    u8 padBD[0x33];
    Quad_3543C8 pos2;
} Obj_3543C8;
typedef struct Vars_3543C8 {
    u8 pad0[0x30];
    f32 hp;
    s16 maxhp;
    s16 hurt;
    u8 pad38[0x48];
    s32 w80;
    u8 pad84[0x2FE];
    u8 b382;
    u8 pad383[0x7D];
    Quad_3543C8 q400;
    Quad_3543C8 q410;
} Vars_3543C8;

/* declared by functions of L18_003514B8.c, which this file was cut from */
typedef int u128_t __attribute__((mode(TI)));
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L18_00351548 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) V_00351548;

extern s32 func_L01_0041A4F0(void);
extern void func_L01_0043A430(void *, s32, void *);
extern void func_0038D278(void *);
extern void *func_L01_0043B548(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L18_003514B8(u8 *);
extern s32 D_001D545C;
extern s32 D_001D545C_00351548;
__asm__(".extern D_001D545C_00351548, 16");
extern u8 D_0014275B[];
extern f32 D_L18_001DA8F8;
extern f32 D_L18_002F1F30[];
extern u128_t D_L18_001D9A60 __attribute__((section(".sdata")));
extern s32 D_L18_001D678C;
extern V_00351548 D_L18_001DFD50 __attribute__((section(".sdata")));

void func_L18_00351548(void *arg) {
    u8 *o = arg;
    u8 *v = *(u8 **)(o + 0x68);
    f32 scale;
    s32 level;
    s32 id;
    s32 i;
    V_00351548 d;

    scale = 1.0f;
    (*(u8 **)(o + 0x24))[0x46] = 13;
    *(s32 *)(v + 0x350) = 0;
    qzero(v + 0x290);
    *(s32 *)(v + 0x354) = 0;
    qzero(v + 0x2A0);
    qzero(v + 0x2B0);
    qzero(v + 0x3F0);
    if (func_L01_0041A4F0() != 0) {
        level = D_001D545C;
        scale = level == 7 && D_0014275B[0] ? D_L18_001DA8F8 : D_L18_002F1F30[level];
    }
    id = D_001D545C_00351548;
    if (id == 0x12) {
        s32 n = scale * 400.0f;
        *(s16 *)(v + 0x34) = n;
        *(f32 *)(v + 0x30) = n;
    } else if (id == 0x14) {
        *(s16 *)(v + 0x34) = 400;
        *(f32 *)(v + 0x30) = 400.0f;
    } else if (id == 0x1A) {
        s32 n = scale * 300.0f;
        *(s16 *)(v + 0x34) = n;
        *(f32 *)(v + 0x30) = n;
    } else if (id == 0x1D) {
        s32 n = scale * 100.0f;
        *(s16 *)(v + 0x34) = n;
        *(f32 *)(v + 0x30) = n;
    } else {
        s32 n = scale * 150.0f;
        *(s16 *)(v + 0x34) = n;
        *(f32 *)(v + 0x30) = n;
    }
    v[0x3E] = 3;
    v[0x38] = 1;
    v[0x58] = 30;
    v[0x5A] = 32;
    *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * 0.8f;
    *(f32 *)(v + 0x368) = *(f32 *)(o + 0x18);
    qzero(v + 0x2C0);
    *(f32 *)(v + 0x390) = 0.05235988f;
    *(s32 *)(v + 0x3AC) = -1;
    *(s32 *)(v + 0x3D4) = 8;
    *(s32 *)(v + 0x3D8) = 21;
    *(s32 *)(v + 0x3DC) = 5;
    *(s32 *)(v + 0x3E0) = 50;
    *(f32 *)(v + 0x388) = 0.0f;
    *(f32 *)(v + 0x38C) = 0.0f;
    *(f32 *)(v + 0x394) = 0.0f;
    *(f32 *)(v + 0x39C) = 0.0f;
    *(f32 *)(v + 0x398) = 0.0f;
    *(f32 *)(v + 0x3A0) = 0.0f;
    *(f32 *)(v + 0x360) = 0.0f;
    *(f32 *)(v + 0x364) = 0.0f;
    *(f32 *)(v + 0x3A4) = 0.0f;
    *(f32 *)(v + 0x3A8) = 0.0f;
    v[0x380] = 0;
    v[0x381] = 0;
    *(s32 *)(v + 0x3B8) = 0;
    *(s16 *)(v + 0x37E) = 0;
    *(s32 *)(v + 0x374) = 0;
    *(s32 *)(v + 0x378) = 0;
    *(s16 *)(v + 0x37C) = 0;
    *(s32 *)(v + 0x3E4) = 0;
    *(s32 *)(v + 0x3E8) = 0;
    for (i = 0; i < 2; i++) {
        if (v[0x91 + i * 0x40] == 0) {
            func_L01_0043A430(o, i + 4, v + 0x90 + i * 0x40);
        }
        if (v[0x111 + i * 0x40] == 0) {
            func_L01_0043A430(o, i + 2, v + 0x110 + i * 0x40);
        }
        if (v[0x191 + i * 0x40] == 0) {
            func_L01_0043A430(o, i + 9, v + 0x190 + i * 0x40);
        }
    }
    func_0038D278(v + 0x2D0);
    *(u128_t *)(v + 0x3C0) = D_L18_001D9A60;
    *(s32 *)(v + 0x3BC) = D_L18_001D678C == 0;
    if (*(s32 *)(v + 0x3BC) == 0) {
        vec_sub_ab(&d, o + 0x10, &D_L18_001DFD50);
        func_0038CF68(&d, &d, 1.0f);
        *(u128_t *)(v + 0x3C0) = *(u128_t *)&d;
        func_L18_003514B8(o);
    }
    if (*(f32 *)(v + 0x444) <= 0.0f) {
        *(f32 *)(v + 0x444) = 3.0f;
    }
    if (*(s32 *)(v + 0x80) > 0) {
        void *t = func_L01_0043B548(0x19E1, 0x6C);
        *(s32 *)(v + 0x80) = -1;
        v[0x8E] = 1;
        v[0x8F] = 9;
        ((void (*)(void *))(*(void **)t))(o);
    } else {
        func_L01_004450F0(o, 0, 1);
    }
    *(u128_t *)(v + 0x420) = *(u128_t *)(o + 0x10);
    *(u128_t *)(v + 0x2D0) = *(u128_t *)(o + 0xC0);
    *(u128_t *)(v + 0x2E0) = *(u128_t *)(o + 0xD0);
    *(u128_t *)(v + 0x2F0) = *(u128_t *)(o + 0xE0);
}
/* localdecomp:end func_L18_00351548 */

INCLUDE_ASM("asm/levels", func_L18_00351908);
