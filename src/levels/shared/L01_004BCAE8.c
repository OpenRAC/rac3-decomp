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
extern s32 D_L01_001DABD4;
extern u8 D_L01_001DABC8;
extern s32 func_00381FF0(s32);

/* localdecomp:start func_L01_004BCAE8 */
typedef struct {
    s32 id;
    s32 cost;
    s32 idx;
    s32 pad;
} Item_004BCAE8;
typedef struct {
    u8 pad0[40];
    void *f28;
    u8 pad2C[84];
    s32 cur;
    s32 state;
    u8 pad88[184];
    Item_004BCAE8 items[96];
} Shop_004BCAE8;
extern S_00244740 D_L01_002446C0[];
extern s32 D_00142660_004BCAE8[];
extern char *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern s32 D_L01_001E0F90;
__asm__(".extern D_L01_001E0F90, 16");
extern s32 D_L01_001E0F90_004BCAE8;
__asm__(".extern D_L01_001DABD4, 4");
__asm__(".extern D_L01_001DABC8, 1");
__asm__(".extern D_L01_001DABD0, 4");
extern s32 D_L01_001DABD4;
extern u8 D_L01_001DABC8;
extern s32 D_L01_001DABD0;
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_00381FF0(s32);
extern void func_L01_004BC0B8(s32 a0);
extern void func_L01_004BD170(void);
extern void func_L01_004BF980(void);

void func_L01_004BCAE8(u8 *a0, u8 *a1) {
    s32 cost = ((Shop_004BCAE8 *)D_L01_002446C0)->items[((Shop_004BCAE8 *)D_L01_002446C0)->cur].cost;

    if (((Shop_004BCAE8 *)D_L01_002446C0)->state == 1) {
        *a0 = 0;
        if (D_00142660_004BCAE8[0] < cost) {
            func_003A52A0(2, 0x11, ((Shop_004BCAE8 *)D_L01_002446C0)->f28);
            ((Shop_004BCAE8 *)D_L01_002446C0)->state = 0;
        } else {
            func_003A52A0(0, 0x11, ((Shop_004BCAE8 *)D_L01_002446C0)->f28);
            ((Shop_004BCAE8 *)D_L01_002446C0)->state = 2;
        }
    } else if (((Shop_004BCAE8 *)D_L01_002446C0)->state == 2) {
        if ((*(s32 *)(D_001D52FC + 0x1C4) & 0x10) && !(D_L01_001E0F90 & 0x10)) {
            *a0 = 0;
            ((Shop_004BCAE8 *)D_L01_002446C0)->state = 3;
        } else if ((*(s32 *)(D_001D52FC + 0x1C4) & 0x40) && !(D_L01_001E0F90_004BCAE8 & 0x40)) {
            *a0 = 1;
            ((Shop_004BCAE8 *)D_L01_002446C0)->state = 3;
        }
    } else if (((Shop_004BCAE8 *)D_L01_002446C0)->state == 3) {
        if (*a0 != 0) {
            if (D_00142660_004BCAE8[0] >= cost && D_L01_001DABD4 != 4) {
                D_L01_001DABC8 = 1;
                D_L01_001DABD0 = ((Shop_004BCAE8 *)D_L01_002446C0)->items[((Shop_004BCAE8 *)D_L01_002446C0)->cur].idx;
                func_003A52A0(7, 0x11, ((Shop_004BCAE8 *)D_L01_002446C0)->f28);
                D_00142660_004BCAE8[0] -= cost;
                func_L01_004BC0B8(func_00381FF0(0x17A));
                func_003A52A0(7, 0x11, ((Shop_004BCAE8 *)D_L01_002446C0)->f28);
                func_L01_004BD170();
            } else if (D_L01_001DABD4 == 4) {
                func_L01_004BC0B8(func_00381FF0(0x17B));
                func_003A52A0(0, 0x11, ((Shop_004BCAE8 *)D_L01_002446C0)->f28);
            } else if (D_00142660_004BCAE8[0] < cost) {
                func_L01_004BC0B8(func_00381FF0(0x17B));
                func_003A52A0(0, 0x11, ((Shop_004BCAE8 *)D_L01_002446C0)->f28);
            }
        } else {
            func_003A52A0(0, 0x11, ((Shop_004BCAE8 *)D_L01_002446C0)->f28);
        }
        ((Shop_004BCAE8 *)D_L01_002446C0)->state = 0;
        func_L01_004BF980();
    }
}
/* localdecomp:end func_L01_004BCAE8 */

