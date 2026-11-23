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

/* localdecomp:start func_L01_004BBD90 */
#include "vu0.h"

typedef struct {
    u8 p0[0x28];
    u8 *w28;
    u8 p2C[0x50 - 0x2C];
    s32 w50;
    u8 p54[0x58 - 0x54];
    s32 w58;
    s32 w5C;
    s32 w60;
    u8 p64[0x78 - 0x64];
    s32 w78;
    s32 w7C;
    u8 p80[0x89 - 0x80];
    u8 b89;
    u8 p8A[0x758 - 0x8A];
    u8 b758;
    u8 p759[3];
    s32 w75C;
    u8 p760[4];
    u8 b764;
} S_004BBD90;
typedef struct {
    u8 p0[0x25C0];
    u8 *w25C0;
    u8 p25C4[0x25E5 - 0x25C4];
    u8 b25E5;
} H_004BBD90;
typedef struct {
    u8 p0[0x76];
    u16 h76;
    u8 p78[0x9E - 0x78];
    u16 h9E;
} C_004BBD90;
typedef struct { void (*fn)(s32, s32); } Vt_004BBD90;

extern S_004BBD90 D_L01_002446C0_004BBD90;
extern H_004BBD90 D_001A4BE0_004BBD90;
extern C_004BBD90 D_001CCFD0_004BBD90;
extern u8 D_L01_001E2CBD[];
extern s32 D_L01_001D6694;
extern s32 D_L01_001D673C;
extern u8 D_L01_001DAC20[8];
__asm__(".extern D_L01_001DAC20, 8");
extern s32 D_L01_001DABD8;
__asm__(".extern D_L01_001DABD8, 4");
extern u8 D_L01_001DABDC;
__asm__(".extern D_L01_001DABDC, 1");
extern u8 D_L01_001EAA20[];
extern u8 D_001A4C60[];

extern s32 func_003B9BD0(s32);
extern void func_003B9E90(s32);
extern void func_003935B0(s32, s32);
extern void func_L01_0041FE68(void);
extern void func_L01_00510AD0(void);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, s32);
extern void func_003C48A8(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern Vt_004BBD90 *func_L01_0043B548(s32, s32);
extern void func_L01_004A3610(void *, void *);
extern void func_L01_004BF950(void);
extern void func_003C2880(void *);
extern void func_0013C1D0(s32);
extern void func_003A1D00(void);
extern s32 func_0013B620(void);

void func_L01_004BBD90(void) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    f32 one;
    s32 hit;
    Vt_004BBD90 *o;
    u8 *w;

    if (D_L01_002446C0_004BBD90.w50 == 5) {
        func_003B9E90(func_003B9BD0(0));
    }
    if (D_L01_002446C0_004BBD90.w7C != -1) {
        func_003935B0(D_L01_002446C0_004BBD90.w7C, 0);
    }
    if (D_L01_002446C0_004BBD90.w78 != -1) {
        func_003935B0(D_L01_002446C0_004BBD90.w78, 0);
    }
    D_L01_002446C0_004BBD90.w7C = -1;
    D_L01_002446C0_004BBD90.w78 = -1;
    func_L01_0041FE68();
    D_L01_001E2CBD[0] = D_L01_002446C0_004BBD90.b764;
    D_L01_001D6694 = 0;
    D_001A4BE0_004BBD90.b25E5 = 0;
    func_L01_00510AD0();
    if (D_L01_002446C0_004BBD90.w60 == 0) {
        c = *(vu0_v4 *)D_L01_001DAC20;
        func_0038D000(&a, &c, D_L01_002446C0_004BBD90.w28 + 0xC0);
        vec_add_ab(&a, &a, D_L01_002446C0_004BBD90.w28 + 0x10);
        b.x = 0.0f;
        b.y = 0.0f;
        b.z = func_0038DAB8(*(f32 *)(D_L01_002446C0_004BBD90.w28 + 0xF8), 3.1415927f);
        if (D_L01_001D673C != 0) {
            func_003C5180(&a, &d, 1);
            one = 1.0f;
            func_L01_004515D8(D_001A4BE0_004BBD90.w25C0 + 0xC0, &d, 0);
            func_003C48A8(D_001A4BE0_004BBD90.w25C0 + 0xC0, &b);
            func_0038CF68(&e, D_001A4BE0_004BBD90.w25C0 + 0xE0, one);
            func_0038CF68(&f, D_001A4BE0_004BBD90.w25C0 + 0xE0, one);
            vec_add_ba(&e, &e, &a);
            vec_add_ab(&f, &f, &a);
            hit = func_003D3CB0(&e, &f, 0, D_001A4BE0_004BBD90.w25C0, 0);
            if (hit != 0) {
                a = *(vu0_v4 *)D_L01_001EAA20;
                func_003C5180(&a, &d, 1);
                func_L01_004515D8(D_001A4BE0_004BBD90.w25C0 + 0xC0, &d, 0);
                func_003C48A8(D_001A4BE0_004BBD90.w25C0 + 0xC0, &b);
            }
        }
        func_L01_004F50C8(&a, &b, 0, 0);
        func_L01_003EB5E0(0, 2);
    }
    if (D_L01_002446C0_004BBD90.b758 != 0) {
        o = func_L01_0043B548(0x1936, 0x10);
        func_L01_004A3610(D_001A4C60, D_001A4C60 + 0x10);
        o->fn(D_L01_002446C0_004BBD90.w75C, D_L01_001DABDC);
        D_L01_001DABDC = 0;
    }
    D_L01_002446C0_004BBD90.w28[0x20] = 1;
    if ((u16)(D_001CCFD0_004BBD90.h76 - 6) >= 2) {
        D_001CCFD0_004BBD90.h76 = 5;
    }
    if ((u16)(D_001CCFD0_004BBD90.h9E - 6) >= 2) {
        D_001CCFD0_004BBD90.h9E = 5;
    }
    if (D_L01_002446C0_004BBD90.b89 != 0) {
        func_L01_004BF950();
    }
    if (D_L01_002446C0_004BBD90.w60 != 0) {
        func_003C2880(D_L01_002446C0_004BBD90.w28);
    }
    if (D_L01_001DABD8 == 0) {
        func_0013C1D0(0x4D);
        func_003A1D00();
    } else {
        D_L01_001DABD8 = 0;
    }
    func_0013B620();
}
/* localdecomp:end func_L01_004BBD90 */
