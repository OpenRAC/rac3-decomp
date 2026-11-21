#include "common.h"

typedef struct {
    void (*f0)(u8 *);
    void (*f4)(u8 *);
} Vt003D1AA8;
typedef struct {
    s32 a;
    f32 b;
    s32 c;
    f32 d;
} Src_3D1EB8;

typedef struct {
    u8 pad0[0x19E0];
    u8 *f19E0;
    u8 pad19E4[0x25C0 - 0x19E4];
    s32 f25C0;
} G_003D1BE8;
typedef struct {
    u8 pad0[0x140];
    s32 f140;
    u8 pad144[0x160 - 0x144];
    u8 f160[0x1C8 - 0x160];
    f32 f1C8;
    u8 pad1CC[0x1E0 - 0x1CC];
    u8 f1E0[0x240 - 0x1E0];
    f32 f240;
    u8 pad244[0x274 - 0x244];
    f32 f274;
    f32 f278;
} P_003D1BE8;

/* declared by functions of L12_003D2E60.c, which this file was cut from */
extern f32 D_L12_001DEF10;
extern void func_L12_003D3978(u8 *, u8 *);
extern void func_L12_003D3A80(u8 *, u8 *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_L01_0040E570(void *, void *);

INCLUDE_ASM("asm/levels", func_L12_003D3978);

INCLUDE_ASM("asm/levels", func_L12_003D3A80);
