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

extern void fe_func_0038CD28(s32, S_4DBFE8_Ent *, s32);
void func_L01_004E0160(S_4DC790 *);
extern void func_L01_004DD4B0(s32, s32, s32, s32);
extern G_4DD4B0 D_001A4BE0;
/* localdecomp:start func_L01_004DD508 */
extern s32 func_L01_004EAA20(f32);

/* Checks the hero's current weapon-like value (3, 4 or 20): unless blocked, tests with
 * anim_frame_crossed whether two animation frames were crossed and calls func_L01_004DD4B0 for side
 * 0 and side 1. */
void func_L01_004DD508(void) {
    s32 selector;

    if ((*(S_004E1218 *)&D_001A4BE0).f25C4 == 2) {
        if ((*(S_004E1218 *)&D_001A4BE0).f1B8 < 15)
            return;
    }

    selector = (*(S_004E1218 *)&D_001A4BE0).b147F;

    switch ((*(S_004E1218 *)&D_001A4BE0).f25C0[67]) {
    case 3:
        if ((*(S_004E1218 *)&D_001A4BE0).fC0C != 0)
            return;
        if (func_L01_004EAA20(49.5f) != 0)
            func_L01_004DD4B0(selector, 0, 1, 30);
        if (func_L01_004EAA20(17.0f) != 0)
            func_L01_004DD4B0(selector, 1, 1, 30);
        return;
    case 4:
        if ((*(S_004E1218 *)&D_001A4BE0).fC0C != 0)
            return;
        if (func_L01_004EAA20(12.5f) != 0)
            func_L01_004DD4B0(selector, 0, 1, 30);
        if (func_L01_004EAA20(1.0f) != 0)
            func_L01_004DD4B0(selector, 1, 1, 30);
        return;
    case 20:
        if ((*(S_004E1218 *)&D_001A4BE0).fC0C != 0)
            return;
        if (func_L01_004EAA20(8.0f) != 0)
            func_L01_004DD4B0(selector, 0, 1, 30);
        if (func_L01_004EAA20(21.0f) != 0)
            func_L01_004DD4B0(selector, 1, 1, 30);
        return;
    }
}
/* localdecomp:end func_L01_004DD508 */
