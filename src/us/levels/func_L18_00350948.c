#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L18_00351548 (src/levels/shared/L18_00351548.c): 60 Hz values (25, 60, pi/72 turn rate) */
/* localdecomp:start func_L18_00350948 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_00388830(void *, void *, f32);

typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) V_00350948;
extern s32 func_L01_00417EA0(void);
extern void func_L01_00437350(void *, s32, void *);
extern void func_00388B40(void *);
extern void *func_L01_00438468(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L18_003508B8(u8 *);
extern s32 D_001D545C;
extern s32 D_001D545C_00350948;
__asm__(".extern D_001D545C_00350948, 16");
extern u8 D_0014275B[];
extern f32 D_L18_001DA938;
extern f32 D_L18_002F1F70[];
extern u128_t D_L18_001D9AA0 __attribute__((section(".sdata")));
extern s32 D_L18_001D678C;
extern V_00350948 D_L18_001DFDD0 __attribute__((section(".sdata")));

void func_L18_00350948(void *arg) {
    u8 *o = arg;
    u8 *v = *(u8 **)(o + 0x68);
    f32 scale;
    s32 level;
    s32 id;
    s32 i;
    V_00350948 d;

    scale = 1.0f;
    (*(u8 **)(o + 0x24))[0x46] = 13;
    *(s32 *)(v + 0x350) = 0;
    qzero(v + 0x290);
    *(s32 *)(v + 0x354) = 0;
    qzero(v + 0x2A0);
    qzero(v + 0x2B0);
    qzero(v + 0x3F0);
    if (func_L01_00417EA0() != 0) {
        level = D_001D545C;
        scale = level == 7 && D_0014275B[0] ? D_L18_001DA938 : D_L18_002F1F70[level];
    }
    id = D_001D545C_00350948;
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
    *(f32 *)(v + 0x390) = 0.043633234f;
    *(s32 *)(v + 0x3AC) = -1;
    *(s32 *)(v + 0x3D4) = 8;
    *(s32 *)(v + 0x3D8) = 25;
    *(s32 *)(v + 0x3DC) = 5;
    *(s32 *)(v + 0x3E0) = 60;
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
            func_L01_00437350(o, i + 4, v + 0x90 + i * 0x40);
        }
        if (v[0x111 + i * 0x40] == 0) {
            func_L01_00437350(o, i + 2, v + 0x110 + i * 0x40);
        }
        if (v[0x191 + i * 0x40] == 0) {
            func_L01_00437350(o, i + 9, v + 0x190 + i * 0x40);
        }
    }
    func_00388B40(v + 0x2D0);
    *(u128_t *)(v + 0x3C0) = D_L18_001D9AA0;
    *(s32 *)(v + 0x3BC) = D_L18_001D678C == 0;
    if (*(s32 *)(v + 0x3BC) == 0) {
        vec_sub_ab(&d, o + 0x10, &D_L18_001DFDD0);
        func_00388830(&d, &d, 1.0f);
        *(u128_t *)(v + 0x3C0) = *(u128_t *)&d;
        func_L18_003508B8(o);
    }
    if (*(f32 *)(v + 0x444) <= 0.0f) {
        *(f32 *)(v + 0x444) = 3.0f;
    }
    if (*(s32 *)(v + 0x80) > 0) {
        void *t = func_L01_00438468(0x19E1, 0x6C);
        *(s32 *)(v + 0x80) = -1;
        v[0x8E] = 1;
        v[0x8F] = 9;
        ((void (*)(void *))(*(void **)t))(o);
    } else {
        func_L01_00441FB8(o, 0, 1);
    }
    *(u128_t *)(v + 0x420) = *(u128_t *)(o + 0x10);
    *(u128_t *)(v + 0x2D0) = *(u128_t *)(o + 0xC0);
    *(u128_t *)(v + 0x2E0) = *(u128_t *)(o + 0xD0);
    *(u128_t *)(v + 0x2F0) = *(u128_t *)(o + 0xE0);
}
/* localdecomp:end func_L18_00350948 */
