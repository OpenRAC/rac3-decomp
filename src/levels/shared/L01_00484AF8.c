#include "common.h"

typedef struct {
    int f0;
    char pad[64];
} S_002EA318;
typedef struct {
    s32 idx;
    u8 pad[0x40];
} S_482AE0;
typedef struct Obj Obj;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj *);
} ObjVt;
struct Obj {
    s32 pad;
    ObjVt *vt;
};
typedef struct {
    u8 pad0[56];
    u16 x38;
    u8 pad3A[182];
} Entry_00483CD8;
typedef struct Obj_484598 Obj_484598;
typedef struct {
    u8 pad[12];
    void (*fn)(Obj_484598 *);
} Vt_484598;
struct Obj_484598 {
    u8 pad[4];
    Vt_484598 *vt;
};
typedef struct { u8 pad[0x38]; u16 h38; u8 pad3A[0xF0 - 0x3A]; } E_4848A8;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[0x82];
    u16 x8A;
    u8 pad8C[0x64];
} E_4858E8;
typedef struct {
    u8 pad[56];
    u16 unk38;
    u8 pad2[182];
} S_002C5640;
typedef struct {
    u8 pad0[56];
    u16 f56;
    u8 pad58[182];
} Entry_00485FF8;
typedef struct {
    s32 id;
    u8 flag;
    u8 pad[0xAB];
} Ent4876B0;
typedef struct {
    s32 obj;
    u8 pad[81];
    char name[91];
} Slot_00487740;
typedef struct VObj_487AC0 VObj_487AC0;
typedef struct {
    u8 pad[12];
    void (*fn)(VObj_487AC0 *self);
} VTbl_487AC0;
struct VObj_487AC0 {
    s32 pad;
    VTbl_487AC0 *vtbl;
};

