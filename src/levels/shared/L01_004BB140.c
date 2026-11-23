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
extern u8 D_L01_001DABC8;

/* localdecomp:start func_L01_004BB140 */
typedef struct {
    s32 w0;
    s32 w4;
    s32 f8;
    s32 fC;
} Skin_004BB140;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Item_004BB140;
typedef struct {
    u8 pad0[320];
    Item_004BB140 items[96];
    s32 count;
} List_004BB140;
typedef struct {
    s32 w0;
    void *p4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
} Desc_004BB140;
extern Skin_004BB140 D_L01_002F1C20[];
extern Desc_004BB140 D_L01_002F1CC0;
extern u8 D_L01_002F1900[];
extern u8 D_0014279F[];
extern u8 D_L01_001DABC8;
extern s32 D_L01_001DABCC;
extern f32 D_L01_001DABAC;
extern f32 D_L01_001DABB0;
extern f32 D_L01_001DABB4;
extern u8 D_L01_001DABB8;
extern f32 D_L01_001DABBC;
extern f32 D_L01_001DABC0;
extern f32 D_L01_001DABC4;
__asm__(".extern D_L01_001DABC8, 1");
__asm__(".extern D_L01_001DABCC, 4");
__asm__(".extern D_L01_001DABAC, 4");
__asm__(".extern D_L01_001DABB0, 4");
__asm__(".extern D_L01_001DABB4, 4");
__asm__(".extern D_L01_001DABB8, 1");
__asm__(".extern D_L01_001DABBC, 4");
__asm__(".extern D_L01_001DABC0, 4");
__asm__(".extern D_L01_001DABC4, 4");
extern u8 func_L01_005147D8(void);
extern s32 func_L01_004BB0F0(s32 a0);
extern void func_L01_004BB120_004BB140(u32 a0);
extern s32 func_L01_00498610(s32);
extern s32 func_L01_004989C0(s32);
extern void func_L01_00498720(s32, Desc_004BB140 *);
extern void func_L01_00499780(s32, u8, f32, f32, f32, f32, f32);
extern void func_L01_004997A0(s32, f32, f32, f32, f32);
extern void func_L01_004C4E60(void);

s32 func_L01_004BB140(void) {
    u32 i;
    u32 j;

    D_L01_001DABC8 = 0;
    (*(List_004BB140 *)&D_L01_002446C0).count = 0;
    D_L01_001DABCC = func_L01_005147D8();
    if (D_0014279F[0] != 0) {
        D_L01_002F1C20[6].f8 = 0;
        func_L01_004BB120_004BB140(10);
    }
    for (i = 0; i < 10; i++) {
        if (func_L01_004BB0F0(D_L01_002F1C20[i].fC) != 0) {
            D_L01_002F1C20[i].f8 = 0;
        }
    }
    for (j = 0; j < 10; j++) {
        if (D_L01_002F1C20[j].f8 != 0xFF) {
            (*(List_004BB140 *)&D_L01_002446C0).items[(*(List_004BB140 *)&D_L01_002446C0).count].f8 = D_L01_002F1C20[j].fC;
            (*(List_004BB140 *)&D_L01_002446C0).items[(*(List_004BB140 *)&D_L01_002446C0).count].f4 = D_L01_002F1C20[j].f8;
            (*(List_004BB140 *)&D_L01_002446C0).items[(*(List_004BB140 *)&D_L01_002446C0).count].f0 = 0;
            (*(List_004BB140 *)&D_L01_002446C0).items[(*(List_004BB140 *)&D_L01_002446C0).count].fC = j;
            (*(List_004BB140 *)&D_L01_002446C0).count++;
        }
    }
    func_L01_004989C0(func_L01_00498610(0));
    D_L01_002F1CC0.p4 = D_L01_002F1900;
    D_L01_002F1CC0.w0 = 800;
    D_L01_002F1CC0.wC = (*(List_004BB140 *)&D_L01_002446C0).count;
    func_L01_00498720(func_L01_00498610(0), &D_L01_002F1CC0);
    func_L01_00499780(func_L01_00498610(0), D_L01_001DABB8, D_L01_001DABAC, D_L01_001DABB0, D_L01_001DABB4, D_L01_001DABBC, D_L01_001DABC0);
    func_L01_004997A0(func_L01_00498610(0), 0.5f, 0.77f, D_L01_001DABC4, 0.12f);
    func_L01_004C4E60();
    return (*(List_004BB140 *)&D_L01_002446C0).count;
}
/* localdecomp:end func_L01_004BB140 */
