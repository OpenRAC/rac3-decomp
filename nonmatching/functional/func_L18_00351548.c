/* functional: high. Hand-written from PAL assembly. Object init: the f20 load for level 7 is in a bnez delay slot, so it runs whether or not the byte test passes (written as retail's effective behaviour). Needs -mvu0-use-vf0-vf2 under the file flags. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L18_00351548 */
typedef int u128_00351548 __attribute__((mode(TI)));
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) V_00351548;

extern s32 func_L01_0041A4F0(void);
extern void func_L01_0043A430(u8 *, s32, u8 *);
extern void func_0038D278(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L18_003514B8(u8 *);
extern void (**func_L01_0043B548(s32, s32))(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 D_001D545C;
extern f32 D_001DA8F8_sda;
extern u8 D_0014275B[];
extern f32 D_L18_002F1F30[];
extern u128_00351548 D_L18_001D9A60;
extern s32 D_L18_001D678C;
extern V_00351548 D_L18_001DFD50;
__asm__(".extern D_001D545C, 16");
__asm__(".extern D_001DA8F8_sda, 4");

void func_L18_00351548(u8 *self) {
    u8 *v;
    f32 f;
    f32 g;
    s32 lvl;
    s32 i;
    s32 t;
    V_00351548 tmp;
    void (**fn)(u8 *);

    v = *(u8 **)(self + 0x68);
    (*(u8 **)(self + 0x24))[0x46] = 0xD;
    *(s32 *)(v + 0x350) = 0;
    qzero(v + 0x290);
    *(s32 *)(v + 0x354) = 0;
    qzero(v + 0x2A0);
    qzero(v + 0x2B0);
    qzero(v + 0x3F0);
    f = 1.0f;
    if (func_L01_0041A4F0() != 0) {
        lvl = D_001D545C;
        if (lvl == 7 && D_0014275B[0] != 0) {
            f = D_001DA8F8_sda;
        } else {
            f = D_L18_002F1F30[lvl];
        }
    }
    lvl = D_001D545C;
    if (lvl == 0x12) {
        g = f * 400.0f;
        i = (s32)g;
        *(s16 *)(v + 0x34) = i;
        *(f32 *)(v + 0x30) = (f32)i;
    } else if (lvl == 0x14) {
        *(s16 *)(v + 0x34) = 0x190;
        *(f32 *)(v + 0x30) = 400.0f;
    } else {
        if (lvl == 0x1A) {
            g = f * 300.0f;
        } else if (lvl == 0x1D) {
            g = f * 100.0f;
        } else {
            g = f * 150.0f;
        }
        i = (s32)g;
        *(s16 *)(v + 0x34) = i;
        *(f32 *)(v + 0x30) = (f32)i;
    }
    v[0x38] = 1;
    v[0x58] = 0x1E;
    v[0x3E] = 3;
    v[0x5A] = 0x20;
    *(f32 *)(self + 0x2C) = *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * 0.8f;
    *(f32 *)(v + 0x368) = *(f32 *)(self + 0x18);
    qzero(v + 0x2C0);
    *(f32 *)(v + 0x390) = 0.05235988f;
    *(s32 *)(v + 0x3AC) = -1;
    *(s32 *)(v + 0x3D4) = 8;
    *(s32 *)(v + 0x3D8) = 0x15;
    *(s32 *)(v + 0x3DC) = 5;
    *(s32 *)(v + 0x3E0) = 0x32;
    *(s32 *)(v + 0x388) = 0;
    *(s32 *)(v + 0x38C) = 0;
    *(s32 *)(v + 0x394) = 0;
    *(s32 *)(v + 0x39C) = 0;
    *(s32 *)(v + 0x398) = 0;
    *(s32 *)(v + 0x3A0) = 0;
    *(s32 *)(v + 0x360) = 0;
    *(s32 *)(v + 0x364) = 0;
    *(s32 *)(v + 0x3A4) = 0;
    *(s32 *)(v + 0x3A8) = 0;
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
            func_L01_0043A430(self, i + 4, v + 0x90 + i * 0x40);
        }
        if (v[0x111 + i * 0x40] == 0) {
            func_L01_0043A430(self, i + 2, v + 0x110 + i * 0x40);
        }
        if (v[0x191 + i * 0x40] == 0) {
            func_L01_0043A430(self, i + 9, v + 0x190 + i * 0x40);
        }
    }
    func_0038D278(v + 0x2D0);
    *(u128_00351548 *)(v + 0x3C0) = D_L18_001D9A60;
    t = (D_L18_001D678C == 0);
    *(s32 *)(v + 0x3BC) = t;
    if (t == 0) {
        vec_sub_ab(&tmp, self + 0x10, &D_L18_001DFD50);
        func_0038CF68(&tmp, &tmp, 1.0f);
        *(V_00351548 *)(v + 0x3C0) = tmp;
        func_L18_003514B8(self);
    }
    if (*(f32 *)(v + 0x444) <= 0.0f) {
        *(f32 *)(v + 0x444) = 3.0f;
    }
    if (*(s32 *)(v + 0x80) > 0) {
        fn = func_L01_0043B548(0x19E1, 0x6C);
        v[0x8E] = 1;
        *(s32 *)(v + 0x80) = -1;
        v[0x8F] = 9;
        (*fn)(self);
    } else {
        func_L01_004450F0(self, 0, 1);
    }
    *(u128_00351548 *)(v + 0x420) = *(u128_00351548 *)(self + 0x10);
    *(u128_00351548 *)(v + 0x2D0) = *(u128_00351548 *)(self + 0xC0);
    *(u128_00351548 *)(v + 0x2E0) = *(u128_00351548 *)(self + 0xD0);
    *(u128_00351548 *)(v + 0x2F0) = *(u128_00351548 *)(self + 0xE0);
}
/* localdecomp:end func_L18_00351548 */
