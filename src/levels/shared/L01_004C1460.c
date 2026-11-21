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
extern void func_L01_00516AA0(s32, s32, s32);

/* localdecomp:start func_L01_004C1460 */
extern s32 D_L01_001E0F7C;
extern s32 D_L01_001E0F80;
extern Ent4BD808 D_L01_002F1D18[];
extern f32 func_0038D098(f32);
extern f32 func_L01_004451A8(f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_00518590(s32, s32, s32);

void func_L01_004C1460(s32 a0) {
    f32 t;
    f32 k;
    f32 y;
    f32 y2;
    f32 m;
    s32 alpha;
    s32 i;

    D_L01_001E0F80 = 1;
    if (a0 != 0) {
        t = (f32)D_L01_001E0F7C / 12.0f;
        t = 1.0f - t;
    } else {
        t = (f32)D_L01_001E0F7C / 15.0f;
    }
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    k = (1.0f - func_0038D098(t * 3.1415927f)) * 0.5f;
    alpha = func_L01_004451A8(t) * 128.0f;
    y = func_003C4088(0.65f, 0.45f, k);
    for (i = 0; i < 2; i++) {
        func_L01_00516470(i + 0x480005, 0.5f, y);
        func_L01_00516470(i + 0x480009, 0.5f, y);
        func_L01_00516470(i + 0x48000D, 0.5f, y);
    }
    y2 = func_003C4088(0.25f, 0.45f, k) - 0.187f;
    for (i = 2; i < 4; i++) {
        func_L01_00516470(i + 0x480005, 0.5f, y2);
        func_L01_00516470(i + 0x480009, 0.5f, y2);
        func_L01_00516470(i + 0x48000D, 0.5f, y2);
    }
    func_L01_005170B8(0x480012, (alpha << 24) | 0x1465B7);
    func_L01_00517538(0x480012, 0.84f, k * 0.56f);
    func_L01_004C13B0(alpha, D_L01_002F1D18);
    func_L01_00516AA0(0x480026, 1, 0);
    func_L01_00518590(0x480004, 1, 1);
    m = (y + y2) * 0.5f;
    func_L01_00516470(0x480004, 0.5f, m);
    func_L01_00517538(0x480004, 1.0f, func_003C4088(0.145f, 0.57f, k));
    func_L01_00518590(0x480003, 1, 1);
    func_L01_00516470(0x480003, 0.5f, m);
    func_L01_00517538(0x480003, 1.0f, func_003C4088(0.13f, 0.57f, k));
}
/* localdecomp:end func_L01_004C1460 */
