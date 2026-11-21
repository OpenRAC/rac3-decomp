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
extern u8 D_001425C0[];
extern S_002C5640 D_L01_002C5600[];

/* localdecomp:start func_L01_004BAA20 */
typedef struct {
    s32 type;
    u8 b4;
    u8 p5[11];
    u8 b16;
    u8 p17[2];
    u8 b19;
} E_004BAA20;
typedef struct {
    u8 pad0[0x5C];
    s32 f5C;
    u8 pad60[0x20];
    s32 cur;
    u8 pad84[0xBC];
    E_004BAA20 e[76];
    u8 pad730[0x10];
    s32 count;
    s32 f744;
    u8 pad748[0x28];
    s32 f770;
    u8 pad774[8];
    s32 f77C;
} Menu_004BAA20;
typedef struct {
    u8 p0;
    u8 b1;
    u8 p2[0x82];
    u16 h84;
    u8 p86[4];
    u16 h8A;
    u8 p8C[0x64];
} Ent_004BAA20;
extern S_00244740 D_L01_002446C0[];
extern S_002C5640 D_L01_002C5600[];
extern u8 D_001425C0[];
extern u16 D_001D54D8[] __attribute__((section(".sdata")));
extern s32 D_001427F0[];
extern u8 D_00142CA0[];
extern s32 D_001D545C;
extern s32 func_L01_0041A4F0(void);
extern void func_L01_004BA990(void);
extern void func_L01_004BA8F8(s32 i, s32 id, u8 b4, u8 b17);
extern void func_L01_004BA940(s32 i, s32 type);
extern void func_L01_004BF660(void);
extern s32 func_L01_004BB0F0(s32 a0);

void func_L01_004BAA20(s32 a0) {
    s32 flag;
    s32 type;
    s32 i;
    s32 id;
    u32 e;
    u32 hi;

    flag = 1;
    if (((Menu_004BAA20 *)D_L01_002446C0)->f5C == 0) {
        flag = a0;
    }
    ((Menu_004BAA20 *)D_L01_002446C0)->count = 0;
    type = ((Menu_004BAA20 *)D_L01_002446C0)->e[((Menu_004BAA20 *)D_L01_002446C0)->cur].type;
    if (func_L01_0041A4F0() != 0) {
        func_L01_004BA990();
    }
    if (((Menu_004BAA20 *)D_L01_002446C0)->f744 == 0) {
        for (i = 0; i < 32; i++) {
            e = D_001D54D8[i];
            if ((u16)e == 0xFFFF) {
                continue;
            }
            hi = (u16)e >> 15;
            id = e & 0x3FFF;
            if (!hi) {
                continue;
            }
            if (((Ent_004BAA20 *)D_L01_002C5600)[D_001425C0[id]].h84 == 0) {
                continue;
            }
            if (D_001427F0[id] >= ((Ent_004BAA20 *)D_L01_002C5600)[D_001425C0[id]].h8A) {
                continue;
            }
            if (((Menu_004BAA20 *)D_L01_002446C0)->f5C != 0 && (id == 16 || id == 17 || id == 19 || id == 21 || id == 22)) {
                continue;
            }
            func_L01_004BA8F8(((Menu_004BAA20 *)D_L01_002446C0)->count, id, 1, 0);
            ((Menu_004BAA20 *)D_L01_002446C0)->count++;
        }
        func_L01_004BA940(((Menu_004BAA20 *)D_L01_002446C0)->count, 0);
        ((Menu_004BAA20 *)D_L01_002446C0)->count++;
        for (i = 0; i < 32; i++) {
            e = D_001D54D8[i];
            if ((u16)e == 0xFFFF) {
                continue;
            }
            hi = (u16)e >> 15;
            id = e & 0x3FFF;
            if (!hi && flag == 0 && !(e & 0x4000)
                && (!(id == 16 || id == 17 || id == 19 || id == 21 || id == 22)
                    || (func_L01_0041A4F0() != 0 && ((Ent_004BAA20 *)D_L01_002C5600)[D_001425C0[id]].b1 != 4))) {
                func_L01_004BA8F8(((Menu_004BAA20 *)D_L01_002446C0)->count, id, 0, 0);
                ((Menu_004BAA20 *)D_L01_002446C0)->count++;
            } else if (flag == 0 && (D_001D54D8[i] & 0x8000) && func_L01_0041A4F0() != 0
                       && ((Ent_004BAA20 *)D_L01_002C5600)[D_001425C0[id]].b1 == 4 && id != 151) {
                func_L01_004BA8F8(((Menu_004BAA20 *)D_L01_002446C0)->count, id, 0, 1);
                ((Menu_004BAA20 *)D_L01_002446C0)->count++;
            }
        }
    } else {
        for (i = 0; i < 32; i++) {
            if (D_001D54D8[i] == 0xFFFF) {
                continue;
            }
            id = D_001D54D8[i] & 0x3FFF;
            if (id == 16 || id == 17 || id == 19 || id == 21 || id == 22) {
                func_L01_004BA8F8(((Menu_004BAA20 *)D_L01_002446C0)->count, id, D_00142CA0[id] != 0, 0);
                ((Menu_004BAA20 *)D_L01_002446C0)->count++;
            }
        }
    }
    func_L01_004BF660();
    if ((((Menu_004BAA20 *)D_L01_002446C0)->f744 != 0 && ((Menu_004BAA20 *)D_L01_002446C0)->f770 == 0)
        || (((Menu_004BAA20 *)D_L01_002446C0)->f744 == 0 && (((Menu_004BAA20 *)D_L01_002446C0)->f77C == 0 || func_L01_004BB0F0(5) == 0) && (D_001D545C == 3 || D_001D545C == 6))) {
        func_L01_004BA940(((Menu_004BAA20 *)D_L01_002446C0)->count, 1);
        ((Menu_004BAA20 *)D_L01_002446C0)->count++;
    }
    for (i = 0; i < ((Menu_004BAA20 *)D_L01_002446C0)->count; i++) {
        if (((Menu_004BAA20 *)D_L01_002446C0)->e[i].type == type) {
            ((Menu_004BAA20 *)D_L01_002446C0)->cur = i;
        }
    }
    if (((Menu_004BAA20 *)D_L01_002446C0)->cur > ((Menu_004BAA20 *)D_L01_002446C0)->count - 1) {
        ((Menu_004BAA20 *)D_L01_002446C0)->cur = ((Menu_004BAA20 *)D_L01_002446C0)->count - 1;
    } else if (((Menu_004BAA20 *)D_L01_002446C0)->cur < 0) {
        ((Menu_004BAA20 *)D_L01_002446C0)->cur = 0;
    }
}
/* localdecomp:end func_L01_004BAA20 */
