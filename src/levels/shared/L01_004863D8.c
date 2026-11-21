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

/* declared by functions of L01_004838A0.c, which this file was cut from */
extern void func_L01_00517748(s32);
extern s32 func_L01_0047EBE0(void);
extern S_002EA318 D_L01_002EA2D8[];
extern u8 D_001425C0[];
extern s32 func_L01_00485A10(s32, s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 D_L01_001D8560;
extern s32 D_L01_001D855C;
extern void func_L01_00516470(s32 a0, f32 a1, f32 a2);
extern u8 D_00142CA0[];
extern int func_L01_00485A38(int, int);

/* localdecomp:start func_L01_004863D8 */
extern void func_L01_0047EC88(void);
extern void func_003BB5D0(void);
extern void func_003BB590(s32);
extern void func_L01_00485D00(void);
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090_004863D8(s32);
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_L01_0047FE28(void);
extern u8 D_L01_001D8558;
extern s32 D_L01_001D855C;
extern s32 D_L01_001D8560;
extern s32 D_L01_001D8564;
extern s32 D_L01_001D8568;
extern f32 D_L01_001D85AC;
extern f32 D_L01_001D85B0;
extern f32 D_L01_001D85B4;
extern f32 D_L01_001D85B8;
__asm__(".extern D_L01_001D8558, 1");
__asm__(".extern D_L01_001D855C, 4");
__asm__(".extern D_L01_001D8560, 4");
__asm__(".extern D_L01_001D8564, 4");
__asm__(".extern D_L01_001D8568, 4");
__asm__(".extern D_L01_001D85AC, 4");
__asm__(".extern D_L01_001D85B0, 4");
__asm__(".extern D_L01_001D85B4, 4");
__asm__(".extern D_L01_001D85B8, 4");
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern S_002EA318 D_L01_002EA2D8[];
extern s32 func_L01_005170B8(s32, u32);
extern void func_L01_0047EC38(s32);
extern s32 func_L01_0048EE70(void);
extern s32 func_L01_00487EB0(void);
extern void func_L01_0047EDB0_004863D8(s32, s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern int func_L01_00517D18(int);
extern void func_L01_00516470(s32 a0, f32 a1, f32 a2);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern u8 D_L01_001D672C;
__asm__(".extern D_L01_001D672C, 16");

typedef struct {
    u8 pad0;
    u8 b1;
    u8 pad2[0xF0 - 2];
} E_004863D8;
typedef struct {
    s32 f0;
    u8 pad4[0x20];
    s32 a24[8];
} S_004863D8;
extern E_004863D8 D_L01_002C5600_004863D8[];
extern S_004863D8 D_L01_002EA2D8_004863D8[];

void func_L01_004863D8(s32 a0) {
    s32 b;
    s32 i;
    s32 j;
    s32 idx;

    func_L01_0047EC88();
    func_L01_00486340();
    func_003BB5D0();
    func_003BB590(0xE000B);
    func_L01_00485D00();
    b = *(s32 *)(D_001D52FC + 0x1C4);
    if (b & 0x800) {
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090_004863D8(a0);
    } else if (b & 0x10) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_0047FE28());
        func_L01_00516090_004863D8(a0);
    } else if (b & 0x1000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8558 = 1;
        D_L01_001D8560 = (D_L01_001D8560 + 1) % 2;
    } else if (b & 0x4000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8558 = 1;
        D_L01_001D8560 = (D_L01_001D8560 + 1) % 2;
    } else if (b & 0x8000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8558 = 1;
        D_L01_001D855C = (D_L01_001D855C + 9) % 10;
    } else if (b & 0x2000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8558 = 1;
        D_L01_001D855C = (D_L01_001D855C + 1) % 10;
    } else if (b & 0x40) {
        idx = func_L01_00485A38(D_L01_001D855C, D_L01_001D8560);
        if (D_00142CA0[idx]) {
            func_003A5348(4, 0, 0);
            func_L01_0047EC38(func_L01_00485A38(D_L01_001D855C, D_L01_001D8560));
        } else {
            func_003A5348(5, 0, 0);
        }
    } else if (b & 0x1) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_0048EE70());
        func_L01_00516090_004863D8(a0);
    } else if (b & 0x2) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_00487EB0());
        func_L01_00516090_004863D8(a0);
    }
    func_L01_0047EDB0_004863D8(func_L01_00485A38(D_L01_001D855C, D_L01_001D8560), *(s32 *)(D_001D52FC + 0x1C4));
    func_L01_00485B18();
    func_L01_004861C0();
    func_L01_00486248();
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 2; j++) {
            if (func_L01_004869D8(i, j)) {
                f32 x = D_L01_001D85AC + D_L01_001D85B0 * (f32)i + 0.001953f;
                f32 y;
                if (j != 0) {
                    y = D_L01_001D85B8 - 0.002404f;
                } else {
                    y = D_L01_001D85B4;
                }
                func_L01_00516470(0xE0013, x, y - 0.004808f);
            }
        }
    }
    if (D_L01_001D8564 != D_L01_001D855C || D_L01_001D8568 != D_L01_001D8560) {
        if (D_L01_001D8564 >= 0 && D_L01_001D8568 >= 0) {
            func_L01_005170B8(func_L01_00485A10(func_L01_00485A60(D_L01_001D8564, D_L01_001D8568), 0xE002D, 0xE0038), 0x8066CCFF);
        }
        func_L01_005170B8(func_L01_00485A10(func_L01_00485A60(D_L01_001D855C, D_L01_001D8560), 0xE002D, 0xE0038), 0x80FFFFFF);
        D_L01_001D8564 = D_L01_001D855C;
        D_L01_001D8568 = D_L01_001D8560;
    }
    if (D_L01_001D8558) {
        idx = func_L01_00485A38(D_L01_001D855C, D_L01_001D8560);
        D_L01_001D8558 = 0;
        func_L01_005170B8(0xE000B, 0x402299DE);
        func_L01_00485D00();
        func_L01_00517D18(0xE0008);
        if (D_00142CA0[idx]) {
            func_L01_00516D60(0xE0012, 1);
            func_L01_00517190(0xE0012, D_L01_002EA2D8_004863D8[func_L01_00485A60(D_L01_001D855C, D_L01_001D8560)].a24[((E_004863D8 *)(D_001425C0[idx] * 0xF0 + (u8 *)D_L01_002C5600_004863D8))->b1] + 1);
        } else {
            func_L01_00516D60(0xE0012, 1);
            func_L01_00517190(0xE0012, 0x65);
        }
    }
    if (func_L01_0047DAB0()) {
        func_L01_0047DAC8();
        func_L01_00516090_004863D8(a0);
        if (D_L01_001D672C == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}
/* localdecomp:end func_L01_004863D8 */
