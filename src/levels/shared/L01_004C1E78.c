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
extern s32 D_001426A8[];

/* localdecomp:start func_L01_004C1E78 */
extern s32 D_L01_001E0F60[] __attribute__((section(".sdata")));

s32 func_L01_004C1E78(void) {
    if (D_L01_001E0F60[0] != 1) {
        D_L01_001E0F60[0] = 4;
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_004C1E78 */

/* localdecomp:start func_L01_004C1EA0 */
typedef struct {
    s32 state;
    u8 pad4[8];
    s32 held;
    u8 pad10[0x90];
} Pad_004C1EA0;
typedef struct {
    u8 pad0[8];
    Pad_004C1EA0 pads[2];
    u8 pad148[0x14];
    s32 f15C;
    u8 pad160[4];
    s32 f164;
    s32 f168;
} Pads_004C1EA0;
typedef struct {
    u8 pad0[0x38];
    s32 state;
    u8 pad3C[0x708];
    s32 f744;
    u8 pad748[0x28];
    s32 f770;
    u8 pad774[4];
    s32 f778;
} Menu_004C1EA0;
extern Menu_004C1EA0 D_L01_002446C0_004C1EA0;
extern Pads_004C1EA0 D_00142430_004C1EA0;
extern s32 D_001426A8[];
extern void func_L01_004C21D0(void);
extern s32 func_L01_004C1E78(void);
extern s32 func_L01_004C1D38(s32);
extern void func_L01_004BAA20(s32);
extern void func_L01_004BF660(void);

void func_L01_004C1EA0(void) {
    s32 t;

    if (D_L01_002446C0_004C1EA0.f744 == 0) {
        func_L01_004C21D0();
        return;
    }
    switch (D_L01_002446C0_004C1EA0.state) {
    case 0:
    case 1:
        if (D_L01_002446C0_004C1EA0.f770 != 0) {
            D_L01_002446C0_004C1EA0.state = 6;
            break;
        }
        if (D_00142430_004C1EA0.f15C < 3 && D_00142430_004C1EA0.f164 < 0 &&
            D_00142430_004C1EA0.pads[0].state == 2 && D_00142430_004C1EA0.pads[0].held != 0 &&
            func_L01_004C1E78() != 0) {
            if (D_00142430_004C1EA0.f164 < 0) {
                D_00142430_004C1EA0.f168 = 0;
                D_00142430_004C1EA0.f164 = 24;
            }
            func_L01_004C1D38(0x17F4);
            D_L01_002446C0_004C1EA0.state = D_L01_002446C0_004C1EA0.state == 1 ? 3 : 2;
            break;
        }
        if (D_L01_002446C0_004C1EA0.state == 1) {
            func_L01_004C1D38(0x17FD);
        }
        D_L01_002446C0_004C1EA0.state = 6;
        break;
    case 2:
    case 3:
        if (D_00142430_004C1EA0.f15C < 3 && D_00142430_004C1EA0.f164 < 0 && func_L01_004C1E78() != 0) {
            if (((s32 (*)(void))func_L01_004BF660)() != 0) {
                func_L01_004BAA20(0);
            }
            if (D_L01_002446C0_004C1EA0.state == 3) {
                if (!(D_001426A8[0] & 0x80)) {
                    func_L01_004C1D38(0x17FD);
                } else if (D_L01_002446C0_004C1EA0.f778 == 0) {
                    func_L01_004C1D38(0x1804);
                }
            }
            if (D_L01_002446C0_004C1EA0.f778 == 1) {
                func_L01_004C1D38(0x1803);
            } else if (D_L01_002446C0_004C1EA0.f778 >= 2) {
                func_L01_004C1D38(0x1802);
            }
            D_L01_002446C0_004C1EA0.state = 6;
        }
        break;
    case 4:
        if (D_00142430_004C1EA0.f15C < 3 && D_00142430_004C1EA0.f164 < 0) {
            if (D_00142430_004C1EA0.pads[1].state == 2 && D_00142430_004C1EA0.pads[1].held != 0) {
                D_00142430_004C1EA0.f164 = 24;
                D_00142430_004C1EA0.f168 = 1;
                func_L01_004C1D38(0x1B90);
                D_L01_002446C0_004C1EA0.state = 5;
            } else {
                D_L01_002446C0_004C1EA0.state = 1;
            }
        }
        break;
    case 5:
        if (D_00142430_004C1EA0.f15C < 3 && D_00142430_004C1EA0.f164 < 0 && func_L01_004C1E78() != 0) {
            if (((s32 (*)(void))func_L01_004BF660)() != 0) {
                func_L01_004BAA20(0);
            }
            if (!(D_001426A8[0] & 0x80)) {
                D_L01_002446C0_004C1EA0.state = 1;
            } else {
                t = D_L01_002446C0_004C1EA0.f778;
                if (t == 0) {
                    func_L01_004C1D38(0x1804);
                    D_L01_002446C0_004C1EA0.state = 6;
                } else if (t == 1) {
                    func_L01_004C1D38(0x1803);
                    D_L01_002446C0_004C1EA0.state = 6;
                } else if (t >= 2) {
                    func_L01_004C1D38(0x1802);
                    D_L01_002446C0_004C1EA0.state = 6;
                }
            }
        }
        break;
    case 6:
        break;
    }
}
/* localdecomp:end func_L01_004C1EA0 */
