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
extern u8 D_00142CA0[];
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_004784C0(s32, s32, f32, f32);
extern s32 func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern s32 func_L01_00487F78(s32, s32, s32);
extern int func_0011B2E8(char *, char *, ...);
extern s32 D_L01_001D8848;
extern s32 D_L01_001D8838;
extern s32 D_L01_001D883C;

/* localdecomp:start func_L01_004892C0 */
extern s32 func_L01_00487F78(s32, s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00485B68(s32);
extern int func_0011B2E8(char *, char *, ...);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_004784C0(s32, s32, f32, f32);
extern s32 D_L01_001D8848;
extern s32 D_L01_001D8838;
extern s32 D_L01_001D883C;
extern u8 D_00142CA0[];
extern char D_L01_001D8818[8];
extern char D_L01_001D89F8[];
extern char D_L01_001D8A00[];
extern f32 D_L01_001D884C;
extern f32 D_L01_001D8850;
extern f32 D_L01_001D8878;
__asm__(".extern D_L01_001D8848, 4");
__asm__(".extern D_L01_001D8838, 4");
__asm__(".extern D_L01_001D883C, 4");
__asm__(".extern D_L01_001D8818, 8");
__asm__(".extern D_L01_001D884C, 4");
__asm__(".extern D_L01_001D8850, 4");
__asm__(".extern D_L01_001D8878, 4");

void func_L01_004892C0(void) {
    s32 i;

    i = func_L01_00487F78(D_L01_001D8848, D_L01_001D8838, D_L01_001D883C);
    if (D_L01_001D8848 == 0 && D_00142CA0[i] != 0) {
        func_0011B2E8(D_L01_001D8818, D_L01_001D89F8, func_00381FF0(0x1604), func_L01_00485B68(i));
    } else {
        func_0011B2E8(D_L01_001D8818, D_L01_001D8A00, func_00381FF0(0x1604));
    }
    i = func_L01_00487F78(0, D_L01_001D8838, D_L01_001D883C);
    if (D_L01_001D8848 == 0 && D_00142CA0[i] != 0) {
        func_L01_00516AA0(0x190009, 1, 1);
        func_L01_004784C0(i, 0x190009, D_L01_001D884C - 0.007f, D_L01_001D8850 - D_L01_001D8878 * 2.0f);
    } else {
        func_L01_00516AA0(0x190009, 1, 0);
    }
}
/* localdecomp:end func_L01_004892C0 */
