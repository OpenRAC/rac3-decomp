#include "common.h"

/* NTSC-U counterpart of func_L30_004E6ED8 (src/levels/shared/L30_004E6AD0.c) */
typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;
extern S_004E6988 D_001A4BE0;
extern void func_L01_0050BB98(s32, s32, f32);
extern s32 func_L01_004F1068(s32, s32);

/* localdecomp:start func_L30_004E2FD8 */
typedef int Q_004E6ED8 __attribute__((mode(TI)));

typedef struct V_004E6ED8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_004E6ED8;

typedef struct S_004E6ED8 {
    u8 pad0[0xC08];
    s32 xC08;
    s32 xC0C;
    u8 pad1[0xC18 - 0xC10];
    f32 xC18;
    u8 pad2[0x1AE4 - 0xC1C];
    f32 x1AE4;
    u8 pad3[0x1B3C - 0x1AE8];
    s16 x1B3C;
    u8 pad4[0x25C0 - 0x1B3E];
    u8 *x25C0;
    u8 pad5[0x25CC - 0x25C4];
    s32 x25CC;
} S_004E6ED8;

extern f32 D_L30_001DC014;
__asm__(".extern D_L30_001DC014, 4");
extern void func_003886E8(void *, void *, f32);
extern s32 func_L01_004EAA20(f32);
extern s32 func_L01_004F1068(s32, s32);
extern void func_L30_0034BC88(void *, void *, s32, s32, s32, s32, f32, f32);
extern s32 func_L30_004E2EC8(s32);

void func_L30_004E2FD8(void) {
    V_004E6ED8 v;

    if (((S_004E6ED8 *)&D_001A4BE0)->x1B3C == 0) {
        return;
    }
    *(Q_004E6ED8 *)&v = 0;
    v.x = 1.0f;
    v.w = 1.0f;
    if (*(u16 *)(((S_004E6ED8 *)&D_001A4BE0)->x25C0 + 0x34) & 0x8000) {
        func_003886E8(&v, &v, -1.0f);
    }
    if (func_L01_004EAA20(D_L30_001DC014) != 0) {
        func_L01_004F1068(7, 0);
    }
    if (((S_004E6ED8 *)&D_001A4BE0)->xC0C == 0 && 11.0f < ((S_004E6ED8 *)&D_001A4BE0)->xC18
        && ((S_004E6ED8 *)&D_001A4BE0)->xC18 < 19.0f) {
        func_L30_0034BC88(((S_004E6ED8 *)&D_001A4BE0)->x25C0, &v, 0, 0, 0, 0, ((S_004E6ED8 *)&D_001A4BE0)->x1AE4, 0.75f);
    }
    if (((S_004E6ED8 *)&D_001A4BE0)->x25CC == 2 && ((S_004E6ED8 *)&D_001A4BE0)->x25C0[0x43] == 0x3A
        && 27.5f <= ((S_004E6ED8 *)&D_001A4BE0)->xC18 && ((S_004E6ED8 *)&D_001A4BE0)->xC0C == 0) {
        func_L01_0050BB98(0x2D, 0, 7.0f);
    }
    if (((S_004E6ED8 *)&D_001A4BE0)->x25CC == 0 && ((S_004E6ED8 *)&D_001A4BE0)->x25C0[0x43] == 0x3A
        && (((S_004E6ED8 *)&D_001A4BE0)->xC08 & 2)) {
        func_L01_0050BB98(func_L30_004E2EC8(1), 0, 5.0f);
    }
    if (((S_004E6ED8 *)&D_001A4BE0)->x25C0[0x43] != 0x3A) {
        ((S_004E6ED8 *)&D_001A4BE0)->x1B3C = 0;
    }
}
/* localdecomp:end func_L30_004E2FD8 */
