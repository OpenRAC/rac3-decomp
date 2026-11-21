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
