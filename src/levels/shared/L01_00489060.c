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
extern u8 D_001425C0[];
extern Entry_00483CD8 D_L01_002C5600[];
extern u8 D_00142CA0[];
extern s32 func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, ...);

/* localdecomp:start func_L01_00489060 */
extern void func_L01_00516470_00489060(s32 a, f32 x, f32 y);
extern void func_L01_00516D60_00489060(s32 a, s32 b);
extern s32 D_L01_001D8848_00489060;
extern s32 D_L01_001D8838_00489060;
extern s32 D_L01_001D883C_00489060;
extern f32 D_L01_001D8890_00489060;
extern f32 D_L01_001D8894_00489060;
extern f32 D_L01_001D8898_00489060;
extern f32 D_L01_001D889C_00489060;
extern f32 D_L01_001D88B0_00489060;
extern f32 D_L01_001D88B4_00489060;
extern f32 D_L01_001D88B8_00489060;
extern f32 D_L01_001D88BC_00489060;
__asm__(".extern D_L01_001D8894_00489060, 16");
__asm__(".extern D_L01_001D889C_00489060, 16");
__asm__(".extern D_L01_001D88B4_00489060, 16");
__asm__(".extern D_L01_001D88BC_00489060, 16");

void func_L01_00489060(void) {
    switch (D_L01_001D8848_00489060) {
    case 0:
        func_L01_00516470_00489060(0x19000E, D_L01_001D8890_00489060 + (f32)D_L01_001D8838_00489060 * D_L01_001D8898_00489060, D_L01_001D8894_00489060 + (f32)D_L01_001D883C_00489060 * D_L01_001D889C_00489060);
        func_L01_00516D60_00489060(0x19000E, 1);
        func_L01_00516D60_00489060(0x19000F, 0);
            break;
    case 1:
        func_L01_00516470_00489060(0x19000F, D_L01_001D88B0_00489060 + (f32)D_L01_001D8838_00489060 * D_L01_001D88B8_00489060, D_L01_001D88B4_00489060 + (f32)D_L01_001D883C_00489060 * D_L01_001D88BC_00489060);
        func_L01_00516D60_00489060(0x19000F, 1);
        func_L01_00516D60_00489060(0x19000E, 0);
        break;
    }
}
/* localdecomp:end func_L01_00489060 */

/* localdecomp:start func_L01_00489160 */
extern Entry_00483CD8 D_L01_002C5600[];
extern s32 func_L01_00487F78(s32, s32, s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_00381FF0(s32);
extern int func_0011B2E8(char *, char *, ...);
extern s32 D_L01_001D8848;
extern s32 D_L01_001D8838;
extern s32 D_L01_001D883C;
extern char D_L01_001D87E0[8];
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern char D_L01_002EAAA8[];
extern char D_L01_001D89C8[];
extern char D_L01_001D89D0[];
extern char D_L01_001D89E0[];
extern char D_L01_001D89F0[];

void func_L01_00489160(void) {
    s32 i = func_L01_00487F78(D_L01_001D8848, D_L01_001D8838, D_L01_001D883C);

    if (D_L01_001D8848 == 1) {
        func_L01_00516D60(0x190007, 0);
    } else {
        func_L01_00516D60(0x190007, 1);
    }
    if (D_00142CA0[i]) {
        func_0011B2E8(D_L01_002EAAA8, D_L01_001D89C8, func_00381FF0((((E_4858E8 *)&D_L01_002C5600) + D_001425C0[i])->x4));
        func_0011B2E8(D_L01_001D87E0, D_L01_001D89D0, func_00381FF0(376), D_001427F0[i], ((E_4858E8 *)&D_L01_002C5600)[D_001425C0[i]].x8A);
    } else {
        func_0011B2E8(D_L01_002EAAA8, D_L01_001D89E0);
        func_0011B2E8(D_L01_001D87E0, D_L01_001D89F0);
    }
}
/* localdecomp:end func_L01_00489160 */
