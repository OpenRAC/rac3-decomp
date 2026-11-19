/* functional: high. Same stores, calls and order as retail; only differs in register-save style (retail saves with sq/lq 16-byte slots, this compiles with ld/sd) and scheduling. Draft from nonmatching verified against the PAL asm: args, offsets, constants, callees. */
#include "vu0.h"
typedef struct { u8 bytes[0x460]; } Player_003EE6E8;
extern Player_003EE6E8 D_L20_001E2E80[];
extern s32 D_001D52F0[];
u8 *func_L20_003EE6E8(vu0_q *pos, s32 notify, s32 w20, s32 w24, s32 w28, s32 w2C, s16 h32, s16 h30,
    s16 h18, s16 h1C, s16 h1A, s16 h1E, s16 h16, s16 h3C, s32 w64, void *owner,
    s32 unused0, s32 unused1, s32 unused2, s32 unused3, s32 unused4, s32 unused5,
    s32 w58, s32 w5C, s32 w60, s16 h36, f32 scale, f32 final, f32 f6C, f32 f68) {
    extern u8 *func_003C24B0(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_L01_0044C870(void *, void *, void *, void *);
    extern s32 func_L01_00459590(void *, s32, f32);
    extern f32 func_L01_0040E548(void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038D0C8(f32);
    extern void func_L20_003EF550(void *, void *, void *, f32);
    vu0_v4 delta, axis, zero, sphere, difference;
    u8 *self = func_003C24B0(0x1D46, 0x80);
    u8 *vars;
    u8 *players = (u8 *)D_L20_001E2E80;
    f32 angle;
    if (self) {
        self[0x30] = 255;
        *(s16 *)(self + 0x32) = 255;
        self[0x20] = 0;
        vars = *(u8 **)(self + 0x68);
        *(vu0_q *)(self + 0x10) = *pos;
        *(f32 *)(self + 0x1C) = 1.0f;
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
          : "=m"(delta) : "m"(*(vu0_v4 *)&D_L20_001E2E80[D_001D52F0[0]]), "m"(*(vu0_v4 *)(self+0x10)) : "vf1", "vf2");
        func_0038CF68(&delta, &delta, 1.0f);
        func_003C5180(self + 0x10, &axis, 1);
        *(vu0_q *)(self + 0xC0) = *(vu0_q *)&delta;
        func_0038CE90(self + 0xD0, self + 0xC0, &axis);
        func_0038CF68(self + 0xD0, self + 0xD0, 1.0f);
        func_0038CE90(self + 0xE0, self + 0xD0, self + 0xC0);
        *(f32 *)(self + 0xCC) = 0.0f;
        *(f32 *)(self + 0xEC) = 0.0f;
        *(f32 *)(self + 0xDC) = 0.0f;
        *(s32 *)(vars+0x20)=w20;
        *(s32 *)(vars+0x24)=w24;
        *(s32 *)(vars+0x28)=w28;
        *(s32 *)(vars+0x2C)=w2C;
        *(s16 *)(vars+0x32)=h32;
        *(s16 *)(vars+0x1C)=h1C;
        *(s16 *)(vars+0x12)=50;
        *(f32 *)(vars)=scale*2.0f;
        *(f32 *)(vars+4)=scale*4.0f;
        *(s16 *)(vars+0x30)=h30;
        *(s16 *)(vars+0x1A)=h1A;
        *(s16 *)(vars+0x1E)=h1E;
        *(s16 *)(vars+0x18)=h18;
        *(s16 *)(vars+0x16)=h16;
        *(s16 *)(vars+0x3E)=7;
        *(s16 *)(vars+0x3C)=h3C;
        *(s32 *)(vars+0x54)=223;
        *(s32 *)(vars+0x48)=255;
        *(s32 *)(vars+0x58)=w58;
        *(s32 *)(vars+0x5C)=w5C;
        *(f32 *)(vars+0x6C)=f6C;
        *(f32 *)(vars+0x68)=f68;
        *(f32 *)(vars+0xC)=scale;
        *(s16 *)(vars+0x10)=50;
        *(void **)(vars+0x38)=owner;
        *(s32 *)(vars+0x40)=223;
        *(s32 *)(vars+0x44)=0;
        *(s32 *)(vars+0x4C)=0;
        *(s32 *)(vars+0x50)=223;
        *(s32 *)(vars+0x60)=w60;
        *(s32 *)(vars+0x64)=w64;
        *(s16 *)(vars+0x36)=h36;
        qzero(&zero);
        if (owner) func_L01_0044C870(self, owner, self+0x10, &zero);
        sphere=*(vu0_v4 *)(self+0x10);
        sphere.w=scale*3.0f;
        if (func_L01_00459590(&sphere,0,128.0f)==1) {
            *(s16 *)(vars+0x14)=8;
            *(f32 *)(vars+8)=0.125f;
            if (notify && func_L01_0040E548(pos,&D_L20_001E2E80[D_001D52F0[0]])<2304.0f) {
                *(s32 *)(players+0x28)=33;
                *(f32 *)(players+0x20)=0.075f;
                *(s32 *)(players+0x2C)=0;
            }
            if (*(s16 *)(vars+0x18)) {
                __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                  : "=m"(difference) : "m"(*(vu0_v4 *)(self+0x10)), "m"(*(vu0_v4 *)&D_L20_001E2E80[D_001D52F0[0]]) : "vf1", "vf2");
                func_0038CF68(&difference,&difference,1.0f);
                angle=1.5707963705062866f-func_0038D0C8(func_0038CE68(&difference,D_L20_001E2E80[D_001D52F0[0]].bytes+0x380));
                *(s16 *)(vars+0x18)=0;
                if (angle<0.45378559827804565f) *(s16 *)(vars+0x18)=1;
            }
        } else {
            *(s16 *)(vars+0x18)=0;
            *(s16 *)(vars+0x14)=0;
        }
        func_L20_003EF550(self,&axis,&zero,final);
    }
    return self;
}
