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

/* localdecomp:start func_L01_004BAE90 */
extern u8 D_001426E0[];
extern void func_0039EF28(void);
void func_L01_004BAE90(u32 a0) {
    if (a0 >= 8) {
        a0 -= 8;
        if (a0 < 8) {
            D_001426E0[200] |= 1 << a0;
        }
        func_0039EF28();
    } else {
        D_001426E0[62] |= 1 << a0;
        func_0039EF28();
    }
}
/* localdecomp:end func_L01_004BAE90 */

/* localdecomp:start func_L01_004BAF08 */
extern u8 D_0014271E[];
extern u8 D_001427A8[];
s32 func_L01_004BAF08(u32 i) {
    if (i >= 8) {
        i -= 8;
        if (i < 8) {
            return (D_001427A8[0] >> i) & 1;
        }
        return 0;
    }
    return (D_0014271E[0] >> i) & 1;
}
/* localdecomp:end func_L01_004BAF08 */

/* localdecomp:start func_L01_004BAF50 */
extern u8 D_00142CC1[];
extern u8 D_00142700[];
extern u8 D_001D5570[] __attribute__((section(".sdata")));
extern void func_L01_004BAE90(u32 a0);
void func_L01_004BAF50(void) {
    func_L01_004BAE90(1);
    if (D_00142CC1[0] != 0) {
        func_L01_004BAE90(2);
    }
    if (D_00142700[0] != 0) {
        func_L01_004BAE90(3);
    }
    if (D_001D5570[6] != 0) {
        func_L01_004BAE90(4);
    }
}
/* localdecomp:end func_L01_004BAF50 */

/* localdecomp:start func_L01_004BAFB8 */
extern s32 func_L01_004BAF08(u32 i);
extern S_00244740 D_L01_002446C0[];



extern s32 D_L01_001DABD4;
extern u8 D_L01_001DABC8;
extern Tbl_004B7420 D_L01_001DAC78;
extern s32 func_L01_0041A4F0(void);

void func_L01_004BAFB8(void) {
    Tbl_004B7420 tbl;
    s32 i;

    (*(List_004B7420 *)&D_L01_002446C0).count = 0;
    i = 1;
    if (D_L01_001DABD4 != 0) {
        i = D_L01_001DABD4 + 1;
    }
    D_L01_001DABC8 = 0;
    tbl = D_L01_001DAC78;
    for (; i < 5; i++) {
        if (((s32 (*)(s32))func_L01_004BAF08)(i) != 0 || func_L01_0041A4F0() != 0) {
            (*(List_004B7420 *)&D_L01_002446C0).items[(*(List_004B7420 *)&D_L01_002446C0).count].idx = i;
            (*(List_004B7420 *)&D_L01_002446C0).items[(*(List_004B7420 *)&D_L01_002446C0).count].val = tbl.v[i];
            (*(List_004B7420 *)&D_L01_002446C0).items[(*(List_004B7420 *)&D_L01_002446C0).count].id = i + 0xEA92;
            (*(List_004B7420 *)&D_L01_002446C0).count++;
        }
    }
}
/* localdecomp:end func_L01_004BAFB8 */

/* localdecomp:start func_L01_004BB0F0 */
extern s32 func_L01_004BAF08(u32 i);
s32 func_L01_004BB0F0(s32 a0) {
    if (a0 == -1) {
        return 1;
    }
    return ((s32 (*)(s32))func_L01_004BAF08)(a0);
}
/* localdecomp:end func_L01_004BB0F0 */

/* localdecomp:start func_L01_004BB120 */
extern void func_L01_004BAE90_004BB120(u32 a0);
void func_L01_004BB120(u32 a0) {
    func_L01_004BAE90_004BB120(a0);
}
/* localdecomp:end func_L01_004BB120 */
