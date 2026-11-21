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

/* localdecomp:start func_L01_004C17E8 */
typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    u8 pad18[8];
    s32 f20;
    f32 g;
    s32 state;
    u8 pad2C[4];
    f32 x;
    f32 y;
    s32 f38;
    s32 f3C;
} S_004C17E8;
extern S_004C17E8 D_L01_001E0F38 __attribute__((section(".sdata")));

void func_L01_004C17E8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g) {
    D_L01_001E0F38.a = a;
    D_L01_001E0F38.c = c;
    D_L01_001E0F38.d = d;
    D_L01_001E0F38.e = e;
    D_L01_001E0F38.f = f;
    D_L01_001E0F38.b = b;
    D_L01_001E0F38.g = g;
    D_L01_001E0F38.state = 1;
}
/* localdecomp:end func_L01_004C17E8 */

INCLUDE_ASM("asm/levels", func_L01_004C1838);

/* localdecomp:start func_L01_004C1CE0 */
typedef struct {
    s32 id;
    u8 pad4[4];
    s32 state;
    u8 padC[4];
    f32 x;
    f32 y;
    s32 a;
    s32 b;
} S_004C1CE0;
extern S_004C1CE0 D_L01_001E0F58 __attribute__((section(".sdata")));

s32 func_L01_004C1CE0(s32 id, f32 x, f32 y, s32 a, s32 b) {
    if (D_L01_001E0F58.state == 1) {
        D_L01_001E0F58.id = id;
        D_L01_001E0F58.x = x;
        D_L01_001E0F58.y = y;
        D_L01_001E0F58.state = 2;
        D_L01_001E0F58.a = a;
        D_L01_001E0F58.b = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_004C1CE0 */
