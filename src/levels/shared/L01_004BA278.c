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

INCLUDE_ASM("asm/levels", func_L01_004BA278);

INCLUDE_ASM("asm/levels", func_L01_004BA7B8);

/* localdecomp:start func_L01_004BA800 */
extern s32 D_L01_001D6690;
extern s32 D_L01_001D6694;
__asm__(".extern D_L01_001D6690, 16");
__asm__(".extern D_L01_001D6694, 16");

s32 func_L01_004BA800(void) {
    s32 r;

    r = 0;
    if (D_L01_001D6690 == 2 || D_L01_001D6694 == 2) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_004BA800 */

/* localdecomp:start func_L01_004BA830 */




extern S_00244740 D_L01_002446C0[];
extern u8 D_001425C0[];
extern S_002C5640 D_L01_002C5600[];
extern s32 func_L01_00419E60(Info_004B6C98 *, s32, s32);

s32 func_L01_004BA830(void) {
    Info_004B6C98 info;
    s32 val = 0;
    s32 cur = D_L01_002446C0[0].cur;

    if (D_L01_002446C0[0].slots[cur].b17 != 0) {
        val = 0;
        if (func_L01_00419E60(&info, D_L01_002446C0[0].slots[cur].id, 5) != 0) {
            val = info.value;
        }
    } else if (D_L01_002446C0[0].slots[cur].b16 == 0) {
        val = (D_001425C0[D_L01_002446C0[0].slots[cur].id])[D_L01_002C5600].value;
    }
    if (D_L01_002446C0[0].unk77C != 0) {
        val = val * 9 / 10;
    }
    return val;
}
/* localdecomp:end func_L01_004BA830 */

/* localdecomp:start func_L01_004BA8F8 */
typedef struct {
    s32 id;
    u8 b4;
    u8 p5[3];
    s32 f8;
    s32 f12;
    u8 b16;
    u8 b17;
    u8 b18;
    u8 b19;
} E_004BA8F8;
typedef struct {
    u8 pad0[320];
    E_004BA8F8 e[76];
} T_004BA8F8;

void func_L01_004BA8F8(s32 i, s32 id, u8 b4, u8 b17) {
    ((T_004BA8F8 *)D_L01_002446C0)->e[i].id = id;
    ((T_004BA8F8 *)D_L01_002446C0)->e[i].b4 = b4;
    ((T_004BA8F8 *)D_L01_002446C0)->e[i].b18 = 0;
    ((T_004BA8F8 *)D_L01_002446C0)->e[i].f12 = 0xCDB;
    ((T_004BA8F8 *)D_L01_002446C0)->e[i].b16 = 0;
    ((T_004BA8F8 *)D_L01_002446C0)->e[i].f8 = 0;
    ((T_004BA8F8 *)D_L01_002446C0)->e[i].b17 = b17;
}
/* localdecomp:end func_L01_004BA8F8 */

/* localdecomp:start func_L01_004BA940 */
typedef struct {
    s32 type;
    u8 b4;
    u8 p5[7];
    s32 w12;
    u8 b16;
    u8 b17;
    u8 b18;
    u8 b19;
} E_004BA940;
typedef struct {
    u8 p0[320];
    E_004BA940 e[76];
} B_004BA940;
extern S_00244740 D_L01_002446C0[];

void func_L01_004BA940(s32 i, s32 type) {
    (*(B_004BA940 *)&D_L01_002446C0).e[i].type = type;
    (*(B_004BA940 *)&D_L01_002446C0).e[i].b4 = type == 0;
    (*(B_004BA940 *)&D_L01_002446C0).e[i].b18 = type == 0;
    (*(B_004BA940 *)&D_L01_002446C0).e[i].b19 = type == 1;
    (*(B_004BA940 *)&D_L01_002446C0).e[i].b16 = 0;
    (*(B_004BA940 *)&D_L01_002446C0).e[i].w12 = 0xCDB;
    (*(B_004BA940 *)&D_L01_002446C0).e[i].b17 = 0;
}
/* localdecomp:end func_L01_004BA940 */

/* localdecomp:start func_L01_004BA990 */
extern S_002C5640 D_L01_002C5600[];

extern u8 D_001425C0[];
extern void func_L01_00419248(s32);

void func_L01_004BA990(void) {
    s32 i;
    for (i = 0; i < 156; i++) {
        u8 *p = &D_001425C0[i];
        if (i != 9 && ((Ent4B6DF8 *)&D_L01_002C5600)[*p].active) {
            func_L01_00419248(i);
        }
    }
}
/* localdecomp:end func_L01_004BA990 */

INCLUDE_ASM("asm/levels", func_L01_004BAA20);

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

INCLUDE_ASM("asm/levels", func_L01_004BB140);

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

INCLUDE_ASM("asm/levels", func_L01_004BBD90);

/* localdecomp:start func_L01_004BC0B8 */
extern S_00244740 D_L01_002446C0[];
extern u8 D_L01_001DACC8[];
extern void func_0011B2E8(s32, u8 *, s32);

void func_L01_004BC0B8(s32 a0) {
    u8 *s = ((u8 *)&D_L01_002446C0);
    func_0011B2E8(*(s32 *)(s + 60), D_L01_001DACC8, a0);
    *(s32 *)(s + 100) = 0;
}
/* localdecomp:end func_L01_004BC0B8 */

INCLUDE_ASM("asm/levels", func_L01_004BC0F8);

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

INCLUDE_ASM("asm/levels", func_L01_004BD618);

INCLUDE_ASM("asm/levels", func_L01_004BDBA0);

/* localdecomp:start func_L01_004BDF08 */
extern s32 D_L01_00244710[];
extern void func_L01_004BD618(void);
extern void func_L01_004BDBA0(void);

void func_L01_004BDF08(void) {
    s32 m = D_L01_00244710[0];
    switch (m) {
    case 0:
    case 2:
        func_L01_004BD618();
        break;
    case 3:
        func_L01_004BD618();
        break;
    case 5:
        func_L01_004BDBA0();
        break;
    }
}
/* localdecomp:end func_L01_004BDF08 */

INCLUDE_ASM("asm/levels", func_L01_004BDF78);

INCLUDE_ASM("asm/levels", func_L01_004BE6B8);

INCLUDE_ASM("asm/levels", func_L01_004BEA70);

/* localdecomp:start func_L01_004BEC88 */
extern void func_0011B2E8(s32, u8 *, s32);
extern s32 D_L01_00244704[];
extern char D_L01_001DAD80[];
extern char D_L01_001DAD90[];
extern char D_L01_001DAD98[];

void func_L01_004BEC88(char *buf, s32 v) {
    if (D_L01_00244704[0] == 0) {
        if (v > 999999) {
            ((s32 (*)(char *, const char *, ...))func_0011B2E8)(buf, D_L01_001DAD80, v / 1000000, (v / 1000) % 1000, v % 1000);
        } else if (v >= 1000) {
            ((s32 (*)(char *, const char *, ...))func_0011B2E8)(buf, D_L01_001DAD90, v / 1000, v % 1000);
        } else {
            ((s32 (*)(char *, const char *, ...))func_0011B2E8)(buf, D_L01_001DAD98, v);
        }
    } else {
        ((s32 (*)(char *, const char *, ...))func_0011B2E8)(buf, D_L01_001DAD98, v);
    }
}
/* localdecomp:end func_L01_004BEC88 */

INCLUDE_ASM("asm/levels", func_L01_004BED50);

/* localdecomp:start func_L01_004BF4D0 */
extern void func_L01_004C3EB8(void);

void func_L01_004BF4D0(void) {
    char buf[4];
    func_L01_004C3EB8();
}
/* localdecomp:end func_L01_004BF4D0 */

/* localdecomp:start func_L01_004BF4F0 */
void func_L01_004BF4F0(void) {

}
/* localdecomp:end func_L01_004BF4F0 */

/* localdecomp:start func_L01_004BF4F8 */
extern void func_L01_004C48D0(void);

void func_L01_004BF4F8(void) {
    char buf[4];
    func_L01_004C48D0();
}
/* localdecomp:end func_L01_004BF4F8 */

/* localdecomp:start func_L01_004BF518 */
extern void func_L01_004C2A80(void);

void func_L01_004BF518(void) {
    char buf[496];
    func_L01_004C2A80();
}
/* localdecomp:end func_L01_004BF518 */

/* localdecomp:start func_L01_004BF538 */
extern void func_L01_004C3A48(void);

void func_L01_004BF538(void) {
    char buf[272];
    func_L01_004C3A48();
}
/* localdecomp:end func_L01_004BF538 */

/* localdecomp:start func_L01_004BF558 */
extern void func_L01_004C51E0(void);

void func_L01_004BF558(void) {
    char buf[272];
    func_L01_004C51E0();
}
/* localdecomp:end func_L01_004BF558 */

/* localdecomp:start func_L01_004BF578 */
extern void func_L01_004C44D8(void);

void func_L01_004BF578(void) {
    char buf[272];
    func_L01_004C44D8();
}
/* localdecomp:end func_L01_004BF578 */

LINKER_REMNANT("asm/levels", func_L01_004BF598);

/* localdecomp:start func_L01_004BF5A0 */
void func_L01_004BF5A0(void) {

}
/* localdecomp:end func_L01_004BF5A0 */

/* localdecomp:start func_L01_004BF5A8 */
void func_L01_004BF5A8(void) {

}
/* localdecomp:end func_L01_004BF5A8 */

/* localdecomp:start func_L01_004BF5B0 */
void func_L01_004BF5B0(void) {

}
/* localdecomp:end func_L01_004BF5B0 */

/* localdecomp:start func_L01_004BF5B8 */
extern void func_L01_004C3D70(void);

void func_L01_004BF5B8(void) {
    char buf[64];
    func_L01_004C3D70();
}
/* localdecomp:end func_L01_004BF5B8 */

/* localdecomp:start func_L01_004BF5D8 */
extern void func_L01_004C5530(void);

void func_L01_004BF5D8(void) {
    char buf[64];
    func_L01_004C5530();
}
/* localdecomp:end func_L01_004BF5D8 */

/* localdecomp:start func_L01_004BF5F8 */
extern void func_L01_004C47A0(void);

void func_L01_004BF5F8(void) {
    char buf[64];
    func_L01_004C47A0();
}
/* localdecomp:end func_L01_004BF5F8 */

/* localdecomp:start func_L01_004BF618 */
extern S_00244740 D_L01_002446C0[];

void func_L01_004BF618(s32 type) {
    s32 i;
    for (i = 0; i < (*(B_4BBAF0 *)&D_L01_002446C0).count; i++) {
        if ((*(B_4BBAF0 *)&D_L01_002446C0).e[i].type == type) {
            (*(B_4BBAF0 *)&D_L01_002446C0).e[i].b16 = 1;
        }
    }
}
/* localdecomp:end func_L01_004BF618 */

/* localdecomp:start func_L01_004BF660 */
extern s32 func_L01_004BF900(void);
extern s32 func_L01_004BF698(void);
extern s32 D_L01_00244E04[];
void func_L01_004BF660(void) {
    if (D_L01_00244E04[0] == 0) {
        ((void (*)(void))func_L01_004BF900)();
    } else {
        ((void (*)(void))func_L01_004BF698)();
    }
}
/* localdecomp:end func_L01_004BF660 */

/* localdecomp:start func_L01_004BF698 */
extern S_00244740 D_L01_002446C0[];

extern A_4BBAF0 D_00142660;
extern u8 D_00142CB5[];
extern u8 D_00142CB1[];
extern u8 D_00142CB3[];
extern u8 D_00142CB6[];
extern u8 D_00142CB0[];
extern s32 D_L01_001DADD8;
extern void func_L01_004BF618(s32);

s32 func_L01_004BF698(void) {
    s32 n, m, i, r, t;
    if (D_00142660.f72 & 2) func_L01_004BF618(21);
    if (D_00142660.f72 & 4) func_L01_004BF618(17);
    if (D_00142660.f72 & 8) func_L01_004BF618(19);
    if (D_00142660.f72 & 0x10) func_L01_004BF618(22);
    if (D_00142660.f72 & 0x20) func_L01_004BF618(16);
    m = 0;
    n = 0;
    (*(B_4BBAF0 *)&D_L01_002446C0).f1912 = 0;
    for (i = 0; i < (*(B_4BBAF0 *)&D_L01_002446C0).count; i++) {
        t = (*(B_4BBAF0 *)&D_L01_002446C0).e[i].type;
        if (t == 16 || t == 17 || t == 19 || t == 21 || t == 22) {
            if ((*(B_4BBAF0 *)&D_L01_002446C0).e[i].b4 == 0 && (*(B_4BBAF0 *)&D_L01_002446C0).e[i].b16 != 0) (*(B_4BBAF0 *)&D_L01_002446C0).f1912++;
        }
    }
    if ((D_00142660.f72 & 2) || D_00142CB5[0]) n = 1;
    if ((D_00142660.f72 & 4) || D_00142CB1[0]) n++;
    if ((D_00142660.f72 & 8) || D_00142CB3[0]) n++;
    if ((D_00142660.f72 & 0x10) || D_00142CB6[0]) n++;
    if ((D_00142660.f72 & 0x20) || D_00142CB0[0]) n++;
    for (i = 0; i < (*(B_4BBAF0 *)&D_L01_002446C0).count; i++) {
        if ((*(B_4BBAF0 *)&D_L01_002446C0).e[i].b19 == 0) m++;
    }
    r = n == m;
    (*(B_4BBAF0 *)&D_L01_002446C0).f1904 = r;
    if (D_L01_001DADD8 != r) {
        D_L01_001DADD8 = r;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_004BF698 */

/* localdecomp:start func_L01_004BF900 */
extern S_00244740 D_L01_002446C0[];
extern s32 D_001426A8[];
extern s32 D_L01_001DADDC;
s32 func_L01_004BF900(void) {
    if (D_001426A8[0] & 1) {
        (*(Unk244740 *)&D_L01_002446C0).v = 1;
    }
    if (D_L01_001DADDC != (*(Unk244740 *)&D_L01_002446C0).v) {
        D_L01_001DADDC = (*(Unk244740 *)&D_L01_002446C0).v;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_004BF900 */

/* localdecomp:start func_L01_004BF948 */
void func_L01_004BF948(void) {

}
/* localdecomp:end func_L01_004BF948 */

/* localdecomp:start func_L01_004BF950 */
extern S_00244740 D_L01_002446C0[];
extern void func_003A2558(void);

void func_L01_004BF950(void) {
    u8 *p;
    func_003A2558();
    p = (u8 *)D_L01_002446C0;
    p[0x89] = 0;
    p[0x88] = 0;
}
/* localdecomp:end func_L01_004BF950 */

INCLUDE_ASM("asm/levels", func_L01_004BF980);

INCLUDE_ASM("asm/levels", func_L01_004C0888);

INCLUDE_ASM("asm/levels", func_L01_004C0ED0);

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

INCLUDE_ASM("asm/levels", func_L01_004C1460);

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

INCLUDE_ASM("asm/levels", func_L01_004C1D38);

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

INCLUDE_ASM("asm/levels", func_L01_004C1EA0);