/* localdecomp:start func_L01_00484AF8 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad4958[0x64C8 - 0x4958];
    u8 f64C8[16];
} S_160C40_00484AF8;
extern S_160C40_00484AF8 D_00160C40_00484AF8;
extern s32 D_L01_001D8550;
__asm__(".extern D_L01_001D8550, 4");
extern s32 D_L01_001D8554;
__asm__(".extern D_L01_001D8554, 4");
extern u8 D_L01_001D8558;
__asm__(".extern D_L01_001D8558, 1");
extern s32 D_L01_001D8564;
__asm__(".extern D_L01_001D8564, 4");
extern s32 D_L01_001D8568;
__asm__(".extern D_L01_001D8568, 4");
extern f32 D_L01_001D856C;
__asm__(".extern D_L01_001D856C, 4");
extern f32 D_L01_001D8570;
__asm__(".extern D_L01_001D8570, 4");
extern f32 D_L01_001D8574;
__asm__(".extern D_L01_001D8574, 4");
extern f32 D_L01_001D8578;
__asm__(".extern D_L01_001D8578, 4");
extern f32 D_L01_001D857C;
__asm__(".extern D_L01_001D857C, 4");
extern f32 D_L01_001D8580;
__asm__(".extern D_L01_001D8580, 4");
extern f32 D_L01_001D8584;
__asm__(".extern D_L01_001D8584, 4");
extern f32 D_L01_001D8588;
__asm__(".extern D_L01_001D8588, 4");
extern f32 D_L01_001D858C;
__asm__(".extern D_L01_001D858C, 4");
extern f32 D_L01_001D8590;
__asm__(".extern D_L01_001D8590, 4");
extern f32 D_L01_001D8594;
__asm__(".extern D_L01_001D8594, 4");
extern f32 D_L01_001D8598;
__asm__(".extern D_L01_001D8598, 4");
extern f32 D_L01_001D859C;
__asm__(".extern D_L01_001D859C, 4");
extern f32 D_L01_001D85A0;
__asm__(".extern D_L01_001D85A0, 4");
extern f32 D_L01_001D85A4;
__asm__(".extern D_L01_001D85A4, 4");
extern f32 D_L01_001D85A8;
__asm__(".extern D_L01_001D85A8, 4");
extern f32 D_L01_001D85AC;
__asm__(".extern D_L01_001D85AC, 4");
extern f32 D_L01_001D85B0;
__asm__(".extern D_L01_001D85B0, 4");
extern f32 D_L01_001D85B4;
__asm__(".extern D_L01_001D85B4, 4");
extern f32 D_L01_001D85B8;
__asm__(".extern D_L01_001D85B8, 4");
extern f32 D_L01_001D85BC;
__asm__(".extern D_L01_001D85BC, 4");
extern f32 D_L01_001D85C0;
__asm__(".extern D_L01_001D85C0, 4");
extern f32 D_L01_001D85C4;
__asm__(".extern D_L01_001D85C4, 4");
extern f32 D_L01_001D85C8;
__asm__(".extern D_L01_001D85C8, 4");
extern f32 D_L01_001D85CC;
__asm__(".extern D_L01_001D85CC, 4");
extern f32 D_L01_001D85D0;
__asm__(".extern D_L01_001D85D0, 4");
extern f32 D_L01_001D85D4;
__asm__(".extern D_L01_001D85D4, 4");
extern f32 D_L01_001D85D8;
__asm__(".extern D_L01_001D85D8, 4");
extern f32 D_L01_001D85DC;
__asm__(".extern D_L01_001D85DC, 4");
extern f32 D_L01_001D85E0;
__asm__(".extern D_L01_001D85E0, 4");
extern f32 D_L01_001D85E4;
__asm__(".extern D_L01_001D85E4, 4");
extern f32 D_L01_001D85E8;
__asm__(".extern D_L01_001D85E8, 4");
extern f32 D_L01_001D85EC;
__asm__(".extern D_L01_001D85EC, 4");
extern f32 D_L01_001D85F0;
__asm__(".extern D_L01_001D85F0, 4");
extern f32 D_L01_001D85F4;
__asm__(".extern D_L01_001D85F4, 4");
extern f32 D_L01_001D85F8;
__asm__(".extern D_L01_001D85F8, 4");
extern f32 D_L01_001D85FC;
__asm__(".extern D_L01_001D85FC, 4");
extern f32 D_L01_001D8600;
__asm__(".extern D_L01_001D8600, 4");
extern f32 D_L01_001D8604;
__asm__(".extern D_L01_001D8604, 4");
extern f32 D_L01_001D8608;
__asm__(".extern D_L01_001D8608, 4");
extern f32 D_L01_001D860C;
__asm__(".extern D_L01_001D860C, 4");
extern f32 D_L01_001D8610;
__asm__(".extern D_L01_001D8610, 4");
extern f32 D_L01_001D8614;
__asm__(".extern D_L01_001D8614, 4");
extern f32 D_L01_001D8618;
__asm__(".extern D_L01_001D8618, 4");
extern f32 D_L01_001D861C;
__asm__(".extern D_L01_001D861C, 4");
extern f32 D_L01_001D8620;
__asm__(".extern D_L01_001D8620, 4");
extern f32 D_L01_001D8624;
__asm__(".extern D_L01_001D8624, 4");
extern f32 D_L01_001D8628;
__asm__(".extern D_L01_001D8628, 4");
extern f32 D_L01_001D862C;
__asm__(".extern D_L01_001D862C, 4");
extern f32 D_L01_001D8630;
__asm__(".extern D_L01_001D8630, 4");
extern f32 D_L01_001D8634;
__asm__(".extern D_L01_001D8634, 4");
extern f32 D_L01_001D8638;
__asm__(".extern D_L01_001D8638, 4");
extern f32 D_L01_001D863C;
__asm__(".extern D_L01_001D863C, 4");
extern f32 D_L01_001D8640;
__asm__(".extern D_L01_001D8640, 4");
extern f32 D_L01_001E0770;
__asm__(".extern D_L01_001E0770, 4");
extern s32 D_L01_001E0774;
__asm__(".extern D_L01_001E0774, 4");
extern f32 D_L01_001E0778;
__asm__(".extern D_L01_001E0778, 4");
extern s32 D_L01_001E077C;
__asm__(".extern D_L01_001E077C, 4");
extern f32 D_L01_001E0780;
__asm__(".extern D_L01_001E0780, 4");
extern s32 D_L01_001E0784;
__asm__(".extern D_L01_001E0784, 4");
extern f32 D_L01_001E0788;
__asm__(".extern D_L01_001E0788, 4");
extern s32 D_L01_001E078C;
__asm__(".extern D_L01_001E078C, 4");
extern f32 D_L01_001E0790;
__asm__(".extern D_L01_001E0790, 4");
extern s32 D_L01_001E0794;
__asm__(".extern D_L01_001E0794, 4");
extern f32 D_L01_001E0798;
__asm__(".extern D_L01_001E0798, 4");
extern s32 D_L01_001E079C;
__asm__(".extern D_L01_001E079C, 4");
extern f32 D_L01_001E07A0;
__asm__(".extern D_L01_001E07A0, 4");
extern s32 D_L01_001E07A4;
__asm__(".extern D_L01_001E07A4, 4");
extern f32 D_L01_001E07A8;
__asm__(".extern D_L01_001E07A8, 4");
extern s32 D_L01_001E07AC;
__asm__(".extern D_L01_001E07AC, 4");
extern char D_L01_001E07D0[] __attribute__((section(".sdata")));
extern char D_L01_001E07E8[] __attribute__((section(".sdata")));
extern char D_L01_001E07F0[] __attribute__((section(".sdata")));
extern char D_L01_001E0810[] __attribute__((section(".sdata")));
extern char D_L01_00233C58[];
extern char D_L01_00233CD8[];
extern void *func_003BB3A8(s32);
extern s32 func_00381FF0(s32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_003B5060(s32);
extern s32 func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_00517340(s32, s32, s32, s32, s32);
extern s32 func_L01_00516B90(s32, s32, s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00518480(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern s32 func_003E8348(s32, s32);
extern void func_L01_00517BF8(s32, s32, s32, s32, s32, s32);
extern void func_L01_00517DB8(s32, s32, s32, f32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_L01_00518110(s32, s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern void func_L01_00485A70(void);
extern s32 func_003E8C68(s32, s32, s32, s32, s32, s32, s32, s32);
extern Obj *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_003E87B8(s32, s32, s32);

void func_L01_00484AF8(void) {
    s32 i;
    s32 h;

    D_L01_001D8564 = -1;
    D_L01_001D8568 = -1;
    D_L01_001D8558 = 1;
    D_L01_001D8554 = (s32)func_003BB3A8(0);
    D_L01_001D8550 = D_L01_001D8554 + 0x9600;
    func_003B9298(0x10, 0xD000B, 0xD0002, 0xD0003, 0xD0004, 0xD0000, 0xD0001, 0xD0005, 0xD0008, func_00381FF0(0x102), 0xD0006, 0x124, 0xD0007, 0xCD5, 8.7f);
    func_003E8FE8(0xD0009, func_00381FF0(0x1B80), 0x8066CCFF, 0.035f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD0009, 1);
    func_003E8FE8(0xD000A, func_00381FF0(0x1B81), 0x8066CCFF, 0.97f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD000A, 1);
    func_003E8A08(0xD000B, 0xD0009, 0xD000A);

    if (D_L01_001E0774 == 0) {
        D_L01_001E0774 = 1;
        D_L01_001E0770 = D_L01_001D85BC;
    }
    if (D_L01_001E077C == 0) {
        D_L01_001E077C = 1;
        D_L01_001E0778 = D_L01_001D85D0;
    }
    if (D_L01_001E0784 == 0) {
        D_L01_001E0784 = 1;
        D_L01_001E0780 = D_L01_001D85CC;
    }
    if (D_L01_001E078C == 0) {
        D_L01_001E078C = 1;
        D_L01_001E0788 = D_L01_001D85D0;
    }
    if (D_L01_001E0794 == 0) {
        D_L01_001E0794 = 1;
        D_L01_001E0790 = D_L01_001D85FC;
    }
    if (D_L01_001E079C == 0) {
        D_L01_001E079C = 1;
        D_L01_001E0798 = (D_L01_001D8600 + D_L01_001D8604) * 0.5f - 0.007212f;
    }
    if (D_L01_001E07A4 == 0) {
        D_L01_001E07A4 = 1;
        D_L01_001E07A0 = D_L01_001D860C - 0.017577f;
    }
    if (D_L01_001E07AC == 0) {
        D_L01_001E07AC = 1;
        D_L01_001E07A8 = (D_L01_001D8600 - D_L01_001D8604) - 0.036059998f;
    }

    func_003B5060(0xE0001);
    func_003B5060(0xE0002);
    func_003E8FE8(0xE0003, (s32)D_L01_001E07D0, 0x8066CCFF, D_L01_001D8624, D_L01_001D8628, 1.0f, 1.0f);
    func_003E8FE8(0xE0004, (s32)D_L01_001E07E8, 0x8066CCFF, D_L01_001D862C, D_L01_001D8630, 1.0f, 1.0f);
    func_003E8FE8(0xE0005, func_00381FF0(0xBF4), 0x8066CCFF, D_L01_001D8634, D_L01_001D8638, 1.0f, 1.0f);
    func_003E8FE8(0xE0000, (s32)D_L01_00233C58, 0x8066CCFF, D_L01_001D863C, D_L01_001D8640, 1.0f, 1.0f);
    func_003E7F20(0xE0000, 1);
    func_003E8FE8(0xE0006, (s32)D_L01_001E07F0, 0x8066CCFF, D_L01_001E0770, D_L01_001E0778, 1.0f, 1.0f);
    func_003E8FE8(0xE0007, (s32)D_L01_001E0810, 0x8066CCFF, D_L01_001E0780, D_L01_001E0788, 1.0f, 1.0f);
    func_003E9358(0xE0008, (s32)D_L01_00233CD8, 0x8066CCFF, D_L01_001E0790, D_L01_001E0798, D_L01_001E07A0, D_L01_001E07A8, 1.0f);
    func_003E9138(0xE0009, 0x332299DE, D_L01_001D856C, D_L01_001D8570, D_L01_001D857C, D_L01_001D8580, 0);
    func_003E9138(0xE0013, 0x192299DE, 0.0f, 0.0f, 0.07f, 0.08615385f, 0);
    func_003E9270(0xE000A, 0x332299DE, D_L01_001D85CC, D_L01_001D8570, D_L01_001D8574, D_L01_001D8578, 0.005f, 0.004f);
    func_003E9270(0xE0010, 0x332299DE, D_L01_001D85BC, D_L01_001D85C0, D_L01_001D85C4, D_L01_001D85C8, 0.005f, 0.004f);
    func_003E9270(0xE0014, 0x332299DE, D_L01_001D85DC, D_L01_001D85E0, D_L01_001D85E4, D_L01_001D85E8, 0.005f, 0.004f);
    func_003E9270(0xE0011, 0x332299DE, D_L01_001D85CC, D_L01_001D85D0, D_L01_001D85D4, D_L01_001D85D8, 0.005f, 0.004f);
    func_003E9270(0xE000C, 0x332299DE, D_L01_001D85FC, D_L01_001D8600, D_L01_001D860C, D_L01_001D8610, 0.005f, 0.004f);
    func_003E9270(0xE000D, 0x332299DE, D_L01_001D85FC, D_L01_001D8604, D_L01_001D860C, D_L01_001D8610, 0.005f, 0.004f);
    func_003E9270(0xE000E, 0x332299DE, D_L01_001D85FC, D_L01_001D8608, D_L01_001D860C, D_L01_001D8610, 0.005f, 0.004f);
    func_003E9138(0xE000F, 0x332299DE, D_L01_001D8614, D_L01_001D8618, D_L01_001D861C, D_L01_001D8620, 0);
    func_003E9138(0xE0012, 0x80808080, D_L01_001D85EC, D_L01_001D85F0, D_L01_001D85F4, D_L01_001D85F8, 0);
    func_L01_00517340(0xE0009, 0x60336600, 0x6095C862, 0x60336600, 0x6095C862);
    func_L01_00516B90(0xE0009, 1, 3);
    func_003E7F20(0xE0006, 1);
    func_003E8EF0(0xE000B, 0x37, 0x332299DE, D_L01_001D8584 + 0.0f * D_L01_001D8588, D_L01_001D858C, 1.0f, 1.0f, 0.0f);
    func_L01_00516AA0(0xE0003, 0x40, 1);
    func_L01_00516AA0(0xE0004, 0x40, 1);
    func_L01_00516AA0(0xE0005, 0x40, 1);
    func_L01_00516AA0(0xE0000, 0x40, 1);
    func_L01_00516AA0(0xE0008, 0x40, 1);
    func_L01_00516AA0(0xE0007, 0x40, 1);
    func_L01_00516AA0(0xE0006, 0x40, 1);
    func_003E7F20(0xE0003, 1);
    func_003E7F20(0xE0008, 1);
    func_003E7F20(0xE0004, 1);
    func_003E7F20(0xE0007, 1);
    func_003E7F20(0xE0008, 1);
    func_L01_00518480(0xE0001, 0xE0003, 0xE0004, 0xE0000, 0xE000B, 0xE0009, 0xE000C, 0xE000D, 0xE000E);
    func_L01_00518480(0xE0001, 0xE0010, 0xE0011, 0xE0006, 0xE0007, 0xE0008, 0xE000F, 0xE0012, 0xE0002);
    func_003E8A08(0xE0002, 0xE0014, 0xE000A);
    func_L01_00516470(0xE000B, 0.1f, 0.1f);
    func_003E8348(0x13, 0xE0001);
    func_L01_00517BF8(0xE0008, 1, 1, 1, 0, 0);
    func_L01_00517DB8(0xE0008, 0x64, 0, 0.0005f);
    func_003E9138(0xE0058, 0x706EC8FF, 0.630249f, 0.195417f, 0.07f, 0.08615385f, 0);
    func_003E9138(0xE0059, 0x706EC8FF, 0.630249f, 0.195417f, 0.07f, 0.08615385f, 0);
    func_003E9138(0xE005A, 0x706EC8FF, 0.630249f, 0.195417f, 0.07f, 0.08615385f, 0);
    func_L01_00517190(0xE0058, 0xED54);
    func_L01_00517190(0xE0059, 0xED52);
    func_L01_00517190(0xE005A, 0xED53);
    func_L01_00516D60(0xE0058, 0);
    func_L01_00516D60(0xE0059, 0);
    func_L01_00516D60(0xE005A, 0);
    func_L01_00518110(0xE0002, 0xE0058, 0xE0059, 0xE005A);

    func_003B5060(0xE0016);
    for (i = 0; i < 10; i++) {
        h = i + 0xE0017;
        func_003E8EF0(h, 0x37, 0x332299DE, D_L01_001D8584 + (f32)i * D_L01_001D8588, D_L01_001D858C, 1.0f, 1.0f, 0.0f);
        func_003E8630(0xE0016, h);
    }
    func_003B5060(0xE0021);
    for (i = 0; i < 10; i++) {
        h = i + 0xE0022;
        func_003E8EF0(h, 0x37, 0x332299DE, D_L01_001D8584 + (f32)i * D_L01_001D8588, D_L01_001D8590, 1.0f, 1.0f, 0.0f);
        func_003E8630(0xE0021, h);
    }
    func_003B5060(0xE002C);
    for (i = 0; i < 10; i++) {
        h = i + 0xE002D;
        func_003E9138(h, 0x706EC8FF, D_L01_001D85AC + (f32)i * D_L01_001D85B0 + 0.001953f, D_L01_001D85B4 + -0.004808f, 0.07f, 0.08615385f, 0);
        func_003E8630(0xE002C, h);
    }
    func_003B5060(0xE0037);
    for (i = 0; i < 10; i++) {
        h = i + 0xE0038;
        func_003E9138(h, 0x706EC8FF, D_L01_001D85AC + (f32)i * D_L01_001D8588 + 0.001953f, D_L01_001D85B8 + -0.004808f, 0.07f, 0.08615385f, 0);
        func_003E8630(0xE0037, h);
    }
    func_003B5060(0xE0042);
    for (i = 0; i < 10; i++) {
        f32 x;
        f32 y;
        h = i + 0xE0043;
        x = D_L01_001D8594 + (f32)i * D_L01_001D8598;
        y = x + ((i == 6 || i == 8) ? 0.001953f : 0.0f);
        func_003E9138(h, 0x706EC8FF, y, D_L01_001D859C - 0.004808f, D_L01_001D85A4, D_L01_001D85A8, 0);
        func_L01_00517340(h, 0x60336600, 0x6095C862, 0x60336600, 0x6095C862);
        func_L01_00516B90(h, 1, 3);
        func_003E8630(0xE0042, h);
    }
    func_003B5060(0xE004D);
    for (i = 0; i < 10; i++) {
        f32 x;
        f32 y;
        h = i + 0xE004E;
        x = D_L01_001D8594 + (f32)i * D_L01_001D8598;
        y = x + ((i == 6 || i == 8) ? 0.001953f : 0.0f);
        func_003E9138(h, 0x706EC8FF, y, D_L01_001D85A0 - 0.004808f, D_L01_001D85A4, D_L01_001D85A8, 0);
        func_L01_00517340(h, 0x60336600, 0x6095C862, 0x60336600, 0x6095C862);
        func_L01_00516B90(h, 1, 3);
        func_003E8630(0xE004D, h);
    }
    func_L01_00485A70();
    func_003B5060(0xE0015);
    func_003E8C68(0xE0015, 0xE0013, 0xE0016, 0xE0021, 0xE002C, 0xE0037, 0xE0042, 0xE004D);
    func_003E8348(0x11, 0xE0015);
    func_003B4528(func_003B42F8(0), D_L01_001D8554, D_L01_001D8550, D_00160C40_00484AF8.f4954, (s32)D_00160C40_00484AF8.f64C8);
    func_003E8710(0xE0012, (s32)func_003B42F8(0));
    func_L01_00517190(0xE0012, 0);
    func_L01_00516D60(0xE0012, 0);
    func_003E87B8(0xE0012, 1, 8);
}
/* localdecomp:end func_L01_00484AF8 */
