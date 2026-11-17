#include "common.h"

typedef union { u8 b[0x2A00]; s32 i[0xA80]; f32 f[0xA80]; u8 *ptr[0xA80]; } Hero_003BBEF8;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003BBEF8;
typedef struct { u8 b[0x80]; } E_003BBEF8;

/* localdecomp:start func_L02_003BBEF8 */
extern Hero_003BBEF8 D_1A4BE0;
extern u8 D_1A4C60[];

extern E_003BBEF8 *D_L02_001DEA80;
extern void func_003C2880(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00412E70(void *, V4_003BBEF8 *, f32, u8 *, f32);
extern void func_L01_003E9250(s32, void *, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L02_003BBEF8(u8 *self) {
    s32 *p = *(s32 **)(self + 0x68);
    u8 st = self[0x20];

    if (st == 0) {
        if (p[0] == -1) {
            func_003C2880(self);
            return;
        }
        self[0x30] = 0x20;
        self[0x20] = 1;
    } else if (st == 1) {
        if (p[1] != 0 && D_1A4BE0.i[0x971] != 0x11) {
            p[1] = 0;
            func_L01_00412E70(D_1A4BE0.b + 0x1540, (V4_003BBEF8 *)(D_1A4BE0.b + 0x80), D_1A4BE0.f[0x26], D_1A4BE0.ptr[0x970], 0.0f);
        }
        if (func_00382380(D_1A4C60, p[0], 0) != 0) {
            func_L01_004450F0(self, 2, -1);
        }
    } else if (st == 2) {
        s32 idx = p[0];
        D_1A4BE0.i[0x8E] = 10;
        func_L01_003E9250(0, &D_L02_001DEA80[idx], 0.05235988f, 0.0f);
        if (D_1A4BE0.i[0x971] == 0x11) {
            p[1] = 1;
        } else if (D_1A4BE0.i[0xD8] != 0) {
            p[1] = 0;
        }
        if (func_00382380(D_1A4C60, p[0], 0) == 0) {
            func_L01_004450F0(self, 1, -1);
        }
    }
}
/* localdecomp:end func_L02_003BBEF8 */
