#include "common.h"

/* NTSC-U counterpart of func_L40_003F1388 (src/levels/shared/L40_003F1388.c): 0.0004 -> 0.000277778; 0.02 -> 0.0166667; 0.00392 -> 0.00272222; 0.04 -> 0.0333333; 0.0100531 -> 0.00698132; 0.251327 -> 0.20944 */
typedef int u128_3F1460 __attribute__((mode(TI)));

/* localdecomp:start func_L40_003F0EE0 */
extern f32 D_L40_00246F70;
extern f32 D_L40_00246F74;
__asm__(".extern D_L40_00246F70, 4");
__asm__(".extern D_L40_00246F74, 4");
extern s32 func_L01_0044B550(void *);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L40_003F11B8(u8 *, s32);

typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 f34;
    u8 pad36[0x8];
    u8 f3E;
    u8 pad3F[0x1];
    f32 f40;
    u8 pad44[0x2C];
    f32 f70;
    f32 f74;
    f32 f78;
    f32 f7C;
    f32 f80;
    u8 pad84[0x18];
    f32 f9C;
    f32 fA0;
    f32 fA4;
    u8 padA8[0x4];
    s32 fAC;
    u8 padB0[0xB7];
    u8 f167;
    u8 f168;
    u8 f169;
    u8 pad16A[0x2];
    s16 f16C;
    s16 f16E;
    u8 f170;
    u8 pad171[0x1F];
    f32 f190;
    f32 f194;
    u8 pad198[0x4];
    f32 f19C;
    u8 pad1A0[0x8];
    u8 f1A8;
    u8 pad1A9[0x2E];
    u8 f1D7;
    u8 pad1D8[0x4];
    s32 f1DC;
    u8 pad1E0[0x98];
    f32 f278;
    u8 pad27C[0x8];
    s32 f284;
    s32 f288;
    u8 pad28C[0x8];
    s32 f294;
    s32 f298;
    u8 pad29C[0xC4];
    u128_3F1460 f360;
} V_003F1388;

s32 func_L40_003F0EE0(u8 *o) {
    V_003F1388 *v = *(V_003F1388 **)(o + 0x68);

    v->f360 = *(u128_3F1460 *)(o + 0x10);
    v->f294 = 0;
    v->f298 = func_L01_0044B550(o);
    v->f170 = 0x1C;
    v->f1A8 = 3;
    v->f190 = 0.5f;
    v->f194 = 0.5f;
    v->f19C = 0.15f;
    v->f1D7 = 1;
    v->f1DC = -1;
    if (v->f34 == 0) {
        v->f34 = 5;
        v->f30 = 5.0f;
    }
    v->f3E = 1;
    v->f40 = 0.2f;
    v->f278 = *(f32 *)(o + 0xF8);
    v->f167 = 0x80;
    v->f168 = 0;
    v->f169 = 0;
    v->f70 = 0.6f;
    v->f74 = 0.3f;
    v->f78 = 1.0f;
    v->f7C = 1.0f;
    v->f80 = 1.3962634f;
    v->fA0 = 0.34906584f;
    v->f9C = 0.00272222236f;
    v->fA4 = 0.0333333351f;
    v->fAC = -1;
    v->f16C = 4;
    v->f16E = 0xF;
    func_L01_00458A70(o, D_L40_00246F70 * 0.000277777785f, D_L40_00246F74 * 0.0166666675f, 0.00698131742f, 0.209439531f);
    o[0x30] = 0xFF;
    *(s16 *)(o + 0x32) = 0xFF;
    v->f288 = 0;
    v->f284 = 0x10001;
    func_L01_00441FB8(o, 1, 0);
    ((void (*)(u8 *, s32, s32, s32))func_L40_003F11B8)(o, 0, 0, 0);
    return 0;
}
/* localdecomp:end func_L40_003F0EE0 */
