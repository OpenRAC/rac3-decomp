#include "common.h"

/* localdecomp:start func_L07_003B9A90 */
typedef struct {
    u8 pad0[0x24];
    f32 f24;
} S_003B9A90_B;

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    s16 f20;
    s16 f22;
    u8 f24;
    u8 pad25[3];
} S_003B9A90_P;

typedef struct {
    u8 pad0[0x23];
    u8 f23;
    S_003B9A90_B *f24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[0x38];
    S_003B9A90_P *f68;
    u8 pad6C[0x74];
} S_003B9A90;

extern s32 func_0038CB00(void *);
extern void func_003C2880(s32);
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0044E820(void *, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_0038CF68(s32, s32, f32);

void func_L07_003B9A90(S_003B9A90 *arg0) {
    S_003B9A90_P *p = arg0->f68;
    if (func_0038CB00(&p->f20) != 0) {
        func_003C2880((s32)arg0);
        return;
    }
    if ((p->f24 & 7) != 7) {
        f32 a = 1.0f - (f32)p->f20 * p->f18;
        f32 t = (1.0f - func_0038D098(a * 3.1415927f)) * 0.5f;
        f32 u;
        if ((p->f24 ^ 1) & 1) {
            func_L01_0044E820(arg0, func_0038DBD8(p->f10, p->f14, t));
        }
        if (!(p->f24 & 2)) {
            u = func_003C4088(p->f0, p->f4, a);
            arg0->f2C = arg0->f24->f24 * u;
        } else {
            u = p->f0;
        }
        if (!(p->f24 & 4)) {
            f32 r = func_003C4088(p->f8, p->fC, t) / u;
            func_0038CF68((s32)arg0 + 0xE0, (s32)arg0 + 0xE0, r);
        }
    }
    if (p->f20 < p->f22) {
        arg0->f23 = (u8)(s32)(p->f1C * (f32)p->f20 * 128.0f);
    }
}
/* localdecomp:end func_L07_003B9A90 */

INCLUDE_ASM("asm/levels", func_L07_003B9C28);

INCLUDE_ASM("asm/levels", func_L07_003B9DF8);

INCLUDE_ASM("asm/levels", func_L07_003BA000);

/* localdecomp:start func_L07_003BA098 */
typedef int Q_003BA098 __attribute__((mode(TI)));
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern void func_L01_004450F0(u8 *, s32, s32);
void func_L07_003BA098(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    if (*(s32 *)(p + 0x70) != -1) {
        *(Q_003BA098 *)(arg0 + 0x10) = *(Q_003BA098 *)(p + 0x80);
        *(Q_003BA098 *)(p + 0x80) = *(Q_003BA098 *)D_L07_001D66B0;
        *(s32 *)(p + 0x70) = -1;
        func_L01_004450F0(arg0, 0, -1);
    }
}
/* localdecomp:end func_L07_003BA098 */

INCLUDE_ASM("asm/levels", func_L07_003BA0E8);

INCLUDE_ASM("asm/levels", func_L07_003BA500);

INCLUDE_ASM("asm/levels", func_L07_003BA970);
