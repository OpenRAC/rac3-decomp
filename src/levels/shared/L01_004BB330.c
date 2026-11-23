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

/* localdecomp:start func_L01_004BB330 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
} T_004BB330;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    u8 b20;
    u8 p21[3];
} E_004BB330;
typedef struct {
    u8 p0[320];
    E_004BB330 e[42];
    u8 p1[1856 - 320 - 42 * 36];
    s32 count;
} B_004BB330;
extern const T_004BB330 D_L01_002BD300[];
extern u32 D_001D54D0;
__asm__(".extern D_001D54D0, 16");
extern B_004BB330 D_L01_002446C0_004BB330;
extern s32 func_L01_00452818(void);
extern s32 func_L01_00435FC8(s32 a0);
extern s32 func_00381FF0(s32);

void func_L01_004BB330(void) {
    s32 v;
    s32 i;

    v = func_L01_00452818();
    D_L01_002446C0_004BB330.count = 0;
    for (i = 0; i < 38; i++) {
        if (v < D_L01_002BD300[i].f14) {
            continue;
        }
        D_L01_002446C0_004BB330.e[D_L01_002446C0_004BB330.count].f4 = D_L01_002BD300[i].f18;
        if (func_L01_00435FC8(D_L01_002BD300[i].f0) != 0) {
            D_L01_002446C0_004BB330.e[D_L01_002446C0_004BB330.count].f4 = 0;
        }
        D_L01_002446C0_004BB330.e[D_L01_002446C0_004BB330.count].f0 = D_L01_002BD300[i].f10;
        D_L01_002446C0_004BB330.e[D_L01_002446C0_004BB330.count].f14 = func_00381FF0(D_L01_002BD300[i].f4);
        D_L01_002446C0_004BB330.e[D_L01_002446C0_004BB330.count].f1C = D_L01_002BD300[i].f1C;
        D_L01_002446C0_004BB330.e[D_L01_002446C0_004BB330.count].f8 = D_L01_002BD300[i].f8;
        D_L01_002446C0_004BB330.e[D_L01_002446C0_004BB330.count].fC = D_L01_002BD300[i].fC;
        D_L01_002446C0_004BB330.e[D_L01_002446C0_004BB330.count].f10 = D_L01_002BD300[i].f0;
        D_L01_002446C0_004BB330.e[D_L01_002446C0_004BB330.count].b20 = (D_L01_002BD300[i].f8 & D_001D54D0) == D_L01_002BD300[i].fC;
        D_L01_002446C0_004BB330.count++;
    }
}
/* localdecomp:end func_L01_004BB330 */

LINKER_REMNANT("asm/levels", func_L01_004BB4D8);

INCLUDE_ASM("asm/levels", func_L01_004BB4E0);
