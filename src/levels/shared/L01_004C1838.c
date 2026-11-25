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

typedef struct {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 dir;
    f32 alpha;
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

/* localdecomp:start func_L01_004C1838 */
extern s32 D_L01_00244750[];
extern u8 *D_001D52FC;
typedef struct {
    u8 pad0[0x90];
    s32 v90;
} S_004C1838;
extern S_004C1838 D_L01_002446C0[];
__asm__(".extern D_001D52FC, 16");
extern s32 func_003B9BD0(s32);
extern void func_L01_004991B8(s32, s32);
extern void func_L01_00516D60(s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_00516FD8(s32, s32);
extern s32 func_00381FF0(s32);

s32 func_L01_004C1838(void) {
    s8 vis; s32 visible; s32 result = 0, full;
    f32 width, height, alpha, pad, half, third, w2, h2;
    s32 sel;
    switch (D_L01_001E0F38.state) {
    case 0:
        break;
    case 1:
        func_L01_004991B8(func_003B9BD0(0), 0);
        break;
    case 2:
        func_L01_004991B8(func_003B9BD0(0), 1);
        D_L01_001E0F38.alpha += 0.14000001f;
        D_L01_00244750[0] = 0;
        D_L01_001E0F38.dir = 1;
        if (D_L01_001E0F38.alpha > 1.0f) D_L01_001E0F38.alpha = 1.0f;
        else if (D_L01_001E0F38.alpha < 0.0f) D_L01_001E0F38.alpha = 0.0f;
        if (D_L01_001E0F38.alpha == 1.0f) D_L01_001E0F38.state = 3;
        break;
    case 3:
        D_L01_00244750[0] = 0;
        func_L01_004991B8(func_003B9BD0(0), 1);
        result = *(s32 *)(D_001D52FC + 0x1A4) & D_L01_001E0F38.f38;
        if (result) D_L01_001E0F38.state = 4;
        break;
    case 4:
        D_L01_002446C0[0].v90 = 0;
        func_L01_004991B8(func_003B9BD0(0), 1);
        D_L01_001E0F38.alpha -= 0.14000001f;
        D_L01_001E0F38.dir = -1;
        if (D_L01_001E0F38.alpha > 1.0f) D_L01_001E0F38.alpha = 1.0f;
        else if (D_L01_001E0F38.alpha < 0.0f) D_L01_001E0F38.alpha = 0.0f;
        if (D_L01_001E0F38.alpha == 0.0f) {
            D_L01_001E0F38.state = 1;
            D_L01_002446C0[0].v90 = 0x80;
        }
        break;
    }
    full = D_L01_001E0F38.alpha >= 1.0f;
    visible = D_L01_001E0F38.alpha > 0.0f;
    half = 0.5f;
    func_L01_00516D60(D_L01_001E0F38.a, full);
    third = 0.3f;
    func_L01_00516D60(D_L01_001E0F38.b, full & D_L01_001E0F38.f3C);
    vis = visible;
    func_L01_00516D60(D_L01_001E0F38.c, vis);
    func_L01_00516D60(D_L01_001E0F38.d, vis);
    func_L01_00516D60(D_L01_001E0F38.e, vis);
    func_L01_00516D60(D_L01_001E0F38.f, vis);
    width = D_L01_001E0F38.x;
    height = D_L01_001E0F38.y;
    alpha = D_L01_001E0F38.alpha;
    pad = D_L01_001E0F38.g;
    sel = D_L01_001E0F38.f3C;
    if (full) {
        func_L01_00516470(D_L01_001E0F38.a, half, 0.29000002f - (f32)sel * 0.03f);
        func_L01_00517538(D_L01_001E0F38.a, width, height);
        func_L01_00516FD8(D_L01_001E0F38.a, func_00381FF0(D_L01_001E0F38.f20));
        func_L01_00516470(D_L01_001E0F38.b, half, height * half + third - 0.02f);
    }
    if (visible) {
        func_L01_00516470(D_L01_001E0F38.c, half, third);
        w2 = (width + pad) * alpha;
        h2 = (height + pad) * alpha;
        func_L01_00517538(D_L01_001E0F38.c, w2, h2);
        func_L01_00516470(D_L01_001E0F38.d, half, third);
        func_L01_00517538(D_L01_001E0F38.d, w2, h2);
        func_L01_00516470(D_L01_001E0F38.e, half, third);
        func_L01_00517538(D_L01_001E0F38.e, w2 + 0.015f, h2 + 0.015f);
    }
    return result;
}
/* localdecomp:end func_L01_004C1838 */
