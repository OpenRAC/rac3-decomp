#include "common.h"

typedef struct {
    u8 pad0[6];
    s16 h6;
} S_4DBFE8_Ent;
typedef struct {
    u8 pad0[0x10];
    u8 b10;
    u8 pad11[2];
    u8 b13;
    u8 pad14[8];
    S_4DBFE8_Ent *entries[1];
} S_4DBFE8_Hdr;
typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[0x3F];
    S_4DBFE8_Hdr *hdrs[1];
} S_4DBFE8_Tbl;
typedef struct {
    u8 pad0[0x24];
    S_4DBFE8_Tbl *tbl;
} S_4DBFE8_Obj;
typedef struct { u8 pad[0xB0]; } S_4DC790;
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_4DD4B0;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[8944];
    u128_t q[8];
    s32 i[8];
    f32 a[8];
    f32 b[8];
    s16 count;
} S_4DF808;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[128];
    s128 v128;
    s128 v144;
    u8 pad160[336];
    s16 h496;
    u8 pad498[126];
    f32 f624;
    f32 f628;
    u8 pad632[12];
    f32 f644;
    u8 pad648[9016];
    u8 *obj;
    u8 pad9668[8];
    s32 w9676;
} S_001A4BE0;
typedef struct {
    u8 p0[0x10];
    u128_t q10;
    u8 p20[0x98 - 0x20];
    s32 f98;
    u8 p9C[0xA8 - 0x9C];
    u8 bA8;
    u8 pA9[0xC0 - 0xA9];
    u8 fC0[0x30];
    u128_t qF0;
} Obj_4E09A8;
typedef struct {
    u8 p0[0x80];
    u128_t q80;
    u128_t q90;
    u8 pA0[0x1F0 - 0xA0];
    s16 h1F0;
    u8 p1F2[0x270 - 0x1F2];
    f32 f270;
    f32 f274;
    u8 p278[0x284 - 0x278];
    f32 f284;
    u8 p288[0x25C0 - 0x288];
    Obj_4E09A8 *f25C0;
    s32 f25C4;
    u8 p25C8[0x25E5 - 0x25C8];
    u8 b25E5;
} S_4E09A8;
typedef struct {
    u8 pad0[8800];
    f32 x2260;
    f32 x2264;
} S_004E1168;
typedef unsigned long u64l;
typedef struct {
    u64l a;
    u64l b;
    u64l c;
    u64l d;
} E_4E1758;
typedef struct {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
    u64l x10;
    u64l data[1];
} H_4E1758;
typedef struct { u8 pad[164]; f32 a; f32 b; } S_004E25C8;
typedef struct { u8 pad[340]; f32 a; f32 b; } S_004E25E0;
typedef struct { u8 pad[516]; f32 a; f32 b; } S_004E25F8;
typedef struct { u8 pad[692]; f32 a; f32 b; } S_004E2610;

typedef struct {
    u8 p0[0x1B8];
    s32 f1B8;
    u8 p1BC[0xC0C - 0x1BC];
    s32 fC0C;
    u8 pC10[0x147F - 0xC10];
    u8 b147F;
    u8 p1480[0x25C0 - 0x1480];
    u8 *f25C0;
    s32 f25C4;
} S_004E1218;

typedef struct {
    u8 p0[0x600];
    s32 f600;
    u8 p604[0x650 - 0x604];
    f32 f650;
    u8 p654[0x65C - 0x654];
    s16 h65C;
    u8 p65E[0x25C0 - 0x65E];
    u8 *f25C0;
    s32 f25C4;
} S_4E2E30;

typedef struct {
    u8 pad0[0x80];
    f32 x;
    f32 y;
    u8 pad88[0x10];
    f32 angle;
    u8 pad9C[0x350 - 0x9C];
    f32 z;
    u8 pad354[0x9C8 - 0x354];
    u16 counter;
} G_004E5840;

typedef struct {
    u8 pad0[0x80];
    f32 x;
    f32 y;
    u8 pad88[0x110 - 0x88];
    f32 vx;
    f32 vy;
    u8 pad118[0x350 - 0x118];
    f32 z;
    u8 pad354[0x9C6 - 0x354];
    s16 counter;
    u8 pad9C8[0x2848 - 0x9C8];
    f32 amount;
} Emit_004E5A20;

/* declared by functions of L01_004DF428.c, which this file was cut from */
extern G_4DD4B0 D_001A4BE0;
extern s32 D_L01_001DFB40;
extern f32 func_0038D0B0(f32);

/* localdecomp:start func_L01_004E27A8 */
typedef struct { u8 pad[0x20E]; s16 mode; } Hero_004E27A8;
extern s32 func_0038DBD8(s32, s32, f32);

/* pulses the moby colour: each channel waves by its amplitude around base + amplitude / 2, over a
   period of frames * 5 / 6 (PAL), then fades the moby's colour (0x78) toward it */
void func_L01_004E27A8(u8 *obj, s32 red, s32 green, s32 blue, s32 alpha, s32 wave_r, s32 wave_g,
                       s32 wave_b, s32 frames) {
    s32 period;
    f32 s;
    f32 speed;
    s32 color;

    period = (frames * 5 + 2) / 6;
    s = func_0038D0B0((f32)(D_L01_001DFB40 % period) / (f32)period * 2.0f * 3.14159274f + -3.14159274f);
    blue += (s32)(s * wave_b) + wave_b / 2;
    green += (s32)(s * wave_g) + wave_g / 2;
    red += (s32)(s * wave_r) + wave_r / 2;
    if (blue > 255) blue = 255;
    if (green > 255) green = 255;
    if (red > 255) red = 255;
    color = (alpha << 24) | (blue << 16) | (green << 8) | red;
    speed = 0.07f;
    if ((*(Hero_004E27A8 *)&D_001A4BE0).mode) speed = 0.037f;
    *(s32 *)(obj + 0x78) = func_0038DBD8(*(s32 *)(obj + 0x78), color, speed * 1.2f);
}
/* localdecomp:end func_L01_004E27A8 */