/* localdecomp:start func_L01_004BCD08 */
typedef struct {
    s32 cost;
    s32 id;
    s32 slot;
    s32 pad;
} Item_004BCD08;
typedef struct {
    u8 pad0[40];
    void *f28;
    u8 pad2C[84];
    s32 cur;
    s32 state;
    u8 pad88[188];
    Item_004BCD08 items[96];
} Shop_004BCD08;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Slot_004BCD08;
extern S_00244740 D_L01_002446C0[];
extern Slot_004BCD08 D_L01_002F1C20[];
extern char *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern s32 D_L01_001E0F90;
__asm__(".extern D_L01_001E0F90, 16");
extern s32 D_L01_001E0F90_004BCD08;
extern s16 D_001426A0[];
__asm__(".extern D_L01_001DABC8, 1");
__asm__(".extern D_L01_001DABCC, 4");
__asm__(".extern D_L01_001DABD0, 4");
extern u8 D_L01_001DABC8;
extern s32 D_L01_001DABCC;
extern s32 D_L01_001DABD0;
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_00381FF0(s32);
extern void func_003A2750(s32);
extern s32 func_L01_004526F8(void);
extern s32 func_L01_004526A0(s32);
extern s32 func_L01_005147A8(s32);
extern void func_L01_004C4E60(void);
extern void func_L01_00425978(s32);
extern void func_L01_004BB120_004BCD08(u32 a0);
extern void func_L01_004BC0B8(s32 a0);
extern void func_L01_004BF980(void);

void func_L01_004BCD08(u8 *a0, u8 *a1) {
    s32 slot;
    s32 cost = ((Shop_004BCD08 *)D_L01_002446C0)->items[((Shop_004BCD08 *)D_L01_002446C0)->cur].cost;

    if (((Shop_004BCD08 *)D_L01_002446C0)->state == 1) {
        *a0 = 0;
        if (func_L01_004526F8() < cost) {
            func_003A52A0(2, 0x11, ((Shop_004BCD08 *)D_L01_002446C0)->f28);
            ((Shop_004BCD08 *)D_L01_002446C0)->state = 0;
        } else {
            func_003A52A0(0, 0x11, ((Shop_004BCD08 *)D_L01_002446C0)->f28);
            ((Shop_004BCD08 *)D_L01_002446C0)->state = 2;
        }
    } else if (((Shop_004BCD08 *)D_L01_002446C0)->state == 2) {
        if ((*(s32 *)(D_001D52FC + 0x1C4) & 0x10) && !(D_L01_001E0F90 & 0x10)) {
            *a0 = 0;
            ((Shop_004BCD08 *)D_L01_002446C0)->state = 3;
        } else if ((*(s32 *)(D_001D52FC + 0x1C4) & 0x40) && !(D_L01_001E0F90_004BCD08 & 0x40)) {
            *a0 = 1;
            ((Shop_004BCD08 *)D_L01_002446C0)->state = 3;
        }
    } else if (((Shop_004BCD08 *)D_L01_002446C0)->state == 3) {
        if (*a0 != 0) {
            if (func_L01_004526F8() >= cost) {
                func_L01_005147A8(((Shop_004BCD08 *)D_L01_002446C0)->items[((Shop_004BCD08 *)D_L01_002446C0)->cur].id);
                slot = ((Shop_004BCD08 *)D_L01_002446C0)->items[((Shop_004BCD08 *)D_L01_002446C0)->cur].slot;
                ((Shop_004BCD08 *)D_L01_002446C0)->items[((Shop_004BCD08 *)D_L01_002446C0)->cur].cost = 0;
                D_L01_002F1C20[slot].f8 = 0;
                func_L01_004BB120_004BCD08(((Shop_004BCD08 *)D_L01_002446C0)->items[((Shop_004BCD08 *)D_L01_002446C0)->cur].id);
                D_L01_001DABC8 = 1;
                D_L01_001DABCC = ((Shop_004BCD08 *)D_L01_002446C0)->items[((Shop_004BCD08 *)D_L01_002446C0)->cur].id;
                func_003A52A0(7, 0x11, ((Shop_004BCD08 *)D_L01_002446C0)->f28);
                func_L01_004526A0(cost);
                D_L01_001DABD0 = ((Shop_004BCD08 *)D_L01_002446C0)->items[((Shop_004BCD08 *)D_L01_002446C0)->cur].id;
                func_L01_004C4E60();
                if (D_L01_001DABD0 == -1) {
                    func_L01_005147A8(0);
                    func_L01_00425978(D_001426A0[0]);
                } else {
                    func_L01_005147A8(((Shop_004BCD08 *)D_L01_002446C0)->items[((Shop_004BCD08 *)D_L01_002446C0)->cur].id);
                    func_L01_00425978(D_001426A0[0]);
                }
                func_003A2750(1);
                func_L01_004BC0B8(func_00381FF0(0x17A));
                func_003A52A0(7, 0x11, ((Shop_004BCD08 *)D_L01_002446C0)->f28);
            } else {
                func_L01_004BC0B8(func_00381FF0(0x17B));
                func_003A52A0(0, 0x11, ((Shop_004BCD08 *)D_L01_002446C0)->f28);
            }
        } else {
            func_003A52A0(0, 0x11, ((Shop_004BCD08 *)D_L01_002446C0)->f28);
        }
        ((Shop_004BCD08 *)D_L01_002446C0)->state = 0;
        func_L01_004BF980();
    }
}
/* localdecomp:end func_L01_004BCD08 */

