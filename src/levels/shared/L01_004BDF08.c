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

/* localdecomp:start func_L01_004BE6B8 */
typedef struct {
    u8 u;
    u8 v;
    s8 yoff;
    s8 width;
} Glyph_004BE6B8;
typedef struct {
    u8 pad0[0x50];
    s32 mode;
} Menu_004BE6B8;
extern S_00244740 D_L01_002446C0[];
extern Glyph_004BE6B8 D_L01_002EF780[];
extern long func_00389598(s32);
extern s32 func_L01_00406210(f32, f32, f32, f32, s32, s32, s32, s32, u32 *, long);

void func_L01_004BE6B8(unsigned long color, u8 *str, s32 n, f32 x, f32 y, f32 scale) {
    u32 cols[4];
    u32 gray[4];
    long tex;
    f32 w;
    s32 i;
    s32 a;
    s32 b;
    u32 ca;
    u32 cb;
    s32 is_ctrl;
    f32 off;
    Glyph_004BE6B8 *tbl;

    tex = func_00389598(2);
    tbl = D_L01_002EF780;
    w = scale * 16.0f;
    color &= 0xFFFFFF;
    for (i = 0; i != n && str[i] != 0; i++) {
        if (tbl[str[i]].width != 0) {
            off = tbl[str[i]].yoff * scale;
            if (((Menu_004BE6B8 *)D_L01_002446C0)->mode == 2) {
                a = 128 - (s32)__builtin_fabs(215.0f - x);
                b = 128 - (s32)__builtin_fabs(215.0f - (x + w));
            } else {
                a = 128 - (s32)(__builtin_fabs(256.0f - x) * 0.75);
                b = 128 - (s32)(__builtin_fabs(256.0f - (x + w)) * 0.75);
            }
            is_ctrl = str[i] < 32;
            if (a < 0) {
                a = 0;
            }
            if (b < 0) {
                b = 0;
            }
            a <<= 24;
            ca = a | (s32)color;
            b <<= 24;
            cb = b | (s32)color;
            cols[0] = ca;
            cols[1] = cb;
            cols[2] = ca;
            cols[3] = cb;
            if (is_ctrl) {
                s32 g;
                u32 c;
                c = (u8)ca + (u8)(ca >> 8) + (u8)(ca >> 16);
                g = (s32)c / 3;
                c = g + ((ca & 0xFF000000) + (g << 16) + (g << 8));
                gray[0] = c;
                gray[1] = c;
                gray[2] = c;
                gray[3] = c;
                func_L01_00406210(x, y + off, scale * 24.0f, scale * 16.0f, tbl[str[i]].u, tbl[str[i]].v, 24, 16, gray, tex);
            } else if (str[i] > 32) {
                func_L01_00406210(x, y + off, w, w, tbl[str[i]].u, tbl[str[i]].v, 16, 16, cols, tex);
            }
            x += tbl[str[i]].width * scale;
        }
    }
}
/* localdecomp:end func_L01_004BE6B8 */
