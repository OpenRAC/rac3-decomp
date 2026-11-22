#include "common.h"

typedef struct {
    s32 id;
    u8 pad4[12];
    u8 b16;
    u8 b17;
    u8 pad18[2];
} Slot_004B6C98;
typedef struct {
    u8 pad0[128];
    s32 cur;
    u8 pad84[188];
    Slot_004B6C98 slots[79];
    u8 pad76C[16];
    s32 unk77C;
} S_00244740;
typedef struct {
    u8 pad0[124];
    s32 value;
    u8 pad80[112];
} S_002C5640;
typedef struct {
    u8 pad0[124];
    s32 value;
    u8 pad80[112];
} Info_004B6C98;
typedef struct {
    u8 active;
    u8 pad[0xEF];
} Ent4B6DF8;
typedef struct {
    s32 id;
    s32 val;
    s32 idx;
    s32 pad;
} Item_004B7420;
typedef struct {
    u8 pad0[320];
    Item_004B7420 items[96];
    s32 count;
} List_004B7420;
typedef struct {
    s32 v[5];
} Tbl_004B7420;
typedef struct { u8 p0[72]; s32 f72; } A_4BBAF0;
typedef struct {
    s32 type;
    u8 b4;
    u8 p5[11];
    u8 b16;
    u8 p17[2];
    u8 b19;
} E_4BBAF0;
typedef struct {
    u8 p0[320];
    E_4BBAF0 e[76];
    u8 p1[1856 - 320 - 76 * 20];
    s32 count;
    u8 p2[44];
    s32 f1904;
    u8 p3[4];
    s32 f1912;
} B_4BBAF0;
typedef struct {
    char pad[1916];
    s32 v;
} Unk244740;
typedef struct {
    s32 id;
    s32 f4;
    s32 kind;
    s32 color;
    u8 pad[32];
} Ent4BD808;

/* declared by functions of L01_004BA278.c, which this file was cut from */
extern S_00244740 D_L01_002446C0[];
extern void func_0011B2E8(s32, u8 *, s32);

/* localdecomp:start func_L01_004BEA70 */
typedef struct {
    u8 p0[0x3C];
    s32 f3C;
    u8 p40[0x10];
    s32 f50;
    u8 p54[0x10];
    s32 f64;
    u8 p68[0x6DC];
    s32 f744;
} G_004BEA70;
extern G_004BEA70 D_L01_002446C0_004BEA70;
extern f32 D_L01_001E0FD0;
extern s32 D_00143950_004BEA70 __attribute__((section(".data")));
extern s32 D_L01_001DAD60;
extern s32 D_L01_001DAD68[2];
extern void func_003A9500(s32, s32, s32, s32);
extern s32 func_0011B868(char *);
extern s32 func_00382468(s32);
extern s32 func_00381FF0(s32);
extern void func_L01_004BC0B8(s32);
/* the colour word is a 64-bit argument: as a `long` its constant stays one `li` for the scheduler */
extern void func_L01_004BE6B8(long, s32, s32, f32, f32, f32);
__asm__(".extern D_L01_001DAD60, 4");
__asm__(".extern D_L01_001DAD68, 8");

void func_L01_004BEA70(void) {
    f32 scale;
    s32 n;
    s32 r;
    s32 x;
    f32 neg;
    f32 fx;

    if (D_L01_002446C0_004BEA70.f50 == 2) {
        n = 0x14;
        scale = 1.0f;
        func_003A9500(0x4B, 0x163, (s32)(D_L01_001E0FD0 * 19.0f + 0.5f), (s32)(D_L01_001E0FD0 * 36.0f + 0.5f));
    } else {
        n = 0x3C;
        scale = 1.5f;
        func_003A9500(0x50, 0x1B0, (s32)(D_L01_001E0FD0 * 56.0f + 0.5f), (s32)(D_L01_001E0FD0 * 100.0f + 0.5f));
    }
    if (func_0011B868((char *)D_L01_002446C0_004BEA70.f3C) - D_L01_002446C0_004BEA70.f64 / 20 > 0) {
        D_L01_002446C0_004BEA70.f64 += 2;
    } else if (D_L01_002446C0_004BEA70.f744 == 0 && D_L01_002446C0_004BEA70.f50 != 2) {
        r = func_00382468(12);
        if (r >= 6) {
            func_L01_004BC0B8(func_00381FF0(D_L01_001DAD60));
        } else {
            func_L01_004BC0B8(func_00381FF0(D_L01_001DAD68[r]));
        }
    }
    neg = (f32)-D_L01_002446C0_004BEA70.f64;
    x = (s32)((f32)n * D_L01_001E0FD0 + 0.5f);
    if (D_00143950_004BEA70 != 0) {
        fx = (f32)(x - 2);
    } else {
        fx = (f32)x;
    }
    func_L01_004BE6B8(0xF0C070, D_L01_002446C0_004BEA70.f3C, -1, neg, fx, scale);
}
/* localdecomp:end func_L01_004BEA70 */