/* localdecomp:start func_L01_004BCFB0 */
typedef struct {
    s32 f0;
    s32 price;
    s32 f8;
    s32 fC;
    s32 id;
    s32 f14;
    s32 f18;
    s32 f1C;
    u8 owned;
    u8 p21[3];
} E_004BCFB0;
typedef struct {
    u8 p0[0x28];
    void *text;
    u8 p2C[0x4C - 0x2C];
    s32 f4C;
    u8 p50[0x80 - 0x50];
    s32 cur;
    s32 state;
    u8 p88[0x140 - 0x88];
    E_004BCFB0 e[42];
    u8 p1[0x740 - 0x140 - 42 * 36];
    s32 count;
    u8 p744[0x76C - 0x744];
    s32 f76C;
} B_004BCFB0;
typedef struct {
    s32 bolts;
    u8 p4[68];
    s32 f72;
} Save_004BCFB0;
extern B_004BCFB0 D_L01_002446C0_004BCFB0;
extern Save_004BCFB0 D_00142660_004BCFB0;
extern char *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern u32 D_001D54D0_004BCFB0;
extern s32 D_L01_001E0F90;
__asm__(".extern D_L01_001E0F90, 16");
extern s32 D_L01_001E0F90_004BCFB0;
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00435FF0(s32);
extern void func_L01_004BB330(void);
extern void func_L01_004BF980(void);

void func_L01_004BCFB0(u8 *a0, u8 *a1) {
    s32 cur = D_L01_002446C0_004BCFB0.cur;
    s32 price = D_L01_002446C0_004BCFB0.e[cur].price;
    s32 bolts;

    if (D_L01_002446C0_004BCFB0.state == 1) {
        *a0 = 0;
        if (D_00142660_004BCFB0.bolts < price || D_L01_002446C0_004BCFB0.e[cur].owned != 0) {
            func_003A52A0(2, 0x11, D_L01_002446C0_004BCFB0.text);
            D_L01_002446C0_004BCFB0.state = 0;
        } else {
            func_003A52A0(0, 0x11, D_L01_002446C0_004BCFB0.text);
            D_L01_002446C0_004BCFB0.state = 2;
        }
    } else if (D_L01_002446C0_004BCFB0.state == 2) {
        if (*(s32 *)(D_001D52FC + 0x1C4) & 0x10) {
            if (!(D_L01_001E0F90 & 0x10)) {
                *a0 = 0;
                D_L01_002446C0_004BCFB0.state = 3;
                return;
            }
        }
        if (*(s32 *)(D_001D52FC + 0x1C4) & 0x40) {
            if (!(D_L01_001E0F90_004BCFB0 & 0x40)) {
                *a0 = 1;
                D_L01_002446C0_004BCFB0.state = 3;
            }
        }
    } else if (D_L01_002446C0_004BCFB0.state == 3) {
        if (*a0 != 0) {
            bolts = D_00142660_004BCFB0.bolts;
            if (bolts >= price) {
                D_L01_002446C0_004BCFB0.f76C = 1;
                D_00142660_004BCFB0.bolts = bolts - price;
                D_001D54D0_004BCFB0 = D_L01_002446C0_004BCFB0.f4C;
                func_L01_00435FF0(D_L01_002446C0_004BCFB0.e[cur].id);
                func_L01_004BB330();
                if (D_L01_002446C0_004BCFB0.count < D_L01_002446C0_004BCFB0.cur) {
                    D_L01_002446C0_004BCFB0.cur = D_L01_002446C0_004BCFB0.count;
                }
                func_003A52A0(7, 0x11, D_L01_002446C0_004BCFB0.text);
            } else {
                func_003A52A0(0, 0x11, D_L01_002446C0_004BCFB0.text);
            }
        } else {
            func_003A52A0(0, 0x11, D_L01_002446C0_004BCFB0.text);
        }
        D_L01_002446C0_004BCFB0.state = 0;
        func_L01_004BF980();
    }
}
/* localdecomp:end func_L01_004BCFB0 */

