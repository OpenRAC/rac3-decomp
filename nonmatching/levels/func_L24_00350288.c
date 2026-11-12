/* func_L24_00350288: 64 differences (level 24, file L24_0034F040.c, -mvu0-use-vf0-vf2 @ps2as). The logic is right (a
   chain of pad-button tests that each call one of the Museum object's action functions, then the +0x1A4 clear and the
   +0x98 copy), but the chain's register use differs: retail keeps the pad pointer in $v1 and copies it to $a0 at the
   second test, re-reading pad[0x1A0] in every branch-likely delay slot; this C holds the value in a register instead.
   3 compiles (s loaded before or after func_L24_0034F828), not converged. */
#include "common.h"
extern void func_L24_0034F828(void *);
extern void func_L24_0034FA98(void *);
extern void func_L24_0034FE28(void *);
extern void func_L24_0034FBE8(void *);
extern void func_L24_00350190(void *);
extern void func_L24_0034E6B0(void *);
extern void func_L01_00404A10(void *, void *);
extern u8 *D_001D52FC;

void func_L24_00350288(u8 *obj) {
    u8 *s;
    u8 *pad;
    s32 t;

    *(s32 *)(obj + 0x98) = 0;
    s = *(u8 **)(obj + 0x68);
    func_L24_0034F828(obj);
    pad = D_001D52FC;
    if ((*(s32 *)(pad + 0x1A0) & 0x28) != 0 && *(s16 *)(s + 0x168) == 0) {
        func_L24_0034FA98(obj);
    } else if ((*(s32 *)(pad + 0x1A0) & 0x42) != 0 && *(s16 *)(s + 0x168) == 0) {
        func_L24_0034FE28(obj);
    } else if ((*(s32 *)(pad + 0x1A8) & 0x81) != 0 && *(s16 *)(s + 0x168) == 0) {
        func_L24_0034FBE8(obj);
    } else if ((*(s32 *)(pad + 0x1A0) & 0x81) != 0 && *(s16 *)(s + 0x168) == 0) {
        func_L24_00350190(obj);
        func_L01_00404A10(func_L24_0034E6B0, obj);
    } else if ((*(s32 *)(pad + 0x1A4) & 4) == 0 || *(s16 *)(s + 0x168) != 0 || !(*(f32 *)(s + 0x148) < -0.6981317f)) {
        s[0x1A4] = 0;
    } else if (*(s32 *)(s + 0x1A0) != 0) {
        t = (*(u8 **)(obj + 0x24))[0x20];
        if (t != 0xFE && t != 0xFD) {
            s[0x1A4] = 0;
        }
    }
    *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
}
