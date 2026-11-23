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
