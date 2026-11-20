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
extern u8 D_001426E0[];

/* localdecomp:start func_L01_004C0F28 */
extern u8 D_001426E0[];
extern s32 func_L01_004C0ED0(s32 a0);
void func_L01_004C0F28(s32 a0, s32 a1) {
    s32 i = func_L01_004C0ED0(a0);
    if (i >= 0) D_001426E0[i] |= 1 << a1;
}
/* localdecomp:end func_L01_004C0F28 */

/* localdecomp:start func_L01_004C0F78 */
extern s32 func_L01_004C0ED0(s32 a0);
extern u8 D_001426E0[];

s32 func_L01_004C0F78(s32 a, s32 bit) {
    s32 i = ((s32 (*)(s32, s32))func_L01_004C0ED0)(a, bit);
    if (i >= 0) {
        D_001426E0[i] &= 1 << bit;
        return D_001426E0[i] != 0;
    }
    return 0;
}
/* localdecomp:end func_L01_004C0F78 */

/* localdecomp:start func_L01_004C0FD0 */
extern s32 D_L01_001DABD8;

void func_L01_004C0FD0(s32 a) {
    D_L01_001DABD8 = a;
}
/* localdecomp:end func_L01_004C0FD0 */

/* localdecomp:start func_L01_004C0FD8 */
extern void func_L01_005170B8_004C0FD8(int a, int b);

void func_L01_004C0FD8(int *a0, int a1, int a2)
{
    while (a0[0] != 0) {
        if (a0[0] == a1) {
            a0[3] = a2;
            func_L01_005170B8_004C0FD8(a0[0], a2);
            return;
        }
        a0 += 12;
    }
}
/* localdecomp:end func_L01_004C0FD8 */

INCLUDE_ASM("asm/levels", func_L01_004C1028);

/* localdecomp:start func_L01_004C13B0 */

extern s32 func_L01_0040F598(s32, s32);
extern void func_L01_005170B8_004C13B0(s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);

void func_L01_004C13B0(s32 alpha, Ent4BD808 *list) {
    s32 i;

    for (i = 0; list[i].id != 0; i++) {
        if (list[i].kind != 0) {
            func_L01_005170B8_004C13B0(list[i].id, func_L01_0040F598(list[i].color, (alpha << 24) + 0x808080));
        }
        if (list[i].kind == 4) {
            func_L01_00516AA0(list[i].id, 64, alpha > 64);
        }
    }
}
/* localdecomp:end func_L01_004C13B0 */