INCLUDE_ASM("asm/levels", func_L01_004BD170);

/* localdecomp:start func_L01_004BD4A8 */
typedef struct {
    s32 state;
    u8 pad4[8];
    s32 held;
    u8 pad10[0x90];
} Pad_4BD4A8_004BD4A8;
typedef struct {
    u8 pad0[8];
    Pad_4BD4A8_004BD4A8 pads[2];
    u8 pad148[0x14];
    s32 f15C;
    u8 pad160[4];
    s32 f164;
} Pads_4BD4A8_004BD4A8;
typedef struct {
    u8 pad0[0x38];
    s32 f38;
    u8 pad3C[0x14];
    s32 mode;
    u8 pad54[0x2C];
    s32 cur;
    s32 pending;
    u8 pad88[0xB8];
    E_4BBAF0 e[76];
} Menu_4BD4A8_004BD4A8;
extern S_00244740 D_L01_002446C0_004BD4A8[];
extern Pads_4BD4A8_004BD4A8 D_00142430;
extern char *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern u8 D_L01_001E0F30_004BD4A8;
extern u8 D_L01_001E0F31_004BD4A8;
__asm__(".extern D_L01_001E0F30_004BD4A8, 1");
__asm__(".extern D_L01_001E0F31_004BD4A8, 1");
extern void func_L01_004BC0F8_004BD4A8(u8 *, u8 *);
extern void func_L01_004BCAE8_004BD4A8(u8 *, u8 *);
extern void func_L01_004BCD08_004BD4A8(u8 *, u8 *);
extern void func_L01_004BCFB0_004BD4A8(u8 *, u8 *);
extern s32 *func_003B9BD0(s32);
extern void func_003BA4F8(void *, s32);

void func_L01_004BD4A8(void) {
    s32 mode;
    s32 a;
    s32 b;

    if (((Menu_4BD4A8_004BD4A8 *)D_L01_002446C0_004BD4A8)->pending == 0) {
        return;
    }
    mode = ((Menu_4BD4A8_004BD4A8 *)D_L01_002446C0_004BD4A8)->mode;
    if (mode == 0) {
        if (((Menu_4BD4A8_004BD4A8 *)D_L01_002446C0_004BD4A8)->e[((Menu_4BD4A8_004BD4A8 *)D_L01_002446C0_004BD4A8)->cur].b19 == 0) {
            func_L01_004BC0F8_004BD4A8(&D_L01_001E0F30_004BD4A8, &D_L01_001E0F31_004BD4A8);
            return;
        }
        a = 0;
        if (D_00142430.f15C < 3 && D_00142430.f164 < 0 && D_00142430.pads[0].state == 2) {
            a = D_00142430.pads[0].held != 0;
        }
        b = 0;
        if (D_00142430.f15C < 3 && D_00142430.f164 < 0 && D_00142430.pads[1].state == 2) {
            b = D_00142430.pads[1].held != 0;
        }
        if (a | b) {
            ((Menu_4BD4A8_004BD4A8 *)D_L01_002446C0_004BD4A8)->f38 = 4;
        }
        ((Menu_4BD4A8_004BD4A8 *)D_L01_002446C0_004BD4A8)->pending = 0;
    } else if (mode == 2) {
        func_L01_004BCFB0_004BD4A8(&D_L01_001E0F30_004BD4A8, &D_L01_001E0F31_004BD4A8);
    } else if (mode == 3) {
        func_L01_004BCAE8_004BD4A8(&D_L01_001E0F30_004BD4A8, &D_L01_001E0F31_004BD4A8);
    } else if (mode == 5) {
        func_003BA4F8(func_003B9BD0(0), *(s32 *)(D_001D52FC + 0x1C4));
        func_L01_004BCD08_004BD4A8(&D_L01_001E0F30_004BD4A8, &D_L01_001E0F31_004BD4A8);
    }
}
/* localdecomp:end func_L01_004BD4A8 */
