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

/* localdecomp:start func_L01_003B42E8 */
extern s32 func_00381FF0(s32);
extern void func_0011B2E8();
extern void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_0038FA18(u16 *, long, char *, s32, unsigned long, f32, f32);
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00436020(s32, s32, f32, f32, f32, f32);
extern char D_L01_002A2970[];
typedef struct { u8 p0[4]; s32 w4; u8 p8[0xE8]; } R_003B42E8;
extern R_003B42E8 D_L01_002C5600[];
extern u8 D_L01_001DE6C0[];
extern u8 D_L01_001DE6D8[];
extern u8 D_L01_001DE6F0[];
extern u8 D_L01_001DE708[];
extern u8 D_L01_001DE718[];
extern f32 D_L01_001E11A4;
__asm__(".extern D_L01_001E11A4, 16");
extern s32 D_L01_001E11A0;
__asm__(".extern D_L01_001E11A0, 16");
extern s32 D_001D4BC8;
__asm__(".extern D_001D4BC8, 16");
extern s32 D_L01_001D64E8;
__asm__(".extern D_L01_001D64E8, 16");

static __inline__ s32 scale_003B42E8(f32 v) {
    f32 z0 = 0.0f, z1 = 0.0f;
    return (s32)(v * D_L01_001E11A4 + 0.5f + (D_L01_001E11A0 == 1 ? z0 : z1));
}

void func_L01_003B42E8(s32 id, s32 a1, s32 a2, s32 a3) {
    u32 color = 0x8066CCFF;
    s32 y = 0x100;
    u16 m[16];
    s32 h, w;
    s32 c, b, r;

    if (a1 != 0 || a2 != 0 || a3 != 0) {
        s32 x = func_00381FF0(0x125C);
        if (a1 != 0) {
            if (a3 != 0) {
                if (a2 != 0) {
                    c = func_00381FF0(0x282);
                    b = func_00381FF0(0x12B4);
                    r = func_00381FF0(((R_003B42E8 *)(a2 * 0xF0 + (u8 *)D_L01_002C5600))->w4);
                    func_0011B2E8(D_L01_002A2970, D_L01_001DE6C0, func_00381FF0(id), b, x, r, x, a1, c);
                } else {
                    c = func_00381FF0(0x282);
                    b = func_00381FF0(0x12B4);
                    func_0011B2E8(D_L01_002A2970, D_L01_001DE6D8, func_00381FF0(id), b, x, a1, c);
                }
            } else {
                if (a2 != 0) {
                    c = func_00381FF0(0x282);
                    r = func_00381FF0(((R_003B42E8 *)(a2 * 0xF0 + (u8 *)D_L01_002C5600))->w4);
                    func_0011B2E8(D_L01_002A2970, D_L01_001DE6F0, func_00381FF0(id), x, r, x, a1, c);
                } else {
                    c = func_00381FF0(0x282);
                    func_0011B2E8(D_L01_002A2970, D_L01_001DE708, func_00381FF0(id), x, a1, c);
                }
            }
        }
    } else {
        func_0011B2E8(D_L01_002A2970, D_L01_001DE718, func_00381FF0(id));
    }
    func_003910C0((s16 *)m, scale_003B42E8((f32)y), scale_003B42E8(384.0f), D_001D4BC8 - 0x90, D_001D4BC8 + 0x90, D_001D4BC8, 0x140, 0x10, 0x27);
    m[12] = 2;
    m[13] = 2;
    func_0038FA18(m, color, D_L01_002A2970, -1, 0x80000000UL, 1.0f, 1.0f);
    w = (s16)m[6] / 2 + 8;
    h = (s16)m[7] / 2 + 8;
    func_0038C3B0((s16)m[5] - h, (s16)m[5] + h, (s16)m[4] - w, (s16)m[4] + w, 0x33, 0x331465B7);
    func_L01_00436020(0x60, 0x332299DE, (s16)m[5] - h, (s16)m[5] + h, (s16)m[4] - w, (s16)m[4] + w);
    m[9] &= 0xFFFB;
    func_0038FA18(m, color, D_L01_002A2970, -1, 0x80000000UL, 1.0f, 1.0f);
    D_L01_001D64E8 = 1;
}
/* localdecomp:end func_L01_003B42E8 */
