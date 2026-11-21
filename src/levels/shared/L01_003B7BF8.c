#include "common.h"

typedef struct {
    u8 pad[0x34];
    u16 h34;
    u8 pad36[0x32];
    s32 *w68;
} Moby_003B3CC0;
typedef struct {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x1C - 0x14];
    s32 w1C;
    u8 pad20[0x30 - 0x20];
    s32 w30;
} S_3B4CC0b;
typedef struct {
    u8 pad0[0x68];
    S_3B4CC0b *p68;
} S_3B4CC0;
typedef int u128_3B5048 __attribute__((mode(TI)));
typedef struct { u8 p0[0x10]; s32 w10; u8 p14[0x30]; u16 h44; } C_3B5048;
typedef struct { u8 p0[0x81]; u8 b81; u16 h82; } V_3B5048;
typedef struct {
    u8 p0[0x10]; u128_3B5048 pos; u8 b20; u8 b21; u8 p22[2]; C_3B5048 *w24; u8 p28[8];
    u8 b30; u8 b31; u16 h32; u16 h34; u8 p36[0x32]; V_3B5048 *w68; u8 p6C[0x13]; u8 b7F; u8 p80[0x15]; u8 b95;
    u8 p96[2]; s32 w98; u8 p9C[0x24]; u8 vC0[0x30]; u128_3B5048 vF0;
} M_3B5048;
typedef struct { f32 f0; s16 h4; } A_3B5048;
typedef struct { s16 h0; s16 h2; u8 b4; u8 b5; u8 b6; u8 p7[0x13]; u8 b1A; u8 p1B[0x1D]; s16 h38; } B_3B5048;
typedef struct { u8 p0[8]; void *w8; } E_3B5048;
typedef struct Obj_003B51A0 {
    u8 pad[0x24];
    s32 w24;
    u8 pad28[0x3C];
    void (*fn64)(struct Obj_003B51A0 *);
} Obj_003B51A0;
typedef void (*Fn_003B52B0)(u8 *, s32);

extern void func_L01_004450F0(s32, s32, s32);
extern u8 *D_L01_001E001C;
extern void func_L01_003B3368(u8 *a0);
extern u8 *func_L01_003B3430(u8 *a0);
extern u8 *D_L01_001E0100[];
extern void func_L01_004F50C8(u8 *, u8 *, s32, s32);
extern void func_L01_003EE650(s32);
extern s32 func_L01_003B3548(u8 *);

/* declared by functions of L01_003B2F80.c, which this file was cut from */
extern void func_L01_004450F0(s32, s32, s32);

/* localdecomp:start func_L01_003B7BF8 */
extern void **func_L01_0043B568(s32 a0, s32 a1, s32 a2);
f32 func_L01_003B7BF8(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 104);
    void **v = func_L01_0043B568(*(s32 *)s0, 6, 4);
    s32 x = *(s32 *)(s0 + 284);
    if (x == 0) {
        return 0.0f;
    }
    return ((f32 (*)(s32))*v)(x);
}
/* localdecomp:end func_L01_003B7BF8 */

/* localdecomp:start func_L01_003B7C48 */
extern void func_L01_003B7C98(s32 a0);
void func_L01_003B7C48(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    if (a0[32] == 0) {
        ((void (*)(u8 *a0, u8 *a1))func_L01_003B7C98)(a0, v);
    }
    if (a0[32] == 1) {
        *(u16 *)(a0 + 52) |= 2;
    }
}
/* localdecomp:end func_L01_003B7C48 */

/* localdecomp:start func_L01_003B7C98 */
extern void func_L01_004450F0(s32, s32, s32);
void func_L01_003B7C98(s32 a0) {
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L01_003B7C98 */

INCLUDE_ASM("asm/levels", func_L01_003B7CB8);

LINKER_REMNANT("asm/levels", func_L01_003B8188);
