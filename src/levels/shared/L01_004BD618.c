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
extern u8 D_L01_001DABC8;
extern char *D_001D52FC;
extern s32 D_L01_001E0F90;
extern s32 D_L01_001DABD0;
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004BD170(void);
extern s16 D_001426A0[];
extern s32 D_L01_001DABCC;
extern void func_003A2750(s32);
extern s32 func_L01_005147A8(s32);
extern void func_L01_004C4E60(void);
extern void func_L01_00425978(s32);
extern s32 *func_003B9BD0(s32);
extern void func_003BA4F8(void *, s32);

INCLUDE_ASM("asm/levels", func_L01_004BD618);

/* localdecomp:start func_L01_004BDBA0 */
typedef struct { s32 id; u8 b4; u8 p5[13]; u8 b18; u8 b19; } E_4BDBA0;
typedef struct { s32 a; s32 b; s32 id; s32 d; } I_4BDBA0;
typedef struct {
    u8 p0[0x28]; s32 f28; u8 p2C[0x24]; s32 f50; u8 p54[8]; s32 f5C; u8 p60[0x18];
    s32 f78; u8 p7C[4]; s32 cur; s32 f84; u8 f88; u8 p89[3]; s32 f8C; u8 p90[0xB0];
    union { E_4BDBA0 e[1]; I_4BDBA0 i[1]; } u;
    u8 p154[0x604]; u8 f758; u8 p759[3]; s32 f75C; s32 f760;
} M_4BDBA0;
typedef struct { u8 b0; u8 p1[0x37]; u16 h38; u8 p3A[0x50]; u16 h8A; u8 p8C[0x64]; } G_4BDBA0;
__asm__(".extern D_001D52FC, 16");
__asm__(".extern D_001D545C, 16");
__asm__(".extern D_L01_001DABC8, 1");
__asm__(".extern D_L01_001DABCC, 4");
__asm__(".extern D_L01_001DABD0, 4");
__asm__(".extern D_L01_001DABD8, 4");
extern s32 func_L01_00498610(s32);
extern s32 func_L01_00498698(s32);
extern void func_L01_004990A8(s32, s32);
extern void func_L01_0041CB70(s32, s32);
extern s32 func_L01_004BB0F0(s32);
extern void func_L01_0045FDF0(s32);
extern void func_L01_004AABF0(s32, s32, s32);
extern void func_L01_0047B798(s32, s32);
extern void func_L01_0047B820(s32, s32);
extern void func_L01_0047B9B8(s32);
extern s32 D_001D545C;
extern s32 D_L01_001DABD8;
extern u8 D_00142CA0[];
extern s32 D_001427F0[];

void func_L01_004BDBA0(void) {
    s32 changed;
    s32 prev;
    s32 cur;
    s32 id;

    if (((M_4BDBA0 *)D_L01_002446C0)->f84 == 0) {
        changed = 0;
        prev = func_L01_00498698(func_L01_00498610(0));
        func_L01_004990A8(func_L01_00498610(0), *(s32 *)(D_001D52FC + 0x1C4));
        cur = func_L01_00498698(func_L01_00498610(0));
        if (prev != cur) {
            ((M_4BDBA0 *)D_L01_002446C0)->cur = cur;
            changed = 1;
        }
        if (changed) {
            if (((M_4BDBA0 *)D_L01_002446C0)->f88) {
                ((M_4BDBA0 *)D_L01_002446C0)->f8C = (((M_4BDBA0 *)D_L01_002446C0)->f50 != 2) ? 1 : 3;
            }
            if (((M_4BDBA0 *)D_L01_002446C0)->f78 != -1 && ((M_4BDBA0 *)D_L01_002446C0)->f50 == 0) {
                func_L01_0041CB70(((M_4BDBA0 *)D_L01_002446C0)->f78, 0);
            }
            ((M_4BDBA0 *)D_L01_002446C0)->f78 = -1;
        }
        if (*(s32 *)(D_001D52FC + 0x1C4) & 0x40) {
            if (!(D_L01_001E0F90 & 0x40)) {
                if (func_L01_004BB0F0(((M_4BDBA0 *)D_L01_002446C0)->u.i[((M_4BDBA0 *)D_L01_002446C0)->cur].id)) {
                    D_L01_001DABC8 = 1;
                    D_L01_001DABD0 = ((M_4BDBA0 *)D_L01_002446C0)->u.i[((M_4BDBA0 *)D_L01_002446C0)->cur].id;
                    func_L01_004C4E60();
                    if (D_L01_001DABD0 == -1) {
                        func_L01_005147A8(D_L01_001DABCC);
                        func_L01_00425978(D_001426A0[0]);
                    } else {
                        D_L01_001DABCC = ((M_4BDBA0 *)D_L01_002446C0)->u.i[((M_4BDBA0 *)D_L01_002446C0)->cur].id;
                        func_L01_005147A8(D_L01_001DABCC);
                        func_L01_00425978(D_001426A0[0]);
                    }
                    func_L01_0045FDF0(1);
                } else {
                    ((M_4BDBA0 *)D_L01_002446C0)->f84 = 1;
                }
                if (((M_4BDBA0 *)D_L01_002446C0)->f50 == 3 || ((M_4BDBA0 *)D_L01_002446C0)->f50 == 5) {
                    func_L01_004AABF0(0, 0x11, ((M_4BDBA0 *)D_L01_002446C0)->f28);
                }
            }
        }
        if (D_001D545C == 3 && ((M_4BDBA0 *)D_L01_002446C0)->f5C == 0 &&
            !((M_4BDBA0 *)D_L01_002446C0)->u.e[((M_4BDBA0 *)D_L01_002446C0)->cur].b18 &&
            !((M_4BDBA0 *)D_L01_002446C0)->u.e[((M_4BDBA0 *)D_L01_002446C0)->cur].b19) {
            E_4BDBA0 *e = &((M_4BDBA0 *)D_L01_002446C0)->u.e[((M_4BDBA0 *)D_L01_002446C0)->cur];
            if (e->id != 0x67 && e->id != 0x16 && ((M_4BDBA0 *)D_L01_002446C0)->f50 == 0 &&
                (*(s32 *)(D_001D52FC + 0x1C4) & 0x80)) {
                D_L01_001DABD8 = 0;
                ((M_4BDBA0 *)D_L01_002446C0)->f758 = 1;
                ((M_4BDBA0 *)D_L01_002446C0)->f760 = e->id;
                ((M_4BDBA0 *)D_L01_002446C0)->f75C = e->id;
                func_L01_004BD170();
            }
        }
        if (*(s32 *)(D_001D52FC + 0x1C4) & 0x10) {
            func_L01_004BD170();
        }
    }
    if (((M_4BDBA0 *)D_L01_002446C0)->u.e[((M_4BDBA0 *)D_L01_002446C0)->cur].b4 == 1) {
        id = ((M_4BDBA0 *)D_L01_002446C0)->u.e[((M_4BDBA0 *)D_L01_002446C0)->cur].id;
        if (((G_4BDBA0 *)D_L01_002C5600)[D_001425C0[id]].b0 && D_00142CA0[id]) {
            func_L01_0047B798(((G_4BDBA0 *)D_L01_002C5600)[D_001425C0[id]].h38, 0);
            func_L01_0047B820(D_001427F0[id], ((G_4BDBA0 *)D_L01_002C5600)[D_001425C0[id]].h8A);
            func_L01_0047B9B8(id);
        }
    }
}
/* localdecomp:end func_L01_004BDBA0 */
